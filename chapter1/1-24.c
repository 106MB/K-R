//program to check unbalanced quotes
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
		printf("%s", line);
		printf("%d\n", len-1);
	}
}
int getl(char line[], int lim){
	char c;
	int i;
	int state = OUT;
	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; i++){
		if(c == '"' && state == OUT){
			state = IN;
			line[i] = c;	
		} else if(c == '"' && state == IN){
			state = OUT;
			line[i] = c;
		}  else {
			line[i] = c;
			state = OUT;
		}


	}
	//error
	if(c == '\n' && state == IN){
		printf("unbalanced quotes\n");
		line[i] = '\n';
		i++;
	} else if(c == '\n'){
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return i;
}



