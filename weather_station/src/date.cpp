#include "Date.h"

Date::Date(/* args */)
{
    ;
}

Date::~Date()
{
    ;
}

void Date::setDate(int d, int m, int y, int hh, int mm, int ss)
{
    d_ = d;
    m_ = m;
    y_ = y;
    hh_ = hh;
    mm_ = mm;
    ss_ = ss;
}

String Date::getFormattedDateTime (void)
{  
    const size_t bufferSize = snprintf(nullptr, 0, "%02d;%02d;%04d;%02d;%02d;%02d", d_, m_ , y_, hh_, mm_, ss_) + 1;
    char *buffer = new char [bufferSize];

    snprintf(buffer, bufferSize, "%02d;%02d;%04d;%02d;%02d;%02d", d_, m_ , y_, hh_, mm_, ss_);
    
    String result(buffer);
    
    delete[] buffer;

    return result;
}