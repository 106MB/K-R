#include "stdio.h" #include "stdlib.h" #include "ctype.h" #include "stdbool.h"
#include "math.h"

#define MAXOP 100 // Max size for single operand or operator #define NUMBER '0'
		  // // Signal for number received #define NEG_NUMBER '1' //
		  // Signal for negative number received

		  // External variables for push and pop #define MAXVAL 100 int
		  // sp = 0;	// Stack pointer. Next free stack position
		  // double val[MAXVAL]; // Value Stack. Only numbers get pushed

void push (double f); double pop (void); int getop(char s[]); int getch(void);
void ungetch(int c);
//static void ungets(char s[]); void peek(void); void duplicate(void); void
//swap(void); void clear(void); ex 4-5: Add access to library functions like
//sin, exp, and pow int main() { char s[MAXOP] = ""; int type = 0;	 //
//Signal for switch double op2 = 0; // Temp variable for non-commutative
//operations int neg_sign = -1; double v = 0; // Variable to Set output for
//later calculation

printf("commands: p = peek top; d = duplicate top; s = swap top two\n");
printf("sin = x; cos = y; pow = e\n");
	
while ((type = getop(s)) != EOF) { switch(type) { case NUMBER: push(atof(s));
	break;

	case NEG_NUMBER: push(neg_sign * atof(s)); break;

	case '+': push(pop() + pop()); break;

	case '*': push(pop() * pop()); break;

	case '-': op2 = pop(); push(pop() - op2); break;
			
	case '/': op2 = pop(); if(op2 != 0.0) { push(pop() / op2); } else {
			  printf("error: division by 0\n"); } break;

	case '%': op2 = pop(); if(op2 != 0.0) { push((int)pop() % (int)op2); }
		  else { printf("error: division by 0\n"); } break;

	case 'p': peek(); break;

	case 'd': duplicate(); break;
		
	case 's': swap(); break;	

	case 'c': clear(); break;

	case 'x': push(sin(pop())); break;

	case 'y': push(cos(pop())); break;
				
	case 'e': op2 = pop(); push(pow(pop(), op2)); break;

	case 'v': push(v); break;

	case '\n': v = val[sp - 1]; printf("v = \t%.8g\n", pop()); break;

	default: printf("error: unknown command %s\n", s); break; } } }


	void push (double f) { if (sp < MAXVAL) { val[sp++] = f; } else {
		printf("error: stack full, can't push %g\n", f); } }

		double pop (void) { if(sp > 0) { return val[--sp]; } else {
			printf("error: stack empty\n"); return 0.0; } }

			// Get operator or operand character by character int
			// getop(char s[]) { int i = 0; int c = 0; bool neg =
			// false; // Flag for negative number static char buf;

			// Skip white space. First non-whitespace will be in c
			// while ((s[0] = c = getch()) == ' ' || c == '\t') { Do
			// nothing }

			if (c == '-') { char sub = c; neg = true; if ((s[0] = c = getch()) == ' ' || c == '\n') // If
														// next
														// character
														// is
														// whitespace,
														// treat
														// as
														// subtract
														// {
														// buf
														// =
														// c;
														// return
														// sub;
														// }

			}

// Start getting input one character at a time s[1] = '\0'; // make string
// readable if only an operator if (!isdigit(c) && c != '.') { return c; // Not
// a number }
	
// Collect integer part if (isdigit(c)) { while (isdigit(s[++i] = c = getch()))
// { string is being built } }

// Collect fraction part if (c == '.') { while (isdigit(s[++i] = c = getch())) {
// string is being built } }

s[i] = '\0'; // make string readable, will be converted using atof()

// getch() will read one character too many to indicate end of a number
// ungetch() will remove that character from the string removed character will
// be placed in a buffer that will be handled on the next call i.e. 34 4 +,
// whitespace after the numbers will be ungetted or 34 4+, whitespace and + will
// be ungetted	if (c != EOF) { buf = c; }

if (!neg) { return NUMBER; } else { return NEG_NUMBER; } }

// 4-8: Assume pushback will never be more than one character That means array
// buffer is not needed, only a one character buffer used by both functions bool
// buf_flag = false; // flag to indicate there is a buffer char Essentially
// wrappers around getchar() int getch(void) { if there are characters in the
// buffer, return the top of the buffer else return character from input if
// (buf_flag) { buf_flag = false; return buf; } else { return getchar(); } }
// Push character back on input void ungetch(int c) {	buf = c; buf_flag =
// true;	} Push entire string back onto input using ungetc()
/*
   static void ungets(char s[]) { for (int i = 0; s[i] != '\0'; i++) {
   ungetch(s[i]); } }
*/
// 4-4: Add peek, duplicate, swap top elements, clear stack void peek(void) { if
// (sp > 0) {	printf("top of stack: %f\n", val[sp - 1]); } }

void duplicate(void) {	if (sp > 0) {	val[sp] = val[sp - 1]; // Copy top
							       // element into
							       // current sp
							       // position,
							       // increment sp
							       // sp++;

} else { printf("error: stack empty\n"); } }

void swap(void) { if (sp > 1) // Two or more elements { double temp = val[sp -
			      // 2]; val[sp - 2] = val[sp - 1]; val[sp - 1] =
			      // temp; } }

	void clear(void) {
		// Clear stack by resetting stack pointer to 0 sp = 0; }
