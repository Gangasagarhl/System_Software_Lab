/*
ID NUMBER: MT2024048
NAME: GANGASAGAR HL

EXERCISE: Create a file and print the file descriptor value, using creat() function
*/ 

#include<stdio.h>//normal io operation
#include<fcntl.h>// the definition of fcntl is written inside this. 
// this is used to control the file, fcntl - file control
// used to execute some commands on the file usually entered on file descriptr value
//when you create a file using open system call,  open or creat, file id/ file descriptor is returned by default
#include<unistd.h>// used if some flags are set, system() ,close()
#include<stdlib.h> // exit function with EXIT_FAILURE flag

void action(){

	const char *hlgs_filename="textfiles/3.txt";
	int hlgs_fd = creat(hlgs_filename,0666);
	
	if(hlgs_fd==-1){
	//if file is not created, then  it prints error
	perror("Creat error: ");
	exit(EXIT_FAILURE);
	}
	
	printf("\nThe File %s, it's descriptor value is  %d\n",hlgs_filename,hlgs_fd);
	
	close(hlgs_fd);
}

void main(){

printf("\n\nCreating file named '3.txt' and printing  the file descriptor value. Used creat() function.\n\n");

//printf("Before creating the file, folder contents are: \n");
//system("ls -l");

action();

printf("\nCreated: \n");
//system("ls -l");

}

