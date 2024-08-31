/*
-----------------------------------------
PROBLEM DESCRIPTION: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

NAME: 14.c
AUTHOR:GANGASAGAR HL
ROLL NUMBER: MT2024048

DATE AND TIME:  28TH AUGUST& 10:57AM
-----------------------------------------

*/

#include<dirent.h> //opening directory related things
#include<stdio.h> //scanf, printf
#include<stdlib.h>//exit()
#include<sys/types.h>// has many flags in it
#include<sys/stat.h>//to include teh stat function under which the information of necessary file functions are available.
// above two are used to make the function work stat function call work properly

#include<fcntl.h>//used to incorporate the flags properly.
#include<unistd.h>//it has open, close system calls

int main(int ar, char * a[]){

  struct stat hlgs_file;
  struct dirent *entry;
  
  printf("Before opening the file\n");
  // if the opening mode of the file is O_RDONLY, then this will not work in 
  int op = atoi(a[2]),st;
  
  if(op==1){
  int filed = open(a[1],O_RDWR);
  
  if(filed ==-1){
  perror("Open Mistake:\n");
  exit(EXIT_FAILURE);
  }
  }
  
  else{
   DIR *dp;
   dp = opendir(a[1]);
   closedir(dp);
  }
  
  printf("After opening the file\n");
  
  //the information regarding is stored in &fileno
  st = lstat(a[1],&hlgs_file);
  printf("After lstat\n\n\n");
  // if you use nornal stat function call then softlink and harlink referring will not work properly
  if(st==-1){
  perror("lStat function call mistake: \n");
  exit(EXIT_FAILURE);
  }
  
  
  int m  = hlgs_file.st_mode;
  printf("st_mode: %d\n",m);
  
   if(S_ISREG(m)){
     printf("Regular File\n");
   }
   else if(S_ISDIR(m)){
      printf("Directory\n");
   }
   else if(S_ISCHR(m)){
     printf("Character special file\n");
   }
   else if(S_ISBLK(m)){
     printf("Block Special File\n");
   }
   else if(S_ISFIFO(m)){
     printf("FIFO Named pipe\n");
   }
   else if(S_ISLNK(m)){
     printf("Symbolic Link\n");
   }
   return 0;
  
}
