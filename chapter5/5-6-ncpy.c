// Write strncpy(s,t,n), strncmp(s,t,n), strtncat(s,t,n) functions
// Operate on at most n characters of t on s
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIMIT 200

void strncpy_local(char s[], char t[], int n);

int main(void)
{
	int n = 0;

	while (1){

		char s[LIMIT] = "";
		char t[LIMIT] = "";

		printf("Enter string to copy\n");
		
		if (fgets(t, LIMIT, stdin) != NULL){
			printf("Enter number of characters to copy: ");
			scanf("%d", &n);
			strncpy_local(s,t,n);
		}
		printf("\n%s\n", s);
	}

	

}
void strncpy_local(char s[], char t[], int n)	
{
	char *sptr = s;
	char *tptr = t;

	while (tptr - t < n){
		*sptr++ = *tptr++;
	}
}
