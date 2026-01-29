#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"

#define MAXOP 100 // Max size for single operand or operator
#define NUMBER '0' // Signal for number received
#define NEG_NUMBER '1'

void push (double f);
double pop (void);
int getop(char s[]);
int getch(void);
void ungetch(int c);

// Add modulo operation and support for negative numbers
int main()
{
	char s[MAXOP] = "";
	int type = 0;	 // Signal for switch
	double op2 = 0; // Temp variable for non-commutative operations
	int neg_sign = -1;
	
	while ((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;

			case NEG_NUMBER:
				push(neg_sign * atof(s));
				break;

			case '+':
				push(pop() + pop());
				break;

			case '*':
				push(pop() * pop());
				break;

			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			
			case '/':
				op2 = pop();
				if(op2 != 0.0)
				{
					push(pop() / op2);
				} else 
				{
					printf("error: division by 0\n");
				}
				break;

			case '%':
				op2 = pop();
				if(op2 != 0.0)
				{
					push((int)pop() % (int)op2);
				} else 
				{
					printf("error: division by 0\n");
				}
				break;
			
			case '\n':
				printf("\t%.8g\n", pop());
				break;

			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
}

// External variables for push and pop
#define MAXVAL 100
int sp = 0;	// Stack pointer. Next free stack position
double val[MAXVAL]; // Value Stack. Only numbers get pushed

void push (double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	} else 
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop (void)
{
	if(sp > 0)
	{
		return val[--sp]; 
	} else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

// Get operator or operand character by character 
int getop(char s[])
{
	int i = 0;
	int c = 0;
	bool neg = false; // Flag for negative number

	// Skip white space. First non-whitespace will be in c
	while ((s[0] = c = getch()) == ' ' || c == '\t')
	{
		// Do nothing
	}

	if (c == '-')
	{
		neg = true;
		s[0] = c = getch(); // Get new character
	}

	// Start getting input one character at a time
	s[1] = '\0'; // make string readable if only an operator
	if (!isdigit(c) && c != '.')
	{
		return c; // Not a number
	}
	
	// Collect integer part
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch())) 
		{
			// string is being built
		}
	}

	// Collect fraction part
	if (c == '.') 
	{
		while (isdigit(s[++i] = c = getch())) 
		{
			// string is being built
		}
	}

	s[i] = '\0'; // make string readable, will be converted using atof()

	// getch() will read one character too many to indicate end of a number
	// ungetch() will remove that character from the string
	// removed character will be placed in a buffer that will be handled on the next call
	// i.e. 34 4 +, whitespace after the numbers will be ungetted or 34 4+, whitespace and + will be ungetted	
	if (c != EOF)
	{
		ungetch(c);
	}

	if (!neg)
	{
		return NUMBER;
	} else 
	{
		return NEG_NUMBER;
	}
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

