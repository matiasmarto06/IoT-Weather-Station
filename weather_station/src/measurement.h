#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <Arduino.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "Photoresistor.h"

#include "Date.h"
#define UTC_3 -10800

class Measurement
{
private:
    unsigned long           timer_; 
    DHT                     dht_;
    WiFiUDP                 ntpUDP_;
    NTPClient               timeClient_;
    Photoresistor           ph_;
    float                   t_;
    float                   h_;
    float                   l_;
    Date                    timestamp_;
    boolean                 _debug = true;

public:
                Measurement         (int pin_, int type_);
                Measurement         (void);
                ~Measurement        (void);
    void        set                 (float, float, Date);
    void        update              (unsigned long delay);
    void        begin               (void);
//  int         fromString          (String);
    String      toString            (void);
    void        setDebugOutput      (boolean);
    template    <typename Generic>
    void        DEBUG_M             (Generic text);
};

#endif // MEASUREMENT_H_