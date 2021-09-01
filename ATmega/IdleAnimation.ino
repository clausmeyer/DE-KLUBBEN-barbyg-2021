unsigned long lastPacket;
byte randomOffset, randomPacket;
int packetEnd[5] = {254, 236, 218, 200, 182};
bool newPacket = true;

unsigned long dataAnimationStartTime;
bool dataAnimationStart = true;
byte red, green, blue;
int sum, sumOld;

byte RGBParab[3];
void IdleAnimation()
{
  // Clock 0 to 181 (182)
  theaterChase(pixels.Color(255, 255, 0), 0, 181, 100, 3, 0); // Clock line

  // Data 182 to 312 (131)
  if (millis() / 15000 % 2)
  {
    theaterChase(pixels.Color(255,   0,   0), 182, 131, 75, -9, 0);
    theaterChase(pixels.Color(170,  85,   0), 182, 131, 75, -9, -1);
    theaterChase(pixels.Color( 85, 170,   0), 182, 131, 75, -9, -2);
    theaterChase(pixels.Color(  0, 255,   0), 182, 131, 75, -9, -3);
    theaterChase(pixels.Color(  0, 170,  85), 182, 131, 75, -9, -4);
    theaterChase(pixels.Color(  0,  85, 170), 182, 131, 75, -9, -5);
    theaterChase(pixels.Color(  0,   0, 255), 182, 131, 75, -9, -6);
    theaterChase(pixels.Color( 85,   0, 170), 182, 131, 75, -9, -7);
    theaterChase(pixels.Color(170,   0,  85), 182, 131, 75, -9, -8);
    dataAnimationStart = false;
  }
  else
  {
    if (newPacket == true)
    {
      lastPacket = millis();
      randomOffset = random(0, 50);
      randomPacket = random(0, 9) % 5;
      newPacket = false;

      sumOld = red + green + blue;
      sum = 0;
      while (sumOld == sum || sum == 0)
      {
        red = random(0, 29) % 2 * 127;
        green = random(0, 29) % 2 * 126;
        blue = random(0, 29) % 2 * 125;
        sum = red + green + blue;
      }
    }
    int byteOffset = (millis() - lastPacket) / 20 % 360;

    dataPacket(pixels.Color(red, green, blue), 312, packetEnd[randomPacket], byteOffset - randomOffset);

    if (byteOffset - randomOffset >= 312 - packetEnd[randomPacket] + 10)
    {
      newPacket = true;
    }
  }
  // XTal  313 to 332 (20)
  theaterChase(pixels.Color(255, 0, 0), 313, 20, 100, 3, 0);

  // 5G  333 to  362 (30)
  theaterChase(pixels.Color(0, 255, 0), 333, 18, 75, 3, 0); // TX
  theaterChase(pixels.Color(0, 0, 255), 351, 12, 75, -3, 0); // RX

  // parabol line 363 to 386 (24)
 // pixels.fill(pixels.Color(0, 255, 0), 363, 24);

  theaterChase(pixels.Color(  0, 255, 255), 363, 24, 75,  -6, 0); // TX
  theaterChase(pixels.Color(255,   0, 0), 363, 24, 75, 8, 0); // RX

  // parabola itself 387 to 437 (50)
  int parab = millis() / 50 % 100;

  int hue = millis() / 50 & 255;

  GetRGBFromHue(hue, RGBParab[0], RGBParab[1], RGBParab[2], 255);
  if (parab < 50)
  {
    pixels.fill(pixels.Color(RGBParab[0], RGBParab[1], RGBParab[2]), 387, parab + 1);
  }
  else
  {
    pixels.fill(pixels.Color(RGBParab[0], RGBParab[1], RGBParab[2]), 387 + parab - 50, 100 - parab);
  }
}
