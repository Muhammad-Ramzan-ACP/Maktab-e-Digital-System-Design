#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 123;
    char str[12];
    sprintf(str, "%d", num); // Converts the integer to a string
    printf("The string is: %s\n", str);
    return 0;
}
