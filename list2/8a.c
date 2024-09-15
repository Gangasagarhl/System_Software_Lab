/*
---------------------------------------------------------------------
NAME:8a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
a. SIGSEGV

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    printf("Received Segmentation violation error\n");
    exit(1);
}

int main() {
    // Catch SIGSEGV using the signal system call
    signal(SIGSEGV, sigsegv_handler);
   /*
   SIGSEGV, which is a signal that is raised when a program attempts to access memory that it is not allowed to access. SIGSEGV stands for "Segmentation Violation" and is commonly known as a segmentation fault.

When a program tries to read or write memory that is outside of its allocated memory space, the operating system sends a SIGSEGV signal to the program. This usually indicates a serious issue such as accessing an uninitialized pointer, dereferencing a null pointer, writing beyond the bounds of an array, or attempting to access memory that the program does not have permission to access.

When a program receives a SIGSEGV signal, it typically terminates unless the signal is caught and handled by the program itself. Developers can analyze the cause of the segmentation fault by examining the stack trace and debugging the program to identify the source of the memory access violation.

Handling SIGSEGV errors involves debugging, tracing the memory access violation, ensuring proper memory management practices, and fixing the underlying issue causing the segmentation fault to occur.
   */
    // Trigger a segmentation fault
    int *ptr = NULL;
    *ptr = 1; // This will cause a segmentation fault

    // This line will not be reached due to the segmentation fault
    printf("Program continues after the segmentation fault.\n");

    return 0;
}
