// Generalized atoi() using for loop
#include <stdio.h>
#include <ctype.h>

#define LIMIT 50

int atoi(char s[]);

int main(){

	char s[LIMIT] = "";

	while(fgets(s, LIMIT - 1, stdin) != NULL && s[0] != EOF)
	{
		int conversion = atoi(s);
		printf("%d\n", conversion);
	}
}


int atoi(char s[])
{
	int i = 0, n = 0, sign = 0;

	for (; isspace(s[i]); i++){;} // Skip leading whitespace
	
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-') {i++;} // Skip sign indicator
	
	for(; isdigit(s[i]); i++){
		n = 10 * n + (s[i] - '0');
	}
	return sign * n;
}
