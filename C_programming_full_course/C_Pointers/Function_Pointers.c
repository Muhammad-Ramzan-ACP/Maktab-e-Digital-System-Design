#include<stdio.h>


/*
int additon(int a,int b);
int main()
{
    //first i have to define a function pointer
    int (*ptr_add)(int a ,int b) = additon;
    int x=12;
    int y=8;
    int result = (*ptr_add)(x,y);
    printf("My results are:%d\n",result);
}
int additon(int a,int b)
{
    int sum = a+b;
    return sum;
}
*/


/*
int find_array_sum(int *arr);
int main()
{
    //Function pointer
    int (*ptr_array)(int *arr) = find_array_sum;
    int num_array[] = {1,2,3,4,5};
    (*ptr_array)(num_array);
}

int find_array_sum(int *arr)

{
    int sum = 0;
    for(int i=0;i<5;i++)
    {
        sum = sum + *(arr+i);
    }
    printf("Sum of an array is:%d",sum);
    return 0;
}
*/

//Function pointer to swap two numbers



int swap(int *a,int *b);
int main()
{
    int (*fun_ptr)(int *a,int *b) = swap;
    int x=12;
    int y=4;
    printf("Before swap:\n");
    printf("x=%d y=%d\n",x,y);
    (*fun_ptr)(&x,&y);
    printf("After swap:\n");
    printf("x=%d y=%d\n",x,y);
    return 0;
}
int swap(int *a,int *b)
{
    int z;
    z=*a;
    *a=*b;
    *b=z;
}

