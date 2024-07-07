#include<stdio.h>


/*
int main()
{
    int x =10;
    int *y =&x;
    printf("x:%d Address of x:%d\n",x,&x);
    printf("Address of y:%d\n",&y);
    printf("Value at Address at y:%d\n",*y);
    return 0;
}
*/


/*
int add(int *,int *);
int main()
{
    int a=10;int b=20;
    int z;
    z=add(&a,&b);
    printf("Sum is:%d\n",z);

}
int add(int *a,int *b)
{  
    int ret = *a + *b;
    return ret;

}

*/


int swap(int *,int *);
int main()
{
    int x=10;
    int y=20;
    printf("Before swap, value of x: %d\n", x);
    printf("Before swap, value of y: %d\n", y);

    swap(&x,&y);

    printf("After swap, value of x: %d\n", x);
    printf("After swap, value of y: %d\n", y);


}
int swap(int *x,int *y){
    int nm;
    nm = *x;
    *x = *y;
    *y = nm;
    return 0;

}
