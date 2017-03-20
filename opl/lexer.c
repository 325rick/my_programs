#define _CRT_SECURE_NO_DEPRECATE

/*
Lexical analyzer
Rick Nygaard
COSC-4310
Mr. Brozovic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

	if (argc != 2)
	{
		printf("Missing arguements");
		exit (1);
	}

	FILE *datainput;
	datainput = fopen(argv[1],"r");

	printf("%s\n\n", argv[1]);
	//printf("%s\n\n", datainput);

	printf("\nPress Enter key to finish");
	//getchar(); //consumes newline after input
	getchar(); // waits for Enter key press

	return 0;
}//end main