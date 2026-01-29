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

void reverse_string(char str[])
{	// start end of string before null char 
	for(int i = 0, j = strlen(str) - 1; i < j; i++, j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void itoa(int n, char s[])
{	int sign = 0;

	if ((sign = n) < 0){
		n = -n; // make n positive
	}
	int i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if(sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse_string(s);
}
