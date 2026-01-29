//rotate x by n bits, return x
#include <stdio.h>

int rotate(unsigned x, int n);
int main(){
	unsigned x;
	int  n;

	printf("enter x: ");
	scanf("%u", &x);

	printf("\nenter number of bits to rotate by: ");
	scanf("%d", &n);

	if(n >= 0){
		x = rotate(x, n);
		printf("\nx rotated by %d bits: %u\n", n, x);
	}

}

int rotate(unsigned x, int n){
	int temp = x & ~(~0 << n);
	x = x >> n;
	temp = temp << ((sizeof(x)*8) - n);
	return x | temp;

}
