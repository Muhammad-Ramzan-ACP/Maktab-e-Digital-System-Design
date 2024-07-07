#include<stdio.h>

/*
int main()
{
    int i=1;
    for(i;i<=5;i++)
    {
        printf("i=%d\n",i);
    }
    return 0;
}
*/

/*
int main()
{
    int a;
    for(a=0;a<=10;a++)
    {
        printf("a=%d\n",a);
        if(a==5)
        {
            break;
        }
    }
    return 0;
}
*/


//print multiplication table


/*
int main()
{
    int i;
    for(i=1;i<=10;i++)
    {
        printf("2 x %d = %d\n",i,2*i);
    }
    return 0;
}
*/


/*
int main()
{
    int a;
    for(a=5;a>=1;a--)
    {
        printf("a=%d\n",a);
    }
    return 0;
}
*/

/*
int main(){
   int i;
   int arr[] = {10, 20, 30, 40, 50};
   for(i=0;i<5;i++)
   {
       printf("a[%d]:%d\n",i,arr[i]);
   }
   return 0;
}
*/



/*
int main()
{
    int i;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int sum=0;
    float average;
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    for(i=1;i<=9;i++)
    {
        sum=sum+arr[i];
    }
    printf("Total sum is:%d\n",sum);
    average = sum/arr_length;
    printf("Total average is:%5.2f\n",average);
    return 0;
}
*/

int main()
{  
    int number=4;
    int fact=1;
    int i;
    for (i=1;i<=number;i++)
    {
        fact=fact*i;
    }
    printf("factorial is :%d\n",fact);
    return 0;
}