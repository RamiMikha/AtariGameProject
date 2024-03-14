#include "music/music.h"
#include <osbind.h>



UINT32 get_time() {
    long *timer = (long *)0x462;
    long timeNow;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}

int main(){
    int quit = 0;
    UINT32 timeThen, timeNow, timeElapsed = 0;
    start_music();

    timeThen = get_time();
    while(quit < 100){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0)
        {
            update_music(timeElapsed);
            quit++;
        }
        timeThen = timeNow;
        
    }
    stop_sound();
    return 0;
}