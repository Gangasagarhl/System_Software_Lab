/*
---------------------------------------------------------------------
NAME:17.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to execute ls -l | wc.
a. use dup
DATE: SEP 16 2024

---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    int fd[2];
    pid_t pid;

    /*
       pipe()  creates a pipe, a unidirectional data channel that can be used for inter‐
       process communication.  The array pipefd is used to return two  file  descriptors
       referring to the ends of the pipe.  pipefd[0] refers to the read end of the pipe.
       pipefd[1] refers to the write end of the pipe.  Data written to the write end  of
       the  pipe  is  buffered  by  the kernel until it is read from the read end of the
       pipe. 
       
    */
    
    printf("When ls-l|wc , we get the number of:\n\t#lines\tWords\t#Chracters\n");
    if(pipe(fd) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    
    // Usually write has to first processed and raed will processed  what has beeen sent from the write end of the pipe
    if (!pid) {// child, closing read part of the pipr
        close(fd[0]);
        close(1);//cloing the terminal , so that it works under pipe
        dup(fd[1]);// duplicating 
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);// executing and producing output on the pipe with writing end. 
        /*
        The  exec() family of functions replaces the current process image with
       a new process image.  The functions described in this manual  page  are
       layered  on  top  of execve(2).  (See the manual page for execve(2) for
       further details about the replacement of the current process image.)

       The initial argument for these functions is the name of a file that  is
       to be executed.

       The  functions can be grouped based on the letters following the "exec"
       prefix.

        */
        close(fd[1]);
        exit(0);
    } else {// parent, so first executing will be given to 
        close(fd[1]);
        close(0);
        dup(fd[0]);
        char *args[] = {"wc", NULL};
        
        /*
        The command ls -l | wc involves two separate commands connected by a pipe (|), which passes the output of one command as input to the other.

        ls -l: This command lists the files and directories in the current directory in long format, which includes file details like permissions, owner, group, size, and last modification date.

         wc: This command stands for "word count." By default, it provides the number of lines, words, and characters in the input it receives.
        */
        execv("/bin/wc", args);
        
        /*
        The  char *const argv[] argument is an array of pointers to null-termi‐
       nated strings that represent the argument list  available  to  the  new
       program.   The first argument, by convention, should point to the file‐
       name associated with the file being executed.  The  array  of  pointers
       must be terminated by a null pointer.

        */
        close(fd[0]);
    }
    return 0;
}



