/*
+++++++++++++++++
NAME: 24.C
AUTHOR: GANGASAGAR HL
DESCRIPTION: Write a program to create an orphan process.
DATE: AUG 29
++++++++++++++++
*/

#include<stdio.h>//printf
#include<unistd.h> //fork(), getpid(), sleep()
#include<stdlib.h>


int main(){
  int pid  = fork();
  int status;
  if(pid==0){
    printf("Child Process Running\n");
    printf("CHILD PID : %d\n",getpid());
    printf("Child Became Orphan\n");
    sleep(20);
    
    //system(" ps -e -o pid,ppid,stat,cmd | awk '$2 == 1 && $3 == \"Z\"' ");
  }
  else{
    printf("Parent Process Running\n");
    printf("Parent Process exit\n");
    //waitpid(pid,&status,0);
    exit(0);
  }
  return 0;
}
