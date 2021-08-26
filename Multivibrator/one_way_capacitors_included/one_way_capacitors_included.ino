#include <Adafruit_NeoPixel.h>

#define PIN_0 15
#define NUM_PIXELS 430
#define NUMPIXELS_SIDE 11
#define NUMPIXELS_TOP 18
#define PIN_1 18
#define PIN_2 26

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN_0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel arm_1 = Adafruit_NeoPixel(150, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel arm_2 = Adafruit_NeoPixel(150, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel capacitor_1 = Adafruit_NeoPixel(2 * NUMPIXELS_SIDE + NUMPIXELS_TOP, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel capacitor_2 = Adafruit_NeoPixel(2 * NUMPIXELS_SIDE + NUMPIXELS_TOP, PIN_2, NEO_GRB + NEO_KHZ800);

unsigned long last_time = 0;
unsigned long current_time = 0;
bool flag = 0;
int segment_1[107];
int segment_2[45]; // 110 til 155
int segment_3[45]; // 107 til 110 og 156 til 198
int segment_4[45]; // 330 til 375
int segment_5[45]; // 376 til 421
int segment_6[31]; // 199 til 229
int segment_7[34]; // 230 til 263
int segment_8[35]; // 264 til 298
int segment_9[31]; // 299 til 329

int segment_1_arm_1[30];
int segment_2_arm_1[88];

int segment_1_arm_2[25];
int segment_2_arm_2[93];
const int R_val = 250;
int delayval = 30;

int count_8 = 0;
int count_7 = 0;
int count_6 = 0;
int count_5 = 0;
int count_4 = 0;
int count_3 = 0;
int count_2 = 0;
int count_1 = 0;
int count_2_arm_1 = 0;
int count_1_arm_1 = 0;
int count_2_arm_2 = 0;
int count_1_arm_2 = 0;


int tick = 4095 / (NUMPIXELS_SIDE - 1);
bool cap_1 = false;
bool cap_2 = false;

void chargeUp(Adafruit_NeoPixel *strip, int PIN) {
  float brightness = analogRead(PIN);
  for (int i = 0; i <= NUMPIXELS_SIDE - 1; i++) {
    if (brightness > tick * i) {
      strip->setPixelColor(i, 0, 0, brightness / 16);
      strip->setPixelColor(39 - i, 0, 0, brightness / 16);
    }
    else {
      strip->setPixelColor(i, 0, 0, 0);
      strip->setPixelColor(39 - i, 0, 0, 0);

    }
    if (brightness > tick * i and i == NUMPIXELS_SIDE - 1) {
      strip->fill(strip->Color(0, 0, brightness / 16), NUMPIXELS_SIDE, NUMPIXELS_TOP);
    }
    else
    {
      strip->fill(strip->Color(0, 0, 0), NUMPIXELS_SIDE, NUMPIXELS_TOP);
    }
  }
  //  capacitor_1.fill(capacitor_1.Color(0, 0, brightness / 16), 0);
  strip->show();   // Send the updated pixel colors to the hardware.
  if (PIN == A0) {
    digitalWrite(21, LOW);
  }

  //Serial.print(PIN);
  //Serial.print("\t");
  //Serial.println(brightness * (3.0 / 4094.0));
}


void turn_all_off() {
  for (int j = 0; j < 422; j++) {
    pixels.setPixelColor(j, pixels.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels.show();
}
int row_1_count = 0;
void row_1() {
  for (int i = 0; i < sizeof(segment_4) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_4[(i + row_1_count)], pixels.Color(0, 0, 0));
  }
  row_1_count++;
  for (int i = 0; i < sizeof(segment_4) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_4[(i + row_1_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_1_count > 2) row_1_count = 0;
}

int row_2_count = 0;
void row_2() {
  for (int i = 0; i < sizeof(segment_5) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_5[(i + row_2_count)], pixels.Color(0, 0, 0));
  }
  row_2_count++;
  for (int i = 0; i < sizeof(segment_5) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_5[(i + row_2_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_2_count > 2) row_2_count = 0;
}

int row_3_count = 0;
void row_3() {
  for (int i = 0; i < sizeof(segment_2) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_2[(i + row_3_count)], pixels.Color(0, 0, 0));
  }
  row_3_count++;
  for (int i = 0; i < sizeof(segment_2) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_2[(i + row_3_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_3_count > 2) row_3_count = 0;
}

int row_4_count = 0;
void row_4() {
  for (int i = 0; i < sizeof(segment_3) / 4 - 17; i = i + 3) {
    pixels.setPixelColor(segment_3[(i + row_4_count)], pixels.Color(0, 0, 0));
  }
  row_4_count++;
  for (int i = 0; i < sizeof(segment_3) / 4 - 19; i = i + 3) {
    pixels.setPixelColor(segment_3[(i + row_4_count)], pixels.Color(R_val, 0, 0));
  }

  for (int i = sizeof(segment_3) / 4 - 17; i < sizeof(segment_3) / 4 ; i = i + 3) {
    pixels.setPixelColor(segment_3[(i)], pixels.Color(R_val, 0, 0));
  }
  if (row_4_count > 2) row_4_count = 0;
}

int row_5_count = 0;
void row_5() {
  for (int i = sizeof(segment_6) / 4 - 12; i < sizeof(segment_6) / 4 - 2; i = i + 3)  {
    pixels.setPixelColor(segment_6[(i + row_5_count)], pixels.Color(0, 0, 0));
  }
  row_5_count++;
  for (int i = 0; i < sizeof(segment_6) / 4 - 12; i = i + 3) {
    pixels.setPixelColor(segment_6[(i )], pixels.Color(R_val, 0, 0));
  }

  for (int i = sizeof(segment_6) / 4 - 12; i < sizeof(segment_6) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_6[(i + row_5_count )], pixels.Color(R_val, 0, 0));
  }
  if (row_5_count > 2) row_5_count = 0;
}
int row_6_count = 0;
void row_6() {
  for (int i = 0; i < sizeof(segment_7) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_7[(i + row_6_count)], pixels.Color(0, 0, 0));
  }
  row_6_count++;
  for (int i = 0; i < sizeof(segment_7) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_7[(i + row_6_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_6_count > 2) row_6_count = 0;
}
int row_7_count = 0;
void row_7() {
  for (int i = 0; i < sizeof(segment_8) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_8[(i + row_7_count)], pixels.Color(0, 0, 0));
  }
  row_7_count++;
  for (int i = 0; i < sizeof(segment_8) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_8[(i + row_7_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_7_count > 2) row_7_count = 0;
}
int row_8_count = 0;
void row_8() {
  for (int i = 0; i < sizeof(segment_9) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_9[(i + row_8_count)], pixels.Color(0, 0, 0));
  }
  row_8_count++;
  for (int i = 0; i < sizeof(segment_9) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_9[(i + row_8_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_8_count > 2) row_8_count = 0;
}

int row_1_arm_1_count = 0;
void row_1_arm_1() {
  for (int i = 0; i < sizeof(segment_1_arm_1) / 4 - 2; i = i + 3) {
    arm_1.setPixelColor(segment_1_arm_1[(i + row_1_arm_1_count)], arm_1.Color(0, 0, 0));
  }
  row_1_arm_1_count++;
  for (int i = 0; i < sizeof(segment_1_arm_1) / 4 - 2; i = i + 3) {
    arm_1.setPixelColor(segment_1_arm_1[(i + row_1_arm_1_count)], arm_1.Color(R_val, 0, 0));
  }
  if (row_1_arm_1_count > 2) row_1_arm_1_count = 0;
}

int row_2_arm_1_count = 0;
void row_2_arm_1() {
  for (int i = 0; i < sizeof(segment_2_arm_1) / 4 + 4; i = i + 1) {
    arm_1.setPixelColor(segment_2_arm_1[(i )], arm_1.Color(0, 0, 0));
  }
  row_2_arm_1_count++;
  /*for (int i = 0; i < sizeof(segment_2_arm_1) / 4 - 2; i = i + 3) {
    arm_1.setPixelColor(segment_2_arm_1[(i )], arm_1.Color(R_val, 0, 0));
    }*/
  if (row_2_arm_1_count > 2) row_2_arm_1_count = 0;
}

int row_1_arm_2_count = 0;
void row_1_arm_2() {
  for (int i = 0; i < sizeof(segment_1_arm_2) / 4 - 2; i = i + 3) {
    arm_2.setPixelColor(segment_1_arm_2[(i + row_1_arm_2_count)], arm_2.Color(0, 0, 0));
  }
  row_1_arm_2_count++;
  for (int i = 0; i < sizeof(segment_1_arm_2) / 4 - 2; i = i + 3) {
    arm_2.setPixelColor(segment_1_arm_2[(i + row_1_arm_2_count)], arm_2.Color(R_val, 0, 0));
  }
  if (row_1_arm_2_count > 2) row_1_arm_2_count = 0;
}

int row_2_arm_2_count = 0;
void row_2_arm_2() {
  for (int i = 0; i < sizeof(segment_2_arm_2) / 4 - 2; i = i + 3) {
    arm_2.setPixelColor(segment_2_arm_2[(i + row_2_arm_2_count)], arm_2.Color(0, 0, 0));
  }
  row_2_arm_2_count++;
  for (int i = 0; i < sizeof(segment_2_arm_2) / 4 - 2; i = i + 3) {
    arm_2.setPixelColor(segment_2_arm_2[(i + row_2_arm_2_count)], arm_2.Color(R_val, 0, 0));
  }
  if (row_2_arm_2_count > 2) row_2_arm_2_count = 0;
}

void one_way() {
  if (count_1_arm_1 == 4)
  {
    row_1_arm_1();
    count_1_arm_1 = 0;
  }
  if (count_1_arm_2 == 4)
  {
    row_1_arm_2();
    count_1_arm_2 = 0;
  }

  if (count_2_arm_2 == 2)
  {
    row_2_arm_2();
    count_2_arm_2 = 0;
  }
  //row_1_arm_1();
  row_2_arm_1();
  //row_1_arm_2();
  //row_2_arm_2();
  if (count_8 == 6) {
    row_8();
    count_8 = 0;
  }
  if (count_7 == 4) {
    row_7();
    count_7 = 0;
  }
  if (count_6 == 4) {
    row_6();
    count_6 = 0;
  }
  if (count_5 == 4) {
    row_5();
    count_5 = 0;
  }

  if (count_4 >= 6) {
    row_4();
    count_4 = 0;
  }
  if (count_3 == 4) {
    row_3();
    count_3 = 0;
  }
  if (count_2 == 4) {
    row_2();
    count_2 = 0;
  }
  if (count_1 >= 2) {
    row_1();
    count_1 = 0;
  }

}

void other_way() {
  if (count_1_arm_1 == 4)
  {
    row_1_arm_1_other_way();
    count_1_arm_1 = 0;
  }
  if (count_1_arm_2 == 4)
  {
    row_1_arm_2_other_way();
    count_1_arm_2 = 0;
  }

  if (count_2_arm_2 == 2)
  {
    row_2_arm_1_other_way();
    count_2_arm_2 = 0;
  }
  //row_1_arm_1();
  row_2_arm_2_other_way();
  //row_1_arm_2();
  //row_2_arm_2();
  if (count_8 == 6) {
    row_8_other_way();
    count_8 = 0;
  }
  if (count_7 == 4) {
    row_7_other_way();
    count_7 = 0;
  }
  if (count_6 == 4) {
    row_6_other_way();
    count_6 = 0;
  }
  if (count_5 == 4) {
    row_5_other_way();
    count_5 = 0;
  }

  if (count_4 >= 2) {
    row_4_other_way();
    count_4 = 0;
  }
  if (count_3 == 4) {
    row_3_other_way();
    count_3 = 0;
  }
  if (count_2 == 4) {
    row_2_other_way();
    count_2 = 0;
  }
  if (count_1 >= 6) {
    row_1_other_way();
    count_1 = 0;
  }
}

void setup() {

  capacitor_1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  capacitor_2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  analogSetPinAttenuation(A0, ADC_11db);
  analogSetPinAttenuation(A6, ADC_11db);





  pinMode(A0, INPUT);
  pinMode(A6, INPUT);
  int j = 0;
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i = 0; i < 107; i++) {
    segment_1[i] = i;
  }
  for (int i = 110; i < 155; i++) {
    segment_2[j] = i;
    j++;
  }
  j = 0;
  for (int i = 107; i < 110; i++) {
    segment_3[j] = i;
    j++;
  }

  for (int i = 156; i < 198; i++) {
    segment_3[j] = i;
    j++;
  }
  j = 0;
  for (int i = 374; i > 330; i--) {
    segment_4[j] = i;
    j++;
  }
  j = 0;
  for (int i = 376; i < 421; i++) {
    segment_5[j] = i;
    j++;
  }
  j = 0;
  for (int i = 199; i < 229; i++) {
    segment_6[j] = i;
    j++;
  }
  j = 0;
  for (int i = 230; i < 263; i++) {
    segment_7[j] = i;
    j++;
  }
  j = 0;
  for (int i = 264; i < 298; i++) {
    segment_8[j] = i;
    j++;
  }
  j = 0;
  for (int i = 299; i < 329; i++) {
    segment_9[j] = i;
    j++;
  }
  j = 0;

  for (int i = 24; i > -1; i--) {
    segment_1_arm_1[j] = i;
    j++;
  }
  j = 0;

  for (int i = 25; i < 117; i++) {
    segment_2_arm_1[j] = i;
    j++;
  }
  j = 0;

  for (int i = 0; i < 25; i++) {
    segment_1_arm_2[j] = i;
    j++;
  }
  j = 0;

  for (int i = 25; i < 117; i++) {
    segment_2_arm_2[j] = i;
    j++;
  }
  j = 0;

  pixels.begin();
  arm_1.begin();
  arm_2.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int j = 0; j < 3; j++) {

    count_8++;
    count_7++;
    count_6++;
    count_5++;
    count_4++;
    count_3++;
    count_2++;
    count_1++;

    count_2_arm_1++;
    count_1_arm_1++;
    count_2_arm_2++;
    count_1_arm_2++;

    for (int i = 0; i < sizeof(segment_1) / 4 - 2; i = i + 3) {
      //if(i+j > 107) i = i-107;
      pixels.setPixelColor(segment_1[i + j], pixels.Color(R_val, 0, 0));
    }
    int A0_val = analogRead(A0);
    int A6_val = analogRead(A6);
    Serial.println("AM HERE D:");
    chargeUp(&capacitor_2, A6);
    chargeUp(&capacitor_1, A0);
    if (A0_val >= A6_val) {
      flag = true;
    }
    else {
      flag = false;
    }
    /*
      current_time = millis();

      if(current_time > last_time+5000){
      flag = !flag;
      last_time = current_time;
      }*/

    if (flag) one_way();
    else other_way();

    /*
          if ((i+j) % 4 == 0) {
            pixels.setPixelColor(segment_2[(i+j) / 4], pixels.Color(R_val, 0, 0));
            pixels.setPixelColor(segment_2[(i+j) / 4 + 1], pixels.Color(0, 0, 0));
            pixels.setPixelColor(segment_2[(i+j) / 4 + 2], pixels.Color(0, 0, 0));
          }
          else if ((i+j) % 3 == 0) {
            pixels.setPixelColor(segment_3[(i+j) / 4], pixels.Color(R_val, 0, 0));
            pixels.setPixelColor(segment_3[(i+j) / 4 + 1], pixels.Color(0, 0, 0));
            pixels.setPixelColor(segment_3[(i+j) / 4 + 2], pixels.Color(0, 0, 0));
          }
          else if ((i+j) % 2 == 0) {
            pixels.setPixelColor(segment_4[(i+j) / 4], pixels.Color(R_val, 0, 0));
            pixels.setPixelColor(segment_4[(i+j) / 4 + 1], pixels.Color(0, 0, 0));
            pixels.setPixelColor(segment_4[(i+j) / 4 + 2], pixels.Color(0, 0, 0));
          }

        }*/
    pixels.show();
    arm_1.show();
    arm_2.show();
    delay(delayval);
    //turn_all_off();
    for (int i = 0; i < sizeof(segment_1) - 2; i = i + 3) {
      //if(i+j > 107) i = i-107;
      pixels.setPixelColor(segment_1[i + j], pixels.Color(0, 0, 0));

    }
    //    if (count_5 == 4) {
    //      count_5 = 0;
    //
    //    }
  }
}
