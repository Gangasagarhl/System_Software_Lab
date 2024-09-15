/*
---------------------------------------------------------------------
NAME:10a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    printf("Received SIGSEGV (Segmentation Fault) its signal number: %d\n", signum);
    exit(1);
}

/*
is used to specify the action to be taken when a specific signal is received by a process. It is typically employed with the sigaction system call to install signal handlers for various types of signals.
*/
int main() {
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_handler = sigsegv_handler;
    sa.sa_flags = 0;
    /*
      struct sigaction {
    void (*sa_handler)(int); // Pointer to the signal-handling function or one of the special values: SIG_DFL, SIG_IGN, or SIG_ERR
    sigset_t sa_mask;        // Signals to be blocked during the execution of the signal handler
    int sa_flags;            // Flags that modify the behavior of the signal
    void (*sa_sigaction)(int, siginfo_t *, void *); // Pointer to the signal-handling function with extended information (optional)
};

    
    
    sa_handler: This member specifies the action to be taken on receipt of the signal. It can be a pointer to the signal-handling function, such as a custom signal handler, or one of the special values: SIG_DFL to execute the default action for the signal or SIG_IGN to ignore the signal. Additionally, SIG_ERR can be used to indicate an error in the signal handling.

sa_mask: This member specifies the set of signals that should be blocked (i.e., not delivered) while the signal handler is executing. This helps prevent the occurrence of certain types of nested signals or concurrent signal handling.

sa_flags: This member specifies flags that modify the behavior of the signal. For example, the SA_RESTART flag ensures that certain system calls are automatically restarted if they are interrupted by the signal during their execution.

sa_sigaction: This member is used when employing the SA_SIGINFO flag in sa_flags to specify a pointer to a signal-handling function that takes three arguments, providing extended information about the signal and its context. This is used when advanced information about the signal is required.

The sigaction structure is used in conjunction with the sigaction system call to control how signals are handled by the process. By initializing a sigaction structure and passing it to sigaction(), developers can install custom signal handlers, specify the behavior for handling signals, and control how the process responds to different types of signals.


    */
    // Register the signal handler for SIGSEGV using sigaction
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    
/*
o install custom signal handlers for specific types of signals. It allows programmers to define how the process should respond when a particular signal is received.

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);


signum: This is the signal number for which the action is being set. For example, SIGINT, SIGSEGV, SIGTERM, etc.

act: A pointer to a struct sigaction containing the new action to be taken when the specified signal is received. This structure specifies the desired behavior, including the handler function to be called, the set of signals to be blocked, and any additional flags.

oldact: This is an optional pointer to a struct sigaction that, if not NULL, will be used to store the previous action that was associated with the signal. This allows the caller to retrieve and potentially restore the previous signal action.

The purpose of the sigaction function is to atomically change the action (handler, mask, and flags) associated with a specific signal. By calling sigaction, a process can set up its custom signal handling, potentially modifying the behavior of the system for a given signal in a controlled and thread-safe manner.
*/

    // Trigger a segmentation fault
    int *ptr = NULL;
    *ptr = 890; // This will cause a segmentation fault

    // This line will not be reached due to the segmentation fault
    printf("Program continues after the segmentation fault.\n");

    return 0;
}
