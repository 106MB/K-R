// Write strncpy(s,t,n), strncmp(s,t,n), strtncat(s,t,n) functions
// Operate on at most n characters of t on s
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIMIT 200

int strncmp_local(char *s, char *t, int n);

int main(void)
{
	int n = 0;
	int comparison = 0;

	while (1){
		char s[LIMIT] = "";
		char t[LIMIT] = "";

		printf("\nEnter two strings\n");

		if (fgets(s, LIMIT, stdin) != NULL && fgets(t, LIMIT, stdin) != NULL){
			printf("Enter number of characters to compare: ");
			scanf("%d", &n);
			comparison = strncmp_local(s,t,n);
			printf("\nresult = %d\n", comparison);
		}



	}

	

}

int strncmp_local(char *s, char *t, int n)
{
	for (int i = 0; i < n; i++){
		if (*s  == '\0' || *s != *t){
			return *s - *t;
		}
	}
	return 0;
}
