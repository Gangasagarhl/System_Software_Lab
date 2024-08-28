/*
Name:labprog12.c
Author: GANGASAGAR HL
ID: MT2024048
Descripton: Write a program to find out the opening mode of a file. Use fcntl.
Date: 28th august
Time: 8:40am
*/

#include<stdio.h>
#include<unistd.h>// it has information regarging open call
#include<fcntl.h>
#include<stdlib.h>//exit function
#include<sys/types.h>//flags, readonly etc

int main(int a, char *ar[])
{ 
  //open(filepath, int flags, mode)
  int hlgs_fd=-1,n,hlgs_fcntl;
  printf("Type \n1 to read the file in ready only mode\n2 write only mode\n3 Read Write mode\n");
  scanf("%d",&n);
  if(n==1) {
  //printf("Opening in readonly mode\n");
  hlgs_fd =  open(ar[1],O_RDONLY);
  }
  else if(n==2) {
  //printf("Opening in writeonly mode\n");
  hlgs_fd = open(ar[1],O_WRONLY);
  }
  else if(n==3) {
  //printf("Opening in readwrite mode\n");
  hlgs_fd = open(ar[1],O_RDWR);
  }
  else{ 
  printf("\nWrong Option\n");
  exit(EXIT_FAILURE);
  } 
   
  if(hlgs_fd==-1){
  perror("Open:");
  exit(EXIT_FAILURE);
   }
   
   //fcntl(file descriptor, command )
   hlgs_fcntl = fcntl(hlgs_fd,F_GETFL);
   //printf("fcntl op: %d\n",hlgs_fcntl);
   
   if(hlgs_fcntl == 32768){
   printf("\nOpened in readonly mode\n");
   }
   
   else if(hlgs_fcntl == 32769 ){
   printf("\nOpened in Writeonly mode\n");
   }
   
   else if(hlgs_fcntl == 32770 ){
   printf("\nOpened in Readwrite mode\n");
   }
   else{
   	printf("error\n");
   }
   
   return 0;
   
  
}
