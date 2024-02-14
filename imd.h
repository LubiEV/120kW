#ifndef IMD_H
#define IMD_H

#include <QObject>
#include <iostream>
#include "dcmodule.h"

#define BuffSize 100
using namespace std;

class Imd : public QObject
{
    Q_OBJECT
public:
    explicit Imd(QObject *parent = nullptr);

signals:

public slots:
    void delay(int number_of_seconds);
    int can_setting_imd(const char* can, const int bitrate, int enable); //call in declaration
    int VoltageVP();
    int Resistance_func();
    int Error_func();
    int Capacitance();
    int isolation_func();
    int Battery_func();
    int vbmax();
    int Restart();
    int imd_test();
    int ImdCalling();
    int Ethernet_connection();
};

#endif // IMD_H
