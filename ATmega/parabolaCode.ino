 
int rings[5] = {19, 14, 10, 6, 1};
int ringStart[5] = {386, 406, 420, 430, 436};

byte turned_on[NUMPIXELS];

void setRingLight(int ringNum, bool On) {
  byte rgb[5][3] = {{0 , 0, 50},
    {0 , 100, 0},
    {150 , 0, 0},
    {200 , 0, 0},
    {255, 0, 0}
  };

  if (ringNum >= 0 && ringNum < 5) {
    pixels.fill(pixels.Color(rgb[ringNum][0]*On, rgb[ringNum][1]*On, rgb[ringNum][2]*On), ringStart[ringNum], rings[ringNum]);
  }
}

void incommingSignal() {
  int limit = (millis()-buttonPressTime) / delayVal % 8;

  setRingLight(limit, true);
  setRingLight(limit + 2, true);
  setRingLight(limit - 2, true);
}
