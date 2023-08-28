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
    char websites[50][20] = {"jssjpn", "ifgnassz", "esoyoan", "fkfhsr", "yclyynw", "plrznulr", "lrxyfjwfk",
         "wnuuly", "rnyipld", "nafe", "tlrynwnxy", "clzltnulf", "efqss", "klgwsxsiy", "fttpn", "alrj", "yokapw",
         "voswf", "lkua", "cswutwnxx", "fusan", "gwfljxplxy", "jlyqoa", "uwstasd", "nxtr", "reylknx",
         "xyfgzsbnwipsc", "aag", "cnfyqnw", "qopo", "iplgzw", "xtsylie", "tfetfp", "enpt", "yqnjofwulfr",
         "iswanx", "grr", "cfpkfwy", "aohhinnu", "uflpekflp", "kxr", "rfxf", "cfpkfwy", "yfwjny", "grny",
         "asszlrj", "nyxe", "qoiitsxy", "cfxqlrjysrtsxy", "rfylsrfpjnsjwftqlg"};

    int rand_i = rand_int();
    char *selected = websites[rand_i];
    int len = strlen(selected);

    char guessed[len];
    for (int i = 0; i < len; i++) guessed[i] = '_';

    char* body = "";
    int mistakes = 0;

    // Prompting the User if they are Ready to play or not
    char c = '\0';
    while (c != 'y' && c != 'Y')
    {
        printf("\nReady to start the game? Type Y or N :");
        scanf("%c",&c);
        int inputChar;
        while ((inputChar = getchar()) != '\n' && inputChar != EOF) ;
    }

    // while (mistakes != 5 || checkWin() == 1)
    {
        displayBody(mistakes, body);
        checkWord(selected, '\0', guessed, len);
    }
    }