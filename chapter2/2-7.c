//return x with n bits at position p inverted, everything else unchanged
#include <stdio.h>

int invert(unsigned x, int p, int n);
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
		x = invert(x, p, n);
		printf("\nx with bits from position %d to %d inverted: %u\n", p, p+1-n, x);
	}

}

int invert(unsigned x, int p, int n){
	int mask = (~(~0 << n)) << (p+1-n); //create mask of n rightmost bits set to 1, shift that mask to proper position
	printf("mask = %d\n", mask);	
	return x  ^ mask;					//xor'ing bits with 1 is the only situation where bits are inverted, 0 keeps the bits	
}
