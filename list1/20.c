/*
===================================================================================
NAME: 20.C
AUTHOR: GANGASAGAR HL
DESCRIPTION: Find out the priority of your running program. Modify the priority with nice command.
===================================================================================
*/

#include<sys/resource.h> // functions and macros for resource usage, including setting and getting the process priority (nice value).
#include<unistd.h>//has getpid(), pid_t, nice()
#include<stdio.h>//input ouput functions


int main(){

     int current_priority = getpriority(PRIO_PROCESS, getpid());
/*The value which is one of PRIO_PROCESS, PRIO_PGRP, or PRIO_USER, and who  is  in‐
       terpreted relative to which (a process identifier for PRIO_PROCESS, process group
       identifier for PRIO_PGRP, and a user ID for PRIO_USER).*/
     
     if( current_priority ==-1){
     printf("error\n");
     return 0;
     }
     
     //The returned value from getpriority() is considered the nice value because, in Unix-like systems, the priority of a process is determined by its nice value. The nice value directly influences the process's priority, with higher nice values corresponding to lower priority (less CPU time).
     
     //nice value varies from -20(most expensive) to 19(leat expensive)
     
     printf("Current priority is(nice): %d\n",current_priority);
     int n1 = nice(3);//i'm increasing the priority value of the process'
     int n2 = nice(5);//increasing the nice value again
     printf("Updated priority(nice): %d\n",n2); 
     
     int priority1 = getpriority(PRIO_PROCESS, getpid());
     if(priority1==-1){
     printf("Error while accessing");
     return 0;
     }
     
     printf("Rechecked priority(nice):%d\n",priority1);
     while(1);// running continuosly
     return 0;
}
