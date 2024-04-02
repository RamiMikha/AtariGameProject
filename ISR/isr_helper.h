#ifndef ISR_HELPER_H
#define ISR_HELPER_H

#include "..\music\music.h"
#include "..\events\events.h"

#define VBL 28
#define IKBD 70

#define DATA_READY 0x80
#define MFP_RECIEVE_ON 0x40
#define MOUSE_INPUT 0xF8
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
Vector install_vector(int num, Vector vector);
void VBL_isr();
void do_VBL_ISR();
void IKBD_isr();
void do_IKBD_ISR();

void enqueue_key(int key);
int dequeue_key();
void disable_midi_interrupt();
void enable_midi_interrupt();

#endif