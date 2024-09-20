/*
---------------------------------------------------------------------
NAME:32d.c
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
#include <semaphore.h>
#include <sys/sem.h>
sem_t semaphore;

int main() {
    int value;
    sem_init(&semaphore, 0, 1);
    /*
    int sem_getvalue(sem_t *sem, int *sval);

    function is used to obtain the current value of a semaphore. This can be useful for debugging or for checking the state of the semaphore without altering it.
    sem_t sem: A pointer to the semaphore whose value you want to retrieve.

*int sval: A pointer to an integer where the current value of the semaphore will be stored.

Return Value
On success, sem_getvalue() returns 0.
On failure, it returns a non-zero value and sets errno to indicate the error.
Behavior
The value retrieved reflects the number of available resources represented by the semaphore.
For a binary semaphore, the value will typically be 0 or 1.
For counting semaphores, the value may be any non-negative integer.
    
    */
    sem_getvalue(&semaphore, &value);
    

    printf("Semphore created successfully : %d\n",value);

    sem_destroy(&semaphore);

    printf("Semphore destroyed successfully : %d\n",value);


    return 0;
}


