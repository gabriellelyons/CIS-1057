#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myheader.h"
#include "resister.h"

int main()
{
        puts("Enter the colors of the resistor’s three "
                "bands, staring with the one on the left.");
        puts("Menu of options to select from: ");

        int i;
	int j = i;

        for ( i = 0; i < RESISTER_SIZE; i++ )
                printf("%c) %s\n", LETTER[j + 2], RESISTER_CODES[i]);
                printf("z) BLANK\n");
        return EXIT_SUCCESS;
}

