// Implement a grep like program using command line arguments
#include <stdio.h>
#include <string.h>
#define LIMIT 1000

// Find pattern in line matching command line arg, if it exists

int main(int argc, char *argv[])
{
	int found = 0;
	char line[LIMIT] = "";

	// Allow only one argument 
	if (argc != 2){
		printf("Useage: find pattern\n");
	} else {
		while (fgets(line, LIMIT, stdin) != NULL){
			if (strstr(line, argv[1]) != NULL){
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
}
