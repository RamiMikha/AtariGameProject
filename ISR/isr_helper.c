#include "isr_he~1.h"

int seconds = 0;
int count = 0;
int render_request = 0;

volatile char * const IKBD_control = (volatile char *)IKBD_BASE_ADDRESS;
volatile char * const IKBD_status = (volatile char *)IKBD_BASE_ADDRESS;
volatile char * const MIDI_register = (volatile char *)MIDI_REGISTER_ADDRESS;
volatile  SCANCODE * const IKBD_RDR = (volatile SCANCODE *)IKBD_RDR_ADDRESS;
volatile char * const MFP_B_REG = (volatile char *)MFP_8_REGISTER_ADDRESS;

int state = KEY;
int mouse_x_value = 0, mouse_y_value = 0, mouse_button_state = 0;
int key_buffer[KEY_BUFFER_SIZE];
int key_buffer_head = 0;
int key_buffer_tail = 0;


/*This ISR is not being used in the game*/
/*void do_VBL_ISR()
{
    count++;
    if (count == 70){
        seconds++;
        count = 0;
    }

    if(seconds > NOTE_DURATION){
        update_music(seconds);
        seconds = 0;
    }

    bird_gravity();
    pipe_move();
    if (pass_pipe()){
        pipe_spawn();
    }
    render_request = 1;
}*/


void enqueue_key(int key){
    key_buffer[key_buffer_tail] = key;
    key_buffer_tail = (key_buffer_tail + 1) % KEY_BUFFER_SIZE;
}

int dequeue_key(){
    int key = key_buffer[key_buffer_head];
    key_buffer_head = (key_buffer_head + 1) % KEY_BUFFER_SIZE;
    return key;
}

void disable_midi_interrupt(){
    UINT32 old_ssp = Super(0);
    *MIDI_register &= ~DATA_READY;
    Super(old_ssp);
}

void enable_midi_interrupt(){
    UINT32 old_ssp = Super(0);
    *MIDI_register |= DATA_READY;
    Super(old_ssp);
}

/*Mouse input not tested yet, and protection of critical sections not done*/
void do_IKBD_ISR(){
    if(*IKBD_status & DATA_READY){
        SCANCODE scancode = *IKBD_RDR;
        switch (state){
            case KEY:
                if (scancode == MOUSE_INPUT){
                    state = MOUSE_BUTTON;
                }
                else{
                    enqueue_key(scancode);
                }
                break;
            case MOUSE_BUTTON:
                mouse_button_state = scancode;
                state = MOUSE_X;
                break;
            case MOUSE_X:
                mouse_x_value += (int)scancode;
                state = MOUSE_Y;
                break;
            case MOUSE_Y:
                mouse_y_value += (int)scancode;
                state = KEY;
                break;
        }
        *MFP_B_REG &=  ~MFP_RECIEVE_ON;
    }
}

Vector install_vector(int num, Vector vector){
	Vector orig;
	Vector *vectp = (Vector *)((long)num<< 2);
	long old_ssp  = Super(0);

	orig = *vectp;
	*vectp = vector;

	Super(old_ssp);
	return orig;

}

