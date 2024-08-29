/*

NAME:17A.C
AUTHOR: GANGASAGAR HL
PROBLEM STATEMENT: Write a program to simulate online ticket reservation.
Write a program to open a file, store a ticket number and exit.

DATE AND TIME: AUG 29TH 2024, 5:50AM
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  
  int file = open("textfiles/17.txt", O_CREAT|O_RDWR,0777),buffer  = 0;
  write(file, &buffer, sizeof(buffer));
  close(file);
}
