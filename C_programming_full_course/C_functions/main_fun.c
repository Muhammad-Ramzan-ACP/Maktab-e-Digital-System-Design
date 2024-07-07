#include<stdio.h>
#include<stdlib.h>

/*
int main()
{
    int i;
    for (i=1;i<=5;i++)
    {
        if (i==3)
        {
            printf("Exit from code....");
            exit(0);
        }
        else
        {
            printf("Number is:%d\n",i);
        }
    }
    return 0;
}

*/


int main()
{
    int i;
    for (i=1;i<=5;i++)
    {
        if (i==3)
        {
            printf("Exit from code....");
            exit(1);
        }
        else
        {
            printf("Number is:%d\n",i);
        }
    }
    return 0;
}