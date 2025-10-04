#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "  moto g84 5G_4056";   // your network SSID (name) 
const char* password = "Tanmoy@123";   // your network password
WiFiClient  client;

unsigned long myChannelNumber = 2913008;
const char * myWriteAPIKey = "FAX9B25U9HMJX97R";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000; // thingspeak need time of 30 sec to write data

// Variable to hold temperature readings
float temperatureC;

void setup() {
  Serial.begin(115200);  //Initialize serial
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {  //for delay
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

    // Get a new temperature reading
    temperatureC = 90;
    Serial.print("Temperature (ºC): ");
    Serial.println(temperatureC);
        
    int x = ThingSpeak.writeField(myChannelNumber, 2, temperatureC, myWriteAPIKey);
    
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
