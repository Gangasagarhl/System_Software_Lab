/*
---------------------------------------------------------------------
NAME:8e.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

// This program was already done
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void sigalrm_handler(int signum) {
    printf("Received SIGALRM\n");
    exit(0);
}

int main() {
    // Catch SIGALRM using the signal system call
    signal(SIGALRM, sigalrm_handler);

    printf("From now, after 5 secs, SIGALRM handler is called, using setitmer\n");

    struct itimerval itimer;
    itimer.it_value.tv_sec = 5;
    itimer.it_value.tv_usec = 0;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &itimer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("Waiting for the timer to expire...\n");

    while (1) {
        // Program continues running until SIGALRM is received
    }

    return 0;
}
