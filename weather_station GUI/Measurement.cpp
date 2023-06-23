#include "Measurement.h"


Measurement::Measurement (float t, float h, QDateTime timestamp)
{
    t_ = t;
    h_ = h;
    timestamp_ = timestamp;
}

Measurement::~Measurement (void)
{
    ;
}

double Measurement::getTemperature (void)
{
    return t_;
}

double Measurement::getHumidity (void)
{
    return h_;
}

/*
QString Measurement::toString (void)
{
    const size_t bufferSize = snprintf(nullptr, 0, "%s - t%.1f;h%.1f", timestamp_.), t_, h_) + 1;
    char *buffer = new char [bufferSize];

    snprintf(buffer, bufferSize, "%s - t%.1f;h%.1f", timestamp_.getFormattedDateTime().toStdString().c_str(), t_, h_);
    
    QString result(buffer);
    
    delete[] buffer;

    return result;
}
*/
