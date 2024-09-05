/*
NAME: 19.C
AUTHOR: GANGASAGAR HL
STATEMENT: Write a program to find out time taken to execute getpid system call. Use time stamp counter.

DATE AND TIME: AUG 29 2024, 8:10AM
*/

#include<stdio.h>//io functions
#include<sys/types.h>// pid_t data type
#include<unistd.h>//getpid() - returns in pid_t
#include<time.h>// clock(),clock_t, mainly used for manipultaing date and time

int main(){

   clock_t hlgs_time,hlgs_time1;
   // an approximation of processor time used by the program.
   /*
   The value returned is the CPU time used so far as a clock_t; to get the
       number  of  seconds  used,  divide by CLOCKS_PER_SEC.  If the processor
       time used is not available or its  value  cannot  be  represented,  the
       function returns the value (clock_t) -1.
   */
   
   hlgs_time = clock();
   pid_t pid = getpid();//returning pid of the process
   hlgs_time1 = clock();
   
   double start = (double)hlgs_time/CLOCKS_PER_SEC;
   printf("Started time is %f\n",start);
   
   
   double end = (double)hlgs_time1/CLOCKS_PER_SEC;
   printf("Ended time is : %f\n",end);
   double f = end-start;
   printf("Total Time Taken is %f\n",f);
   return 0;
   
}
