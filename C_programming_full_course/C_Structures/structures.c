#include<stdio.h>
#include<string.h>

/*
struct BOOK{
    char title[10] ;
    char author[10];
    double price;
    int page;
};
int main()
{
    struct BOOK my_book = {"Learn C", "Dennis Ritchie", 675.50, 325};
    printf("Title is: %s\n",my_book.title);
    printf("Author is: %s\n",my_book.author);
    printf("Price is: %lf\n",my_book.price);
    printf("Total pages are: %d\n",my_book.page);
    printf("Size of book struct: %d\n",sizeof(struct BOOK));
    return 0;
}
*/



//do lil bit modificaions in my previous programme



/*
struct BOOK{
    char title[10] ;
    char author[10];
    double price;
    int page;
} my_book;
int main()
{
    strcpy(my_book.title,"Learn C");
    strcpy(my_book.author,"Dennis Ritche");
    my_book.price = 675.50;
    my_book.page = 325;
    
    //struct BOOK my_book = {"Learn C", "Dennis Ritchie", 675.50, 325};
    printf("Title is: %s\n",my_book.title);
    printf("Author is: %s\n",my_book.author);
    printf("Price is: %5.2f\n",my_book.price);
    printf("Total pages are: %d\n",my_book.page);
    printf("Size of book struct: %d\n",sizeof(struct BOOK));
    return 0;
}
*/


//Structures as Function Arguments
/*
struct BOOK{
    char title[40];
    char author[50];
    char subject[60];
    int book_id;
};

void PrintBooks(struct BOOK books);
int main()
{
    struct BOOK bok1;
    struct BOOK bok2;
    strcpy(bok1.title,"C Programming");
    strcpy(bok1.author,"Nohal Ali");
    strcpy(bok1.subject,"Learn Basic of C.");
    bok1.book_id = 1122;
    //function call
    PrintBooks(bok1);

    //i have put some other things
    strcpy(bok2.title,"Python Programming");
    strcpy(bok2.author,"Sara Ali");
    strcpy(bok2.subject,"Learn Basic of Python.");
    bok2.book_id = 8139;
    //second function call
    PrintBooks(bok2);
    return 0;

}

void PrintBooks(struct BOOK books)
{
    printf("Book title : %s\n", books.title);
    printf("Book author : %s\n", books.author);
    printf("Book subject : %s\n", books.subject);
    printf("Book book_id : %d\n", books.book_id);
}

*/





//Use of pointer...

struct BOOK{
    char title[10] ;
    char author[10];
    double price;
    int page;
};
int main()
{
    struct BOOK my_book = {"Learn C", "Dennis Ritchie", 675.50, 325};
    struct BOOK *myptr;
    myptr = &my_book;
    printf("Title is: %s\n",myptr->title);
    printf("Author is: %s\n",myptr->author);
    printf("Price is: %lf\n",myptr->price);
    printf("Total pages are: %d\n",myptr->page);
    printf("Size of book struct: %d\n",sizeof(struct BOOK));
    return 0;
}
