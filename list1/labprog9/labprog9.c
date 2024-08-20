/*
NAME: GANGASAGAR HL
ROLL NUMBER: MT2024048

PROBLEM STATEMENT: PRINITNG THE INFORMATION REGARDING FILE GIVEN, THE LIST WILL BE SHOWN AS YOU PRINT ON THE CONSOLE

*/
#include<stdio.h>//input output functions
#include<stdlib.h>//exit with teh flag
#include<sys/types.h>
#include<sys/stat.h>//the above 2 are used for stat structure and realted data type
#include<unistd.h>//stst system call
#include<time.h>// time related functions and structures

void hlgs_printinfo_file(const char *hlgs_filename)
{

	struct stat hlgs_file_stat; 
	
	//getting stat of file
	if(stat(hlgs_filename,&hlgs_file_stat)==-1){
	  perror("status of file call error: ");
	  exit(EXIT_FAILURE);
	}
	
	printf("The status of file structure is ready: \n");
	
	
	//print the file information
	printf("Filename:  %s\n", hlgs_filename);//name of the file
	printf("INODE: %ld\n",(long)hlgs_file_stat.st_ino);//INODE value 
	printf("NUMBER OF HARDLINKS: %ld\n",(long)hlgs_file_stat.st_nlink);//hardy
	printf("UID: %d\n",hlgs_file_stat.st_uid);
	printf("GID: %d\n",hlgs_file_stat.st_gid);
	printf("SIZE: %ld bytes\n",(long)hlgs_file_stat.st_size);//size of file
	printf("BLOCK SIZE: %ld bytes\n",(long)hlgs_file_stat.st_blksize);
	printf("NUMBER OF BLOCKS : %ld bytes\n",(long)hlgs_file_stat.st_blocks);
	printf("TIME OF LAST ACCESS: %s\n",ctime(&hlgs_file_stat.st_atime));
	printf("TIME OF LAST MODIFICATION: %s\n",ctime(&hlgs_file_stat.st_mtime));
	printf("TIME OF LAST CHANGE: %s\n",ctime(&hlgs_file_stat.st_ctime));


}


int main( int argc, char* argv[] ){
	//when the file name is passed along with the command, it has count
	// regarding number of arguments passed along with name of the program
	if( argc !=2 ){
	  printf("Give proper values thorugh command line, Missing file name:\nRequired format is 'name_of_the_program' filename:\n");
	  exit(EXIT_FAILURE);
	}
	
	printf("Information regarding file is printed using stat structure and the parameters of the stat struture\nThe file is passed as the argument, whcih inturn takes the input and produces all the required output:\n\n ");
	
	hlgs_printinfo_file(argv[1]);
	return 0;

}
