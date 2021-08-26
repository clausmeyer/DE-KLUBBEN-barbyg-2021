#include <Adafruit_NeoPixel.h>

#define PIN            15
#define NUMPIXELS      70

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 100; // delay for half a second

//byte *led_pointers[10];
byte rings[5] = {19, 14, 10, 6, 1};
byte ringStart[5] = {0, 20, 34, 44, 50};

byte turned_on[NUMPIXELS];

void setRingLight(int ringNum, bool On) {
  byte rgb[5][3] = {{0 , 0, 50},
    {0 , 100, 0},
    {150 , 0, 0},
    {200 , 0, 0},
    {200, 0, 0}
  };

  if (ringNum >= 0 && ringNum < 5) {
    pixels.fill(pixels.Color(rgb[ringNum][0]*On, rgb[ringNum][1]*On, rgb[ringNum][2]*On), ringStart[ringNum], rings[ringNum]);
  }
}

void incommingSignal() {
  int limit = millis() / delayVal % 8;

  setRingLight(limit, true);
  setRingLight(limit + 2, true);
  setRingLight(limit - 2, true);

  pixels.show();
  setRingLight(limit, false);
  setRingLight(limit + 2, false);
  setRingLight(limit - 2, false);
}

void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  incommingSignal();
}
