#include <pins_arduino.h>
#include <Arduino.h>

byte a = 10;
byte b = 9;
byte c = 6;
byte d = 7;
byte e = 8;
byte f = 11;
byte g = 12;

bool a_arr[10] = { true, false, true, true, false, true, true, true, true, true };
bool b_arr[10] = { true, true, true, true, true, false, false, true, true, true };
bool c_arr[10] = { true, true, false, true, true, true, true, true, true, true };
bool d_arr[10] = { true, false, true, true, false, true, true, false, true, false};
bool e_arr[10] = { true, false, true, false, false, false, true, false, true, false};
bool f_arr[10] = { true, false, false, false, true, true, true, false, true, true };
bool g_arr[10] = { false, false, true, true, true, true, true, false, true, true };

void setup()
{
    // set up 7 pins for output -- maybe 6 w/o DP
    // 12- 5
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);

    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    // define arrays for the numbers
}

void loop()
{

    for (int i = 0; i < 10; i++)
    {
        delay(500);
        digitalWrite(a, a_arr[i] ? HIGH : LOW);
        digitalWrite(b, b_arr[i] ? HIGH : LOW);
        digitalWrite(c, c_arr[i] ? HIGH : LOW);
        digitalWrite(d, d_arr[i] ? HIGH : LOW);
        digitalWrite(e, e_arr[i] ? HIGH : LOW);
        digitalWrite(f, f_arr[i] ? HIGH : LOW);
        digitalWrite(g, g_arr[i] ? HIGH : LOW);
        delay(500);
    }
}
