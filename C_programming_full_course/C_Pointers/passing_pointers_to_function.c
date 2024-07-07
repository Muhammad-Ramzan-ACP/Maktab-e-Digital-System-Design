#include<stdio.h>
#include <string.h>


/*
int add(int *x,int *y);
int main()
{
    int x=10;
    int y=20;
    add(&x,&y);
}
int add(int *x,int *y)
{
    int z;
    z = *x+*y;
    printf("Sum is:%d",z);
    return 0;
}
*/

/*
int swap(int *x,int*y);
int main()
{
    int a=4;
    int b=5;
    printf("Before swap:\n");
    printf("a=%d b=%d\n",a,b);
    swap(&a,&b);
    printf("After swap:\n");
    printf("a=%d b=%d\n",a,b);
}
int swap(int *x,int *y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
    return 0;
}
*/

int compare(char *str1,char *str2);
int main()
{
    char str1[] = "BAT";
    char str2[] = "BALL";
    compare(str1,str2);
}
int compare(char *x,char *y)
{
    if (strlen(x) > strlen(y))
    {
        printf("Length of Str1 is greater than or equal to the length of Str2.\n");
    }
    else
    {
        printf("Length of Str1 is less than or equal to the length of Str2.");
    }
    return 0;
}