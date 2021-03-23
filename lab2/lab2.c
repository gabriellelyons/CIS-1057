#include <stdio.h>
#include <stdlib.h>

/*
 *
 * Programmer: Gabrielle Lyons
 * Class: CIS 1057
 * Date: September 4, 2019
 *
*/

int main()
{
	int m, n, side1, side2, hypotenuse;
	
	// perform for input from the user
	printf( "Enter an integer: ");
	scanf("%d", &n);
	printf( "Enter a greater integer: ");
	scanf("%d", &m);

	// perform the calculation for each side
	side1 = ((m * m) - (n *n));
	side2 = (2 * m * n);
	hypotenuse = ((m * m) + (n * n));

	// display the results
	printf("Your pythagorean triple is: %d %d %d.\n", 
	side1, side2, hypotenuse);

	return EXIT_SUCCESS;
 }
