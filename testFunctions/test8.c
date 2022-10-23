#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef enum EN_terminalError_t
{
     TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void setMaxAmountTest(void)
{
    for(int i =0; i<2;i++)
{
    float maxAmount;
    printf("input: ");
    scanf("%f",&maxAmount);
    printf("Expected Result: %d\n",(i>0)?6:0);
    if(maxAmount>0)
    {
        printf("Actual Result: %d\n",TERMINAL_OK);
    }
    
    else
        printf("Actual Result: %d\n",INVALID_MAX_AMOUNT);
    }
}

int main()
{
    setMaxAmountTest();
}