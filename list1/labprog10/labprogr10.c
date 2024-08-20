/*
NAME: GANGASAGAR HL
ROLL NUMBER: MT2024048

PROBLEM STATEMENT :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data.
*/

//this helps in normal io functions
#include<stdio.h>
//open closse system calls, lseek,system
#include<unistd.h>
//exit functions
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>//This give us control over files, if this is written, you don;t get error of
//O_RDWR etc, because this manages


/*
Steps: 

1 . open file in O_RDWR|O_CREAT, with mode 0666(my sepcification)
2. Then write the data of 10 letters into it, using write function
3. Then use lseek to make displacement of 10 bytes,
4. Then write again next 10 bytes
*/



void action(){

	const char *hlgs_filename = "lab10.txt";
	char hlgs_data1[10]="9876543210";
	//open(file_name, flags, mode), written in unistd library
	int hlgs_fd = open(hlgs_filename,O_RDWR|O_CREAT,0666);
	
	if(hlgs_fd ==-1){
	perror("Opening a file error: ");
	exit(EXIT_FAILURE);
	}
	
	
	//write(fd, data1, sizeof()))
	if( write(hlgs_fd, hlgs_data1,sizeof(hlgs_data1))==-1){
	perror("Write call error:");
	exit(EXIT_FAILURE);
	
	}
	
	// now the time for displacement
	int hlgs_lseek = lseek(hlgs_fd, 10,SEEK_CUR);
	printf("\nThe position of lseek command is: %d\n\n", hlgs_lseek);
	
	
	//now enter the data2	
	char hlgs_data2[10]="qwertyuiop";
	if( write(hlgs_fd, hlgs_data2,sizeof(hlgs_data2))==-1){
	perror("Write call error:");
	close(hlgs_fd);
	exit(EXIT_FAILURE);
	
	}
	
	close(hlgs_fd);
	
	


}


void main(){

action();
printf("\n\nThe contents of lab10.txt using od is:  \n\n");
system("od -c lab10.txt ");
}
