//File:			lexer.c
//Project:  	lexeical analyzer
//Programmer:	Rick Nygaard
//Date:			03/02/17
//University:	McMurry University
//Course:		COSC-4310 spring 2017
//Instructor:	Mr. Brozovic 
//Complier:		Visual Studio
//Description:	

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //declare variables
    int count = 0;
    //char *store;
    int ch = 0;
    
    /* Check for expected command line arg */
    if (argc != 2) {
        printf("\nMissing Argument\n");
        printf("\nPress ENTER to continue...\n");
        getchar();
        return -1;
    }

    // declare variables
    FILE * datainput;

    /*  Open the input file  */
    datainput = fopen(argv[1], "r");
    if (!datainput) {
        printf("\nError opening input file: \"%s\"!\n", argv[1]);
        printf("\nProgram terminating due to errors!\n");
        printf("\nPress ENTER to continue...\n");
        getchar();
        return -1;
    }

    //program header "save"
    printf("\t\t\t           Lexer\n");
    printf("\t\t\t    COSC-4310 spring 2017\n");
    printf("\t\t\t       Rick Nygaard\n\n");

    printf("%s\n\n", argv[1]);

    int char_remain = 1;

    while (char_remain)
    {
        ch = fgetc(datainput);
        if ((ch == '\n') || (ch == EOF))
        {
            char_remain = 0;
        }
        else
        {
            printf("%c ", ch);
            count++;
            printf(" %d \n", count);
        }

    }


    fclose(datainput);

    // DO NOT REMOVE keeps console open until enter key is pressed
    printf("\n\n\tPress ENTER key to finish\n");
    //getchar(); // consumes newline after numeric input
    getchar(); // waits for Enter key press

    return 0; 

}// end main