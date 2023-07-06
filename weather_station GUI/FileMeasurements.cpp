#include "FileMeasurements.h"
#include <QDir>
#include <QStandardPaths>

FileMeasurements::FileMeasurements(QString n)
{
    nombre = n.append(".csv");
    QDir path(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));

    path.mkdir("WSA Databases");
    path.cd("WSA Databases");

    nombre = path.absolutePath() + "/" + nombre;
}

void FileMeasurements::println(QString reg)
{
    QFile p(nombre);
    if (!p.open(QIODevice::Append))
    {
        cout << p.errorString().toStdString() << endl;
    }
    p.write(reg.append('\n').toUtf8());
    p.close();
    return;
}

QString FileMeasurements::readLine(void)
{
    QFile p(nombre);

    cout << "readLine (sizeof): " << sizeof(p.readLine()) << endl;

    return QString("Reading done");
}
