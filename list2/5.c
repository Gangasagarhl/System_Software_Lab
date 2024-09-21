/*
---------------------------------------------------------------------
NAME:5.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.


DATE: SEP 12 2024
TIME: 11:15PM
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>
//#include <limits.h>
//#include <sys/time.h>
#include <sys/resource.h>
//The sysconf() function in Linux is used to query system configuration limits and parameters at runtime. It provides information about system limits like the number of processors, maximum file descriptors, and memory page sizes. Unlike hardcoded constants, sysconf() retrieves these values dynamically, ensuring they reflect the current system's settings.



int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec functions: %ld\n", arg_max);

    // b. Maximum number of simultaneous processes per user ID
    long max_processes = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user ID: %ld\n", max_processes);

    // c. Number of clock ticks (jiffy) per second
    long ticks_per_second = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second: %ld\n", ticks_per_second);
    
    // d. Maximum number of open files
    struct rlimit rlim;
    getrlimit(RLIMIT_NOFILE, &rlim);
    printf("Maximum number of open files: %ld\n", rlim.rlim_max);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory
    long available_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in the physical memory: %ld\n", available_pages);

    return 0;
}

