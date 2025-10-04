#  Weather Monitoring System

##  Overview
The **Weather Monitoring System** is an IoT-based project designed to monitor and record real-time environmental parameters such as **temperature** and **humidity**. The system utilizes sensor data acquisition, microcontroller-based processing, and cloud-based visualization to provide continuous monitoring of weather conditions. 

The project aims to automate weather tracking using reliable sensors and wireless data transfer, making it ideal for applications in smart agriculture, climate observation, and IoT research.

##  Hardware Components
- **ESP8266 / ESP32** – Main microcontroller for Wi-Fi communication  
- **DHT11 / DHT22 Sensor** – Measures temperature and humidity  
- **Jumper Wires & Breadboard** – For circuit connections  
- **USB Cable** – For programming and power  
- **(Optional)**: LCD Display module to view real-time readings locally  

---

##  Software Requirements
- **Arduino IDE** (for code uploading and serial monitoring)  
- **ThingSpeak** (for cloud data visualization and logging)  
- **DHT Sensor Library**  
- **WiFi Library**  


##  Project Structure
Weather-Monitoring-System/
│
├── dhtada.ino # Basic DHT sensor data acquisition and display
├── final.ino # Final integrated code with Wi-Fi and ThingSpeak upload
├── thinhspeaktestmulyiple.ino # Multi-sensor data upload test to ThingSpeak
│
└── README.md # Project documentation


##  Features
 Real-time temperature and humidity monitoring  
 Wireless data transmission to **ThingSpeak** IoT cloud platform  
 Live visualization of weather data (temperature & humidity graphs)  
 Compact, low-power IoT design  
 Scalable for multi-sensor integration  


##  Working Principle
1. The **DHT11/DHT22 sensor** continuously senses the surrounding temperature and humidity.  
2. The **ESP8266/ESP32** reads the sensor data via a digital pin.  
3. The controller processes and sends the collected data to the **ThingSpeak** cloud using Wi-Fi connectivity.  
4. The data is then displayed in real-time on the ThingSpeak dashboard for visualization and further analysis.


## 📊 Output Example
- **Serial Monitor Output:**
Temperature: 28.5°C
Humidity: 62%
Data sent to ThingSpeak successfully!


- **ThingSpeak Dashboard:**
- Channel 1 → Temperature graph  
- Channel 2 → Humidity graph  

*(You can insert screenshots here once you upload your ThingSpeak results.)*

---

## 🧩 Setup Instructions
  1. Open any of the `.ino` files in **Arduino IDE**.  
  2. Install the required libraries:
   - `DHT.h`
   - `WiFi.h`
   - `ThingSpeak.h`
  3. Update your **Wi-Fi credentials** and **ThingSpeak API Key** in the code:
   ```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";
   unsigned long channelID = YOUR_CHANNEL_ID;
   const char* writeAPIKey = "YOUR_WRITE_API_KEY";
  
  4.Connect the components as per the circuit diagram (DHT sensor to data pin).
  
  5. Upload the code to your ESP8266/ESP32.
  
  6. Open the Serial Monitor to check sensor readings and upload status.
