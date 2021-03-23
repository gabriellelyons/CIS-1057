#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myheader.h"
#include "resister.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 11
 * Date: December 4, 2019
 * Version: 1
 * Description: Calculates the resistance dependent on the color of
 * 		each of four bands.
 */

void display_resister_selection_menu(void);
char *input_color_code(char *prompt);
int band1_num(char band1[ ]);
int band2_num(char band2[ ]);
int band3_num(char band3[ ]);
int calculate_resistance (int band1, int band2, int band3); 
	// changed above prototype to enable abstraction
double tolerance_percentage(char band4[ ]);
void calculate_tolerances(int resistance, double tolerance, double *low, double *high);
void print_results(int resistance, double tolerance, double low, double high);

int main()
{
	program_banner("This program calculates the resitance dependent on "
			"the color of each of four bands.");

	display_resister_selection_menu();

        char* band = input_color_code("Band");

        int band1 = band1_num(&band[0]);
        int band2 = band2_num(&band[1]);
        int band3 = band3_num(&band[2]);

        int resistance = calculate_resistance (band1, band2, band3);

        double percentage = tolerance_percentage(&band[3]);
        double low, high;
        calculate_tolerances(resistance, percentage, &low, &high);

        print_results(resistance, percentage, low, high);

	return EXIT_SUCCESS;
}

/*
 * Function: display_resister_selection_menu()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: * none *
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Displays the color options available for input.
 */

void display_resister_selection_menu(void)
{
	puts("Enter the colors of the resistor’s three "
                "bands, staring with the one on the left.");
        puts("Menu of options to select from: ");

	int i;
	int j = 0;

        for ( i = 0; i < RESISTER_SIZE; i++ ) 
		printf("%c) %s\n", LETTER_MENU[j++], RESISTER_CODES[i]);
		printf("z) BLANK\n");
        return;
}

/*
 * Function: input_color_code()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: prompt - string
 * Outputs: * none *
 * Globals: * none *
 * Returns: whole_band - string of letters representing each band color
 * Description: Prompts user to enter band colors, verifies that they are proper
 * 		input values, then returns the string or prints an error, and 
 *		requests another input.
 */

char *input_color_code(char *prompt)
{
        int i, j, result1, result2, result3;
	
        char band;
	static char whole_band[5];

        for( i = 1; i <= 4; i++ ) {
                printf("%s %d: ", prompt, i);
                scanf("%s", &band);

		for (j = 0; j < RESISTER_SIZE * 2; j++) {
        	        result1 = strncmp(&band, &LETTER_SEARCH[j], 1);
			result2 = strncmp(&band, "z", 1);
			result3 = strncmp(&band, "Z", 1);

			if ((result1 == 0) || (result2 == 0) || (result3 == 0)) {	
                		strncat(whole_band, &band, 1);
				break;
			}
		} 
		if ((result1 != 0) && (result2 != 0) && (result3 != 0)) {
			printf("I'm sorry, but \"%c\" is not a valid color"
                                " code.\n", band);
                        display_resister_selection_menu();
                        printf("Please try again.\n");
			--i;
		}
	}
        return whole_band;
}

/*
 * Function: band1_num()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: band1[ ]
 * Outputs: * none *
 * Globals: * none *
 * Returns: band - value the band1 input represents
 * Description: Takes in the character array and assigns a proper value.
 */

int band1_num(char band1[ ])
{
	int band;

        switch (band1[0]) {
                case 'a':
		case 'A':
                        band = 0;
                        break;
                case 'b':
		case 'B':
                        band = 10;
                        break;
                case 'c':
		case 'C':
                        band = 20;
                        break;
                case 'd':
                case 'D':
                        band = 30;
                        break;
                case 'e':
                case 'E':
                        band = 40;
                        break;
                case 'f':
                case 'F':
                        band = 50;
                        break;
                case 'g':
                case 'G':
                        band = 60;
                        break;
                case 'h':
                case 'H':
                        band = 70;
                        break;
                case 'i':
                case 'I':
                        band = 80;
                        break;
                case 'j':
                case 'J':
                        band = 90;
                        break;
	}

	return band;
}

/*
 * Function: band2_num()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: band2[ ]
 * Outputs: * none *
 * Globals: * none *
 * Returns: band - value the band2 input represents
 * Description: Takes in the character array and assigns a proper value.
 */

