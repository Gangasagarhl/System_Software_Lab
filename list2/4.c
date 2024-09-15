/*
---------------------------------------------------------------------
NAME:4.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.

DATE: SEP 13 2024
TIME: 4:35PM
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>
#include<unistd.h>
#include <x86intrin.h>
// if the above things is not mentioned, it creates warning, but do not geneate the executable file.


int main() {
    unsigned long long start, end;
    int i;

    start = __rdtsc();
    //The __rdtsc() function is an intrinsic that reads the Time Stamp Counter (TSC) of the processor, which is a special CPU register. This counter starts at zero when the system boots and increments with each CPU clock cycle. It returns a 64-bit value representing the number of clock cycles since the processor was powered on. The function is commonly used for high-resolution timing and performance measurements in code.

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = __rdtsc();

    printf("To make 100 getppid() system call, it took : %llu cycles\n", end - start);

    return 0;
}
