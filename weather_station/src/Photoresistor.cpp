#include "Photoresistor.h"

Photoresistor::Photoresistor(int pin) : pin_(pin)
{
    DEBUG_PH("pin selected " + pin_);
    pinMode(pin_, INPUT);
}

float Photoresistor::readLightness(void)
{
    DEBUG_PH("measures: " + String(analogRead(pin_)));
    return ((1 - (float) analogRead(pin_)/1024) * 100);
}

Photoresistor::~Photoresistor()
{
    ;
}

void Photoresistor::setDebugOutput(boolean debug) {
  _debug = debug;
}

template <typename Generic>
void Photoresistor::DEBUG_PH(Generic text) {
    if (_debug) {
        Serial.print("*PH: ");
        Serial.println(text);
    }
}
