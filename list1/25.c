/*
NAME: 25.C
AUTHOR: GANGASAGAR HL
DESCRIPTION: Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t f1 = fork();

    if (f1 == 0) {
        printf("Child 1\n parent id %d\n child id %d\n\n", getppid(), getpid());
    } 
    else {
        pid_t f2 = fork();

        if (f2 == 0) {
            sleep(10);
            printf("Child 2\n parent id %d\n child id %d\n\n", getppid(), getpid());
        }
         else {
            pid_t f3 = fork();
            if (f3 == 0) {
                printf("Child 3\n parent id %d\n child id %d\n\n", getppid(), getpid());
            } else {
                printf("Leftover part of parent before wait for Child 2\n");
                int status;
                int a = waitpid(f2, &status, WNOHANG);
                /*
                All of these system calls are used to wait for state changes in a child
       of the calling process, and obtain information about  the  child  whose
       state  has changed.  A state change is considered to be: the child ter‐
       minated; the child was stopped by a signal; or the child was resumed by
       a  signal.  In the case of a terminated child, performing a wait allows
       the system to release the resources associated with  the  child;  if  a
       wait  is not performed, then the terminated child remains in a "zombie"
       state (see NOTES below).
                
                */

                if (a == -1) {
                    perror("Waitpid error");
                    return 1;
                }

                if (WIFEXITED(status)) {
                    printf("Child 2 (PID %d) exited with status %d.\n\n", a, WEXITSTATUS(status));
                } else {
                    printf("Child (PID %d) did not exit normally.\n\n", 0);
                }

                printf("Leftover part of parent after wait for Child 2\n");
            }
        }
    }

    return 0;
}
