int  D1[6] = {27, 28, 29, 30, 31, 32};
int  D2[2] = {0, 26};
int  D3[2] = {1, 25};
int  D4[2] = {2, 24};
int  D5[2] = {3, 23};
int  D6[2] = {4, 22};
int  D7[2] = {5, 21};
int  D8[2] = {6, 20};
int  D9[2] = {7, 19};
int  D10[2] = {8, 18};
int  D11[2] = {9, 17};
int  D12[2] = {10, 16};
int  D13[2] = {11, 15};
int  D14[3] = {12, 13, 14};


int  E1[8] = {41, 42, 43, 44, 45, 46, 47, 48};
int  E2[2] = {40, 49};
int  E3[3] = {39, 56, 50};
int  E4[3] = {38, 57, 51};
int  E5[3] = {37, 58, 52};
int  E6[3] = {36, 59, 53};
int  E7[3] = {35, 60, 54};
int  E8[3] = {34, 61, 55};
int  E9[2] = {33, 62};


int  dot[1] = {63};


int  K1[9] = {64, 65, 66, 67, 68, 69, 70, 71, 72};
int  K2[2] = {80, 79};
int  K3[2] = {81, 78};
int  K4[2] = {82, 77};
int  K5[2] = {83, 76};
int  K6[2] = {84, 75};
int  K7[2] = {85, 74};
int  K8[2] = {86, 73};


int  L1[8] = {87, 88, 89, 90, 91, 92, 93, 94};
int  L2[1] = {95};
int  L3[1] = {96};
int  L4[1] = {97};
int  L5[1] = {98};
int  L6[1] = {99};
int  L7[1] = {100};
int  L8[1] = {101};


int  U_1[7] = {102, 103, 104, 105, 106, 107, 108};
int  U_2[1] = {109};
int  U_3[1] = {110};
int  U_4[1] = {111};
int  U_5[1] = {112};
int  U_6[1] = {113};
int  U_7[1] = {114};
int  U_8[1] = {115};
int  U_9[1] = {116};
int  U_10[1] = {117};
int  U_11[1] = {118};
int  U_12[7] = {119, 120, 121, 122, 123, 124, 125};


int  B_1[8] = {126, 127, 128, 129, 130, 131, 132, 133};
int  B_2[2] = {155, 134};
int  B_3[3] = {154, 156, 135};
int  B_4[3] = {153, 157, 136};
int  B_5[3] = {152, 158, 137};
int  B_6[3] = {151, 159, 138};
int  B_7[3] = {150, 160, 139};
int  B_8[2] = {149, 140};
int  B_9[2] = {148, 141};
int  B_10[2] = {145, 144};
int  B_11[2] = {146, 143};
int  B_12[2] = {147, 142};


int  BB1[8] = {161, 162, 163, 164, 165, 166, 167, 168};
int  BB2[2] = {190, 169};
int  BB3[3] = {189, 191, 170};
int  BB4[3] = {188, 192, 171};
int  BB5[3] = {187, 193, 172};
int  BB6[3] = {186, 194, 173};
int  BB7[3] = {185, 195, 174};
int  BB8[2] = {184, 175};
int  BB9[2] = {183, 176};
int  BB10[2] = {180, 179};
int  BB11[2] = {181, 178};
int  BB12[2] = {182, 177};


int  EE1[8] = {203, 204, 205, 206, 207, 208, 209, 210};
int  EE2[2] = {202, 211};
int  EE3[3] = {201, 218, 212};
int  EE4[3] = {200, 219, 213};
int  EE5[3] = {199, 220, 214};
int  EE6[3] = {198, 221, 215};
int  EE7[3] = {197, 222, 216};
int  EE8[3] = {196, 223, 217};
int  EE9[1] = {224};


int  N_1[8] = {232, 231, 230, 229, 228, 227, 226, 225};
int  N_2[1] = {233};
int  N_3[1] = {234};
int  N_4[1] = {235};
int  N_5[1] = {236};
int  N_6[1] = {237};
int  N_7[1] = {238};
int  N_8[1] = {239};
int  N_9[1] = {240};
int  N_10[1] = {241};
int  N_11[1] = {242};
int  N_12[1] = {243};
int  N_13[1] = {244};
int  N_14[8] = {252, 251, 250, 249, 248, 247, 246, 245};

int  dummy[1] = {25};

int  column_lengths_D[14] = {6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
int  *column_pointers_D[14] = {D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14};

int  column_lengths_E[9] = {8, 2, 3, 3, 3, 3, 3, 3, 2};
int  *column_pointers_E[9] = {E1, E2, E3, E4, E5, E6, E7, E8, E9};

int  column_lengths_dot[1] = {1};
int  *column_pointers_dot[1] = {dot};

int  column_lengths_K[8] = {9, 2, 2, 2, 2, 2, 2, 2};
int  *column_pointers_K[8] = {K1, K2, K3, K4, K5, K6, K7, K8};

int  column_lengths_L[8] = {8, 1, 1, 1, 1, 1, 1, 1};
int  *column_pointers_L[8] = {L1, L2, L3, L4, L5, L6, L7, L8};

int  column_lengths_U[12] = {7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7};
int  *column_pointers_U[12] = {U_1, U_2, U_3, U_4, U_5, U_6, U_7, U_8, U_9, U_10, U_11, U_12};

int  column_lengths_B[12] = {8, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
int  *column_pointers_B[12] = {B_1, B_2, B_3, B_4, B_5, B_6, B_7, B_8, B_9, B_10, B_11, B_12};

int  column_lengths_BB[12] = {8, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
int  *column_pointers_BB[12] = {BB1, BB2, BB3, BB4, BB5, BB6, BB7, BB8, BB9, BB10, BB11, BB12};

int  column_lengths_EE[9] = {8, 2, 3, 3, 3, 3, 3, 3, 1};
int  *column_pointers_EE[9] = {EE1, EE2, EE3, EE4, EE5, EE6, EE7, EE8, EE9};

int  column_lengths_N[14] = {8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8};
int  *column_pointers_N[14] = {N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9, N_10, N_11, N_12, N_13, N_14};

int column_length_all[99] = {6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 8, 2, 3, 3, 3, 3, 3, 3, 2, 1, 9, 2, 2, 2, 2, 2, 2, 2, 8, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 8, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 8, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 8, 2, 3, 3, 3, 3, 3, 3, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8};
int  *column_pointers_all[99] = {D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, E1, E2, E3, E4, E5, E6, E7, E8, E9, dot, K1, K2, K3, K4, K5, K6, K7, K8, L1, L2, L3, L4, L5, L6, L7, L8, U_1, U_2, U_3, U_4, U_5, U_6, U_7, U_8, U_9, U_10, U_11, U_12, B_1, B_2, B_3, B_4, B_5, B_6, B_7, B_8, B_9, B_10, B_11, B_12, BB1, BB2, BB3, BB4, BB5, BB6, BB7, BB8, BB9, BB10, BB11, BB12, EE1, EE2, EE3, EE4, EE5, EE6, EE7, EE8, EE9, N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9, N_10, N_11, N_12, N_13, N_14};

int  led_pointers[10] = {column_pointers_D, column_pointers_E, column_pointers_dot, column_pointers_K, column_pointers_L, column_pointers_U, column_pointers_B, column_pointers_BB, column_pointers_EE, column_pointers_N};
