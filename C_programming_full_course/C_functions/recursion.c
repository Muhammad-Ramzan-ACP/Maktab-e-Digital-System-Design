#include<stdio.h>



/*
void Fibbonacci_squence(int);

int main()
{
    int num=10;
    Fibbonacci_squence(num);
}
void Fibbonacci_squence(int num){
    int i;
    int t1=0;
    int t2=1;
    int next_term;

    for(i=0;i<=num;i++)
    {
        printf("%d\n",t1);

        next_term = t1+t2;
        t1 = t2;
        t2 = next_term;
    }
    return 0;
}

*/

void Fictorial(int);
int main()
{
    int num=5;
    Fictorial(num);
}
void Fictorial(int num)
{
    int fic = 1;
    int i;
    for (i=1;i<=num;i++)
    {
        fic = fic*i;
    }
    printf("Fictorial of %d is:%d\n",num,fic);
    return 0;
}