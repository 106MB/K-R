//implement stack with push and pop functions
#include "stdio.h"

#define SIZE 100

int stack[SIZE];
int top=0;

int push(int item);

int main(){
	int item = 4;
	
	int ack = push(item);

	printf("\n%d\n");

	pop(&item);


}

int push(int item){
	if(top == SIZE){
		return 1
	} else{
		stack[top] = item;
		top++;
		return 0
	}
}

int pop(int* temp){
	if(top == 0){
		return 1
	}else{
		*temp = stack[top];
		top--;
		return 0
	}
}
