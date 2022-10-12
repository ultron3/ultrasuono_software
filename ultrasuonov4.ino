#include"TFT_eSPI.h"
#include <Ultrasonic.h>

TFT_eSPI tft;
Ultrasonic ult(0);

void setup(){
  tft.begin();
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  tft.fillScreen(0xF800);

}



void loop(){

  if (digitalRead(WIO_KEY_B) == LOW) {
    tft.drawString((String)"fine programma", 100, 100);
    tft.setTextColor(0xFFFF);
    tft.fillScreen(0x0);
  }
  tft.drawString((String)(long)ult.MeasureInCentimeters(), 100, 100);
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.fillScreen(0x0);

}
