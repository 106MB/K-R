//count occurences of digits, whitespace, others with switch statement
#include <stdio.h>

int main(){
	char c = '\0';
	int digits[10];
		for(int i = 0; i < 10; i++){
			digits[i] = 0;
		}
	int whitespace = 0;
	int other = 0;

	while((c = getchar()) != EOF){
		switch(c)
		{
			case '0': case '1': case '2': case '3': case '4': 
			case '5': case '6': case '7': case '8': case '9': 
				  digits[c-'0']++;
				  break;

			case ' ':
			case '\t':
			case '\n':
				  whitespace++;
				  break;
			default:
				  other++;
				  break;
		}
	}

	printf("digits = ");
		for(int i = 0; i < 10; i++){
			printf("%d ", digits[i]);
		}
	printf(", white space = %d, other = %d\n", whitespace, other);
}
