//use array in a function

//calculate average of array
int average(int array[]);

#include "stdio.h"
#define SIZE 5

int main(){
	int nums[SIZE];
	int avg;
	printf("enter 5 numbers: \n");
	for (int i = 0; i < SIZE;  i++){
		scanf("%d", &nums[i]);
	}
	
	avg = average(nums);
	printf("\naverage: %d\n", avg);


}

int average(int array[]){
	int sum = 0;
	for (int i = 0; i < SIZE;  i++){
	sum += array[i];
	}
	return (sum / SIZE);

}
