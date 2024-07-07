#include<stdio.h>
#include<string.h>

/*
int main()
{
    int i =0;
    while(i<=10)
    {
        i++;
        if(i%2==0)
        {
            continue;
        }
        else
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
*/


/*
int main()
{
    char str [] = "Welcome to TutorialsPoint C Tutorial";
    int i =0;
    int len = strlen(str);

    printf("Given string is:%s\n",str);
    printf("String after removing vowels is:\n");
    for(i=0;i<=len;i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            continue;
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}
*/


int main()

{
    int i =0;
    START:
        i++;
        printf("i=%d\n",i);
        if(i<5)
        {
            goto START;
        }
    END:
        printf("End of loop");
    return 0;

}