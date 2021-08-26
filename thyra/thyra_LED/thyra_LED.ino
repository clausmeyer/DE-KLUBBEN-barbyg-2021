// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)
#include <uStepperS.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
int LED_PIN_BODY = 2;
int LED_PIN_EYE =  3;

// How many NeoPixels are attached to the Arduino?
int LED_COUNT_BODY = 130;
int LED_COUNT_EYE = 8;

uStepperS stepper;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel krop(LED_COUNT_BODY, LED_PIN_BODY, NEO_GRB + NEO_KHZ800), eye(LED_COUNT_EYE, LED_PIN_EYE, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel eye(LED_COUNT_EYE, LED_PIN_EYE, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

unsigned long current_time = 0;
unsigned long last_time = 0;
unsigned long current_time_LED = 0;
unsigned long last_time_LED = 0;
bool tail_flag = false;

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
Serial.println("1");
  krop.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  eye.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  //krop.show();            // Turn OFF all pixels ASAP
  //eye.show();            // Turn OFF all pixels ASAP
  
  
  //stepper.setup();
  stepper.checkOrientation(30.0);       //Check orientation of motor connector with +/- 30 microsteps movement
  Serial.begin(9600);
  stepper.setHoldCurrent(100);
  stepper.setRPM(1);
  stepper.setMaxVelocity  ( 200 );
  Serial.println("2");
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() { Serial.println("3");
  // Fill along the length of the strip in various colors...
//  colorWipe(strip.Color(255,   0,   0), 50); // Red
//  colorWipe(strip.Color(  0, 255,   0), 50); // Green
//  colorWipe(strip.Color(  0,   0, 255), 50); // Blue
//
//  // Do a theater marquee effect in various colors...
//  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
//  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
//  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness

  //rainbow(&eye,10);             // Flowing rainbow cycle along the whole strip

  for(int i=0; i<eye.numPixels(); i++) { // For each pixel in strip...
      eye.setPixelColor(i, eye.Color(127,0,0));
    }
    eye.show(); // Update strip with new contents


  rainbow(&krop,10);
  

  //theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
}


// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
//void colorWipe(uint32_t color, int wait) {
//  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
//    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
//    strip.show();                          //  Update strip to match
//    delay(wait);                           //  Pause for a moment
//  }
//}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
//void theaterChase(Adafruit_NeoPixel *strip, uint32_t color, int wait) {
//  for(int a=0; a<10; a++) {  // Repeat 10 times...
//    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
//      strip.clear();         //   Set all pixels in RAM to 0 (off)
//      // 'c' counts up from 'b' to end of strip in steps of 3...
//      for(int c=b; c<strip.numPixels(); c += 3) {
//        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
//      }
//      strip.show(); // Update strip with new contents
//      delay(wait);  // Pause for a moment
//    }
//  }
//}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(Adafruit_NeoPixel *strip, int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip->numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip->numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip->setPixelColor(i, strip->gamma32(strip->ColorHSV(pixelHue)));
    }
    strip->show(); // Update strip with new contents
    while(current_time_LED < last_time_LED + wait){
      motor();
      current_time_LED = millis();
    }
    last_time_LED = current_time_LED;  }
}

void motor(){
  current_time = millis();
  if(current_time > last_time+2000){
    if(tail_flag == true){ stepper.moveSteps(51200 * 4);}
    else {stepper.moveSteps(-51200 * 4);}
  tail_flag = !tail_flag;
  last_time = current_time;
  }
}
