#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Generating a random int in the range 0 to 49
int rand_int(){
    srand(time(NULL));
    return rand() % 50;
}

// Displaying the Hangman Body
void displayBody(int mistakes, char body[], char falseGuess[]){
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

    printf("\t  ___________\n");
    printf( "\t |           |\n");
    printf( "\t |           %c\n" , body[0]);
    printf( "\t |          %c%c%c\n", body[1], body[3], body[2] );
    printf( "\t |           %c\n", body[3] );
    printf( "\t |          %c %c\n" ,body[4],body[5]);
    printf( "\t |           \n" );
    printf( "\t |           \n" );
    printf( "\t |           \n\n\n");

    // Printing Number of mistakes and All the false characters
    printf("\n\nNumber of Mistakes: %d\n\n", mistakes);
    for (int i = 0; i < mistakes; i++) printf("%c ", falseGuess[i]);
    printf("\n\n");
}

// 
int checkWord(char* selected, char c, char* guessed, int len){
    printf("\n\t");
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if(selected[i] == c){
            guessed[i] = c;
            flag++;
        }
        printf("%c ", guessed[i]);
    }

    printf("\n\n");
    if(c == '\0') return 1;
    return flag;
}

// Setting the initial guessed word to underscores
void setWord(char* guessed, int len){
    for (int i = 0; i < len; i++) guessed[i] = '_';
}
// Decrypting the Selected Name
void decrypt(char * s, int len){
    char alpha[26][2] = { { 'f', 'a' }, { 'a', 'b' }, { 'g', 'c' }, { 'u', 'd' }, { 'n', 'e' }, { 'i', 'f' }, { 'j', 'g' }, { 'q', 'h' }, { 'l', 'i' }, { 'm', 'j' },
                        { 'z', 'k' }, { 'p', 'l' }, { 'k', 'm' }, { 'r', 'n' }, { 's', 'o' }, { 't', 'p' }, { 'v', 'q' }, { 'w', 'r' }, { 'x', 's' }, { 'y', 't' },
                        { 'o', 'u' }, { 'b', 'v' }, { 'c', 'w' }, { 'd', 'x' }, { 'e', 'y' }, { 'h', 'z' } };
    char decrypted[len + 1];
    for (int i = 0; i < len; i++){
        char c;
        for (int j = 0; j < 26; j++){
            if( alpha[j][0] == s[i]) {
                c = alpha[j][1];
                break;
            }
        }
        s[i] = c;
    }
    s[len] = '\0';
}

void checkStatus(){
    char c = '\0';
    while (c != 'y' && c != 'Y')
    {
        printf("\nReady to start the game? Type Y or N :");
        scanf("%c",&c);
        int status;
        while ((status = getchar()) != '\n' && status != EOF) ;
    }
}
int main(){

    // Explaining the Rules
    printf("\n\n");
    printf("\t\t\t\t\t\t\t Welcome to Hangman!!! \n\n");
    printf("Guess the word before you are Hanged!!!\n\n");
    printf("\t RULES: \n\n");
    printf("1. The word to be guessed is a famous website name eg. 'google' .\n");
    printf("2. You can make 6 mistakes after which you will be hanged completly. \n");
    printf("3. All words and inputs are Case Insensitive. \n");
    printf("4. Repeated correct guess will be ignored whereas repeated wrong guess will be counted as a mistake.\n\n\n");

    // List of Websites to choose from
    char websites[50][20] = {"jssjpn", "ifgnassz", "esoyoan", "fkfhsr", "yclyynw", "plrznulr", "lrxyfjwfk",
         "wnuuly", "rnyipld", "nafe", "tlrynwnxy", "clzltnulf", "efqss", "klgwsxsiy", "fttpn", "alrj", "yokapw",
         "voswf", "lkua", "cswutwnxx", "fusan", "gwfljxplxy", "jlyqoa", "uwstasd", "nxtr", "reylknx",
         "xyfgzsbnwipsc", "aag", "cnfyqnw", "qopo", "iplgzw", "xtsylie", "tfetfp", "enpt", "yqnjofwulfr",
         "iswanx", "grr", "cfpkfwy", "aohhinnu", "uflpekflp", "kxr", "rfxf", "cfpkfwy", "yfwjny", "grny",
         "asszlrj", "nyxe", "qoiitsxy", "cfxqlrjysrtsxy", "rfylsrfpjnsjwftqlg"};

    int rand_i = rand_int();
    char *selected = websites[rand_i];  // encrypted word
    int len = strlen(selected);
    selected[len] = '\0';
    char guessed[len];
    char body[6];
    int mistakes = 0;
    char falseGuess[7];
    int totalGuessedChars = 0;
    decrypt(selected, len);
    setWord(guessed, len);  // initializing to underscores


    // Prompting the User if they are Ready to play or not
    checkStatus();

    char inputChar = '\0';
    while (mistakes < 6)
    {
        int guessedChars = checkWord(selected, inputChar, guessed, len);
        if (guessedChars == 0 && inputChar != '\0'){
             falseGuess[mistakes] = inputChar;
             mistakes++;
        }
        displayBody(mistakes, body, falseGuess);
        // Checking win condition
        totalGuessedChars += guessedChars;
        if(totalGuessedChars == len+1) {
            // won();
             printf("You guessed the word correctly!!!\n");
             break;
        }
        if(mistakes == 6) break;
        printf("Guess a character: ");
        while ((inputChar = getchar()) == '\n') ;
    }
    if(mistakes == 6){
        printf("Oops!!! You failed to guess the word correctly. \nThe Word was : %s\n", selected);
    }
}