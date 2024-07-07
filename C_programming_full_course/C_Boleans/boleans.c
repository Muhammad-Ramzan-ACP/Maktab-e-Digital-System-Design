#include<stdio.h>
int main()
{
    enum bool {false,true};
    enum bool x = true;
    enum bool y = false;
    printf("%d\n:",x);
    printf("%d\n:",y);
    return 0;
}