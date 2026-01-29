//rewrite tolower() with conditional expression
#include <stdio.h>

int static tolower(char c);

int main(){
	char c;

	while((c = getchar()) != EOF){
		c = tolower(c);
		putchar(c);
	}


}


int tolower(char c){

	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; 

}
