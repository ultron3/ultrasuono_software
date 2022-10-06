#include"TFT_eSPI.h"
#include "rpcWiFi.h"
#include <Ultrasonic.h>
#include <MQTT.h>
TFT_eSPI tft;
Ultrasonic ult(0);
const char ssid[] = "Its-guest";
const char pass[] = "eet6Euru";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/hello");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}

void setup(){
  tft.begin();
  tft.fillScreen(0xF800);
  WiFi.begin(ssid, pass);
  

}



void loop(){
   client.loop();
    delay(10);  // <- fixes some issues with WiFi stability

    if (!client.connected()) {
      connect();
    }
  tft.fillScreen(0xF800);
  if (!client.connected()) {
      connect();
    }
  

  tft.drawString((String)(long)ult.MeasureInCentimeters(), 100, 100);
  tft.setTextColor(0x0);
  if (((long)ult.MeasureInCentimeters() > 100)) {
    tft.drawString((String)"oggetto nel range", 100, 100);
    tft.setTextColor(0x0);
    client.publish("/dddd-test-in-gnavi","oggetto nel range");
    
  }
  if (((long)ult.MeasureInCentimeters() < 100)) {
    tft.drawString((String)"oggetto fuori range", 100, 100);
    tft.setTextColor(0x0);
    client.publish("/dddd-test-in-gnavi","oggetto fuori range");
   
  }

}
