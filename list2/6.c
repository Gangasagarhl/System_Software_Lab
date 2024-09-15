/*
---------------------------------------------------------------------
NAME:6.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a simple program to create three threads.

DATE: SEP 12 2024
TIME: 5:10PM
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_num = *((int*)arg);
    printf("Created thread: %d\n", thread_num);
    return NULL;
}
/*
A thread is the smallest unit of execution that exists within a process and shares the same memory space, file descriptors, and other resources as the parent process 1 5 . Threads can execute a given piece of code, have their own stack, and can be part of a single-threaded process or a multi-threaded process.

Inside a thread, code execution, variables, and resources are managed independently within the thread's context, allowing for parallel or concurrent execution 6 10 . When a thread is called within a process, it allows for multiple units of work to be performed concurrently, enhancing the efficiency and speed of task execution within the application .

To create a thread, you typically use system calls such as clone or pthread_create.
Thread is nothing but a small process within the process.

pthread_create to create threads, pthread_join to synchronize threads, and pthread_exit to exit a thread.

*/

int main() {
    pthread_t thread1, thread2, thread3;
    /*
    
Structure, which is used to hold the identifier of the thread created, called when crreating and synchronising the thread.

Deatils: 
In POSIX systems like Linux, the pthread_t type is considered an opaque data type, meaning its internal structure and contents are not revealed or accessible to application programmers. The pthread_t type is used as a handle or identifier to refer to threads within a process, and its implementation details are hidden to maintain abstraction and portability across different systems.

While the actual structure of pthread_t is not defined in user-space code, it is typically a simple data structure or an integer type behind the scenes within the pthread library. Application developers interact with pthread_t through pthread functions like pthread_create, pthread_join, and others without needing to know the internal representation of pthread_t.

Therefore, from a practical standpoint, the structure of pthread_t is abstracted and not meant to be accessed or manipulated directly by programmers. Instead, it serves as a unique identifier for threads and is used in conjunction with pthread functions to manage multithreaded programming tasks effectively.

     It is an opaque data type used to uniquely identify threads within a process. The actual contents and structure of pthread_t are typically not meant to be accessed or manipulated directly by application code. Instead, it serves as a handle that can be used with various pthread functions to manage, control, and interact with threads.

When a new thread is created using pthread_create, the unique identifier for the newly created thread is stored in a variable of type pthread_t. This identifier can then be used to refer to the thread in subsequent pthread function calls such as pthread_join, pthread_detach, or pthread_cancel.

In simple terms, pthread_t is a data type that acts as a reference or identifier for threads within a process. It allows the application to manage and work with individual threads in a multi-threaded program. However, the specifics of its implementation and internal structure are typically hidden from the application programmer, who interacts with pthread_t through the provided pthread API functions.


 The pthread_t type in POSIX systems such as Linux represents a thread identifier. It is an opaque data type used to uniquely identify threads within a process. The actual contents and structure of pthread_t are typically not meant to be accessed or manipulated directly by application code. Instead, it serves as a handle that can be used with various pthread functions to manage, control, and interact with threads.

When a new thread is created using pthread_create, the unique identifier for the newly created thread is stored in a variable of type pthread_t. This identifier can then be used to refer to the thread in subsequent pthread function calls such as pthread_join, pthread_detach, or pthread_cancel.

In simple terms, pthread_t is a data type that acts as a reference or identifier for threads within a process. It allows the application to manage and work with individual threads in a multi-threaded program. However, the specifics of its implementation and internal structure are typically hidden from the application programmer, who interacts with pthread_t through the provided pthread API functions.  


    */
    
    
    int thread_num[3] = {1, 2, 3};
/*

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
   
   
   *pthread_t thread: This parameter is a pointer to a pthread_t variable that will store the thread identifier once the thread is created. You can use this identifier to manipulate the thread, such as joining or detaching it. After a successful pthread_create call, this variable will hold the unique identifier for the newly created thread.

*const pthread_attr_t attr: The pthread_attr_t structure is used to specify the attributes for the new thread being created. By passing a pointer to this structure, you can define various thread attributes like stack size, scheduling policy, and priority. If you pass NULL for this parameter, default attributes will be used for the new thread.

void *(*start_routine)(void *): This is a pointer to the function that will be executed by the newly created thread. The function should take a void * argument and return a void * pointer. The thread will start executing code from this function once created. Any arguments required by the function can be passed as arg.

*void arg: This parameter allows you to pass arguments to the start_routine function. You can pass a single argument (typically a pointer to a data structure) by casting it to a void * type. This argument will be accessible inside the start_routine function once the thread starts execution.

By using pthread_create with these parameters, you can create a new thread with specific attributes and execute a designated function in parallel with the main thread of your program. It's essential to manage the synchronization and communication between threads to ensure correct and efficient multithreaded behavior in your applications.
   

*/
    pthread_create(&thread1, NULL, thread_function, &thread_num[0]);
    pthread_create(&thread2, NULL, thread_function, &thread_num[1]);
    pthread_create(&thread3, NULL, thread_function, &thread_num[2]);


/*
int pthread_join(pthread_t thread, void **status)
*/
    pthread_join(thread1, NULL);
    
/* 
pthread_join();
is used to wait for a specific thread to terminate and obtain its exit status. 


thread: This parameter specifies the thread for which the calling thread will wait. When you call pthread_join, the function waits for the thread identified by the thread parameter to terminate.

status: This parameter is a pointer to a pointer. When pthread_join returns, the exit status of the target thread is stored in the location pointed to by status. This provides a way for the calling thread to obtain information about the termination status of the joined thread.

The pthread_join function allows for synchronization between threads. When a thread calls pthread_join on another thread, it effectively waits for the joined thread to finish its execution before continuing. This is commonly used to ensure that the main thread doesn't proceed beyond a certain point until specific worker threads have completed their tasks and terminated.

The exit status obtained via the status parameter typically contains information about how the joined thread terminated, such as an exit code or a specific value returned from the thread's entry point function.

In summary, pthread_join is a crucial function for coordinating the execution of multiple threads within a program and obtaining information about the termination status of individual threads.

*/
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
