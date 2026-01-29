//remove all occurences of char c from string
#include <stdio.h>
#include <stdlib.h>
#define LIM 32
void squeeze(char s[], int c);
int main(){

	char c;
	char s[LIM+1] = "";

printf("choose character to delete followed by string: ");
scanf("%c", &c);

	if(fgets(s, sizeof(s), stdin) != NULL){
		squeeze(s, c);
		printf("%s", s);
	} else {
		exit(1);
	}
}


void squeeze(char s[], int c){

	int i, j;

	for(i = j = 0; s[i] != '\0'; i++){

		if(s[i] != c){
			s[j++] = s[i];
		}
	}
	s[i] = '\0';

}
