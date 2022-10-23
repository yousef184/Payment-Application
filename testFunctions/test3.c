#include <stdio.h>
#include <string.h>


typedef enum EN_cardError_t
{
     CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

void getCardPANTest (void)
{
    
    for(int i =0; i<3;i++)
    {
    printf("input data: ");
    char a[100];
    gets(a);
    int size = strlen(a);
    printf("Expected Result: %d\n",(i>0)?3:0);
    if(size>19 || size<16)
    {
        printf("Actual Result: %d\n",WRONG_PAN);
    }
    else
    {
    printf("Actual Result: %d\n",CARD_OK);
    }
    }
}
int main()
{
    getCardPANTest();
}