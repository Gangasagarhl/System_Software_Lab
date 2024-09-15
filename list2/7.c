/*
---------------------------------------------------------------------
NAME:7.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a simple program to print the created thread ids.

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
/*
When pthread_self() is called within a thread, it returns a unique identifier that represents the calling thread. This identifier allows the program to distinguish and work with different threads within the same process. The returned value of type pthread_t can be used to perform various operations related to the calling thread, such as comparing thread IDs, passing the ID to other thread-related functions, and so on.

Internally, the pthread_self() function accesses thread-specific information maintained by the threading system to retrieve and return the ID of the current thread. This thread-specific information allows the function to accurately identify the calling thread and provide the necessary identifier.
*/
    pthread_t tid = pthread_self(); // Get the thread ID
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_create(&thread3, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
