#ifndef ISR_HELPER_H
#define ISR_HELPER_H

#include "..\music\music.h"
#include "..\events\events.h"
#include <stdio.h>

#define IKBD_BASE_ADDRESS 0xFFFC00
#define IKBD_RDR_ADDRESS 0xFFFC02
#define MIDI_REGISTER_ADDRESS 0xFFFC04
#define MFP_8_REGISTER_ADDRESS  0xFFFA11

#define VBL 28
#define IKBD 70

#define DATA_READY 0x80
#define MFP_RECIEVE_ON 0x40
#define MOUSE_INPUT 0xF8
#define LEFT_BUTTON_PRESS 0xFA
#define RIGHT_BUTTON_PRESS 0xF9
#define KEY 0
#define MOUSE_BUTTON 1
#define MOUSE_X 2
#define MOUSE_Y 3
#define KEY_BUFFER_SIZE 256

typedef void (*Vector) ();
typedef UINT8 SCANCODE;

extern int render_request;
extern int key_buffer_head;
extern int key_buffer_tail;
extern int mouse_x_value;
extern int mouse_y_value;
extern int mouse_button_state;
extern int mouse_x_prev;
extern int mouse_y_prev;
Vector install_vector(int num, Vector vector);
void IKBD_isr();
void do_IKBD_ISR();

void enqueue_key(int key);
int dequeue_key();
void disable_midi_interrupt();
void enable_midi_interrupt();

#endif
