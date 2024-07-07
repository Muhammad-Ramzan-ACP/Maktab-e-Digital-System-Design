#include <stdio.h>
#include <math.h>
/*forward declaration*/
float area_of_square(float side);

int main() {
    float side = 4.5;
    float area = area_of_square(side);
    printf("Side=%5.2f Area=%5.2f\n", side, area); // Added a newline for clarity
    return 0;
}
/*subroutine*/
float area_of_square(float side) {
    float area = side*side;
    return area;
}
