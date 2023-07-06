#include "encrypt.h"

void encrypt(char *message) {
    while (*message) // anything but 0 evaluated as true 
    {
        *message = *message ^ 31;
        message++;
    }
}