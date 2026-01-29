//modified longest line program
//correctly print length of input lines
//and as much of the text as possible
#include <stdio.h>
#define MAX_LINE 6

int getl(char line[], int lim);
void copy(char longest[], char line[]);

int main(){
	int len;
	int max;
	char line[MAX_LINE];
	char longest[MAX_LINE];

	max = 0;
	while((len = getl(line, MAX_LINE)) > 0){
			if(len > max){
				max = len;
				copy(longest, line);
			}
		}
		if(max > 0){
			printf("\n*longest line*\n%s", longest);
			printf("\nlength: %d characters\n", max - 1); //exclude null char in length calculation
		}


}


int getl(char line[], int lim){
	int c, i;

	//place char into input up to lim - 1 to save space for null char
	//
	for(i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; i++){
		line[i] = c;
	}
//keep counting if limit has been reached and there is input
//but do not place in string
//if newline has been reached, place the newline and increase count
	int m = 0;
	if(i >= lim-1){
		while((c = getchar()) != '\n' && c != EOF){
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

