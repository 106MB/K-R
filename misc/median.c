//find median of array
#include "stdio.h"
#define NUMS 5

void insertsort(int list[]);
double median(int list[]);

int main(){
	int arr[NUMS];
	printf("insert %d items: ", NUMS);
	for(int i=0; i<NUMS; i++){
		scanf("%d", &arr[i]);
	}
	double med = median(arr);
	printf("\nmedian = %lf\n", med);

}

void insertsort(int list[]){
	int unsorted; //index
	int sorted;	  //index
	int temp;	  //temp hold
	
	for(unsorted = 1; unsorted < NUMS; unsorted++){
		temp = list[unsorted];

		for(sorted = unsorted-1; list[sorted] > temp && sorted >= 0; sorted--){
			list[sorted+1] = list[sorted];
			
		}
		
		list[sorted + 1] = temp;
	}

	putchar('\n');
	for(int i = 0; i < NUMS; i++){
		printf("%d ", list[i]);

	}
	putchar('\n');
}

double median(int list[]){
	insertsort(list);

	int idx = NUMS/2;
	if( (NUMS%2) != 0){
		return list[idx];
	} else{
		return (list[idx] + list[idx-1]) / 2.0; 
	}
}
