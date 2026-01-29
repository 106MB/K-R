//program to fold line after laster non-blank character
#include <stdio.h>
#include <ctype.h>
#define LIM 1024
#define COL_LIM 10
int getl(char line[], int lim);

int main(){
	int len;
	char line[LIM] = "";

	while((len = getl(line, LIM)) > 0){
		printf("**folded input**\n");
		printf("%s", line);
		printf("%d\n", len-1);
	}
}
int getl(char line[], int lim){
	char c;
	int i;
	int colCount = 0;

	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; i++){
		//fold after column limit
		colCount++;
		if((c == ' ' || c == '\t') && colCount >= COL_LIM){
			line[i] = '\n';
			colCount = 0;		
		}  else {
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



