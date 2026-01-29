//return the first location in s1 where any char in s2 first occurs
//return -1, otherwise 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 32
#define NO_CHAR -1
int anychar(char s1[], char s2[]);
int main(){

	char s1[LIM+1] = "";
	char s2[LIM+1] = "";
	int location = NO_CHAR;

printf("enter 2 strings: ");

	if((fgets(s2, sizeof(s2), stdin) != NULL) && (fgets(s1, sizeof(s1), stdin) != NULL)){
		location = anychar (s1, s2);
		if(location != NO_CHAR){
			printf("(string 2) first character match at index: %d\n", location);
		} else {
			printf("no character match\n");
		} 

	} else {
		exit(1);
	}
}
int anychar(char s1[], char s2[]){

	int i, j;
	for(i = 0; s1[i] != '\n'; i++){
		for(j = 0; s2[j] != '\n'; j++){
			if(s1[i] == s2[j]){
				return i;
			}
		}
	}
	return -1;
}
