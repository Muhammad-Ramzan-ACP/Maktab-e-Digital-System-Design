#include <stdio.h>
#define PI 3.14159
#define AREA(r) ((PI*r*r)/2)
int main()
{
    int radius=3;
    float area=AREA(radius);
    printf("Area of triangle is: %f\n",area);
    return 0;
}