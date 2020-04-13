#include<stdlib.h>
#include <stdio.h>
#include<string.h>
//Every user has a file of his own
//the name of the file is the ID of the user
//the pin and the balance of the user are stored in the file
//For example here there are two users with id 101 and 102 
void main()
{
	printf("Enter your ID:");
	char F[100],s_pin[100],s_amt[100],s[100];
	int amount,deposit,withdraw;
	int choice, pin,PIN;
	gets(F);
	strcat(F,".txt");
	FILE *p,*P;
	p=fopen(F,"r+");
	P=fopen(F,"r+");
	fgets(s_pin,100,p);
	fgets(s,100,p);
	fgets(s_amt,100,p);
	sscanf(s_pin,"%d",&PIN);
	sscanf(s_amt,"%d",&amount);
	do
	{
		pin=0;
		while (pin != PIN)
		{
			printf("\nENTER YOUR SECRET PIN NUMBER:");
			scanf("%d", &pin);
			if (pin != PIN)
			printf("PLEASE ENTER VALID PASSWORD\n");
		}
		printf("\n\n\n********Welcome to ATM Service**************\n");
		printf("1. Check Balance\n");
		printf("2. Withdraw Cash\n");
		printf("3. Deposit Cash\n");
		printf("4. Quit\n");
		printf("******************?**************************?*\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n YOUR BALANCE Is :  %d ", amount);
			break;
		case 2:
			printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
			scanf("%d", &withdraw);
			if (withdraw % 100 != 0)
				printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100:");
			else if (withdraw >(amount - 1000))
			{
				printf("\n INSUFFICENT BALANCE");
				printf(" \nTHE MIN BALANCE IN 1000");
			}			
			else
			{
				amount = amount - withdraw;
				printf("\n\n PLEASE COLLECT CASH");
				printf("\n YOUR CURRENT BALANCE IS : %d", amount);
			}
			break;
		case 3:
			printf("\n ENTER THE AMOUNT TO DEPOSIT : ");
			scanf("%d", &deposit);
                        amount = amount + deposit;
			printf("YOUR BALANCE IS :  %d", amount);
			break;
		case 4:
			printf("\n THANK U USING ATM");
			sprintf(s,"%d",amount);
			fprintf(P,"%s\n%s",s_pin,s);
			fclose(P);
			fclose(p);
			printf("\n\n THANKS FOR USING OUT ATM SERVICE");
			exit(0);
		default:
			printf("\n INVALID CHOICE");
		}
	} while (1);
	
}
