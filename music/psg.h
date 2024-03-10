#include <osbind.h>
#include "..\raster\types.h"

#ifndef PSG_H
#define PSG_H

/* Main PSG Routines */
void write_psg (int reg, UINT8 val);

UINT8 read_psg (int reg);

void set_tone (int channel, int tuning);

void set_volume (int channel, int volume);

void enable_channel (int channel, int tone_on, int noise_on);

void stop_sound ();

/* Sound Effects */
void set_noise (int tuning);

void set_envelope (int shape, unsigned int sustain);

#endif
