//calculate length of input string
#include "stdio.h"
#define MAX_STRING 20

int stringlength(char string[]);

int main(){
	char str[20];
	int length;

	printf("input string: ");
	scanf("%s", str);
	
	length = stringlength(str);


	printf("\ninput length: %d\n", length);
	

}

int stringlength(char string[]){
	int	idx = 0;
	while(string[idx] != '\0'){
		idx++;
		}
	return idx;
}
