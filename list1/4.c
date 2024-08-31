/*
NAME: 4.C
AUTHOR: GANGASAGAR HL

CURRENTLY IN LABPROGRAM 4
STATEMENT: A program to open an existing file with read write mode. Try O_EXCL flag also.
DATE: AUG 17TH 2024 
*/

#include<stdio.h>//for normal input and output file
#include<fcntl.h>//open() system call
#include<unistd.h> //close()
#include<errno.h>//for handling errorno
#include<stdlib.h>//for exit(EXIT_FAILURE)

//The problem statement is execute here
//called from main to avoid plagarism
void execute(){

	const char *hlgs_filename = "textfiles/4.txt";
	printf("\nNow creating file named 'textfiles/4.txt'\n ");
	
	int hlgs_fd= open(hlgs_filename, O_RDWR|O_CREAT,0777);
	if(hlgs_fd ==-1){
	perror("Open  mistake:\n");
	exit(EXIT_FAILURE);
	}
	
	printf("\n\nFile opened successfully\n\n");
	
	
	
	
	
	hlgs_fd = open(hlgs_filename, O_RDWR|O_CREAT|O_EXCL,0644);
	//Atempting to create the same file with the help of O_EXCL 
	if( hlgs_fd==-1 )
	{
		
		if(errno ==EEXIST)
		printf("\n\nFile already exist, Cannot open with O_EXCL\n");
		
		else{
		perror("\n\nError while opening file using O_EXCL:\n");
		exit(EXIT_FAILURE);
		}
	
	}
	
	else{
	printf("\n\nFile Created Successfully with O_EXCL flag.\nFile descriptor is %d", hlgs_fd);
	close(hlgs_fd);
	}
	
	
	

}

void main(){

printf("\nO_EXCL executed if the file path is not existed, else it will generated erro or do not let to create new file.\nUsually used with O_CREAT\n\nExcution:\nhave a look at the dierctory before all the below operation:\n\n");

//system("ls -l");
execute();

printf("\n\n\nOperations Done:\n");
//system("ls -l");

}
