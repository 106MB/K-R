// convert n to characters in s using base b
#include <stdio.h>
#include <string.h>
#define LIMIT 40

void reverse_string(char str[]);
void itob(int n, char s[], int b);

int main(){
	char string[LIMIT+1] = "";
	int n = 0;
	int b = 0;
	printf("enter an integer: ");
	scanf("%d", &n);
	printf("enter base: ");
	scanf("%d", &b);
	itob(n, string, b);
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

void itob(int n, char s[], int b)
{	int sign = 0;
	int i = 0;
	if ((sign = n) < 0){
	do {
		int pos_dig = -(n % b);
		s[i++] = pos_dig + '0';
	} while ((n /= b) < 0);
	} else {
		do {
		s[i++] = n % b + '0';
	} while ((n /= b) > 0);
	}

	if(sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse_string(s);
}
