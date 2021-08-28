#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MINBAL 500
struct Bank_Account
{
char no[10];
char name[20];
char balance[15]; 
};
struct Bank_Account acc;
void main()
{
 long int pos1,pos2,pos;
 FILE *fp;
 char *ano,*amt;
 char choice;
 int type,flag=0;
 float bal;
 do
 {
fflush(stdin);
printf("1. Add a New Account Holder\n");
printf("2. Display\n");
printf("3. Deposit or Withdraw\n");
printf("4. Number of Account Holder Whose Balance is less than the MinimumBalance\n");
printf("5. Stop\n"); 
printf("Enter your choice : ");
 choice=getchar();
 switch(choice)
 {
case '1' : 
fflush(stdin); 
 fp=fopen("acc.dat","a"); 
printf("\nEnter the Account Number : "); 
gets(acc.no);
printf("\nEnter the Account Holder Name : ");
gets(acc.name);
printf("\nEnter the Initial Amount to deposit : ");
gets(acc.balance);
fseek(fp,0,2);
fwrite(&acc,sizeof(acc),1,fp);
fclose(fp);
 break;
case '2' :
 fp=fopen("acc.dat","r");
 if(fp==NULL)
printf("\nFile is Empty");
 else
 {
printf("\nA/c Number\tA/c Holder NameBalance\n");
 while(fread(&acc,sizeof(acc),1,fp)==1)
printf("%-10s\t\t%-20s\t%s\n",acc.no,acc.name,acc.balance);
fclose(fp);
 }
 break;
case '3' :
fflush(stdin); 
 flag=0; 
 fp=fopen("acc.dat","r+"); 
printf("\nEnter the Account Number :");
scanf("%d",&ano);
 
for(pos1=ftell(fp);fread(&acc,sizeof(acc),1,fp)==1;pos1=ftell(fp))
 {
 if(strcmp(acc.no,ano)==0)
 {
printf("\nEnter the Type 1 for deposit & 2 for withdraw : ");
scanf("%d",&type);
printf("\nYour Current Balance is : %s",acc.balance);
printf("\nEnter the Amount to transact : ");
fflush(stdin);
gets(amt);
if(type==1)
 bal = atof(acc.balance) + atof(amt);
else
{
 bal = atof(acc.balance) - atof(amt);
 if(bal<0)
 {
printf("\nRs.%s Not available in your A/c\n",amt); 
 flag=2; 
 break;
 }
}
flag++;
break;
 }
 }
 if(flag==1)
 {
 pos2=ftell(fp);
 pos = pos2-pos1;
fseek(fp,-pos,1);
sprintf(amt,"%.2f",bal);
strcpy(acc.balance,amt);
fwrite(&acc,sizeof(acc),1,fp);
 }
 else if(flag==0)
printf("\nA/c Number Not exits... Check it again");
fclose(fp);
 break;
case '4' : 
 fp=fopen("acc.dat","r");
 flag=0;
 while(fread(&acc,sizeof(acc),1,fp)==1)
{
 bal = atof(acc.balance);
 if(bal<MINBAL)
 flag++;
 }
printf("\nThe Number of Account Holder whose Balance less than the Minimum Balance : %d",flag);
fclose(fp);
 break; 
case '5' : 
fclose(fp);
 exit(0); 
 } 
printf("\nPress any key to continue....");
getch();
 }while (choice!='5');
}