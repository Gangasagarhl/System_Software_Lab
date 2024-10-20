#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "structure.h"




int addadmin() {
    int nbyt=0;
    struct admin adm;

    memset(adm.loginId, '\0', sizeof(adm.loginId));
    memset(adm.password, '\0', sizeof(adm.password));
    
    printf("\nEnter the admin Login Id:  ");
    nbyt = scanf("%[^\n]",adm.loginId);
    getchar();
    if(adm.loginId[nbyt]=='\n')
    adm.loginId[nbyt] = '\0';
    
    printf("Login Id entered: %s", adm.loginId);
    
    
    
    printf("\nEnter the admin Password:  ");
    nbyt = scanf("%[^\n]",adm.password);
    getchar();
    if(adm.password[nbyt]=='\n')
    adm.password[nbyt] = '\0';
    printf("Password entered: %s\n", adm.password);
    
    
    


    

    int openFD = open("admin_database.txt", O_RDWR | O_CREAT | O_APPEND, 0775); // Open the file in append mode

    if (openFD == -1) {
        perror("open");
        
        return 0;
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
        
        return 0;
    }


        mylock.l_type = F_UNLCK;
        fcntl(openFD, F_SETLK, &mylock);
        
        
    close(openFD);
    printf("Successfully Inserted\n");

    

    return 1; // Success
}












void adminshow() {
    struct admin temp;
    int openFD = open("admin_database.txt", O_RDONLY, 0744); // Open in read-only mode

    if (openFD == -1) {
        perror("Error opening file");
        return;
    }
    
    
    // Reset the file pointer to the beginning of the file
    lseek(openFD, 0, SEEK_SET);
  
    // Loop to search for the student in the file
    while (read(openFD, &temp, sizeof(temp)) > 0) {
    
    printf("\n Login Id: %s", temp.loginId);
    printf("\n Password: %s", temp.password);
        
       
    printf("\n\n");
    	    	
    		
        
    
}
    close(openFD); // Close the file after use
}





void employeeshow() {
    struct employee temp;
    int openFD = open("employee_database.txt", O_RDONLY, 0744); // Open in read-only mode

    if (openFD == -1) {
        perror("Error opening file");
        return;
    }
    
    
    // Reset the file pointer to the beginning of the file
    lseek(openFD, 0, SEEK_SET);
  
    // Loop to search for the student in the file
    while (read(openFD, &temp, sizeof(temp)) > 0) {
    
    printf("\n Login Id:  %s", temp.loginId);
    printf("\n Password: %s", temp.password);
    printf("\n Name: %s", temp.name);
    printf("\n Age: %s", temp.age);
    printf("\n Email Address: %s", temp.emailAddress);
    printf("\n Mobile: %s", temp.mobile);
    printf("\n date_of_joining: %s", temp.date_of_joining);
    
    printf("\n Position: %s", temp.position);
    printf("\n managerId: %s", temp.managerId);
    printf("\n Assign for Loan: %s", temp.assigned_for_loan);
    printf("\n Address: %s", temp.address);
    
    
    printf("\n\n");
    	    	
    		
        
    
}
    close(openFD); // Close the file after use
}





void accountshow() {
    struct account temp;
    int openFD = open("account_database.txt", O_RDONLY, 0744); // Open in read-only mode

    if (openFD == -1) {
        perror("Error opening file");
        return;
    }
    
    
    // Reset the file pointer to the beginning of the file
    lseek(openFD, 0, SEEK_SET);
  
    // Loop to search for the student in the file
    while (read(openFD, &temp, sizeof(temp)) > 0) {
    
    printf("\n Login Id:  %s", temp.loginId);
    printf("\n Account Number: %s", temp.account_number);
    printf("\n Account Name: %s", temp.account_holder_name);
    printf("\n BAnk Name: %s", temp.bank_name);
    printf("\n Branch Name: %s", temp.branch_name);
    printf("\n Balance: %s", temp.balance);
    printf("\n Date of Opening: %s", temp.date_of_opening);
    
    printf("\n ACtivation: %s", temp.activation);
    //printf("\n managerId: %s", temp.managerId);
    //printf("\n Assign for Loan: %s", temp.assigned_for_loan);
    //printf("\n Address: %s", temp.address);
    
    
    printf("\n\n");
    	    	
    		
        
    
}
    close(openFD); // Close the file after use
}





