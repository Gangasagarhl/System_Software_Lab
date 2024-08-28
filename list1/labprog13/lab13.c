/*
=====================
ROLL NO: MT2024048
NAME:GANGASAGAR HL

ECERCISE:  Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).


Date and time:  August 28th, 10:30am

=====================

*/

#include<stdio.h>//printf,scanf function
#include<stdlib.h>//exit unction
#include<sys/select.h>//calls select functions

int main(){
   fd_set readfds;//only things they have asked for STDIN
   struct timeval timeout; //the 5th parameter to be given 
   int retu=0;//to hold the return of select
   
   
   
   timeout.tv_sec=10;//in seconds
   timeout.tv_usec = 0; // in micro seconds
   
   FD_ZERO(&readfds);// clears all the thing in readfds
   FD_SET(0,&readfds);//setting readfds to 0
   
   
   

   //select(max(filedesc)+1,fd_set readfds,fd_set writefds,fd_set exceptfds,timeval timeout), 
   //it waits till, atleast one of fds is set untill time val given, returns 0 if nothing is set.
   
   retu = select(1,&readfds,NULL,NULL,&timeout);
   //printf("\nretu: %d\n", retu);
   
   //without pressing enter it will not take the input from STDIN.
   
   if(retu)printf("\n\nData is available within 10 seconds\n");
   else printf("\n\nData Is not avaialble within 10 seconds\n");
   
return 0;
}
