#include"TFT_eSPI.h"
#include <Ultrasonic.h>

TFT_eSPI tft;
Ultrasonic ult(0);

void setup(){
  tft.begin();
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  tft.fillScreen(0xF800);

}



void loop(){

  tft.drawString((String)"premi pulsante A per iniziare ", 100, 50);
  if (digitalRead(WIO_KEY_A) == LOW) {
    tft.drawString((String)(long)ult.MeasureInCentimeters(), 50, 50);
    tft.setTextColor(0x0);
    tft.fillScreen(0xEFC2);
  }
  tft.fillScreen(0xFFA0);

}
