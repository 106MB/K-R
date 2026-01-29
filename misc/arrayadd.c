#include <stdio.h>
#define MAX 5

int main(){
	int arr1[MAX];
	int arr2[MAX];
	int total[MAX];

	for(int i = 0; i < MAX; i++){
		printf("enter number %d: ", i);
		scanf("%d", &arr1[i]);
	}

	for(int i = 0; i < MAX; i++){
		printf("enter number %d: ", i);
		scanf("%d", &arr2[i]);
	}

	for(int i = 0; i < MAX; i++){
		total[i] = arr1[i] + arr2[i];
		
	}

	for(int i = 0; i < MAX; i++){
		printf("%d\n", total[i]); 
	}


}
