#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
char uni[40];
struct checkk{

 char name[40]; 
};

void prr(struct checkk s){

   printf("In the prr function: %s\n",s.name);
   struct checkk k;
   strcpy(k.name, s.name);
   strcpy(uni, k.name);
   
}

int main(){

  struct checkk c;
  memset(&c,'\0',sizeof(c));
  scanf("%[^\n]",c.name);
  
  
  prr(c);
  printf("In Main function: %s\n",uni);
  
  
  char buff[15];
  snprintf(buff,"%d",4000);
  printf("\nChecking whether itoa is workign or not %s\n",buff);
  
}

