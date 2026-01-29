//what is the output?
#include "stdio.h"

int x;
int main(){

	int *px = &x;
	int x = 7;
	*px = 4;
	printf("x = %d\n", x);
}
