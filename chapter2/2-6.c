//return x with n bits that begin at position p
//set to right most n bits of y
//leaving others unchanged
#include <stdio.h>
#include <stdlib.h>

int setbits(unsigned x, int p, int n, unsigned y);
int main(){
	unsigned x, y;
	int p, n;

	printf("enter x: ");
	scanf("%u", &x);

	printf("enter y: ");
	scanf("%u", &y);

	printf("\nenter bit position: ");
	scanf("%d", &p);

	printf("\nenter number of bits: ");
	scanf("%d", &n);

	if((p >= 0) && (n >= 0) && (p >= n)){
		x = setbits(x, p, n, y);
		printf("\nnew x = %u\n", x);
	} else {
		exit(1);
	}

}

int setbits(unsigned x, int p, int n, unsigned y){
	y = (y << (p+1-n)); //shift rightmost n bits of y to position p
	x = x | y;		//set bits in x while preserving all other bits
	return x;
}
