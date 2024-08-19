/*
NAME: GANGASAGAR HL
ROLL NUMBER: MT2024048

STATEMENT: PROGRAM TO TAKE INPUT FROM STDIN AND DISPLAY ON STDOUT , using read write calls

*/

//perror and some basic input outpur function
#include<stdio.h>
//This is used for read and write system calls, STDIN_FILENO, STDOUT_FILENO
#include<unistd.h>
//exit function and as well as flag
#include<stdlib.h>


void call()
{
	char hlgs_buff[1024];
	ssize_t hlgs_bytesRead;//This is used to store the number of bytes.
	//ssize_t  it is unsigned
	
	//READING INPUT THRIUGH CONSOLE and stroing it in buffer
	if((hlgs_bytesRead = read(STDIN_FILENO, hlgs_buff,1024))>0){
	//WRITING THE OUTPUT AGAIN INTO THE STDOUT
	    if(write(STDOUT_FILENO,hlgs_buff,hlgs_bytesRead)!= hlgs_bytesRead){
	 
		perror("Write error: ");
		exit(EXIT_FAILURE);
	}
	
	}
	
	if(hlgs_bytesRead==-1){
	perror("Read Error: ");
	exit(EXIT_FAILURE);
	}
}



void main(){

printf("\nThis takes a input from  user in standard input and produces the ouput, it can also be modified to take infinte length string \n \nNow Type the input, you want to see in the output:\n\nBegin:\n\n");
call();
}


