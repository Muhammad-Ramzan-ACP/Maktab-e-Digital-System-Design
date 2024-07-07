#include<stdio.h>
#define LENGTH 4
#define WIDTH 5
#define NEWLINE '\n'
int main()
{
    int area = LENGTH*WIDTH;
    printf("length: %d width: %d", LENGTH, WIDTH);
    printf("%c",NEWLINE);
    printf("Value of Area is:%d\n",area);
    return 0;
}
    