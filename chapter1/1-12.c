//write a program that prints its input one word per line
#include <stdio.h>

int main(){
	char c;
	
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t'){
			putchar('\n');
		} else {
			putchar(c);
		}
	}

}
