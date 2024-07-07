#include<stdio.h>

/*
int main()
{
    int i,j;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            printf("i:%d j:%d\n",i,j);
        }
        printf("End of inner loop.\n");
    }
    printf("End of outer loop.");
}
*/

/*
int main() {

    int i, j;
    printf("Program to Print the Tables of 1 to 10 \n\n");
    
    for(i = 1; i <= 10; i++) {
        for(j = 1; j <= 10; j++) {
            printf("%4d ", i * j);  // Print each result in a 4-character wide field
        }
        printf("\n");  // Move to the next line after printing each row
    }
    
    return 0;
}

*/


/*
#include<string.h>
int main()
{
    int i,j;
    char x[] = "TutorialsPoint";
    int length = strlen(x);
    for (i=0;i<length;i++){
        for(j=0;j<=i;j++){
            printf("%c",x[j]);
        }
        printf("\n");
    }
    return 0;
}

*/


int main(){

   int i, j;
   int arr[4][4] = {{1,2,3,4},
      {11, 22, 33, 44},
      {9, 99, 999, 9999},
      {10, 20, 30, 40}};
   for(i=0;i<=3;i++){
      for(j=0;j<=3;j++){
        printf("%5d ",arr[i][j]);
      }
      printf("\n");
   }
   return 0;
}