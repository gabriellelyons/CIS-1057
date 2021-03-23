#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/myheader.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 5
 * Date: September 25, 2019
 * Version: 1
 * Description: Estimates the value of a factorial using Gosper's algorithm.
 */

void program_banner( const char *program_function, const char *program_date );
int prompt_and_return_integer();
double estimate_gospers_algorithm();
void display_results();

#define ONE_THIRD 0.333333333

int main()
{
        program_banner( "This program will estimate the value of a factorial "
                        "using Gosper's algorithm.", "September 25, 2019" );

	double value;
	value = prompt_and_return_integer( "Enter a positive integer: " );

	double factorial;
	factorial = estimate_gospers_algorithm(value);

	display_results(factorial);

	return EXIT_SUCCESS;
}

/*
 * Function: prompt_and_return_integer()
 * Programmer: Gabrielle Lyons
 * Date: September 25, 2019
 * Inputs: string prompt
 * Outputs: "(prompt from input)" 
 *	    "You entered: (number)"
 * Globals: * none *
 * Returns: number read in from keyboard
 * Description: Prompts user based on input, reads in a value, echo
 *		prints what was input, and returns the value to the
 *		calling function.
 */

int prompt_and_return_integer( const char *prompt )
{
	int number;

	printf( "%s", prompt);
	scanf( "%d", &number );
	printf( "You entered: %d.\n", number);
	
	return number;
}

/*
 * Function: estimate_gospers_algorithm()
 * Programmer: Gabrielle Lyons
 * Date: September 25, 2019
 * Inputs: variable findme - number to calculate factorial
 * Outputs: * none *
 * Globals: ONE_THIRD, M_E, M_PI
 * Returns: f - factorial approximation
 * Description: Performs the calculations to approximate a factorial.
 */

double estimate_gospers_algorithm( const double findme )
{
	double f, v, n;
	
	n = findme;

	f = pow(n, n);
	f *= pow(M_E, -n);
	v = ((2 * n) + ONE_THIRD) * M_PI;
	f *= sqrt(v);

	return f;
}

/*
 * Function: display_results()
 * Programmer: Gabrielle Lyons
 * Date: September 25, 2019
 * Inputs: answer - value resulting from factorial approximation
 * Outputs: "The factorial approximation for your input is (answer)."
 * Globals: * none *
 * Returns: * none *
 * Description: Displays the results from factorial approximation.
 */

void display_results( const double answer )
{
	printf( "The factorial approximation for your input is %.0lf. \n\n", answer);
	
	return;
}

