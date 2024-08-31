/*

NAME: 1A.C
AUTHOR: GANGASAGER HL
DESCRIPTION:
a. softlink(symlink system call)
b. hard link(link system call)

DATE: 10 AUGUST 2024
*/

// Creating_softlink using sytem call

#include<stdio.h>//normal printf and scanf
#include<unistd.h>// for creating links
#include<stdlib.h>// for system() library function 

//softlink 
void softy()
{
// This function called from the main , used to create the soft link of the function

const char *hlgs_target_file = "1.txt";
const char *hlgs_soft_destination = "textfiles/soft_function_call";

//symlink is available in unistd
	if(symlink(hlgs_target_file,hlgs_soft_destination )==-1)
	{
		perror("Symlink unable to  create:\n");
		exit(EXIT_FAILURE);
		

	}
	

}

//hardlink
void hardy()
{

// This function called from the main , used to create the hard link of the function

const char *hlgs_target_file = "textfiles/1.txt";
const char *hlgs_soft_destination = "textfiles/hard_function_call";

//link is available in unistd, and create the hard link of the file mentioned above.
	if(link(hlgs_target_file,hlgs_soft_destination )==-1)
	{
		perror("Symlink unable to  create:\n");
		exit(EXIT_FAILURE);
		

	}

}




//main function call
int main(){

int flag;
printf("\nEnter 1 to create softlink using system call\nEnter 2 to create hardlink using system call, for the files entered statically");

scanf("%d",&flag);
//printf("\n\nList of files  in this directory before calling system calls:\n");
//system("ls -l");
printf("\n");


if(flag==1)softy();
else if(flag==2)hardy();

//printf("\n\nList of files  in this directory after calling system calls:\n");
//system("ls -l");
printf("\n");

}
