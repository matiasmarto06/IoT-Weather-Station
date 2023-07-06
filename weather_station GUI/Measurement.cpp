#include "Measurement.h"


Measurement::Measurement (float t, float h, QDateTime timestamp)
{
    t_ = t;
    h_ = h;
    timestamp_ = timestamp;
}

Measurement::Measurement (QString text)
{
    if (text.length() < 29)
    {
        return;
    }
    QList<QString> temp = text.split(';');
    QDateTime dateTime(QDate(temp[2].toInt(), temp[1].toInt(), temp[0].toInt()), QTime(temp[3].toInt(), temp[4].toInt(), temp[5].toInt(), 0));
    setMeasurement(temp[6].toFloat(), temp[7].toFloat(), dateTime);
}

void Measurement::setMeasurement(float t, float h, QDateTime timestamp)
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

QDateTime Measurement::getTimestamp(void)
{
    return timestamp_;
}
