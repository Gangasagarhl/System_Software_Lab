/*
---------------------------------------------------------------------
NAME:12.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to create an orphan process. Use kill system call to send SIGKILL signal to  the parent process from the child process. 

DATE: SEP 15 2024

---------------------------------------------------------------------
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        // If fork fails
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Inside the child process
        printf("Child process (PID: %d)\n", getpid());
        sleep(1);  // Give parent some time

        // Kill the parent process using SIGKILL
        printf("Child (PID: %d) sending SIGKILL to parent (PID: %d).\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        /*
        
        The kill command in Unix-like operating systems is used to send signals to processes. While the name implies it might only be used for terminating processes, it can actually send any signal, not just the SIGKILL (kill signal). By default, if no signal is specified, the kill command sends the SIGTERM (terminate) signal, which allows a process to clean up before it shuts down.
        
        
        signal: The signal number or name (e.g., -9 or -KILL).
PID: The process ID of the process to which you want to send the signal.
Common Signals:
SIGTERM (15): The default signal. It requests a process to terminate, but the process can handle this signal and decide how to terminate. It’s a graceful way to stop a process.

Command: kill PID
SIGKILL (9): This signal forcefully kills a process without allowing it to clean up or handle the termination. It’s useful for killing unresponsive processes.

Command: kill -9 PID or kill -KILL PID
SIGHUP (1): Often used to tell a process to reload its configuration without restarting.

Command: kill -1 PID or kill -HUP PID
SIGINT (2): Equivalent to pressing Ctrl+C in a terminal. It interrupts and stops a process.

Command: kill -2 PID or kill -INT PID
SIGSTOP (19): This signal pauses the execution of a process, which can be resumed later using SIGCONT.

Command: kill -19 PID or kill -STOP PID
SIGCONT (18): Resumes a process that was paused (stopped by SIGSTOP or Ctrl+Z).

Command: kill -18 PID or kill -CONT PID
        
        
        
        
        */

        // Parent is now terminated, and child becomes orphan
        printf("Child (PID: %d) now orphaned and adopted by init.\n", getpid());

        // Sleep to observe that the child is now orphaned
        sleep(1);
        printf("Child (PID: %d) finished, it had the parent pid as %d\n", getpid(), getppid());
    } else {
        // Inside the parent process
        printf("Parent process (PID: %d)\n", getpid());
        sleep(5);  // Wait for a while (child will kill us before this completes)
        printf("\nIf this printf executes, then parent process is not killed else killed\n");
    }

    return 0;
}

