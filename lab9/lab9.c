#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 9
 * Date: October 30, 2019
 * Version: 1
 * Description: Populates an array with an external txt file, prints the array,
 *		then decides if entered values exist in the array.
 */

#define SIZE 100

void insert_in_array_ascending(int a[], const int size);
void print_int_array(const int *a, const int size);
int get_value_from_user(const char *prompt);
int is_in_array(const int *a, const int size, int number);
void print_results(int is, int number);

int main()
{
	program_banner("This program will determine if a value is in the"
			" following array.");

	FILE *inp;
	inp = fopen("input_numbers.txt", "r");
	
	int a[SIZE];
	int i;

	for (i = 0; i < SIZE; i++)
	{
		fscanf(inp, "%d", &a[i]);
	}

	insert_in_array_ascending(a, 21);
	print_int_array(a, 21);

	int number;
	number = get_value_from_user("Enter value: ");

	int is;
	is = is_in_array(a, 21, number);

	print_results(is, number);

	return EXIT_SUCCESS;
}

/*
 * Function: insert_in_array_ascending()
 * Programmer: Gabrielle Lyons
 * Date: October 30, 2019
 * Inputs: a[], size - an array and its size
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Rearranges the values of an array in ascending order.
 */

void insert_in_array_ascending(int a[], const int size)
{
	int i, j, tmp;
	
	for (i = 1; i < size; i++) {
		j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;	
			j--;
		}
	}

        return;
}

/*
 * Function: print_int_array()
 * Programmer: Gabrielle Lyons
 * Date: October 30, 2019
 * Inputs: a, size - pointer to an array and its size
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Prints a listing of values in an array.
 */

void print_int_array(const int *a, const int size)
{
        int i;

        for (i = 0; i < size; i++)
                printf("a[%d]=%d\n", i, a[i]);

        return;
}

/*
 * Function: get_value_from_user()
 * Programmer: Gabrielle Lyons
 * Date: October 30, 2019
 * Inputs: prompt
 * Outputs: * none *
 * Globals: * none *
 * Returns: number - read in from user input
 * Description: Prompts user, echo prints user input, then returns the input.
 */

int get_value_from_user(const char *prompt)
{
        int number;

        printf( "%s", prompt);
        scanf( "%d", &number );

        printf("You entered %d.\n", number);

        return number;
}

/*
 * Function: is_in_array()
 * Programmer: Gabrielle Lyons
 * Date: October 30, 2019
 * Inputs: a, size, number - an array, its size, and a number to test
 * Outputs: * none *
 * Globals: * none *
 * Returns: 1 or 0, true or false
 * Description: Tests a number to see if it's in a certain array.
 */

int is_in_array(const int *a, const int size, int number)
{
	int i, result;

	for (i = 1; i < size; i++) {
		if( number == a[i] )
			return 1;
	}
	return 0;
}

/*
 * Function: print_results()
 * Programmer: Gabrielle Lyons
 * Date: October 30, 2019
 * Inputs: is, number - result of is_an_array(), number to test 
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Prints if a number is in an array based on is_an_array() results.
 */

void print_results(int is, int number)
{
        if (is == 1)   
                printf("%d is in the array.\n", number);
        else
                printf("%d is not in the array.\n", number);

	return;
}
