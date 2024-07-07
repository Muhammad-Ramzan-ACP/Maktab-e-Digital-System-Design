#include <stdio.h>
/*
float average(int arr[]);

int main()
{
    int arr[5] = {10, 34, 21, 78, 5};
    int len = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements
    float rtr = average(arr); // Pass the array to average function
    printf("Average of my array is: %f\n", rtr);
    return 0;
}

float average(int arr[])
{
    int sum = 0;
    float avg;
    // Calculate number of elements using sizeof in the same scope
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    avg = (float)sum / len;
    return avg;
}
*/


/*
float average(int arr[]);

int main()
{
    int arr[5] = {10, 34, 21, 78, 5};
    float rtr = average(arr); // Pass the array to average function
    printf("Average of my array is: %f\n", rtr);
    return 0;
}

float average(int arr[])
{
    int sum = 0;
    float avg;
    // Calculate number of elements using sizeof in the same scope
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    avg = (float)sum / 5;
    return avg;
}
*/

/*

int main()
{
    int arr[] = {1,2,3,4,5};
    int *x = arr,i;
    for(i=0;i<5;i++)
    {
        printf("%d\n",*x);
        x++;
    }
    return 0;
}

*/



/*
int max(int *arr,int lenght);
int main()
{
    int arr[] = {10, 34, 21, 78, 5};
    int len = sizeof(arr)/sizeof(int);
    int maxnum = max(arr,len);
    printf("Maximum number is:%d\n",maxnum);
}

int max(int *arr,int length)
{
    int mx = *arr;
    int i;
    for(i=0;i<length;i++)
    {
        printf("arr[%d]:%d\n",i,(*arr));
        if ((*arr)>mx)
        {
            mx = (*arr);
        }
        arr++;
    }
    return mx;
}

*/


#include<string.h>
int compare(char *,char*);
int main()
{
    char  a[] = "BAT";
    char  b[] = "BALL";
    compare(a,b);
}

int compare(char *a,char *b)
{
    if (strlen(a)>strlen(b))
    {
        printf("Lenght of string a is greater then string b.\n");
    }
    else
    {
        printf("Lenght of string b is greater then string a .\n");
    }
}