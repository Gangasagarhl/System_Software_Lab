/*
---------------------------------------------------------------------
NAME:8g.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void sigprof_handler(int signum) {
    printf("Received SIGPROF it's signal number is: %d'\n", signum);
    exit(0);
}

int main() {
    // Catch SIGPROF using the signal system call
    signal(SIGPROF, sigprof_handler);

    printf("This computes the time taken by process+kernel+child but not wait and IO, 5 secs has been set from now, so then signal handler is called.\n");

    struct itimerval itimer;
    itimer.it_value.tv_sec = 5;
    itimer.it_value.tv_usec = 0;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &itimer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("Waiting for the profiling timer to expire...\n");

    while (1) {
        // Program continues running until SIGPROF is received
    }

    return 0;
}
