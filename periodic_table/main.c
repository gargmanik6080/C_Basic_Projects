#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Change the getEle(atnum) to get Ele(FILE* ptr) using gotoline
struct element{
    int at_num;
    char symbol[3];
    char name[15];
    double at_mass;
    char type[21];
    double at_radius;
    char discoverer[35];
    int num_shell;
};

// Function to go to a specific line number
FILE* gotoline(FILE *fp, int pos){
    char c;
    while (pos >= 1)
    {
        c = fgetc(fp);
        if(c =='\n') pos--;
    }
    return fp;
}
//  Function to Retrive the element info from the file by using its Atomic Number
struct element getElement(int at_num){
    struct element ele1;
    ele1.at_num = at_num;
    FILE *ptr = fopen("periodic_table.csv", "r");
    ptr = gotoline(ptr, at_num-1);
    // Element Symbol
    char c= fgetc(ptr);
    int i = 0;
    while (c != ',')
    {
        ele1.symbol[i++] = c;
        c = fgetc(ptr);
    }
    ele1.symbol[i]='\0';
    // Element Name
    i = 0;
    c = fgetc(ptr);
    while (c != ',')
    {
        ele1.name[i++] = c;
        c = fgetc(ptr);
    }
    ele1.name[i] = '\0';
    // Element Atomic Mass
    char tmp_mass[10];
    char *eptr;
    i = 0;
    c = fgetc(ptr);
    while (c != ',')
    {
        tmp_mass[i] = c;
        c = fgetc(ptr);
        i++;
    }
    // Converting String to Double
    ele1.at_mass =(double)strtod(tmp_mass, &eptr);

    // Element Type
    i = 0;
    c = fgetc(ptr);
    while (c != ',')
    {
        ele1.type[i++] = c;
        c = fgetc(ptr);
    }

    // Atomic Radius 
    char tmp_r[10];
    // char *eptr;
    i = 0;
    c = fgetc(ptr);
    while (c != ',')
    {
        tmp_r[i++] = c;
        c = fgetc(ptr);
    }
    // Converting String to Double
    ele1.at_radius =(double)strtod(tmp_r, &eptr);
    // Discoverer of the element
    i = 0;
    c = fgetc(ptr);
    while (c != ',')
    {
        ele1.discoverer[i++] = c;
        c = fgetc(ptr);
    }

    // Number of Shells
    char tmp_shell[10];
    // char *eptr;
    i = 0;
    c = fgetc(ptr);
    while (c != ',' && c!='\n')
    {
        tmp_shell[i++] = c;
        c = fgetc(ptr);
    }
    // Converting String to Int
    ele1.num_shell= atoi(tmp_shell);

    // Closing the file
    fclose(ptr);
    return ele1;
}

void display_element(int atnum){
    struct element ele = getElement(atnum);
    printf("Atomic Number: %d \n", ele.at_num);
    printf("Element Symbol: %s \n", ele.symbol);
    printf("Element Name: %s \n", ele.name);
    printf("Atomic Mass: %lf \n", ele.at_mass);
    printf("Element Type: %s \n", ele.type);
    printf("Atomic Radius: %lf \n", ele.at_radius);
    printf("Discoverer: %s \n", ele.discoverer);
    printf("Number of Shells in the Element: %d \n", ele.num_shell);
}
int main(){
    display_element(118);
}
