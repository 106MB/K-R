// Modify entab from chapter 1 to use command line arguments to set tab stops
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LIM 60
#define DEFAULT_TAB 4
int getl(char line[], int lim, int TAB);

int main(int argc, char **argv){
	int len;
	char line[LIM] = "";
	
	if (argc == 1){
		// no argument
		while((len = getl(line, LIM, DEFAULT_TAB)) > 0){
			printf("%s", line);
			printf("%d\n", len-1);
		}
	} else if (argc == 2){
		while((len = getl(line, LIM, atoi(*++argv)))> 0){
			printf("%s", line);
			printf("%d\n", len-1);
		}
	} else {
		printf("Useage: enter amount of tab stops in first argument\nDefault: 4");
	}
	return 0;

}
int getl(char line[], int lim, int TAB){
	char c;
	int i;
	int blankCount = 0;
	//if OUT of a word AND c is a space
	//start counting the spaces
	//if spaceCount == TAB, replace string of spaces with '\t'
	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; i++){
		if(c == ' '){
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
			blankCount = 0; //reset counter
		}		
	}
	if(c == '\n'){
		line[i++] = '\n';
	}
	line[i] = '\0';
	return i;
}

