/*
NAME : 27_1.C
AUTHOR: GANGASAGAR HL
DESCRIPTION: Write a program to execute ls -Rl by the following system calls
      a. execl
*/

#include <unistd.h>
#include <stdio.h>

int main() {
  char *args[] = {"ls", "-Rl", NULL};

//replace the current process image with a new process image. It is part of the exec family of functions that are used to execute a new program within the current process. Specifically, execl replaces the current process with a new process specified by the given path name. It loads and runs the new program, discarding the old program, and the control is never returned to the old program unless there is an error.
 printf("Using execl function call\n");
 int ret = execl("/bin/ls", args[0], args[1], NULL);
 printf("hello");
  if (ret < 0) {
    perror("execl");
    return 1;
  }

  return 0;
}

