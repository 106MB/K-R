// Write getline using pointers
// read a line into s, return length
#include <stdio.h>
#define LIMIT 300

int getline_ptr(char *s, int lim);


int main(void)
{
	char s[LIMIT] = "";
	int len = 0;

	while ((len = getline_ptr(s, LIMIT)) > 0){
		printf("%s", s);
		printf("Length of string: %d\n", len - 1);
	}

}

// Write from getchar to s,  up to the limit
// If newline is reached, end traveral
// Return difference between start address and end address to get strlen
int getline_ptr(char *s, int lim)
{
	int c = 0; // input char
	char *start = s; //start of array placeholder
	for (; s < s + (lim - 1) && (c=getchar()) != EOF && c != '\n';){
		*s++ = c;
	}
	if (c == '\n'){
		*s++ = c;
	}
	return s - start; 
}
