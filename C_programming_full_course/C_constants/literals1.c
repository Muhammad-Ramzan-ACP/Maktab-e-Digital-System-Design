#include<stdio.h>
int main()
{
    int oct = 025;
    int hex = 0xa1;
    int x = 0b00010000;
    float j=100E+4;
    float k=-1.3E-03;
    printf("Octal to decimal conversion:%d\n",oct);
    printf("Hexadecimal to decimal conversion:%d\n",hex);
    printf("binary to decimal: %d\n", x);
    printf("j=%f\n",j);
    printf("k=%f\n",k);
    return 0;
}

