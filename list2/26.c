/*
---------------------------------------------------------------------
NAME:26.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to send messages to the message queue. Check $ipcs -q
DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct buffer{
	long mtype;
	char mtext[100];
}msg;

int main(void) {
	int key = ftok(".", 1);// we are creating unique new key to the shared memory resources
// it uses 3 resources properly: file descriptor, devce id and the last byte of teh project id passed
/*

The ftok(".", 1) call generates a key based on the inode and other metadata of the current directory (".") and the project ID 1


*/
	if(key == -1) {
		perror("Error while running ftok");
		return 0;
	}
	
	int msg_que = msgget(key, 0666 | IPC_CREAT);
	//  Creates or retrieves access to a message queue.
	if(msg_que == -1) {
		perror("Error while running msgget");
		return 0;
	}
	
	msg.mtype = 1;
	/*
	mtype: This is a long integer that specifies the type of the message. It's important because the message queue allows processes to send and receive messages of different types. When a process retrieves a message from the queue, it can request a specific message type or accept any message type.
	
	ex: type 1 msg -  text, we can directly store it in the mtext
	type 2 msg - Here we cannot store the image, instead we can store the image somewhere else and we can pass the path of the image here. 
	*/
	printf("Enter msg to send, to the smg queue\n");
	fgets(msg.mtext, 50, stdin);
	/*
	(msg.mtet)str: This is the pointer to a buffer (a character array) where the input string will be stored. In your case, this is msg.mtext. It is the character buffer.
n: This is the maximum number of characters to read, including the null terminator (\0). In your example, 10 means fgets() will read up to 9 characters, leaving space for the null terminator.
stream: This is the input stream to read from. In your case, stdin (standard input) is used, which means the function will read from the keyboard.
	*/
	
	int ms = msgsnd(msg_que, &msg, sizeof(msg), 0);
	/*
	The msgsnd() function in C is used to send a message to a System V message queue. This is part of the inter-process communication (IPC) mechanisms in UNIX-like systems. It allows processes to send messages to a queue, which can then be retrieved by other processes using msgrcv().
	
	
	int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

msqid:

The message queue identifier, returned by msgget(). This specifies which message queue the message will be sent to.
msgp:

A pointer to the message structure that contains the message to be sent. The structure must have a long mtype field at the beginning (indicating the message type) followed by the message data.
msgsz:

The size (in bytes) of the message's data portion (not including the mtype field). This specifies how much data (typically text or some structure) will be sent.
msgflg:

Flags that control the behavior of the msgsnd() function. Common flags include:
IPC_NOWAIT: If the message queue is full, msgsnd() will return immediately with an error instead of waiting.
0: If no flag is specified, the process will wait if the queue is full.
Return Value:
On success, msgsnd() returns 0.
On failure, it returns -1 and sets errno to indicate the error.

	*/
	
	if(ms == -1) {
		perror("Error while running msgsnd");
		return 0;
	}
	
	printf("\nData sent to the message queue\nExecuting ipcs -q\n\n");
	/*
	
	
The ipcs -q command in Linux displays information about active System V message queues on the system. It shows the following details:

key: A unique identifier (key) associated with the message queue, generated using functions like ftok().
msqid: Message queue identifier, which is a unique system-wide identifier.
owner: The user who owns the message queue.
perms: The access permissions for the message queue (in octal format).
used-bytes: The amount of data (in bytes) currently in the message queue.
messages: The number of messages currently in the queue.s
qbytes: Maximum number of bytes that can be in the message queue.
	*/
            system("ipcs -q");
}
