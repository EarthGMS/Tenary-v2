#include <Arduino.h>

void ResetPin()
{
    for (int i = 0; i < 15; i++)
    {
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(5);
        digitalWrite(7, LOW);
    }

    delay(50);
    digitalWrite(5, HIGH);
    delay(50);
    digitalWrite(5, LOW);
}
