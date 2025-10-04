#  Weather Monitoring System (IoT)

##  Overview
The **Weather Monitoring System** is an IoT-based project that monitors **ambient temperature** and **humidity** in real time.  
It uses an **ESP32 microcontroller**, a **DHT22 digital sensor**, and the **ThingSpeak cloud platform** for data aggregation, visualization, and analysis.  

This project provides a reliable and scalable solution for environmental monitoring and can easily be extended for smart agriculture, home automation, or climate research.

---

##  Key Features
-  **Real-Time Data Collection:** Continuously reads temperature and humidity from the DHT22 sensor.  
-  **Wi-Fi Connectivity:** Uses the powerful ESP32 board for seamless internet access.  
-  **Cloud Integration:** Publishes sensor data to a ThingSpeak channel via HTTP.  
-  **Data Visualization:** Displays live and historical weather data using ThingSpeak charts.  
-  **Scalable Architecture:** Easily extendable to include more sensors such as pressure, air quality, or light intensity.  

---

##  Hardware & Software Requirements

###  Hardware Components
| Component | Quantity | Description |
|------------|-----------|-------------|
| **ESP32 Dev Module** | 1 | Main microcontroller with Wi-Fi/Bluetooth capabilities |
| **DHT22 Sensor** | 1 | Digital temperature and humidity sensor |
| **Resistor (10k Ω)** | 1 | Pull-up resistor for DHT22 data line |
| **Breadboard** | 1 | Used for circuit prototyping |
| **Jumper Wires** | Few | For making electrical connections |
| **USB Cable** | 1 | For powering and programming the ESP32 |

---

###  Software and Libraries
| Software / Platform | Purpose |
|----------------------|----------|
| **Arduino IDE** | Code writing, compiling, and uploading |
| **ThingSpeak Account** | Cloud-based IoT analytics and visualization |
| **ESP32 Board Support** | Required package for programming ESP32 boards |
| **DHT Sensor Library (Adafruit)** | For reading data from the DHT22 sensor |
| **Adafruit Unified Sensor** | Dependency library for DHT sensor |
| **ThingSpeak Library (MathWorks)** | For sending data to the ThingSpeak cloud |

---

##  Circuit and Wiring
The **DHT22 sensor** is connected to the **ESP32** development board.  
A **10k Ω pull-up resistor** is required between the **data pin** and **VCC**.

| DHT22 Pin | Description | ESP32 Pin (Example) |
|------------|--------------|--------------------|
| **VCC (Pin 1)** | Power Supply | 3.3V |
| **Data (Pin 2)** | Data Line (with 10k Ω Pull-up) | GPIO 4 |
| **NC (Pin 3)** | Not Connected | — |
| **GND (Pin 4)** | Ground | GND |

>  *Note: The example code uses GPIO 4, but you can modify the `DHTPIN` variable to use any available digital pin.*

---

###  Circuit Diagram
![Circuit Diagram](./A_schematic_circuit_diagram_in_2D_digital_format_i.png)

---

##  Setup and Installation Guide

### 🔧 Arduino IDE Setup
1. **Install Arduino IDE:** Download the latest version from [arduino.cc](https://www.arduino.cc/en/software).  
2. **Add ESP32 Board Manager URL:**  
   Go to **File → Preferences**, and in *Additional Board Manager URLs*, add:  
https://dl.espressif.com/dl/package_esp32_index.json

markdown
Copy code
3. **Install ESP32 Boards:**  
Go to **Tools → Board → Boards Manager...**, search for **esp32**, and click **Install**.  
4. **Install USB to UART Drivers:**  
If your ESP32 COM port isn’t detected, install **CP210x USB to UART Bridge VCP Drivers**.  

---

###  Library Installation
Open Arduino IDE → **Sketch → Include Library → Manage Libraries...** and install:
- **DHT sensor library** by Adafruit  
- **Adafruit Unified Sensor**  
- **ThingSpeak** by MathWorks  

After installation, restart the IDE.

---

###  ThingSpeak Configuration
1. **Create an Account:**  
Sign up at [ThingSpeak](https://thingspeak.com/).  
2. **Create a New Channel:**  
Go to **Channels → My Channels → New Channel**.  
3. **Define Fields:**  
- Field 1 → **TEMPERATURE**  
- Field 2 → **HUMIDITY**  
4. **Get API Key:**  
Go to the **API Keys** tab and copy your **Write API Key** — you’ll need it for your code.

---

###  Code Configuration and Upload
1. Open your Arduino sketch (e.g., `final.ino` or `weather_monitor.ino`).  
2. Update the following lines with your credentials:
```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
unsigned long myChannelNumber = YOUR_CHANNEL_ID;
const char* myWriteAPIKey = "YOUR_WRITE_API_KEY";

###Select the correct board and port:

Board: DOIT ESP32 DEVKIT V1

Port: Your COM port

Click Upload and wait for successful compilation.

###Troubleshooting
Error Message	Possible Cause	Solution
Failed to connect to ESP32: Timed out... Connecting...	ESP32 not in flash mode	Hold BOOT while uploading, release when "Connecting..." appears
COM Port not detected	Missing USB driver	Install CP210x USB to UART Bridge VCP Drivers
DHT Sensor errors	Wiring or library issue	Check wiring and ensure both DHT & Adafruit libraries are installed
No data on ThingSpeak	Incorrect credentials	Verify Wi-Fi SSID, password, channel ID, and API key

###Data Visualization
Once the ESP32 successfully uploads data, open your ThingSpeak channel to view:

Field 1 (Temperature): Graph of temperature over time

Field 2 (Humidity): Graph of humidity over time

You can also use MATLAB Analysis Apps within ThingSpeak for:

Calculating averages

Detecting trends

Generating alerts

###Project Structure

Weather-Monitoring-System/
│
├── dhtada.ino                  # Basic DHT sensor data acquisition
├── final.ino                   # Final version with ThingSpeak integration
├── thinhspeaktestmulyiple.ino  # Multi-sensor upload testing
├── A_schematic_circuit_diagram_in_2D_digital_format_i.png  # Circuit diagram
└── README.md                   # Project documentation


###Author
Siddharth Chandra Prabhakar
B.Tech (Electronics and Communication Engineering)
National Institute of Technology, Sikkim


 ###License
This project is licensed under the MIT License.
Feel free to use, modify, and share for educational or research purposes.

“Accurate weather data today ensures smarter decisions tomorrow.”
