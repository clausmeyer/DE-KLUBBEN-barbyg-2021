byte  D1[6] = {27, 28, 29, 30, 31, 32};
byte  D2[2] = {0, 26};
byte  D3[2] = {1, 25};
byte  D4[2] = {2, 24};
byte  D5[2] = {3, 23};
byte  D6[2] = {4, 22};
byte  D7[2] = {5, 21};
byte  D8[2] = {6, 20};
byte  D9[2] = {7, 19};
byte  D10[2] = {8, 18};
byte  D11[2] = {9, 17};
byte  D12[2] = {10, 16};
byte  D13[2] = {11, 15};
byte  D14[3] = {12, 13, 14};


byte  E1[8] = {41, 42, 43, 44, 45, 46, 47, 48};
byte  E2[2] = {40, 49};
byte  E3[3] = {39, 56, 50};
byte  E4[3] = {38, 57, 51};
byte  E5[3] = {37, 58, 52};
byte  E6[3] = {36, 59, 53};
byte  E7[3] = {35, 60, 54};
byte  E8[3] = {34, 61, 55};
byte  E9[2] = {33, 62};


byte  dot[1] = {63};
 

byte  K1[9] = {64, 65, 66, 67, 68, 69, 70, 71, 72};
byte  K2[2] = {80, 79};
byte  K3[2] = {81, 78};
byte  K4[2] = {82, 77};
byte  K5[2] = {83, 76};
byte  K6[2] = {84, 75};
byte  K7[2] = {85, 74};
byte  K8[2] = {86, 73};


byte  L1[8] = {87, 88, 89, 90, 91, 92, 93, 94};
byte  L2[1] = {95};
byte  L3[1] = {96};
byte  L4[1] = {97};
byte  L5[1] = {98};
byte  L6[1] = {99};
byte  L7[1] = {100};
byte  L8[1] = {101};
 

byte  U_1[7] = {102, 103, 104, 105, 106, 107, 108};
byte  U_2[1] = {109};
byte  U_3[1] = {110};
byte  U_4[1] = {111};
byte  U_5[1] = {112};
byte  U_6[1] = {113};
byte  U_7[1] = {114};
byte  U_8[1] = {115};
byte  U_9[1] = {116};
byte  U_10[1] = {117};
byte  U_11[1] = {118};
byte  U_12[7] = {119, 120, 121, 122, 123, 124, 125};
 

byte  B_1[8] = {126, 127, 128, 129, 130, 131, 132, 133};
byte  B_2[2] = {155, 134};
byte  B_3[3] = {154, 156, 135};
byte  B_4[3] = {153, 157, 136};
byte  B_5[3] = {152, 158, 137};
byte  B_6[3] = {151, 159, 138};
byte  B_7[3] = {150, 160, 139};
byte  B_8[2] = {149, 140};
byte  B_9[2] = {148, 141};
byte  B_10[2] = {145, 144};
byte  B_11[2] = {146, 143};
byte  B_12[2] = {147, 142};
 

byte  BB1[8] = {161, 162, 163, 164, 165, 166, 167, 168};
byte  BB2[2] = {190, 169};
byte  BB3[3] = {189, 191, 170};
byte  BB4[3] = {188, 192, 171};
byte  BB5[3] = {187, 193, 172};
byte  BB6[3] = {186, 194, 173};
byte  BB7[3] = {185, 195, 174};
byte  BB8[2] = {184, 175};
byte  BB9[2] = {183, 176};
byte  BB10[2] = {180, 179};
byte  BB11[2] = {181, 178};
byte  BB12[2] = {182, 177};
 

byte  EE1[8] = {203, 204, 205, 206, 207, 208, 209, 210};
byte  EE2[2] = {202, 211};
byte  EE3[3] = {201, 218, 212};
byte  EE4[3] = {200, 219, 213};
byte  EE5[3] = {199, 220, 214};
byte  EE6[3] = {198, 221, 215};
byte  EE7[3] = {197, 222, 216};
byte  EE8[3] = {196, 223, 217};
byte  EE9[1] = {224};
 

byte  N_1[8] = {232, 231, 230, 229, 228, 227, 226, 225};
byte  N_2[1] = {233};
byte  N_3[1] = {234};
byte  N_4[1] = {235};
byte  N_5[1] = {236};
byte  N_6[1] = {237};
byte  N_7[1] = {238};
byte  N_8[1] = {239};
byte  N_9[1] = {240};
byte  N_10[1] = {241};
byte  N_11[1] = {242};
byte  N_12[1] = {243};
byte  N_13[1] = {244};
byte  N_14[8] = {252, 251, 250, 249, 248, 247, 246, 245};

byte  dummy[1] = {25};

byte  column_lengths_D[14] = {6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
byte  *column_pointers_D[14] = {D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14};

byte  column_lengths_E[9] = {8, 2, 3, 3, 3, 3, 3, 3, 2};
byte  *column_pointers_E[9] = {E1, E2, E3, E4, E5, E6, E7, E8, E9};

byte  column_lengths_dot[1] = {1};
byte  *column_pointers_dot[1] = {dot};

byte  column_lengths_K[8] = {9, 2, 2, 2, 2, 2, 2, 2};
byte  *column_pointers_K[8] = {K1, K2, K3, K4, K5, K6, K7, K8};

byte  column_lengths_L[8] = {8, 1, 1, 1, 1, 1, 1, 1};
byte  *column_pointers_L[8] = {L1, L2, L3, L4, L5, L6, L7, L8};

byte  column_lengths_U[12] = {7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7};
byte  *column_pointers_U[12] = {U_1, U_2, U_3, U_4, U_5, U_6, U_7, U_8, U_9, U_10, U_11, U_12};

byte  column_lengths_B[12] = {8, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
byte  *column_pointers_B[12] = {B_1, B_2, B_3, B_4, B_5, B_6, B_7, B_8, B_9, B_10, B_11, B_12};

byte  column_lengths_BB[12] = {8, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
byte  *column_pointers_BB[12] = {BB1, BB2, BB3, BB4, BB5, BB6, BB7, BB8, BB9, BB10, BB11, BB12};

byte  column_lengths_EE[9] = {8, 2, 3, 3, 3, 3, 3, 3, 1};
byte  *column_pointers_EE[9] = {EE1, EE2, EE3, EE4, EE5, EE6, EE7, EE8, EE9};

byte  column_lengths_N[14] = {8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8};
byte  *column_pointers_N[14] = {N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9, N_10, N_11, N_12, N_13, N_14};

byte  led_pointers[10] = {column_pointers_D, column_pointers_E, column_pointers_dot, column_pointers_K, column_pointers_L, column_pointers_U, column_pointers_B, column_pointers_BB, column_pointers_EE, column_pointers_N};
