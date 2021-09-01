
void GetRGBFromHue(byte hue, byte &Red, byte &Green, byte &Blue, int scale)
{ // Convert Hue (0-255) to 8 bit RGB values.
  if (hue < 85)
  { // decrease red and increase green
    Red = 255 - hue * 3;
    Green = hue * 3;
    Blue = 0;
  }
  else if (hue < 170)
  { // decrease green and indcrease blue
    Red = 0;
    Green = 510 - hue * 3;
    Blue = hue * 3 - 255;
  }
  else if (hue < 255)
  { // decrease blue and increase red
    Red = hue * 3 - 510;
    Green = 0;
    Blue = 765 - hue * 3;
  }
  else
  {
    Red = 0;
    Green = 0;
    Blue = 0;
  }
  Red = (int)Red*scale/255;
  Green = (int)Green*scale / 255;
  Blue = (int)Blue*scale/255;
}
