// convert n to characters in s
#include <stdio.h>
#include <string.h>
#define LIMIT 40

void reverse_string(char str[]);
void itoa(int n, char s[]);

int main(){
	char string[LIMIT+1] = "";
	int n = 0;
	printf("enter an integer: ");
	scanf("%d", &n);
	itoa(n, string);
	printf("%s\n", string);
}


void itoa(int n, char s[])
{
	static int i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		n = -n;
	}

	if (n / 10)
	{
		itoa(n/10, s);
	}

	s[i++] = (n % 10 + '0');	 
}
