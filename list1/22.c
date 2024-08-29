/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
NAME: 22.C
AUTHOR: GANGASAGAR HL
DESCRIPTOR: Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
DATE and TIME : AUG 29TH, 6:30pm 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include<stdio.h>//printf,scanf
#include<unistd.h>//open, write,fork, close
#include<fcntl.h>//all the file related control things

int main(){

int filedsc = open("textfiles/22output.txt",O_RDWR | O_CREAT , 0777);//OPENING THE FILE IN read write and execute mode
if(filedsc==-1){
printf("Opening File Mistake:\n");
return 0;

}

pid_t hpid = fork();//create child processes

if(hpid ==0 ) write(filedsc, "Child 22\n",10);
else write(filedsc,"Parent 22\n",11);

close(filedsc);//closing the file descriptor opened.
return 0;

}
