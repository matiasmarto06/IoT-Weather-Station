#ifndef DATE_H_
#define DATE_H_

#include <Arduino.h>

class Date
{
private:
    int d_;
    int m_;
    int y_;
    int ss_;
    int mm_;
    int hh_;
    
public:
                Date                        (/* args */);
                ~Date                       ();
    void        setDate                     (int d, int m, int y, int hh, int mm, int ss);
    String      getFormattedDateTime        (void);
};

#endif // DATE_H_