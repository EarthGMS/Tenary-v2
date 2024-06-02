#include "Arduino.h"
#include "MathOperation.h"

// Mode
typedef enum mode
{
    Add,
    Sub,
    Mul,
    Div
};

mode mathMode;

void MathCalculate(uint8_t set1, uint8_t set2, String ChooseMode, uint8_t &Result, double &DecimalResult)
{
    uint8_t SubResult = 0;
    if (ChooseMode == "Add")
    {
        mathMode = Add;
    }
    else if (ChooseMode == "Sub")
    {
        mathMode = Sub;
    }
    else if (ChooseMode == "Mul")
    {
        mathMode = Mul;
    }
    else if (ChooseMode == "Div")
    {
        mathMode = Div;
    }

    switch (mathMode)
    {
    case Add:
        Result = set1 + set2;
        DecimalResult = 0;
        break;
    case Mul:
        Result = set1 * set2;
        DecimalResult = 0;
        break;
    case Div:
        if (set2 == 0){
          Result = 0;
          digitalWrite(3, HIGH);
          break;
        }
        Result = (set1 / set2) + 0.5;
        DecimalResult = (double)set1 / (double)set2;
        break;
    case Sub:
        SubResult = set1 - set2;
        if (SubResult > 7){
          digitalWrite(2, HIGH); //Open negative LED
          SubResult = (abs)((int8_t)(SubResult));
        }
        Result = SubResult;
        DecimalResult = 0;
        break;
    default:
        Result = 0;
        DecimalResult = 0;
        break;
    }
}


