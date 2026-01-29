//print out number of repeats for each number in array
#include "stdio.h"
#define MAX 5

int main(){
	int list[MAX];
	int repeats[MAX];
	
	

	printf("enter 5 numbers: \n");
	for(int i  = 0; i < MAX; i++){
		scanf("%d", &list[i]);
	} 

	for(int i = 0; i < MAX; i++){
		repeats[i] = 0;
		for(int k = 0; k < MAX; k++)
			if(list[k] == list[i]){
				repeats[i]++;
			}
		}

	for(int i  = 0; i < MAX; i++){
	printf("the number of repeats for %d: %d\n", list[i], repeats[i]);
	} 



}
 
