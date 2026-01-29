///insertion sort algorithm using one array
///O(n) time complexity due to many number of comparisons
#include "stdio.h"
void insertion_sort(int list[]);

int main(){
	int unsorted[] = {10,6,420,69,610,333,106,111,318,0}; 
	for(int i = 0; i < 10; i++){	
		printf("%d ", unsorted[i]);
	}
	printf("\n");
	insertion_sort(unsorted);

	for(int i = 0; i < 10; i++){	
		printf("%d ", unsorted[i]);
	}

	printf("\n");
}

void insertion_sort(int list[]){
	int sorted;			//index
	int unsorted;		//index
	int unsorteditem;	//temp holder

	for(int unsorted = 1; unsorted < 10; unsorted++){
		unsorteditem = list[unsorted];
		for(sorted = unsorted - 1; sorted >= 0 && list[sorted] > unsorteditem; sorted-- ){
			list[sorted+1] = list[sorted];
		
		for(int i = 0; i < 10; i++){	
			printf("%d ", list[i]);
			}	
			printf("\n");
		}
		list[sorted+1] = unsorteditem;
	}
}
