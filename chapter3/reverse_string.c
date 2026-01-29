// Reverse String using for loop
#include <stdio.h>
#include <string.h>
#define LIMIT 40

void reverse_string(char str[]);

int main(){
	char string[LIMIT+1] = "";

	while(fgets(string, LIMIT, stdin) != NULL && string[0] != EOF)
	{
		reverse_string(string);
		printf("%s", string);
	}
}

void reverse_string(char str[])
{	// start end of string before null char and newline
	for(int i = 0, j = strlen(str) - 2; i < j; i++, j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
