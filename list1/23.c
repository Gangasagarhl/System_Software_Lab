/*
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
NAME: 23.C
AUTHOR:  GANGASAGAR HL
DESCRIPTOR: Write a program to create a Zombie state of the running program.
DATE:29TH AUGUST 7PM
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


#include <stdio.h>//iop
#include <stdlib.h>//exit
#include <unistd.h>//fork(),getpid()

int main() {
    
    pid_t child_pid = fork(); // Create a child process
    // the main target is, by the time exit called by child, the parent should be either sleepy or parent will not executing at all, hence the handling of the process id of child don't happen normally'
    if (child_pid == 0) {
        // This code runs in the child process
        printf("Inside child process \n");
        printf("CHILD PID : %d\n",getpid());
        printf("Child process is exiting.\n\n");
        printf("have a look at the process before child going to sleep\n\n");
        system("ps aux | grep Z");//prints the zombie process
        exit(0); // Child process exits
    } else if (child_pid > 0) {
        // This code runs in the parent process
        printf("PARENT PID : %d\n",getpid());
        printf("Parent process is running.\n");
        
        sleep(40); // Sleep for 120 seconds to ensure the child becomes a zombie
        
        printf("\n\nProcess After parent coming from sleep\n");
        system("ps aux | grep Z");//prints the zombie process
        
        printf("\n\nParent process is exiting.\n");
    } else {
        printf("Fork system call error:\n");
        return 1; // Fork failed
    }

    return 0;
}

//to chcek the the process that is zombied ""
