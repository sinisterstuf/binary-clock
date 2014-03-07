#include <stdbool.h>

// represents a led, which has an identifiying pin number and a state on/off
typedef struct {
    int num;
    bool on;
} led;

// converts an integer number into a string of 0s and 1s
char* int2bin(int, char*, int);
