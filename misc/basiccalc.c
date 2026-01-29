#include <stdio.h>

int calculator(int o1, int o2, char op);

int main(){
	int operand1;
	int operand2;
	char operator;
	printf("enter first operand: ");
	scanf("%d", &operand1);
	printf("\nenter operand2: ");
	scanf("%d", &operand2);
	printf("\nenter operation: ");
	scanf("%c", &operator);

	int result = calculator(operand1, operand2, operator);

	printf("result:%d", result);

}

int calculator(int o1, int o2, char op){
	switch(op){
		case '+':
			return o1 + o2;
			break;
	/*	
		case '-':
			return o1 - o2;

		case '*':
			return o1 * o2;

		case '/':
			if(o2 != 0){
				return o1 / o2;
			}else{
				printf("invalid operation\n");
				break;
			}
			
*/
	}
	
}
