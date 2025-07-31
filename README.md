# 🔥 WiFi-Based Forest Fire Alert System (Without LCD)

This project is a **forest fire detection system** that uses a **flame sensor** and **WiFi module** to detect fire hazards and alert through serial communication and sound. It's ideal for remote monitoring of forest environments where early fire detection is critical.

## 🛠️ Components Used

| Component            | Description                                 |
|---------------------|---------------------------------------------|
| Arduino (Uno/Nano)  | Microcontroller unit                        |
| Flame Sensor        | Detects fire or flame                       |
| Buzzer              | Provides audio alert on fire detection      |
| LED (Optional)      | Visual indication of system status          |
| ESP8266 WiFi Module | For sending alerts over serial communication|
| Resistors, Wires    | For basic circuit connections               |

## ⚙️ Features

- Detects fire using a flame sensor.
- Sends alert via AT commands using a WiFi module.
- Activates a buzzer when flame is detected.
- Easy to configure and modify.
- Works without an LCD display.

## 🧠 How It Works

- The flame sensor reads analog values from the environment.
- If the value is **below 300**, fire is likely detected.
- The system:
  - Triggers a **buzzer** to alert locally.
  - Sends an alert message (`FIRE DETECTED @ FOREST ;`) via serial AT commands.
- If the value rises above 500 (i.e., no fire), the buzzer turns off.

## 📦 Code Overview

- `setup()` initializes serial communication, pin modes, and WiFi configuration.
- `loop()` constantly reads the flame sensor and checks for fire conditions.
- `sendAlert()` handles sending alert messages using the ESP8266.
- `wificonfig()` sets up the ESP8266 module with required AT commands.

## 🔧 WiFi Configuration

Update the following lines in the code with your WiFi credentials:

```
Serial.print("fire");         // Replace with your WiFi SSID
Serial.print("monitor1234");  // Replace with your WiFi Password
```
