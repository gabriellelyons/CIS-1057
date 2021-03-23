#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Programmer: Gabrielle Lyons
 * Class: CIS 1057
 * Date: September 11, 2019
 *
*/

#define BASE_POPULATION 52.966
#define ANNUAL_GROWTH 2.184

void program_banner();
double model_population();

int main()
{
	program_banner( "\nThis program will calculate the population\n"
         		"growth in the city of Gotham.\n");

	double P, t;

	printf( "Enter a year after 1990: ");
	scanf("%lf", &t);

	P = model_population(t);

	printf( "Predicted Gotham City population for %4.0f (in thousands): %.3lf thousand.\n\n", t, P);

	return EXIT_SUCCESS;
}

void program_banner( const char *program_function )
{
	printf( "%s\n"
		"This program was written by Gabrielle Lyons.\n\n",
		 program_function);
	return;
}

double model_population(double year)	
{	
	double M;

	M = BASE_POPULATION + (ANNUAL_GROWTH * (year - 1990));

	return (M);
}
