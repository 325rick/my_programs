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
#include <ctype.h>
/*global variables*/
char nextChar;
/*function prototype*/

void getNonBlank();
/*defined constants*/
#define MAXLEX 127;

int main(int argc, char *argv[])
{
    /* Check for expected command line arg */
    if (argc != 2) {
        printf("\nMissing Argument\n");
        printf("\nPress ENTER to continue...\n");
        getchar();
        return -1;
    }

    //declare variables
    /*int count = 0;*/
    int lineNum = 10;
    int colNum = 10;
    char *token = "PPDIR";
    char *message = "#define";
    //int ch = 0;

    // declare variables
    FILE *datainput, *dataoutput;

    /*  Open the input file  */
    datainput = fopen(argv[1], "r");
    dataoutput = fopen("lexoutput.txt", "w");
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

    printf("\tFile to parse. %s\n\n", argv[1]);

    printf("(%3d,%3d)\t%s  %s", lineNum, colNum, token, message);
    /*Summary*/
    printf("\n\n\n    Processed   %2d lines", lineNum);
    printf("\n\t        %2d PPDIRs", lineNum);
    printf("\n\t        %2d IDENTs", lineNum);
    printf("\n\t        %2d KEYWDs", lineNum);
    printf("\n\t        %2d INTGRs", lineNum);
    printf("\n\t        %2d FLOATs", lineNum);
    printf("\n\t        %2d STRNGs", lineNum);
    printf("\n\t        %2d CHARs", lineNum);
    printf("\n\t        %2d CMNTs", lineNum);

    /*Output report to text file*/
    if (!dataoutput)
    {
        printf("\n\tOppen file error!\n");
        printf("\tProgram will close.\n Press enter to continue.\n");
        getchar();
        exit(1);
    }
    fprintf(dataoutput, "(%3d,%3d)\t%s  %s", lineNum, colNum, token, message);
    fprintf(dataoutput, "\n\n\n    Processed   %2d lines", lineNum);
    fprintf(dataoutput, "\n\t        %2d PPDIRs", lineNum);
    fprintf(dataoutput, "\n\t        %2d IDENTs", lineNum);
    fprintf(dataoutput, "\n\t        %2d KEYWDs", lineNum);
    fprintf(dataoutput, "\n\t        %2d INTGRs", lineNum);
    fprintf(dataoutput, "\n\t        %2d FLOATs", lineNum);
    fprintf(dataoutput, "\n\t        %2d STRNGs", lineNum);
    fprintf(dataoutput, "\n\t        %2d CHARs", lineNum);
    fprintf(dataoutput, "\n\t        %2d CMNTs", lineNum);

    fclose(datainput);
    fclose(datainput);
    // DO NOT REMOVE keeps console open until enter key is pressed
    printf("\n\n\tPress ENTER key to finish\n");
    //getchar(); // consumes newline after numeric input
    getchar(); // waits for Enter key press

    return 0;

}// end main
void getNonBlank()
{
    while (isspace(nextChar))
    {

    }

}