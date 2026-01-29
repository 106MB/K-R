// Modify the Qsort program to take in a flag that prints out the input
// strings in reverse sorted order
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define CHAR_LIMIT 80	// line length limit
#define LINE_LIMIT 250	// 250 pointers * 8 bytes/pointer = 2kB allocated
#define BUFFER 2000 	// Another 2kB to hold line data 
bool numeric = false;	// Global Flags for options
bool reverse = false;	//

static int readlines(char *lineptrs[], char linebuffer[]);
static void writelines(char *lineptrs[], int nlines);
static void qsort_local(void *v[], int left, int right, int (*comp)(void *num, void *str));
static int numcmp(const char *s1, const char *s2);
static void swap(void *v[],int i, int j);
int main(int argc, char **argv)
{
	char *lineptrs[LINE_LIMIT] = {NULL}; // array of pointers to lines
	char linebuffer[BUFFER] = ""; // storage for characters
	int nlines = 0;
	int c;
	while (--argc > 0 && (*++argv)[0] == '-'){
		while ((c = *++argv[0])){
			switch (c){
				case 'n':
					printf("numeric mode: on\n");
					numeric = true;
					break;
				case 'r':
					printf("reverse mode: on\n");
					reverse = true;
					break;
				default:
					printf("error: unknown flag\n");
					break;

			}
		}
	}
	if ((nlines = readlines(lineptrs, linebuffer)) >= 0){
		qsort_local((void **)lineptrs, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
		writelines(lineptrs, nlines);
	} else {
		printf("input too large to sort\n");
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
// quick sort pseudo
// Base Case: Size of the array is <= 1. A solo element is considered sorted

// Place the partition element on left side of the array
// Swap the next element greater than the partition if you encounter and element less
// than the partition 
// Swap the partition element with the last encountered less than element
// You will be left with a sorted partition element and two subarrays to the
// left and right of it

// Call the sort again on these smaller subarrays
static void qsort_local(void *v[], int left, int right, int (*comp)(void *num, void *str))
{
	if (left >= right){
		return;
	}
	swap(v, left, (left + right) / 2);
	int last = left; // 'Last' contains the index of the last encountered item
			 // less than the current partition element
	if (!reverse){
		for (int i = left+1; i <= right; i++){
			if ((*comp)(v[i], v[left]) < 0){
				swap(v, ++last, i);
			}
		}
	} else {
		// reverse order: change comparison
		for (int i = left+1; i <= right; i++){
			if ((*comp)(v[i], v[left]) >= 0){
				swap(v, ++last, i);
			}
		}

	}
	swap(v, left, last);
	qsort_local(v, left, last-1, comp);
	qsort_local(v, last+1, right, comp);
}

static int numcmp(const char *s1, const char *s2)
{
	
	double v1 = atof(s1);
	double v2 = atof(s2);
	if (v1 < v2){
		return -1;
	} else if (v1 > v2){
		return 1;
	} else {
		return 0;
	}
}

static void swap(void *v[],int i, int j)
{
	void *temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
