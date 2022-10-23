#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef enum EN_terminalError_t
{
     TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void isBelowMaxAmountTest(void)
{
    for(int i =0; i<2;i++)
    {
        int maxAmount = 56;
    float amount;
    printf("input: ");
    scanf("%f",&amount);
    printf("Expected Result: %d\n",(i>0)?5:0);
    if(amount <= maxAmount)
    {
        printf("Actual Result: %d\n",TERMINAL_OK);
    }
    
    else
        printf("Actual Result: %d\n",EXCEED_MAX_AMOUNT);
    }
}

int main()
{
    isBelowMaxAmountTest();
}