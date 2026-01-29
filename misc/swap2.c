//using pointers in function calls
#include "stdio.h"

void swap(int* ptr1, int* ptr2);

int main(){
	int num1, num2;
	int* test1 = &num1;
	int* test2 = &num2;

	printf("insert 2 numbers to be swapped: ");
	scanf("%d %d", &num1, &num2);

	printf("\nbefore: %d %d\n", num1, num2 );
	swap(test1, test2);
	printf("\nafter: %d %d\n", num1, num2 );


}

void swap(int* ptr1, int* ptr2){
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

