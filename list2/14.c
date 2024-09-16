/*
---------------------------------------------------------------------
NAME:14.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor
DATE: SEP 16 2024

---------------------------------------------------------------------
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
    char buf[1000];
    int pipefd[2];
    char s[1000];
    
    //pipe(), creates 2 default file descriptor, one to read and another one to write
    
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(0);
    }
    printf("Now pipe created successfully\nPlease type something to pass into other end of the pipe\n");
    scanf("%[^\n]",s);
    
    
    // writing to the pipe, created
    write(pipefd[1],s,strlen(s));
    //reading from other end of pipe
    printf("Written data on the write end of the pipe is:\n%s\n\n",s);
    read(pipefd[0],buf,strlen(s));
    //priniting on the monitor or stdoutS
    printf("%s\n",buf);
    return 0;
    
    // by default after the process completes the pipe created gets removed
}
