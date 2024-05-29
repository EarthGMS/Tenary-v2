#include "Arduino.h"
#include "OutputBinary.h"
#include "math.h"

uint8_t decimalVal;

void OutputCalculate(double CalResult)
{
    round(CalResult);
    decimalVal = CalResult;
    decimalVal += 0.5;
    round(decimalVal);
    Serial.println("Result : ");
    //Serial.print(build16BitValue(CalResult, decimalVal)); [ERROR POINT]
}
/* [TBD]
uint16_t build16BitValue(uint8_t intPart, double decPart)
{
    //uint16_t returnValue = buildBitsForInt(intPart); [ERROR POINT]
    returnValue |= buildBitsForDecimal(decPart);
    return returnValue;
}
uint16_t buildBitsForInt(uint8_t CalculateNum)
{
    uint16_t returnValue = 0;
    uint8_t bitNumber = 2;
    for (int i = 0; i <= 5; i++)
    {
        if (CalculateNum % 2)
        {
            bits_setBit(&returnValue, bitNumber);
        }
        bitNumber++;
    }
}
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
*/
