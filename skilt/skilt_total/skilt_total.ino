// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include "columns.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
#define NUMPIXELS      253

const byte interruptPin = 2;
bool interrupted = false;
int interruptValOld;
int interruptVal;
unsigned long interruptTime;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//int *by_columns();
int delayval = 20; // delay for half a second
unsigned long last_time;
unsigned long current_time;

unsigned long last_time_glitter;
unsigned long current_time_glitter;

unsigned long last_time_fade_in;
unsigned long current_time_fade_in;

byte letters = 10;
//byte *led_pointers[10];
byte array_lengths[10] = {33, 30, 1, 23, 15, 24, 35, 35, 29, 28};
byte turned_on[253];



void interruptFunc() {
  interruptValOld = interruptVal;
  interruptVal = digitalRead(interruptPin);

  if (interruptVal == HIGH & interruptValOld != interruptVal & millis() - interruptTime > 1000) {
    interruptTime = millis();
    /*int delayval = 200 / 20;
      int tail = 15;

      for (int i = 0; i < sizeof(column_length_all) + tail * 2; i++) { //wipe the board
      int cnt = i - tail;
      if (cnt >= 0 && cnt < sizeof(column_length_all)) {
        flash_letter(column_pointers_all[cnt], column_length_all[cnt], 66, 68, 66);
      }
      for (int j = 1; j < tail; j ++) {
        if (cnt - j >= 0 && cnt - j < sizeof(column_length_all)) {
          flash_letter(column_pointers_all[cnt - j], column_length_all[cnt - j], 66, 68, 66);
        }
      }
      pixels.show();
      delay(delayval);
      //turn_all_off();
      if (cnt - tail >= 0 && cnt - tail < sizeof(column_length_all)) {
        flash_letter(column_pointers_all[cnt - tail], column_length_all[cnt - tail], 0, 0, 0);
      }
      }*/
    while (millis() - interruptTime < 1000) {
      /*for (int i = 0; i < pixels.numPixels(); i++) {
        long lngRGB = pixels.getPixelColor(i);
        uint8_t r = pixels.getPixelColor(i) >> 16;
        uint8_t g = pixels.getPixelColor(i) >> 8;
        uint8_t b = pixels.getPixelColor(i);
        Serial.print(r);
        Serial.print("\t");
        Serial.print(g);
        Serial.print("\t");
        Serial.print(b);
        Serial.print("\t");
        Serial.println(i);
        pixels.setPixelColor(i, r/2, g, b);
        // pixels.setPixelColor(i, LEDr, LEDg, LEDb);

      }*/
      pixels.setBrightness((interruptTime+1000 - millis())/4);
      pixels.show();
      delay(10);
    }

    pixels.clear();
    interrupted = true;
    //Serial.println("Interrupted bitch");
  }

}

void setup() {

  Serial.begin(115200);
  pixels.begin(); // This initializes the NeoPixel library.
  last_time = millis();
  current_time = millis();
  last_time_glitter = millis();
  current_time_glitter = millis();
  last_time_fade_in = millis();
  current_time_fade_in = millis();

  pinMode(interruptPin, INPUT);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunc, RISING);
  randomSeed(analogRead(0));
}


int state = 0;

int val = 10;
bool flag = 1;

void loop() {

  //Serial.println(interrupted);
  if (interrupted == true) {
    int preState = state;
    while (state == preState) {
      state = random(4);
    }
    interrupted = false;
    pixels.setBrightness(255);
    //pixels.fill(pixels.Color(200, 0, 0), 0, 253);
  }


  switch (state) {
    case 0:
      threeColors(pixels.Color(255, 0, 0), 5, 42, 0);
      threeColors(pixels.Color(0, 255, 255), 5, 42, 42);
      threeColors(pixels.Color(0, 255, 0), 5, 42, 42 * 2);
      threeColors(pixels.Color(255, 0, 0), 5, 42, 42 * 3);
      threeColors(pixels.Color(0, 255, 255), 5, 42, 42 * 4);
      threeColors(pixels.Color(255, 255, 0), 5, 43, 42 * 5);
      break;
    case 1:
      theaterChaseRain(0, pixels.numPixels(), 50, 1);
      break;
    case 2:
      fillFromCenter(6);
      break;
    case 3:
      theaterChaseRain(0, pixels.numPixels(), 50, 3);
      break;
  }
  pixels.show();
  interruptFunc();
  pixels.clear();

}
