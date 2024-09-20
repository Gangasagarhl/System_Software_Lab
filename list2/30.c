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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include<signal.h>
#define SHM_SIZE 1000


void handy(int signum){

     printf("\nSegmentation error generated, I'm signal handler speaking\nThe signal number is: %d\n",signum);
     exit(0);
}

int main() {
    int shmid;
    key_t key;
    char *shmaddress;

    key = ftok(".", 'a');
    printf("Key generated is : %d\n",key);
    /*
    int shmget(key_t key, size_t size, int shmflg);
    key: A unique identifier for the shared memory segment. It is used to either create or access a shared memory segment. Multiple processes can use the same key to access the same shared memory segment. Special values:

IPC_PRIVATE: Creates a new shared memory segment that can only be used by processes that explicitly share the segment identifier.
ftok() can be used to generate a key from a file and a project identifier.
size: The size of the shared memory segment in bytes. If the segment already exists and the size is greater than the existing size, it will be ignored. If the segment is being created, the size is used to allocate memory.

shmflg: A flag that controls the creation and access modes for the shared memory segment. Common flags include:

IPC_CREAT: Create the segment if it doesn’t exist.
IPC_EXCL: Used with IPC_CREAT to ensure that the call fails if the segment already exists.
0666: Permissions for read and write access, typically specified in octal format.
Return Value:
On success, it returns a shared memory identifier (a non-negative integer) that can be used in subsequent operations like shmat(), shmdt(), or shmctl().
On failure, it returns -1, and errno is set to indicate the error.

    */
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    
    

    if (shmid == -1) {
        perror("Error in shmget function");
        return 0;
    }

    /*
    void *shmat(int shmid, const void *shmaddr, int shmflg);
    shmid: The shared memory identifier, which is obtained from shmget(). This ID represents the shared memory segment you want to attach to your process.

shmaddr: A pointer specifying the address where the shared memory should be attached. If set to NULL, the operating system will choose an appropriate address.

shmflg: Flags that control the attachment behavior. Common flags include:

0: Default behavior, the memory will be attached as read-write.
SHM_RDONLY: Attach the shared memory as read-only.
SHM_RND: Round the shmaddr down to a multiple of the system page size.
Return Value:
On success, shmat() returns a pointer to the attached shared memory segment, which can be used to access the shared memory.
On failure, it returns (void *) -1, and errno is set to indicate the error.
    
    */
    shmaddress = shmat(shmid, NULL, 0);
    

    if ((shmaddress == (char *)-1)) {
        perror("Error in shmat function ");
        return 0;
    }
    
    
    
    char buff[SHM_SIZE];
    printf("Enter the text you want to write to shared memory\n");
    scanf("%[^\n]",buff);
    strcpy(shmaddress, buff);

    //detaching the sharedmemory
    if (shmdt(shmaddress) == -1) {
        perror("Error in shmdt function");
        return 0;
    }

    shmaddress = shmat(shmid, NULL, SHM_RDONLY);


    if (shmaddress == (char *)-1) {
        perror("Error in shmat function");
        return 0;
    }
    printf("Contents of shared memory: %s\n", shmaddress);
    
    
    //signal(SIGSEGV, handy);
    //printf("\nTrying to overwrite the shared memory\n");
    //strcpy(shmaddress, "This should not overwrite!"); 
    
    
    
    /*
    Detaching shared memory means that a process stops accessing the shared memory it had previously attached to. This does not remove or delete the shared memory; it just unmaps the memory region from the process's address space.

Function: shmdt(const void *shmaddr);
Purpose: To stop the current process from using the shared memory.
Effect: The shared memory remains available for other processes that have it attached, and it remains in the system until explicitly removed.
Usage: Every process that attaches to shared memory using shmat() should eventually call shmdt() to detach from it when done.



After calling shmdt(), the process can no longer access the memory pointed to by shm_ptr.
The shared memory segment itself is still available in the system for other processes.

When the processor does not need any memory anymore, just detach from the attached shared memory.

    
    */
    
    //detaching shared memory
    if (shmdt(shmaddress) == -1) {
        perror("Error in shmdt function");
        return 0;
    }
    printf("Shared memory detached\n");
    
    
    // removing shared memory
    /*
    Removing shared memory means deleting the shared memory segment from the system entirely. Once removed, the memory will no longer be accessible to any process, even if some processes are still attached to it.

Function: shmctl(int shmid, int cmd, struct shmid_ds *buf);
Purpose: To delete the shared memory segment from the system.
Effect: After calling shmctl(shmid, IPC_RMID), the shared memory is marked for deletion. It will be removed when no processes are attached to it. If a process is still attached, it remains attached until it detaches, and only then the segment is deleted.
Usage: Typically, this is called by the process that created the shared memory (though any process with permission can remove it).


    */
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error in shmctl function");
        return 0;
    }
    
    printf("Shared memory removed\n");
    

    return 0;
}
