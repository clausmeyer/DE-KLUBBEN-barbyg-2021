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
#define NUMPIXELS      300


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
void fade_out() {

}

void flash_letter(byte *letter_array, byte arr_length, byte R, byte G, byte B) {
  for (int j = 0; j < arr_length; j++) {
    pixels.setPixelColor(*(letter_array + j), pixels.Color(R, G, B)); // Moderately bright green color.
    if ( R > 0 || G > 0 || B > 0) turned_on[*(letter_array + j)] = 1;
    //Serial.println(*(letter_array + j));
  }
  //pixels.show();

}
/*
  void flash_column(byte *letter_array, byte arr_length, byte R, byte G, byte B) {
  for (int j = 0; j < arr_length; j++) {
    pixels.setPixelColor(*(letter_array + j), pixels.Color(R, G, B)); // Moderately bright green color.
    Serial.println(*(letter_array + j));
  }
  pixels.show();

  }*/
/*
  void sharp_center() {
  // fade thingy

  for (int i = 0; i < letters; i++) {
    int indices[10] = {i, i - 1, i + 1, i - 2, i + 2, i - 3, i + 3, i - 4, i + 4, i - 5};
    for (int j = 0; j < 10; j++) {
      if (indices[j] < 0) indices[j] = indices[j] + 10;
      else if (indices[j] > 9) indices[j] = indices[j] - 10;
    }
    /* for (int i = 0; i < sizeof(column_lengths_D); i++) {
       flash_letter(column_pointers_D[indices[0]], column_lengths_D[indices[0]], 255, 0, 0);
      }*//*
    pixels.show();
    for (int i = 0; i < 10; i++) flash_letter(led_pointers[indices[1]], 10, 125, 0, 0);
    Serial.println(sizeof(led_pointers[indices[1]]));
    flash_letter(led_pointers[indices[2]], array_lengths[indices[2]], 125, 0, 0);
    flash_letter(led_pointers[indices[3]], array_lengths[indices[3]], 100, 0, 0);
    flash_letter(led_pointers[indices[4]], array_lengths[indices[4]], 100, 0, 0);
    flash_letter(led_pointers[indices[5]], array_lengths[indices[5]], 75, 0, 0);
    flash_letter(led_pointers[indices[6]], array_lengths[indices[6]], 75, 0, 0);
    flash_letter(led_pointers[indices[7]], array_lengths[indices[7]], 25, 0, 0);
    flash_letter(led_pointers[indices[8]], array_lengths[indices[8]], 25, 0, 0);
    flash_letter(led_pointers[indices[9]], array_lengths[indices[9]], 25, 0, 0);
    //Serial.println(indices[4]);
    pixels.show();
    delay(delayval);
  }
  }
*/

void sharp_center() {
  int centerColor = 200;
  int colourFall = 10;
  int fallLength = 20;
  int delayval = 200 / 10;
  //int columnColors[99] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


  for (int i = 0; i < sizeof(column_pointers_all) * 5; i++) {
    //turn_all_off();
    //columnColors[i] = centerColor;
    flash_letter(column_pointers_all[i % 99], column_length_all[i % 99], centerColor, 0, 0);
    if (i < fallLength) {

      for (int j = 1; j <= i; j++) {
        //columnColors[i-j] = colourFall * j;
        flash_letter(column_pointers_all[i - j], column_length_all[i - j], centerColor - (colourFall * j), 0, 0);
      }

      for (int k = 1; k <= fallLength; k++) {
        //columnColors[i+k] = colourFall * k;
        flash_letter(column_pointers_all[i + k], column_length_all[i + k], centerColor - (colourFall * k), 0, 0);
      }

    }
    else {
      for (int l = 1; l <= fallLength; l++) {
        flash_letter(column_pointers_all[(i + l) % 99], column_length_all[(i + l) % 99], centerColor - (colourFall * l), 0, 0);
        flash_letter(column_pointers_all[(i - l) % 99], column_length_all[(i - l) % 99], centerColor - (colourFall * l), 0, 0);
      }
    }
    pixels.show();
    delay(delayval);
    //turn_all_off();
    flash_letter(column_pointers_all[(i - fallLength) % 99], column_length_all[(i - fallLength) % 99], 0, 0, 0);
  }

}

void shift_Effect() {
  int smldly = 25;
  for (int i = 0; i < sizeof(column_length_all) ; i = i + 2) {
    flash_letter(column_pointers_all[i], column_length_all[i], 133, 0, 0);
    pixels.show();
    delay(smldly);
    flash_letter(column_pointers_all[i + 1], column_length_all[i + 1], 0, 0, 133);
    pixels.show();
    delay(smldly);
  }
  delay(smldly * 100);

  for (int j = sizeof(column_length_all); j >= 0; j--) {
    flash_letter(column_pointers_all[j], column_length_all[j], 133, 0, 0);
    pixels.show();
    delay(smldly);
  }
  delay(smldly * 100);

  for (int k = 0; k < sizeof(column_length_all); k = k + 2) {
    flash_letter(column_pointers_all[k], column_length_all[k], 0, 133, 0);
  }
  pixels.show();
  delay(smldly * 100);

  //turn_all_off();
}

