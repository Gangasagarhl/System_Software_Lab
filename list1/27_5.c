/*
NAME:27_5.C
AUTHOR:GANGASAGAR HL
PROBLEM DESCRIPTION: Write a program to execute ls -Rl by the following system calls
execvp
*/
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
     printf("execvp system call\n");
    // Execute the "ls -RL" command using execlp
    int ret = execvp("ls", args	);

    // Check for errors in the execlp call
    if (ret < 0) {
        perror("execlp");
        return 1; // Return an error code
    }

    // The code will not reach this point if execlp is successful

    // The following line will not be executed if execlp succeeds
    printf("hello");

    return 0;
}
