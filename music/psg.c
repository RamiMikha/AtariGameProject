#include "psg.h"

UINT8 reg_value = 0;


void write_psg (int reg, UINT8 val) {
  volatile char *PSG_reg_select = 0xFF8800;
  volatile char *PSG_reg_write = 0xFF8802;
  UINT32 old_ssp;
  
  old_ssp = Super(0);

  *PSG_reg_select = reg;
  *PSG_reg_write = val;

  Super(old_ssp);
}

UINT8 read_psg(int reg) {
    volatile char *PSG_reg_select = (char *)0xFF8800;
    volatile char *PSG_reg_read = (char *)0xFF8802;
    UINT32 old_ssp;
    UINT8 val;

    old_ssp = Super(0);

    *PSG_reg_select = reg;
    val = *PSG_reg_read;

    Super(old_ssp);

    return val;
}

void set_tone (int channel, int tuning) {

  /* Coarse Tuning */
  write_psg(channel * 2 + 1, tuning >> 8);
  
  /* Fine Tuning*/
  write_psg(channel * 2, tuning & 0xFF);
  
}

void set_volume (int channel, int volume) {
  write_psg(8 + channel, volume);
}

void enable_channel (int channel, int tone_on, int noise_on) {
  if (tone_on) {
    reg_value &= ~(1 << channel);
  }
  else {
    reg_value |= (1 << channel);
  }

  if (noise_on) {
    reg_value &= ~(1 << (channel + 3));
  }
  else {
    reg_value |= (1 << (channel + 3));
  }

  write_psg (7, reg_value);
}

void set_noise (int tuning) {
  write_psg(6, tuning & 0x1F);
}

void set_envelope (int shape, unsigned int sustain) {
  write_psg(13, shape & 0x0F);
  write_psg(12, sustain & 0xFF);
  write_psg(11, (sustain >> 8) & 0xFF);
}

void stop_sound() {
  int channel;
  for (channel = 0; channel < 3; channel++) {
    set_volume(channel, 0);
    enable_channel(channel, 0, 0);
  }

}