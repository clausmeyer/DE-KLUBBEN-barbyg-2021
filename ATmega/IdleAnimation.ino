void IdleAnimation()
{

  // Clock 0 to 181 (182)
  theaterChase(pixels.Color(255, 255, 0), 0, 181, 100, 3); // Clock line

  // Data 182 to 312 (72)
  theaterChase(pixels.Color(0, 255, 255), 182, 130, 50, -3); // Clock line

  // XTal  313 to 332 (20)
  theaterChase(pixels.Color(255, 0, 0), 313, 20, 100, 3);
  // 5G  333 to  362 (30)
  theaterChase(pixels.Color(0, 255, 0), 333, 18, 75, 3);  // TX
  theaterChase(pixels.Color(0, 0, 255), 351, 12, 75, -3); // RX

  // parabol line 363 to 386 (24)

  pixels.fill(pixels.Color(0, 255, 0), 363, 24);

}
