#ifndef FILES_H_
#define FILES_H_

#include <Arduino.h>
#include <LittleFS.h>
#include <String.h>
#include "Measurement.h"

class FileMeasurements
{
private:
    const char *dir_;
    int max_ = 4;
    int pos_ = 0;
    int i_ = 0;
    bool debug_ = true;
    uint32_t timer_ = 0;
    uint32_t timerUpdate_ = 0;
    uint32_t frecuency_ = 10000UL;
    File file_;

    size_t      println         (String, int);
    size_t      size            (void);
    int         count           (void);
    template    <typename Generic>
    void        DEBUG_FS        (Generic);    
    int         sizeof_         (void);
    String      read            (uint32_t);

public:
    //FileMeasurements          (const char *);
    FileMeasurements            (const char *, int , uint32_t);
    ~FileMeasurements           ();
    void        begin           (void);
    void        end             (void);
    void        remove          (void);
    String      readAll         (void);
    size_t      append          (String);
    bool        exists          (void);
    void        setDebug        (bool);
    void        update          (uint32_t);
    void        record          (String);
};

#endif // FILES_H_