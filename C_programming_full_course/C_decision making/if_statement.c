#include <stdio.h>
/*
int main () {

   // local variable declaration
   int amount;
   float discount, net;

   amount=2250;
   if (amount<1000)
   {
    discount=0;
   }
   if (amount>=1000 && amount<<5000)
   {
    discount=5;
   }
   if (amount>=5000)
   {
    discount=10;
   }
   net = amount - amount*discount/100;
   printf("Amount:%d Discount:%f Net Payable:%f\n",amount,discount,net);
   return 0;
   }
   */

//Q2
/*
  int main (){
   int phy, maths;
   float avg;
   phy = 40; maths = 50; 
   avg = (float)(phy + maths)/2;
   printf("Phy: %d Maths: %d Avg: %f\n", phy, maths, avg);
    
   if (avg >= 50 && (maths >= 35 && phy >= 35))
   {
      printf("Result: Pass");
   }

   if (avg<50)
   {
      printf("Result: Fail\n");
   }
   return 0;
}
*/

//Q3

int main(void) {
   int age = 25;
   if (age<18)
   {
    printf("You need to be over 18 years old to continue\n");
   }
   else if(age<21)
   {
    printf("You need to be over 21\n");
   }
   else
   {
    printf("You are over 18 and older than 21 so you can continue \n");
   }
   return 0;
}