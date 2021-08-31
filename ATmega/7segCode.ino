// inslude the SPI library:
#include <SPI.h>

unsigned int bitval;
int wait = 750;
byte NumbConv[11] = {252, 12, 182, 158, 78, 218, 250, 140, 254, 206, 0}; // 0 through 9 with 10 being off.

const int LATCH = 17;      // 9 (Do not pil)
const int OE = 16;        //10  (Do not pil)
const int buttonPin = 13   ;  // 2

const int BeerAmount = 25;
int currentValue = 0;

byte Numbers[5] = {0, 0, 0, 0, 0};
int buttonVal;
int buttonValOld;

//new vals

//new vals

int  incrementMax = 500;
int incrementMin  = 100;
int increment = 200;
int valueDiffMax = BeerAmount;

unsigned long lastIncrementTime = 0;

void sevenSegSetup() {
  // set the slaveSelectPin as an output:
  pinMode(LATCH, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);
  digitalWrite(OE, HIGH);


  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  //Serial.begin(115200);
  // BootSequence();
  // Test();
}


/*void loop()
  {
  ReadButton();
  //increment = incrementMax - ((incrementMax - incrementMin)  valueDiffMax * (targetValue - currentValue));

  increment = incrementMax - (incrementMax - incrementMin) / valueDiffMax * (targetValue - currentValue);
  if (millis() - lastIncrementTime > increment)
  {
    lastIncrementTime = millis();
    if (currentValue < targetValue)
    {
      currentValue++;
    }
    // reset DiffMax when done counting.
    else if (currentValue == targetValue)
    {
      valueDiffMax = BeerAmount;
    }
  }

  UpdateDisplay(currentValue);
  }*/

void ReadButton()
{
  buttonValOld = buttonVal;
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == 0 & buttonVal != buttonValOld)
  {
    targetValue += BeerAmount; // updates the number the counter should reach
    valueDiffMax = targetValue - currentValue;
    lastIncrementTime = 0;
    buttonPressTime = millis();
    buttonPressed = true;
    Serial.println("pressed");
  }
}

void UpdateDisplay(int target)
{
  increment = incrementMax - (incrementMax - incrementMin) / valueDiffMax * (targetValue - currentValue);
  if (millis() - lastIncrementTime > increment)
  {
    lastIncrementTime = millis();
    if (currentValue < target)
    {
      currentValue++;
    }
    // reset DiffMax when done counting.
    else if (currentValue == target)
    {
      valueDiffMax = BeerAmount;
    }
  }
  // Seperate value into numbers
  int value = currentValue;
  for (int i = 0; i < 5; i++)
  {
    Numbers[i] = value % 10;
    value = value / 10;
  }

  // send data
  for (int i = 0; i < 5; i++)
  {
    SPI.transfer(NumbConv[Numbers[i]]);
  }
  digitalWrite(LATCH, LOW);
  digitalWrite(LATCH, HIGH);
  digitalWrite(OE, LOW);
}

void Test()
{
  for (int i = 0; i < 11; i++)
  {
    bitval = NumbConv[i];
    SPI.transfer(NumbConv[i]);
    SPI.transfer(NumbConv[i]);
    SPI.transfer(NumbConv[i]);
    SPI.transfer(NumbConv[i]);
    SPI.transfer(NumbConv[i]);
    digitalWrite(LATCH, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(OE, LOW);
    delay(wait);
  }
}
void BootSequence()
{
  // boot sequence
  bitval = 128;
  for (int i = 0; i < 7 ; i++)
  {
    SPI.transfer(bitval);
    SPI.transfer(bitval);
    SPI.transfer(bitval);
    SPI.transfer(bitval);
    SPI.transfer(bitval);
    digitalWrite(LATCH, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(OE, LOW);
    delay(250);
    bitval = bitval >> 1;
  }

  for (int i = 0; i <= 8; i++)
  {
    SPI.transfer(i % 2 * 254);
    SPI.transfer(i % 2 * 254);
    SPI.transfer(i % 2 * 254);
    SPI.transfer(i % 2 * 254);
    SPI.transfer(i % 2 * 254);
    digitalWrite(LATCH, LOW);
    digitalWrite(LATCH, HIGH);
    delay(250);
  }
  delay(500);
}
