#include <stdio.h>
#include <time.h>
#ifndef MYHEADER_H
#define MYHEADER_H
#define PRIME_PROGRAMMER "Gabrielle Lyons" 

/*
 * Function: program_banner() 
 * Programmer: Gabrielle Lyons
 * Date: September 18, 2019
 * Inputs: description_of_code - description of what program will do
 * Outputs: * none *
 * Globals: * none *
 * Returns: * none *
 * Description: Reads in a description and a date then prints the banner.
 */

void program_banner( const char *description_of_code )
{
	time_t t;
	time(&t);

        printf( "Programmed by %s, ", PRIME_PROGRAMMER );
	printf( "compiled on %s", ctime(&t) );
	printf( "%s\n", description_of_code );
        return;
}

#endif // MYHEADER_H

