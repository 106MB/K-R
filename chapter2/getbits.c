//return the n bits from position p, right adjusted.
#include <stdio.h>

int getbits(unsigned x, int p, int n);
int main(){
	unsigned x;
	int p, n;

	printf("enter x: ");
	scanf("%u", &x);

	printf("\nenter bit position: ");
	scanf("%d", &p);

	printf("\nenter number of bits: ");
	scanf("%d", &n);

	if((p >= 0) && (n >= 0) && (p >= n)){
		x = getbits(x, p, n);
		printf("\nbits from position %d to %d: %u\n", p, p+1-n, x);
	}

}

int getbits(unsigned x, int p, int n){
	return (x >> (p+1-n) & ~(~0 << n));

}
