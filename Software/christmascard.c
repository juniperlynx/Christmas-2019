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
#include "christmasfont.h"

// Sets number of LEDs and rows / cols for display routine
#define NUM_LEDS 20
#define NUM_ROWS 5
#define NUM_COLS 4

// Sets text for greeting
#define GREETING_STRING "HELLO WORLD! "

// Declare variable to hold surrent phase of screen update
volatile uint8_t phase = 0;

// Declare screen VRAM, least significant 5 bits are columns of screen
volatile uint8_t display[NUM_COLS] = {0x00, 0x00, 0x00, 0x00};

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

// Timer0 ISR
ISR(TIM1_COMPA_vect) {
    // Clear DDRA and PORTA
    DDRA = 0;
    PORTA = 0;

    // Light current phase's LED if a one is present in the corresponding bit
    if (display[phase / NUM_ROWS] >> (phase % NUM_ROWS) & 0x01) {
        lightLED(phase);
    }

    // Increment phase and iterate for each LED
    phase++;
    if (phase >= NUM_LEDS) {
        phase = 0;
    }
}

int main(void) {
    const char greeting[] = GREETING_STRING;
    char scrollbuffer[NUM_COLS * 2];
    int slice;
    int stringindex;
    int column;

    // Setup DDRs, interrupts, &c
    christmasInit();



    // Cycle chars, Wait for interrupts
    while(1) {
        for (stringindex = 0; stringindex < strlen(greeting); stringindex++) {
            // Fill scroll buffer with appropriate data for this char
            for (column = 0; column < NUM_COLS; column++) {
                scrollbuffer[column] = font[greeting[stringindex]][column];
            }

            // If at the end of the string, fill second char from beginning of greeting
            if (stringindex + 1 >= strlen(greeting)) {
                for (column = 0; column < NUM_COLS; column++) {
                     scrollbuffer[column + NUM_COLS] = font[greeting[0]][column];
                }
            }
            // Otherwise fill second char from next char
            else {
                for (column = 0; column < NUM_COLS; column++) {
                     scrollbuffer[column + NUM_COLS] = font[greeting[stringindex + 1]][column];
                }
            }

            // Iterate through each slice of scroll
            for (slice = 0; slice < NUM_COLS; slice++) {
                // Copy each column for this slice
                for (column = 0; column < NUM_COLS; column++) {
                    display[column] = scrollbuffer[slice + column];
                }
                // Delay after each slice
                _delay_ms(250);
            }
        }
    }
}
