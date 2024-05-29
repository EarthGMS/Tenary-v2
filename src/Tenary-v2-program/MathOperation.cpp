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

uint8_t MathCalculate(uint8_t set1, uint8_t set2, String ChooseMode)
{
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

    mathMode = Mul;

    switch (mathMode)
    {
    case Add:
        return set1 + set2;
        break;
    case Sub:
        uint8_t SubResult = set1 - set2;
        if (SubResult > 7){
          digitalWrite(2, HIGH); //Open negative LED
          return (abs)((int8_t)(SubResult));
        }
        break;
    case Mul:
        return set1 * set2;
        break;
    case Div:
        if (set2 == 0)
        {
            return 0;
        }
        return set1 / set2;
        break;

    default:
        return 0;
        break;
    }
}
