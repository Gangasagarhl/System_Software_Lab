/*
NAME: 
AUTHOR:GANGASAGAR HL
ROLL NUMBER: MT2024048

PROBLEM STATEMENT: PROGRAM TO OPEN A FILE IN READ MODE AND READ LINE BY LINE AND DISPLAY IT LINE BY LINE, STOP WHEN END OF THE FIE REACHED

steps:
1. I'll create a file named input.txt and enter something into it.
2. With the help of open system call read it and print the content of it on the terminal

DATE: AUG 22 2024
*/
#include<stdio.h>//io
#include<unistd.h>//open,write
#include<fcntl.h>//flags to open the file O_RDONLY
#include<stdlib.h>//exit and exit_failure


int main(int argc, char* ar[]){

 int hlgs_fd,hlgs_nb;
 char hlgs_c;
 if(argc!=2){
 printf("\nThe input in command should be like ./programname file_name\n");
 exit(EXIT_FAILURE);
 }
 
 hlgs_fd = open(ar[1],O_RDONLY);
 if(hlgs_fd==-1){
 perror("Opening Error:\n");
 exit(EXIT_FAILURE);
 
 }
 
 while(10){
 	//reading the content byte by byte
 	hlgs_nb= read(hlgs_fd,&hlgs_c,1);
 	
 	//checking whetehte the reading of the file has reached the end or not.
 	if(hlgs_nb==0){
 	printf("\n\nAll the contents of teh file is already on the output terminal.\nThank you.\n");
 	
 	break;
 	
 	}
 	//1-STDOUT standard file descriptor, but can be used to some flag STDOUT_FILENO
 	write(1,&hlgs_c,1);
 	 
 }
 
 return 1;
 
}



