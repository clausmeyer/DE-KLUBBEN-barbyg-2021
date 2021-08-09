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

int delayval = 20; // delay for half a second
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

void fade_out() {

}

void flash_letter(byte *letter_array, byte arr_length, byte R, byte G, byte B) {
  for (int j = 0; j < arr_length; j++) {
    pixels.setPixelColor(*(letter_array + j), pixels.Color(R, G, B)); // Moderately bright green color.
  }
  pixels.show();

}

void sharp_center() {
  // fade thingy

  for (int i = 0; i < letters; i++) {
    int indices[10] = {i, i - 1, i + 1, i - 2, i + 2, i - 3, i + 3, i - 4, i + 4, i - 5};
    for (int j = 0; j < 10; j++) {
      if (indices[j] < 0) indices[j] = indices[j] + 10;
      else if (indices[j] > 9) indices[j] = indices[j] - 10;
    }
    flash_letter(led_pointers[indices[0]], array_lengths[indices[0]], 0, 0, 15);
    flash_letter(led_pointers[indices[1]], array_lengths[indices[1]], 0, 15, 0);
    flash_letter(led_pointers[indices[2]], array_lengths[indices[2]], 0, 15, 0);
    flash_letter(led_pointers[indices[3]], array_lengths[indices[3]], 15, 0, 0);
    flash_letter(led_pointers[indices[4]], array_lengths[indices[4]], 15, 0, 0);
    flash_letter(led_pointers[indices[5]], array_lengths[indices[5]], 0, 0, 0);
    flash_letter(led_pointers[indices[6]], array_lengths[indices[6]], 0, 0, 0);
    flash_letter(led_pointers[indices[7]], array_lengths[indices[7]], 0, 0, 0);
    flash_letter(led_pointers[indices[8]], array_lengths[indices[8]], 0, 0, 0);
    flash_letter(led_pointers[indices[9]], array_lengths[indices[9]], 0, 0, 0);
    //Serial.println(indices[4]);
    pixels.show();
    delay(delayval);
  }
}

void fill_from_left() {
  for (int i = 0; i < letters; i++) {
    flash_letter(led_pointers[i], array_lengths[i], 15, 15, 15);
    delay(delayval);
  }
  for (int j = 0; j < 254; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); 
  }
  pixels.show();
}

void fade_in_and_out() {
  int value = 10;
  int fades = 5; // Skru op når der er mere juice tilgængelig
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], value, 0, 0);
    }
    delay(delayval);
    value = value + 10;
  }
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], value, 0, 0);
    }
    delay(delayval);
    value = value - 10;
  }
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
  /*-----------------------------------------------------*/
  /*
  */
  /*-----------------------------------------------------*/
  fade_in_and_out();
  //sharp_center();
  //fill_from_left();
  /*-----------------------------------------------------*/

}
