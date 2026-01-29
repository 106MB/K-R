// Implement reverse using pointers

#include <stdio.h>
#define LIMIT 300

static int strlen_local(char s[]);
static void reverse_string(char *head, int len);
int main(void)
{
	char arr[LIMIT] = "";
	char *s = arr;

	while(fgets(s, LIMIT, stdin) != NULL && *s != EOF){
		int len = strlen_local(s);
		reverse_string(s, len);
		printf("%slen = %d\n", s, len);
	}
}

// Traverse until null char
// Return the difference between string beginning and end, before null 
static int strlen_local(char *s)
{

	char *head = s; // Start of string

	while(*s != '\0'){
		s++;
	}
	return (s - head) - 1;
}

// Start tail ptr at end of string, before newline and null char
// Swap characters and then inc head and dec tail
// When tail is less than head, return
static void reverse_string(char *head, int len)
{
	char *tail = head + (len - 1);
	while (head < tail){
		char temp = *head;
		*head++ = *tail;
		*tail-- = temp;
	}
}
