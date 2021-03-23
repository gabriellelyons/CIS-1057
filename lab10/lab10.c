#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"
#include "mastermind.h"

/*
 * Location: Temple University Computer Science
 * Programmer: Gabrielle Lyons
 * Class: Intro to C Programming 1057:005 Fall 2019
 * Assignment: Lab 10
 * Date: November 6, 2019
 * Version: 1
 * Description: Runs the game Mastermind.
 */

void getGuessCode( char a[] );
int codeCheck( char keyCode[], char guessCode[] );
int winOrLose( int correct );

int main()
{
	program_banner( "Let's play Mastermind!" );

	char keyCode[4], guessCode[4];
	int i, correct;

	getKeyCode( keyCode );
	printKeyCode( keyCode );

	for( i = 1; i <= 8; i++ ) {
		getGuessCode( guessCode );

		correct = codeCheck( keyCode, guessCode );
		i = winOrLose( correct );
	}

	return EXIT_SUCCESS;
}

/*
 * Function: getColorString
 * Programmer: Ray Lauff
 * Date: November 6, 2019
 * Inputs: a - character to change to English or send error
 * Outputs: * none *
 * Globals: * none *
 * Returns: string related to input character or error message
 * Description: Converts a single key code into it's English equivalent.
 */

char *getColorString( char a )
{
        switch ( a ) {
                case 'p': case 'P': return "Purple";
                case 'b': case 'B': return "Blue";
                case 'g': case 'G': return "Green";
                case 'y': case 'Y': return "Yellow";
                default:            return COLOR_NOT_FOUND_MESSAGE;
        }

}

/*
 * Function: getKeyCode()
 * Programmer: Ray Lauff
 * Date: November 6, 2019
 * Inputs: * none *
 * Outputs: a[] - filled with the key input
 * Globals: * none *
 * Returns: * none *
 * Description: Prompts the user for the key and reads it in to the four formal
 *		arguments.
 */

void getKeyCode( char a[] )
{
        int i;

        puts( "Enter a four-character key code:" );

        for ( i = 0; i < 4; i++ )
                a[ i ] = getchar();
        scanf( "%*c" ); 

        return;
}


/*
 * Function: printKeyCode()
 * Programmer: Ray Lauff
 * Date: November 6, 2019
 * Inputs: a[] - array consisting of four elements to be printed
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Displays to the screen the full names of the colors passed in as
 *		formal arguments.
 */

void printKeyCode( char a[] )
{
	puts( "The key is: " );
	printf( "%s %s %s %s\n", getColorString( a[ 0 ] ), getColorString( a[ 1 ] ),
				getColorString( a[ 2 ] ), getColorString( a[ 3 ] ) );

	return; 
}

/*
 * Function: getGuessCode()
 * Programmer: Gabrielle Lyons
 * Date: November 6, 2019
 * Inputs: * none * 
 * Outputs: a[] - filled with the input guess
 * Globals: * none *
 * Returns: * none *
 * Description: Prompts player 2 to guess that colors and puts that guess into
 *		an array.
 */

void getGuessCode( char a[] )
{
	int i;

	puts( "Enter your guess:" );

	for( i = 0; i < 4; i++ )
		a[ i ] = getchar();
        scanf( "%*c" );

	return;
}

/*
 * Function: codeCheck()
 * Programmer: Gabrielle Lyons
 * Date: November 6, 2019
 * Inputs: keyCode[], guessCode[] - two arrays to compare values of
 * Outputs: * none *
 * Globals: * none *
 * Returns: correct - how many values of the array are the same
 * Description: Compares the key and guess inputs to tell the user how close
 *		they are getting to the right input.
 */

int codeCheck(char keyCode[], char guessCode[])
{
	int correct;
	char answerA, answerB, answerC, answerD;

	correct = 0;

	if( guessCode[0] == keyCode[0] ) {
		answerA = '*';
		correct++;
	}
	else if( (guessCode[0] == keyCode[1]) || (guessCode[0] == keyCode[2])
                        || (guessCode[0] == keyCode[3]) )
                answerA = '+';
	else
                answerA = '.';

	if( guessCode[1] == keyCode[1] ) {
		answerB = '*';
		correct++;
	}
	else if( (guessCode[1] == keyCode[0]) || (guessCode[1] == keyCode[2])
                        || (guessCode[1] == keyCode[3]) )
                answerB = '+';
	else
                answerB = '.';

	if( guessCode[2] == keyCode[2] ) {
		answerC = '*';
		correct++;
	}
	else if( (guessCode[2] == keyCode[0]) || (guessCode[2] == keyCode[1])
                        || (guessCode[2] == keyCode[3]) )
                answerC = '+';
	else
                answerC = '.';

	if( guessCode[3] == keyCode[3] ) {
		answerD = '*';
		correct++;
	}
	else if( (guessCode[3] == keyCode[0]) || (guessCode[3] == keyCode[1])
                        || (guessCode[3] == keyCode[2]) )
                answerD = '+';
	else
                answerD = '.';

	printf("%c %c %c %c", answerA, answerB, answerC, answerD);

	return correct;
}

/*
 * Function: winOrLose()
 * Programmer: Gabrielle Lyons
 * Date: November 6, 2019
 * Inputs: correct - pulled number of correct inputs for the game
 * Outputs: * none *
 * Globals: * none *
 * Returns: i - 8 if game won so loop ends in main
 * Description: Prints a winning, losing, or try again prompt.
 */

int winOrLose( int correct )
{
	int i;

	if ( correct == 4) {
		i = 8;
		printf( "\nCongratulations, you won!\n" );
	}
	else if ( correct < 4 )
		printf( "\nTry again.\n");
	else
		printf( "\nYou lose!\n" ); 
	return i;
}
