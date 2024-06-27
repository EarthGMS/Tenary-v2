#include <Arduino.h>

void ResetPin()
{
    for (int i = 0; i < 16; i++)
    {
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(5);
        digitalWrite(6, LOW);
    }

    delay(50);
    digitalWrite(4, HIGH);
    delay(50);
    digitalWrite(4, LOW);
}
