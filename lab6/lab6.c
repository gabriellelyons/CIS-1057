#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 6
 * Date: October 2, 2019
 * Version: 1
 * Description:
 */

void program_banner();
int get_date();
int is_a_leap_year();
int is_a_valid_date();
int ordinal_date();
void print_US_date();
void print_ordinal_date();

int main()
{
	program_banner( "This program will print the US and Julian dates for an input"
			" month, day, and year.", "October 2, 2019" );

	int month, day, year, date;

	month = get_date( "Enter the month: " );
	day = get_date( "Enter the day: " );
	year = get_date( "Enter the year: " );

	is_a_leap_year(year);
	is_a_valid_date(month, day, year);
	date = ordinal_date(month, day, year);
	print_US_date(month, day, year);
	print_ordinal_date(year, date);

	return EXIT_SUCCESS;
}

/*
 * Function: get_date()
 * Programmer: Gabrielle Lyons
 * Date: October 2, 2019
 * Inputs: string prompt
 * Outputs: string prompt
 * Globals: * none *
 * Returns: number - read in from user input
 * Description: Prints a prompt, reads in the user input, then returns the input.
 */

int get_date( const char *prompt )
{
        int number;

        printf( "%s", prompt);
        scanf( "%d", &number );

        return number;
}

/*
 * Function: is_a_leap_year()
 * Programmer: Gabrielle Lyons
 * Date: October 2, 2019
 * Inputs: variable year
 * Outputs: * none *
 * Globals: * none *
 * Returns: 1 - for true; 0 for false
 * Description: Takes a year and analyzes if it is a leap year.
 */

int is_a_leap_year(int year)
{
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 1;               // It is a leap year.
        else
                return 0;               // It is not a leap year.
}

/*
 * Function: is_a_valid_date()
 * Programmer: Gabrielle Lyons
 * Date: October 2, 2019
 * Inputs: variables month, day, year
 * Outputs: * none *
 * Globals: * none *
 * Returns: 1 - for true; 0 - for false
 * Description: Takes an input for month, day, and year and analyzes the validity.
 */

int is_a_valid_date(int month, int day, int year)
{
        if ((month == 4 || month == 6 || month == 9 || month == 11) && 
		(day >= 1 && day <= 30) && (year >= 1900 && year <= 2200))
			return 1;
	else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12) &&
                (day >= 1 && day <= 31) && (year >= 1900 && year <= 2200))
                        return 1;
	else if ((month == 2 && is_a_leap_year(year) == 0) &&
		(day >= 1 && day <= 28) && (year >= 1900 && year <= 2200))
			return 1;
	else if ((month == 2 && is_a_leap_year(year) == 1) &&
		(day >= 1 && day <= 29) && (year >= 1900 && year <= 2200))
                        return 1;
        else
                return 0;
}

/*
 * Function: ordinal_date()
 * Programmer: Gabrielle Lyons
 * Date: October 2, 2019
 * Inputs: variables month, day, year
 * Outputs: * none *
 * Globals: * none *
 * Returns: date - calculated from input date; or 0
 * Description: Takes a month, day, and year and calculates the julianized date.
 */

int ordinal_date(int month, int day, int year)
{
	int date;
	int jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec;

	jan = 0; feb = 31; mar = 59; apr = 90; 
	may = 120; jun = 151; jul = 181; aug = 212; 
	sep = 243; oct = 273; nov = 304; dec = 334;
	
	if (is_a_leap_year(year) == 0 && is_a_valid_date(month, day, year) == 1)
		{switch (month) {
			case 1: date = jan + day;
				break;
			case 2: date = feb + day;
                	        break;
			case 3: date = mar + day;
                	        break;
			case 4: date = apr + day;
        	                break;
			case 5: date = may + day;
                        	break;
			case 6: date = jun + day;
        	                break;		
			case 7: date = jul + day;
        	                break;
			case 8: date = aug + day;
        	                break;
			case 9: date = sep + day;
	                        break;
			case 10: date = oct + day;
                	        break;
			case 11: date = nov + day;
        	                break;
			case 12: date = dec + day;
        	                break;
			}
		return date;
		}
	else if (is_a_leap_year(year) == 1 && is_a_valid_date(month, day, year) == 1)
		{switch (month) {
                        case 1: date = jan + day;
                                break;
                        case 2: date = feb + day;
                                break;
                        case 3: date = ++mar + day;
                                break;
                        case 4: date = ++apr + day;
                                break;
                        case 5: date = ++may + day;
                                break;
                        case 6: date = ++jun + day;
                                break;
                        case 7: date = ++jul + day;
                                break;
                        case 8: date = ++aug + day;
                                break;
                        case 9: date = ++sep + day;
                                break;
                        case 10: date = ++oct + day;
                                break;
                        case 11: date = ++nov + day;
                                break;
                        case 12: date = ++dec + day;
                                break;
                        }
                return date;
		}
	else
		printf("***ERROR: NOT A VALID DATE***\n");
		return 0;
}

/*
 * Function: print_US_date()          
 * Programmer: Gabrielle Lyons
 * Date: October 2, 2019
 * Inputs: variables month, day, year
 * Outputs: "MM/DD/YYYY" (with proper values)
 * Globals: * none *
 * Returns: * none *
 * Description: Prints "MM/DD/YYYY" with the values that relate to the input date.
 */

void print_US_date(int month, int day, int year)
{
	if (ordinal_date(month, day, year) != 0)
		printf( "%02d/%02d/%04d is the ", month, day, year );
	else
		return;
}

/*
 * Function: print_ordinal_date()
 * Programmer: Gabrielle Lyons
 * Date: October 2, 2019
 * Inputs: variable year, ordinal_day
 * Outputs: "YYYYDDD" (with proper values)
 * Globals: * none *
 * Returns: * none *
 * Description: Prints "YYYYDDD" with the values that relate to the input date.
 */

void print_ordinal_date(int year, int ordinal_day)
{
	if (ordinal_day != 0)
		printf("%04d%03d.\n\n", year, ordinal_day);
	else
		return;
}
