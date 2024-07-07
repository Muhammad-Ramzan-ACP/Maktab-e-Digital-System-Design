#include<stdio.h>
float divide(int,int);
int main()
{
    int x=10;
    int y=4;
    float z=divide(x,y);
    printf("Final result is:%f",z);
    return 0;
}
float divide(int x,int y)
{
    float result=x/y;
    return result;
}