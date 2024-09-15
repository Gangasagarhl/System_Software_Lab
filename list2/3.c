/*
---------------------------------------------------------------------
NAME:3.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to set (any one) system resource limit. Use setrlimit system call.

DATE: SEP 13 2024
TIME: 3:32PM
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <unistd.h>


 // Recursive function to cause stack overflow
    void cause_stack_overflow(int depth) {
        int arr[1024]; // Allocate memory on the stack
        //system("ulimit -s");
        printf("Recursion depth: %d\n", depth);
       
        
        cause_stack_overflow(depth + 1); // Recur to exceed stack size
    }
    
    
    
int main() {
    struct rlimit limit;

    // Get the current stack size limit
    if (getrlimit(RLIMIT_STACK, &limit) == 0) {
        printf("Current stack size limit: %ld bytes\n", limit.rlim_cur);
    } else {
        perror("getrlimit failed");
        return 1;
    }

    // Set a new soft stack size limit (e.g., 1MB)
    limit.rlim_cur = 1024*1024;  // When this limit is trying to change
    // by default 1, is nothing but 1 byte, 1024B is nothing but 1 kilo byte, 2^20 is nothing but 1MB
    limit.rlim_max = limit.rlim_max;  // Keep the hard limit unchanged

    if (setrlimit(RLIMIT_STACK, &limit) == 0) {
        printf("New stack size limit set to: %ld bytes\n", limit.rlim_cur);
        
        
    } else {
        perror("setrlimit failed");
        return 1;
    }

    // Trigger a stack overflow by recursion to exceed the limit
    printf("Attempting to exceed stack size limit...\n");

   

    // Start recursion
    cause_stack_overflow(1);

    return 0;
}

