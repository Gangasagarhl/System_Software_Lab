/*
---------------------------------------------------------------------
NAME:27a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag

DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buf {
	long msg_type;
	char msg_text[100];
}msg; 

int main(void) {	
	int ra = rand();
	int key = ftok(".", ra);
	if(key == -1) {
		perror("Error ouccred while calling ftok");
		return 0;
	}
	
	int msg_que = msgget(key, 0666 | IPC_CREAT);
	if(msg_que == -1) {
		perror("Error while running msgget");
		return 0;
	}
	
	printf("\nEnter the message to be sent: \n");
	msg.msg_type = 1;
	fgets(msg.msg_text, 50, stdin);
	
	//Sending the message
	msgsnd(msg_que, &msg, sizeof(msg), 0); 
	
	//Receiving the msg with IPC_NOWAIT as a flag
	int rec = msgrcv(msg_que, &msg, sizeof(msg), 1, IPC_NOWAIT);
	if(rec == -1) {
		perror("Message not received");
		return 0;
	}
	
	printf("Message Received is %s\n", msg.msg_text);
}
