#ifndef RENDERER_H
#define RENDERER_H

const UINT32 flappy_bitmap[32] = {
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

void render();

void render_bird();

void render_pipe();

void render_pipe_opening();

void render_ground();

void render_score();

#endif
