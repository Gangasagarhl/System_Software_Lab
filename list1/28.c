/*
NAME: 28.C
AUTHOR:GANGASAGAR HL
DESCRIPTION: Write a program to get maximum and minimum real time priority.
*/

#include <stdio.h>//printf
#include <sched.h>//sged_get_prio
#include<stdlib.h>//exit

int main() {
    int maxprio= sched_get_priority_max(SCHED_RR);
    if (maxprio == -1) {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    int minprio = sched_get_priority_min(SCHED_RR);
    if (minprio== -1) {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    printf("Maximum  priority: %d\n", maxprio);
    printf("Minimum  priority: %d\n", minprio);

    return 0;
}
