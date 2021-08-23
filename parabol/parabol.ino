// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
#define NUMPIXELS      70

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//int *by_columns();
int delayval = 20; // delay for half a second

//byte *led_pointers[10];
byte rings[5] = {19, 14, 10, 6, 1};
byte ringStop[5] = {19, 33, 43, 49, 50};

byte turned_on[NUMPIXELS];


void turn_all_off() {
  for (int j = 0; j < NUMPIXELS; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); // Moderately bright green color.
    turned_on[j] = 0;
  }
  pixels.show();
}

void light_all_rings() {
  int limit = 0;
  for (int i = 0; i < 5; i++) {
    delay(200);
    for (int j = 0; j < ringStop[i]; j++ ) {
      pixels.setPixelColor(j, pixels.Color(200, 0, 0));
    }
    pixels.show();
  }
}

void setRingLight(int ringNum, bool On) {
  switch (ringNum) {
    case 0:
      if (On == true) {
        for (int k = 0; k < ringStop[0]; k++) {
          pixels.setPixelColor(k, pixels.Color(200, 0, 0));
        }
      }
      else {
        for (int k = 0; k < ringStop[0]; k++) {
          pixels.setPixelColor(k, pixels.Color(0, 0, 0));
        }
      }
      break;
    case 1:
      if (On == true) {
        for (int k = ringStop[0]; k < ringStop[1]; k++) {
          pixels.setPixelColor(k, pixels.Color(200, 0, 0));
        }
      }
      else {
        for (int k = ringStop[0]; k < ringStop[1]; k++) {
          pixels.setPixelColor(k, pixels.Color(0, 0, 0));
        }
      }
      break;
    case 2:
      if (On == true) {
        for (int k = ringStop[1]; k < ringStop[2]; k++) {
          pixels.setPixelColor(k, pixels.Color(200, 0, 0));
        }
      }
      else {
        for (int k = ringStop[1]; k < ringStop[2]; k++) {
          pixels.setPixelColor(k, pixels.Color(0, 0, 0));
        }
      }
      break;
    case 3:
      if (On == true) {
        for (int k = ringStop[2]; k < ringStop[3]; k++) {
          pixels.setPixelColor(k, pixels.Color(200, 0, 0));
        }
      }
      else {
        for (int k = ringStop[2]; k < ringStop[3]; k++) {
          pixels.setPixelColor(k, pixels.Color(0, 0, 0));
        }
      }
      break;
    case 4:
      if (On == true) {
        for (int k = ringStop[3]; k < ringStop[4]; k++) {
          pixels.setPixelColor(k, pixels.Color(200, 0, 0));
        }
      }
      else {
        for (int k = ringStop[3]; k < ringStop[4]; k++) {
          pixels.setPixelColor(k, pixels.Color(0, 0, 0));
        }
      }
      break;
  }
}

void incommingSignal() {
  int limit = millis()/100 % 8;
  
    //delay(100);

    setRingLight(limit, true);

    
    setRingLight(limit+2, true);
    if(limit >= 2){
      setRingLight(limit-2, true);
      }

    pixels.show();
    setRingLight(limit, false);
    setRingLight(limit+2, false);
    if(limit >= 2){
      setRingLight(limit-2, false);
      }
  
}

void slowAll() {
  for (int j = 0; j < NUMPIXELS; j++ ) {
    pixels.setPixelColor(j, pixels.Color(200, 0, 0));
    pixels.show();
    delay(70);
  }
}

void setup() {

  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.

}



void loop() {

  //slowAll();
  //light_all_rings();
  incommingSignal();
  //delay(1000);
  //turn_all_off();
}
