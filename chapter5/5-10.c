// Write the program expr, which evaluates a reverse polish expression from the
// command line, where each operator or operand is a seperate argument
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void push (double f);
double pop(void);


int main(int argc, char **argv)
{
	double op2 = 0.0;	// temp holder for subtraction and division
	if (argc < 4){
		printf("Useage: Enter at least 2 operands and an operator.\n");
	} else {
		while (--argc > 0){
			if(isdigit((*++argv)[0])){
				push(atof(*argv));
			} else if (!strcmp(*argv, "+")){
				push(pop() + pop());
			} else if (!strcmp(*argv, "*")){
				push(pop() * pop());
			} else if (!strcmp(*argv, "-")){
				op2 = pop();
				push(pop() - op2);
			} else if (!strcmp(*argv, "/")){
				op2 = pop();
				if (op2 != 0.0){
					push(pop() /op2);
				} else {
					printf("error: zero divisor\n");
				}
			} else {
				printf("\nerror: unknown command %s", *argv);
			}
		}
	}
	printf("\t\t\t\t\t= %.8g\n", pop());
	return 0;
}
// External variables for push and pop
#define MAXVAL 100
int sp = 0;	// Stack pointer. Next free stack position
double val[MAXVAL]; // Value Stack. Only numbers get pushed

void push (double f)
{
	if (sp < MAXVAL){
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop (void)
{
	if(sp > 0){
		return val[--sp]; 
	} else{
		printf("error: stack empty\n");
		return 0.0;
	}
}
