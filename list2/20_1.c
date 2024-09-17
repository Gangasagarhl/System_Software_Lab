/*
---------------------------------------------------------------------
NAME:20_1.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write two programs so that both can communicate by FIFO -Use one way communication.
Writing the data to the fifo file
DATE: SEP 17 2024
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	
	char data[] = "Hello I'm at 20_1th program ' \nData from FIFO communication\nThis writes the content to the fifo file\n";
	
	printf("Writer to fifo\nHas data:\n\n%s",data);
	
	//Create the FIFO
	int fd = mkfifo("fifo_20", 0777);
	if(fd == -1) {
		perror("Fifo not Generated");
		exit(EXIT_FAILURE);
	}
	
	printf("\nfifo created\n");
	int open_fifo = open("fifo_20", O_WRONLY|O_CREAT);
	if(open_fifo == -1) {
		perror("Fifo not Opened");
		exit(EXIT_FAILURE);
	}
	printf("\nWriting data to the fifo file\n");
	
	int data_written = write(open_fifo, data, strlen(data) + 1);
	if(data_written == -1) {
		perror("Writing in FIFO not happen");
	}
	
	close(open_fifo);
	//system("rm fifo_20");
}
