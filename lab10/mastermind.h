#ifndef MASTERMIND_H
#define MASTERMIND_H

#define COLOR_NOT_FOUND_MESSAGE    "( Error: Unknown Color )"
#define RESPONSE_NOT_FOUND_MESSAGE "( Error: No Such Master Mind Response )"

typedef enum {
        dot, plus, asterisk,
} mastermind_response_t;

// Prototypes
char *getColorString( char a );
void  printKeyCode( char a[] );
void  getKeyCode( char a[] );
char *getMMString( mastermind_response_t response );

#endif // MASTERMIND_H



