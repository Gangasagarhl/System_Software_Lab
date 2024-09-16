/*
---------------------------------------------------------------------
NAME:15.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a simple program to send some data from parent to the child process.
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
    int pipefd[2];
    int fd1;
    char *buf="Hi I'm at 15th lab program\n";
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(0);
    }

    fd1 = fork();
    if(fd1 == -1){
        perror("fork");
        exit(0);
    }
    else if(fd1 == 0){
        char b1[100];
        // closing the unused end, here child id meant to read the data
        close(pipefd[1]);
        printf("Inside child process reading...\n");
        // read is a block call, so keeps waiting till it read and finished
        int s = read(pipefd[0],&b1,sizeof(buf));
        if(s==-1){
           perror("Error\n");
           exit(0);
        }
        printf("The message sent from parent is:\n%s\n",buf);
        //close(pipefd[0]);
    }
    else{
        printf("\nParent process writing to child...\nMessage:  %s\n",buf);
        close(pipefd[0]);// closing the read end unused.
        write(pipefd[1], &buf, strlen(buf));
        close(pipefd[1]);
        exit(0);
    }
    return 0;
}
