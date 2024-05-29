#include "Arduino.h"

// Binary to base 10 script

double result;


uint8_t BinaryConvert(uint8_t startPin)
{
    result = 0;
    // Read digital input from 2 input sets
    for (int i = 0; i <= 2; i++)
    {
        if (digitalRead(i + startPin) == 0){
          result += round(pow(2,i));
        }
    }
    return result;
}

