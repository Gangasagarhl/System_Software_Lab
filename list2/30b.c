/*
---------------------------------------------------------------------
NAME:30.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to create a shared memory.

b. attach with O_RDONLY and check whether you are able to overwrite.

DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

void main() {
    int key, shmid;
    char *data;
    key=ftok("file", 97);
    shmid=shmget(key, 1024, 0);
    data=(char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Shared memory input : %s\n", data);
    
    strcpy(data,"This should overwrite, but will not happen");
}
