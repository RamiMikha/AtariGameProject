#include "bitmaps.h"

const UINT32 flappy_bitmap[BIRD_HEIGHT] = {
  0x00000000, 
  0x00000000, 
  0x00000000, 
  0x000fff00, 
  0x000fff00, 
  0x00f060c0, 
  0x00f060c0, 
  0x03018030, 
  0x03018030, 
  0x7fc180cc, 
  0x7fc180cc, 
  0x806180cc, 
  0x806180cc, 
  0x8018600c, 
  0x8018600c, 
  0x80181ffe, 
  0x80181ffe, 
  0x60606001, 
  0x60606001, 
  0x1f819ffe, 
  0x1f819ffe, 
  0x18006006, 
  0x18006006, 
  0x07801ff8, 
  0x07801ff8, 
  0x007fe000, 
  0x007fe000, 
  0x00000000, 
  0x00000000, 
  0x00000000,
  0x00000000, 
  0x00000000,
};

const UINT32 flappy_middle_bitmap[BIRD_HEIGHT] = {
  0x00000000, 
  0x00000000, 
  0x00000000, 
  0x000fff00, 
  0x000fff00, 
  0x00f060c0, 
  0x00f060c0, 
  0x03018030, 
  0x03018030, 
  0x0c0180cc, 
  0x0c0180cc,
  0x300180cc,
  0x300180cc,
  0x7fe0600c,
  0x7fe0600c,
  0x80181ffe,
  0x80181ffe,
  0x80186001,
  0x80186001,
  0x7fe19ffe,
  0x7fe19ffe,
  0x18006006,
  0x18006006,
  0x07801ff8,
  0x07801ff8,
  0x007fe000, 
  0x007fe000, 
  0x00000000, 
  0x00000000, 
  0x00000000, 
  0x00000000, 
  0x00000000, 
};

