/*
---------------------------------------------------------------------
NAME:13_1.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

It is the first program, there is the signal handler, waiting to check wheteher signal stop could bee acught or not.
DATE: SEP 17 2024
---------------------------------------------------------------------
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Caught signal %d\n", signum);
}

int main() {
    // Register signal handler for SIGTERM and SIGINT
    printf("Registering the signal handlre to sigstop\nWaiting for teh signal SIGSTOP...\n");
    signal(SIGTERM, signal_handler);  // SIGTERM can be caught
    signal(SIGINT, signal_handler);   // SIGINT can be caught
    signal(SIGSTOP, signal_handler); // alloting 

    printf("Running process's (PID: %d)\n", getpid());

    // Infinite loop to keep the program running and waiting for signals
    while (1) {
        sleep(1);
    }

    return 0;
}

