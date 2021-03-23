#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/myheader.h"
#include "include/boiling_points.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 7
 * Date: October 9, 2019
 * Version: 1
 * Description: Reads in a boiling point for an unknown substance then compares 
 *		it to boiling points for known substances then prints out if the
 *		unknown substance is close to one of the knowns.
 */

void program_banner();
double get_data();
double set_substance();
int is_substance_within_x_percent();
double percent_difference();
void print_substance();

int main()
{
	program_banner( "This program will take the boiling point of an unknown"
			" substance\n then print what substance has a similar"
			" boiling point.", "October 9, 2019" );

	double data, substance, diff;

	data = get_data("Enter a boiling point for an unknown substance: ");
	substance = set_substance(data);
	is_substance_within_x_percent(substance, data, 0.03);
	diff = percent_difference(substance, data);
	print_substance(data, substance, diff);
}

/*
 * Function: get_data()
 * Programmer: Gabrielle Lyons
 * Date: October 9, 2019
 * Inputs: prompt
 * Outputs: "You entered (number)"
 * Globals: * none *
 * Returns: number - read in from user input
 * Description: Prompts user, echo prints user input, then returns the input.
 */

double get_data(const char *prompt)
{
        double number;

        printf( "%s", prompt);
        scanf( "%lf", &number );
	printf("You entered %.1lf.\n", number);

        return number;
}

/*
 * Function: set_substance()
 * Programmer: Gabrielle Lyons
 * Date: October 9, 2019
 * Inputs: variable data
 * Outputs: * none *
 * Globals: * none *
 * Returns: variable substance
 * Description: Determines which value to set for the substance based 
 *		on data input.
 */

double set_substance(double data)
{
	double substance;

        if (data < (-78.5 + 0.04 * 78.5))
                substance = CARBON_DIOXIDE;
        else if (data < (-35.5 + 0.04 * 35.5))
                substance = AMMONIA;
        else if (data < (45 + 0.04 * 45))
                substance = WAX;
        else if (data < (100.7 + 0.04 * 100.7))
                substance = WATER;
        else if (data < (300 + 0.04 * 300))
                substance = OLIVE_OIL;
        else if (data < (356.9 + 0.04 * 356.9))
                substance = MERCURY;
        else if (data < (444.6 + 0.04 * 444.6))
                substance = SULFUR;
        else if (data < (1500 + 0.04 * 1500))
                substance = TALC;
        else if (data < (2212 + 0.04 * 2212))
                substance = SILVER;
        else if (data < (2562 + 0.04 * 2562))
                substance = COPPER;
        else if (data < (2700 + 0.04 * 2700))
                substance = GOLD;
        else if (data < (2862 + 0.04 * 2862))
                substance = IRON;
        else
                substance = SILICON;

	return substance;
}

/*
 * Function: is_substance_within_x_percent
 * Programmer: Gabrielle Lyons
 * Date: October 9, 2019
 * Inputs: variables substance, data, percent
 * Outputs: * none *
 * Globals: * none *
 * Returns: 1 - true, or 0 - false
 * Description: Determines if data is within a certain percentage of the
 *		substance value.
 */

int is_substance_within_x_percent(double substance, double data, double percent)
{
	if ((substance - percent * fabs(substance) <= data) && 
		(substance + percent * fabs(substance) >= data))
		return 1;
	else
		return 0;
}

/*
 * Function: percent_difference()
 * Programmer: Gabrielle Lyons
 * Date: October 9, 2019
 * Inputs: variables substance, data
 * Outputs: * none *
 * Globals: * none *
 * Returns: diff - percent difference
 * Description: Calculates the percent difference between the substance value
 * 		and the data value.
 */

double percent_difference(double substance, double data)
{
	double diff;

	diff = substance - data;
	diff = fabs(diff);
	diff /= substance; 
	diff *= 100;

	return diff;
}

/*
 * Function: print_substance()
 * Programmer: Gabrielle Lyons
 * Date: October 9, 2019
 * Inputs: variables data, substance, diff
 * Outputs: "You entered a boiling point of (data), which is within 3% of the 
 * 	    substance [substance name]. (data) is (diff)% away from the reference 
 *	    temperature of (substance) for Carbon Dioxide."
 * Globals: * none *
 * Returns: * none *
 * Description: Prints what substance is within the percentage range, with details,
 *		when is_substance_within_x_percent proves true.
 */

void print_substance(double data, double substance, double diff)
{
        if (is_substance_within_x_percent(data, substance, 0.03) != 0 ) {
                if (substance == CARBON_DIOXIDE)
			printf("You entered a boiling point of %.1lf, which is within "
			"3%% of the\n substance Carbon Dioxide. %.1lf is %.2lf%% away "
			"from the reference temperature\n of %.1lf for Carbon Dioxide.\n", 
			data, data, diff, substance);
                else if (substance == AMMONIA)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Ammonia. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Carbon Ammonia.\n",
                        data, data, diff, substance);
                else if (substance == WAX)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Wax. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Wax.\n",
                        data, data, diff, substance);
                else if (substance == WATER)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Water. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Water.\n",
                        data, data, diff, substance);
                else if (substance == OLIVE_OIL)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Olive Oil. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Olive Oil.\n",
                        data, data, diff, substance);
                else if (substance == MERCURY)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Mercury. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Mercury.\n",
                        data, data, diff, substance);
                else if (substance == SULFUR)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Sulfur. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Sulfur.\n",
                        data, data, diff, substance);
                else if (substance == TALC)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Talc. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Talc.\n",
                        data, data, diff, substance);
                else if (substance == SILVER)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Silver. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Silver.\n",
                        data, data, diff, substance);
                else if (substance == COPPER)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Copper. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Copper.\n",
                        data, data, diff, substance);
                else if (substance == GOLD)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Gold. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Gold.\n",
                        data, data, diff, substance);
                else if (substance == IRON)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Iron. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Iron.\n",
                        data, data, diff, substance);
                else if (substance == SILICON)
                        printf("You entered a boiling point of %.1lf, which is within "
                        "3%% of the\n substance Silicon. %.1lf is %.2lf%% away "
                        "from the reference temperature\n of %.1lf for Silicon.\n",
                        data, data, diff, substance);
                else
                        printf("This substance is unidentified.\n");
	}
	else
		printf("This substance is unidentified.\n");
		return;
}
