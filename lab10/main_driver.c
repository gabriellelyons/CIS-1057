#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"
#include "mastermind.h"

// Driver to test the reading of the color key codes
int main()
{
        char guess_codes_from_user[ 4 ];

        program_banner( "Driver to test color codes." );

        // read in four input codes
        getKeyCode( guess_codes_from_user );

        printf( "Echo print: %c %c %c %c\n",
                guess_codes_from_user[ 0 ], guess_codes_from_user[ 1 ],
                guess_codes_from_user[ 2 ], guess_codes_from_user[ 3 ] );

        // display as words
        printKeyCode( guess_codes_from_user );

        // and test out our responses
        mastermind_response_t resp = dot;
        printf( "Our Three Responses: %s  ", getMMString( resp++ ) );
        printf(                      "%s  ", getMMString( resp++ ) );
        printf(                      "%s\n", getMMString( resp ) );

        return EXIT_SUCCESS;
}
