// Create a swap(t,x,y) macro to interchange two arguments with type t
#include "stdio.h"
#define swap(t,x,y) (t = x, x = y, y = t)

int main()
{
	int x = 6;
	int y = 10;
	int temp = 0;
	swap(temp,x,y);
	printf("x = %d\ny = %d\n", x, y);

}
