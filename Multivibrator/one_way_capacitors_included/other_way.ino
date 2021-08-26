

void row_4_other_way() {
  for (int i = 0; i < sizeof(segment_3) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_3[(i + row_4_count)], pixels.Color(0, 0, 0));
  }
  row_4_count++;
  for (int i = 0; i < sizeof(segment_3) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_3[(i + row_4_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_4_count > 2) row_4_count = 0;
}

void row_2_other_way() {
  for (int i = 0; i < sizeof(segment_5) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_5[(i + row_2_count)], pixels.Color(0, 0, 0));
  }
  row_2_count++;
  for (int i = 0; i < sizeof(segment_5) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_5[(i + row_2_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_2_count > 2) row_2_count = 0;
}

void row_3_other_way() {
  for (int i = 0; i < sizeof(segment_2) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_2[(i + row_3_count)], pixels.Color(0, 0, 0));
  }
  row_3_count++;
  for (int i = 0; i < sizeof(segment_2) / 4 - 2; i = i + 3) {
    pixels.setPixelColor(segment_2[(i + row_3_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_3_count > 2) row_3_count = 0;
}

void row_1_other_way() {
  for (int i = 0; i < sizeof(segment_4) / 4 - 23; i = i + 3) {
    pixels.setPixelColor(segment_4[(i + row_1_count)], pixels.Color(0, 0, 0));
  }
  row_1_count++;
  for (int i = 0; i < sizeof(segment_4) / 4 - 25; i = i + 3) {
    pixels.setPixelColor(segment_4[(i + row_1_count)], pixels.Color(R_val, 0, 0));
  }

  for (int i = sizeof(segment_4) / 4 - 23; i < sizeof(segment_4) / 4 ; i = i + 3) {
    pixels.setPixelColor(segment_4[(i)], pixels.Color(R_val, 0, 0));
  }
  if (row_1_count > 2) row_1_count = 0;
}

void row_5_other_way() {
  for (int i = sizeof(segment_9) / 4 - 15; i > 0; i = i - 3)  {
    pixels.setPixelColor(segment_9[(i - row_5_count)], pixels.Color(0, 0, 0));
  }
  row_5_count++;
  for (int i = sizeof(segment_9) / 4 - 2; i > sizeof(segment_9) / 4 - 15; i = i - 3) {
    pixels.setPixelColor(segment_9[(i )], pixels.Color(R_val, 0, 0));
  }

  for (int i = sizeof(segment_9) / 4 - 15; i > 0; i = i - 3)  {
    pixels.setPixelColor(segment_9[(i - row_5_count )], pixels.Color(R_val, 0, 0));
  }
  if (row_5_count > 2) row_5_count = 0;
}
void row_6_other_way() {
  for (int i = sizeof(segment_7) / 4 ; i >  0; i = i - 3){
    pixels.setPixelColor(segment_7[(i - row_6_count)], pixels.Color(0, 0, 0));
  }
  row_6_count++;
  for (int i = sizeof(segment_7) / 4 ; i >  0; i = i - 3) {
    pixels.setPixelColor(segment_7[(i - row_6_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_6_count > 2) row_6_count = 0;
}
void row_7_other_way() {
  for (int i = sizeof(segment_8) / 4 ; i >  0; i = i - 3) {
    pixels.setPixelColor(segment_8[(i - row_7_count)], pixels.Color(0, 0, 0));
  }
  row_7_count++;
  for (int i = sizeof(segment_8) / 4 ; i >  0; i = i - 3){
    pixels.setPixelColor(segment_8[(i - row_7_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_7_count > 2) row_7_count = 0;
}
void row_8_other_way() {
  for (int i = sizeof(segment_6) / 4 ; i >  0; i = i - 3) {
    pixels.setPixelColor(segment_6[(i - row_8_count)], pixels.Color(0, 0, 0));
  }
  row_8_count++;
  for (int i = sizeof(segment_6) / 4 ; i >  0; i = i - 3) {
    pixels.setPixelColor(segment_6[(i - row_8_count)], pixels.Color(R_val, 0, 0));
  }
  if (row_8_count > 2) row_8_count = 0;
}

void row_1_arm_1_other_way() {
  for (int i = sizeof(segment_1_arm_1) / 4 ; i >  0; i = i - 3) {
    arm_1.setPixelColor(segment_1_arm_1[(i - row_1_arm_1_count)], arm_1.Color(0, 0, 0));
  }
  row_1_arm_1_count++;
  for (int i = sizeof(segment_1_arm_1) / 4 ; i >  0; i = i - 3) {
    arm_1.setPixelColor(segment_1_arm_1[(i - row_1_arm_1_count)], arm_1.Color(R_val, 0, 0));
  }
  if (row_1_arm_1_count > 2) row_1_arm_1_count = 0;
}

void row_2_arm_2_other_way() {
  for (int i = 0; i < sizeof(segment_2_arm_2) / 4 + 4; i = i + 1) {
    arm_2.setPixelColor(segment_2_arm_2[(i )], arm_2.Color(0, 0, 0));
  }
  row_2_arm_2_count++;
  /*for (int i = 0; i < sizeof(segment_2_arm_1) / 4 - 2; i = i + 3) {
    arm_1.setPixelColor(segment_2_arm_1[(i )], arm_1.Color(R_val, 0, 0));
    }*/
  if (row_2_arm_2_count > 2) row_2_arm_2_count = 0;
}

void row_1_arm_2_other_way() {
  for (int i = sizeof(segment_1_arm_2) / 4 ; i >  0; i = i - 3) {
    arm_2.setPixelColor(segment_1_arm_2[(i - row_1_arm_2_count)], arm_2.Color(0, 0, 0));
  }
  row_1_arm_2_count++;
  for (int i = sizeof(segment_1_arm_2) / 4 ; i >  0; i = i - 3) {
    arm_2.setPixelColor(segment_1_arm_2[(i - row_1_arm_2_count)], arm_2.Color(R_val, 0, 0));
  }
  if (row_1_arm_2_count > 2) row_1_arm_2_count = 0;
}

void row_2_arm_1_other_way() {
  for (int i = 0; i < sizeof(segment_2_arm_1) / 4 - 2; i = i + 3) {
    arm_1.setPixelColor(segment_2_arm_1[(i + row_2_arm_1_count)], arm_1.Color(0, 0, 0));
  }
  row_2_arm_1_count++;
  for (int i = 0; i < sizeof(segment_2_arm_1) / 4 - 2; i = i + 3) {
    arm_1.setPixelColor(segment_2_arm_1[(i + row_2_arm_1_count)], arm_1.Color(R_val, 0, 0));
  }
  if (row_2_arm_1_count > 2) row_2_arm_1_count = 0;
}
