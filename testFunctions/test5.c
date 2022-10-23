#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int flag = 1;

typedef enum EN_terminalError_t
{
     TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void getCardExpiryDateTest (void)
{
    int counter =0;
    char date1[]= {"01/22"} ;
    char date2[11];
    int months[2];
    int years[2];
    int x;
    sscanf(date1, "%2d/%2d",&months[0], &years[0]);
    years[0] += 2000;
    for(int i =0;i<2;i++)
    {
    printf("Input data: ");
    gets(date2);
    printf("Expected Result: %d\n",(i>0)?2:0);
    sscanf(date2, "%2d/%2d/%4d",&x,&months[1], &years[1]);
    if(years[0] > years[1])
    {
        printf("Actual Result: %d\n", TERMINAL_OK);
    }
    else if(years[0] == years[1])
    {
        if(months[0] >= months[1])
        {
            printf("Actual Result: %d\n", TERMINAL_OK);
        }
        else
        {
        printf("Actual Result: %d\n", EXPIRED_CARD);
        }
    }
    else
    {
        printf("Actual Result: %d\n", EXPIRED_CARD);
    }
    }
}

int main()
{
    getCardExpiryDateTest();
}