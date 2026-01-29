//modify getline so that it doesn't use && or ||
#include <stdio.h>
#define MAX_LINE 1000

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
		}


}


int getl(char line[], int lim){
	int c, i;

	for(i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; i++){
				line[i] = c;
			}
	if(c == '\n'){
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;


}
void copy(char longest[], char line[]){
	int i = 0;

	while((longest[i] = line[i]) != '\0'){
		i++;
	}
	
}

