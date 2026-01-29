//remove comments from program
#include <stdio.h>
#include <ctype.h>
#define LIM 1024
#define IN 1
#define OUT 0
int getl(char line[], int lim);

int main(){
	int len;
	char line[LIM] = "";

	while((len = getl(line, LIM)) > 0){
		printf("**without comments**\n");
		printf("%s", line);
		printf("%d\n", len-1);
	}
}
int getl(char line[], int lim){
	char c;
	int i;
	int state = OUT;
	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; i++){
		if(c == '/' &&  ((c = getchar()) == '/' || c  == '*')){
			line[i] = '\n';
			state = IN;
		} else if (state == OUT) {
			line[i] = c;
		}  		
	}
	if(c == '\n'){
		line[i] = '\n';
		i++;
		state = OUT;
	}
	line[i] = '\0';
	return i;
}



