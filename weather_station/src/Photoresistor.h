#include "Arduino.h"

class Photoresistor
{
private:
    int pin_ = A0;
    bool _debug = false;
    int _value;

public:
                Photoresistor       (int);
                ~Photoresistor      ();
    float       readLightness       (void);
    void        setDebugOutput      (boolean);
    template    <typename Generic>
    void        DEBUG_PH            (Generic text);

};