void loanshow() {
    struct loan temp;
    int openFD = open("loan_database.txt", O_RDONLY, 0744); // Open in read-only mode

    if (openFD == -1) {
        perror("Error opening file");
        return;
    }
    
    
    // Reset the file pointer to the beginning of the file
    lseek(openFD, 0, SEEK_SET);
  
    // Loop to search for the student in the file
    while (read(openFD, &temp, sizeof(temp)) > 0) {
    
    printf("\n EMployee Id:  %s", temp.empId);
    printf("\n USer id: %s", temp.userId);
    printf("\n Status: %s", temp.status);
    printf("\n Descption : %s", temp.description_to_grant_loan);
    printf("\n Feedback: %s", temp.feedback_from_customer_about_employee);
    printf("\n Manager Read: %s", temp.read_by_manager);
    printf("\n Processed??: %s", temp.processed);
    
    
    
    
    printf("\n\n");
    	    	
    		
        
    
}
    close(openFD); // Close the file after use
}




void transactionshow() {
    struct transaction temp;
    int openFD = open("transaction_database.txt", O_RDONLY, 0744); // Open in read-only mode

    if (openFD == -1) {
        perror("Error opening file");
        return;
    }
    
    
    // Reset the file pointer to the beginning of the file
    lseek(openFD, 0, SEEK_SET);
  
    // Loop to search for the student in the file
    while (read(openFD, &temp, sizeof(temp)) > 0) {
    
    printf("\n From Customer Id :  %s", temp.from_customer_id);
    printf("\n From account Nuumber: %s", temp.from_account_no);
    printf("\n To account number: %s", temp.to_account_no);
    printf("\n Date Time: %s", temp.date_time);
    printf("\n Transaction amount: %s", temp.transaction_amount);
    printf("\n Description: %s", temp.description_to_transaction);
    
    printf("\n Balance: %s", temp.balance_from_account_after_transaction);
    
    
    
    printf("\n\n");
    	    	
    		
        
    
}
    close(openFD); // Close the file after use
}




void customershow() {
    struct customer temp;
    int openFD = open("customer_database.txt", O_RDONLY, 0744); // Open in read-only mode

    if (openFD == -1) {
        perror("Error opening file");
        return;
    }
    
    
    // Reset the file pointer to the beginning of the file
    lseek(openFD, 0, SEEK_SET);
  
    // Loop to search for the student in the file
    while (read(openFD, &temp, sizeof(temp)) > 0) {
    
    printf("\n Customer Id :  %s", temp.loginId);
    printf("\n Password :  %s", temp.password);
    printf("\n Name:  %s", temp.name);
    printf("\n Age:  %s", temp.age);
    printf("\n Email Address:  %s", temp.emailAddress);
    printf("\n Mobile:  %s", temp.mobile);
    printf("\n Address:  %s", temp.address);
    printf("\n Applied For Loan:  %s", temp.applied_for_loan);
    
    
    
    printf("\n\n");
    	    	
    		
        
    
}
    close(openFD); // Close the file after use
}






int main(){

//printf("Admin add\n:");
//addadmin();


int number;
scanf("%d",&number);

switch(number){
 
  case 1: adminshow();break;
  case 2: employeeshow(); break;
  case 3: accountshow(); break;
  case 4: loanshow(); break;
  case 5: transactionshow();break;
  case 6: customershow();break;
   
    
}

//viewadmin();

}


































