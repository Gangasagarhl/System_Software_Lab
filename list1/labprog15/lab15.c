/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
NAME:GANGASAGAR HL
ROLL NUMBER: MT2024048

PROBLEM DESCRIPTION: Write a program to display the environmental variable of the user (use environ).

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include<stdio.h>
#include<stdlib.h>// for getenv function call


extern char **environ; 
//environ is used to access environment variables in the current process
//it is pointer to an array of character pointers , each is pointing to a null terminated string
int main(){

     for(int i=0;environ[i]!=NULL;i++) 
        printf("%d) %s\n ",(i+1),environ[i]);
     //printing the contents of environ
        
     printf("***************************************************************\n\n");
     printf("Using getenv() function \n");
     
     char * value = getenv("SHELL");//calling the specific environment variable.
     printf("SHELL: %s\n",value);
     return 0;
}
