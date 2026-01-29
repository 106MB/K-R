#include <stdio.h>
#define IN 1
#define OUT 0

int main(){

	char c;
	int wordcount = 0;
	int charcount = 0;
	int linecount = 0;
	int state = OUT;
	while((c = getchar()) != EOF){
		charcount++;

		if (c == '\n'){
			linecount++;
		}
		if(c == ' ' || c == '\t' || c == '\n'){
			state = OUT;
		} else if (state == OUT){
			state = IN;
			wordcount++;
		}
	}

		printf("character count: %d\nword count: %d\nline count: %d\n", charcount, wordcount, linecount);
}
