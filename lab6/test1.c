#include <stdio.h>
#include <stdlib.h>

int is_a_leap_year();

int main()
{
	int year;

	printf("Enter a year: ");
	scanf("%d", &year);

	if (is_a_leap_year(year) == 0)
		printf("It is not a leap year, February has 28 days.\n");
	else
                printf("It is a leap year, February has 29 days.\n");

	return EXIT_SUCCESS;
}


int is_a_leap_year(int year)
{
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        	return 1;		// It is a leap year.
        else
		return 0;		// It is not a leap year.
	
	
}

