#include<stdio.h>
int main()
{
    char name[14];
    printf("Enter your name:");
    gets(name);
    printf("Your name is: %s",name);
    return 0;
}