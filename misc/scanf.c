#include "stdio.h"

int main(){
    char name[100];
    int month, day, year;
    double gpa;

    printf("enter : lastname birthday gpa\n");
    scanf("%s %d/%d/%d %lf", name, &month, &day, &year, &gpa);

    printf("\nName : %s\n", name);
    printf("Birthday : %d/%d/%d\n", month,day,year);
    printf("GPA : %lf\n", gpa);



}
