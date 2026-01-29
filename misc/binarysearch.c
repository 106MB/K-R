//perform binary search on sorted array
//return 1 if item found, return -1 otherwise
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
		printf("\nitem found\n");
		
	}


}
int binsearch(int item, int list[], int start, int end){
	int middle = (start + end) / 2;
	
	if(end < start){
		//subarry size = 0; item not found
		return -1;
	} else if(list[middle] == item){
		//item found
		return middle;
	}else if(item > list[middle]){
		return binsearch(item, list, middle+1, end);
	} else{
		return binsearch(item, list, start, middle-1);
	}


}
void insertsort(int list[]){
	int sorted;
	int unsorted;
	int temp;

	for(int unsorted = 1; unsorted < NUM; unsorted++){
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

