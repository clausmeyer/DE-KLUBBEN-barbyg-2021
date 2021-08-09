// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
#define NUMPIXELS      300


// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // delay for half a second
byte leds_D[33];
byte leds_E1[30];
byte leds_dot[1];
byte leds_K[23];
byte leds_L[15];
byte leds_U[24];
byte leds_B1[35];
byte leds_B2[35];
byte leds_E2[29];
byte leds_N[28];
byte letters = 10;
byte *led_pointers[10];
byte array_lengths[10] = {33, 30, 1, 23, 15, 24, 35, 35, 29, 28};

void flash_letter(byte *letter_array, byte arr_length) {
  pixels.show();
  for (int j = 0; j < arr_length; j++) {
    pixels.setPixelColor(*(letter_array + j), pixels.Color(15, 15, 15)); // Moderately bright green color.
  }
  pixels.show();
  delay(delayval);
}

void setup() {

  Serial.begin(9600);

  for (int i = 0; i < sizeof(leds_D); i++) leds_D[i] = i;
  for (int i = 0; i < sizeof(leds_E1); i++) leds_E1[i] = i + leds_D[sizeof(leds_D) - 1] + 1;
  for (int i = 0; i < sizeof(leds_dot); i++) leds_dot[i] = i + leds_E1[sizeof(leds_E1) - 1] + 1;
  for (int i = 0; i < sizeof(leds_K); i++) leds_K[i] = i + leds_dot[sizeof(leds_dot) - 1] + 1;
  for (int i = 0; i < sizeof(leds_L); i++) leds_L[i] = i + leds_K[sizeof(leds_K) - 1] + 1;
  for (int i = 0; i < sizeof(leds_U); i++) leds_U[i] = i + leds_L[sizeof(leds_L) - 1] + 1;
  for (int i = 0; i < sizeof(leds_B1); i++) leds_B1[i] = i + leds_U[sizeof(leds_U) - 1] + 1;
  for (int i = 0; i < sizeof(leds_B2); i++) leds_B2[i] = i + leds_B1[sizeof(leds_B1) - 1] + 1;
  for (int i = 0; i < sizeof(leds_E2); i++) leds_E2[i] = i + leds_B2[sizeof(leds_B2) - 1] + 1;
  for (int i = 0; i < sizeof(leds_N); i++) leds_N[i] = i + leds_E2[sizeof(leds_E2) - 1] + 1;
  
  led_pointers[0] = leds_D;
  led_pointers[1] = leds_E1;
  led_pointers[2] = leds_dot;
  led_pointers[3] = leds_K;
  led_pointers[4] = leds_L;
  led_pointers[5] = leds_U;
  led_pointers[6] = leds_B1;
  led_pointers[7] = leds_B2;
  led_pointers[8] = leds_E2;
  led_pointers[9] = leds_N;
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  for (int i = 0; i < letters; i++) {
    flash_letter(led_pointers[i], array_lengths[i]);
  }
  for (int j = 0; j < 254; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels.show();
}
