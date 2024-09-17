/*
---------------------------------------------------------------------
NAME:18.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION: Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
DATE: SEP 17 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void) {
	int p1[2], p2[2];
	pid_t childp1, childp2;
	
	// now creating pipe for maing communications
	int status1 = pipe(p1);// pipe 1
	int status2 = pipe(p2);// pipe2
	printf("\nUsed to print NUmber of directoies at the  first part of the sentence\n#lines \t # words \t #characters\n(#directories)");
	/*
	
	
	 When the pipe() function is successful in creating a pipe, it returns 0. This indicates that the pipe was created successfully.

In the case of failure, the pipe() function returns -1, indicating that the pipe creation has failed. When pipe() returns -1, the reason for the failure can be determined by examining the errno variable, which is set to the specific error code indicating the nature of the failure. Common error codes for pipe() function failures include EMFILE (reached the limit on the number of file descriptors open in the calling process), EFAULT (bad address), ENFILE (system file table is full), or ENOMEM (out of memory).

Developers normally handle the failure of pipe() by checking the return value and then examining errno to determine the specific reason for the failure, allowing them to respond appropriately to the error condition.

	*/
	
	
/*
   Steps:
     1. Assessment: Need to execute 3 commands, ls -l, gred ^d(starting with d), wc.
     2. Requirements: 
     	a. If I'm going to use 2 different forks, I can create 4 process, which are sufficent for me to execute the commands in pipe. 
     	b. Create a child from the parent process, and within the parent create another chid, but the child created earlier should wait for the execution from the other processes.
     	c. Make 2 different pipes in line.
     	d. Finally I need 2 pipes, because pipe cant store the memory, so bothe has to be inline. 
     	
     3.  ls -l  will be written on the pipe1 write end, which has to piped with the last process created. So need to close the ends, 3 , pipe1 read,  pipe2 write and read. Finally need to close STDIN_FILENO. Now I'm  executing the execv, with ""ls-l""
     4. child 2 will get the data from the from the read end of the pipe, by making it as the input end, not output.Now need to close the write end of the pipe 1, read end of pipe 2, close the read and write of the std. Write to the pipe2 with the ""grep ^d"" command.
     
     
     5. Finally read the content at the child 1, and at pipe, and hence writing on stdout on the terminal. ""wc". 
     
     Hence 

*/
	
	if(status1 == -1 || status2 == -1)// if the returned 
		perror("Pipe not created");
	
	else {
		childp1 = fork();
		
		if(childp1 == -1)
			perror("Child not created");
		
		else if(childp1 == 0) {
			close(p1[0]);
			close(p1[1]);
			close(p2[1]);
			
			close(STDIN_FILENO);
			dup2(p2[0], STDIN_FILENO);
			
			execl("/usr/bin/wc", "wc", NULL);
		}
		
		else {
			childp2 = fork();
			
			if(childp2 == -1)
				perror("Child not created");
			
			else if(childp2 == 0) {
				close(p1[1]);
				close(p2[0]);
				
				close(STDIN_FILENO);
				dup2(p1[0], STDIN_FILENO);
				close(STDOUT_FILENO);
				dup2(p2[1], STDOUT_FILENO);
				
				execl("/usr/bin/grep", "grep ^d", "^d", NULL);
			}
			
			else {
				close(p1[0]);
				close(p2[1]);
				close(p2[0]);
				
				close(STDOUT_FILENO);
				dup2(p1[1], STDOUT_FILENO);
				
				execl("/usr/bin/ls", "ls", "-l", "-l", NULL);
			}
		}
	}
}
