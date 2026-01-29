//iterative binary search
#include "stdio.h"
#define NUM 5

int binsearch(int item, int list[], int start, int end);
void insertsort(int list[]);

int main(){
	int arr[NUM];
	int item;
	printf("insert list of items: ");
	for(int i = 0; i < NUM; i++){
		scanf("%d", &arr[i]);
	}
	insertsort(arr);
	printf("\ninsert search item: ");
	scanf("%d", &item);
	int ack = binsearch(item, arr, 0, NUM-1);

	if(ack == -1){
		printf("\nitem not found\n");
	} else {
		printf("\nitem found at index: %d\n", ack);
		
	}


}
int binsearch(int item, int list[], int start, int end){
	int mid = (start + end) / 2;
	while(start <= end && item != list[mid])
	{
		mid = (start + end) / 2;

		if(item < list[mid])
		{ 
			end = mid - 1;
		} else
		{ 
			start = mid + 1;
		}
	}
	if(item == list[mid]){
		return mid;
	} else {
		return -1; //item not found
	}
}
void insertsort(int list[]){
	int sorted;
	int unsorted;
	int temp;

	for(unsorted = 1; unsorted < NUM; unsorted++){
		temp = list[unsorted];

		for(sorted=unsorted-1; list[sorted] > temp && sorted >= 0; sorted--){
			list[sorted+1] = list[sorted];
		}
		list[sorted+1] = temp;
	}

	putchar('\n');
	for(int i = 0; i < NUM; i++){
		printf("%d ", list[i]);
	}
	putchar('\n');
}

