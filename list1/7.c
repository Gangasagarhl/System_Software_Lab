/*
NAME: 7.C
AUTHOR:GANGASAGAR HL


PROBLEM STATEMENT: Write a program to copy file 1 to file 2
DATE: 22nd AUG 2023

steps:
1.create a file with some input text in it. 
2. Read every character in the sourec file and write the same thing on to th enewfile created.
3. So the file which to be opened in O_RDONLY, o_WRONLY or O_CREAT mode, with some mode.
4. The system calls that may require here are.
read(int fd,buffer,length of the buffer).
Usually the read returns the number of bytes return when it reads 0. 

*/

#include<unistd.h>//open,write,close
#include<stdio.h>
#include<stdlib.h>//exit function with EXIT_FAILURE STATUS
#include<fcntl.h>//Without this O_CREAT,O_RDONLY, these flags won't work'

int main(int argc, char *argv[]){
	printf("Number of parameters passed: %d\n",argc);
	
	printf("Reading from: %s\n",argv[1]);
	printf("Writing to: %s\n",argv[2]);
	int hlgs_fdr = open(argv[1],O_RDONLY,0777),hlgs_nb,hlgs_nw;
	int hlgs_fdw = open(argv[2],O_RDWR|O_CREAT,0777);
	char hlgs_c;
	
	if(hlgs_fdr==-1 || hlgs_fdw==-1 ){
	perror("Error in opening reading or wring file");
	exit(EXIT_FAILURE);
	}
	
	for(;;){
	
	hlgs_nb = read(hlgs_fdr,&hlgs_c,1);
	// since the file descriptor open is not closed, 
	//by default the position is incremented by 1 inside the file opened.
		
	
	if(hlgs_nb==0) break;// when te file reading pointer reaches the end of the file, it returns zero
	hlgs_nw = write(hlgs_fdw, &hlgs_c,1);//The content read is writing into the file 

	
	}
	
	printf("\ncopied from one file to another\n");
	//printf("Have a look at the directory content, The file content has been copied:\n\n");
	//system("ls -l");
	
	if (close(hlgs_fdr)==-1 || close(hlgs_fdw) == -1){
	printf("\nClosing Error\n");
	}
	
	return 0;


}



