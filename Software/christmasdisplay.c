// Display function file for a Christmas card with a Charlieplexed display
// By:   _           _               
//      (_)_  _ _ _ (_)_ __  ___ _ _ 
//      | | || | ' \| | '_ \/ -_) '_|
//     _/ |\_,_|_||_|_| .__/\___|_|  
//    |__/            |_|  
// Filename: christmasdisplay.c
// Date: Nov 28, 2019

// Include AVR I/O defines, the delay function, and a 3x5 font
#include <avr/io.h>
#include "christmasdisplay.h"
#include "christmasfont.h"

// Lights an individual LED as specified. Expects PORTA and DDRA to be cleared first.
// I know this is uncreative, but eh...
// Physically mapped as follows:
//     4  9  14 19
//     3  8  13 18
//     2  7  12 17
//     1  6  11 16
//     0  5  10 15
void lightLED(uint8_t led) {
    // Set needed bits
    switch (led) {
        case 0 :
            DDRA |= _BV(PA0) | _BV(PA1);
            PORTA |= _BV(PA0);
            break;
        case 1 :
            DDRA |= _BV(PA0) | _BV(PA1);
            PORTA |= _BV(PA1);
            break;
        case 2 :
            DDRA |= _BV(PA0) | _BV(PA2);
            PORTA |= _BV(PA2);
            break;
        case 3 :
            DDRA |= _BV(PA0) | _BV(PA3);
            PORTA |= _BV(PA3);
            break;
        case 4 :
            DDRA |= _BV(PA0) | _BV(PA7);
            PORTA |= _BV(PA7);
            break;
        case 5 :
            DDRA |= _BV(PA0) | _BV(PA2);
            PORTA |= _BV(PA0);
            break;
        case 6 :
            DDRA |= _BV(PA1) | _BV(PA2);
            PORTA |= _BV(PA1);
            break;
        case 7 :
            DDRA |= _BV(PA1) | _BV(PA2);
            PORTA |= _BV(PA2);
            break;
        case 8 :
            DDRA |= _BV(PA1) | _BV(PA3);
            PORTA |= _BV(PA3);
            break;
        case 9 :
            DDRA |= _BV(PA1) | _BV(PA7);
            PORTA |= _BV(PA7);
            break;
        case 10 :
            DDRA |= _BV(PA0) | _BV(PA3);
            PORTA |= _BV(PA0);
            break;
        case 11 :
            DDRA |= _BV(PA1) | _BV(PA3);
            PORTA |= _BV(PA1);
            break;
        case 12 :
            DDRA |= _BV(PA2) | _BV(PA3);
            PORTA |= _BV(PA2);
            break;
        case 13 :
            DDRA |= _BV(PA2) | _BV(PA3);
            PORTA |= _BV(PA3);
            break;
        case 14 :
            DDRA |= _BV(PA2) | _BV(PA7);
            PORTA |= _BV(PA7);
            break;
        case 15 :
            DDRA |= _BV(PA0) | _BV(PA7);
            PORTA |= _BV(PA0);
            break;
        case 16 :
            DDRA |= _BV(PA1) | _BV(PA7);
            PORTA |= _BV(PA1);
            break;
        case 17 :
            DDRA |= _BV(PA2) | _BV(PA7);
            PORTA |= _BV(PA2);
            break;
        case 18 :
            DDRA |= _BV(PA3) | _BV(PA7);
            PORTA |= _BV(PA3);
            break;
        case 19 :
            DDRA |= _BV(PA3) | _BV(PA7);
            PORTA |= _BV(PA7);
            break;
    }
}

void displayBit(int phase, uint8_t display[NUM_COLS]) {
    // Clear DDRA and PORTA
    DDRA = 0;
    PORTA = 0;

    // Light current phase's LED if a one is present in the corresponding bit
    if (display[phase / NUM_ROWS] >> (phase % NUM_ROWS) & 0x01) {
        lightLED(phase);
    }
}

// Wrapper to grab characters from the font function by column 
uint8_t getFontCol(char character, int column) {
    if (column >= NUM_COLS - 1) {
        return 0x00;
    }
    else {
        return font[character][column];
    }
}
