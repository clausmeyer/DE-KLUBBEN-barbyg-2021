void theaterChasePSU(uint32_t color, int start, int numLed, int velocity, int stepSize) {
  byte offset = millis() / velocity % abs(stepSize);
  if (stepSize > 0) {
    for (int c = offset + start; c < numLed + start; c += stepSize) {
      psu.setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
  else {
    for (int c = start - offset - stepSize - 1; c < numLed + start; c -= stepSize) {
      psu.setPixelColor(c, color); // Set pixel 'c' to value 'color'
    }
  }
}
