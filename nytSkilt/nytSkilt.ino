#include <Adafruit_NeoPixel.h>

#define NUMPIXELS_SIDE 11
#define NUMPIXELS_TOP 18
#define PIN_1 18
#define PIN_2 26
int tick = 3500 / (NUMPIXELS_SIDE - 1);
int egern_interrupt = 12;
int skilt_interrupt = 13;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(550, 15, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel armRight = Adafruit_NeoPixel(150, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel armLeft = Adafruit_NeoPixel(150, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel capacitor_1 = Adafruit_NeoPixel(2 * NUMPIXELS_SIDE + NUMPIXELS_TOP, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel capacitor_2 = Adafruit_NeoPixel(2 * NUMPIXELS_SIDE + NUMPIXELS_TOP, PIN_2, NEO_GRB + NEO_KHZ800);

struct segment {
  uint32_t LEDcolor;
  int LEDstart;
  int LEDnumber;
  int LEDvelocity;
  int LEDstepsize;
};

segment armRight_1 = {armRight.Color(0, 200, 200), 0, 24, 150, 3};
segment armRight_2 = {armRight.Color(0, 200, 200), 24, 88, 150, 3};

segment armLeft_1 = {armLeft.Color(0, 200, 200), 0, 24, 150, 3};
segment armLeft_2 = {armLeft.Color(0, 200, 200), 24, 93, 150, 3};

segment voltageRail = {pixels.Color(0, 200, 200), 0, 107, 150, 3};
segment column1_1 = {pixels.Color(0, 200, 200), 330, 21, 150, -3};
segment column1_2 = {pixels.Color(0, 200, 200), 351, 24, 150, -3};
segment column2 = {pixels.Color(0, 200, 200), 376, 46, 150, 3};
segment column3 = {pixels.Color(0, 200, 200), 110, 46, 150, 3};
segment column4_0 = {pixels.Color(0, 200, 200), 107, 3, 150, 3};
segment column4_1 = {pixels.Color(0, 200, 200), 156, 24, 150, 3};
segment column4_2 = {pixels.Color(0, 200, 200), 180, 18, 150, 3};


segment baseRight_1 = {pixels.Color(0, 200, 200), 199, 17, 150, -3};
segment baseRight_2 = {pixels.Color(0, 200, 200), 216, 14, 150, -3};
segment baseLeft_1 = {pixels.Color(0, 200, 200), 299, 14, 150, 3};
segment baseLeft_2 = {pixels.Color(0, 200, 200), 313, 17, 150, 3};

segment crossRight = {pixels.Color(0, 200, 200), 230, 34, 150, 3};
segment crossLeft = {pixels.Color(0, 200, 200), 264, 35, 150, 3};

segment emitterRight = {pixels.Color(0, 200, 200), 422, 8, 150, 3};
segment emitterLeft = {pixels.Color(0, 200, 200), 477, 8, 150, -3};

segment groundRail = {pixels.Color(0, 200, 200), 430, 47, 150, 1};


void chargeUp(Adafruit_NeoPixel *strip, int PIN) {
  float brightness = analogRead(PIN);
  for (int i = 0; i <= NUMPIXELS_SIDE - 1; i++) {
    if (brightness > tick * i) {
      strip->setPixelColor(i, 0, brightness / 16, brightness / 16);
      strip->setPixelColor(39 - i, 0, brightness / 16, brightness / 16);
    }
    else {
      strip->setPixelColor(i, 0, 0, 0);
      strip->setPixelColor(39 - i, 0, 0, 0);

    }
    if (brightness > tick * i and i == NUMPIXELS_SIDE - 1) {
      strip->fill(strip->Color(0, brightness / 16, brightness / 16), NUMPIXELS_SIDE, NUMPIXELS_TOP);
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
}
void theaterChase(Adafruit_NeoPixel *strip, uint32_t color, int start, int numLed, int velocity, int stepSize) {
  byte offset = millis() / velocity % abs(stepSize);
  if (stepSize > 0) {
    for (int c = offset + start; c < numLed + start; c += stepSize) {
      strip->setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
  else {
    for (int c = start - offset - stepSize - 1; c < numLed + start; c -= stepSize) {
      strip->setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(egern_interrupt, OUTPUT);
  pinMode(skilt_interrupt, OUTPUT);
  pixels.begin();
  armRight.begin();
  armLeft.begin();
  capacitor_1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  capacitor_2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  analogSetPinAttenuation(A0, ADC_11db);
  analogSetPinAttenuation(A6, ADC_11db);

  pinMode(A0, INPUT);
  pinMode(A6, INPUT);

}
void loop() {
  
  int A0_val = analogRead(A0);
  int A6_val = analogRead(A6);
  chargeUp(&capacitor_2, A6);
  chargeUp(&capacitor_1, A0);
  theaterChase(&pixels, voltageRail.LEDcolor, voltageRail.LEDstart, voltageRail.LEDnumber, voltageRail.LEDvelocity, voltageRail.LEDstepsize);
  theaterChase(&pixels, column1_1.LEDcolor, column1_1.LEDstart, column1_1.LEDnumber, column1_1.LEDvelocity, column1_1.LEDstepsize);
  theaterChase(&pixels, column1_2.LEDcolor, column1_2.LEDstart, column1_2.LEDnumber, column1_2.LEDvelocity, column1_2.LEDstepsize);
  theaterChase(&pixels, column2.LEDcolor, column2.LEDstart, column2.LEDnumber, column2.LEDvelocity, column2.LEDstepsize);
  theaterChase(&pixels, column3.LEDcolor, column3.LEDstart, column3.LEDnumber, column3.LEDvelocity, column3.LEDstepsize);
  theaterChase(&pixels, column4_0.LEDcolor, column4_0.LEDstart, column4_0.LEDnumber, column4_0.LEDvelocity, column4_0.LEDstepsize);
  theaterChase(&pixels, column4_1.LEDcolor, column4_1.LEDstart, column4_1.LEDnumber, column4_1.LEDvelocity, column4_1.LEDstepsize);
  theaterChase(&pixels, column4_2.LEDcolor, column4_2.LEDstart, column4_2.LEDnumber, column4_2.LEDvelocity, column4_2.LEDstepsize);

  theaterChase(&pixels, baseRight_1.LEDcolor, baseRight_1.LEDstart, baseRight_1.LEDnumber, baseRight_1.LEDvelocity, baseRight_1.LEDstepsize);
  theaterChase(&pixels, baseLeft_1.LEDcolor, baseLeft_1.LEDstart, baseLeft_1.LEDnumber, baseLeft_1.LEDvelocity, baseLeft_1.LEDstepsize);
  theaterChase(&pixels, baseRight_2.LEDcolor, baseRight_2.LEDstart, baseRight_2.LEDnumber, baseRight_2.LEDvelocity, baseRight_2.LEDstepsize);
  theaterChase(&pixels, baseLeft_2.LEDcolor, baseLeft_2.LEDstart, baseLeft_2.LEDnumber, baseLeft_2.LEDvelocity, baseLeft_2.LEDstepsize);

  theaterChase(&pixels, crossRight.LEDcolor, crossRight.LEDstart, crossRight.LEDnumber, crossRight.LEDvelocity, crossRight.LEDstepsize);
  theaterChase(&pixels, crossLeft.LEDcolor, crossLeft.LEDstart, crossLeft.LEDnumber, crossLeft.LEDvelocity, crossLeft.LEDstepsize);

  theaterChase(&pixels, emitterRight.LEDcolor, emitterRight.LEDstart, emitterRight.LEDnumber, emitterRight.LEDvelocity, emitterRight.LEDstepsize);
  theaterChase(&pixels, emitterLeft.LEDcolor, emitterLeft.LEDstart, emitterLeft.LEDnumber, emitterLeft.LEDvelocity, emitterLeft.LEDstepsize);

  theaterChase(&pixels, groundRail.LEDcolor, groundRail.LEDstart, groundRail.LEDnumber, groundRail.LEDvelocity, groundRail.LEDstepsize);

  theaterChase(&armRight, armRight_1.LEDcolor, armRight_1.LEDstart, armRight_1.LEDnumber, armRight_1.LEDvelocity, armRight_1.LEDstepsize);
  theaterChase(&armRight, armRight_2.LEDcolor, armRight_2.LEDstart, armRight_2.LEDnumber, armRight_2.LEDvelocity, armRight_2.LEDstepsize);

  theaterChase(&armLeft, armLeft_1.LEDcolor, armLeft_1.LEDstart, armLeft_1.LEDnumber, armLeft_1.LEDvelocity, armLeft_1.LEDstepsize);
  theaterChase(&armLeft, armLeft_2.LEDcolor, armLeft_2.LEDstart, armLeft_2.LEDnumber, armLeft_2.LEDvelocity, armLeft_2.LEDstepsize);

  if (A0_val >= A6_val) {
          digitalWrite(skilt_interrupt, LOW);
          digitalWrite(egern_interrupt, HIGH);
          armLeft_2.LEDcolor = armLeft.Color(0, 200, 200);
          armRight_2.LEDcolor = armRight.Color(0, 0, 0);
          armRight_1.LEDstepsize = -3;
          armLeft_1.LEDstepsize = 3;
          crossRight.LEDstepsize = -3;
          crossLeft.LEDstepsize = -3;
          baseRight_2.LEDstepsize = -3;
          baseLeft_1.LEDstepsize = -3;
          baseLeft_1.LEDvelocity = 150;
          baseLeft_2.LEDvelocity = 20000;
          crossLeft.LEDvelocity = 150;
          baseRight_1.LEDvelocity = 150;
          baseRight_2.LEDvelocity = 150;
          column1_1.LEDvelocity = 20000;
          column4_2.LEDvelocity = 150;
          emitterLeft.LEDvelocity = 150;
          emitterRight.LEDvelocity = 20000;
        }
        else {
          digitalWrite(skilt_interrupt, HIGH);
          digitalWrite(egern_interrupt, LOW);
          armLeft_2.LEDcolor = armLeft.Color(0, 0, 0);
          armRight_2.LEDcolor = armRight.Color(0, 200, 200);
          armLeft_1.LEDstepsize = -3;
          armRight_1.LEDstepsize = 3;
          crossRight.LEDstepsize = 3;
          crossLeft.LEDstepsize = 3;
          baseRight_2.LEDstepsize = 3;
          baseLeft_1.LEDstepsize = 3;
          baseLeft_1.LEDvelocity = 150;
          baseLeft_2.LEDvelocity = 150;
          crossLeft.LEDvelocity = 150;
          baseRight_1.LEDvelocity = 20000;
          baseRight_2.LEDvelocity = 150;
          column1_1.LEDvelocity = 150;
          column4_2.LEDvelocity = 20000;
          emitterRight.LEDvelocity = 150;
          emitterLeft.LEDvelocity = 20000;
          
        }

  pixels.show();
  pixels.clear();
  armRight.show();
  armRight.clear();
  armLeft.show();
  armLeft.clear();
  capacitor_1.show();
  capacitor_1.clear();
  capacitor_2.show();
  capacitor_2.clear();
  // put your main code here, to run repeatedly:

}
