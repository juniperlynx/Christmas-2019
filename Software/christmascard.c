// Firmware for a Christmas card with a Charlieplexed display
// By:   _           _               
//      (_)_  _ _ _ (_)_ __  ___ _ _ 
//      | | || | ' \| | '_ \/ -_) '_|
//     _/ |\_,_|_||_|_| .__/\___|_|  
//    |__/            |_|  
// Filename: christmascard.c
// Date: Nov 23, 2019

// Define CPU frequency for delay function (must be before delay.h include)
#define F_CPU 800000UL

// Include AVR I/O defines, the delay function, and a 3x5 font
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "christmasdisplay.h"

// Sets constants for animations
#define GREETING_STRING " Hello World!"
#define GREETING_DELAY 175
#define SNOW_PROB 15
#define SNOW_DELAY 225

// Define possible modes
#define SCROLL_MODE 1
#define SNOW_MODE 2

// Declare variable to hold current mode
volatile uint8_t mode = SCROLL_MODE;

// Declare variable to hold surrent phase of screen update
volatile uint8_t phase = 0;

// Declare screen VRAM, least significant 5 bits are columns of screen
uint8_t display[NUM_COLS] = {0x00, 0x00, 0x00, 0x00};

// Sets up DDR, Prescaler, and interrupts
void christmasInit(void) {
    // Set DDRA as input (for now) and DDRB0 & 1 as input
    DDRA = 0;
    DDRB &= ~(_BV(DDB0) | _BV(DDB1));

    // Initialize Timer1
    cli();         // Disable global interrupts
    TCCR1A = 0;    // Clear TCCR1A
    TCCR1B = 0;    // Clear TCCR1B

    // Set prescaler to 1 and WGM 13:10 to 0100 (CTC)
    TCCR1B |= _BV(CS10) | _BV(WGM12);

    // Set output compare register to 1023 (1024 cycles)
    OCR1A = 1023;

    // Enable Timer1 output compare interrupts
    TIMSK1 |= _BV(OCIE1A);

    // Enable global interrupts
    sei();

    // Disable ADC before shutdown
    ADCSRA &= ~_BV(ADEN);

    // Shutdown ADC and USI for power savings
    PRR |= _BV(PRADC) | _BV(PRUSI);
}

// Scrolls the greeting on the display
void scrollChars(const char* greeting) {
    // Declare indexes and buffers
    char scrollbuffer[NUM_COLS * 2];
    uint8_t slice;
    uint8_t strindex;
    uint8_t column;

    // Iterate across string
    for (strindex = 0; strindex < strlen(greeting); strindex++) {
        // Fill scroll buffer with appropriate data for this char
        for (column = 0; column < NUM_COLS; column++) {
            scrollbuffer[column] = getFontCol(greeting[strindex], column);
        }

        // If at the end of the string, fill second char from beginning of greeting
        if (strindex + 1 >= strlen(greeting)) {
            for (column = 0; column < NUM_COLS; column++) {
                scrollbuffer[column + NUM_COLS] = getFontCol(greeting[0], column);
            }
        }
        // Otherwise fill second char from next char
        else {
            for (column = 0; column < NUM_COLS; column++) {
                scrollbuffer[column + NUM_COLS] = getFontCol(greeting[strindex + 1], column);
            }
        }

        // Iterate through each slice of scroll
        for (slice = 0; slice < NUM_COLS; slice++) {
            // Copy each column for this slice
            for (column = 0; column < NUM_COLS; column++) {
                display[column] = scrollbuffer[slice + column];
            }
            // Delay after each slice
            _delay_ms(GREETING_DELAY);
        }
    }
}

// Runs a crude falling snow animation
void animateSnow() {
    // Declare index
    uint8_t column;

    // iterate across each column
    for (column = 0; column < NUM_COLS; column++) {
       // If set the top bit 15% of the time
       if (rand() % 100 < SNOW_PROB) {
           display[column] |= 1 << (NUM_ROWS + 1);
       }
       // Shift all bits down (snow's gotta fall)
       display[column] = display[column] >> 1;
    }

    // Delay after each frame
    _delay_ms(SNOW_DELAY);
}

// Timer0 ISR
ISR(TIM1_COMPA_vect) {
    // Display current bit
    displayBit(phase, display);

    // Increment phase, loop if NUM_LEDS exceeded
    phase++;
    if (phase >= NUM_LEDS) {
        phase = 0;
    }

    // If "A" pressed, but not "B", switch to scroll mode
    if ((PINB & _BV(PB0)) && !(PINB & _BV(PB1))) {
        mode = SCROLL_MODE;
    }
    // If "B" pressed, switch to snow mode
    if ((PINB & _BV(PB1)) && !(PINB & _BV(PB0))) {
        mode = SNOW_MODE;
    }
}

int main(void) {
    const char greeting[] = GREETING_STRING;

    // Setup DDRs, interrupts, &c
    christmasInit();

    // Cycle modes, Wait for interrupts
    while(1) {
        switch (mode) {
            case SCROLL_MODE :
                scrollChars(greeting);
                break;
            case SNOW_MODE :
                animateSnow();
                break;
       }
    }
}
