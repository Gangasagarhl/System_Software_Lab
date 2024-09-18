/*
---------------------------------------------------------------------
NAME:30.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    int key, shmid;
    char *data;
    key=ftok("file", 97);
    shmid=shmget(key, 1024, IPC_CREAT | 0744);
    data=(char *)shmat(shmid, NULL, 0);
    printf("Enter input : ");
    scanf("%[^\n]", data);
    
    printf("\n\nThe shared memory with data:  %s\n", data);
}
