/*
---------------------------------------------------------------------
NAME:10c.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE

DATE: SEP 15 2024

---------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfpe_handler(int signum) {
    printf("Received SIGFPE (Floating Point Exception), its signla number: %d\n", signum);
    exit(1);
}

int main() {
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_handler = sigfpe_handler;
    sa.sa_flags = 0;

    // Register the signal handler for SIGFPE using sigaction
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

   
    int num,den;
    printf("Enter numerator and denominator\nForget not to give 0 as denominator once to check for SIGFPE\n");
    
    scanf("%d %d", &num, &den);
    
    int result = num / den ; // This will cause a SIGFPE

    // This line will not be reached due to the SIGFPE
    printf("Result: %d\n", result);

    return 0;
}

