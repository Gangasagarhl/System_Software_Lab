/*
---------------------------------------------------------------------
NAME:31b.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to create a semaphore and initialize value to the semaphore.
a. create a counting semaphore
DATE: SEP 20 2024
---------------------------------------------------------------------
*/


#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t counting_semaphore;

  
/*
    int sem_init(sem_t *sem, int pshared, unsigned int value);
    
    sem_t *sem: A pointer to the semaphore object that you want to initialize. The sem_t type is typically defined in semaphore.h.

int pshared: This parameter determines whether the semaphore is shared between processes or just between threads of a process.

If pshared = 0, the semaphore is shared between threads of the same process.
If pshared = 1, the semaphore is shared between processes (if the semaphore is located in a shared memory segment).
unsigned int value: The initial value of the semaphore. This is the number of units available.

For a binary semaphore (like a mutex), value is often 1.
For a counting semaphore, value can be greater than 1 to represent the number of available resources.
    */
    
      sem_init(&counting_semaphore, 0, 5);

    printf("Counting semaphore created and initialized.\n");

    sem_destroy(&counting_semaphore);
    printf("Counting semaphore destroyed\n");

    return 0;
}

