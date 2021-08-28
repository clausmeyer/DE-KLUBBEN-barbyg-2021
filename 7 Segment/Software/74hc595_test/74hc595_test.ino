// inslude the SPI library:
#include <SPI.h>

unsigned int bitval;
int wait = 750;
byte NumbConv[11] = {252, 12, 182, 158, 78, 218, 250, 140, 254, 206, 0}; // 0 through 9 with 10 being off.

const int LATCH = 17;      // 9
const int OE = 16;        //10
const int buttonPin = 13   ;  // 2

const int BeerAmount = 25;
int currentValue = 0;
int targetValue = 1;
byte Numbers[5] = {0, 0, 0, 0, 0};
int buttonVal;
int buttonValOld;

int  incrementMax = 500;
int incrementMin  = 100;
int increment = 200;
int valueDiffMax = BeerAmount;

unsigned long lastIncrementTime = 0;

void setup() {
  // set the slaveSelectPin as an output:
  pinMode(LATCH, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(OE, HIGH);


  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  Serial.begin(115200);
  // BootSequence();
  // Test();
}


void loop()
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
  Serial.print(currentValue);
  Serial.print("\t");
  Serial.print(targetValue);
  Serial.print("\t");
  Serial.print(valueDiffMax);
  Serial.print("\t");
  Serial.println(increment);
  UpdateDisplay(currentValue);
}

void ReadButton()
{
  buttonValOld = buttonVal;
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == 0 & buttonVal != buttonValOld)
  {
    targetValue += BeerAmount;
    valueDiffMax = targetValue - currentValue;
    lastIncrementTime = 0;
  }
}

void UpdateDisplay(int value)
{
  // Seperate value into numbers
  for (int i = 0; i < 5; i++)
  {
    Numbers[i] = value % 10;
    value = value / 10;
  }
  /*  // debug stuff
    Serial.print(currentValue);
    Serial.print("\t");
    for (int i = 0; i < 5; i++)
    {
      Serial.print(Numbers[4 - i]);
      Serial.print("\t");

    }
    Serial.println();
  */
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
    Serial.print(i);
    Serial.print("\t");
    Serial.println(bitval);
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
