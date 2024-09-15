/*
---------------------------------------------------------------------
NAME:8d.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>// alarm(), calls SIGALARM 

void sigalrm_handler(int signum) {
    printf("Received SIGALRM\n");
    exit(0);
}
/*
When you call the alarm() function in a program, it can have different effects based on the return value of the function and the arguments passed. Let's break down the explanation based on the behavior of the alarm() function:

Returns the number of seconds remaining until any previously scheduled alarm, or zero if no alarm was scheduled:

If no alarm was previously set, calling alarm() with a new time value will return 0.
If an alarm was previously set, calling alarm() with a new time value will return the number of seconds remaining until the previously scheduled alarm was supposed to go off.
This return value is useful for programs that need to know how much time is remaining until a scheduled alarm triggers. It allows the program to adjust its logic or perform other tasks based on the remaining time.

Cancel a previously set alarm by calling alarm(0):

Passing a value of 0 to alarm() effectively cancels any previously set alarm.
When alarm(0) is called, it stops the previously scheduled alarm from triggering and returns the number of seconds remaining until the alarm was originally set to go off.
This is a way to reset the alarm and prevent any pending alarm from occurring.
By leveraging the return value of alarm() and calling alarm(0) to cancel any previously set alarms, developers can effectively manage scheduled alarms in their programs. This capability enables the program to handle timing-related tasks, implement timeouts, and control the behavior based on the scheduled alarms more efficiently.
*/
int main() {
    // Catch SIGALRM using the signal system call
    signal(SIGALRM, sigalrm_handler);

    printf("Setting an alarm for 5 seconds...\n");
    //The alarm() system call in Unix-like operating systems, including Linux, is used to schedule a signal (by default, the SIGALRM signal) to be delivered to the calling process after a specified number of seconds. 
    alarm(5); // Set an alarm for 5 seconds
    /*
    When the specified number of seconds elapses, the process will receive a SIGALRM signal, interrupting the process's current execution.

Programs can install signal handlers for SIGALRM to take specific actions when the alarm signal is received. This functionality is commonly used in situations where a process needs to perform an action after a certain period of time has elapsed, such as timing out an operation, scheduling periodic tasks, or handling time-related events.

For example, a program might use alarm() in conjunction with a signal handler for SIGALRM to implement a timeout mechanism, ensuring that an operation completes within a specified time frame.
    */
    

    printf("Waiting for the alarm...\n");

    while (1) {
        // Program continues running until SIGALRM is received
    }

    return 0;
}

