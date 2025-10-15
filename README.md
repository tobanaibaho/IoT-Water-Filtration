# 💧 IoT Water Filtration System

[![GitHub Stars](https://img.shields.io/github/stars/tobanaibaho/IoT-Water-Filtration?style=flat-square)](https://github.com/tobanaibaho/IoT-Water-Filtration/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/tobanaibaho/IoT-Water-Filtration?style=flat-square)](https://github.com/tobanaibaho/IoT-Water-Filtration/network/members)
[![GitHub License](https://img.shields.io/badge/License-MIT-blue.svg?style=flat-square)](LICENSE)
[![Made with Arduino](https://img.shields.io/badge/Made%20with-Arduino-blue?style=flat-square&logo=arduino)](https://www.arduino.cc/)
[![Powered by Blynk](https://img.shields.io/badge/Powered%20by-Blynk-green?style=flat-square&logo=blynk)](https://blynk.io)

An **IoT-based water quality monitoring system** using Arduino and ESP8266 that measures **pH, TDS, and temperature** in real-time, sends the data to **Blynk Cloud**, and logs readings into **Excel via PLX-DAQ** for further analysis.

---

## 🧠 Project Overview

The **IoT Water Filtration System** is designed to help monitor and improve water quality using smart sensors.  
It enables real-time monitoring and data logging for environmental or laboratory research purposes.

### 🌟 Key Features
- Real-time **pH, TDS, and Temperature Monitoring**
- **Wi-Fi data transmission** using ESP8266 to Blynk Cloud
- **Excel data logging** with PLX-DAQ
- **Simulation support** via Wokwi (https://wokwi.com)
- Open-source and customizable

---

## ⚙️ Hardware Components

| No | Component | Description |
|----|------------|-------------|
| 1 | **Arduino Uno** | Main microcontroller |
| 2 | **ESP8266 Wi-Fi Module** | IoT connectivity to Blynk |
| 3 | **pH Sensor (Analog)** | Measures water acidity |
| 4 | **Gravity TDS Sensor** | Measures dissolved solids |
| 5 | **DS18B20 Sensor** | Measures water temperature |
| 6 | **Jumper Wires & Breadboard** | Circuit connections |

---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) or [VS Code with Arduino Extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino)
- [Blynk Cloud](https://blynk.cloud)
- [PLX-DAQ v2](https://github.com/netlabtoolkit/PLX-DAQ)
- [Wokwi Simulator](https://wokwi.com)
- [Git](https://git-scm.com/) & [GitHub](https://github.com)

---

## 📦 Library Dependencies

Make sure to install these libraries in your Arduino IDE before uploading:

| Library | Description |
|----------|--------------|
| `BlynkSimpleShieldEsp8266.h` | Connection to Blynk IoT platform |
| `ESP8266_Lib.h` | ESP8266 serial communication |
| `AnalogPHMeter.h` | pH sensor reading |
| `GravityTDS.h` | TDS sensor reading |
| `DallasTemperature.h` | DS18B20 temperature measurement |
| `OneWire.h` | DS18B20 communication protocol |
| `EEPROM.h` | Calibration data storage |

---

## 🔌 Wiring Diagram (Basic)

| Sensor | Arduino Pin |
|---------|--------------|
| pH Sensor | A0 |
| TDS Sensor | A1 |
| DS18B20 | D7 |
| ESP8266 RX/TX | D2 / D3 |
| Power Supply | 5V / GND |

---

## 🌐 Blynk Setup

Edit your Wi-Fi and Blynk credentials in the `.ino` file:

```cpp
#define BLYNK_TEMPLATE_ID "Your_Blynk_Template_ID"
#define BLYNK_AUTH_TOKEN "Your_Blynk_Auth_Token"
const char ssid[] = "Your_WiFi_Name";
const char pass[] = "Your_WiFi_Password";

🧪 Simulation (Wokwi)

To simulate your project without hardware:

Visit https://wokwi.com

Create a new Arduino Uno Project

Add simulated components:

DS18B20 sensor

2 potentiometers (simulate pH & TDS)

Paste your code from FINAL_CODE.ino

Open Serial Monitor → Observe sensor readings in real time.


📊 Data Logging (PLX-DAQ)

Open PLX-DAQ-v2.xlsm in Excel

Enable Macros

Set correct COM port

Click Connect

Your real-time data (Date, Time, Temperature, pH, TDS) will start logging

Example Serial Output:

Suhu: 26.45 °C
TDS: 512 ppm
pH: 7.02
DATA,DATE,TIME,26.45,7.02,512

🚀 Upload Steps

Connect Arduino to PC via USB

Open FINAL_CODE.ino in Arduino IDE or VS Code

Select Board: Arduino Uno

Select Port: COMx

Click Upload


🌱 Future Improvements

Add automatic relay control for water filtering system

Use MQTT or Firebase for real-time online dashboard

Implement mobile app alerts for abnormal pH/TDS readings