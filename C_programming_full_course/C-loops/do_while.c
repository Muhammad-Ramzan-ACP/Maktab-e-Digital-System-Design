#include<stdio.h>

/*
int main()
{
    int i=1;
    do
    {
        printf("Hello world ...I love C programming.\n");
        i++;
    } while (i<=5);
    printf("End of do while loop.");
    return 0;
}
*/



int main(){

   // local variable definition
   int a = 0, b = 0; 
   printf("Output of while loop.\n");
   while(a<=5)
   {
        printf("a=%d\n",a);
        a++;
   }
   printf("Output of do while loop.\n");
   do
   {
        printf("b=%d\n",b);
        b++;
   } while (b<=5);
   return 0;
}
   

