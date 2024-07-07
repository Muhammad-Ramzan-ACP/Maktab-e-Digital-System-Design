#include <stdio.h>
int main()
{
    int price,quantity,total;
    printf("Enter the value of price and quantity:");
    scanf("%d %d",&price,&quantity);
    total=price+quantity;
    printf("Total amount is %d\n",total);
    return 0;
}