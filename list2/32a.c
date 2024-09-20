/*
---------------------------------------------------------------------
NAME:32a.c
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
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_TICKETS 5

int ticket_counter = 1;
sem_t mutex;

void* sellTicket(void* arg) {
    int *w = (int *)arg;
    int who = *w;
    while (1) {
        sem_wait(&mutex); // Wait for the semaphore
        if (ticket_counter <= NUM_TICKETS) {
            
            printf("Ticket %d sold by %d.\n", ticket_counter,who);
            ticket_counter++;
        }
        sem_post(&mutex); // Release the semaphore
        sleep(1);// made sleep make the lock acquired by both s
        if (ticket_counter > NUM_TICKETS) break;
    }

    pthread_exit(NULL);
}

int main() {
    //creating the threads to make concurrent process to acces the contents of ticket and trying to access/modify it
    pthread_t seller1, seller2;
 
 
    // initialisng binary semaphore
    sem_init(&mutex, 0, 1);

    
    /*
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

pthread_t *thread: A pointer to a pthread_t type, which is used to store the identifier of the newly created thread.

const pthread_attr_t *attr: A pointer to a thread attribute object (optional). You can pass NULL to use default attributes. Attributes control various properties of the thread, such as stack size and scheduling behavior.

void *(*start_routine)(void *): A pointer to the function that the new thread will execute. This function should accept a single argument of type void * and return a value of type void *. This is the "entry point" for the new thread.

void *arg: A pointer to an argument passed to the thread function. If no argument is needed, you can pass NULL.

Return Value
On success, pthread_create() returns 0.
On failure, it returns a non-zero error code.
    
    */
    int a =1,b=2;
    pthread_create(&seller1, NULL, sellTicket, (void *)&a);
    pthread_create(&seller2, NULL, sellTicket, (void *)&b);

/*
pthread_t thread: Declares a thread identifier of type pthread_t which will hold the ID of the newly created thread.

pthread_create():

&thread: A pointer to the thread ID variable.
NULL: No special thread attributes are specified, so the default attributes are used.
print_message: The function that the new thread will execute.
message: A pointer to the string "Hello, Thread!" that will be passed as an argument to the print_message() function.
pthread_join(): This function blocks the calling thread (main thread in this case) until the specified thread terminates, ensuring the main thread waits for the new thread to finish execution before continuing.

int pthread_join(pthread_t thread, void **retval);
pthread_t thread: The ID of the thread you want to wait for. This ID is typically obtained when you create the thread using pthread_create().

**void retval: A pointer to a pointer where the exit status of the thread will be stored. This allows the calling thread to retrieve the return value of the thread that has terminated. If you do not need the return value, you can pass NULL.


On success, pthread_join() returns 0.
On failure, it returns a non-zero error code (e.g., ESRCH if no thread with the specified ID exists, or EINVAL if the thread is not joinable).
*/
    
    pthread_join(seller1, NULL);
    pthread_join(seller2, NULL);


    sem_destroy(&mutex);

    return 0;
}
