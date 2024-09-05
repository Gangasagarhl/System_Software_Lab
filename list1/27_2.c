/*
NAME:27_2.C
AUTHOR: GANGASAGAR
DESCRIPTION: Write a program to execute ls -Rl by the following system calls
 b.execlp
*/

#include <unistd.h>
#include <stdio.h>

int main() {
  char *args[] = {"ls", "-Rl", NULL};
  
  printf("Using execlp function call\n");
  int ret = execlp("ls", args[0], args[1], NULL);
 printf("This is executed only if the previous command is failed\n");
  if (ret < 0) {
    perror("execl");
    return 1;
  }

  return 0;
}
