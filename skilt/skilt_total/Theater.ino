void theaterChase(uint32_t color, int start, int numLed, int velocity, int stepSize) {
  int offset = millis() / velocity % abs(stepSize);
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

int hue;
uint32_t colorRain;
int firstPixelHue;

void theaterChaseRain(int start, int numLed, int velocity, int stepSize) {
  int offset = millis() / velocity % abs(stepSize);
  int hueShift = millis() / 10 % 65536;
  firstPixelHue = hueShift * 256;
  
  if (stepSize > 0) {
    for (int c = offset + start; c < numLed + start; c += stepSize) {
      hue   = firstPixelHue + c * 65536L / pixels.numPixels();
      colorRain = pixels.gamma32(pixels.ColorHSV(hue));
      pixels.setPixelColor(c, colorRain); // Set pixel 'c' to value 'color'
    }
  }
  else {
    for (int c = start - offset - stepSize - 1; c < numLed + start; c -= stepSize) {
      hue   = firstPixelHue + c * 65536L / pixels.numPixels();
      colorRain = pixels.gamma32(pixels.ColorHSV(hue));
      pixels.setPixelColor(c, colorRain); // Set pixel 'c' to value 'color'
    }
  }
}
