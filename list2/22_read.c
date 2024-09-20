/*
---------------------------------------------------------------------
NAME:22.c
AUHTOR: GANGASAGAR HL
ROLL NO: MT2024048
DESCRIPTION:Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
DATE: SEP 17 2024
---------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>


int main() {
    fd_set rfds;
    struct timeval tv;
    int fd;

    tv.tv_sec = 10;

    fd = open("22_fifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    if (!select(fd + 1, &rfds, NULL, NULL, &tv)) {
        printf("No data available\n");
    }
	
else{


    char buffer[100];
    

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    close(fd);
    
    printf("Data read from FIFO: %s\n", buffer);


}
    close(fd);

    return 0;
}
