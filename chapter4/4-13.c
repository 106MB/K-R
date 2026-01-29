#include <stdio.h>
#include <string.h>
#define LIMIT 40

void reverse_string(char str[], int i, int j);

// Recursive Reverse String
int main(){
	char string[LIMIT+1] = "";

	while(fgets(string, LIMIT, stdin) != NULL && string[0] != EOF)
	{
		// start end of string before null char and newline
		reverse_string(string, 0, strlen(string) - 2);
		printf("%s", string);
	}
}

void reverse_string(char str[], int i, int j)
{
	if (i >= j) 
	{
		return;
	} else 
	{	
		 char temp = str[i];
		 str[i++] = str[j];
		 str[j--] = temp;
		 reverse_string(str,i,j);
	}
}

