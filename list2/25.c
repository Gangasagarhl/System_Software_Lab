/*
---------------------------------------------------------------------
NAME:25.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
DATE: SEP 18 2024
---------------------------------------------------------------------
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int queueIdentifier;
    struct msqid_ds metadata;
    /*
    It contains information about a message queue, such as permissions, message counts, process IDs, and timestamps. This structure is typically used with the msgctl system call to retrieve or modify the properties of a message queue.


struct msqid_ds {
    struct ipc_perm msg_perm;   /* Permissions structure 
    time_t          msg_stime;  /* Time of last msgsnd()
    time_t          msg_rtime;  /* Time of last msgrcv() 
    time_t          msg_ctime;  /* Time of last change in the message queue 
    unsigned long   msg_cbytes; /* Current number of bytes in the queue 
    msgqnum_t       msg_qnum;   /* Number of messages currently in the queue 
    msglen_t        msg_qbytes; /* Maximum number of bytes allowed in the queue 
    pid_t           msg_lspid;  /* PID of last msgsnd() 
    pid_t           msg_lrpid;  /* PID of last msgrcv() 
};

msg_perm:

This is a structure of type ipc_perm that defines the permissions and ownership of the message queue (similar to file permissions).
The ipc_perm structure typically contains the following fields:
uid: User ID of the owner.
gid: Group ID of the owner.
mode: Permission bits (read/write permissions for the user, group, and others).
key: Key associated with the message queue.
seq: Sequence number.
msg_stime:

This is the time of the last successful msgsnd() call (when a message was sent to the queue). It is represented as a time_t type (epoch timestamp).
msg_rtime:

This is the time of the last successful msgrcv() call (when a message was received from the queue). It is also a time_t type.
msg_ctime:

This represents the time of the last change to the message queue, such as when the permissions or ownership were modified. It is updated by calls like msgctl().
msg_cbytes:

This field holds the current number of bytes of messages stored in the queue (i.e., the total size of messages waiting in the queue).
msg_qnum:

This is the number of messages currently in the queue.
msg_qbytes:

This specifies the maximum number of bytes allowed in the message queue (the queue’s capacity in bytes).
msg_lspid:

This stores the process ID (PID) of the last process that sent a message to the queue.
msg_lrpid:

This stores the process ID (PID) of the last process that received a message from the queue.

    */
    
    int msgctlStatus;

    key_t key = ftok(".", 1);

    if (key == -1) {
        perror("Error while computing key!");
        exit(0);
    }

    queueIdentifier = msgget(key, IPC_CREAT | 0700);
    if (queueIdentifier == -1) {
        perror("Error while creating Message Queue!");
        exit(0);
    }

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &metadata);
    /*
    To retrieve the properties of a message queue, the msgctl function can be used with the IPC_STAT command:
    
    The msgctl function can be used to retrieve (IPC_STAT), modify (IPC_SET), or remove (IPC_RMID) a message queue.
The msqid_ds structure allows detailed monitoring and control over the message queue properties.
    */

    if (msgctlStatus == -1) {
        perror("Error while getting Message Queue info!");
        exit(0);
    }

    printf("Access Permission: %o\n", metadata.msg_perm.mode);
    printf("UID: %d\n", metadata.msg_perm.uid);
    printf("GID: %d\n", metadata.msg_perm.gid);
    printf("Time of last message sent: %ld\n", metadata.msg_stime);
    printf("Time of last message received: %ld\n", metadata.msg_rtime);
    printf("Size of queue: %ld\n", metadata.msg_cbytes);
    printf("Number of messages in the queue: %ld\n", metadata.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", metadata.msg_qbytes);
    printf("PID of last sent message: %d\n", metadata.msg_lspid);
    printf("PID of last received message: %d\n", metadata.msg_lrpid);

    return 0;
}
