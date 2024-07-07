#include<stdio.h>

/*
struct employee{
    char name[23];
    int salary;
    struct DOB{
        int d,m,y;
    }d1;
};
int main()
{
    struct employee e1 = {"Kiran",12000,{5,3,2004}};
    printf("Name: %s\n",e1.name);
    printf("Salary: %d\n",e1.salary);
    printf("Data of birth: %d-%d-%d\n",e1.d1.d,e1.d1.m,e1.d1.y);
    return 0;
}
*/

struct employee{
    char name[23];
    int salary;
    struct DOB{
        int d,m,y;
    }d1;
};
int main()
{
    struct employee e1 = {"Kiran",12000,{5,3,2004}};
    struct employee *ptr = &e1;
    printf("Name: %s\n",ptr->name);
    printf("Salary: %d\n",ptr->salary);
    printf("Data of birth: %d-%d-%d\n",ptr->d1.d,ptr->d1.m,ptr->d1.y);
    return 0;

}