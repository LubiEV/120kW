#ifndef RFID_H
#define RFID_H


#include <QObject>
#include <linux/input.h>
#include <sys/select.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/types.h>
#include "common.h"
#include <QtSerialPort>
class RFID  : public QObject
{
     Q_OBJECT
public:       
    RFID(QObject* parent = nullptr);
    int	keypad_init(const char * keypad);
    int rf_func(int fd);
    QSerialPort serial;
    int keypad_monitor(int fd /*struct input_event *ev*/);
    char *dev_name = "/dev/input/event4";
    int fd;
 //   struct pollfd fds[1];
    char buffer[20];

signals:
    void readReady(int);


public slots:
    void poll_read_ready(void);
    int  readrfid_COM(int );
};
#endif // RFID_H
