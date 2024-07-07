#include<stdio.h>

/*
struct RECTANGLE{
    float length;
    float width;
};

void AREA(float x,float y);
int main()
{
    struct RECTANGLE par;
    par.length=2.2;
    par.width=3.3;
    AREA(par.length,par.width);
}
void AREA(float x,float y)
{
    float result;
    result = (float) (x*y);
    printf("Length is:%5.2f \nWidth is:%5.2f \nArea is:%5.2f",x,y,result);
}
*/

/*

struct RECTANGLE{
    float length;
    float width;
};

void AREA(struct RECTANGLE my_arrea);
int main()
{
    struct RECTANGLE par;
    par.length=2.2;
    par.width=3.3;
    AREA(par);
}
void AREA(struct RECTANGLE my_arrea)
{
    float result;
    result = (float) (my_arrea.length * my_arrea.width);
    printf("Length is:%5.2f \nWidth is:%5.2f \nArea is:%5.2f",my_arrea.length,my_arrea.width,result);
}

*/


//How to Pass a Struct by Reference
/*
struct RECTANGLE{
    float length;
    float width;
};

void AREA(struct RECTANGLE *my_arrea);
int main()
{
    struct RECTANGLE par;
    par.length=2.2;
    par.width=3.3;
    AREA(&par);
}
void AREA(struct RECTANGLE *my_arrea)
{
    float result;
    result = (float) (my_arrea->length * my_arrea->width);
    printf("Length is:%5.2f \nWidth is:%5.2f \nArea is:%5.2f",my_arrea->length,my_arrea->width,result);
}
*/

/*
struct TRIANGLE{
    int length;
    int width;
};

void AREA(int *x,int *y);
int main()
{
    struct TRIANGLE pm;
    pm.length=2;
    pm.width=3;
    AREA(&pm.length,&pm.width);
}
void AREA(int *x,int *y)
{
    struct TRIANGLE temp;
    temp.length=*x;
    temp.width=*y;
    int result = (int)(temp.length * temp.width);
    printf("Length is: %d\nWidth is: %d\nResult is: %d", temp.length, temp.width, result);
}
*/


/*
struct TRIANGLE{
    int length;
    int width;
};

void AREA(int *x,int *y);
int main()
{
    struct TRIANGLE *pm = (struct TRIANGLE*)malloc(sizeof(struct TRIANGLE));
    if(pm==NULL)
    {
        printf("Mmory allocation has been failed");
    }
    pm->length=2;
    pm->width=3;
    AREA(&pm->length,&pm->width);
    free(pm);
}
void AREA(int *x,int *y)
{
    struct TRIANGLE temp;
    temp.length=*x;
    temp.width=*y;
    int result = (int)(temp.length * temp.width);
    printf("Length is: %d\nWidth is: %d\nResult is: %d", temp.length, temp.width, result);
}

*/





