/*
---------------------------------------------------------------------
NAME:19a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Create a FIFO file by
a. mknod command
b. mkfifo command
DATE: SEP 17 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

    int main(void) {
	
       printf("This is used to create FIFO files\n");
              
	//Create a FIFO file by mknod system call 
        int fd1 = mknod("mknod19", S_IFIFO | 0666, 0);
	if(fd1 == -1) {
		perror("File not created by mknod");
	
		return 0;
	}
	
        printf("FIFO file using mknod is created\n");
	
	//Create a FIFO file by mkfifo library function
	int fd2 = mkfifo("mkfifo19", 0666);
	if(fd2 == -1) {
		perror("File not created by mkfifo");
		return 0;
	}
        printf("FIFO file using mkfifo is created\n");
	}
