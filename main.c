#include <stdio.h>
#include "application/application.h"


int main()
{
    int i =1;
    while(i)
    {
    fflush(stdin);
    appStart();
    printf("-To exit insert 0\n-For another transaction insert 1\n");
    scanf("%d",&i);
    }
}