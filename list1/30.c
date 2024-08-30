/*
=======================================
NAME: 30.C
AUTHOR: GANGASAGAR HL
DESCRIPTION:Write a program to run a script at a specific time using a Daemon process.
=======================================
*/

#include <time.h>  //time(),localtime,mktime all the time related activities   
#include <stdio.h> //printf and scanf related input output  
#include <stdlib.h>    //exit functio
#include <sys/stat.h> 
#include <sys/types.h> // I tries to remove, but got some warnings, so included
#include <unistd.h> //fork, pid  
 

void main(int argc, char *argv[])
{
    time_t now, specific_time; 
    struct tm *deadline; //the tructure has the infomation regarding hours, minutes and seconds                
    
        int hrs,min,sec;
        
        printf("Please enter in 24hs format:\n");
        printf("\nEnter the hours: ");
        scanf("%d",&hrs);
        printf("\nEnter the minutes: ");
        scanf("%d",&min);
        printf("\nEnter the seconds: ");
        scanf("%d",&sec);
        
        time(&now); 
        deadline = localtime(&now);
        deadline->tm_hour = hrs;
        deadline->tm_min = argv[2] == NULL ? 0 : min;
        deadline->tm_sec = argv[3] == NULL ? 0 : sec;
        specific_time = mktime(deadline); // 
        if (!fork()) 
        {
            setsid();
            chdir("/");
            umask(0);
            do
            {
                time(&now);
            } while (difftime(specific_time, now) > 0);
            printf("TIME UP\n");
            //system("ll");
            printf("\nTILL NOW DAEMON WAS WORKING AS AN ORPHAN \nNOW IT WILL EXIT\n");
            exit(0);
        }
        exit(0);
    }

