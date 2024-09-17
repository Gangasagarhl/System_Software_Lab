/*
---------------------------------------------------------------------
NAME:17.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to execute ls -l | wc.
b. use dup2
DATE: SEP 17 2024

---------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];

    pipe(pipe_fd);

    if (fork() == 0) {
        close(pipe_fd[0]); // Close read end

        dup2(pipe_fd[1], STDOUT_FILENO); 
        // STDOUT_FILENO , that refers to the file descriptor for standard output (stdout). It is defined in the header file <unistd.h>, and its value is always 1.
        // Redirect stdout to pipe write end
        close(pipe_fd[1]); // Close the duplicated file descriptor

        execlp("ls", "ls", "-l", NULL); // Execute ls -l
        
        /*
        The  char *const argv[] argument is an array of pointers to null-termi‐
       nated strings that represent the argument list  available  to  the  new
       program.   The first argument, by convention, should point to the file‐
       name associated with the file being executed.  The  array  of  pointers
       must be terminated by a null pointer.

        */
    } else {
        close(pipe_fd[1]); // Close write end

        dup2(pipe_fd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        /*
        The dup2 system call in UNIX-like operating systems is used to duplicate a file descriptor. Here is a brief explanation of the dup2 system call:

Functionality: dup2 duplicates an existing file descriptor (given as the first argument) to another file descriptor number (specified by the second argument).

File Descriptor Duplication: If the target file descriptor number is already open, dup2 closes it before duplicating the source file descriptor to the target number.

Error Handling: In case of failure, dup2 returns -1 and sets the appropriate error code in errno.

Use Case: It is commonly used to atomically implement input/output redirection, such as redirecting standard input or output to a file.

Atomic Operation: Unlike the dup system call, dup2 allows for an atomic and controlled duplication of file descriptors, reducing the risk of race conditions in concurrent environments.

Return Value: Upon successful duplication, dup2 returns the new file descriptor number (which is the same as the second argument).

Efficient Resource Management: dup2 facilitates efficient resource sharing and management within an application or process.

Support for Custom File Descriptors: It provides the flexibility to duplicate file descriptors onto custom file descriptor numbers.

C Standard Library Support: The dup2 system call is available as a low-level system call and is often used in conjunction with higher-level functions in the C standard library.

Operating System Support: dup2 is a fundamental system call and is supported across various UNIX-like operating systems, providing a standardized mechanism for file descriptor duplication and management.
        */
        close(pipe_fd[0]); // Close the duplicated file descriptor

        execlp("wc", "wc", NULL); // Execute wc
        
    }

    return 0;
}

