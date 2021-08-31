void xtal() {
  int limit = millis() / delayVal % 2;
  pixels.fill(pixels.Color(255 * limit, 0, 0), 313, 20);
}
