/*
----------------------------------------------------------------------------
NAME: 21.c
AUTHOR: GANGASAGAR HL
PROBLEM STATEMENT: Write a program, call fork and print the parent and child process id.
----------------------------------------------------------------------------
*/

#include<stdio.h>//normla io operations
#include<unistd.h>// fork command, pid_t 

int main(){
   
   pid_t pid = fork();// from here 2 process runs in parallel
   // so the one with the pid ==0, is the child process, whose pid is printed with the help of getpid()
   // else the parent process id is printed.
   
   if(pid == 0){
      printf("The child process id is: %d\n", getpid());
   }else{
      printf("The parent process id is: %d\n",getpid());
   }
   
   return 0;

}


