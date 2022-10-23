#include <stdio.h>
#include <time.h>
#include <string.h>
#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    int date[3];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    date[0] = tm.tm_year + 1900;
    date[1] = tm.tm_mon + 1;
    date[2] = tm.tm_mday;
    char day[10];
    char month[10];
    char year[10];
    sprintf(day, "%d", date[2]);
    sprintf(month, "%d", date[1]);
    sprintf(year, "%d", date[0]);
    strcpy((char*)termData->transactionDate, day);
    strcat((char*)termData->transactionDate, "/");
    strcat((char*)termData->transactionDate, month);
    strcat((char*)termData->transactionDate, "/");
    strcat((char*)termData->transactionDate,year );
    return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    int months[2];
    int years[2];
    int x;
    sscanf((char*)cardData->cardExpirationDate, "%2d/%2d",&months[0], &years[0]);
    years[0] += 2000;
    sscanf((char*)termData->transactionDate, "%2d/%2d/%4d",&x,&months[1], &years[1]);
    if(years[0] > years[1])
    {
        return TERMINAL_OK;
    }
    else if(years[0] == years[1])
    {
        if(months[0] >= months[1])
        {
            return TERMINAL_OK;
        }
        return EXPIRED_CARD;
    }

    return EXPIRED_CARD;
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("how much money you want to withdraw: ");
    scanf("%f",&termData->transAmount);
    if(termData->transAmount > 0)
    {
        return TERMINAL_OK;
    }
    return INVALID_AMOUNT;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount <= termData -> maxTransAmount)
    {
        return TERMINAL_OK;
    }
    return EXCEED_MAX_AMOUNT;
}
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    
    termData -> maxTransAmount = maxAmount;
    if(termData -> maxTransAmount > 0)
    {
        return TERMINAL_OK;
    }
    return INVALID_MAX_AMOUNT;
}
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)
{
    int nDigits = strlen((char*)cardData->primaryAccountNumber);
 
    int nSum = 0, isSecond = 0;
    for (int i = nDigits - 1; i >= 0; i--) {
 
        int d = cardData->primaryAccountNumber[i] - '0';
 
        if (isSecond == 1)
            d = d * 2;
 
        
        nSum += d / 10;
        nSum += d % 10;
 
        isSecond = !isSecond;
    }
    if(nSum % 10 == 0)
    {
        return TERMINAL_OK;
    }
    else
    {
        return INVALID_CARD;
    }
}