int band2_num(char band2[ ])
{
	int band;

        switch (band2[0]) {
                case 'a':
                case 'A':
                        band = 0;
                        break;
                case 'b':
                case 'B':
                        band = 1;
                        break;
                case 'c':
                case 'C':
                        band = 2;
                        break;
                case 'd':
                case 'D':
                        band = 3;
                        break;
                case 'e':
                case 'E':
                        band = 4;
                        break;
                case 'f':
                case 'F':
                        band = 5;
                        break;
                case 'g':
                case 'G':
                        band = 6;
                        break;
                case 'h':
                case 'H':
                        band = 7;
                        break;
                case 'i':
                case 'I':
                        band = 8;
                        break;
                case 'j':
                case 'J':
                        band = 9;
                        break;
	}

        return band;
}

/*
 * Function: band3_num()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: band3[ ]
 * Outputs: * none *
 * Globals: * none *
 * Returns: band - value the band3 input represents
 * Description: Takes in the character array and assigns a proper value.
 */

int band3_num(char band3[ ])
{
	int band;

        switch (band3[0]) {
                case 'a':
                case 'A':
                        band = 1;
                        break;
                case 'b':
                case 'B':
                        band = 10;
                        break;
                case 'c':
                case 'C':
                        band = 100;
                        break;
                case 'd':
                case 'D':
                        band = 1000;
                        break;
                case 'e':
                case 'E':
                        band = 10000;
                        break;
                case 'f':
                case 'F':
                        band = 100000;
                        break;
                case 'g':
                case 'G':
                        band = 1000000;
                        break;
                case 'h':
                case 'H':
                        band = 10000000;
                        break;
		default:
			puts("ERROR: Improper input for Band 3.");
	}

        return band;
}

/*
 * Function: calculate_resistance()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: band1, band2, band3
 * Outputs: * none *
 * Globals: * none *
 * Returns: resistance
 * Description: Calculates the resistance specific to a set of bands.
 */

int calculate_resistance (int band1, int band2, int band3)
{
	int resistance;

	resistance = (band1 + band2) * band3;

	return resistance;
}

/*
 * Function: tolerance_percentage()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: band4[ ]
 * Outputs: * none * 
 * Globals: * none *
 * Returns: percentage - value the band4 input represents
 * Description: Takes in the character array and assigns a proper value.
 */

double tolerance_percentage(char band4[ ]) 
{
	double percentage;

	switch(band4[0]) {
                case 'a':
                case 'A':
                        percentage = 20;
                        break;
		case 'b':
                case 'B':
			percentage = 1;
                        break;
                case 'c':
                case 'C':
			percentage = 2;
                        break;
                case 'd':
                case 'D':
                        percentage = 20;
                        break;
                case 'e':
                case 'E':
                        percentage = 20;
                        break;
                case 'f':
                case 'F':
			percentage = 0.5;
                        break;
                case 'g':
                case 'G':
			percentage = 0.25;
                        break;
		case 'h':
                case 'H':
			percentage = 0.1;
			break;
		case 'i':
                case 'I':
			percentage = 0.05;
			break;
                case 'j':
                case 'J':
                        percentage = 20;
                        break;
		case 'z':
                case 'Z':
			percentage = 20;
                        break;
	}

	return percentage;
}

/*
 * Function: calculate_tolerance()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: resistance, tolerance, low, high
 * Outputs: low, high
 * Globals: * none *
 * Returns: * none *
 * Description: Calculates the high and low points of the tolerance.
 */

void calculate_tolerances(int resistance, double tolerance, double *low, double *high)
{
	double adjustment;
	adjustment = (tolerance * 0.01) * resistance;
	
	*low = resistance - adjustment;
	*high = resistance + adjustment;

	return;
}

/*
 * Function: print_results()
 * Programmer: Gabrielle Lyons
 * Date: December 4, 2019
 * Inputs: resistance, tolerance, low, high
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Prints out the resistance and tolerance values calculated 
 *		in other functions.
 */

void print_results(int resistance, double tolerance, double low, double high)
{
	printf("Resistance value: %d kilo-ohms.\n", resistance);
	printf("Tolerance: %0.2lf%%, or %0.2lf kilo-ohms to %0.2lf kilo-ohms "
		"variance.\n", tolerance, low, high);

	return;
}
