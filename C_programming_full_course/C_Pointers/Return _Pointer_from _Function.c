#include<stdio.h>


/*
int *squrar(int *num); // Function prototype

int main()
{
    int a = 5;
    int *result = squrar(&a); // Pass the address of 'a' to squrar
    printf("My result is: %d", *result); // Dereference result to print the value
    return 0;
}

int *squrar(int *num)
{
    static int z; // Static variable to hold the squared result
    z = (*num) * (*num); // Square the value pointed to by num
    return &z; // Return the address of z
}
*/

/*
#include<string.h>
#include<stdlib.h>
char *hellomsg(char *arr);
int main()
{
    char *name = "TutorialsPint";
    char *arr = hellomsg(name);
    printf("%s\n:",arr);
    free(arr);
    return 0;
}
char *hellomsg(char *x)
{
    char *arr = (char*)
    malloc(5*sizeof(char));
    if(arr !=NULL){
        strcpy(arr,"Hello ");// copies the string "Hello" into arr.
        strcat(arr,x);
    }
    return arr;
}
*/



