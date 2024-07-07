#include<stdio.h>


/*
int main()
{
    int num,i;
    for(num=2;num<=30;num++){
        for(i=2;i<=num/2;i++){
            if(num%i==0){
                break;
            }
        }
        if (i>num/2){
            printf("%d is prime\n",num);
        }
    
    }
    return 0;
}
*/


#include<string.h>

int main()
{
    int i;
    char str[] = "Rythmic";
    int len = strlen(str);
    for(i=0;i<len;i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            break;
        }
        printf("%c\n",str[i]);
    }
    return 0;
}