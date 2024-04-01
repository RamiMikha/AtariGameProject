#include "isr_helper.h"

int seconds = 0;
int count = 0;
int render_request = 0;

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


void do_IKBD_ISR(){
    
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

}