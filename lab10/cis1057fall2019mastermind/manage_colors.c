#include <stdio.h>
#include "mastermind.h"

/*
 * Function:    getKeyCode
 * Description: Prompts the user for the key and reads it in to the four
 *              formal arguments.
 * Inputs: array a      
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 */
void getKeyCode( char a[] )
{ 
	int i;

	puts( "Enter a four-character key code:" );
	
	for ( i = 0; i < 4; i++ )
		a[ i ] = getchar();
	scanf( "%*c" );				// discard the newline character

	return;
}



/*
 * Function:    printKeyCode
 * Description: Displays to the screen the full names of the colors passed in as 
 *              formal arguments.
 * Inputs: array a
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 */
void printKeyCode( char a[] )
{
	puts( "The key is: " );

	printf( "%s %s %s %s\n", getColorString( a[ 0 ] ), getColorString( a[ 1 ] ),
                                 getColorString( a[ 2 ] ), getColorString( a[ 3 ] ) );

	return;
}



/*
 * Function:    getColorString
 * Description: Converts a single key code into it's English equivalent. 
 * Inputs: a - letter to signify color
 * Outputs: * none *
 * Globals: * none *
 * Returns: color associated to input letter
 */
char * getColorString( char a )
{
	switch ( a ) {
		case 'p': case 'P': return "Purple";
		case 'b': case 'B': return "Blue";
		case 'g': case 'G': return "Green";
		case 'y': case 'Y': return "Yellow";
		default:	    return COLOR_NOT_FOUND_MESSAGE;
	}
}


/*
 * Function:    getMMString
 * Description: Converts a single key code into it's English equivalent. 
 * Inputs: r - response symbol in words
 * Outputs: * none *
 * Globals: * none *
 * Returns: symbol associated with input
 */
char * getMMString( mastermind_response_t r )
{
	switch ( r ) {
		case asterisk: return "*";
		case dot:      return ".";
		case plus:     return "+";
		default:       return RESPONSE_NOT_FOUND_MESSAGE;
	}
}
