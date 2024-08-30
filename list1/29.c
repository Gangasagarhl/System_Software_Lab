/*
NAME: 29.C
AUTHOR: GANGASAGAR HL
DESCRIPTION:Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include <sched.h>
#include <stdio.h>
#include <stdlib.h> // Include the necessary header for 'exit' function
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Get the process ID and scheduling policy
    pid_t pid = getpid();
    int sched = sched_getscheduler(pid);
    struct sched_param shd;
    int ret ;
    
    // Determine and print the scheduling policy
    switch (sched) {
        case SCHED_FIFO:
            printf("FIFO scheduling is implemented\n");
            printf("Converting from FIFO scheduling to  RR\n");
            
               // Set the scheduling policy to SCHED_FIFO with a priority of 10
	    
	    shd.sched_priority = 11;
	    ret = sched_setscheduler(pid, SCHED_RR, &shd);

	    if (ret == -1) {
	        perror("Error setting scheduling policy");
	        exit(EXIT_FAILURE);
	    }
            
            break;
        
        case SCHED_RR:
            printf("Round Robin scheduling is implemented\n");
            printf("Changing from RR to FIFO schedule\n");
            
            
    	shd.sched_priority = 10;
    	ret = sched_setscheduler(pid, SCHED_FIFO, &shd);

    	if (ret == -1) {
        	perror("Error setting scheduling policy");
        	exit(EXIT_FAILURE);
             }
            break;
        
        case SCHED_OTHER:
            printf("Other scheduling is implemented\n");
            printf("Converting  to  RR\n");
            // Set the scheduling policy to SCHED_FIFO with a priority of 10
	    
	    shd.sched_priority = 11;
	    ret = sched_setscheduler(pid, SCHED_RR, &shd);

	    if (ret == -1) {
	        perror("Error setting scheduling policy");
	        exit(EXIT_FAILURE);
	    }
	    
            break;
        
        default:
            printf("Unknown scheduling policy\n");
            break;
    }

 
    sched = sched_getscheduler(pid);

    // Determine and print the scheduling policy
    switch (sched) {
        case SCHED_FIFO:
            printf("updated with FIFO scheduling\n");
            break;
        
        case SCHED_RR:
            printf("updated with Round Robin scheduling\n");
            break;
        
        case SCHED_OTHER:
            printf("updated with Other scheduling\n");
            break;
        
        default:
            printf("Unknown scheduling policy\n");
            break;
    }

    return 0;
}
