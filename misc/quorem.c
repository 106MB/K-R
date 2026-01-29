#include <stdio.h>

void quoRem(int x, int y, int* quo, int* rem);

int main(){
	int x, y, quo, rem;
	printf("dividend: ");
	scanf("%d", &x);
	printf("divisor: ");
	scanf("%d", &y);
	quoRem(x, y, &quo, &rem);
	printf("quotient = %d\tremainder = %d\n", quo, rem);
}


void quoRem(int x, int y, int* quo, int* rem){
	*quo = x / y;
	*rem = x % y;
	return;
}

