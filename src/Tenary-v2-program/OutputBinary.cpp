#include "Arduino.h"
#include "OutputBinary.h"
#include "math.h"

double decimalVal;
String ResultInt;

void OutputCalculate(double CalResult, double DecimalResult)
{
    ResultInt = "0000000000000000";
    decimalVal = DecimalResult - CalResult;
    
    round(CalResult);
    Serial.print("Binary Result : ");
    build16BitValue(CalResult, decimalVal);
    Serial.println(ResultInt);
    Serial.print("DECIMAL BINARY : ");
    for (int i = 0; i < 8; i++){
      Serial.print(ResultInt[i]);
    }
    Serial.println("");
    Serial.print("INTEGER BINARY : ");
    for (int j = 8; j < 16; j++){
      Serial.print(ResultInt[j]);
    }
    Serial.println("");
    shiftOut();
}

void build16BitValue(uint8_t intPart, double decPart)
{
    buildBitsForDecimal();
    buildBitsForInt(intPart);
}
void buildBitsForInt(uint8_t CalculateNum)
{
    uint8_t bitNumber = 7;
    for (int i = 0; i < 6; i++)
    {
        if (CalculateNum % 2)
        {
            ResultInt[i+8] = '1';
            digitalWrite(5, HIGH);
        }
        else{
            ResultInt[i+8] = '0';
            digitalWrite(5, LOW);
        }
        digitalWrite(6, HIGH); 
        delay(5);  
        digitalWrite(6, LOW);
        CalculateNum /= 2;
        bitNumber++;
    }
}

void buildBitsForDecimal()
{
 
    for (int i = 0; i < 6; i++)
    {
        decimalVal*= 2;
        if (decimalVal >= 1.00){
          decimalVal-= 1;
          ResultInt[i] = '1';
          digitalWrite(5, HIGH);
        }
        else{
          ResultInt[i] = '0';
          digitalWrite(5, LOW);
        }
        digitalWrite(6, HIGH); 
        delay(5);  
        digitalWrite(6, LOW);
    }
}

void shiftOut()
{
    for (int i = 0; i < 16; i++){
      if (ResultInt[i] == '1'){
        digitalWrite(5, HIGH);
      }
      else{
        digitalWrite(5, LOW);
      }
      digitalWrite(6, HIGH); 
      delay(5);  
      digitalWrite(6, LOW);

    }
}

