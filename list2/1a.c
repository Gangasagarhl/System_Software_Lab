/*
---------------------------------------------------------------------
NAME:1a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL

DATE: SEP 12 2024
TIME: 4:30PM
---------------------------------------------------------------------
*/

/*
SIGALRM is a signal in Unix-like systems that is sent to a process when a timer set by setitimer or alarm expires. It is commonly used to interrupt a process after a specified amount of real (wall-clock) time has passed. This allows the process to handle timed events, timeouts, or perform periodic tasks without blocking the main flow of execution. When the signal is received, a signal handler (if set) is executed to handle the event.*/

#include <stdio.h>// printf 
#include <sys/time.h>// strcut itimerval,  setitimer
#include <signal.h>//signal,SIGALRM
#include <unistd.h>// sleep
//#include<stdlib.h>//exit call;

void handler(int signum) {
    printf("SIGALRM Called!\n");
    //exit(0);// usually after handling the signal it has to come out of the handler by making exit call, the control stays here, it has to return to the kernel.
    
}

int main() {
    struct itimerval timer;// specify teh setting of interval timer
    /*
       struct itimerval {
    struct timeval it_interval;  // Interval for periodic timer
    struct timeval it_value;     // Initial expiration time
};
    */
    signal(SIGALRM, handler);
    /*
    
    The line signal(SIGALRM, handler) sets up a signal handler for the SIGALRM signal in Unix-like systems. Here's what it does:

SIGALRM: This is the signal sent to the process when a timer (like one set with alarm() or setitimer()) expires.
handler: This is a function that will be executed whenever the SIGALRM signal is received by the process. You define the handler function to specify what the program should do when the signal arrives (e.g., printing a message or performing some specific action).
By using signal(SIGALRM, handler), you tell the operating system that when the SIGALRM signal occurs, the handler function should be called.

    */

    timer.it_value.tv_sec = 10;
    // it says, suppose now it 9:15pm, 20 secs,  ring occurs at 30 secs, because we have given the tv_sec=10.
    
    timer.it_value.tv_usec = 0;
    // micro seconds
    
    // this makes signaled or alarmed, after every 10 secs, after 9:15pm 30secs, 40secs, 50 secs etc
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    // 
    setitimer(ITIMER_REAL, &timer, NULL);
    // in place of null if you give the structure then that structure will have the value regarding the all the things, the previous setting we made to the struct itmerval. 

    while (1) {
        // Program will continue running and the timer will trigger every 10 seconds
        sleep(1);
    }

    return 0;
}

/*

ITIMER_REAL: A real-time timer. The timer counts down in real time and sends a SIGALRM signal when it expires.(9:15pm, 9:16pm etc)
It measures the actual elapsed time, including any time the process spends waiting for I/O or being blocked. This timer includes time during which the process is not actively running, such as when it is waiting for a system call to complete or when the CPU is used by other processes. It is not specific to CPU usage or process activity.

VIRTUAL

ITIMER_VIRTUAL: Counts down based on the CPU time consumed by the process (does not count down during system calls or when the process is sleeping).

ITIMER_VIRTUAL measures CPU time used by the process. It counts only the CPU time consumed while the process is actively executing instructions, not including time spent in system calls, sleeping, or waiting for I/O. This timer is useful for monitoring the CPU resources a process uses. It does not account for wall-clock time or time spent by child processes.


ITIMER_PROF: Counts down based on the CPU time consumed by the process and its children (both user and system time).

measures the CPU time consumed by the process and its child processes, including both user and system time. It tracks the time the process spends executing on the CPU, as well as the time spent by its children. This timer is useful for profiling CPU usage across process hierarchies. Unlike ITIMER_REAL, it does not include wall-clock time or periods when the process is waiting.

does not count waiting or blocking time. It measures the combined CPU time used by both the process and the system on behalf of the process (i.e., user time and system time). This includes time spent executing the program's code and time spent in kernel mode during system calls, but it excludes time when the process is idle, waiting for I/O, or blocked. It's useful for profiling CPU-bound activities.

*/
