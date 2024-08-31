/*
NAME : 1C.c
AUTHOR: GANGASAGAR HL


OBJECTIVE: Create fifo file using mkfifo library or mknod system call
*/

/*
When I tried creatng fifo file using mkfifo in command line:
Use 2 different terminals or process(official way)

1. to push the content to the fifo file
2. To retrive the value entered in the fifo file.

if you follow 1 -> 2: 
	First create the fifo file, enter into the fifio file using echo
	Ex: echo "string">>fifo_file

	Then it is not closed by deafult, till it is read from other process.
	When you open other terminal, and read the content of the fifo file,
	It will be closed. 
	cat fifo file name
	
2->1:
	The 2nd processor keep waiting for the input from the processor. 
	1 st processor nor enters the value to teh craeted fifo_file
	after enter in 1st process,
	The contents in the file are openened, and make according to the command
	automatically the opened will be closed. 
	
    
DATE: 10TH AUGUST 2024
	
*/

//including all the necessary header files
#include<stdio.h>//normal input and output functions
#include<fcntl.h>//used to control teh file, some necessary information
#include<sys/stat.h>// this has mknod and mkfifo calls in it
#include<unistd.h> //This necessary when creating files in c program , uses system calls and requires definitons of various data types and constants
#include<sys/types.h>// many macros defined in it will be useful in creating files
#include<stdlib.h> // this include exit function

void fifo_mkfifo(){

	const char *hlgs_fifo_name = "textfiles/fifo_mkfifo_1";
	if(mkfifo(hlgs_fifo_name,0666)==-1){
	
	perror("mkfifo:");
	exit(EXIT_FAILURE);
	
	}
	
}
void fifo_mknod(){

	const char *hlgs_fifo_name = "textfiles/fifo_mknod_1";
	if(mknod(hlgs_fifo_name, S_IFIFO|0666, 0)==-1){
	
	perror("mknod:");
	exit(EXIT_FAILURE);
	
	}
}

int main(){

	int hlgs_flag;
	printf("\nEnter:\n1.To create fifo using mkfifo\n2.create fifo using mknod\n");
	
	scanf("%d",&hlgs_flag);
	//printf("\nThe directory content before execution:\n");
	//system("ls -l");
	
	if(hlgs_flag==1)fifo_mkfifo();
	else if(hlgs_flag==2)fifo_mknod();
	
	//printf("\n\nThe directory content after execution:\n");
	//system("ls -l");
}




