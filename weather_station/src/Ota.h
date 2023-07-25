#ifndef OTA_H_
#define OTA_H_

#include "Arduino.h"
#include "ArduinoOTA.h"

class Ota
{
private:
	bool debug_;
    template <typename Generic>
    void DEBUG_OTA(Generic text);

public:
    Ota(/* args */);
    ~Ota();
    void setup (void);
    void begin (void);
    void setDebug (bool);

};


#endif // OTA_H_