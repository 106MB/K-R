// Write the function strend()
// Return 1 if the string t occurs at the end of s
// 0, otherwise

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIMIT 100

bool strend(char s1[], char s2[]);

int main(void)
{

	char s1[LIMIT] = "";	
	char s2[LIMIT] = "";
	bool result  = false;	

	while (1){
	printf("= Enter two strings =\n");
	if(fgets(s1, LIMIT, stdin) != NULL && fgets(s2, LIMIT, stdin) != NULL){
		result = strend(s1, s2);
	}
	printf("\nOutput: %d\n", result);
	}	

}
bool strend(char s1[], char s2[])
{
	int index = 0;
	if ((index = (strlen(s1)) - strlen(s2)) > 0){
		char *s1ptr = s1 + index;
		char *s2ptr = s2;

		for(; *s1ptr == *s2ptr; s1ptr++, s2ptr++){
			if(*s1ptr == '\0'){
				return true;
			}
			
		}
			return false;
	}

	return false;
}
