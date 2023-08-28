#include<stdio.h>

char alpha[27][3] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, { 'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'q' }, { 'i', 'l' }, { 'j', 'm' },
                     { 'k', 'z' }, { 'l', 'p' }, { 'm', 'k' }, { 'n', 'r' }, { 'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, { 't', 'y' },
                     { 'u', 'o' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, { 'y', 'e' }, { 'z', 'h' } };
char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}


char str[20];

int main() {
    char websites[50][20] = {"google", "facebook", "youtube", "amazon", "twitter", "linkedin", "instagram", "reddit", "netflix", "ebay", "pinterest", "wikipedia", "yahoo", "microsoft", "apple", "bing", "tumblr", "quora",
                    "imdb", "wordpress", "adobe", "craigslist", "github", "dropbox", "espn", "nytimes", "stackoverflow", "bbc", "weather", "hulu", "flickr", "spotify", "paypal", "yelp", "theguardian", "forbes",
                    "cnn", "walmart", "buzzfeed", "dailymail", "msn", "nasa.gov", "walmart", "target", "cnet", "booking", "etsy", "huffpost", "washingtonpost", "nationalgeographic"};
    char str[20];
    int i;
    for (int j = 0; j < 50; j++){
        for (i = 0; websites[j][i]; i++) {
            str[i] = monocipher_encr(websites[j][i]);
        }
        str[i] = '\0';
        printf("\"%s\", ", str);
    }
}


