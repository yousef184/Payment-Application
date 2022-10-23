#include <stdio.h>
#include <string.h>
#include<ctype.h>

typedef enum EN_cardError_t
{
     CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

void getCardExpiryDateTest (void)
{
    
    for(int i =0; i<4;i++)
    {
    printf("input data: ");
    char a[100];
    gets(a);
    int size = strlen(a);
    printf("Expected Result: %d\n",(i>0)?2:0);
    if(size>5 || size<=0 || !isdigit(a[0]) || !isdigit(a[1])||  a[2] != '/'|| !isdigit(a[3]) || !isdigit(a[4]) )
    {
        printf("Actual Result: %d\n",WRONG_EXP_DATE);
    }
    else
    {
    printf("Actual Result: %d\n",CARD_OK);
    }
    }
}

int main()
{
    getCardExpiryDateTest();
}