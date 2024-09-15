/*
---------------------------------------------------------------------
NAME:8b.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
b. SIGINT

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("\nReceived SIGINT (Interrupt)\n");
    exit(0);
}
/*

is sent to a process to interrupt its execution. It is typically triggered by the user pressing Ctrl+C in the terminal where the process is running. The purpose of SIGINT is to provide a way for a user to gracefully terminate a running process or to bring the process to the foreground if it is running in the background.

When a process receives the SIGINT signal, it can choose to handle the signal by performing custom actions before exiting. By default, if the signal is not caught and handled explicitly by the process, it will cause the process to terminate.

Programs can install signal handlers to intercept SIGINT and perform specific actions when the Ctrl+C sequence is detected. For example, a program might use a signal handler to clean up resources, save state, or perform other tasks to ensure a graceful shutdown when it receives a SIGINT signal.

*/
int main() {
    // Catch SIGINT using the signal system call
    signal(SIGINT, sigint_handler);

    printf("Cntrl + C generates signal interrupt, now program is in loop, waiting for you to enter cntrl+c\n");

    while (1) {
        // Program continues running until SIGINT is received
    }

    return 0;
}
