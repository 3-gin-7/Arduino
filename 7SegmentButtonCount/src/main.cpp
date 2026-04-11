#include "HardwareSerial.h"
#include <Arduino.h>

// out pins
int a = 10;
int b = 9;
int c = 6;
int d = 7;
int e = 8;
int f = 11;
int g = 12;

// in pins
int btnPin = 5;

// state vars
int count = 0;
int MAX_COUNT = 9;
byte lastReading;
int stableState = HIGH;
long lastChangeTime;
int debouceDuration = 50;

// display vars
bool a_arr[10] = { true, false, true, true, false, true, true, true, true, true };
bool b_arr[10] = { true, true, true, true, true, false, false, true, true, true };
bool c_arr[10] = { true, true, false, true, true, true, true, true, true, true };
bool d_arr[10] = { true, false, true, true, false, true, true, false, true, false};
bool e_arr[10] = { true, false, true, false, false, false, true, false, true, false};
bool f_arr[10] = { true, false, false, false, true, true, true, false, true, true };
bool g_arr[10] = { false, false, true, true, true, true, true, false, true, true };

void setup()
{
    Serial.begin(9600);

    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);

    pinMode(btnPin, INPUT_PULLUP);
    lastReading = digitalRead(btnPin);

    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
}

void loop()
{
    int state = digitalRead(btnPin);

    if (state != lastReading)
    {
        lastChangeTime = millis();
    }

    // if (state == LOW)
    // {
    //     Serial.println("state is low");
    // }else if (state == HIGH)
    // {
    //     Serial.println("state is high");
    // }else
    // {
    //     Serial.println("state is something else");
    // }

    if ((millis() - lastChangeTime) > debouceDuration)
    {
        if (state != stableState)
        {
            stableState = state;
            if (state == LOW)
            {
                count++;
                Serial.println("count is: ");
                Serial.println(count);
                if ( count > MAX_COUNT)
                {
                    count = 0;
                }

                digitalWrite(a, a_arr[count] ? HIGH : LOW);
                digitalWrite(b, b_arr[count] ? HIGH : LOW);
                digitalWrite(c, c_arr[count] ? HIGH : LOW);
                digitalWrite(d, d_arr[count] ? HIGH : LOW);
                digitalWrite(e, e_arr[count] ? HIGH : LOW);
                digitalWrite(f, f_arr[count] ? HIGH : LOW);
                digitalWrite(g, g_arr[count] ? HIGH : LOW);
            }
        }
    }

    lastReading = state;
}
