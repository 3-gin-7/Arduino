#include <Arduino.h>

int ledPin = 8;
int btnPin = 7;

byte lastButtonState;
byte ledState = LOW;

unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDuration = 50;

void setup ()
{
    pinMode(ledPin, OUTPUT);
    pinMode(btnPin, INPUT);
    lastButtonState = digitalRead(btnPin);
}

void loop()
{
    if(millis() - lastTimeButtonChanged >= debounceDuration)
    {
        byte buttonState = digitalRead(btnPin);
        if(buttonState != lastButtonState)
        {
            lastTimeButtonChanged = millis();
            buttonState = lastButtonState;
            if(buttonState == LOW)
            {
                if(ledState == HIGH)
                {
                    ledState = LOW;
                }else
                {
                    ledState = HIGH;
                }
                digitalWrite(ledPin, ledState);
            }
        }
    }
}
