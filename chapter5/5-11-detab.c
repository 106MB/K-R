// Modify programs entab and detab from chapter 1 to accept a list of tab stops
// as arguments
// detab
// program to replace tabs with spaces 
// output length and string to confirm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 60
#define DEFAULT_TAB 4

void entab(int tab);

int main(int argc, char **argv){
	if (argc == 1){
		// no argument
		printf("default mode\n");
		detab(DEFAULT_TAB);
	} else if (argc == 2){
		printf("other\n");
		detab(atoi(*++argv));
	} else {
		printf("Useage: enter amount of tab stops in first argument\nDefault: 4");
	}
	return 0;
}

void detab(int TAB)
{
	char c;
        int count = 0;
        char line[MAX] = "";
        while((c = getchar()) != '\n' && count < MAX-1){
		if(c == '\t'){
			for(int i = 0; i < TAB; i++){
                                 line[count++] = ' ';
                         }
                 } else {
                         line[count] = c;
                         count++;
                 }
        }
	line[count] = '\0';
        printf("string: %s\ncharacter count: %d", line, count);
}
