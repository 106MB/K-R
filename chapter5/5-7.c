// Rewrite line sorting program to use array supplied by main instead of alloc |
// Have an array of pointers pointing to lines contained in buffer
// Sort the lines using quicksort
// Print sorted lines
#include <stdio.h>
#include <string.h>
#define CHAR_LIMIT 80 // line length limit
#define LINE_LIMIT 250//250 //  250 pointers * 8 bytes/pointer = 2kB allocated
#define BUFFER 2000 // Another 2kB to hold line data =

static int readlines(char *lineptrs[], char linebuffer[]);
static void writelines(char *lineptrs[], int nlines);
static void qsort(char *lineptrs[], int left, int right);
static void swap(char *lineptrs[], int i, int j);
int main(void)
{
	// Read Lines
	// Sort them
	// Write Lines
	char *lineptrs[LINE_LIMIT] = {NULL}; // array of pointers to lines
	char linebuffer[BUFFER] = ""; // storage for characters
	int nlines = 0;

	if ((nlines = readlines(lineptrs, linebuffer)) >= 0){
			printf("\nNumber of lines to sort: %d\n", nlines);
			qsort(lineptrs, 0, nlines - 1); // sort lines
			writelines(lineptrs, nlines);  // print lines
			printf("Size of array of pointers: %lu\nSize of Final Buffer: %lu\n", sizeof(lineptrs), sizeof(linebuffer));
			}
	

	
}

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

static void writelines(char *lineptrs[], int nlines)
{
	for (int i = 0; i < nlines; i++){
		printf("%d: %s", i, lineptrs[i]);
	}
}
// 
static void qsort(char *lineptrs[], int left, int right)
{
	int 
}

static void swap (char *v[], int i, int j)
{
	char *temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
	
