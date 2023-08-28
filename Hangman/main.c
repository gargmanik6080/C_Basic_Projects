#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int rand_int(){
    srand(time(NULL));
    return rand() % 50;
}

void displayBody(int mistakes, char* body){
    if (mistakes > 0) {
        body[0] = 'O';
    }
    if (mistakes > 1) {
        body[1] = '/';
    }
    if (mistakes > 2) {
        body[2] = '\\';
        body[3] = ' ';
    }
    if (mistakes > 3) {
        body[3] = '|';
    }
    if (mistakes > 4) {
        body[4] = '/';
    }
    if (mistakes > 5) {
        body[5] = '\\';
    }
    printf( "\t  ___________\n" );
    printf( "\t |           |\n");
    printf( "\t |           %c\n" , body[0]);
    printf( "\t |          %c%c%c\n", body[1], body[3], body[2] );
    printf( "\t |           %c\n", body[3] );
    printf( "\t |          %c %c\n" ,body[4],body[5]);
    printf( "\t |           \n" );
    printf( "\t |           \n" );
    printf( "\t |           \n\n\n");

}

int checkWord(char* selected, char c, char* guessed, int len){
    printf("\n\t");
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if(selected[i] == c){
            guessed[i] = c;
            flag = 1;
        }
        printf("%c ", guessed[i]);
    }
    printf("\n\n");
    return flag;
}
int main(){

    printf("\n\n");
    printf("\t\t\t\t\t\t\t Welcome to Hangman!!! \n\n");
    printf("Guess the word before you are Hanged!!!\n\n");
    printf("\t RULES: \n\n");
    printf("1. The word to be guessed is a famous website name eg. 'google' .\n");
    printf("2. You can make 6 mistakes after which you will be hanged completly. \n");
    printf("3. All words and inputs are Case Insensitive. \n\n\n");

    // List of Websites to choose from
    char websites[50][20] = {"google", "facebook", "youtube", "amazon", "twitter", "linkedin", "instagram", "reddit", "netflix", "ebay", "pinterest", "wikipedia", "yahoo", "microsoft", "apple", "bing", "tumblr", "quora",
                        "imdb", "wordpress", "adobe", "craigslist", "github", "dropbox", "espn", "nytimes", "stackoverflow", "bbc", "weather", "hulu", "flickr", "spotify", "paypal", "yelp", "theguardian", "forbes",
                        "cnn", "walmart", "buzzfeed", "dailymail", "msn", "nasa.gov", "walmart", "target", "cnet", "booking", "etsy", "huffpost", "washingtonpost", "nationalgeographic"};

    int rand_i = rand_int();
    char *selected = websites[rand_i];
    int len = strlen(selected);

    char guessed[len];
    for (int i = 0; i < len; i++) guessed[i] = '_';

    char* body = "";
    int mistakes = 0;
    while(true){
        printf("\nReady to start the game? Type Y or N :");
        char c;
        scanf("%c", &c);
        if(c == 'y' || c == 'Y') break;
    }

    // while (mistakes != 5 || checkWin() == 1)
    {
        displayBody(mistakes, body);
        checkWord(selected, '\0', guessed, len);
    }
}