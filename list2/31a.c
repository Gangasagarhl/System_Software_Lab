/*
---------------------------------------------------------------------
NAME:31a.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to create a semaphore and initialize value to the semaphore.
b.create a counting semaphore
DATE: SEP 20 2024
---------------------------------------------------------------------
*/
#include<stdio.h>
#include<semaphore.h>
int main() {
    sem_t binary_semaphore;
    /*
    The structure of the semaphore is opaque by nature. Not allowed for a user to modeify the operations to it. 
    sem_t sem;
    
    Functions: 
    1. sem_init: initisase the semaphore, sem_init(&sem,0,1)
    2. sem_wait: Decrements (locks) the semaphore. If the semaphore's value is greater than zero, it decrements the value and continues. If the value is zero, it blocks until the semaphore becomes available.
    sem_wait(&sem);
    
    
    3. sem_post: Increments (unlocks) the semaphore, allowing other threads to proceed if they were blocked.
    sem_post(&sem);
    
    4. sem_destroy:  Destroys the semaphore once it is no longer needed, freeing any resources associated with it.
    sem_destroy(&sem);
    
    5. sem_trywait:
Similar to sem_wait, but does not block if the semaphore is already at zero. Instead, it returns an error.
    
     
   
    
    */
    
    sem_init(&binary_semaphore, 0, 1);

    printf("Binary semaphore created and initialized.\n");

    sem_destroy(&binary_semaphore);
    printf("Deleted binary semaphore\n");

    return 0;
}
