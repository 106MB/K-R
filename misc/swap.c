#include <stdio.h>

void swap(int* xptr, int* yptr);

int main(){
	int x;
	int y;

	printf("choose 2 values to swap: ");
	scanf("%d %d", &x, &y);
	printf("x = %d\t y = %d\n", x, y);
	swap(&x, &y);
	printf("x = %d\t y = %d\n", x, y);
}

void swap(int* xptr, int* yptr){
	int temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
}
