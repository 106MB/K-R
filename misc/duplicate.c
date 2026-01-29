//remove duplicates from list
#include "stdio.h"
#define NUM 5

int main(){
	int arr[NUM];

	printf("enter %d numbers: ", NUM);
	for(int i = 0; i < NUM; i++){
		scanf("%d", &arr[i]);
	}

	int nondup;
	int test;
	for(test = 1; test < NUM; test++){

		for(nondup = test - 1; nondup >= 0; nondup--){
			if (arr[nondup] == arr[test]){
				arr[test] = 0;
			}
		}
		
	}

	putchar('\n');
	for(int i = 0; i < NUM; i++){
		if(arr[i] != 0){
		printf("%d ", arr[i]);
		}
	}
	putchar('\n');
}
