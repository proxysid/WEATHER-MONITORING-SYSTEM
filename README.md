☁️ Weather Monitoring System (IoT)
This project demonstrates a complete Internet of Things (IoT) solution for monitoring ambient temperature and humidity in real-time. It utilizes an ESP32 microcontroller, a DHT22 digital sensor, and the ThingSpeak cloud platform for data aggregation, visualization, and analysis.

🚀 Key Features
Real-Time Data Collection: Reads temperature and humidity from the DHT22 sensor.

Wi-Fi Connectivity: Uses the powerful ESP32 board to connect to the internet.

Cloud Integration: Publishes sensor data to a custom ThingSpeak channel via HTTP.

Data Visualization: Displays real-time and historical weather data using ThingSpeak's built-in charts.

Scalable Architecture: Easily expandable to include more sensors (e.g., pressure, air quality).

🛠️ Hardware & Software Requirements
Hardware Components
Component

Quantity

Notes

ESP32 Dev Module

1

Microcontroller with Wi-Fi/Bluetooth capabilities.

DHT22 Sensor

1

Digital Relative Humidity and Temperature sensor.

Resistor

1

10k Ω Pull-up resistor.

Breadboard

1

For prototyping the circuit.

Jumper Wires

Few

For making connections.

USB Cable

1

For powering and programming the ESP32.

Software and Libraries
Software/Platform

Purpose

Arduino IDE

Used to write, compile, and upload the code (sketch) to the ESP32.

ThingSpeak Account

Cloud platform for IoT analytics and visualization.

ESP32 Board Support

Add-on for Arduino IDE (required for ESP32 programming).

DHT Sensor Library

Adafruit library for interfacing with the DHT22 sensor.

Adafruit Unified Sensor

Required dependency for the DHT sensor library.

ThingSpeak Library

MathWorks library for pushing data to the ThingSpeak cloud.

🔌 Circuit and Wiring
The DHT22 sensor is connected to the ESP32 development board. A 10k Ω pull-up resistor is mandatory for the data line.

DHT22 Pin

Connection

ESP32 Pin (Example)

VCC (Pin 1)

Power

3.3V

Data (Pin 2)

Data Line (with 10k Ω Pull-up)

GPIO 4

NC (Pin 3)

Do Not Connect

-

GND (Pin 4)

Ground

GND

Note: The example code is configured to use GPIO 4, but you can adjust the DHTPIN variable in the sketch to use any suitable digital GPIO pin.

⚙️ Setup and Installation Guide
1. Arduino IDE Setup (Prerequisites)
Ensure you have the latest version of the Arduino IDE installed.

Add ESP32 Board Manager URL: Go to File > Preferences and add the following URL to the "Additional Board Manager URLs" field:

[https://dl.espressif.com/dl/package_esp32_index.json](https://dl.espressif.com/dl/package_esp32_index.json)

Install ESP32 Boards: Go to Tools > Board > Boards Manager..., search for esp32, and click Install on the "esp32 by Espressif Systems" package.

Install USB to UART Drivers: If your ESP32's COM port is not visible, you may need to install the CP210x USB to UART Bridge VCP Drivers.

2. Library Installation
Install the necessary libraries via the Arduino IDE Library Manager (Sketch > Include Library > Manage Libraries...):

Search for DHT sensor library and install the version by Adafruit.

Search for Adafruit Unified Sensor and install it (required dependency).

Search for ThingSpeak and install the version by MathWorks.

Restart your Arduino IDE after installing the libraries.

3. ThingSpeak Configuration
Create an Account: Sign in or create a free account at https://thingspeak.com/.

Create a New Channel: Go to Channels > My Channels and click New Channel.

Define Fields: Name your channel and enable at least two fields:

Field 1: TEMPERATURE

Field 2: HUMIDITY

Get API Key: Navigate to the API Keys tab and securely save your Write API Key. You will need to enter this into the Arduino sketch.

4. Code Configuration and Upload
Open the provided Arduino sketch (usually named weather_monitor.ino or similar).

Update the following placeholders in the code with your specific credentials:

ssid: Your Wi-Fi network name.

password: Your Wi-Fi network password.

myChannelNumber: Your ThingSpeak Channel ID.

myWriteAPIKey: Your ThingSpeak Write API Key.

Select your board (Tools > Board) (e.g., DOIT ESP32 DEVKIT V1) and the correct COM Port (Tools > Port).

Press the Upload button.

🐛 Troubleshooting
Error Message

Possible Cause & Solution

Failed to connect to ESP32: Timed out... Connecting...

The ESP32 is not in flashing mode. Hold down the 'BOOT' button while uploading. Once you see the Connecting... message in the console, release the button.

Cannot see COM Port

Missing CP210x USB to UART Bridge VCP Drivers. Install them.

DHT Sensor Errors

Check wiring, especially the 10k Ω pull-up resistor on the data line. Ensure both DHT and Adafruit Unified Sensor libraries are installed.

No data on ThingSpeak

Verify your SSID, Password, Channel ID, and Write API Key are all correctly entered and match your ThingSpeak settings.

📈 Data Visualization
Once the ESP32 starts uploading data, you can view the charts in your ThingSpeak channel's Private View.

Field 1 Chart (Temperature): Shows the temperature readings over time.

Field 2 Chart (Humidity): Shows the humidity readings over time.

You can further use the MATLAB Analysis apps within ThingSpeak for advanced data processing, such as calculating averages, identifying trends, and creating alerts.
