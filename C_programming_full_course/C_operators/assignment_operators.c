#include <stdio.h>

//Q1
/*
int main(){

   int a = 10;
   int b = 20;
   a +=b;
   printf("a:%d",a);
   return 0;
}
*/

//Q2
/*
int main()
{
    int a = 60;
    int b = 2;
    a<<=b;
    printf("a=%d\n",a);
    printf("a=%b\n",a);
    return 0;
}
*/

//Q4

int main(){

   int a = 21;
   int c ;

   c =  a;
   printf("Line 1 - =  Operator Example, Value of c = %d\n", c );

   c +=  a;
   printf("Line 2 - += Operator Example, Value of c = %d\n", c );

   c -=  a;
   printf("Line 3 - -= Operator Example, Value of c = %d\n", c );

   c *=  a;
   printf("Line 4 - *= Operator Example, Value of c = %d\n", c );

   c /=  a;
   printf("Line 5 - /= Operator Example, Value of c = %d\n", c );

   c  = 200;
   c %=  a;
   printf("Line 6 - %%= Operator Example, Value of c = %d\n", c );

   c <<=  2;
   printf("Line 7 - <<= Operator Example, Value of c = %d\n", c );

   c >>=  2;
   printf("Line 8 - >>= Operator Example, Value of c = %d\n", c );

   c &=  2;
   printf("Line 9 - &= Operator Example, Value of c = %d\n", c );

   c ^=  2;
   printf("Line 10 - ^= Operator Example, Value of c = %d\n", c );

   c |=  2;
   printf("Line 11 - |= Operator Example, Value of c = %d\n", c );
   
   return 0;
}

/*
Explanation of Each Operation

    Initial Assignment:
        c = a;
        c is assigned the value of a (21).
        Output: Line 1 - = Operator Example, Value of c = 21

    Addition Assignment:
        c += a;
        c is incremented by a: c = c + a → 21 + 21 = 42.
        Output: Line 2 - += Operator Example, Value of c = 42

    Subtraction Assignment:
        c -= a;
        c is decremented by a: c = c - a → 42 - 21 = 21.
        Output: Line 3 - -= Operator Example, Value of c = 21

    Multiplication Assignment:
        c *= a;
        c is multiplied by a: c = c * a → 21 * 21 = 441.
        Output: Line 4 - *= Operator Example, Value of c = 441

    Division Assignment:
        c /= a;
        c is divided by a: c = c / a → 441 / 21 = 21.
        Output: Line 5 - /= Operator Example, Value of c = 21

    Modulus Assignment:
        c = 200;
        c %= a;
        c is assigned the remainder of c divided by a: c = c % a → 200 % 21 = 11.
        Output: Line 6 - %= Operator Example, Value of c = 11

    Left Shift Assignment:
        c <<= 2;
        c is left-shifted by 2 bits: c = c << 2 → 11 << 2 = 44.
        Explanation: 11 in binary is 1011, left-shifted by 2 bits becomes 101100, which is 44 in decimal.
        Output: Line 7 - <<= Operator Example, Value of c = 44

    Right Shift Assignment:
        c >>= 2;
        c is right-shifted by 2 bits: c = c >> 2 → 44 >> 2 = 11.
        Explanation: 44 in binary is 101100, right-shifted by 2 bits becomes 1011, which is 11 in decimal.
        Output: Line 8 - >>= Operator Example, Value of c = 11

    Bitwise AND Assignment:
        c &= 2;
        c is bitwise ANDed with 2: c = c & 2 → 11 & 2 = 2.
        Explanation: 11 in binary is 1011, 2 in binary is 0010, bitwise AND gives 0010, which is 2 in decimal.
        Output: Line 9 - &= Operator Example, Value of c = 2

    Bitwise XOR Assignment:
        c ^= 2;
        c is bitwise XORed with 2: c = c ^ 2 → 2 ^ 2 = 0.
        Explanation: 2 in binary is 0010, bitwise XOR with 2 gives 0000, which is 0 in decimal.
        Output: Line 10 - ^= Operator Example, Value of c = 0

    Bitwise OR Assignment:
        c |= 2;
        c is bitwise ORed with 2: c = c | 2 → 0 | 2 = 2.
        Explanation: 0 in binary is 0000, 2 in binary is 0010, bitwise OR gives 0010, which is 2 in decimal.
        Output: Line 11 - |= Operator Example, Value of c = 2

*/