#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <QString>
#include <QDateTime>

class Measurement
{
private:
    float                   t_;
    float                   h_;
    QDateTime               timestamp_;

public:
                Measurement         (float t, float h, QDateTime timestamp);
                ~Measurement        (void);
                double getTemperature (void);
                double getHumidity (void);

};

#endif // MEASUREMENT_H_
