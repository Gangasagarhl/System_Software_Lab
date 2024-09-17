/*
---------------------------------------------------------------------
NAME:13_1.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Sending signal to the other process, SIGSTOP
DATE: SEP 17 2024
---------------------------------------------------------------------
*/

// need to ecute other first, then it can be use to send teh sigstop signal through kill
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID of target process>\n", argv[0]);
        return 1;
    }

    pid_t target_pid = atoi(argv[1]);

    // Send SIGSTOP signal (cannot be caught)
    printf("Sending SIGSTOP to process %d\n", target_pid);
    /*
    
    int kill(pid_t pid, int sig);
    
    pid: The process ID of the target process. Special values:

pid > 0: Sends the signal to the process with the given PID.
pid == 0: Sends the signal to all processes in the same process group as the caller.
pid == -1: Sends the signal to all processes the user has permission to send signals to.
pid < -1: Sends the signal to all processes in the process group -pid.
sig: The signal to be sent (e.g., SIGKILL, SIGTERM).

Return Value:
Returns 0 on success.
Returns -1 on error, with errno set to indicate the error.
    */
    kill(target_pid, SIGSTOP);
    

    sleep(2);  // Pause for a while to observe the effect

    // Send SIGCONT to resume the stopped process
    printf("Sending SIGCONT to process %d\nResuming back te process which has stopped\n", target_pid);
    kill(target_pid, SIGCONT);

    sleep(2);

    // Send SIGTERM signal (can be caught)
    printf("Sending SIGTERM to process %d\nTerminating the process\n", target_pid);
    kill(target_pid, SIGTERM);

    return 0;
}

