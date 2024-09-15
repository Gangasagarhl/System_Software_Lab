/*
---------------------------------------------------------------------
NAME:10b.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using sigaction system call to catch the following signals.
b. SIGINT

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("\nReceived SIGINT (Interrupt), its signal number is %d\n", signum);
    exit(0);
}

int main() {
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;// by default 

    // Register the signal handler for SIGINT using sigaction
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("CNTRL C is used to generate SIGNINT signal\nNow system is in infinite loop\n Press Control C to generate sigint\n");

    while (1) {
        // Program continues running until Ctrl+C is pressed
    }

    return 0;
}

