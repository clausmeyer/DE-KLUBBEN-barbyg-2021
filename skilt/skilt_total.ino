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

void sharp_center(byte red, byte green, byte blue) {
  int centerColor = 200;
  float colourFall = 20;
  int fallLength = 20;
  int delayval = 200 / 10;

  for (int i = 0; i < sizeof(column_length_all) + fallLength * 2; i++) {
    //turn_all_off();
    //columnColors[i] = centerColor;
    int cnt = i - fallLength;

    if (cnt >= 0 && cnt < sizeof(column_length_all)) {
      flash_letter(column_pointers_all[cnt], column_length_all[cnt], red, green, blue);
    }
    for (int j = 1; j < fallLength; j++) {
      if (cnt + j >= 0 && cnt + j < sizeof(column_length_all)) {
        //flash_letter(column_pointers_all[cnt + j], column_length_all[cnt + j], red - (colourFall * j), green - (colourFall * j), blue - (colourFall * j));
        flash_letter(column_pointers_all[cnt + j], column_length_all[cnt + j], red * (1 - (j / colourFall)), green * (1 - (j / colourFall)), blue * (1 - (j / colourFall)));
      }
      if (cnt - j >= 0 && cnt - j < sizeof(column_length_all)) {
        //flash_letter(column_pointers_all[cnt - j], column_length_all[cnt - j], red - (colourFall * j), green - (colourFall * j), blue - (colourFall * j));
        flash_letter(column_pointers_all[cnt - j], column_length_all[cnt - j], red * (1 - (j / colourFall)), green * (1 - (j / colourFall)), blue * (1 - (j / colourFall)));
      }
    }

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

  for (int i = 0; i < sizeof(column_length_all) + tail; i++) {//wipe the board
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
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
    turned_on[j] = 1;
    glitter();
    pixels.show();
  }
  for (int count = 0; count < 5; count++) {
    for (int j = 0; j < 253; j++) {
      int k = j + 85;
      int l = j - 85;
      if (k > 252) k = k - 253;
      if (l < 0) l = l + 253;
      pixels.setPixelColor(j, pixels.Color(255, 0, 0));
      pixels.setPixelColor(k, pixels.Color(0, 255, 0));
      pixels.setPixelColor(l, pixels.Color(0, 0, 255));
      turned_on[j] = 1;
      pixels.show();
      //glitter();
      //delay(1);
    }
  }
  for (int j = 85; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 255, 0)); // Moderately bright green color.
    pixels.show();
  }
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 255)); // Moderately bright green color.
    pixels.show();
  }
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
    pixels.show();
  }
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
  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(126 + j, pixels.Color(0, 0, 255));
    pixels.setPixelColor(126 - j, pixels.Color(0, 0, 255));
    pixels.show();
    delay(1);
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 253; j++) {
      pixels.setPixelColor(j, pixels.Color(255, 0, 0)); // Moderately bright green color.
      pixels.setPixelColor(253 - j, pixels.Color(0, 0, 255));
      pixels.setPixelColor(126 + j, pixels.Color(0, 255, 0));
      pixels.setPixelColor(126 - j, pixels.Color(0, 255, 0));
      pixels.show();
      delay(1);
    }
  }

  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(126 + j, pixels.Color(0, 0, 255));
    pixels.setPixelColor(126 - j, pixels.Color(0, 0, 255));
    pixels.show();
    delay(1);
  }

  for (int j = 0; j < 253; j++) {
    pixels.setPixelColor(126 + j, pixels.Color(0, 0, 0));
    pixels.setPixelColor(126 - j, pixels.Color(0, 0, 0));
    pixels.show();
    delay(1);
  }

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

void glimmer() {
  current_time = millis();
  by_columns();

  last_time = millis();
  current_time = millis();
  while (current_time < last_time + 10000) {
    current_time = millis();
    glitter();
  }
  last_time = millis();
  stochastic_fade_out();
}

int val = 10;
bool flag = 1;
void loop() {

  /*-----------------------------------------------------*/
  /*
  */
  /*-----------------------------------------------------*/
  //fade_in_and_out();
  //change_colors();
  current_time = millis();
  if (current_time > last_time + 3000) {
    Serial.println(1);
    last_time = millis();
    state = state + 1;
    turn_off_counter = 0;
    /*for (int i = 0; i < 253; i++) {
      pixels.setPixelColor(i, pixels.Color(150, 0, 0));
      }*/
    if (state > 3) state = 0;

  }


  /*switch (state) {
    case 0:
      Serial.println("fade");
      by_columns();
      break;
    case 1:
      Serial.println("glitter");
      glitter();
      break;
    case 2:
      Serial.println("glitter");
      glitter();
      break;
    case 3:
      Serial.println("in");
      stochastic_fade_out();
      break;
    }*/

  //sharp_center();
  //fill_from_left();
  //single_from_left();
  three_colors();//used
  //by_columns();
  back_and_forth();//used
  glimmer();//used
  sharp_center(150, 0, 50);
  sharp_center(0, 200, 0);
  sharp_center(0, 0, 200);

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
