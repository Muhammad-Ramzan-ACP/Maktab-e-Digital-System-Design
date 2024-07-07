#include <stdio.h>

int main(){

   int a = 60;	/* 60 = 0011 1100 */  
   int b = 13;	/* 13 = 0000 1101 */
   int c = 0;
   int d = 0;
   c = a&b;
   d = a&&b;
   printf("Line 1 - Value of c is %d\n", c);
   printf("Line 11- Value of d is %d\n", d);

   c = a|b;
   d = a||b;
   printf("Line 2 - Value of c is %d\n", c);
   printf("Line 22- Value of d is %d\n", d);

   c = ~a;
   d = !a;
   printf("Line 3 - Value of c is %d\n", c);
   printf("Line 33- Value of d is %d\n", d);

   c = a << 2;
   d = a >> 2;
   printf("Line 4 - Value of c is %d\n", c);
   printf("Line 44- Value of d is %d\n", d);

   c = a^b;
   printf("Line 5 - Value of c is %d\n", c);
   return 0;
}
  
