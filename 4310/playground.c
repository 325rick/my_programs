#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE 127

void prompt();

int main(int argc, char *argv){
    argc =2;
/* Check for expected command line arg */
    if (argc != 2) {
        printf("\nMissing Argument\n");
        printf("\nPress ENTER to continue...\n");
        getchar();
        exit(1);
    }
// variables
int i = 0;
char *ch;

printf("Type -1 to Exit::");
printf("Enter command::");

do{
  prompt();
  fgets(ch, MAXSIZE, stdin);
  printf("%s", ch);
  i = atoi(ch);

} while(i != -1);

return 0;
}
void prompt(){
printf("::");
}
