#include <Adafruit_NeoPixel.h>

#define PIN            15
#define NUMPIXELS      437
#define PINPSU         2
#define NUMPIXELSPSU   454

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel psu = Adafruit_NeoPixel(NUMPIXELSPSU, PINPSU, NEO_GRB + NEO_KHZ800);

int delayVal = 100;

bool buttonPressed = false;
unsigned long buttonPressTime;

int targetValue = 0;
int BeerPin = 25;

void theaterChase(uint32_t color, int start, int numLed, int velocity, int stepSize,int offset) {
  int Step = (offset+(millis() / velocity)) % abs(stepSize);
  if (stepSize > 0) {
    for (int c = Step + start; c < numLed + start; c += stepSize) {
      pixels.setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
  else {
    for (int c = start - Step - stepSize - 1; c < numLed + start; c -= stepSize) {
      pixels.setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
}

void dataPacket(uint32_t color, int start, int dest, int offset) {
  int tail = 0;
  int cut = 0;

  if (offset < 7) {
    tail = offset + 1;
  }
  else {
    tail = 8;
  }
  if ((start - offset) <= dest) {
    cut = dest - start + offset;
  }
  else {
    cut = 0;
  }
  if (offset < start - dest + 8 && offset >= 0)
  {
    pixels.fill(color, (start - offset)  + cut, tail - cut);
  }
}

void setup() {
  sevenSegSetup();
  Serial.begin(115200);
  pixels.begin(); // This initializes the NeoPixel library.
  psu.begin();
  pinMode(BeerPin,OUTPUT);
  digitalWrite(BeerPin,HIGH);
  
}

void loop() {
  ReadButton();

  if (buttonPressed == true) {
    buttonAnim();
    theaterChase(pixels.Color(0, 255, 0), 0, 181, 100, 3,0); // Clock line
    xtal();
    digitalWrite(BeerPin,HIGH);
  }
  else {
    IdleAnimation();
    UpdateDisplay(targetValue);
  }
  pixels.show();
  pixels.clear();

  int dir = (millis()/2000%2)*2-1;
   int col1 = (millis()/2000%2);
   int col2 = ((millis()/2000)+1)%2;
   
  // 230V AC
  theaterChasePSU(psu.Color(255*col1, 0, 255*col2), 0, 34, 50, 5*dir);         // Top
  theaterChasePSU(psu.Color(255*col2, 0, 255*col1), 423, 31, 50, 5*dir);       //Bottom

  // 12V AC
  theaterChasePSU(psu.Color(255*col1, 0, 255*col2), 34, 123, 150, 3*dir);    // Top
  theaterChasePSU(psu.Color(255*col2, 0, 255*col1), 369, 54, 150, 3*dir);   // Bottom
  
  // 12V DC
  theaterChasePSU(psu.Color(255, 0, 0), 262, 107, 150, -3);   // Top
  theaterChasePSU(psu.Color(0, 0, 255), 157, 105, 150, -3);  // Bottom
  psu.show(); // Update strip with new contents
  psu.clear();
}
/*void loop() {

  byteOffset = millis() / 20 % 202;
  //long clock signal
  theaterChase(pixels.Color(255, 0, 0), 0, 181, 100, 3);

  //5G
  theaterChase(pixels.Color(0, 255, 0), 333, 18, 75, 3);
  theaterChase(pixels.Color(0, 0, 255), 351, 12, 75, -3);

  //parabol
  theaterChase(pixels.Color(0, 200, 200), 363, 24, 125, -3);
  incommingSignal();

  //Osc
  xtal();

  //Data to 7seq
  dataPacket(pixels.Color(200, 0, 0), dataPacketStart, 254, byteOffset);
  dataPacket(pixels.Color(0, 200, 200), dataPacketStart, 236, byteOffset - 16);
  dataPacket(pixels.Color(200, 0, 200), dataPacketStart, 218, byteOffset - 32);
  dataPacket(pixels.Color(200, 200, 0), dataPacketStart, 200, byteOffset - 48);
  dataPacket(pixels.Color(0, 0, 200), dataPacketStart, 182, byteOffset - 64);

  // Bottom
  pixels.show(); // Update strip with new contents
  pixels.clear();
  //
  }*/
