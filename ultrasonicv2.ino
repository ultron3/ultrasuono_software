#include"TFT_eSPI.h"
#include <Ultrasonic.h>

TFT_eSPI tft;
Ultrasonic ult(0);

void setup(){
  tft.begin();
  tft.fillScreen(0x281F);

}



void loop(){

  if (((long)ult.MeasureInCentimeters() > 10)) {
    tft.fillScreen(0xF800);
    tft.drawString((String)"oggetto fuori range", 100, 100);
    tft.setTextColor(0x0);
  }
  if (((long)ult.MeasureInCentimeters() < 10)) {
    tft.fillScreen(0xF800);
    tft.drawString((String)"oggetto dentro range", 100, 100);
    tft.setTextColor(0x0);
  }

}
