#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef enum EN_terminalError_t
{
     TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void getTransactionAmountTest(void)
{
    for(int i =0; i<2;i++)
    {
    float amount;
    printf("input: ");
    scanf("%f",&amount);
    printf("Expected Result: %d\n",(i>0)?4:0);
    if(amount > 0)
    {
        printf("Actual Result: %d\n",TERMINAL_OK);
    }
    else
        printf("Actual Result: %d\n",INVALID_AMOUNT);
    }
}

int main()
{
    getTransactionAmountTest();
}