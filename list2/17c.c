/*
---------------------------------------------------------------------
NAME:17.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to execute ls -l | wc.
c. use fcntl
DATE: SEP 17 2024

---------------------------------------------------------------------
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    pipe(fd);
    if ((pid = fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if(!pid) {
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD, STDIN_FILENO);
        /*
        The fcntl() function in Unix-like systems performs various operations on file descriptors. It is typically used to manipulate file descriptors and change file status flags.

File descriptor control: fcntl() can duplicate file descriptors, set them to non-blocking mode, or close them on exec().
File locks: It allows setting, testing, or releasing advisory file locks for coordinating access between processes.
File status flags: It can retrieve or modify flags like O_NONBLOCK (non-blocking mode) and O_APPEND (append mode).
Signal-driven I/O: It can enable signals to be generated when a file descriptor is ready for I/O.
Syntax: The basic form is fcntl(int fd, int cmd, ...), where fd is the file descriptor and cmd specifies the operation.

        */
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        close(fd[0]);
        exit(0);
    } else {
        close(fd[0]);
        close(1);
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
        
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        close(fd[1]);
    }
}
