/*
---------------------------------------------------------------------
NAME:2.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:  Write a program to print the system resource limits. Use getrlimit system call.

DATE: SEP 12 2024
TIME: 11:15PM
---------------------------------------------------------------------
*/

#include <stdio.h>// perror, printf 
#include <sys/resource.h>//getrlimit() struct rlimit


/*
  These limits can help prevent a process from using too many resources on the system. 
  
  Soft - limit: 
  A processor can lower or higher the softlimit, so when the limits are exceeded, SIGXCPU is sginalled we can handle the signal.
  This is more like a warning, but not the end, or resource totally utilised.
  Normal user can increase the limits , even super user.
  
  Hard - limit: This can only be reduced, cannot be increased
  Only super user can increase the limits, not avaialbel to the normal user
  xceeding this , operations becomes invalidated,  may call sigkill, eagain, enomem can be set based on the condition it has violated
  
*/
void limits(int resource, const char *name) {
    struct rlimit rlim;// this is structure under which the values of limits are stored after calling getrlimit

    if (getrlimit(resource, &rlim) == 0) {
        printf("%s soft limit = %lld, hard limit = %lld\n",
               name, (long long)rlim.rlim_cur, (long long)rlim.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    limits(RLIMIT_CPU, "RLIMIT_CPU");/*
    This is a limit, in seconds, on the amount of CPU time  that  the  process      can  consume.  When the process reaches the soft limit, it is sent a SIGX‐ CPU signal.  The default action  for  this  signal  is  to  terminate  the          process.   However,  the  signal can be caught, and the handler can return          control to the main program.  If the  process  continues  to  consume  CPU time,  it  will  be  sent  SIGXCPU once per second until the hard limit is
reached, at which time it is sent SIGKILL. 
    */
    limits(RLIMIT_FSIZE, "RLIMIT_FSIZE");
    /*
     This is the maximum size in bytes of files that the  process  may  create. SIGXFZS
    */
    limits(RLIMIT_STACK, "RLIMIT_STACK");
    limits(RLIMIT_DATA, "RLIMIT_DATA");
    limits(RLIMIT_NOFILE, "RLIMIT_NOFILE");
    limits(RLIMIT_MSGQUEUE, "RLIMIT_MSGQUEUE");
    /*
    This is a limit on the number of bytes that can  be  allocated  for  POSIX
              message queues for the real user ID of the calling process
    */
   
    

    return 0;
}

