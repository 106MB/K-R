// Learning about multidimensional arrays
// Convert input Month and Day to corresponding year day
// OR convert year day to corresponding month and day
// Use multidimensional array to account for leap year
// Calculate if year is a leap year on input and use the corresponding array
#include <stdio.h>
#include <stdbool.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // non-leap years
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // leap years
};

static void month_and_day(int year, int yearday, int *month, int *day);
static int day_year(int year, int month, int day);

int main(){

	bool end = false;
	int yearday = 0, year = 0;
	int month = 0, day = 0;
	char input = '\0';

	while (!end){
		printf("m: Monthday to Yearday\ny: Yearday to Monthday\n> ");	
		input = getchar();
		switch (input) {
			case 'm':
				printf("Enter year\n>  ");
				scanf("%d", &year);
				printf("Enter day of year up to 365\n> ");
				scanf("%d", &yearday);
				month_and_day(year, yearday, &month, &day);
				printf("Date: %d/%d/%d\n\n", month, day, year);
				break;
			case 'y':
				printf("Enter year\n> ");
				scanf("%d", &year);
				printf("Enter month\n> ");
				scanf("%d", &month);
				printf("Enter day\n> ");
				scanf(" %d", &day);
				int result = day_year(year, month, day); 
				printf("Day of Year: %d\n\n", result);
				break;
			case 'x':
			case EOF:
				end = true;
				break;
			default:
				break;
		}
	
	}

}
// Convert yearday and return month and day
// Given yearday, subtract from it the mumber of days in a month for as long as it is larger than the number of days in a given month
// This will give you the proper month
// The remainder in yearday will be the day in the month where the loop stopped.
static void month_and_day(int year, int yearday, int *month, int *day)
{
	int i = 0;
	int leap = year%4 && year%100 != 0 || year%400 == 0;
	if (yearday < 365 && yearday > 0 && year >= 0){
	for (i = 1; yearday > *daytab[leap]+i; i++){
		yearday -= *daytab[leap]+i;
	}
	*month = i;
	*day = yearday;
	} else {
		printf("Error: Invalid Day or Year Number\n");
	}
}
// Convert month and day and return yearday
static int day_year(int year, int month, int day)
{
	int leap = year%4 && year%100 != 0 || year%400 == 0;
	if (year > 0 && month >= 1 && month <= 12 && day > 0 && day <= 31)
	for (int i = 1; i < month; i++){
		day += *daytab[leap]+i;
	}
	return day;
}
