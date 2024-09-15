/*
---------------------------------------------------------------------
NAME:9.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

DATE: SEP 15 2024

---------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Ignore SIGINT using the signal system call
    signal(SIGINT, SIG_IGN);

    printf("SIGINT is now ignored. Try  Ctrl+C check whether it is working or not.\n");

    // Sleep to allow time for user input (Ctrl+C)
    sleep(10);

    // Reset SIGINT to its default action using the signal system call
    signal(SIGINT, SIG_DFL);

    printf("\nSIGINT is now reset to its default action.\n");

    while (1) {
        // Program continues running until Ctrl+C is pressed
    }

    return 0;
}

