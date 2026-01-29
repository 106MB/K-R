//write program to reverse input line at a time
#include <stdio.h>
#include <string.h>
#define MAX_LINE 50

void reverse(char string[]);
void swap(char *ptr1, char *ptr2);

int main(){
	
	char string[MAX_LINE];

	//press enter twice to end program
	while(fgets(string, MAX_LINE + 1, stdin) != NULL && strcmp(string, "\n") != 0){
		reverse(string);
		printf("%s\n\n", string);
	}

}


void reverse(char string[]){
	int idx1 = 0;
	int idx2 = strlen(string) - 1;
	while(idx2 > idx1){
		swap(&string[idx1], &string[idx2]);
		idx1++;
		idx2--;
	}
}
void swap(char *ptr1, char *ptr2){
	char temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

}

