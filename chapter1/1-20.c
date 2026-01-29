//program to replace tabs with spaces
//output length to confirm
#include <stdio.h>
#define TAB 4
#define MAX 32

int main(){
	int c;
	int count = 0;
	char line[MAX] = "";
	while((c = getchar()) != '\n'  && count < MAX-1){
		if(c == '\t'){
			for(int i = 0; i < TAB; i++){
				line[count] = ' ';
			}
			count += TAB;
		} else {
			line[count] = c;
			count++;
		}
	}
	printf("string: %s\ncount: %d", line, count);
}
