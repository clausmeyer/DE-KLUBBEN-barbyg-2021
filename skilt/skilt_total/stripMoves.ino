void threeColors(uint32_t color, int movSpeed, int colLength, int offset) {
  long start = (millis() - interruptTime) / movSpeed % (pixels.numPixels() * 100);

  for (long r = start; r < colLength + start; r++) {
    if (r - offset - colLength >= 0) {
      pixels.setPixelColor((r - offset - colLength) % pixels.numPixels(), color);
    }
  }
}
bool centFlag = false;
int centerVal;
int redFill;
int greenFill;
int blueFill;

void fillFromCenter(int movSpeed) {
  long count = ((millis() - interruptTime) / movSpeed ) % pixels.numPixels();
  long start = 0;

  if (count < 127) {
    start = count;
  }
  else {
    start = 127 - (count - 127);
  }

  if (count <= 10 && centFlag == false) {
    centerVal = random(50, pixels.numPixels() - 50);
    redFill = 0;
    greenFill = 0;
    blueFill = 0;
    while (redFill == 0 && greenFill == 0 && blueFill == 0) {
      redFill = random(0, 2) * 127;
      greenFill = random(0, 2) * 127;
      blueFill = random(0, 2) * 127;
      }
    centFlag = true;
  }

  if (count >= 240 && centFlag == true) {
    centFlag = false;
  }


  for (int i = centerVal; i < centerVal + start; i++) {
    pixels.setPixelColor((i) % pixels.numPixels(), redFill, greenFill, blueFill);
  }
  for (int i = centerVal; i > centerVal - start; i--) {
    pixels.setPixelColor((i) % pixels.numPixels(), redFill, greenFill, blueFill);
  }

}
