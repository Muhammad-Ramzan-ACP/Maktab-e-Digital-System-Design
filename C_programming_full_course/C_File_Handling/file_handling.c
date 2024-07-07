#include<stdio.h>
//Examples of opening a file
/*
int main()
{
    FILE* file;
    file = fopen("razi.txt","w");\
    if(file==NULL)
    {
        printf("Error in creating file.");
    }
    printf("File is created");
    return 0;
}
*/



//Examples of closing a file

/*
int main()
{
    FILE* file;
    file = fopen("razi.txt","w");\
    if(file==NULL)
    {
        printf("Error in creating file.");
    }
    printf("File is created");
    fclose(file);
    printf("\nFile has been closed.");
    return 0;
}
*/


//Writing Single Character to a File
/*
int main()
{
    FILE *fp;
    char *str = "C Programming tutorial from TutorialsPoint";
    int i;
    char ch;
    fp = fopen("file1.txt", "w");

    for(i=0;i<strlen(str);i++)
    {
        ch = str[i];
        if(ch==EOF)
        {
            break;
        }
        fputc(ch,fp);
    }
    printf("Character has been written successfuly in your file.");
    fclose(fp);
    return 0;
*/



//Writing String to a File
/*
int main()
{
    FILE *fp;
    char *str[] =  {"C Programming Tutorial\n", "C++ Tutorial\n", "Python Tutorial\n", "Java Tutorial\n"};
    int i;
    fp = fopen("file2.txt","w");
    for(i=0;i<4;i++)
    {
        fputs(str[i],fp);
    }
    fclose(fp);
    return 0;
}
*/



//Writing Formatted String to a File

/*

struct employee {
   int age;
   float percent;
   char *name;
};
int main()
{
    FILE* filee;
    filee = fopen("file3.txt","w");
    struct employee et[] = {
      {25, 65.5, "Ravi"}, 
      {21, 75.5, "Roshan"}, 
      {24, 60.5, "Reena"}
   };
   for(int i=0;i<3;i++)
   {
        fprintf(filee, "%d %.2f %s\n", et[i].age, et[i].percent, et[i].name);
   }
   fclose(filee);
   return 0;
}*/




/*
    fgetc(): Reads a single character from a file.
    fgets(): Reads a string from a file.
    fscanf(): Reads a formatted string from a file.

*/




//Reading Single Character from a File

/*
int main()
{
    FILE* fp;
    fp = fopen("file1.txt","r");
    char ch;
    while(1)
    {
        ch = fgetc(fp);
        if(ch==EOF)
        {
            break;
        }
        printf("%c",ch);
    }
    return 0;
}
*/


//Reading String from a File
/*
int main()
{
    FILE* fp;
    char *str;
    fp = fopen("file2.txt","r");
    while(!feof(fp))
    {
        fgets(str,256,fp);
        printf ("%s", str) ;

    }
    fclose(fp);
}

*/

//Reading Formatted String from a File

/*
int main() {

   FILE *fp;
   char s[45];
   int a;  
   float p;

   fp = fopen ("file3.txt", "r");

   if (fp == NULL) {
      puts ("Cannot open file"); return 0;
   }

   while (fscanf(fp, "%d %f %s", &a, &p, s) == 3)
   printf ("Name: %s Age: %d Percent: %f\n", s, a, p);
   fclose(fp);

   return 0;
}
*/



//File Handing Binary Read and Write Functions


//Writing to Binary File
/*
struct employee{
    char name[34];
    int age;
    float percent;
};
int main()
{
    FILE *fp;
    fp = fopen("file4.dat","wb");
    struct employee emp[] = {
      {25, 65.5, "Ravi"}, 
      {21, 75.5, "Roshan"}, 
      {24, 60.5, "Reena"}
    };

    for(int i =0;i<3;i++)
    {
        fwrite(&emp[i],sizeof(struct employee),1,fp);
    }
    fclose(fp);
    return 0;
}

*/


//Reading from Binary File


struct employee {
   int age;
   float percent;
   char name[10];
};

int main() {

   FILE *fp;
   struct employee e;

   fp = fopen ("file4.dat", "rb");

   if (fp == NULL) {
      puts ("Cannot open file"); 
      return 0;
   }

   while (fread (&e, sizeof (struct employee), 1, fp) == 1)
   printf ("Name: %s Age: %d Percent: %f\n", e.name, e.age, e.percent);

   fclose(fp);
   
   return 0;
}