// write a faster version of bitcount.c
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
	while(x != 0){
		b++;
		x &= (x-1);
	}	
return b;
}
