/*Tenary 2.0
Made by : Pongsapat Boonpong
Purpose : To extend functions and applications from the Tenary 1.0
Version : v2.0
Finish date : TBD
*/

// Indicators
int ErrorPin = 3;
int NegativePin = 4;

// input value
int Set1Val = 0;
int Set2Val = 0;

// Mode
int AddMode;
int SubtractMode;
int MultiplyMode;
int DivideMode;

// Result value
double Result;

void setup()
{
    // Indicator setup
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);

    // 74HC595 setup
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

    // Input setup
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);

    pinMode(11, INPUT);
    pinMode(12, INPUT);
    pinMode(13, INPUT);

    // Set mode pins
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop()
{
    // Turn off output pins

    // Reset set1, set2 and math result
    Set1Val = 0;
    Set2Val = 0;
    Result = 0;

    // Turn off LED indicator pin
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

    // Read digital input from 2 input sets
    for (int i = 0; i <= 2; i++)
    {
        if (digitalRead(i + 8) == 1)
        {
            Set1Val += round(pow(2, i));
        }
        if (digitalRead(i + 11) == 1)
        {
            Set2Val += round(pow(2, i));
        }
    }

    // Read digital input from 4 mode inputs
    AddMode = digitalRead(A0);
    SubtractMode = digitalRead(A1);
    MultiplyMode = digitalRead(A2);
    DivideMode = digitalRead(A3);

    // Print value of set 1 and set 2
    Serial.println("Set 1 : " + Set1Val);
    Serial.println("Set 1 : " + Set2Val);

    // Math operation function (set1, set2)

    // Print math result and mode
    Serial.pintln("Mode : ");
    Serial.println("Result : " + (int)Result);

    // Set up negative pins
    if (Result < 0)
    {
        digitalWrite(4, HIGH);
    }

    // Output setup function

    // delay for 2 secs and repeat
    delay(2000);
}
