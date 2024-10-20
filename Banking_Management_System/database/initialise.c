#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "structure.h"










void ini_employee(){

int openFD = open("employee_database.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644); 

struct employee emp;

    memset(emp.name, '\0', sizeof(emp.name));
    memset(emp.loginId, '\0', sizeof(emp.loginId));
    memset(emp.password, '\0', sizeof(emp.password));
    memset(emp.age, '\0', sizeof(emp.age));
    memset(emp.emailAddress, '\0', sizeof(emp.emailAddress));
    memset(emp.mobile, '\0', sizeof(emp.mobile));
    memset(emp.date_of_joining, '\0', sizeof(emp.date_of_joining));
    memset(emp.position, '\0', sizeof(emp.position));
    memset(emp.managerId, '\0', sizeof(emp.managerId));
    memset(emp.assigned_for_loan, '\0', sizeof(emp.assigned_for_loan));
    memset(emp.address, '\0', sizeof(emp.address));




/*
//strcpy(admin.db_name,"Admin");

strcpy(emp.loginId,"MT2024048");
strcpy(emp.password,"sagar");
strcpy(emp.name,"GANGASAGAR HL");
//dob
strcpy(emp.age,"25");
strcpy(emp.emailAddress,"hlgsagar.1@gmail.com");
strcpy(emp.mobile,"8105114611");
//date of joining 
strcpy(emp.date_of_joining,"14-10-2024");
/*
emp -  employee
mng -  manager
*/
/*
strcpy(emp.position,"mng");
//the login id of the some employee is pasted here
// usually this is stored
strcpy(emp.managerId,"admin");
//y,n 
strcpy(emp.assigned_for_loan,"n");
// Adress of the employee
strcpy(emp.address,"Hullekere at post Turuvekere Taluk");


*/

printf("\nLoginId ");
scanf("%[^\n]", emp.loginId);
getchar();

printf("\nPassword ");
scanf("%[^\n]", emp.password);
getchar();


printf("\n Name ");
scanf("%[^\n]", emp.name);
getchar();


printf("\nage ");
scanf("%[^\n]", emp.age);
getchar();

printf("\n Email Address");
scanf("%[^\n]", emp.emailAddress);
getchar();

printf("\nMobile ");
scanf("%[^\n]", emp.mobile);
getchar();

printf("\nDate Of Joining ");
scanf("%[^\n]", emp.date_of_joining);
getchar();


printf("\nPosition ");
scanf("%[^\n]", emp.position);
getchar();

printf("\nmanager id");
scanf("%[^\n]", emp.managerId);
getchar();

printf("\nassigned for loan");
scanf("%[^\n]", emp.assigned_for_loan);
getchar();

printf("\naddress");
scanf("%[^\n]", emp.address);
getchar();


lseek(openFD, 0, SEEK_END);
ssize_t bytes_written = write(openFD, &emp, sizeof(emp));

    if (bytes_written == -1) {
        perror("write");
        close(openFD);
        //close(clientSocket);
        return;
    }
    printf("Succesfull Initialised Employee\n");
    close(openFD);


}








void ini_cust(){

int openFD = open("customer_database.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 

struct customer cust;
    memset(cust.name, '\0', sizeof(cust.name));
    memset(cust.loginId, '\0', sizeof(cust.loginId));
    memset(cust.password, '\0', sizeof(cust.password));
    memset(cust.age, '\0', sizeof(cust.age));
    memset(cust.emailAddress, '\0', sizeof(cust.emailAddress));
    memset(cust.mobile, '\0', sizeof(cust.mobile));
    memset(cust.address, '\0', sizeof(cust.address));
    memset(cust.applied_for_loan,'\0',sizeof(cust.applied_for_loan));

/*
strcpy(cust.loginId,"1SG17CS031");
strcpy(cust.password,"log_sagar");
strcpy(cust.name,"HLG SAGAR");
strcpy(cust.age,"25");
strcpy(cust.emailAddress,"hlgsagar.1@gmail.com");
strcpy(cust.mobile,"8105114611");

// this is used for loan recovery
strcpy(cust.address,"Hullekere");

// 0(default),1(when applying)
strcpy(cust.applied_for_loan,"0");

*/

printf("Login Id: \n");
scanf("%[^\n]", cust.loginId);
getchar();

printf("\nPassword ");
scanf("%[^\n]",cust.password);
getchar();


printf("\nName ");
scanf("%[^\n]",cust.name);
getchar();

printf("\nage");
scanf("%[^\n]",cust.age);
getchar();

printf("\nEmailAddress ");
scanf("%[^\n]",cust.emailAddress);
getchar();


printf("\nMobile ");
scanf("%[^\n]",cust.mobile);
getchar();


printf("\nAddress ");
scanf("%[^\n]",cust.address);
getchar();


printf("\nApplied For Loan");
scanf("%[^\n]",cust.applied_for_loan);
getchar();


lseek(openFD, 0, SEEK_END);
ssize_t bytes_written = write(openFD, &cust, sizeof(cust));

    if (bytes_written == -1) {
        perror("write");
        close(openFD);
        //close(clientSocket);
        return;
    }
    printf("Succesfull Initialised customer Initialisation done Employee\n");
    close(openFD);


}



void ini_acc(){

int openFD = open("account_database.txt",  O_WRONLY | O_CREAT | O_TRUNC, 0644); 

struct account acc;
// this can be used by both the user and employee, so 
//memset(cust.name, '\0', sizeof(cust.name));



// Correct usage of memset for all fields



memset(acc.loginId, '\0',sizeof(acc.loginId));
memset(acc.account_number, '\0', sizeof(acc.account_number) );
memset(acc.account_holder_name,'\0',sizeof(acc.account_holder_name));
memset(acc.bank_name,'\0',sizeof(acc.bank_name));
memset(acc.branch_name,'\0',sizeof(acc.branch_name));
//memset(acc.IFSC,'\0',sizeof(acc.IFSC));
memset(acc.balance,'\0',sizeof(acc.balance));
memset(acc.date_of_opening,'\0',sizeof(acc.date_of_opening));
memset(acc.activation,'\0',sizeof(acc.activation));



/*strcpy(acc.account_user_id,"1SG17CS031");
strcpy(acc.account_number,"8105114611");
strcpy(acc.account_holder_name,"HLG SAGAR");
strcpy(acc.bank_name,"SBI");
strcpy(acc.branch_name,"AMMASANDRA");
strcpy(acc.IFSC,"SBIN");
strcpy(acc.balance,"8105114611");
strcpy(acc.date_of_opening,"14-10-2024");
strcpy(acc.status,"a");

*/

printf("\nUser Login Id: ");
scanf("%[^\n]",acc.loginId);
getchar();

printf("\nAccount Number ");
scanf("%[^\n]",acc.account_number);
getchar();

printf("\nHolder Name");
scanf("%[^\n]",acc.account_holder_name);
getchar();

printf("\nBank name");
scanf("%[^\n]",acc.bank_name);
getchar();

printf("\nBranch Name");
scanf("%[^\n]",acc.branch_name);
getchar();

printf("\nbalance ");
scanf("%[^\n]",acc.balance);
getchar();

printf("\ndate_of_opening");
scanf("%[^\n]",acc.date_of_opening);
getchar();

printf("\nActivation");
scanf("%[^\n]",acc.activation);
getchar();


lseek(openFD, 0, SEEK_END);
ssize_t bytes_written = write(openFD, &acc, sizeof(acc));

    if (bytes_written == -1) {
        perror("write");
        close(openFD);
        //close(clientSocket);
        return;
    }
    printf("Succesfull Initialised account done\n");
    close(openFD);

}






void ini_loan(){

int openFD = open("loan_database.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644); 

struct loan l;

   
    memset(l.empId, '\0', sizeof(l.empId));
    memset(l.userId, '\0', sizeof(l.userId));
    memset(l.status, '\0', sizeof(l.status));
    memset(l.description_to_grant_loan, '\0', sizeof(l.description_to_grant_loan));
    memset(l.feedback_from_customer_about_employee, '\0', sizeof(l.feedback_from_customer_about_employee));
    memset(l.read_by_admin, '\0', sizeof(l.read_by_admin));
   





printf("\nEmpid ");
scanf("%[^\n]",l.empId);
getchar();

printf("\nUserId ");
scanf("%[^\n]",l.userId);
getchar();

printf("\nstatus ");
scanf("%[^\n]",l.status);
getchar();

printf("\nDescription to grant loan:  ");
scanf("%[^\n]",l.description_to_grant_loan);
getchar();

printf("\nFeedback_from_customer_about_employee\n");
scanf("%[^\n]",l.feedback_from_customer_about_employee);
getchar();

printf("\n read_by_admin: ");
scanf("%[^\n]",l.read_by_admin);
getchar();



lseek(openFD, 0, SEEK_END);
ssize_t bytes_written = write(openFD, &l, sizeof(l));

    if (bytes_written == -1) {
        perror("write");
        close(openFD);
        //close(clientSocket);
        return;
    }
    printf("Succesfull Initialised Manager Employee\n");
    close(openFD);


}




void ini_trans(){

int openFD = open("transaction_database.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644); 

struct transaction t;

   
    memset(t.transaction_id, '\0', sizeof(t.transaction_id));
    memset(t.from_account_no, '\0', sizeof(t.from_account_no));
    memset(t.to_account_no, '\0', sizeof(t.to_account_no));
    memset(t.date_time, '\0', sizeof(t.date_time));
    memset(t.amount, '\0', sizeof(t.amount));
    memset(t.description_to_transaction, '\0', sizeof(t.description_to_transaction));
    memset(t.balance_from_account_after_transaction, '\0', sizeof(t.balance_from_account_after_transaction));
    
   





printf("\n Transaction Id ");
scanf("%[^\n]",t.transaction_id);
getchar();

printf("\n From Accunt number ");
scanf("%[^\n]",t.from_account_no);
getchar();

printf("\n To account number ");
scanf("%[^\n]",t.to_account_no);
getchar();

printf("\n Date Time ");
scanf("%[^\n]",t.date_time);
getchar();

printf("\n Amount ");
scanf("%[^\n]",t.amount);
getchar();

printf("\n Description to transaaction ");
scanf("%[^\n]",t.description_to_transaction);
getchar();

printf("\n Balance from account after transaction: ");
scanf("%[^\n]",t.balance_from_account_after_transaction);
getchar();



lseek(openFD, 0, SEEK_END);
ssize_t bytes_written = write(openFD, &t, sizeof(t));

    if (bytes_written == -1) {
        perror("write");
        close(openFD);
        //close(clientSocket);
        return;
    }
    printf("Succesfull Initialised Manager Employee\n");
    close(openFD);


}






int main(){
// this to be done only at start, before starting anything.

printf("Employee Details to be filled\n\n");
ini_employee();

//printf("Customer\n");
//n=4;
//while(n--) 
//ini_cust();

//printf("Loan: \n");
//n=5;
//while(n--) 
//ini_loan();

//printf("Account\n");
//n=4; // same as number of customers, so that managing becomes easy
//while(n--) 
//ini_acc();

//printf("Transaction\n");
//n=7;// shall be withdraw, deposit, etc etc 
//while(n--) 
//ini_trans();

}
