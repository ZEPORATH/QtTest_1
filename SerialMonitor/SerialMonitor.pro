#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T10:37:00
#
#-------------------------------------------------

QT       += core gui
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialMonitor
TEMPLATE = app


SOURCES += main.cpp\
        serialmonitor.cpp \
    settings.cpp \
    console.cpp

HEADERS  += serialmonitor.h \
    console.h \
    settings.h

FORMS    += serialmonitor.ui
