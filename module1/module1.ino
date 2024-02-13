#include <TFT_eSPI.h>
#include <SPI.h>

#include "script.h"
#include "objection.h"
#include "restCase.h"
#include "overruled.h"
#include "evidence.h"

#include <Pangodream_18650_CL.h> 
#include <array>

#define ADC_PIN 34
#define CONV_FACTOR 1.8
#define READS 20
Pangodream_18650_CL BL(ADC_PIN, CONV_FACTOR, READS);

TFT_eSPI tft = TFT_eSPI();

#define BUTTON_PIN_BITMASK 0x800000000
#define array_size(arr) (sizeof(arr) / sizeof(*(arr)))

#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */ 
#define TIME_TO_SLEEP 60 /* Time ESP32 will go to sleep (in seconds) */

int screenW=240;
int screenH=135;

void IRAM_ATTR goToSleep() {
  esp_deep_sleep_start();
}

void setup() {
  // put your setup code here, to run once:
  tft.init();
  tft.setRotation(1);
  attachInterrupt(0, goToSleep, CHANGE);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK);

  tft.setSwapBytes(true);

  //set screen Back Light brightness
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(0, 5000, 8); // 0-15, 5000, 8
  ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
  ledcWrite(0, 50); // 0-15, 0-255 (with 8 bit resolution); 0=totally dark;255=totally shiny

}

int name1 = 20;
int name2 = 160;
int name3 = 95;

int person = 0;
int x = 10;
int nameH = 100;
int scriptH = 120;
int dT = 3000;

int rN;
int rN1;
int rN2;

void loop() {

  tft.drawString("INT.", 40, 60, 4);
  tft.drawString("COURTROOM", 40, 85, 4);
  delay(dT);
  // put your main code here, to run repeatedly:
  tft.fillScreen(TFT_WHITE);
  
  int rounds = random(1, 5);
  
  for (int i = 0; i < rounds; i++) {
    //lawyer 1
    //name
    tft.drawString(lawyer[0], name1, nameH, 2);
    //dialogue
    while (rN1 == (rN = random(1, array_size(lawyer)))) {
      continue;
    }
    rN1 = rN;
    tft.drawString(lawyer[rN1], x, scriptH);
    //image
    int pic = random(2);
    if (pic == 0) {
      tft.pushImage(0, 0, objectionW, objectionH, objection);
    } else {
      tft.pushImage(0, 0, restCaseW, restCaseH, restCase);
    }
    
  
    //delay
    delay(dT);
    //reset
    tft.fillScreen(TFT_WHITE);

    //lawyer 2
    //name
    tft.drawString(lawyer[0], name2, nameH, 2);
    //dialogue
    while (rN2 == (rN = random(1, array_size(lawyer)))) {
      continue;
    }
    rN2 = rN;
    tft.drawString(lawyer[rN2], x, scriptH);
    //image
    pic = random(2);
    if (pic == 0) {
      tft.pushImage(80, 0, overruledW, overruledH, overruled);
    } else {
      tft.pushImage(110, 0, evidenceW, evidenceH, evidence);
    }
    
  
    //delay
    delay(dT);
    //reset
    tft.fillScreen(TFT_WHITE);


  }


  tft.drawString("END.", 160, 100, 4);
  delay(dT);
  // put your main code here, to run repeatedly:
  tft.fillScreen(TFT_WHITE);

  goToSleep();
}
