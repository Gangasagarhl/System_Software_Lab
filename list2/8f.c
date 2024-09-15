/*
---------------------------------------------------------------------
NAME:8f.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)

DATE: SEP 15 2024

---------------------------------------------------------------------
*/
// this computes only the time consumed by the process in execution, kernel, wait time thsese are all ignored
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void sigvtalrm_handler(int signum) {
    printf("Received SIGVTALRM %d\n", signum);
    exit(0);
}

int main() {
    // Catch SIGVTALRM using the signal system call
    signal(SIGVTALRM, sigvtalrm_handler);

    printf("Virtual timer is set for 5 secs from now, which counts only the process actual execution time\n");

    struct itimerval itimer;
    itimer.it_value.tv_sec = 5;
    itimer.it_value.tv_usec = 0;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &itimer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("Waiting for the virtual timer to expire...\n");

    while (1) {
        // Program continues running until SIGVTALRM is received
    }

    return 0;
}


