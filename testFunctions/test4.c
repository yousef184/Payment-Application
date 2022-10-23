#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef enum EN_terminalError_t
{
     TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void getTransactionDateTest(void)
{
    
    int date[3];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    date[0] = tm.tm_year + 1900;
    date[1] = tm.tm_mon + 1;
    date[2] = tm.tm_mday;
    char a[10];
    char day[10];
    char month[10];
    char year[10];
    sprintf(day, "%d", date[2]);
    sprintf(month, "%d", date[1]);
    sprintf(year, "%d", date[0]);
    strcpy(a, day);
    strcat(a, "/");
    strcat(a, month);
    strcat(a, "/");
    strcat(a,year );
    printf("%s",a);
}

int main()
{
    getTransactionDateTest();
}