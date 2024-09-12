/*
---------------------------------------------------------------------
NAME:1c.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
b.ITIMER_PROF

DATE: SEP 12 2024
TIME: 10:15PM
---------------------------------------------------------------------
*/


#include <stdio.h>// printf function
#include <sys/time.h>// setitimer,  itimerval, 
#include <signal.h>// signal, SIGPROF
#include <unistd.h>//sleep

void handy(int signum) {
    printf("Interval Timer Expired with signum %d: \n", signum);// 27 is retunred
}

int main() {
    struct itimerval timer;// structure, which hastimer to set for
    signal(SIGPROF, handy);// attaching handler functions

    // starting trigger, after te process started to play
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    // setting interval in 10 secs and 10 micro sec
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    
    // used to calculate for both parent and hild process , so based on the
    setitimer(ITIMER_PROF, &timer, NULL);
    /*
    is one of the interval timers used in Unix-like systems to measure the total CPU time (both user and system time) consumed by the process and its children. Unlike ITIMER_VIRTUAL, which only measures the user CPU time (time spent executing the process's code), ITIMER_PROF counts both the time spent in user mode and kernel mode. This is useful for profiling applications, as it tracks how long the process is running, including the time spent in system calls.
    
    Totally it is the combination of both user space and kernel space
    */

    //  There are many states like running, sleeping, stopped,Zombie, ide etc.
    //  
    while (1) {
        // Program will continue running and the timer will trigger every 10 seconds
        //sleep(1);// 1 sec
        // If I don't remve it then waiting will be more, since when slept, the status of the process in execution changes
        // When the sleep() function is called in a process, the process changes its state to a waiting or "sleeping" state. This means the process will no longer be in the "running" state and will not consume CPU time until the specified sleep duration ends.
    }

    return 0;
}

/*
Usecase: 

Typically used for profiling and performance analysis to track how much CPU time (user + kernel) is consumed.
For example, it helps you determine how long a process spends executing user code versus time spent in system calls (e.g., file I/O, memory management).


*/
