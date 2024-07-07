#include<stdio.h>
int main()
{
    char a=231;
    unsigned char b=a;
    printf("a=%c",a);
    printf("\nb=%c",b);
    if(a==b)
    {
        printf("\n Same");
    }
    else
    {
        printf("\n Not Same");
    }
    
}