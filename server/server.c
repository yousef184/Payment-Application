#include <stdio.h>
#include <string.h>
#include "server.h"

ST_accountsDB_t accountsDB[255]=  {{2000.0, RUNNING, "8989374615436851"},
                                   {200.0, RUNNING, "0755048969661871"},
                                   {20000.0, RUNNING, "6772178395399477"},
                                   {2000.0, RUNNING, "5509256074853899"},
                                   {2000.0, BLOCKED, "0114047354192589"},
                                   {2000.0, RUNNING, "0114047354192581"}};

ST_transaction_t transactionsDB[255]={0};
ST_accountsDB_t *ref;
uint32_t sequence = 0;
EN_transState_t result;

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    
    if(isValidAccount(&transData->cardHolderData,ref))
    {
        result = FRAUD_CARD;
        printf("FRAUD_CARD, error : %d\n",result);
        return FRAUD_CARD;
    }
    
    if(isBlockedAccount(ref))
    {
        
        result =DECLINED_STOLEN_CARD;
        printf("DECLINED_STOLEN_CARD, error : %d\n",result);
        return DECLINED_STOLEN_CARD;
    }
    if(isAmountAvailable(&transData->terminalData,ref))
    {
        result =DECLINED_INSUFFECIENT_FUND;
        printf("DECLINED_INSUFFECIENT_FUND, error : %d\n",result);
        return DECLINED_INSUFFECIENT_FUND;
    }
    
    ref->balance = ref->balance - transData->terminalData.transAmount;
    result =APPROVED;
    return APPROVED;
}   

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence)
{
    for(int i = 0; i<6;i++)
    {
        if(!(strcmp((char*)cardData->primaryAccountNumber,(char*)accountsDB[i].primaryAccountNumber)))
        {
            
            ref = &accountsDB[i];
            return SERVER_OK;
        }
    }
    return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    
    if(ref->state == BLOCKED)
    {
        return BLOCKED_ACCOUNT;
    }
    return SERVER_OK;
}
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence)
{
    
    if(accountRefrence->balance < termData->transAmount)
    {
        return LOW_BALANCE;
    }
    return SERVER_OK;
}

EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    transData->transactionSequenceNumber = sequence;
    transData->transState = result;
    transactionsDB[sequence] = *transData;
    sequence++;
    listSavedTransactions();
    return  SERVER_OK;
}
void listSavedTransactions(void)
{
    for(int i = 0;i<sequence;i++)
    {
        printf("#########################\n");
        printf("Transaction Sequence Number: %d\n",i+1);
        printf("Transaction Date: %s\n",transactionsDB[i].terminalData.transactionDate);
        printf("New Account Balance: %.2f\n",accountsDB[i].balance);
        printf("Transaction Amount: %.2f\n",transactionsDB[i].terminalData.transAmount);
        printf("Transaction State: %d\n",transactionsDB[i].transState);
        printf("Terminal Max Amount: %.2f\n",transactionsDB[i].terminalData.maxTransAmount);
        printf("Cardholder Name: %s\n",transactionsDB[i].cardHolderData.cardHolderName);
        printf("PAN: %s\n",transactionsDB[i].cardHolderData.primaryAccountNumber);
        printf("Card Expiration Date: %s\n",transactionsDB[i].cardHolderData.cardExpirationDate);
        printf("#########################\n");
    }
}

