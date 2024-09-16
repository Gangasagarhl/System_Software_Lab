/*
---------------------------------------------------------------------
NAME:16.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to send and receive data from parent to child vice versa. Use two way communication.
DATE: SEP 16 2024

---------------------------------------------------------------------
*/
/*
   1. Need to create 2 pipes.
   2. create 2 diffrent file descriptors 
   3. close the unused ends of the pipe for both the child and parent
   4. do write on one pipe in parent process and read from the same pipe.
   5. Do the same thing in child as well as parent.  

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h>

int main(void) 
{
    int ptc[2];        
    int ctp[2];          
    int r, w;
    char *writeBuf, *readBuf;
    pipe(ptc); 
    pipe(ctp); 
    int child = fork(); 
    if (child != 0) { 
            close(ptc[0]);
            close(ctp[1]);
            writeBuf = "Data from parent process\n";
            w = write(ptc[1], &writeBuf, sizeof(writeBuf)); 
            if(w == -1)
            	perror("Error while writing from parent to child");
            	
            r = read(ctp[0], &readBuf, sizeof(readBuf));
            
            if(r == -1)
            	perror("Error while reading from child to parent");
            else 
            	printf("This parent read: %s\n", readBuf);
        } 
        
        else { 
            /* child */ 
            close(ptc[1]);
            close(ctp[0]);
            
            writeBuf = "Data from child process\n";
            w = write(ctp[1], &writeBuf, sizeof(writeBuf));
            
            if(w == -1)
            	perror("Error while writing to child to parent");
            
            r = read(ptc[0], &readBuf, sizeof(readBuf));
            if(r == -1)
            	perror("Error while reading from parent to child");
            
            else
            	printf("The child read : %s\n", readBuf);
      }
} 

