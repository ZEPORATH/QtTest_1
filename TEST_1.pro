#-------------------------------------------------
#
# Project created by QtCreator 2017-03-27T12:51:28
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TEST_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contol_window.cpp \
    portsettings.cpp

HEADERS  += mainwindow.h \
    contol_window.h \
    portsettings.h

FORMS    += mainwindow.ui \
    contol_window.ui \
    portsettings.ui

RESOURCES += \
    res.qrc
