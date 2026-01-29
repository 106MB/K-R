//remove all occurences of chars in string 2 from string 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 32
void squeeze(char s1[], char s2[]);
int main(){

	char s1[LIM+1] = "";
	char s2[LIM+1] = "";

printf("choose characters to be deleted: ");

	if((fgets(s2, sizeof(s2), stdin) != NULL) && (fgets(s1, sizeof(s1), stdin) != NULL)){
		squeeze(s1, s2);
		printf("%s", s1);
	} else {
		exit(1);
	}
}


void squeeze(char s1[], char s2[]){

	int i, j, k;

	for(i = 0; s2[i] != '\0'; i++){
		printf("deleting %c\n", s2[i]);
		for(j = k = 0; s1[j] != '\0'; j++){
			if(s1[j] != s2[i]){
				s1[k++] = s1[j];
			}
			printf("%s\n", s1);
		}

	}

	s1[j] = '\0';

}
