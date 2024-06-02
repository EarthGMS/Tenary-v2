#include "Arduino.h"
#include "OutputBinary.h"
#include "math.h"

uint8_t decimalVal;

void OutputCalculate(double CalResult)
{
    round(CalResult);
    //decimalVal = CalResult;
    //decimalVal += 0.5;
    //round(decimalVal);
    Serial.print("Desired Result : ");
    Serial.println(9);
    Serial.print("Actual Result : ");
    uint16_t BinaryResult = build16BitValue(CalResult/*, decimalVal*/);
    Serial.println(BinaryResult);
}

uint16_t build16BitValue(uint8_t intPart/*, double decPart*/)
{
    uint16_t returnValue = buildBitsForInt(intPart);
    //returnValue |= buildBitsForDecimal(decPart); NOT NOW, ONLY INTEGERS FIRST
    return returnValue;
}
uint16_t buildBitsForInt(uint8_t CalculateNum)
{
    uint16_t returnValue = 0;
    uint8_t bitNumber = 2;
    uint8_t currentReminder = 0;
    for (int i = 0; i <= 5; i++)
    {
        if (CalculateNum % 2)
        {
            bits_setBit(&returnValue, bitNumber);
            CalculateNum /= 2;
        }
        bitNumber++;
    }
    currentReminder = CalculateNum % 2;
    Serial.print("RE : ");
    Serial.println(currentReminder);
    returnValue |= currentReminder;
    return returnValue;
}
/*
uint16_t buildBitsForDecimal(double CalculateNum)
{
    uint16_t returnValue = 0;
    uint8_t bitNumber = 10;
    for (int i = 0; i <= 5; i++)
    {
        bool bitShouldBeSet;
        if (bitShouldBeSet)
            bits_setBit(&returnValue, bitNumber);
        bitNumber++;
    }
    return returnValue;
}
*/
void bits_setBit(uint16_t *bitsPtr, uint8_t bitNumber)
{
    if (bitNumber > 15)
    {
        Serial.println("ERROR!");
        return;
    }
    *bitsPtr |= (1 << bitNumber);
}

void shiftOut(uint8_t CalculateNum, bool mode)
{

}

