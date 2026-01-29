// Return the index of the first occurence of string t in s
// Using pointers

#include <stdio.h>
#include <string.h>
#define LIMIT 200

static int string_index(char *s, char *t);

int main(void)
{
	char sar[LIMIT] = "";
	char tar[LIMIT] = "";
	char *s = sar; 
	char *t = tar; // Create pointers to data structure
	
	while (*s != EOF && *t != EOF){
		printf("Enter first string: ");
		if (fgets(s, LIMIT, stdin) != NULL){
			printf("Enter second string: ");
			if (fgets(t, LIMIT, stdin) != NULL){\
				s[strcspn(s, "\n")] = 0;	// remove newlines		
				t[strcspn(t, "\n")] = 0;	
				int index = string_index(s,t);
				if (index == -1){
					printf("\nString not found!\n");
				} else {
					printf("String found at index: %d\n", index);
				}
			}
		}
	}
}
// Loop through s until null char
// Loop through t until null char or t != s
// If t is longer than 0 chars and t  is null char, return s - start
static int string_index(char *s, char *t)
{
	char *start = s; // Save head of s
	while (*s != '\0'){
		char *temps = s, *tempt = t;

		for (; *tempt != '\0' && *temps == *tempt; temps++, tempt++){
			// do nothing
		}
		
		if((tempt - t) > 0 && *tempt == '\0'){
			return s - start;
		}

		s++;
	}
	return -1;
}
