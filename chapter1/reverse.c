//take user input string and output reversed string
#include "stdio.h"
#define LEN 20

int leng(char string[]);
void swap(char* ptr1, char* ptr2);
void reverse(char string[]);

int main(){
	char str[LEN];

	printf("Enter string: ");
	scanf("%s", str);
	reverse(str);
	printf("\n\t%s\n", str);

}

void reverse(char string[]){
	int idx1 = 0;
	int idx2 = leng(string) - 1;
	while (idx2 > idx1){
		swap(&string[idx1], &string[idx2]);
		idx1++;
		idx2--;
		}
}

void swap(char* ptr1, char* ptr2){
	char temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int leng(char string[]){
	int count = 0;
	while(string[count] != '\0'){
		count++;
		}
	return count;
}
