/*
---------------------------------------------------------------------
NAME:28.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write a program to change the exiting message queue permission. (use msqid_ds structure
DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

int main(void) {
            int ra = rand();
	int key = ftok(".", ra);
	if(key == -1) {
		perror("Error occured while calling ftok");
		return 0;
	}
	
	int msg_que = msgget(key, 0777 | IPC_CREAT|  IPC_EXCL );
	if(msg_que == -1) {
	            printf("returned error with errorno: %d\n",errno);
		perror("Error occured while calling msgget");
		return 0;
	}
	
	struct msqid_ds msg_ds;
	int t = msgctl(msg_que, IPC_STAT, &msg_ds);
	/*
	int msgctl(int msqid, int cmd, struct msqid_ds *buf);
	It allows you to retrieve, set, or remove information about a message queue.
	
	msqid:

The message queue identifier returned by msgget().
cmd:

The command to be performed on the message queue. Common commands include:
IPC_RMID: Removes the message queue.
IPC_STAT: Retrieves the current msqid_ds structure (status information about the message queue).
IPC_SET: Sets new values for some fields in the msqid_ds structure (like permissions).
buf:

A pointer to a msqid_ds structure, which holds information about the message queue. It is used to either retrieve or modify the message queue status, depending on the cmd.
Common Commands:
IPC_RMID:

Removes the message queue and any messages still in the queue.
Example usage:
c
Copy code
msgctl(msqid, IPC_RMID, NULL);
IPC_STAT:

Retrieves the current status of the message queue and stores it in the msqid_ds structure.
Example usage:
c
Copy code
struct msqid_ds buf;
msgctl(msqid, IPC_STAT, &buf);
IPC_SET:

Modifies certain fields in the msqid_ds structure, like the message queue's access permissions.
Example usage:
c
Copy code
struct msqid_ds buf;
// First retrieve current settings
msgctl(msqid, IPC_STAT, &buf);

// Modify permissions
buf.msg_perm.mode = 0666;
msgctl(msqid, IPC_SET, &buf);

	*/
	if(t == -1) {
		perror("Error occured while calling msgctl1");
		return 0;
	}
	
	printf("The current permission is: %o\n", msg_ds.msg_perm.mode);
	
	msg_ds.msg_perm.mode = 0666;
	
	t = msgctl(msg_que, IPC_SET, &msg_ds);
	if(t == -1) {
		perror("Error occured while calling msgctl2");
		return 0;
	}
	
	printf("The permission changed to %o\n", msg_ds.msg_perm.mode);

}
	
