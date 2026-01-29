// Get stream of integers of input, convert them, and place them into an array
#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
#define SIZE 300

int getch(void);
void ungetch(int c);
int getint(int *pn);
int main()
{
	int array[SIZE+1];
	
	for (int n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
	{
		// DO NOTHING: Array will be filled.
		printf("%d ", array[n]);
	}


}
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
	{
		// SKIP WHITESPACE
	}

	// Unget first character after whitespace if not a digit, EOF, or sign and return 0
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}

	// Get sign if there is one, then get the next character
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		int ch = getch();
		if (!isdigit(ch))
		{
			if (ch != EOF)
			{
				ungetch(ch);
			}
			ungetch(c);
			return c;
		}
		c = ch;
	}

	// Init array index to 0 and start converting ascii to integer. Continue for each digit.
	for (*pn = 0; isdigit(c); c = getch())
	{
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;

	// c will hold an extra character after the last digit. Must unget it if not EOF.
	if (c != EOF)
	{
		ungetch(c);
	}
	return c;
}

// External variables for getch() and ungetch()
#define BUFSIZE 100
 
char buf[BUFSIZE] = ""; // Buffer for ungetch()
int bufp = 0; // stack pointer for buffer

// Essentially wrappers around getchar()
int getch(void)
{
	// if there are characters in the buffer, return the top of the buffer
	// else return character from input
	return (bufp > 0) ? buf[--bufp] : getchar();
}
// Push character back on input
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	} else
	{
		buf[bufp++] = c;
	}
}

