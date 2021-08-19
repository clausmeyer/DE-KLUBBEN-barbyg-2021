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

const byte interruptPin = 2;
volatile bool interrupted = false;

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

void sharp_center(byte red, byte green, byte blue) {
  if (interrupted == true) return;
  int centerColor = 200;
  float colourFall = 20;
  int fallLength = 20;
  int delayval = 200 / 10;

  for (int i = 0; i < sizeof(column_length_all) + fallLength * 2; i++) {
    if (interrupted == true) return;
    //turn_all_off();
    //columnColors[i] = centerColor;
    int cnt = i - fallLength;

    if (cnt >= 0 && cnt < sizeof(column_length_all)) {
      flash_letter(column_pointers_all[cnt], column_length_all[cnt], red, green, blue);
    }
    for (int j = 1; j < fallLength; j++) {
      if (interrupted == true) return;
      if (cnt + j >= 0 && cnt + j < sizeof(column_length_all)) {
        //flash_letter(column_pointers_all[cnt + j], column_length_all[cnt + j], red - (colourFall * j), green - (colourFall * j), blue - (colourFall * j));
        flash_letter(column_pointers_all[cnt + j], column_length_all[cnt + j], red * (1 - (j / colourFall)), green * (1 - (j / colourFall)), blue * (1 - (j / colourFall)));
      }
      if (cnt - j >= 0 && cnt - j < sizeof(column_length_all)) {
        //flash_letter(column_pointers_all[cnt - j], column_length_all[cnt - j], red - (colourFall * j), green - (colourFall * j), blue - (colourFall * j));
        flash_letter(column_pointers_all[cnt - j], column_length_all[cnt - j], red * (1 - (j / colourFall)), green * (1 - (j / colourFall)), blue * (1 - (j / colourFall)));
      }
    }
    if (interrupted == true) return;
    pixels.show();
    delay(delayval);
    //turn_all_off();
    if (cnt - fallLength >= 0 && cnt - fallLength < sizeof(column_length_all)) {
      flash_letter(column_pointers_all[cnt - fallLength], column_length_all[cnt - fallLength], 0, 0, 0);
    }
  }

}


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

void interruptFunc() {

  int delayval = 200 / 10;
  int tail = 5;

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
  }
  interrupted = true;

}

void setup() {

  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  last_time = millis();
  current_time = millis();
  last_time_glitter = millis();
  current_time_glitter = millis();
  last_time_fade_in = millis();
  current_time_fade_in = millis();

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunc, RISING);
}


void by_columns() {


  int delayval_col = 0;
  int R_val = 255;
  for (int i = 0; i < sizeof(column_length_all); i++) {
    flash_letter(column_pointers_all[i], column_length_all[i], 255, 0, 0);
    current_time_fade_in = millis();
    while (current_time_fade_in < last_time_fade_in + 20) {
      glitter();
      current_time_fade_in = millis();
    }
    last_time_fade_in = current_time_fade_in;
  }

  //pixels.show();
  //delay(delayval_col * 50);
  //turn_all_off();
}

void single_from_left() {
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
    turned_on[j] = 1;
    pixels.show();
    glitter();
    //delay(1);
  }
  //delay(1000);
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); // Moderately bright green color.
    turned_on[j] = 0;
    pixels.show();
    glitter();
    //delay(1);
  }
  //turn_all_off();
}

void three_colors() {
  if (interrupted == true) return;
  for (int j = 0; j < 253; j++) {
    if (interrupted == true) return;
    pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
    turned_on[j] = 1;
    glitter();
    pixels.show();
  }
  for (int count = 0; count < 5; count++) {
    if (interrupted == true) return;
    for (int j = 0; j < 253; j++) {
      if (interrupted == true) return;
      int k = j + 85;
      int l = j - 85;
      if (k > 252) k = k - 253;
      if (l < 0) l = l + 253;
      pixels.setPixelColor(j, pixels.Color(255, 0, 0));
      pixels.setPixelColor(k, pixels.Color(0, 255, 0));
      pixels.setPixelColor(l, pixels.Color(0, 0, 255));
      turned_on[j] = 1;
      if (interrupted == true) return;
      pixels.show();
      //glitter();
      //delay(1);
    }
  }
  for (int j = 85; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 255, 0)); // Moderately bright green color.
    if (interrupted == true) return;
    pixels.show();
  }
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 255)); // Moderately bright green color.
    if (interrupted == true) return;
    pixels.show();
  }
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
    if (interrupted == true) return;
    pixels.show();
  }
  if (interrupted == true) return;
  stochastic_fade_out();
  turn_all_off();
  delay(1000);
}

void turn_all_off() {
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); // Moderately bright green color.
    turned_on[j] = 0;
  }
  pixels.show();
}

