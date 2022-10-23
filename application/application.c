#include "application.h"
#include <stdio.h>

void appStart(void)
{
    ST_cardData_t cardData;
    ST_terminalData_t termData;
    ST_transaction_t transData;
    if(getCardHolderName(&cardData))
    {
        printf("WRONG_NAME, error : %d\n",WRONG_NAME);
        return ;
    }
    if(getCardExpiryDate(&cardData))
    {
        printf("WRONG_EXP_DATE, error : %d\n",WRONG_EXP_DATE);
        return ;
    }
    if(getCardPAN(&cardData))
    {
        printf("WRONG_PAN, error : %d\n",WRONG_PAN);
        return ;
    }
    getTransactionDate(&termData);
    if(isCardExpired(&cardData, &termData))
    {
        printf("EXPIRED_CARD, error : %d\n",EXPIRED_CARD);
        return ;
    }
    setMaxAmount(&termData, 2000.0);
    if(getTransactionAmount(&termData))
    {
        printf("INVALID_AMOUNT, error : %d\n",INVALID_AMOUNT);
        return ;
    }
    if(isBelowMaxAmount(&termData))
    {
        printf("EXCEED_MAX_AMOUNT, error : %d\n",EXCEED_MAX_AMOUNT);
        return ;
    }
    
    if(isValidCardPAN(&cardData))
    {
        printf("INVALID_CARD, error : %d\n",INVALID_CARD);
        return ;
    }
    transData.cardHolderData = cardData;
    transData.terminalData = termData;
    if(recieveTransactionData(&transData))
    {
        return;
    }   
    saveTransaction(&transData);
}
