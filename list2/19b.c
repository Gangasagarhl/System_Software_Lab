/*
---------------------------------------------------------------------
NAME:19b.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Create a FIFO file by
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function 
DATE: SEP 17 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int filesize(char *file) {
    FILE *fd;
    int fileSize;

    // Open the file in binary mode
    fd = fopen(file, "rb");
    if (fd == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Move the file pointer to the end of the file
    fseek(fd, 0, SEEK_END);

    // Get the current file pointer position (size of the file)
    fileSize = ftell(fd);

    // Close the file
    fclose(fd);

    // Print the size of the file
    printf("The size of the file %s is: %d bytes\n", file ,fileSize);

    return fileSize;
}



int main(void) {
	
              

	printf("Using strace command to check whether mknod make more system call or mkfifo makes system call\n");
	

	system("strace -o mkfifo.txt mkfifo myfifo");
	system("strace -o mknod.txt mknod file_pipe p");
	printf("Output for strace for mkfifo and mknod is passed on to txt files and checking the size of the file.\nHence getting to know who has made more system call\n\n\n");
	
	// returnong the file size
	int f1s = filesize("mkfifo.txt"), f2s = filesize("mknod.txt");
	
	if(f1s>f2s) printf("\nmkfifo takes more system calls, hence mknod is better\n");
	else printf("\nmknod takes more system calls, hence mkfifo is better\n");
	
	
	system("rm mkfifo.txt");
	system("rm mknod.txt");
	//system("rm mknod19");
	//system("rm mkfifo19");
	system("rm myfifo");
	system("rm file_pipe");
	
	
	return 0;
	
	
	
}
		
