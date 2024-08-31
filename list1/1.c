/*
NAME: MT2024048
AUTHOR: GANGASAGAR HL
PROBLEM STATEMENT: 

1. Using shell command and system call create following tyoes of file:
	a. softlink(symlink system call)
	b. hard link(link system call)
	c. FIFO(mknode sys call or mkfifo library)
	
DATE: AUG 10 2024

*/


#include<stdio.h>// printf, fgets function
#include<stdlib.h>//system(command) function/system call
#include<unistd.h>//symlink function

//when I used to enter the input string, it was taking \n which was there in buffer to eradicate that error,i'm using after first scanf and before fgets()'
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void hlgs_stat(){

	perror("Error is:\n ");
	exit(EXIT_FAILURE);
	
	}


int main()
{

	char hlgs_command[1000];
	int flag;
	
	printf("\nPress:\n1.Create softlink of existing file using command\n2.Create hardlink of existing file using command\n");
	
	scanf("%d",&flag);
	
	
	//printf("\nHave a look at the files in this folder: \n");
		//fushing the standard output , if there anything in teh buffer of standard ouput, then it will be removed by default
	fflush(stdout);
	//if(system("ls -l")==-1)hlgs_stat();
	
	//code begins
	
	// softlink thorugh command
	if(flag==1){
	
		
		
		//getting the command input from the user
		printf("\n\nEnter the soflink command to execute: \n");	
		fflush(stdin);
		fflush(stdout);	
		getchar();// before giving this, the while loop used to loop, without taking any input from the user, but later part it is solved.
		fgets(hlgs_command,sizeof(hlgs_command),stdin);//This takes the command from the user and print work accordingly. 
		if(system(hlgs_command) ==-1) hlgs_stat();
		else{ 
			printf("\nDone:\n");
			//system("ls -l"); 
			
		    }
		    
		
		
			
		}
	
		
		
	//hardlink
	else if(flag==2)
	{
	
		
		
			//getting the command input from the user
		printf("\n\nEnter the hardlink command to execute: \n");	
		fflush(stdin);
		fflush(stdout);	
		getchar();// before giving this, the while loop used to loop, without taking any input from the user, but later part it is solved.
		fgets(hlgs_command,sizeof(hlgs_command),stdin);//This takes the command from the user and print work accordingly. 
		if(system(hlgs_command) ==-1) hlgs_stat();
		else{ 
			printf("\nDone:\n");
			//system("ls -l"); 
		
		    }
		    
		
		  
	
	}
	
	
	
	
	
}


