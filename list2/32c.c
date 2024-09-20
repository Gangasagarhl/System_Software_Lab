/*
---------------------------------------------------------------------
NAME:32c.c
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
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>

#define NUM_RESOURCES 2

// number of resources are defined as 2, arra
int resource[NUM_RESOURCES];// creating array with the 2 elements in it
sem_t semaphore; //  se

void* useResource(void* arg) {
    int resource_id = *(int*)arg;

    sem_wait(&semaphore); // Wait for a resource to be available
    
    // Access and use resource
    printf("Using resource %d.\n", resource_id);
    sleep(1);
    resource[resource_id] = 0;

    sem_post(&semaphore); // Release the resource

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_RESOURCES];

    sem_init(&semaphore, 0, NUM_RESOURCES);//dealing with counting semaphores

    for (int i = 0; i < NUM_RESOURCES; ++i) {
        resource[i] = 1; // Resource is initially available
        pthread_create(&threads[i], NULL, useResource, (void*)&i);
    }

    for (int i = 0; i < NUM_RESOURCES; ++i) {
        pthread_join(threads[i], NULL);//  By calling this we are waing for the threads to execute, and it has capacity to get the contnt from the thread and can handle the way we want
    }

    sem_destroy(&semaphore);// finally destroying the counting semaphore.

    return 0;
}
/*

 Here the resources are created, and in the same amount the number of semaphores are created. 
 So first we are making the resource availble , bu assigning the contents of the array to 1.
 Later we are changing the contents of the array, to 0.
 sleep for 2 seconds inside thread to demonstracte the counting semaphore, however only one thread is allowed to its contents hence we are protecting , this is just used for implementations of counting semaphore 

*/


