// Display function header for a Christmas card with a Charlieplexed display
// By:   _           _               
//      (_)_  _ _ _ (_)_ __  ___ _ _ 
//      | | || | ' \| | '_ \/ -_) '_|
//     _/ |\_,_|_||_|_| .__/\___|_|  
//    |__/            |_|  
// Filename: christmasdisplay.h
// Date: Nov 28, 2019


// Sets number of LEDs and rows / cols for display routine
#define NUM_LEDS 20
#define NUM_ROWS 5
#define NUM_COLS 4

extern void displayBit(int phase, uint8_t display[NUM_COLS]);
extern uint8_t getFontCol(char character, int column);
