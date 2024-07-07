#include<stdio.h>

/*
struct NAME{
    int a;
    struct NAME *b;
};
int main()
{
    struct NAME x = {10,NULL},y = {20,NULL} ,z={30,NULL};
    struct NAME *p1,*p2,*p3;
    p1=&x;
    p2=&y;
    p3=&z;
//to find next address
    x.b=p2;
    y.b=p3;
    z.b=p1;
    printf("Address of x:%d a:%d Address of Next is:%d\n",p1,x.a,x.b);
    printf("Address of y:%d a:%d Address of Next is:%d\n",p2,y.a,y.b);
    printf("Address of z:%d a:%d Address of Next is:%d\n",p3,z.a,z.b);
    return 0;
}
*/

struct NAME{
    int a;
    struct NAME *b;
};
int main()
{
    struct NAME *p1,*p2,*p3;
    p1 = (struct NAME*)malloc(sizeof(struct NAME));
    p2 = (struct NAME*)malloc(sizeof(struct NAME));
    p3 = (struct NAME*)malloc(sizeof(struct NAME));

    p1->a = 10;
    p2->a = 20;
    p3->a = 30;

    p1->b = p2;
    p2->b = p3;
    p3->b = p1;

    printf("Address of x:%d a:%d Address of Next is:%d\n",p1,p1->a,p1->b);
    printf("Address of y:%d a:%d Address of Next is:%d\n",p2,p2->a,p2->b);
    printf("Address of z:%d a:%d Address of Next is:%d\n",p3,p3->a,p3->b);
}