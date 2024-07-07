#include<stdio.h>


int add(int,int);
int sub(int,int);
int mul(int,int);
float div(float,float);

int main()
{
    int a=10;
    int b=8;

    int res_add = add(a,b);
    int res_sub = sub(a,b);
    int res_mul = mul(a,b);
    float res_div = div(a,b);

    printf("Addition result is:%d\n",res_add);
    printf("Subtraction result is:%d\n",res_sub);
    printf("Multiplication result is:%d\n",res_mul);
    printf("Division result is:%f\n",res_div);
    
}

int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int mul(int a,int b)
{
    return a*b;
}
float div(float a,float b)
{
    return a/b;
}