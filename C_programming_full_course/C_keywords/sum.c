#include <stdio.h>

void sum(int,int);
int main()
{
    int a=4;
    int b=6;
    sum(a,b);
    return 0;
}
void sum(int a,int b)
{
    printf("Sum is:%d",a+b);
}