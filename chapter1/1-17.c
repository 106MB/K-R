//print all input lines longer than 80 chars
//using strcat
#include <stdio.h>
#include <string.h>
#define MAX_LINE 1000
#define MAX_CHARS 10

int getl(char line[], int lim);
void copy(char longest[], char line[]);

int main(){
	int len;
	char line[MAX_LINE];
	char longest[MAX_LINE] = "";

	while((len = getl(line, MAX_LINE)) > 0){
			if(len > MAX_CHARS){
				strcat(longest, line);
			}
		}
			printf("\n\n*lines longer than %d chars, including newline*\n%s", MAX_CHARS, longest);
			
	


}


int getl(char line[], int lim){
	int c, i;

	//place char into input up to lim - 1 to save space for null char
	//
	for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++){
		line[i] = c;
	}
//keep counting if limit has been reached and there is input
//but do not place in string
//if newline has been reached, place the newline and increase count
	int m = 0;
	if(i >= lim-1){
		while((c = getchar()) != EOF && c != '\n'){
			m++;
		}
	}
	if (c == '\n'){
		line[i] = c;
		i++;
	} 
	line[i] = '\0';
	return (i + m);


}
void copy(char longest[], char line[]){
	int i = 0;

	while((longest[i] = line[i]) != '\0'){
		i++;
	}
}

