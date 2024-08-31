/*
-----------------------------------------
PROBLEM DESCRIPTION: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

NAME: GANGASAGAR HL
ROLL NUMBER: MT2024048

DATE AND TIME:  28TH AUGUST& 10:57AM
-----------------------------------------

*/

#include<stdio.h> //scanf, printf
#include<stdlib.h>//exit()
#include<sys/types.h>// has many flags in it
#include<sys/stat.h>//to include teh stat function under which the information of necessary file functions are available.
#include<unistd.h>//it has open, close system calls

int main(int ar, char * a[]){

  struct stat fileinfo;
  int filed = open(argv[1],O_RDONLY),st;
  if(filed ==-1){
  perror("Open Mistake:\n");
  exit(EXIT_FAILURE);
  }
  
  
  //the information regarding is stored in &fileno
  st = stat(argv[1],&fileino);
  if(st==-1){
  perror("Stat function call mistake: \n");
  exit(EXIT_FAILURE);
  }
  
  if (S_ISREG(fileinfo.st_mode)) 
		printf("regular file\n");
           	
      else if (S_ISDIR(fileinfo.st_mode)) 
		printf("directory file\n");
	           
      else if (S_ISCHR(fileinfo.st_mode)) 
		printf("Character file\n");
           
      else if (S_ISBLK(fileinfo.st_mode)) 
		printf("Block file\n");
           
      else if (S_ISFIFO(fileinfo.st_mode)) 
		printf("FIFO(PIPE) file\n");
           
      else if (S_ISLNK(fileinfo.st_mode)) 
		printf("Symbolic file\n");
	
      else if (S_ISSOCK(fileinfo.st_mode)) 
		printf("Socket file\n");
      else{
      printf("unknown file\n");
      }
close(filed);
  
}
