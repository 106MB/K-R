// Write find program but now include flags
// x: print all the lines except the matching pattern
// n: print line numbers before each line
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIMIT 1000

int main(int argc, char *argv[])
{
	char line[LIMIT] = "";	// input line
	long lineno = 0;	// line number storage
	int c = 0, found = 0;	// counters
	bool except = false, number = false;	// flags for input flags
	while (--argc > 0 && (*++argv)[0] == '-'){
		 while ((c = *++argv[0])){
			 switch (c){
				 case 'x':
					 except = true;
					 break;
				 case 'n':
					 number = true;
					 break;
				default:
					 printf("find: illegal option: %c\n", c);
					 argc = 0;
					 found = -1;
					 break;
			 }
		 }
	 }
	 if (argc != 1){
		 printf("Useage: find -x -n pattern\n");
	 } else {
		 while(fgets(line, LIMIT, stdin) != NULL) {
			 lineno++;
			 if((strstr(line, *argv)!= NULL) != except){
				if (number){
					 printf("%ld:", lineno);
			 	}
			 printf("%s", line);
			 found++;
			 }
		 }
	 }
	return found;
}
