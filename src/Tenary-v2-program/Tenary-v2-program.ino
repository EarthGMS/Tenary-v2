#include "Arduino.h"
#include "BinaryToBaseTen.h"
#include "MathOperation.h"
// #include "OutputBinary.h"
// #include "ClearCode.h"
/*Tenary 2.0
Made by : Pongsapat Boonpong
Purpose : To extend functions and applications from the Tenary 1.0
Version : v2.0
Finish date : TBD
*/

// input value
uint8_t Set1Val = 0;
uint8_t Set2Val = 0;

// Result value
uint8_t Result;

// Text
String modeText;
void setup()
{
    // Indicator setup
    pinMode(2, OUTPUT); // Error pin
    pinMode(3, OUTPUT); // Negative pin

    // 74HC595 setup
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);

    // Set mode pins
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);

    // Input setup
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);

    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop()
{
    // Reset set1, set2 and math result
      Set1Val = 0;
      Set2Val = 0;
      Result = 0;
    // Turn off output pins
    // ResetPin();

    // Turn off LED indicator pin
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
    // Convert binary input to integers
    Set1Val = BinaryConvert(7);
    Set2Val = BinaryConvert(10);

    // Print value of set 1, set 2, mode
    Serial.print("Set 1 : ");
    Serial.println(Set1Val);
    Serial.print("Set 2 : ");
    Serial.println(Set2Val);

    // Display mode
//    if (digitalRead(A0) == 0)
//    {
//        modeText = "Add";
//    }
//    else if (digitalRead(A1) == 0)
//    {
//        modeText = "Sub";
//    }
    if (digitalRead(A2) == 0)
    {
        modeText = "Mul";
    }
//    else if (digitalRead(A3) == 0)
//    {
//        modeText = "Div";
//    }
//    else{
//        modeText = "ERROR";
//    }


    // Math operation function (set1, set2)
    Result = MathCalculate(Set1Val, Set2Val, modeText);
    Serial.println("Result : " + String((int)Result));

    // Print math result and mode
    Serial.println("Mode : " + modeText);

    
    /* TBD

    // Set up negative pins
    if (Result < 0)
    {
        digitalWrite(4, HIGH);
    }

    if (Result == NULL)
    {
        Serial.println("ERROR");
        delay(2000);
        return;
    }

    // Output setup function
    IntegerOutputCalculate(Result);
    DecimalOutputCalculate(Result);
    */
    Serial.println("**************************");

    // delay for 2 secs and repeat
    delay(2000);
}
