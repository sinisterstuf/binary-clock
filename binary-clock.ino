#include <Time.h>

// we've just got 5 LEDs here, which is supposed to show an hour 0-23
#define NUM_LEDS 6

// represents a led, which has an identifiying pin number and a state on/off
typedef struct {
    int num;
    boolean on;
} led;

// array of connected leds
led leds[NUM_LEDS] = {{13, false}, {12, false}, {11, false}, {10, false}, {9, false}, {8, false}};

// FUNCTION DEFS
char *int2bin(int, char*, int);

// converts an integer number into a string of 0s and 1s
char *int2bin(int a, char *buffer, int buf_size) {
    int i = 0; // for the for loop
    buffer += (buf_size - 1);

    for (i = buf_size - 1; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';
        a >>= 1;
    }

    return buffer;
}

void setup() {
    // initialize the pins as output and set all to LOW
    for(int i = 0; i < NUM_LEDS; i++) {
        pinMode(leds[i].num, OUTPUT);
        digitalWrite(leds[i].num, LOW);
    }
}

void loop() {
    int number = second();

    char buffer[NUM_LEDS + 1]; //the +1 is for the \0 null terminator
    buffer[NUM_LEDS] = '\0';
    int2bin(number, buffer, NUM_LEDS);
    for(int i; i < NUM_LEDS; i++) {
        if ( buffer[i] == '0' ) {
            leds[i].on = false;
            digitalWrite(leds[i].num, LOW);
        } else if ( buffer[i] == '1' ) {
            leds[i].on = true;
            digitalWrite(leds[i].num, HIGH);
        } else {
            return;
        }
    }
}
