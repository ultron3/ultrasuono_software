#include"TFT_eSPI.h"
#include <Ultrasonic.h>

TFT_eSPI tft;
Ultrasonic ult(0);

void setup(){
  tft.begin();
  tft.fillScreen(0xF800);

}



void loop(){

  if (((long)ult.MeasureInCentimeters() < 10)) {
    tft.setTextColor(0x0);
    tft.setTextSize(1);
    tft.drawString((String)"OGGETTO DENTRO AL RANGE", 100, 100);
    tft.fillScreen(0xF800);
  }
  if (((long)ult.MeasureInCentimeters() > 10)) {
    tft.setTextColor(0x0);
    tft.setTextSize(1);
    tft.drawString((String)"OGGETTO FUORI DAL RANGE", 100, 100);
    tft.fillScreen(0x2FE0);
  }
  if (((long)ult.MeasureInCentimeters() == 5)) {
    tft.setTextSize(1);
    tft.drawString((String)"OGGETTO A CONFINE RANGE", 100, 100);
    tft.fillScreen(0xEFE0);
    tft.setTextColor(0x0);
  }

}
