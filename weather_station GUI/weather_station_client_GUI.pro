#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T20:38:36
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TcpCliente
TEMPLATE = app


SOURCES += main.cpp\
        Measurement.cpp \
        mainwindow.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
        Measurement.h \
        qcustomplot.h

FORMS    += mainwindow.ui
