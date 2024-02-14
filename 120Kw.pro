#-------------------------------------------------
#
# Project created by QtCreator 2022-04-12T15:35:42
#
#-------------------------------------------------   
QT       += core gui\
            serialbus serialport websockets concurrent sql
QT += concurrent
QT += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ARAI_120kW
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += THIRTEE M2 PLC_THREAD

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MY_LineEdit.cpp \
    dccomboplc_2.cpp \
    main.cpp \
    mainwindow.cpp \
    database.cpp \
    dccomboplc.cpp \
    dcmodule.cpp \
    keypad.cpp \
    modbus.cpp \
    ocpp.cpp \
    rfid.cpp \
    tty.cpp \
    form.cpp \
    keyboard/QKeyPushButton.cpp \
    keyboard/widgetKeyBoard.cpp

HEADERS += \
    Controller.h \
    MY_LineEdit.h \
    Worker.h \
    dccomboplc_2.h \
    dcplc.h \
    mainwindow.h \
    common.h \
    database.h \
    dccomboplc.h \
    dcmodule.h \
    keypad.h \
    modbus.h \
    ocpp.h \
    rfid.h \
    tty.h \
    form.h \
    keyboard/QKeyPushButton.h \
    keyboard/widgetKeyBoard.h

FORMS += \
        form.ui \
        mainwindow.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
