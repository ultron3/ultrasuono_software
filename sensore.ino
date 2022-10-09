#include"TFT_eSPI.h"
#include <Ultrasonic.h>

TFT_eSPI tft;
Ultrasonic ult(0);

void setup(){
  tft.begin();
  tft.fillScreen(0x101F);

}



void loop(){

  tft.drawString((String)(long)ult.MeasureInCentimeters(), 100, 100);
  tft.setTextColor(0xFFFF);
  tft.fillScreen(0x0);

}
