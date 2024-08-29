/*

NAME: 16a.C
AUTHOR: GANGASAGAR HL
DESCRIPTION: Write a program to perform mandatory locking.
a. Implement write lock


DATE AND TIME: 29TH AUGUST 4:53AM

*/
#include<stdio.h>//printf function
#include<fcntl.h>//fnctl function
#include<unistd.h>//opening and closing the file


int main(void){

int count=0;

struct flock lock;//calling the flock struct instance
lock.l_type=F_WRLCK;//write implementation
lock.l_whence=SEEK_SET;//moves cursor at the beginning, is same like lseek
lock.l_start=0;//offset from the cursor
lock.l_len=0;//The length of the file region to be locked.
lock.l_pid=getpid();// if locked and closed without unclocking?? This comes to rescue. 

int fd=open("textfiles/16a.txt",O_RDWR);//opening the file in readwrite mode
if(fd==-1){
perror("File not opened\n");
return 0;
}
printf("Before Critical Section\n");

fcntl(fd,F_SETLKW,&lock);//locked
printf("Inside Critical Section\n");
printf("press enter to exit critical section \n");
getchar();//enterrr

lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);//now unlocked
//fcntl(file_descriptor,Command,structure variable)
printf("Out of Critical Section\n");


return 0;
}


