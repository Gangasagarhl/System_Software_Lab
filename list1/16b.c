/*

NAME: 16B.C
AUTHOR:GANGASAGAR HL
DESCRIPTION:Write a program to perform mandatory locking.
b. Implement read lock

DATE AND TIME: 29TH AUGUST 2024, 5:20AM.
*/

#include<stdio.h>//printf,getchar
#include<unistd.h>//open and close function calls
#include<fcntl.h>//function, all file control requirements
int main(void){

int count=0;

struct flock lock;//defining parameters required to lock
lock.l_type=F_RDLCK;//defining readlock
lock.l_whence=SEEK_SET;// same old, set to start
lock.l_start=0;//This sets the starting point of the lock at the beginning of the file
lock.l_len=0;// >0 locks specific range of files, else locks from lstart to the end of the file
lock.l_pid=getpid();// getting process id for rescue

int fd=open("textfiles/16a.txt",O_RDWR);//opening in readwrite mode
if(fd==-1){
perror("File not opened\n");
}
printf("Before Critical Section\n");
fflush(stdin);//attempting to clear the input buffer
fcntl(fd,F_SETLKW,&lock);//locked
printf("Inside Critical Section\n");
printf("press enter to exit critical section \n");

//getchar();
getchar();

lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);//unlocking
printf("Out of Critical Section\n");


return 0;
}
