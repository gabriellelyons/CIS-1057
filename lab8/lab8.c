#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/myheader.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 8
 * Date: October 16, 2019
 * Version: 1
 * Description: Takes the amount due and amount paid, then calculates the change
 *		to return specific to dollars and each type of coin. 
 */

void program_banner();
double get_data();
void cashier_prompt();
double how_many_dollars();
void how_many_coins();
void print_coin_change();

int main()
{
        program_banner("This program will print the change owed to a customer.");

	double paid, due, change, remainder;
	int quarters, dimes, nickels, pennies;

	due = get_data("Enter amount due: ");
	paid = get_data("Enter amount paid: ");
	change = (paid - due) * 100;

	cashier_prompt(change);

	remainder = how_many_dollars(change);

	how_many_coins(remainder, &quarters, &dimes, &nickels, &pennies);

	print_coin_change(quarters, dimes, nickels, pennies);

	return EXIT_SUCCESS;
}

/*
 * Function: get_data()
 * Programmer: Gabrielle Lyons
 * Date: October 9, 2019
 * Inputs: prompt
 * Outputs: * none *
 * Globals: * none *
 * Returns: number - read in from user input
 * Description: Prompts user, echo prints user input, then returns the input.
 */

double get_data(const char *prompt)
{
        double number;

        printf( "%s", prompt);
        scanf( "%lf", &number );

        printf("You entered %.2lf.\n", number);

        return number;
}

/*
 * Function: cashier_prompt()
 * Programmer: Gabrielle Lyons
 * Date: October 16, 2019
 * Inputs: change - amount due minus amount paid
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Prints that either no change is needed or that the cashier
 *		will return change.
 */

void cashier_prompt(double change)
{
	if (change == 0)
		printf("No change needed.\n");
	else
		printf("Cashier will return:\n");
	
	return;
}

/*
 * Function: how_many_dollars()
 * Programmer: Gabrielle Lyons
 * Date: October 16, 2019
 * Inputs: change - amount due minus amount paid
 * Outputs: * none *
 * Globals: * none *
 * Returns: remainder - change left to make with coins
 * Description: Determines how many dollars to give as change and prints value.
 */

double how_many_dollars(double change)
{
	int dollars;
	double remainder;

	dollars = change / 100;
	remainder = fmod(change, 100);

	if (dollars == 1)
                printf("%d dollar\n", dollars);
        else if (dollars == 0)
		return remainder;
	else
		printf("%d dollars\n", dollars);

	return remainder;
}

/*
 * Function: how_many_coins()
 * Programmer: Gabrielle Lyons
 * Date: October 16, 2019
 * Inputs: remainder - change total left after dollars substracted
 * Outputs: quarters, dimes, nickels, pennies - number of each for change
 * Globals: * none *
 * Returns: * none *
 * Description: Determines how many coins (of each type) will be included in the change.
 */

void how_many_coins(double remainder, int *quarters, int *dimes, int *nickels, int *pennies)
{
	*quarters = remainder / 25;
        remainder = fmod(remainder, 25);

        *dimes = remainder / 10;
        remainder = fmod(remainder, 10);

        *nickels = remainder / 5;
        remainder = fmod(remainder, 5);

        *pennies = remainder / 1;

        return;
}


/*
 * Function: print_coin_change()
 * Programmer: Gabrielle Lyons
 * Date: October 16, 2019
 * Inputs: quarters, dimes, nickels, pennies - number of each for change
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Prints how many of each coin must be given as change.
 */

void print_coin_change(int quarters, int dimes, int nickels, int pennies)
{

        if (quarters == 1)
                printf("%d quarter\n", quarters);
        else if (quarters == 0);
        else
                printf("%d quarters\n", quarters);

        if (dimes == 1)
                printf("%d dime\n", dimes);
        else if (dimes == 0);
        else
		printf("%d dimes\n", dimes);

        if (nickels == 1)
                printf("%d nickel\n", nickels);
        else if (nickels == 0);
	else
		printf("%d nickels\n", nickels);

	if (pennies == 1)
                printf("%d penny\n", pennies);
        else if (pennies == 0);
	else
                printf("%d pennies\n", pennies);

	return;
}
