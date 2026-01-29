//program to replace strings of blanks with equal numbers of tabs and blanks
#include <stdio.h>
#define LIM 1024
#define IN 1
#define OUT 0
#define TAB 4
#define TAB_STOPS 3
int getl(char line[], int lim);

int main(){
	int len;
	char line[LIM] = "";

	while((len = getl(line, LIM)) > 0){
		printf("%s", line);
		printf("%d\n", len-1);
	}
}
int getl(char line[], int lim){
	char c;
	int i;
	int blankCount = 0;
	//if OUT of a word AND c is a space
	//start counting the spaces
	//if spaceCount == TAB, replace string of spaces with '\t'
	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; i++){
		if(c == ' '){
			//int j = i; //save place in string
			blankCount++;
			if(blankCount == TAB){
				line[i - (TAB-1)] = '\t';
				i -= (TAB-1); // move back in string;
				blankCount = 0; //reset counter
				printf("tab added\n");
			} else {
				line[i] = c;
			}
		} else {
			line[i] = c;
		}		
	}
	if(c == '\n'){
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return i;
}