void fill_from_left() {
  int delayval_col = 500;
  int R_val = 50;
  for (int i = 0; i < sizeof(column_lengths_D); i++) {
    flash_letter(column_pointers_D[i], column_lengths_D[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);

  for (int i = 0; i < sizeof(column_lengths_E); i++) {
    flash_letter(column_pointers_E[i], column_lengths_E[i], R_val, 0, 0);

  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_dot); i++) {
    flash_letter(column_pointers_dot[i], column_lengths_dot[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_K); i++) {
    flash_letter(column_pointers_K[i], column_lengths_K[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_L); i++) {
    flash_letter(column_pointers_L[i], column_lengths_L[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_U); i++) {
    flash_letter(column_pointers_U[i], column_lengths_U[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_B); i++) {
    flash_letter(column_pointers_B[i], column_lengths_B[i], R_val, 0, 0);

  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_BB); i++) {
    flash_letter(column_pointers_BB[i], column_lengths_BB[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_EE); i++) {
    flash_letter(column_pointers_EE[i], column_lengths_EE[i], R_val, 0, 0);
    //delay(delayval_col);
  }
  pixels.show();
  delay(delayval_col);
  for (int i = 0; i < sizeof(column_lengths_N); i++) {
    flash_letter(column_pointers_N[i], column_lengths_N[i], R_val, 0, 0);
    //delay(delayval_col);
  }

  pixels.show();
  delay(delayval_col * 5);
  turn_all_off();
}
/*
  void fade_in_and_out() {
  int value = 10;
  int fades = 23; // Skru op når der er mere juice tilgængelig
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], 0, 0, value);
    }
    delay(delayval);
    value = value + 10;
  }
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], 0, 0, value);
    }
    delay(delayval);
    value = value - 10;
  }
  }
*/
/*
  void change_colors() {
  int value = 0;
  int fades = 23; // Skru op når der er mere juice tilgængelig
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], 0, 0, value);
    }
    delay(delayval);
    value = value + 10;
  }
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], 0, 0, value);
    }
    delay(delayval);
    value = value - 10;
  }
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], 0, value, 0);
    }
    delay(delayval);
    value = value + 10;
  }
  for (int j = 0; j < fades; j++) {
    for (int i = 0; i < letters; i++) {
      flash_letter(led_pointers[i], array_lengths[i], 0, value, 0);
    }

    delay(delayval);
    value = value - 10;
  }
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
*/
void setup() {

  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  last_time = millis();
  current_time = millis();
  last_time_glitter = millis();
  current_time_glitter = millis();
  last_time_fade_in = millis();
  current_time_fade_in = millis();
}


void by_columns() {


  int delayval_col = 50;
  int R_val = 255;
  current_time_fade_in = millis();
  for (int i = 0; i < sizeof(column_lengths_D); i++) {
    flash_letter(column_pointers_D[i], column_lengths_D[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }


  for (int i = 0; i < sizeof(column_lengths_E); i++) {
    flash_letter(column_pointers_E[i], column_lengths_E[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_dot); i++) {
    flash_letter(column_pointers_dot[i], column_lengths_dot[i], R_val, 0, 0);
    pixels.show();
    delay(delayval_col);
  }

  for (int i = 0; i < sizeof(column_lengths_K); i++) {
    flash_letter(column_pointers_K[i], column_lengths_K[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_L); i++) {
    flash_letter(column_pointers_L[i], column_lengths_L[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_U); i++) {
    flash_letter(column_pointers_U[i], column_lengths_U[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_B); i++) {
    flash_letter(column_pointers_B[i], column_lengths_B[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_BB); i++) {
    flash_letter(column_pointers_BB[i], column_lengths_BB[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_EE); i++) {
    flash_letter(column_pointers_EE[i], column_lengths_EE[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  for (int i = 0; i < sizeof(column_lengths_N); i++) {
    flash_letter(column_pointers_N[i], column_lengths_N[i], R_val, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + delayval_col) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  pixels.show();
  //delay(delayval_col * 50);
  //turn_all_off();
}

void hvid() {
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(255, 255, 255)); // Moderately bright green color.
  }
}

void turn_all_off() {
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels.show();
}

void glitter() {
  int vals;
  current_time_glitter = millis();
  if (current_time_glitter > last_time_glitter + 20) {
    last_time_glitter = current_time_glitter;
    srand(micros());
    for (int i = 0; i < 253; i++) {
      if (turned_on[i] > 0) {
        int probab = rand();
        if (probab < 5000) {
          vals = rand() % 255;
          //Serial.println(vals);
          pixels.setPixelColor(i, pixels.Color(vals, 0, 0));
        }
      }
    }
    pixels.show();
  }

}
byte turn_off_counter = 0;
void stochastic_fade_out() {
  //int vals;
  srand(micros());
  /*for (int i = 0; i < 253; i++) {
    int probab = rand();
    if (probab < 50+turn_off_counter*50)
    {
      turn_off_counter++;
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    }
    pixels.show();
    delay(10);*/
  /*for (int i = 0; i < 253; i++) {
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    }*/
  byte places[253];
  for (int i = 1; i < 253; i++) {
    places[i - 1] = i;
  }

  for (int i = 0; i < 252; i++) {
    int swap = rand() % 8;
    byte temp = places[i];
    places[i] = places[swap];
    places[swap] = temp;
  }

  for (int i = 0; i < 252; i++) {
    //Serial.println(places[i]);
  }
  for (int i = 0; i < 252; i++) {
    pixels.setPixelColor(places[i], pixels.Color(0, 0, 0));
    glitter();
    turned_on[places[i]] = 0;
    pixels.show();
    delay(1);
  }

}
int state = 0;

void loop() {

  /*-----------------------------------------------------*/
  /*
  */
  /*-----------------------------------------------------*/

  shift_Effect();
  sharp_center();
  delay(10);
  
  /*-----------------------------------------------------*/

}
