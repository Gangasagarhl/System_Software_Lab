/*
---------------------------------------------------------------------
NAME:8c.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
c. SIGFPE

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

/*SIGFPE is a signal in Unix-like operating systems, including Linux, that is raised when a process performs an arithmetic exception, such as division by zero or an operation resulting in overflow. The SIGFPE signal stands for "Floating Point Exception," although it is not limited to floating-point arithmetic and can also occur for integer arithmetic exceptions.

When a process encounters an arithmetic exception, the operating system sends the SIGFPE signal to the process, which can then handle the signal by installing a custom signal handler. By default, if the signal is not explicitly caught and handled, the process will typically terminate.

Programs can install signal handlers to intercept SIGFPE and perform specific actions when arithmetic exceptions are detected.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfpe_handler(int signum) {
    printf("\nReceived SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {
    // Catch SIGFPE using the signal system call
    signal(SIGFPE, sigfpe_handler);

    printf("Enter a number to divide by zero, this is the best way to see how a signfpe is generated: ");

    int divisor;
    scanf("%d", &divisor);

    int result = 10 / divisor; // Division by zero will cause a SIGFPE

    // This line will not be reached if a SIGFPE occurs
    printf("\nResult: %d\n", result);

    return 0;
}
