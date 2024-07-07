#include<stdio.h>

/*
int main()
{
    char my_word='a';
    while(my_word<='z')
    {
        printf("%c",my_word);
        my_word++;
    }
    printf("\nEnd of Loop!.");
    return 0;
    
}
*/



int main(){

   // local variable definition
   int a = 10, b = 0;
   while(a != b)
   {
        printf("a = %d b = %d\n", a, b);
        a--;
        b++;
   }
   printf("a = %d b = %d\n",a,b);
   printf("End loop.\n");
   return 0;
}