#include <Arduino.h>

int readPin = 7;
int ledPin = 8;

int previousState;

void setup()
{
    Serial.begin(9600);
    pinMode(readPin, INPUT);
    previousState = digitalRead(readPin);
}

void loop()
{
    int pinState = digitalRead(readPin);
    if (pinState != previousState)
    {
        Serial.println(pinState);
    }
    previousState = pinState;
    delay(100);
}
