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
    Measurement             (void);
    Measurement             (float t, float h, QDateTime timestamp);
    Measurement             (QString);
    ~Measurement            (void);
    void        setMeasurement  (float, float, QDateTime);
    double      getTemperature  (void);
    double      getHumidity     (void);
    QDateTime   getTimestamp    (void);


};

#endif // MEASUREMENT_H_
