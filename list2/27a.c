/*
---------------------------------------------------------------------
NAME:27a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write a program to receive messages from the message queue.
a. with 0 as a flag
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
	//= "This code is for receiving message with 0 as a flag";
}msg; 

int main(void) {	
            int ra = rand();
	int key = ftok(".", ra);// generates the unique key
	if(key == -1) {
		perror("Error ouccred while calling ftok\n");
		return 0;
	}
	
	int msg_que = msgget(key, 0666 | IPC_CREAT);// 
	if(msg_que == -1) {
		perror("Error while running msgget\n");
		return 0;
	}
	
	
	
	printf("\nEnter the message to be sent: \n");
	msg.msg_type = 1;
	fgets(msg.msg_text, 50, stdin);
	printf("Message sending is:  %s \n\n",msg.msg_text);
	
	//Sending the message
	msgsnd(msg_que, &msg, sizeof(msg), 0); 
	/*
	int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

		
	msqid:

The message queue identifier returned by msgget().
msgp:

A pointer to the message structure that must contain a long mtype field followed by the message data.
msgsz:

The size of the message data in bytes (excluding the mtype field).
msgflg:

Flags that control the behavior of the function:
IPC_NOWAIT: Do not block if the queue is full.
0: Wait until the message can be sent if the queue is full.

Return Value:
0 on success.
-1 on failure, and errno is set to indicate the error.



Generate a key: ftok() is used to generate a unique key.
Create/access a message queue: msgget() creates or accesses the message queue using the generated key.
Prepare message: The message is stored in the msgbuf structure, where mtype is the message type, and mtext contains the data.
Send message: msgsnd() sends the message to the queue.

	*/
	
	
	//Receiving the msg with 0 as a flag
	int rec = msgrcv(msg_que, &msg, sizeof(msg), 1, 0);
	/*
	ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
	


msqid:

The message queue identifier obtained from msgget().
msgp:

A pointer to a structure that will hold the received message. The structure must contain a long mtype field followed by the message data.
msgsz:

The maximum size of the message data (excluding the mtype field) that can be received.
msgtyp:

The type of the message to be received:
If msgtyp > 0: Receives the first message of the exact type.
If msgtyp == 0: Receives the first message in the queue, regardless of type.
If msgtyp < 0: Receives the first message of the lowest type less than or equal to the absolute value of msgtyp.
msgflg:

Flags that control the behavior of the function:
IPC_NOWAIT: Do not block if there are no messages of the requested type.
MSG_NOERROR: Truncate the message if it is longer than msgsz.
	*/
	if(rec == -1) {
		perror("Message not received");
		return 0;
	}
	
	printf("Message Received is %s\n", msg.msg_text);
}
