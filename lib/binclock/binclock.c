#include <stdbool.h>

// represents a led, which has an identifiying pin number and a state on/off
typedef struct {
    int num;
    bool on;
} led;

// FUNCTION DEFS
char* int2bin(int, char*, int);

// converts an integer number into a string of 0s and 1s
char* int2bin(int a, char *buffer, int buf_size) {
    int i = 0; // for the for loop
    buffer += (buf_size - 1);

    for (i = buf_size - 1; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';
        a >>= 1;
    }

    return buffer;
}
