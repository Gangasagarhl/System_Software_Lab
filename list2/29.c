/*
---------------------------------------------------------------------
NAME:29.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write a program to remove the message queue.
DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<errno.h>

int main(void) {
    int ra = rand();
    int key = ftok(".", ra);
    if(key == -1) {
    	printf("Error number: %d\n",errno);
    	perror("Error occured while running ftok:\n");
    	return 0;
    }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1) {
    	printf("Error number: %d\n",errno);
    	perror("Error occured while running msgget");
    	return 0;
    }
    
    printf("Message queue id = %d\n", msgid);


    int ctr = msgctl(msgid, IPC_RMID, NULL);// removing the created msg queue
    if(ctr == -1) {
        printf("Error number: %d\n",errno);
        perror("Error while calling msgctl");
        return 0;
    }

    printf("Message queue removed.\n");
}
