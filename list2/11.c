/*
---------------------------------------------------------------------
NAME:11.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

DATE: SEP 15 2024

---------------------------------------------------------------------
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

  struct sigaction sa;
  sa.sa_handler = SIG_IGN;
  sa.sa_flags = 0;
  
  
  if(sigaction(SIGINT,&sa,NULL)==-1){
  
    perror("Error while calling sigaction for SIGINT, SIG_IGNORE\n");
    exit(1);
  }
  printf("\nNow SIGINT is getting ignored check with CNTRL+C\nTill 10 secs from now, the signal SIGINT is ignored\n");
  sleep(10);
  
  
  // setting signal to set with default action of signal
  sa.sa_handler = SIG_DFL;
  if(sigaction(SIGINT,&sa,NULL)==-1){
  
    perror("Error while calling sigaction for SIGINT, with SIG_DFL\n");
    exit(1);
  }
  
  printf("\nNow Deafult action for SIGINT is restored\nCheck with cntrl+C\nRunning infinitley\n");
  while(1);
  
  
  
  

}
