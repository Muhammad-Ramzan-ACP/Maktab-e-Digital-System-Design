#include <stdio.h>

/*
int main () {

   int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
   int i, j;
   for(i=0;i<5;i++)
   {
        for(j=0;j<2;j++)
        {
            printf("a[%d][%d]:%d\n",i,j,a[i][j]);
        }
   }
   return 0;
}
*/

/*
int main(){
   int i, j, k;
   int arr[3][3][3]= {
      {
         {11, 12, 13},
         {14, 15, 16},
         {17, 18, 19}
      },
      {
         {21, 22, 23},
         {24, 25, 26},
         {27, 28, 29}
      },
      {
         {31, 32, 33},
         {34, 35, 36},
         {37, 38, 39}
      },
   };
   printf("3D array elements are:\n");

   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
        for(k=0;k<3;k++)
        {
            printf("%4d",arr[i][j][k]);
        }
        printf("\n");
    }
    printf("\n");

   }
   return 0;
}
*/

/*
int  main() {
   int arr[3][5] = {{1,2,3,4,5}, {10,20,30,40,50}, {5,10,15,20,25}};
   int i, j;
   int sum = 0;
   for(i=0;i<3;i++)
   {
        for(j=0;j<5;j++)
        {
            sum = sum+arr[i][j];
        }
        printf("Sum of row %d: = %d\n",i,sum);
   }
   return 0;
}
*/



int main() {
    int mat1[3][3] = { {2, 4, 1}, {2, 3, 9}, {3, 1, 8} };
    int mat2[3][3] = { {1, 2, 3}, {3, 6, 1}, {2, 4, 7} };
    int mat3[3][3];
    int sum;
    int i, j, k;

    printf("Matrix 1 is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2 is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }

    printf("Multiplication matrix is:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum = 0; // Reset sum for each element in mat3
            for (k = 0; k < 3; k++) {
                sum += mat1[i][k] * mat2[k][j]; // Corrected index for mat2
            }
            mat3[i][j] = sum;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}


