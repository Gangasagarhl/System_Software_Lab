/*
---------------------------------------------------------------------
NAME:32b.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048

DESCRIPTION: Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore


DATE: SEP 20 2024
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define SHM_KEY 1234
#define SHM_SIZE 100

int shmid;
char *shm_ptr;
sem_t mutex;

void* writeToSharedMemory(void* arg) {
    char* message = (char*)arg;
    //sleep(1);
    sem_wait(&mutex); // Wait for the semaphore

    // Write data to the shared memory
    strcpy(shm_ptr, message);

    sem_post(&mutex); // Release the semaphore

    pthread_exit(NULL);
    /*
    
    void retval: This parameter is a pointer that can be used to return a value to the thread that joins with this thread. If you don’t need to return any specific value, you can pass NULL.
Key Points
Thread Termination: When pthread_exit() is called, the calling thread will terminate its execution immediately. Any resources allocated to that thread (like thread-local storage) are released.

Return Value: The value passed to pthread_exit() can be retrieved by another thread that calls pthread_join() on the terminating thread. This is useful for returning results from threads.

Not Affecting Other Threads: Calling pthread_exit() only affects the calling thread. Other threads in the same process continue to run unaffected.

Detaching Threads: If a thread is created in a detached state (using pthread_detach()), it cannot be joined, and any exit value will be lost since there’s no other thread to retrieve it.
    */
}

int main() {
    // Create a shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    //NULL gives freedom to OS to handle everything in terms of shared memory
    shm_ptr = shmat(shmid, NULL, 0);
    
    

    if (shm_ptr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Initialize the semaphore
    sem_init(&mutex, 0, 1);

    // Create threads to write to shared memory
    pthread_t thread1, thread2;
    char* message1 = "Message from Thread 1";
    char* message2 = "Message from Thread 2";

    pthread_create(&thread2, NULL, writeToSharedMemory, (void*)message1);
    printf("Content of shared memory: %s\n", shm_ptr);

    pthread_create(&thread1, NULL, writeToSharedMemory, (void*)message2);
    printf("Content of shared memory: %s\n", shm_ptr);

    // When pthread_exit is called, it terminate by itself by releasing all the components held, But it has option to return the value to it where it is joined,
    
    //so now master can make hold of it. 
    pthread_join(thread2, NULL);
    pthread_join(thread1, NULL);

    // Print the content of the shared memory
    printf("Content of shared memory: %s\n", shm_ptr);

    // Detach the shared memory
    shmdt(shm_ptr);

    return 0;
}

/*

When you giving slepp inside, let the other thread to execute by sleeping yourself. 
Otherwise the thiread will keeep on executing the function passed till teh other thread created. 
, so once the mutex is held by the second thread then it will keep one executing, since the other one will be in watin state.
When thread 2 is waiting for a resource that is currently held by thread 1, it is not considered "sleeping" in the typical sense, but rather it is blocked or waiting for the resource to become available.

*/
