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
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/*

Remember: 
1.  Create the fifo file, after createing the fifio file.
2. Write from here.
3. Launch the write
4.  Launch the read. 
5. Before it was the other way, hence I was not getting the output. 
6. If you just open read and not executing write it will wait till other side of the fifo is opened.
7. Then it checks for 10 secs from opening of write, if the data is unavailable, then it prints.


*/

int main() {
    int fd = open("22_fifo", O_WRONLY);
    
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[100];
    

    printf("Enter text: ");
    scanf(" %[^\n]", buffer); // Note the space before %[^\n] to skip leading whitespace

    ssize_t bytesWritten = write(fd, buffer, sizeof(buffer));

    if (bytesWritten == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    close(fd);
    
    printf("Data written to FIFO: %s\n", buffer);

    return 0;
}
