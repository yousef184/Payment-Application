#include <stdio.h>
#include <string.h>


typedef enum EN_cardError_t
{
     CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

void getCardHolderNameTest(void)
{
    
    for(int i =0; i<4;i++)
    {
    printf("input data: ");
    char a[100];
    gets(a);
    int size = strlen(a);
    printf("Expected Result: %d\n",(i>0)?1:0);
    if(size>50 || size<20)
    {
        printf("Actual Result: %d\n",WRONG_NAME);
    }
    else
    {
    printf("Actual Result: %d\n",CARD_OK);
    }
    }
}
int main()
{
    getCardHolderNameTest();
}