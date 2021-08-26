#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      454

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 100; // delay for half a second

//byte *led_pointers[10];

void theaterChase(uint32_t color, int start, int numLed, int velocity, int stepSize) {
  byte offset = millis() / velocity % abs(stepSize);
  if (stepSize > 0) {
    for (int c = offset + start; c < numLed + start; c += stepSize) {
      pixels.setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
  else {
    for (int c = start - offset - stepSize - 1; c < numLed + start; c -= stepSize) {
      pixels.setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
}


void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  //  theaterChase(pixels.Color(Red, Green, Blue), Start, NumLeds, Interval, stepSize);
   int dir = (millis()/1000%2)*2-1;
   int col1 = (millis()/1000%2);
   int col2 = ((millis()/1000)+1)%2;
   
  // 230V AC
  theaterChase(pixels.Color(20*col1, 0, 20*col2), 0, 34, 10, 5*dir);         // Top
  theaterChase(pixels.Color(20*col2, 0, 20*col1), 423, 31, 10, 5*dir);       //Bottom

  // 12V AC
  theaterChase(pixels.Color(20*col1, 0, 20*col2), 34, 123, 25, 3*dir);    // Top
  theaterChase(pixels.Color(20*col2, 0, 20*col1), 369, 54, 25, 3*dir);   // Bottom
  
  // 12V DC
  theaterChase(pixels.Color(20, 0, 0), 262, 107, 25, -3);   // Top
  theaterChase(pixels.Color(0, 0, 20), 157, 105, 25, -3);  // Bottom
  pixels.show(); // Update strip with new contents
  pixels.clear();
  // pixels.fill(pixels.Color(0, 0, 0), 0, 454);

}
