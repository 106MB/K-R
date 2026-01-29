#include "stdio.h"
#define SIZE 2
int main(){
	int student1[SIZE];
	int student2[SIZE];
	int total[SIZE];
	float average = 0;
	float percent;

	printf("enter student 1 scores: ");
		for(int i = 0; i < SIZE; i++){
			scanf("%d", &student1[i]);
			}

	printf("\nenter student 2 scores: ");
		for(int i = 0; i < SIZE; i++){
			scanf("%d", &student2[i]);
			}


		for (int i = 0; i < SIZE; i++){
		total[i] = student1[i] + student2[i];		
			}

		for(int i = 0; i < SIZE; i++){
			average += total[i];

			}

	printf("\nthe class average is: %f\n", average /(200 * SIZE));
}
