#include "stdio.h"
#define ALLOCSIZE 10600

static char allocbuf[ALLOCSIZE] = "";
static char *allocp = allocbuf;
char *alloc (int n);
void afree (char *p);
int main()
{
	int space = 0;
	char *rtn = NULL;
	while (allocp <= allocbuf + ALLOCSIZE){

		printf("Avaialble space = %ld\n", allocbuf+ALLOCSIZE-allocp);
		printf("Allocate how many blocks? ");
		scanf("%d", &space);
		rtn = alloc(space);

	}
}

// Alloc n chars if enough space is available
char *alloc (int n)
{	// Get size of remaining space
	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;	
		return allocp - n;
	} else {
		return 0;
	}	
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE){
		allocp = p;
	}
}

