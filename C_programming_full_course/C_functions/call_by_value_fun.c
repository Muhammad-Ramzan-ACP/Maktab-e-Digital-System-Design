#include<stdio.h>

/*
int add(int x,int y);
int main()
{
    int a=10;
    int b=20;
    int z;
    z=add(a,b);
    printf("Sum is:%d\n",z);
}
int add(int x,int y)
{
    int ret = x+y;
    return ret;
}   
*/


void swap(int x, int y);

int main(){

   /* local variable definition */
   int a = 100;
   int b = 200;

   printf("Before swap, value of a: %d\n", a);
   printf("Before swap, value of b: %d\n", b);

   swap(a,b);
   
   printf("After swap, value of a: %d\n", a);
   printf("After swap, value of b: %d\n", b);
}
void swap(int x,int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    return;
}
