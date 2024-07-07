#include<stdio.h>
int main()
{
    typedef enum {false,true} BOOL;
    int i=0;
    while(true)
    {
        i++;
        printf("%d\n",i);
        if(i>=5)
        {
            break;
        }
    }
    return 0;
}