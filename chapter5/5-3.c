// Write a pointer version of strcat()

#include <stdio.h>
#include <string.h>
#define LIMIT 100

static void strcat_local(char s1[], char s2[]);

int main(void)
{
	char s1[LIMIT] = "";	
	char s2[LIMIT] = "";	

	while (1){
	printf("= Enter two strings =\n");
	if(fgets(s1, LIMIT, stdin) != NULL && fgets(s2, LIMIT, stdin) != NULL){
		strcat_local(s1, s2);
	}
	printf("\nOutput: %s\n", s1);
	}	
}

// Take 2 strings
// Find where first ends
// Use end point of first string as starting point for second
// s1 must be big enough
// Output: Void, or pointer to beginning of new string 
static void strcat_local(char s1[], char s2[])
{
	if ((strlen(s1) + strlen(s2)) < LIMIT){
		char *s1ptr = s1;
		char *s2ptr = s2;

		// Find end of s1
		while (*s1ptr != '\n'){
			s1ptr++;
		}

		while (*s2ptr != '\0'){
			*s1ptr++ = *s2ptr++;
		}
	} else {
		printf("\nERROR: Limit Reached\n");
	}
}


