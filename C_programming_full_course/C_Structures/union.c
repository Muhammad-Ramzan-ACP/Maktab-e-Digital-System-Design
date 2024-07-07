#include<stdio.h>
#include<string.h>
/*
union DATA{
    char name[34];
    int age;
    int salary;
};
int main()
{
    union DATA e1;
    strcpy(e1.name,"Ramzan");
    e1.age = 20;
    e1.salary = 2399;
    printf("Name=%s\nAge=%d\nSalary=%d",e1.name,e1.age,e1.salary);
    return 0;
}
*/

/*

#include <stdio.h>
#include <string.h>

struct Data{
   int i;
   float f;
   char str[20];
};

int main(){
   struct Data data;        
   printf("Memory occupied by Struct Data: %d \n", sizeof(data));
   return 0;
}
*/


#include <stdio.h>
#include <string.h>

union Data{
   int i;
   float f;
   char str[20];
};

int main(){
   union Data data;        
   printf("Memory occupied by Union Data: %dbytes \n", sizeof(data));
   return 0;
}