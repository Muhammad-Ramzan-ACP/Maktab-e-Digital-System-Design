
/*
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float *arrfunction(int);

int main()
{
    int x = 16;
    float *arr = arrfunction(x);
    
    printf("Square of %d: %f\n", x, arr[0]);
    printf("Cube of %d: %f\n", x, arr[1]);
    printf("Square root of %d: %f\n", x, arr[2]);
    
    // Free allocated memory
    free(arr);
    
    return 0;
}

float *arrfunction(int x)
{
    float *arr = (float *)malloc(3 * sizeof(float));
    arr[0] = pow(x, 2);
    arr[1] = pow(x, 3);
    arr[2] = sqrt(x); // Use sqrt() for square root
    
    return arr;
}

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *hellomstr(char *);
int main()
{
    char *name = "Tutorialspoint";
    char *arr = hellomstr(name);
    printf("%s\n",arr);
    return 0;

}
char *hellomstr(char *name)
{
    char *arr = (char*)malloc(50*sizeof(char));
    strcpy(arr,"Hello ");
    strcat(arr,name);
    return arr;
}