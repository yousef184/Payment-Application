
#include "../server/server.h"
#include "stdio.h"
#include <string.h>
ST_accountsDB_t accountsDB[255]=  {{2000.0, RUNNING, "8989374615436851"},
                                   {200.0,  RUNNING, "0755048969661871"},
                                   {20000.0, RUNNING, "6772178395399477"},
                                   {2000.0, RUNNING, "5509256074853899"},
                                   {2000.0, BLOCKED, "0114047354192589"},
                                   {2000.0, RUNNING, "0114047354192581"}};
ST_accountsDB_t *ref;
ST_transaction_t yousef = {{"yousef mohamed mahomud","8989374615436851","11/22"},{12,100,"24/10/2022"},{APPROVED},{RUNNING}};
ST_transaction_t zeyad = {{"zeyad mohamed mahomud","8989374615436852","11/22"},{12,100,"24/11/2022"},{APPROVED},{BLOCKED}};
ST_transaction_t transactionsDB[255]={0};
int sequence =0;

void listSavedTransactionsTest(void)
{
    for(int i = 0;i<2;i++)
    {
        printf("#########################\n");
        printf("Transaction Sequence Number: %d\n",transactionsDB[i].transactionSequenceNumber+1);
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

void saveTransactionTest(void)
{
    transactionsDB[0] = zeyad;
    transactionsDB[1] = yousef;
    yousef.transactionSequenceNumber=sequence;
    zeyad.transactionSequenceNumber=sequence+1;
    listSavedTransactionsTest();
}
int main()
{
   saveTransactionTest() ;
}