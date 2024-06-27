/*Tenary 2.0
Made by : Pongsapat Boonpong & David Lowther
Purpose : To extend functions and applications from the Tenary 1.0
Version : v2.0
Finish date : 9 June 2024
*/

#include "Arduino.h"
#include "BinaryToBaseTen.h"
#include "MathOperation.h"
#include "OutputBinary.h"
#include "ClearCode.h"

// input value
uint8_t Set1Val = 0;
uint8_t Set2Val = 0;

// Result value
uint8_t Result;
double DecimalResult;

//Pins

const int NEG_PIN = 2;
const int ERR_PIN = 3;

const int LCH_PIN = 4;
const int DTA_PIN = 5;
const int CLK_PIN = 6;

const int SET1_1 = 7;
const int SET1_2 = 8;
const int SET1_3 = 9;

const int SET2_1 = 10;
const int SET2_2 = 11;
const int SET2_3 = 12;

int ModeCount;

// Text
String modeText;
void setup()
{
    // Indicator setup
    pinMode(ERR_PIN, OUTPUT); // Error pin
    pinMode(NEG_PIN, OUTPUT); // Negative pin

    // 74HC595 setup
    pinMode(LCH_PIN, OUTPUT); //LATCH
    pinMode(DTA_PIN, OUTPUT); //DATA
    pinMode(CLK_PIN, OUTPUT); //CLOCK

    // Set mode pins
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);

    // Input setup
    pinMode(SET1_1, INPUT_PULLUP);
    pinMode(SET1_2, INPUT_PULLUP);
    pinMode(SET1_3, INPUT_PULLUP);

    pinMode(SET2_1, INPUT_PULLUP);
    pinMode(SET2_2, INPUT_PULLUP);
    pinMode(SET2_3, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop()
{
    // Reset set1, set2 and math result
      Set1Val = 0;
      Set2Val = 0;
      Result = 0;
      DecimalResult = 0;
      ModeCount = 0;
    // Turn off output pins
    ResetPin();
    
    // Turn off LED indicator pin
    digitalWrite(ERR_PIN, LOW);
    digitalWrite(NEG_PIN, LOW);
    
    // Convert binary input to integers
    Set1Val = BinaryConvert(7);
    Set2Val = BinaryConvert(10);

    // Print value of set 1, set 2, mode
    Serial.print("Set 1 : ");
    Serial.println(Set1Val);
    Serial.print("Set 2 : ");
    Serial.println(Set2Val);

    ModeCount += !digitalRead(A0);
    ModeCount += !digitalRead(A1);
    ModeCount += !digitalRead(A2);
    ModeCount += !digitalRead(A3);

    // Display mode
    if (digitalRead(A0) == 0)
    {
        modeText = "Add";
    }
    else if (digitalRead(A1) == 0)
    {
        modeText = "Sub";
    }
    else if (digitalRead(A2) == 0)
    {
        modeText = "Mul";
    }
    else if (digitalRead(A3) == 0)
    {
        modeText = "Div";
    }
    else{
        modeText = "ERROR (NO MODE SELECTED)";
    }

    if(ModeCount > 1){
      Serial.println("ERROR (MORE THAN 1 MODE IS SELECTED");
    }
    else{
      // Print math result and mode
      Serial.println("Mode : " + modeText); 
    }

    // Output setup function
    if (modeText != "ERROR" && ModeCount == 1){
      Serial.print("Result : ");
      // Math operation function (set1, set2)
      MathCalculate(Set1Val, Set2Val, modeText, Result, DecimalResult);
      OutputCalculate(Result, DecimalResult);
    }

    //Shift result to 74HC595
    delay(50);
    digitalWrite(LCH_PIN, HIGH); // Output pulse to RCLK (your REG_LCH)
    delay(50);
    digitalWrite(LCH_PIN, LOW); // End of pulse
    delay(50);

    Serial.println("**************************");
    
    // delay for 2 secs and repeat
    delay(2000);
}
