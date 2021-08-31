#define TIMER_INTERRUPT_DEBUG 1

#include "ESP8266TimerInterrupt.h"
#include <SPI.h>

// SPI Settings
const int LATCH = 5; // D1
const int OE = 0;    // D2
const int ISR_Reset = 4;

#define SEGMENTS 24
#define Bytes SEGMENTS * 3 / 8
byte LED[3 * SEGMENTS]; // [RGB][segment]
byte SPI_OUTPUT[Bytes];
bool new_data = false;

// Global timing variables
volatile uint32_t lastMicros = 0;
volatile uint32_t animationFrameInterval = 50000;
volatile uint8_t idx_ISR = 0;

// Defining shortest period timing
// TIMER_BASE_MICROS is used to define how many microseconds the shortest bit takes up.
// Since we are running 8 bit we can find the period by:
//    PWM_period = TIMER_BASE_MICROS * 255 [microsecond]
// To find the update frequency:
//    PWM_f = 1 / PWM_period
//
// TABLE OF WORKING VALUES:
// PWM_Period [ms]    |  25.50 | 12.75 |   6.38 |   2.55|
// HZ                 |  39.21 | 78.43 | 156.9  | 392.2 |
// TIMER_BASE_MICROS  | 100    | 50    |  25    |  10   |

#define TIMER_BASE_MICROS        25
static uint32_t onTime[8] = {TIMER_BASE_MICROS * 1, TIMER_BASE_MICROS * 2, TIMER_BASE_MICROS * 4, TIMER_BASE_MICROS * 8,
                             TIMER_BASE_MICROS * 16, TIMER_BASE_MICROS * 32, TIMER_BASE_MICROS * 64, TIMER_BASE_MICROS * 128
                            };
// Init ESP8266 timer 0
ESP8266Timer ITimer;

unsigned long T1, T2;
void ICACHE_RAM_ATTR TimerHandler(void)
{
  // Calc SPI output for all channels
  for (int idx_color = 0; idx_color < SEGMENTS * 3; idx_color++) {
    bitWrite(SPI_OUTPUT[Bytes - 1 - (idx_color >> 3)], idx_color % 8, bitRead(LED[idx_color], idx_ISR));
  }
  SPI.transfer(&SPI_OUTPUT, Bytes);
  digitalWrite(LATCH, LOW);
  digitalWrite(LATCH, HIGH);
  digitalWrite(OE, LOW);
  new_data = true;

  // Attach timer for next cycle
  if (ITimer.attachInterruptInterval(onTime[idx_ISR], TimerHandler)) {

#if (TIMER_INTERRUPT_DEBUG)
    //Serial.println("Bit: " + String(idx_ISR) + " Delta us = " + String(micros() - lastMicros));
    lastMicros = micros();
#endif
    idx_ISR++;
    if (idx_ISR >= 8) {
      idx_ISR = 0;
    }
  }
  else {
#if (TIMER_INTERRUPT_DEBUG)
    Serial.println("Can't set ITimer correctly. Select another freq. or interval");
#endif
  }
}

void SetLED(int segmentID, byte Red, byte Green, byte Blue)// Set RGB values to specific LED.
{
  LED[segmentID * 3] = Red;
  LED[(segmentID * 3) + 1] = Green;
  LED[(segmentID * 3) + 2] = Blue;
}

void setup()
{
  pinMode(ISR_Reset, OUTPUT);
  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(20000000, LSBFIRST, SPI_MODE0));
  pinMode(LATCH, OUTPUT);
  pinMode(OE, OUTPUT);
  digitalWrite(OE, HIGH);

  // Serial setup
#if (TIMER_INTERRUPT_DEBUG)
  Serial.begin(1000000);
  Serial.println("\nStarting");
#endif

  // Attach first interrupt
  if (ITimer.attachInterruptInterval(TIMER_BASE_MICROS, TimerHandler)) {
#if (TIMER_INTERRUPT_DEBUG)
    Serial.println("Starting  ITimer OK, millis() = " + String(millis()));
  }
  else {
    Serial.println("Can't set ITimer correctly. Select another freq. or interval");
#endif
  }
}

volatile uint32_t last_frame = 0;
volatile uint8_t J_state = 0;
byte animationRunning = 0;
long col = 0;
byte buttonVal = 0;
byte buttonValOld = 0;
//byte buttonPin =
byte red, green, blue;
void loop()
{
  if (new_data) {
    new_data = false;
  }

  animationRunning = ((millis() / 5000) % 3); // step between the 3 animations with a interval of 5s

  if (micros() - last_frame > animationFrameInterval) {
    last_frame = micros();

    if (animationRunning == 0)
    {
      animationFrameInterval = 50000;
      for (int i = 0; i < SEGMENTS; i++)
      {
        if (col == i)
        {
          SetLED(i, 170, 170, 70);
        }
        else if (col  > i)
        {
          SetLED(i, 170, 70, 0);
        }
        else
        {
          SetLED(i, 0, 0, 0);
        }
      }
      col++;
      if (col >= SEGMENTS)
      {
        col = 0;
      }
    }
    else if (animationRunning == 1)
    {
      // rainbow color scroll on all segments at once
      animationFrameInterval = 5000;

      for (int seg = 0; seg < SEGMENTS; seg++)
      {
        GetRGBFromHue((col + seg * 10) % 255, red, green, blue,50);
        SetLED(seg, red, green, blue);
      }
      col++;
      if (col >= 255)
      {
        col = 0;
      }
    }
    else if (animationRunning == 2)
    {
      animationFrameInterval = 5000;
      ClearLED();
      byte hue = millis() / 60 % 255;
      GetRGBFromHue(hue % 255, red, green, blue,200);
      theaterChase(red, green, blue, 0, 12, 100, 3);
      theaterChase(red, green, blue, 12, 23, 100, -3);
    }
  }
}
