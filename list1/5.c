/*
NAME: 5.C
AUTHOR:GANGASAGAR HL


Statement:  Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
 steps:
 1. Opened the series of 5 files with the help of the O_CREAT|O_RDONLY etc 
 2. With the help of loops, printerd the information
 3. Thence by oepning the file descriptor folder in the processorr, the rest things can be seen/ required oputput

DATE: AUG 18 2024
*/

#include<stdio.h>//basic io
#include<stdlib.h>//exit function and as well as the exi_failure status
#include<fcntl.h>// without this the flags given would not work. 
#include<unistd.h>//

void execute(){
	int hlgs_fds[5],hlgs_i=0;
	char hlgs_filename[5][100]={"textfiles/5/file1.txt","textfiles/5/file2.txt","textfiles/5/file3.txt","textfiles/5/file4.txt","textfiles/5/file5.txt"};
	printf("\nThe process id of the running process: %d\n", getpid());
	//Now opening the file in readwrite mode, 
	for(hlgs_i=0;hlgs_i<5;hlgs_i++)
	    hlgs_fds[hlgs_i] = open(hlgs_filename[hlgs_i],O_RDWR|O_CREAT,0777);
	    
	
	for(hlgs_i=0;hlgs_i<5;hlgs_i++)
	    if(hlgs_fds[hlgs_i] == -1){
	    perror("There is error in opening the files:");
	    exit(EXIT_FAILURE);
	    }
	    else{
	    
	    printf("The  File descriptor of %s is %d\n",hlgs_filename[hlgs_i],hlgs_fds[hlgs_i]);
	    }
	printf("\nNow running infinite loop, you can now check /proc/pid/fd\n");   	
	while(10);
}
void main(){
execute();
}
