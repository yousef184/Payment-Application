#include "card.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    printf("Card Holder Name: ");
    char a[100];
    gets(a);
    int size = strlen(a);
    if(size>50 || size<20)
    {
        return WRONG_NAME;
    }
    else
    {
        strcpy((char*)cardData->cardHolderName, a);
        return CARD_OK;
    }
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    printf("Expiry Date: ");
    char a[100];
    gets(a);
    int size = strlen(a);
    if(size>5 || size<=0 || !isdigit(a[0]) || !isdigit(a[1])||  a[2] != '/'|| !isdigit(a[3]) || !isdigit(a[4]) )
    {
        return WRONG_EXP_DATE;
    }
    else
    {
        strcpy((char*)cardData->cardExpirationDate, a);
        return CARD_OK;
    }
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    printf("Card PAN: ");
    char a[100];
    gets(a);
    int size = strlen(a);
    if(size>19 || size<16)
    {
        return WRONG_PAN;
    }
    else
    {
        strcpy((char*)cardData->primaryAccountNumber, a);
        return CARD_OK;
    }
}
