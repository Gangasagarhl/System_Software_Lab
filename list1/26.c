/*
NAME: 26
AUTHOR: GANGASAGAR HL
DESCRIPTION: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include<stdio.h>//io operations
#include<unistd.h>//system 
#include<string.h>
#include<stdlib.h>


int main(){

  
  char s[100]="./a.out ",p[20];
  
  printf("\nEnter what you want to pass\n");
  scanf("%[^\n]",p);
  
  strcat(s,p);
  printf("\nCommand going to execute is: %s\n",s);
  
  printf("Now Compiling the executable file from here:\n");
  system("cc 26exe.c");
  
  printf("Executing the file by passing entered content:\nHanding over control\n");
  system(s);
  printf("\n\nParent program excuting\nDone!!\n");
  
  
  
}
