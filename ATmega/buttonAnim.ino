byte animStage = 0;

void buttonAnim() {
  int dataPacketStart = 312;
  int byteOffset = (millis() - buttonPressTime - 2000) / 20 % 240;
  unsigned long animTime = millis() - buttonPressTime;
  //int dataPacketStart = 312;


  if (animTime <= 2100) {
    theaterChase(pixels.Color(0, 200, 200), 363, 24, 125, -3);
    theaterChase(pixels.Color(0, 255, 0), 333, 18, 75, 3);
    theaterChase(pixels.Color(0, 0, 255), 351, 12, 75, -3);
    incommingSignal();

    animStage = 1;
  }
  if (animTime >= 2000 && animTime <= 4760) {
    dataPacket(pixels.Color(200, 0, 0), dataPacketStart, 182, byteOffset);
    dataPacket(pixels.Color(0, 200, 200), dataPacketStart, 200, byteOffset - 16);
    dataPacket(pixels.Color(200, 0, 200), dataPacketStart, 218, byteOffset - 32);
    dataPacket(pixels.Color(200, 200, 0), dataPacketStart, 236, byteOffset - 48);
    dataPacket(pixels.Color(0, 0, 200), dataPacketStart, 254, byteOffset - 64);

    animStage = 2;
  }
  if (animTime >= 4760 && animTime <= 24000) {
    buttonPressed = false;
    
    theaterChase(pixels.Color(0, 200, 200), 0, 437, 100, 3);
  }

  if (animTime >= 10500) {
    animStage = 0;
    buttonPressed = false;
  }
}
