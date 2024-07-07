#include<stdio.h>
int main()
{
    typedef enum {false,true} BOOL;
    BOOL x=true;
    BOOL y =false;
    printf("%d\n:",x);
    printf("%d:",y);
    return 0;
}