#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T20:38:36
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = WeatherStationApp
TEMPLATE = app


SOURCES += main.cpp\
        FileMeasurements.cpp \
        Measurement.cpp \
        mainwindow.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
        FileMeasurements.h \
        Measurement.h \
        qcustomplot.h

FORMS    += mainwindow.ui

RC_ICONS = weather.ico

DISTFILES += \
    weather.ico
