#ifndef FILEMEASUREMENTS_H_
#define FILEMEASUREMENTS_H_

#include <iostream>
#include <string.h>
#include <QString>
#include <QFile>

using namespace std;


class FileMeasurements{
private:
    QString nombre;
public:
    FileMeasurements    (QString);
    void    println     (QString);
    QString readLine    (void);
};

#endif // FILEMEASUREMENTS_H_
