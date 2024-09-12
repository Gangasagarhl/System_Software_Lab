/*
---------------------------------------------------------------------
NAME:1b.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
b.ITIMER_VIRTUAL 

DATE: SEP 12 2024
TIME: 9:30PM
---------------------------------------------------------------------
*/

#include <stdio.h>// printf
#include <sys/time.h>// setitimer, itimerval
#include <signal.h>//signal, SIGVTALRM
#include <unistd.h>// usleep

// handlre function called everytime when the
void handling_function(int signum) {
    printf("Interval Timer Expired with signum: %d!\n",signum);// signum for SIGVTALRM is 26
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, handling_function);
    // in this case we are consuming in terms of cpu clock ticks, virtual clock timings are considered 
    // my laptops maximum clock frequency is 3400 mhz, 3.4ghz. To make 1 clock time it is taking around, 0.294 * 10^-9 secs, to make
    // to make 10 secs,  the laptop, especially the processor has to make almost 34*10^9 number of CPU CLOCK TICKS, to make 10 secs, my laptops, process has to make these many number of clock ticks.(maximum)
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 10;// after the process started to execute and the process spends 10 micro seconds,  first SIGVTALRM is called.
    // this is specifically mentioned only for the processor/root/ parent not the child , wait, IO etc.
    timer.it_interval.tv_sec = 10;// 
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1); 
    /*
    {usleep(1000);}
    */
    // Program will continue running and the timer will trigger every 10 microseconds
        // need to remove this so that output gets generated fastly, since no sleep of the processor, it is not like the other.
    

    return 0;
}
