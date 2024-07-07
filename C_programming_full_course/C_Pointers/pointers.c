#include<stdio.h>

/*
int main()
{
    int num = 10;
    int *ptr;
    ptr = &num;

    printf("Number is:%d\n",*ptr);

    *ptr = 29;
    printf("Number is:%d\n",*ptr);
    return 0;
}
*/

/*
int main() {
  int x = 10;
  float y = 1.3f;
  char z = 'A';

  // Pointer declaration and initialization

  int *ptr_x;
  float *ptr_y;
  char *ptr_z;

  ptr_x=&x;
  ptr_y=&y;
  ptr_z=&z;

  printf("Value of x = %d\n",*ptr_x);
  printf("Value of y = %f\n",*ptr_y);
  printf("Value of z = %c\n",*ptr_z);
  return 0;
}

*/



/*
int main() {
  int x = 10;
  float y = 1.3f;
  char z = 'A';

  // Pointer declaration and initialization

  int *ptr_x;
  float *ptr_y;
  char *ptr_z;

  ptr_x=&x;
  ptr_y=&y;
  ptr_z=&z;
  // Printing the size of pointer variables
  printf("Size of integer pointer : %zu\n", sizeof(ptr_x));
  printf("Size of float pointer : %zu\n", sizeof(ptr_y));
  printf("Size of char pointer : %zu\n", sizeof(ptr_z));
  return 0;
}

*/

/*

int main(){

   float var1 = 10.55;
   float *ptr_val;
   ptr_val = &var1;

   printf("var1 = %f\n",var1);
   printf("Address of var1 is = %p\n",ptr_val);
   return 0;
}

*/

/*
int main(){

   int var = 10;
   int *ptr_var;
   int **ptr_var1;

   ptr_var = &var;
   ptr_var1 = &ptr_var;

   printf("%p\n",ptr_var);
   printf("%p\n",ptr_var1);
   printf("%d\n",*ptr_var);
  printf("%d\n",**ptr_var1);
   return 0;
}

*/


/*
int main()
{
    int *ptr=NULL;
    printf("The value of ptr is:%x\n",ptr);
    return 0;
}
*/



/*
int main(){

   int  var1;
   char var2[10];

   printf("Address of var1 variable: %x\n", &var1);
   printf("Address of var2 variable: %x\n", &var2);

   return 0;
}
*/

/*

int main(){

   int arr[5] = {1, 2, 3, 4, 5};
   int *art = arr;

   for(int i=0;i<5;i++)
   {
        printf("arr[%d] : %d\n",i,(*art+i));

   }
   return 0;
}

*/



/*
int swap(int *x,int *y);
int main()
{
    int a=10;
    int b =20;
    printf("Before swap....x=%d,y=%d\n",a,b);

    swap(&a,&b);
    printf("After swap....x=%d,y=%d\n",a,b);
    return 0;
}

int swap(int *x,int *y){
    int z;
    z=*x;
    *x=*y;
    *y=z;
}
*/



/*
int max(int *arr, int length);

int main()
{
    int arr[] = {10, 34, 21, 78, 5};
    int len = sizeof(arr)/sizeof(int);

    int ret = max(arr,len);
    printf("The max nummber is:%d\n",ret);
}

int max(int *arr,int length)
{
    int max_num = *arr;
    for(int i=0;i<5;i++)
    {
        printf("arr[%d]:%d\n",i,*arr);
        if (*arr > max_num)
        {
            max_num = *arr;
        }
        arr++;
    }
    return max_num;
}
*/


/*
int main(){

   int a[]= {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   int len = sizeof(a)/sizeof(int);
   int *ptr;
   ptr = a;

   for(int i=0;i<len;i++)
   {
        printf("Address of subscript %d = %d Value=%d\n",i,ptr,*ptr);
        ptr++;
    
   }
   return 0;
}
*/


int main() {
  int int_arr[] = {12, 23, 45, 67, 89};
  int *ptrArr;
  ptrArr = int_arr;

  printf("Value at ptrArr is:%d\n",*ptrArr);

  ptrArr = ptrArr+2;

  printf("Value at ptrArr is:%d\n",*ptrArr);

  return 0;
}



   
