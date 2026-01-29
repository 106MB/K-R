// append first character to end and concatenate -ay at the end
// assume there is enough memory to add extra letters
#include "stdio.h"
#define NUM 50
void pig(char list[]);
int len(char list[]);

int main(){
	char str[NUM];
	printf("enter string: ");
	scanf("%s", str);
	pig(str);
	printf("%s\n",str);
}

void pig(char list[]){
	char first = list[0];
	int size = len(list);
	for(int i = 1; i < size; i++){
		list[i - 1] = list[i];
	}
	list[size-1] = first;
	list[size] = 'a';
	list[size+1] = 'y';
}

int len(char list[]){
	int count = 0;
	for(int i = 0; list[i] != '\0'; i++){
		count++;
	}
	return count;
}

