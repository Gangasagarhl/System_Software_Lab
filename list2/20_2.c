/*
---------------------------------------------------------------------
NAME:20_2.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write two programs so that both can communicate by FIFO -Use one way communication.
Reading the data from the fifo file
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
	//const char *path = "./fifo_file";
	char data[500];
	
	printf("Waiting to read the data\nData Written on fifo file is:\n\n\n");
	int open_fifo = open("fifo_20", O_RDONLY);
	if(open_fifo == -1) {
		perror("Fifo not Opened");
		return 0;
	}
	
	int read_data = read(open_fifo, data, sizeof(data));
	if(read_data == -1) {
		perror("Reading in FIFO not happen");
		return 0;
	}
	 
	
	
	close(open_fifo);
	system("rm fifo_20");
}
