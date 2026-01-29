// Write a pointer version of strcat()

#include <stdio.h>
#include <string.h>
#define LIMIT 100

static void strcat_local(char s1[], char s2[], int n);

int main(void)
{
	char s1[LIMIT] = "";	
	char s2[LIMIT] = "";	
	int n = 0;

	while (1){
	printf("= Enter two strings =\n");
	if(fgets(s1, LIMIT, stdin) != NULL && fgets(s2, LIMIT, stdin) != NULL){
		printf("Enter number of characters to cat: ");
		scanf("%d", &n);
		strcat_local(s1, s2, n);
	}
	printf("\nOutput: %s\n", s1);
	}	
}

// Take 2 strings
// Find where first ends
// Use end point of first string as starting point for second
// s1 must be big enough
// Output: Void, or pointer to beginning of new string 
static void strcat_local(char s1[], char s2[], int n)
{
	if ((strlen(s1) + strlen(s2)) < LIMIT){
		char *s1ptr = s1;
		char *s2ptr = s2;

		// Find end of s1
		while (*s1ptr != '\n'){
			s1ptr++;
		}

		while (s2ptr - s2 < n){
			*s1ptr++ = *s2ptr++;
		}
	} else {
		printf("\nERROR: Limit Reached\n");
	}
}


