#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>		/* everything after # in col 1 ignored! */
#include <math.h>
#include <string.h>


/*
 *	"Sample" source code for COSC-4310, Spring 2017
 *	Programming project #1 -- partial lexical scanner
 *	Author:  Mr. Rich Brozovic
 *
 *	This code compiles without any warnings and executes!
 */

void main(void)
{
	int int0Var, nbr_out_123, year2017 = 0;
	char L26 = 'Z', X3_86Z, Array_of_25_Char[25], tabch;
	double pi = 3.1415926535897932384626433832795;	float flt_IN = -1.0, ResultNBR = 0.0;		/* that was fun!! */

	/*  Print title  */
	printf("Sample Code for COSC-4310\n");	printf("\t Spring 2017\n");
	
	tabch	= '\t';                                                                          tabch = '\'';
	tabch='	';  printf("preceding char literal contains single tab code 0x09, printf starts in col 17\n");
	tabch ='	';  printf("preceding char literal contains single tab code 0x09, printf starts in col 21\n");
	tabch = '	';  printf("preceding char literal contains single tab code 0x09, printf starts in col 21\n");
	tabch =  '	';  printf("preceding char literal contains single tab code 0x09, printf starts in col 21\n");
	tabch  =  '	';  printf("preceding char literal contains single tab code 0x09, printf starts in col 21\n");
	tabch   =  '	';  printf("preceding char literal contains single tab code 0x09, printf starts in col 25\n");
	
	strcpy(Array_of_25_Char,"COSC-4310, Spring 2017");		/*	rolling now, with tab chars in this comment	... */		X3_86Z = tabch;

	/*  Get inputs:  */
	printf("Enter an integer and a float:  ");
	scanf("%d %f", &int0Var, &flt_IN);		getchar();
	/*  two tab chars after first semicolon above */		/* two tab chars between comments */
	nbr_out_123 = (int) ( (long long)int0Var % 1234567890123456789 	+	flt_IN );

	/*  Calculate something
		even though it's really meaningless! */
	ResultNBR = (float)(76.612 - (flt_IN - int0Var) *
		(00.303107 / sqrt(year2017 + int0Var ) - 01.020425 * pi + 043.474677));		/* 2 tab chars after semicolon */

	/*  Print results, which is still meaningless! *
	 *  Also, rest of this comment and following format string contains tab char codes 0x09 instead of \t's -- weird right? /
	 *	/	Fooled you again!!
	 * / Fooled you again!!
	 #	should NOT be a PPDIR!!
	 */
	printf("\n	 Results? =		%7.3f\n	 More? =	%c%d\n\n",	ResultNBR,
			L26,	nbr_out_123);
	printf("\nPress ENTER key to continue	...");	getchar();

/* End of "Sample" source code for program #1 */
}
