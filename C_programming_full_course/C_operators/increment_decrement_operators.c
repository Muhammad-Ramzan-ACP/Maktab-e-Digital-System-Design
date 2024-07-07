#include <stdio.h>
//Q1
/*
int main() {
  int a = 5, b = 5, c = 5, d = 5;
  
  a++; // postfix increment
  ++b; // prefix increment
  c--; // postfix decrement
  --d; // prefix decrement
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
  printf("d=%d\n",d);
  return 0;
}
*/

//Q2
/*
int main() {
  int x = 10;
  int y = 10 + ++x;
  printf("x=%d y=%d",x,y);
  return 0;
}
*/

//Q3
/*
int main() {
  int x = 10;
  int y = 10 + x++;
  printf("x=%d y=%d",x,y);
  return 0;
}
*/

//Q4
/*
int main() {
  int x = 10;
  int y = 10 + x--;
  printf("x=%d y=%d",x,y);
  return 0;
}
*/

//Q5
/*
int main() {
  int x = 10;
  int y = 10 + --x;
  printf("x=%d y=%d",x,y);
  return 0;
}
*/

//Q6

/*
int main(){

   char a = 'a', b = 'M';
   int x = 5, y = 23;

   printf("a: %c b: %c\n", a, b);
   
   a++;
   printf("postfix increment a: %c\n", a);
   
   ++b;
   printf("prefix increment b: %c\n", b);

   printf("x: %d y: %d\n", x, y);
   
   x--;
   printf("postfix decrement x : %d\n", x);
   
   --y;
   printf("prefix decrement y : %d\n", y);

   return 0;
}
*/

int main(){

   int x;
   for(x=1;x<=5;x++)
   {
    printf("x=%d\n",x);
   }
   return 0;
}