/************************
 * David Sellers
 * CS 415
 * Program 1
 * Create a command line parser in the C/C++ 
 * language.
************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * cstrings, c++ strings, algorithms library
 *
 */
char ** parseCommandLine(char * aCommandLine);

int main(int argc, char *argv[]) {

    char cmd[256];
    int num = 7;

    printf("***********Begin***********\n");
    for(int i = 0; i < argc; i++) {
         printf("%s\n", argv[i]);
         
    }

    scanf("%255[^\n]", cmd);
    printf(cmd);
//     printf("Enter your name: ");
//     scanf("%19s", name);
//    
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     printf("\n%s\n%d\n", name, num);
    parseCommandLine("ls -al | grep howdy > data");
    printf("************End************\n");

    return 0;
}

char ** parseCommandLine(char * aCommandLine) {
    // Delimiters < > >> << |
    int start = 0;
    //number of command line arguments
    int n = 10; 

    int* ptr = (int*)calloc(n, sizeof(int));
    for(int i = 0; i <  strlen(aCommandLine); i++) {
        if( aCommandLine[i] == '<') {
            printf("Found special delimiter < at %d.\n", i);
        }
        else if( aCommandLine[i] == '|') {
            printf("Found special delimiter | at %d.\n", i);
        }
        else if( aCommandLine[i] == '>') {
            printf("Found special delimiter > at %d.\n", i);
        }
        else if(aCommandLine[i] == 'l') {
            printf("Comparison works!\n");
        }
        else {
            printf("else Found  %c at %d.\n", aCommandLine[i], i);
        }
    }
}

