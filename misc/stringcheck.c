//check if two strings are equal
#include "stdio.h"
#define NUM 20

int len(char arr[]);
int check(char a[], char b[]);

int main(){
	char a[NUM], b[NUM];
	printf("enter 2 strings: ");
	scanf("%s %s", a, b);
	int final = check(a, b);
	printf("\n%d\n", final);
}

int len(char arr[]){
	int count = 0;
	while(arr[count] != '\0'){
		count++;
	}
	return count;
}

int check(char a[], char b[]){
	int sizeA = len(a);
	int sizeB = len(b);

	if(sizeA == sizeB){
		for (int i = 0; a[i] != '\0'; i++){
			if(a[i] < b[i]){
				return 1;
			} else if( a[i] > b[i]){
				return 2;
			}
		}
	return 0;
	} else if(sizeA < sizeB){
		for (int i = 0; a[i] != '\0'; i++){
			if(a[i] < b[i]){
				return 1;
			} else if( a[i] > b[i]){
				return 2;
			}else{
				return 1;
			}
		}
	} else{
		for (int i = 0; b[i] != '\0'; i++){
			if(a[i] < b[i]){
				return 1;
			} else if( a[i] > b[i]){
				return 2;
			} else{
				return 2;
			}
		}
		
	}
return 0;
}
