/*

NAME: 17B.C
AUTHOR: GANGASAGAR HL
DESCRIPTION: Write a program to simulate online ticket reservation. Implement write lock
	Write a separate program, to open the file, implement write lock, read the ticket number, 	
	increment the number and print the new ticket number then close the file.

DATE AND TIME: AUG 29th

*/

#include<stdio.h>//
#include<fcntl.h>//handling file related
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>//open, close,read, write

int main(){
	int filed = open("textfiles/17.txt", O_RDWR);
        struct flock mylock;//initialising values to set it correct for locking
        mylock.l_type = F_WRLCK;
        mylock.l_whence = SEEK_SET;
        mylock.l_start = 0;
        mylock.l_len = 0;
        mylock.l_pid = getpid();//
        
        printf("Before entering CS:\n");
	//acquire the lock with the help of fcntl.
        fcntl(filed, F_SETLKW, &mylock);//flock(filed, LOCK_EX)
        printf("Entered into the critical section:\n");
        
	int buf;//since we know it was a number, I'm using this else I would have sufferred
	read(filed, &buf, sizeof(buf));
	//reading file descriptor and storing it into the 
	printf("The current ticket number is: %d\n", buf);
	buf = buf+1;// performing according to the problem requirement
	
	//lseek(file_descriptor, offfset, seek current position)
	lseek(filed, 0, SEEK_SET);//now it is set again to starting position.
	//after everytime a file descriptor is read, it points to the last location from where reading or writing has left. 
	printf("Now ticket number is: %d\n", buf);
	write(filed, &buf, sizeof(buf));
	//Because of above, we are overwritng.
	
	
        mylock.l_type = F_UNLCK;
        // after all the operations to be performed, now it getting unlocked.
        fcntl(filed, F_SETLK, &mylock);//unlocked.
        printf("unlocked \n"); 

	close(filed);//closing file descriptor
}


