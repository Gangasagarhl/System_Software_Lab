#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"structure.h"


void addAdmin(){

    int nbyt=0;
    struct admin adm;

    memset(adm.loginId, '\0', sizeof(adm.loginId));
    memset(adm.password, '\0', sizeof(adm.password));
    
    printf("Enter admin login ID: ");
    scanf("%[^\n]",adm.loginId);
    getchar();
    
    
    
    printf("Enter admin Passowrd: ");
    scanf("%[^\n]",adm.password);
    getchar();
    
    
    
  
    
    
   
    int openFD = open("admin_database.txt", O_RDWR | O_CREAT | O_APPEND, 0775); // Open the file in append mode

    if (openFD == -1) {
        perror("open");
        
        return ;
    }


struct flock mylock;
        mylock.l_type = F_WRLCK;
        mylock.l_whence = SEEK_SET;
        mylock.l_start = 0;
        mylock.l_len = 0;
        mylock.l_pid = getpid();
        
        
        
        
    fcntl(openFD, F_SETLKW, &mylock);
    lseek(openFD, 0, SEEK_END);
    ssize_t bytes_written = write(openFD, &adm, sizeof(adm));

    if (bytes_written == -1) {
        perror("write");
        close(openFD);
        
        return ;
    }


        mylock.l_type = F_UNLCK;
        fcntl(openFD, F_SETLK, &mylock);
        
        
    close(openFD);
    printf("Successfully added\n");
    

 
}



int main(){

    
   addAdmin();
}






















