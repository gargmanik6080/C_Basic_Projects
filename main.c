#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
    int at_num;
    char symbol[2];
    char name[14];
    double at_mass;
    char type[21];
    double at_radius;
    char discoverer[35];
    int num_shell;
};

struct element getElement(int at_num){
    struct element ele1;
    ele1.at_num = at_num;
    FILE *ptr = fopen("periodic_table.csv", "r");
    char c= fgetc(ptr);
    int i = 0;
    while (c != ',')
    {
        ele1.symbol[i++] = c;
        c = fgetc(ptr);
    }
    fclose(ptr);
    return ele1;
}

int main(){
    struct element ele = getElement(1);
    printf("%s \n", ele.symbol);
}