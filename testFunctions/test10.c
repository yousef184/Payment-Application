#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char c[2][6]={"12345","6789"};

typedef enum EN_serverError_t 
{
     SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t ;

void isValidAccountTest(void)
{
    char card[19];
    for(int i =0; i<2;i++)
{
    printf("input: ");
    gets(card);
    printf("Expected Result: %d\n",(i>0)?3:0);
    for(int j =0; j<2;j++)
    {
        if(!strcmp(card,c[i]))
        {
            printf("Actual Result: ,%d\n",SERVER_OK);
        }
        else
        {
            printf("Actual Result: ,%d\n",ACCOUNT_NOT_FOUND); 
        }
    }
}
}

int main()
{
    isValidAccountTest();
}