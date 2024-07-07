#include<stdio.h>

//Q1
/*
int main()
{
   char x = 'A';
   char y = +x;

   float a = 1.55;
   float b = +a;

   printf("x:%c y:%c\n",x,y);
   printf ("a: %f y: %f\n", a,b);

   return 0;
}
*/

//Q2
/*
int main(){

   char x = 'A';
   printf ("Address of x in decimal:%d\n",&x);
   printf ("Address of x in hexadecimal:%p\n",&x);
   return 0;
}
*/

//Q3

int main(){

   int a = 60;	/* 60 = 0011 1100 */
   int c = 0;

   c = ~a;      /* -61 = 1100 0011 */
   printf("Value of c is: %d\n",c);
   return 0;
}