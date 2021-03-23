#include <stdio.h>
#include <stdlib.h>

/*
*
* Programmer: Gabrielle Lyons
* Class:      CIS 1057
* Date:       Wednesday, August 28, 2019
*
*/

#define CELSIUS_ADJUSTMENT 0.5555555

int main()
{
        double fahrenheit, celsius;

        // perform for input from the user
        printf( "Enter a temperature in fahrenheit: ");
        scanf( "%lf", &fahrenheit );

        // perform the calculation to perform the conversion
        celsius = ( fahrenheit - 32.0 ) * CELSIUS_ADJUSTMENT;

        // display the results
        printf( "%0.2lf degrees fahrenheit is %0.2lf in celsius.\n",
                fahrenheit, celsius );
        printf( " %lfF = %lf.\n", fahrenheit, celsius );

        return EXIT_SUCCESS;
}

