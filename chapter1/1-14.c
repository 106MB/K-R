//write a program to print out a histogram of lengths of words from user input
#include <stdio.h>
#include <ctype.h>
#define BUFFER 26 

int main(){
	int charbuff[BUFFER];
	char c;
	//intialize charbuff indices to 0
	for(int i = 0; i < BUFFER; i++){
		charbuff[i] = 0;
	}

	//add to array only if within bounds to stop memory leaks
	while((c = getchar()) != '\n'){
		c =	tolower(c);
		if(c != ' ' &&  c != '\t' && (c - 'a') < BUFFER && (c - 'a') >= 0){
			charbuff[c - 'a']++;
		} 
	} 
	//print frequency numbers
	printf("\ncharacter frequency\n");
	for(int i = 'a'; i <= 'z'; i++){
		printf("%c ", i);
	}
	putchar('\n');

	for(int i = 0; i < BUFFER; i++){
		printf("%d ", charbuff[i]);
	}
	putchar('\n');

	//print histogram
	printf("\ncharacter histogram\n");
	for(int i = 'a'; i <= 'z'; i++){
		printf("%c: ", i);
		for(int j = 0; j < charbuff[i - 'a'] ; j++ ){
			putchar('*');	
			}
	putchar('\n');
	}

}
