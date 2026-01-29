//program to convert string of decimals to int
#include <stdio.h>
#include <stdlib.h>
#define LIM 16

int atoi_local(char s[]);
int main(){
	int num;
	char s[LIM+1] = "";

	if(fgets(s, sizeof(s), stdin) != NULL){
	num = atoi_local(s);
	printf("%d\n", num);

	} else {
		exit(1);
	}
	
}

int atoi_local(char s[]){
	int i, n;
	n = 0;

	for(i = 0; s[i] >= '0' && s[i]<= '9'; i++){
		n = 10 * n + (s[i] - '0');
	}
	return n;
}