const UINT32 flappy_down_bitmap[BIRD_HEIGHT] = {
  0x00000000, 
  0x00000000, 
  0x00000000,
  0x000fff00,
  0x000fff00,
  0x00f060c0,
  0x00f060c0,
  0x03018030,
  0x03018030,
  0x0c0180cc,
  0x0c0180cc,
  0x300180cc,
  0x300180cc,
  0x3000600c,
  0x3000600c,
  0x7fe01ffe,
  0x7fe01ffe,
  0x80186001,
  0x80186001,
  0x80619ffe,
  0x80619ffe,
  0x81806006,
  0x81806006,
  0x7f801ff8,
  0x7f801ff8,
  0x007fe000,
  0x007fe000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

const UINT32 flappy_bitmaps[] = {
  flappy_bitmap,
  flappy_middle_bitmap,
  flappy_down_bitmap,
};

const UINT32 pipe_section_bitmap[PIPE_SECTION_HEIGHT] = {
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF,
   0xFFFFFFFF

};

const UINT8 zero_bitmap[FONT_LENGTH] = {
    0x00, 
    0x18, 
    0x24, 
    0x24, 
    0x24,
    0x18,
    0x00 
};

const UINT8 one_bitmap[FONT_LENGTH] = {
    0x00, 
    0x08, 
    0x18, 
    0x08, 
    0x08,
    0x08,
    0x1c 
};

const UINT8 two_bitmap[FONT_LENGTH] = {
    0x00, 
    0x38, 
    0x04, 
    0x18, 
    0x20,
    0x3c,
    0x00 
};

const UINT8 three_bitmap[FONT_LENGTH] = {
    0x00, 
    0x38, 
    0x04, 
    0x18, 
    0x04,
    0x38,
    0x00 
};

const UINT8 four_bitmap[FONT_LENGTH] = {
    0x00, 
    0x0c, 
    0x14, 
    0x24, 
    0x3e,
    0x04,
    0x00 
};

const UINT8 five_bitmap[FONT_LENGTH] = {
    0x00, 
    0x3c, 
    0x20, 
    0x3c, 
    0x04,
    0x3c,
    0x00 
};

const UINT8 six_bitmap[FONT_LENGTH] = {
    0x00, 
    0x1c, 
    0x20, 
    0x3c, 
    0x42,
    0x3c,
    0x00 
};

const UINT8 seven_bitmap[FONT_LENGTH] = {
    0x00, 
    0x3c, 
    0x04, 
    0x08, 
    0x10,
    0x20,
    0x00 
};

const UINT8 eight_bitmap[FONT_LENGTH] = {
    0x00, 
    0x18, 
    0x24, 
    0x18, 
    0x24,
    0x24,
    0x18 
};

const UINT8 nine_bitmap[FONT_LENGTH] = {
    0x00, 
    0x1c, 
    0x42, 
    0x1e, 
    0x02,
    0x1c,
    0x00 
};

const UINT8 A_bitmap[FONT_LENGTH] = {
    0x1C,
    0x22,
    0x42,
    0x7E,
    0x42,
    0x42,
    0x00
};

const UINT8 B_bitmap[FONT_LENGTH] = {
    0x3E,
    0x22,
    0x3E,
    0x22,
    0x22,
    0x3E,
    0x00
};

const UINT8 C_bitmap[FONT_LENGTH] = {
    0x1E,
    0x20,
    0x20,
    0x20,
    0x20,
    0x1E,
    0x00
};

const UINT8 D_bitmap[FONT_LENGTH] = {
    0x3E,
    0x22,
    0x22,
    0x22,
    0x22,
    0x3E,
    0x00
};

const UINT8 E_bitmap[FONT_LENGTH] = {
    0x3E,
    0x20,
    0x3C,
    0x20,
    0x20,
    0x3E,
    0x00
};

const UINT8 F_bitmap[FONT_LENGTH] = {
    0x3E,
    0x20,
    0x3C,
    0x20,
    0x20,
    0x20,
    0x00
};

const UINT8 G_bitmap[FONT_LENGTH] = {
    0x1E,
    0x20,
    0x2E,
    0x22,
    0x22,
    0x1E,
    0x00
};

const UINT8 H_bitmap[FONT_LENGTH] = {
    0x22,
    0x22,
    0x3E,
    0x22,
    0x22,
    0x22,
    0x00
};

const UINT8 I_bitmap[FONT_LENGTH] = {
    0x1C,
    0x08,
    0x08,
    0x08,
    0x08,
    0x1C,
    0x00
};

const UINT8 J_bitmap[FONT_LENGTH] = {
    0x0E,
    0x04,
    0x04,
    0x04,
    0x24,
    0x18,
    0x00
};

const UINT8 K_bitmap[FONT_LENGTH] = {
    0x22,
    0x24,
    0x38,
    0x24,
    0x22,
    0x22,
    0x00
};

const UINT8 L_bitmap[FONT_LENGTH] = {
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0x3E,
    0x00
};

const UINT8 M_bitmap[FONT_LENGTH] = {
    0x63,
    0x55,
    0x49,
    0x41,
    0x41,
    0x41,
    0x00
};

const UINT8 N_bitmap[FONT_LENGTH] = {
    0x62,
    0x32,
    0x1A,
    0x0E,
    0x06,
    0x02,
    0x00
};

const UINT8 O_bitmap[FONT_LENGTH] = {
    0x1C,
    0x22,
    0x22,
    0x22,
    0x22,
    0x1C,
    0x00
};

const UINT8 P_bitmap[FONT_LENGTH] = {
    0x3E,
    0x22,
    0x22,
    0x3E,
    0x20,
    0x20,
    0x00
};

const UINT8 Q_bitmap[FONT_LENGTH] = {
    0x1C,
    0x22,
    0x22,
    0x2A,
    0x14,
    0x0A,
    0x00
};

const UINT8 R_bitmap[FONT_LENGTH] = {
    0x3E,
    0x22,
    0x22,
    0x3E,
    0x24,
    0x22,
    0x00
};

const UINT8 S_bitmap[FONT_LENGTH] = {
    0x1E,
    0x20,
    0x1C,
    0x02,
    0x02,
    0x3C,
    0x00
};

const UINT8 T_bitmap[FONT_LENGTH] = {
    0x7E,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x00
};

const UINT8 U_bitmap[FONT_LENGTH] = {
    0x22,
    0x22,
    0x22,
    0x22,
    0x22,
    0x1C,
    0x00
};

const UINT8 V_bitmap[FONT_LENGTH] = {
    0x41,
    0x41,
    0x22,
    0x14,
    0x08,
    0x08,
    0x00
};

const UINT8 W_bitmap[FONT_LENGTH] = {
    0x41,
    0x41,
    0x49,
    0x55,
    0x63,
    0x41,
    0x00
};

const UINT8 X_bitmap[FONT_LENGTH] = {
    0x41,
    0x22,
    0x14,
    0x08,
    0x14,
    0x22,
    0x00
};

const UINT8 Y_bitmap[FONT_LENGTH] = {
    0x22,
    0x22,
    0x1C,
    0x08,
    0x08,
    0x1C,
    0x00
};

const UINT8 Z_bitmap[FONT_LENGTH] = {
    0x7E,
    0x04,
    0x08,
    0x10,
    0x20,
    0x7E,
    0x00
};

