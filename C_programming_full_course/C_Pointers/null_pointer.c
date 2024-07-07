/*

#include<stdio.h>
int main()
{
    int *ptr = NULL;
    printf("The value of a pointer is: %u",ptr);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    //dynamic memory allocation
    int *ptr = (int *) malloc(5*sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory allocation was failed.\n");
    }
    else
    {
        printf("Memory allocated successfully.\n");
        printf("Size of memory is:%p\n",ptr);
    }
    free(ptr);
    return 0;
}