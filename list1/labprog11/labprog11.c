/*
NAME: GANGASAGAR HL
ROLL NUMBER: MT2024048

PROBLEM STATEMENT: Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

once I forgot to add \n 
To all the printf statments, some of the traces could be seen even after appending.
In file , so forget not to add \n to the files.


*/
#include<stdio.h>//normal io
#include<unistd.h> //read,write, dup, dup2, lseek function calls
#include<fcntl.h>//without this some of the options don't work like O_RDWR O_CREAT
#include<stdlib.h>//exit and the EXIT_FAILURE flag
#include<string.h>//The lenght of strings wa not working with the help ofn size of trying to utilise.

void clear(){

fflush(stdout);
fflush(stdin);

  
}

int main(int a,char* ar[]){

 int hlgs_dup,hlgs_dup2,hlgs_fd;
 
 //hlgs
 hlgs_fd = open(ar[1],O_RDWR|O_CREAT,0777);//opening the file with the file name
 if(hlgs_fd ==-1){
 perror("There is error in opening file:\n");
 exit(EXIT_FAILURE);
 }
 //placing the file pointer to end of the file, so that appending becomes easy
 lseek(hlgs_fd, -1,SEEK_END);
 char *content1 ="Appending the contents to the file using orignal file descriptor\n";
 printf("Into the file: %s\n",content1);
 write(hlgs_fd, content1, strlen(content1));
 clear();
 
 
 
 
 
 //now it is dup turn
 hlgs_dup = dup(hlgs_fd);
 if(hlgs_dup==-1){
 perror("Dup error:");
 exit(EXIT_FAILURE);
  }
 //here I'm placing the pointer to the end'
 //lseek(hlgs_dup,-1,SEEK_END);
 char *content2 = "Appendign the content through dup system call\n";
 printf("DUPs turn: %s\n",content2);
 write(hlgs_fd, content2, strlen(content2));
 clear();
 
 
 
 
 
 /*******************************************************************/
 //dup2
 hlgs_dup2 = dup2(hlgs_fd,10);
 printf("\nGiven file descriptor to be 10, to call the dup2\n");
 if(hlgs_dup2==-1){
 perror("Dup2 error:");
 exit(EXIT_FAILURE);
  }
 //here I'm placing the pointer to the end'
 //lseek(hlgs_dup2,-1,SEEK_END);
 char *content3 = "Appending the content through dup2 system call\n";
 printf("DUP2s turn: %s\n",content3);
 write(hlgs_fd, content3, strlen(content3));
 clear();
 

//********************************
//fcntl
char *content4 = "Appending the content through fcntl system call, the last.\nThank you!!\n";
 int fdf = fcntl(hlgs_fd, F_DUPFD, 0);
 if(fdf == -1){
 printf("Error in duplicating:\n");
 close(fdf);
 return 0;
 }
 
 //This enables appending.
 if (fcntl(fdf, F_SETFL, O_APPEND) == -1) {
        perror("Error setting file status flags");
        close(fdf);
        return 1;
    }
 
 
 printf("FCNTL: %s\n",content4);
 write(fdf,content4,strlen(content4));
 

 
 printf("Coming out after appending the contents\n");
 return 0;
 
}



