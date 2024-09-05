/*
NAME: 27_4.C
AUTHOR:GANGSAGAR HL
DESCRIPTION: Write a program to execute ls -Rl by the following system calls
execv
*/

#include <unistd.h>
#include <stdio.h>

int main() {
  // Define the command to execute
  char *args[] = {"ls", "-Rl", NULL};

  // Execute the specified command with the given environment variables
  printf("Execv system call is used\n");
  int ret = execv("/bin/ls", args);

  // Check for errors in the execle call
  if (ret < 0) {
    perror("execv");
    return 1; // Return an error code
  }

  // The code will not reach this point if execle is successful

  return 0;
}
 
