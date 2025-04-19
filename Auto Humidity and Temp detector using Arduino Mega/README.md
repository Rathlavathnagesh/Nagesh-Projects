# Automatic Humidity and Temperature Detection System using Arduino Mega 2560

## 📖 Project Overview

The **Automatic Humidity and Temperature Detection System** is designed to monitor real-time temperature and humidity levels using the **DHT11 sensor** and display the readings on a **16x2 LCD**. It visually indicates temperature conditions using two LEDs:

- **Yellow LED**: Lights up when the temperature is **≥ 35°C**
- **Blue LED**: Lights up when the temperature is **< 35°C**

This system is ideal for simple weather stations, greenhouse monitoring, or home automation applications.

---

## 🧰 Hardware Components

| Component                | Quantity |
|--------------------------|----------|
| Arduino Mega 2560        | 1        |
| DHT11 Temperature Sensor | 1        |
| 16x2 LCD Display         | 1        |
| Yellow LED               | 1        |
| Blue LED                 | 1        |
| White LED (optional)     | 1        |
| 220Ω Resistors (for LEDs)| 3        |
| Breadboard               | 1        |
| Jumper Wires             | As needed |

---

## ⚙️ Pin Configuration

### DHT11 Sensor
- **VCC** → 5V on Arduino
- **GND** → GND on Arduino
- **DATA** → Pin 8

### 16x2 LCD (in 4-bit mode)
- **RS** → Pin 1  
- **E**  → Pin 2  
- **D4** → Pin 4  
- **D5** → Pin 5  
- **D6** → Pin 6  
- **D7** → Pin 7  

### LEDs
- **Yellow LED** → Pin 9  
- **Blue LED**   → Pin 10  
- **White LED**  → Pin 11 (optional)  

---

## 🧪 How It Works

1. The DHT11 sensor continuously reads temperature and humidity.
2. Readings are displayed on the LCD.
3. LED indicators respond to the temperature:
   - **≥ 35°C**: Yellow LED turns ON
   - **< 35°C**: Blue LED turns ON

---

## 🔧 Libraries Required

Make sure to install the following libraries via the Arduino Library Manager:

- `LiquidCrystal`  
- `DHT` (by Adafruit or compatible)

---

## 🚀 Getting Started

1. Connect the components as per the pin configuration.
2. Upload the Arduino sketch to your Mega 2560 board.
3. Open the Serial Monitor or observe the LCD and LEDs for live readings and indicators.

---

## 📌 Notes

- Ensure correct power supply for sensors and components.
- You may adjust the temperature threshold (`35°C`) in the code to fit your use-case.
- Make sure the DHT11 is not exposed to moisture or direct sunlight for accurate results.
