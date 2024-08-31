/*
NAME: 18.C
AUTHOR:GANGASAGAR HL
DESCRIPTION: 18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

*/



#include<stdio.h>//print and scan
#include<fcntl.h>//filecontrol operations
#include<unistd.h>// open close getpid
#include<stdlib.h>// exit and exit status

// Basic structure, it is how the data is pushed into the data base
struct TOD{
int disk;
int tower;
};

//Now initialising the database with some values , and table structure is mentioned according above mentioed structure
void dbinitalise(){
 int wrt;
 printf("We have 3 towers and Number of disks under it is modifable\n");
 printf("Initlaising\n");
 
 
 int file = open("textfiles/18db.txt", O_RDWR|O_CREAT,0777);
 if(file == -1){
 printf("File cannot be opened\n");
 exit(EXIT_FAILURE);
 }
 
 //initlaising the structure
 struct TOD t[3];// considered 2 disks 
 for(int i=0;i<3;i++){
 
 printf("\nPlease enter number of disks to be at tower %d: ",(i+1));
 scanf("%d",&t[i].disk);
 t[i].tower = (i+1);
 
 wrt = write(file,&t[i],sizeof(struct TOD));
 if(wrt==-1){
     perror("Write:");
     exit(EXIT_FAILURE);
 }
 printf("\nWrote these many bytes:%d\n",wrt);
 }
 
 printf("\nInitialised the database:\n");
 
 close(file);
 
 }
 
//While writing this program, I was unable to get the output accordingly, so Want to have a eye on it when something goes wrong
//working
void debugread(){
  int rd;
  int file = open("textfiles/18db.txt",O_RDONLY);
  struct TOD check;
  for(int i=0;i<3;i++ ){
    rd = read(file,&check,sizeof(check));
    printf("Disk:%d\nTower:%d\n\n",check.disk,check.tower);
  }
  
  close(file);

}






// Implmenting read lock on record, there are 2 records in database
void readlock(int l){

  int file = open("textfiles/18db.txt",O_RDONLY);
  if(file == -1){
     printf("File cannot be opened\n");
     exit(EXIT_FAILURE);
   }
  
  struct TOD td;
  
  struct flock rdlk;
  rdlk.l_type = F_RDLCK;
  rdlk.l_whence = SEEK_SET;
  rdlk.l_start = (l-1)*sizeof(struct TOD);
  rdlk.l_len = sizeof(struct TOD);
  rdlk.l_pid = getpid();
  
  printf("Waiting for the lock & outside critical section\n");
  fcntl(file,F_SETLKW, &rdlk);//write lock
  printf("Inside Critical Section\n");
  
  lseek(file,(l-1)*sizeof(struct TOD),SEEK_SET);
  int rd = read(file,&td,sizeof(td));
  printf("Disk: %d\nTower: %d\n\n",td.disk,td.tower);
  
  printf("Press enter to come out of critical section\n");
  getchar();
  getchar();
  
  rdlk.l_type = F_UNLCK;
  fcntl(file,F_SETLK,&rdlk);
  
  printf("Out of critical section:\n");
  close(file);
  
}










//Implmenting advisory locking on the 2 records we have in database
void writelock(int l){
  
  int ndisk;
  int file = open("textfiles/18db.txt",O_RDWR);
  if(file == -1){
     printf("File cannot be opened\n");
     exit(EXIT_FAILURE);
   }
  
  
  struct flock wrlk;
  wrlk.l_type = F_WRLCK;
  wrlk.l_whence = SEEK_SET;
  wrlk.l_start = (l-1)*sizeof(struct TOD);
  wrlk.l_len = sizeof(struct TOD);
  wrlk.l_pid = getpid();
  
  
  
  
  
  
  
  struct TOD td;
  
  printf("Waiting for the lock & outside critical section\n");
  fcntl(file,F_SETLKW, &wrlk);//write lock
  printf("Inside Critical Section\n");
  
  
  lseek(file,(l-1)*sizeof(struct TOD),SEEK_SET);
  int rd = read(file,&td,sizeof(td));
  printf("Enter the number of new disks:\n");
  scanf("%d",&ndisk);
  td.disk = ndisk;
  
  //printf("\n\n\n\nNumber of disks pushed:%d",ndisk);
  td.tower = l;
  
  //modifying the database by writing to the record, but before alter the fd pointer
  lseek(file,-1*sizeof(struct TOD),SEEK_CUR);
  //lseek(file,-1*sizeof(td),SEEK_CUR);
   //currently passing pointer from previously pointed to upwards
  
  printf("Press enter to modify/update\n");
  getchar();
  getchar();
  int wr = write(file,&td,sizeof(td));
  if(wr==-1){
    printf("Writing issue\n");
    perror("Write:");
    exit(EXIT_FAILURE);
  }
  
  printf("Modified the number of disks at tower %d",td.tower);
  
  wrlk.l_type = F_UNLCK;
  
  
  fcntl(file,F_SETLK,&wrlk);//
  printf("Unlocking/ came out of critical section\n");
  
  close(file);

}












int main(){
  
  int choice;
  
  
  printf("Press\n1. Reinitialise the database\n2.Check the contents of database\n3.Ignore\n");
  scanf("%d",&choice);
  if(choice == 1) dbinitalise();
  else if(choice == 2) debugread();
  
  
  printf("Press\n1.Readlock\n2.Writelock\n");
  scanf("%d",&choice);
  
  if (choice==1){
  //readlock
  int twr;
  printf("Press\n 1.Tower1 ,  2.Tower2  and 3.Tower3\n");
  scanf("%d",&twr);
  readlock(twr);
  
  
  }
  else if(choice==2){
  
   int twr;
   printf("Tower content to be changed:\n");
   printf("Press\n 1.Tower1 ,  2.Tower2  and 3.Tower3\n");
   scanf("%d",&twr);
   writelock(twr);
   
   
   printf("\n\nAfter altering the tower content\n");
   debugread();
  
  }
  
  
  
return 0;
}
