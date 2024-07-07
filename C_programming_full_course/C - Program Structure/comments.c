#include<stdio.h>
//florward declration
float area_of_square(float);

/* 
User-defined function to calculate
the area of square. It takes side as the argument 
and returns the area */
float area_of_square(float side)
{
    float area=side*side;
    return area;
}
int main()
{
    float side=2;
    float area=area_of_square(side);
    printf("Side of square is:%5.2f Area of square is:%5.2f",side,area);
    return 0;
}