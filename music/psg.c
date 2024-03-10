#include "psg.h"

void write_psg (int reg, UINT8 val) {
  volatile char *PSG_reg_select = 0xFF8800;
  volatile char *PSG_reg_write = 0xFF8802;
  
  *PSG_reg_select = reg;
  *PSG_reg_write = val;

  long old_ssp = Super(0);
}

void set_tone (int channel, int tuning) {

  /* Coarse Tuning */
  write_psg(channel * 2 + 1, tuning >> 8);
  
  /* Fine Tuning*/
  write_psg(channel * 2, tuning & 0xFF);
  
}

void set_volume (int channel, int volume) {
  write_psg(channel, volume);
}

void enable_channel (int channel, int tone_on, int noise_on) {
  UINT8 reg_value = 0;

  if (tone_on) {
    reg_value |= (1 << channel);
  }

  if (noise_on) {
    reg_value |= (1 << (channel + 3));
  }

  write_psg (channel, reg_value);
}

void stop_sound() {
  Super(old_ssp);
}
