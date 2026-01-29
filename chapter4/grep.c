#include <stdio.h>
#include <string.h>
#define LIMIT 1000

int strindex(char s[], char t[]);


// Print starting index of first occurence of pattern
int main(){

	char line[LIMIT+1] = "";
	char pattern[LIMIT+1] = "";
	printf("enter pattern to match: ");
	if (fgets(pattern, LIMIT, stdin) != NULL)
	{	// Remove New Line
		pattern[strlen(pattern)-1] = pattern[strlen(pattern)];

		while (fgets(line, LIMIT, stdin) != NULL)
		      	// Find first occurence	
		{	int idx = strindex(line, pattern);
			if (idx >= 0) 
			{
				printf("\nfirst occurence at index: %d\n", idx);	
			}
		}
	}

}

// Return first index of t in s, -1 if none
int strindex(char s[], char t[]){
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		// For every character in string, compare it with the beginning of the pattern
		// If the characters are the same, continue with pattern match
		// If k == '\0'; pattern is matched; return current place in string
		// If not, search next character in string
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0'){
			return i;
		}
	}
	return -1;


}
