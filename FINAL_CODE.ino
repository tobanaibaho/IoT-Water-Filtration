// Konfigurasi Blynk
#define BLYNK_TEMPLATE_ID "TMPL67BePw6Yl"
#define BLYNK_TEMPLATE_NAME "SKRIPSI"
#define BLYNK_AUTH_TOKEN "vVrQ4EN87RdAH349BAScU6Co3k5uz2bB"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <AnalogPHMeter.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include "GravityTDS.h"
#include <BlynkSimpleShieldEsp8266.h>  // Library Blynk
#include <ESP8266_Lib.h>


// Pin untuk DS18B20
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
GravityTDS gravityTds;

#define TdsSensorPin A1
AnalogPHMeter pHSensor(A0);
unsigned int pHCalibrationValueAddress = 0;

float tdsValue, phValue, temperature;
bool check_connection = false;
const char ssid[] = "PEMBURU TOBRUT";   // Ganti dengan SSID Anda
const char pass[] = "Bencikamu3kali";    // Ganti dengan Password Wi-Fi Anda

SoftwareSerial EspSerial(2, 3); // RX, TX untuk ESP8266
#define ESP8266_BAUD 38400
ESP8266 wifi(&EspSerial);
// BlynkTimer timer;  // Timer untuk Blynk

void setup() {
    Serial.begin(9600);
    EspSerial.begin(ESP8266_BAUD);

    // Inisialisasi sensor
    struct PHCalibrationValue pHCalibrationValue;
    EEPROM.get(pHCalibrationValueAddress, pHCalibrationValue);
    pHSensor.initialize(pHCalibrationValue);

    sensors.begin();
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);
    gravityTds.setAdcRange(1024);
    gravityTds.begin();

    // Blynk.begin(BLYNK_AUTH_TOKEN, ESP8266, ssid, pass);  // Menggunakan ESP8266 dan SoftwareSerial
    Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);
    // timer.setInterval(3000L, sendDataToBlynk);  // Kirim data setiap 3 detik
    
    // Header untuk PLX-DAQ
    // Serial.println("CLEARDATA");
    // Serial.println("LABEL,Date,Time,Temperature,pH,TDS");

    delay(500);
}

void loop() {
    Blynk.run();
    sendDataToBlynk();
    delay(3000);
}

void sendDataToBlynk() {
    // Membaca sensor dan mengirim data ke Blynk
    sensors.requestTemperatures();
    temperature = sensors.getTempCByIndex(0);  // Membaca suhu
    if (temperature == DEVICE_DISCONNECTED_C){
      Serial.println("Sensor Disconnected");
    }else{
      Serial.println("temperature");
    }
    gravityTds.setTemperature(temperature);
    gravityTds.update();
    tdsValue = gravityTds.getTdsValue();  // Membaca TDS
    phValue = pHSensor.singleReading().getpH();  // Membaca pH
    // temperature = random(1,100);              // Pembacaan simulasi data
    // tdsValue = random(1,1000);                // Pembacaan simulasi data
    // phValue = random(1,15);                   // Pembacaan simulasi data

    // Mengirim data ke virtual pin Blynk
    Blynk.virtualWrite(V2, temperature);
    Blynk.virtualWrite(V0, phValue);  
    Blynk.virtualWrite(V1, tdsValue);

    

    Serial.print("Suhu: ");
    Serial.println(temperature);
    Serial.print("TDS: ");
    Serial.println(tdsValue);
    Serial.print("pH: ");
    Serial.println(phValue);

    Serial.println( (String) "DATA,DATE,TIME," + temperature + "," + phValue + "," + tdsValue );
}
