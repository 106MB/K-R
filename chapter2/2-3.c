//program to convert string of hex to int
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LIM 16

int htoi_local(char s[]);
int main(){
	int num;
	char s[LIM+1] = "";

	if(fgets(s, sizeof(s), stdin) != NULL){
	num = htoi_local(s);
	printf("%d\n", num);

	} else {
		exit(1);
	}
	
}

int htoi_local(char s[]){
	int i, n;
	n = 0;

	for(i = 0; (s[i] >= '0' && s[i]<= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); i++){
		if (isdigit(s[i])){
			n = 16 * n + (s[i] - '0');
		} else {
		s[i] = tolower(s[i]);
			n = 16 * n + (s[i] - 'a' + 10);
		}
	}
	return n;
}



