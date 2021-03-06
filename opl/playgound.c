#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable: 4244)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*global variables*/
char nextChar;

/*function prototype*/
void lex(char ch);
void alpha();
void digit();
void other();



/*defined constants*/
#define MAXLEN 127

//typedef struct 
//{
//    int lineNum;
//    int colNum;
//    char *token;
//    char *lexeme;
//} Lex_t;

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
    int lineNum = 0;
    int colNum = 0;
    int ch = 0;
    //int sentinel = 1;
    //char *token = "PPDIR";
    //char *message = "#define";
    //int ch = 0;
    //Lex_t *lineData;

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

    ////program header "save"
    //printf("\t\t\t           Lexer\n");
    //printf("\t\t\t    COSC-4310 spring 2017\n");
    //printf("\t\t\t       Rick Nygaard\n\n");

    printf("\tFile to parse. %s\n\n", argv[1]);
    while (ch != EOF)
    {
        ch = fgetc(datainput);
        if (ch != '\n')
        {
            colNum++;
        }
        else {
            lineNum++;
            colNum = 1;
        }
        printf("%c %2d", ch, colNum);
        //lex(ch);
    }
    fclose(datainput);

    //printf("(%3d,%3d)\t%s  %s", lineNum, colNum, Lex_t.token, Lex->lexeme);
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
    //fprintf(dataoutput, "(%3d,%3d)\t%s  %s", lineNum, colNum, Lex->token, message);
    fprintf(dataoutput, "\n\n\n    Processed   %2d lines", lineNum);
    fprintf(dataoutput, "\n\t        %2d PPDIRs", lineNum);
    fprintf(dataoutput, "\n\t        %2d IDENTs", lineNum);
    fprintf(dataoutput, "\n\t        %2d KEYWDs", lineNum);
    fprintf(dataoutput, "\n\t        %2d INTGRs", lineNum);
    fprintf(dataoutput, "\n\t        %2d FLOATs", lineNum);
    fprintf(dataoutput, "\n\t        %2d STRNGs", lineNum);
    fprintf(dataoutput, "\n\t        %2d CHARs", lineNum);
    fprintf(dataoutput, "\n\t        %2d CMNTs", lineNum);



    // DO NOT REMOVE keeps console open until enter key is pressed
    printf("\n\n\tPress ENTER key to finish\n");
    //getchar(); // consumes newline after numeric input
    getchar(); // waits for Enter key press

    return 0;

}

//void lex(char ch)
//{
//    char *token="";
//    switch (ch)
//    {
//    case '#':
//        strcpy(token, "PPDIR");
//        break;
//    case '/':
//        strcpy(token, "IDENT");
//        break;
//
//    default:
//        break;
//    }
//    printf("%s", token);
//}
//
//void alpha(char ch)
//{
//    printf("%c", ch);
//}
