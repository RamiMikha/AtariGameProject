#ifndef VBL_HELPER_H
#define VBL_HELPER_H


#define VBL 28

typedef void (*Vector) ();


Vector install_vector(int num, Vector vector);
void VBL_isr();
void do_VBL_ISR();

#endif