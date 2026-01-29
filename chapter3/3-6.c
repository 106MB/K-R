// convert n to characters in s
// include a third argument that specifies minimum field width
#include <stdio.h>
#include <string.h>
#define LIMIT 40

void reverse_string(char str[]);
void itoa(int n, char s[], int width);

int main(){
	char string[LIMIT+1] = "";
	int n = 0;
	int width = 0;
	printf("enter an integer: ");
	scanf("%d", &n);
	printf("enter minimum field width: ");
	scanf("%d", &width);
	itoa(n, string, width);
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

void itoa(int n, char s[], int width)
{	int sign = 0;
	int i = 0;
	if ((sign = n) < 0){
	do {
		int pos_dig = -(n % 10);
		s[i++] = pos_dig + '0';
	} while ((n /= 10) < 0);
	} else {
		do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	}

	if(sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';

	// Add padding if width does not match strlen 
	if(strlen(s)-1 != width){
		while(i < width){
			s[i++] = ' ';
		}
	}
	s[i] = '\0';
	reverse_string(s);
}
