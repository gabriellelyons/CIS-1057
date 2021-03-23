#include <stdio.h>
#include <stdlib.h>

/*
*
* Programmer: Gabrielle Lyons
* Class:      CIS 1057
* Date:       Wednesday, August 28, 2019
*
*/

#define KELVIN_ADJUSTMENT 0.5555555 + 273.15

int main()
{
	double fahrenheit, kelvin;

	// perform for input from the user
	printf( "Enter a temperature in fahrenheit: ");
	scanf( "%lf", &fahrenheit );

	// perform the calculation to perform the conversion
	kelvin = ( fahrenheit - 32.0 ) * KELVIN_ADJUSTMENT;

	// display the results
	printf( "%0.2lf degrees fahrenheit is %0.2lf in kelvin.\n",
		fahrenheit, kelvin );
	printf( " %lfF = %lf.\n", fahrenheit, kelvin );

	return EXIT_SUCCESS;
}
