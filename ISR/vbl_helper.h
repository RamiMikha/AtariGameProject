#ifndef VBL_HELPER_H
#define VBL_HELPER_H

#include "..\music\music.h"
#include "..\events\events.h"

#define VBL 28

typedef void (*Vector) ();

extern render_request;

Vector install_vector(int num, Vector vector);
void VBL_isr();
void do_VBL_ISR();

#endif