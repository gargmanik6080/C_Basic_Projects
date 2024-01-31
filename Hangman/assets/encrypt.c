#include<stdio.h>

char alpha[26][2] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, { 'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'q' }, { 'i', 'l' }, { 'j', 'm' },
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