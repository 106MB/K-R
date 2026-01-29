//write a program to print out a histogram of lengths of words from user input
#include <stdio.h>
#define BUFFER 11 //don't use 0 index, or refactor so arr[0] = len(1)
#define IN 1
#define OUT 0
int main(){
	int wordlen[BUFFER];
	char c;
	//itialize wordlen index to 0
	for(int i = 0; i < BUFFER; i++){
		wordlen[i] = 0;
	}

	int len = 0;
	while((c = getchar()) != '\n'){
		if(c == ' ' ||  c == '\t'){
			wordlen[len]++;
			len = 0;
		} else {
			len++;
		}
	} 
	wordlen[len]++;

	printf("\nword length\n");
	for(int i = 1; i < BUFFER; i++){
		printf("%d: ", i);
		for(int j = 0; j < wordlen[i]; j++){
			putchar('*');
		}

	putchar('\n');
	}

}