void back_and_forth() {
  turn_all_off();
  if (interrupted == true) return;
  for (int j = 0; j < 253; j++) {
    if (interrupted == true) return;
    pixels.setPixelColor(126 + j, pixels.Color(0, 0, 255));
    pixels.setPixelColor(126 - j, pixels.Color(0, 0, 255));
    if (interrupted == true) return;
    pixels.show();
    delay(1);
  }
  for (int i = 0; i < 10; i++) {
    if (interrupted == true) return;
    for (int j = 0; j < 253; j++) {
      if (interrupted == true) return;
      pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
      pixels.setPixelColor(253 - j, pixels.Color(0, 0, 255));
      pixels.setPixelColor(126 + j, pixels.Color(0, 255, 0));
      pixels.setPixelColor(126 - j, pixels.Color(0, 255, 0));
      if (interrupted == true) return;
      pixels.show();
      delay(1);
    }
  }

  for (int j = 0; j < 253; j++) {
    if (interrupted == true) return;
    pixels.setPixelColor(126 + j, pixels.Color(0, 0, 255));
    pixels.setPixelColor(126 - j, pixels.Color(0, 0, 255));
    if (interrupted == true) return;
    pixels.show();
    delay(1);
  }

  for (int j = 0; j < 253; j++) {
    if (interrupted == true) return;
    pixels.setPixelColor(126 + j, pixels.Color(0, 0, 0));
    pixels.setPixelColor(126 - j, pixels.Color(0, 0, 0));
    if (interrupted == true) return;
    pixels.show();
    delay(1);
  }

}
void glitter() {
  if (interrupted == true) return;
  int vals;
  current_time_glitter = millis();
  if (current_time_glitter > last_time_glitter + 20) {
    if (interrupted == true) return;
    last_time_glitter = current_time_glitter;
    srand(micros());
    for (int i = 0; i < 253; i++) {
      if (interrupted == true) return;
      if (turned_on[i] > 0) {
        int probab = rand();
        if (probab < 5000) {
          vals = rand() % 255;
          //Serial.println(vals);
          pixels.setPixelColor(i, pixels.Color(vals, 0, 0));
        }
      }
    }
    if (interrupted == true) return;
    pixels.show();
  }


}
byte turn_off_counter = 0;
void stochastic_fade_out() {
  if (interrupted == true) return;
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
    if (interrupted == true) return;
    places[i - 1] = i;
  }

  for (int i = 0; i < 252; i++) {
    if (interrupted == true) return;
    int swap = rand() % 8;
    byte temp = places[i];
    places[i] = places[swap];
    places[swap] = temp;
  }

  for (int i = 0; i < 252; i++) {
    //Serial.println(places[i]);
  }
  for (int i = 0; i < 252; i++) {
    if (interrupted == true) return;
    pixels.setPixelColor(places[i], pixels.Color(0, 0, 0));
    glitter();
    turned_on[places[i]] = 0;
    if (interrupted == true) return;
    pixels.show();
    delay(1);
  }

}
int state = 3;

void glimmer() {
  if (interrupted == true) return;
  current_time = millis();
  by_columns();

  last_time = millis();
  current_time = millis();
  while (current_time < last_time + 10000) {
    if (interrupted == true) return;
    current_time = millis();
    glitter();
  }
  last_time = millis();
  stochastic_fade_out();
}

int val = 10;
bool flag = 1;

void loop() {

  if (interrupted == true) {
    int preState = state;
    while (state == preState) {
      state = random(4);
    }
    interrupted = false;
  }

  switch (state) {
    case 0:
      three_colors();
      break;
    case 1:
      back_and_forth();
      break;
    case 2:
      glimmer();
      break;
    case 3:
      sharp_center(200, 0, 0);
      sharp_center(0, 200, 0);
      sharp_center(0, 0, 200);
      break;
  }

  //sharp_center();
  //fill_from_left();
  //single_from_left();
  //used
  //by_columns();
  //used
  //used


  /*
    val=255;
    Serial.println(val);
    for (int j = 0; j < 126; j = j + 2) {
      pixels.setPixelColor(j + 126, pixels.Color(val, 0, 0)); // Moderately bright green color.
      pixels.setPixelColor(126 - j, pixels.Color(val, 0, 0)); // Moderately bright green color.
      pixels.show();

      delay(1);
    }
    for (int j = 1; j < 126; j = j + 2) {
      pixels.setPixelColor(j, pixels.Color(val, 0, 0)); // Moderately bright green color.
      pixels.setPixelColor(252 - j, pixels.Color(val, 0, 0)); // Moderately bright green color.
      pixels.show();
      delay(1);
    }

    for (int j = 0; j < 126; j = j + 2) {
      pixels.setPixelColor(j + 126, pixels.Color(0, 0, val)); // Moderately bright green color.
      pixels.setPixelColor(126 - j, pixels.Color(0, 0, val)); // Moderately bright green color.
      pixels.show();

      delay(1);
    }
    for (int j = 1; j < 126; j = j + 2) {
      pixels.setPixelColor(j, pixels.Color(0, 0, val)); // Moderately bright green color.
      pixels.setPixelColor(252 - j, pixels.Color(0, 0, val)); // Moderately bright green color.
      pixels.show();
      delay(1);
    }*/

  //delay(1000);
  //turn_all_off();


}
