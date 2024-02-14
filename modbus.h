#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>
#include <QThread>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include<iostream>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <termios.h>
#include <linux/ioctl.h>
#include <linux/serial.h>
#include <asm-generic/ioctls.h> /* TIOCGRS485 + TIOCSRS485 ioctl definitions */
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <sys/mman.h>
#include <sys/types.h>
#include "dccomboplc.h"
#include <QtConcurrent>
#include <QFuture>
#include<QThread>
#include <QtSerialPort>

using namespace std;

typedef enum {DISABLE = 0, ENABLE} RS485_ENABLE_t;
union
{
    unsigned short int word;
    uint32_t dword;
    float dfloat;
    unsigned char byte[4];
}split_int;

class MODBUS : public QObject
{
    Q_OBJECT
public:
    explicit MODBUS(QObject *parent = nullptr);

    dcComboPLC *CCS_em;
    bool m_val, m_checkVal;   
    char preACConnected, preACNotConn,preACCharging;
    char m_ccs_precharge_status = 0,m_ccs_dcmain_status = 0;
    int i;

    int tty_fd;
    void Initialization();
    bool Rishabh_DC();
    void Dcplcfunction();
       bool Current();
       bool PowerKW();
       bool EnergyKWH();
       bool Current_2();
       bool PowerKW_2();
       bool EnergyKWH_2();
       uint16_t ModRTU_CRC(char buf[], int len);
};
#endif // MODBUS_H
