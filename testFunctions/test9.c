#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef enum EN_terminalError_t
{
     TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void isValidCardPANTest(void)
{
    char card[19];
    for(int i =0; i<2;i++)
{
    printf("input: ");
    gets(card);
    printf("Expected Result: %d\n",(i>0)?3:0);
    int nDigits = strlen(card);
 
    int nSum = 0, isSecond = 0;
    for (int i = nDigits - 1; i >= 0; i--) {
 
        int d = card[i] - '0';
 
        if (isSecond == 1)
            d = d * 2;
 
        // We add two digits to handle
        // cases that make two digits after
        // doubling
        nSum += d / 10;
        nSum += d % 10;
 
        isSecond = !isSecond;
    }
    if(nSum % 10 == 0)
    {
        printf("Actual Result: %d\n",TERMINAL_OK);
    }
    else
    {
        printf("Actual Result: %d\n",INVALID_CARD);
    }
}
}

int main()
{
    isValidCardPANTest();
}