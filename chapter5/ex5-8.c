/*Exercise 5-8. There is no error checking in day_of_year 
 *or month_day. Remedy this defect.
*/
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int check_year(int year);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0 ,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
	int yearday, month, day;

	yearday = day_of_year(1932, 2, 3);
	printf("%d\n", yearday);
	yearday = day_of_year(2004, 2, 18);
	printf("%d\n", yearday);

	month_day(1912, 21, &month, &day);
	printf("M: %d, D: %d\n", month, day);
	month_day(2001, 3000, &month, &day);
	printf("M: %d, D: %d\n", month, day);

	return 0;
}

int check_year(int year) {
	return year % 4 == 0 && 
		year % 100 != 0 || year % 400 == 0;
}

// set day of year from month & day
int day_of_year(int year, int month, int day) {

	int i, leap = check_year(year);

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return -1;

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

// set  month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday) {

	int i, leap = check_year(year);
	int leap_check = leap ? 366 : 365;

	if (year < 1 || yearday < 1 || yearday > leap_check) {
		*pmonth = -1;
		*pday = -1;
		return;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
