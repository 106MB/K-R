// Write the program tail(), which prints the last n lines of its input. By
// default, n is 10, but enable n to be input as a command argument.
// Store pointers to lines and print the last n strings the pointers are
// addressed to
// Solution: Modify writelines to only print the last n lines
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEFAULT_LINES 3
#define CHAR_LIMIT 80 // line length limit
#define LINE_LIMIT 250// 250 pointers * 8 bytes/pointer = 2kB allocated
#define BUFFER 2000 // Another 2kB to hold line data 

static int readlines(char *lineptrs[], char linebuffer[]);
static void writelines(char *lineptrs[], int nlines);
static void write_last_nlines(char *lineptrs[], int nlines, int tail);
int main(int argc, char **argv)
{
	char *lineptrs[LINE_LIMIT] = {NULL}; // array of pointers to lines
	char linebuffer[BUFFER] = ""; // storage for characters
	int nlines = 0;
	if (argc == 1){
		// Use default option
		printf("Output: last %d lines of input\n", DEFAULT_LINES);
		while ((nlines = readlines(lineptrs, linebuffer)) > 0){
			if (DEFAULT_LINES > nlines){
				writelines(lineptrs, nlines);
			} else {
				write_last_nlines(lineptrs,nlines,DEFAULT_LINES);
			}
		}
	} else if (argc == 2){
		// User input
		int tail = atoi(*++argv);
		printf("Output: last %d lines of input\n", tail);
		while ((nlines = readlines(lineptrs, linebuffer)) > 0){
			if (tail > nlines){
				writelines(lineptrs, nlines);
			} else {
				write_last_nlines(lineptrs, nlines, tail);
			}
		}
	} else {
		printf("Enter last n lines to output\nDefault: %d", DEFAULT_LINES);
	}
	return 0;
}
// Takes input line and assigns it to a pointer
// Pointer to string is added to array of string pointers
// Returns number of lines input before empty newline
static int readlines(char *lineptrs[], char linebuffer[])
{
	int nlines = 0; // number of lines input before error or empty newline
	char *bufptr = linebuffer; // next available spot in buffer	
	char temp[CHAR_LIMIT] = ""; // temp string storage 

	while (fgets(temp, CHAR_LIMIT, stdin) != NULL && *temp != '\n'){
		if (nlines >= LINE_LIMIT || strlen(temp) + strlen(linebuffer) >= BUFFER){
			return -1;
		} else {
			strcpy(bufptr, temp);
			lineptrs[nlines++] = bufptr;
			bufptr += strlen(bufptr) + 1; // save null char
		}
	}
	return nlines;
}

// Iterates through array of pointers and outputs each one 
static void writelines(char *lineptrs[], int nlines)
{
	for (int i = 0; i < nlines; i++){
		printf("%d: %s", i, lineptrs[i]);
	}
	putchar('\n');
}
// nlines > tail, otherwise, call writelines
// Starts iterator at (nlines - tail) index
// Outputs string until nlines is reached
static void write_last_nlines(char *lineptrs[], int nlines, int tail)
{
	for (int i = (nlines - tail); i < nlines; i++){
		printf("%d: %s", i, lineptrs[i]);
	}
	putchar('\n');

}
