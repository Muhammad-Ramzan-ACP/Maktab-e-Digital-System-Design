#include<stdio.h>

int main() {
    char ch;
    char word[10];
    printf("Enter characters. End by pressing the Enter key:");
    int i = 0;
    while(1) {
        ch = getchar();
        if (ch == '\n')  // Remove the semicolon here
            break;
        word[i] = ch;
        i++;
    }
    printf("You entered the word: %s", word);
    return 0;
}