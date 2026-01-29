#include "stdio.h"


void swap(int *x, int *y);

int main()
{
	int x = 0;
	int y = 0;
	printf("\nEnter x: ");
	scanf("%d", &x);
	printf("\nEnter y: ");
	scanf("%d", &y);
	printf("\nSwap");
	swap(&x, &y);
	printf("\nx =\t %d\n", x);
	printf("\ny =\t %d\n", y);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
