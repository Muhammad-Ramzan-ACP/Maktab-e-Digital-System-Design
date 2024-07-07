#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int main()
{
    bool loop = true;
    int i=0;
    while(loop)
    {
        i++;
        printf("i=%d\n",i);
        if(i>=5)
        {
            loop = false;
        }
    }
    printf("Loop stopped\n");
    return EXIT_SUCCESS;
}