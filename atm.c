#include<stdio.h>
unsigned long amount = 2000, deposition, withdrawal;
int pin, choice, k;
char transaction = 'y';
void main()
{
    while (pin != 1234) // Using while loop to check for the condition on a pin number matching
    {
        printf("Type your secret pin number: ");
        scanf("%d", &pin);
        if (pin != 1234) 
            printf("Please insert your valid password:\n");
    }
    do
    {
        printf("Hello! Welcome to our ATM Service\n");
        printf("1. Balance Checking\n");
        printf("2. Cash Withdrawal\n");
        printf("3. Cash Deposition\n");
        printf("4. Exit\n");
        printf("*******?********?*\n\n");
        printf("Please proceed with your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nThe account balance in Rs: %lu\n", amount);
            break;
        case 2:
            printf("\nInsert the amount to be withdrawn: ");
            scanf("%lu", &withdrawal);
            if (withdrawal % 100 != 0)  // Fixed typo here
            {
                printf("\nYou are requested to insert the amount in multiples of 100\n");
            }
            else if (withdrawal > (amount - 500))
            {
                printf("\nYou have insufficient balance\n");
            }
            else
            {
                amount = amount - withdrawal;
                printf("\n\nYou can now collect the cash");
                printf("\nThe current balance is %lu\n", amount);  // Fixed space issue here
            }
            break;
        case 3:
            printf("\nInsert the amount to be deposited: ");
            scanf("%lu", &deposition);
            amount = amount + deposition;
            printf("The balance is %lu\n", amount); 
            break;
        case 4:
            printf("\nWe are thankful to you for using our ATM services!\n");
            break;
        default:
            printf("\nYou have made an invalid choice\n"); 
        }
        printf("\n\n\nWould you like to have another ATM transaction? (y/n): ");
        fflush(stdin);
        scanf("%c", &transaction);
        if (transaction == 'n' || transaction == 'N')
            k = 1;
    } while (!k);

    printf("\n\nThank you so much for choosing our ATM services!\n");
}
