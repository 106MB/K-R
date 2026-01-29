//program to check ranges of integral types
//using limits.h libray
#include <stdio.h>
#include <limits.h>

int main(){

	printf("the ranges data types are:\n");
	printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char: %d to %d\n", 0, UCHAR_MAX);
	printf("signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short: %d to %d\n", 0, USHRT_MAX);
	printf("signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("unsigned int: %d to %u\n", 0, UINT_MAX);
	printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long: %d to %lu\n", 0, ULONG_MAX);

}
