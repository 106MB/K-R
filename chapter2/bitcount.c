//count the number of 1-bits in an integer argument
#include <stdio.h>


int bitcount(unsigned x);

int main(){
	unsigned x;
	int bits;

	printf("Enter x: ");
	scanf("%u", &x);

	bits = bitcount(x);

	printf("Number of 1-bits in x: %d\n", bits);
}

int bitcount(unsigned x){

int b = 0;
for (b = 0; x !=; x >>= 1){
	if (x & 01){
		b++;
	}
}
return b;
}
