// Write a local version of the concatenate program
// Prints contents of file command line argument to the screen
// if no argument is given, cat from standard input
#include <stdio.h>

void filecopy(FILE *ifp, FILE *opf);
int main(int argc, char **argv)
{
	FILE *fp = NULL;

	if (argc == 1){
		filecopy(stdin, stdout);
	} else {
		while(--argc > 0){
			if ((fp = fopen(*++argv, "r")) != NULL){
				filecopy(fp, stdout);
				fclose(fp);
			} else {
				printf("cant open file\n");
				return 1;
			}
		}
	}
}
void filecopy(FILE *ifp, FILE *opf)
{
	int c;
	while((c = getc(ifp)) != EOF){
		putc(c, opf);
	}
}
