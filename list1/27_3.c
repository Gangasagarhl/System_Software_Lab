/*
NAME: 27_3.C
AUTHOR: GANGASAGAR HL
DESCRIPTION:Write a program to execute ls -Rl by the following system calls
c.execle
*/

#include <unistd.h>
#include<stdio.h>

int main() {
  char *args[] = {"ls", "-Rh", NULL};
  char *envp[] = {"PATH=/bin:/usr/bin", NULL};
  
  printf("Using exele function call\n");
  int ret = execle("/bin/ls", args[0], args[1], NULL, envp);

  if (ret < 0) {
    perror("execle");
    return 1;
  }

  return 0;
}

