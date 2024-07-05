#include<stdio.h>
#include<string.h>
#define MAX_ACCOUNT 100
typedef struct
{
    int account_num;
    char holder_name[20];
    float balance;
}Bankaccount;
Bankaccount bankaccount[MAX_ACCOUNT];
int Numacc=0;
void newacc()
{
    if(Numacc>=MAX_ACCOUNT)
    {
        printf("Maximum limit is reached.");
        return;
    }
    printf("enter account number :");
    scanf("%d",&bankaccount[Numacc].account_num);
    printf("enter account holder name: ");
    scanf("%s",&bankaccount[Numacc].holder_name);
    printf("enter balance: ");
    scanf("%f",&bankaccount[Numacc].balance);
    Numacc++;
    printf("Account added successfully.\n");
}
void display()
{
    int accnum;
    printf("enter account number: ");
    scanf("%d",&accnum);
    for(int i=0;i<Numacc;i++)
    {
        if(bankaccount[i].account_num==accnum)
        {
            printf("Account number: %d\n",bankaccount[i].account_num);
            printf("Account holder name: %s\n",bankaccount[i].holder_name);
            printf("Account Balnace : %f\n",bankaccount[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}
void deposit()
{
    int accnum,i;
    float amount;
    printf("enter account number: ");
    scanf("%d",&accnum);
    for(i=0;i<Numacc;i++)
    {
        if(bankaccount[i].account_num==accnum)
        {
            printf("enter amount to deposit: ");
            scanf("%f",&amount);
            bankaccount[i].balance+=amount;
            printf("Deposit successful.\n New balance is: %f\n",bankaccount[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}
void withdraw()
{
    int accnum,i;
    float amount;
    printf("enter account number: ");
    scanf("%d",&accnum);
    for(i=0;i<Numacc;i++)
    {
        if(bankaccount[i].account_num==accnum)
        {
            printf("enter withdraw ammount: ");
            scanf("%f",&amount);
            if(bankaccount[i].balance>=amount)
            {
            bankaccount[i].balance-=amount;
            printf("Withdraw successful.\n New balance is %f\n",bankaccount[i].balance);
            }
            else
            printf("insufficient balance.\n");
            return;
        }
    }
    printf("Account is not found!\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("1. Create a new account.\n");
        printf("2. Display account details.\n");
        printf("3. Deposit amount.\n");
        printf("4. Withdraw amount.\n");
        printf("5. Exit.\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            newacc();
            break;
            case 2:
            display();
            break;
            case 3:
            deposit();
            break;
            case 4:
            withdraw();
            break;
            case 5:
            printf("Exiting the program.\n");
            return 0;
            break;
            default:
            printf("Invalid input, try again.\n");
        }
    }
    return 0;
}