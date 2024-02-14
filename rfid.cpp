#include "rfid.h"
#include <getopt.h>
#include <unistd.h>
#include <fcntl.h>
#include "stdlib.h"
#include "qdebug.h"
#include "tty.h"
#include"ocpp.h"
QString rcvData;
 extern Charger_Status CCS;
RFID::RFID(QObject *parent )  : QObject(parent)
{
  //      connect(this, &RFID::readReady(int), this, &RFID::readrfid_COM(int));
}
int	RFID::keypad_init(const char * keypad)
{
    int fd;
    fd = rfid_init("/dev/input/event4");
    if(fd == -1)
    {
        qDebug() << "Failed to open rfid";
        return -1;
    }
    return fd;
}
void RFID::poll_read_ready(){

     qDebug() << "Poll rfid \n";
    int ret =  rfid_read_ready(fd);
    if (ret == 1) {
    }
    else if (ret == -1)
    {
        qDebug() << "failSCAN_TAGIDed to read" << this->fd <<endl;
    }
}
int RFID::readrfid_COM(int fd )
{
    struct input_event ev[64];
    static char buffer[20],i=0;
    static long int num = 0;

    int ret = rfid_read(fd,ev);
    if(ret == -1)
    {
         qDebug() << "Read rfid failed \n";
        return -1;
    }

  //  i=0;
    for(int var =0;var < ret/sizeof(input_event);var++)
    {
        if((ev[var].type == 1) && (ev[var].value == 1))
        {
            if(ev[var].code != 28)
            {
                if(ev[var].code == 11)
                {
                    buffer[i++] = 0+48;
                }
                else
                {
                    buffer[i++] = ev[var].code +47;
                    //buffer[i++] = ev[var].code -1;
                }
                // num = num * 10 + (buffer);
                printf ("Code[%d]\n", ev[var].code);
            }
            else
            {
                  buffer[i++] = '\0';
              rcvData =  QString::fromUtf8(buffer, 10);
              bool ok;
              CCS.SCAN_TAGID = 2;
              qulonglong tagid  = rcvData.toLongLong(&ok,10);
              if(ok == true)
              {
                 //CCS.TadId = QString::number(tagid,16);
                  CCS.RfidTagId = QString("%1").arg(tagid, 8, 16, QLatin1Char( '0' ));
                 //CCS.TadId =  QByteArray::fromHex(QString::number(tagid));
              }
                qDebug() << rcvData.toLocal8Bit()<< CCS.RfidTagId << endl;
                rcvData.clear();               
                i=0;
                num =  0;
                break;
            }
        }
    }
    return 1;
}
int RFID::keypad_monitor(int fd/*, struct input_event *ev*/)
{
    int ret = 0;
    fd_set key_ev_fds;
    struct timeval tv;

    unsigned int timeout = 5000;
    tv.tv_sec = 0;
    tv.tv_usec = timeout ;

    FD_ZERO(&key_ev_fds);
    FD_SET(fd, &key_ev_fds);

    ret = select(sizeof(key_ev_fds)+1, &key_ev_fds, NULL, NULL, &tv);
    if ( ret < 0){
        perror("select key event failed");
    }

    if(FD_ISSET(fd, &key_ev_fds)){
      return 1;
    }

    return ret;
}
int RFID::rf_func(int fd)
{
    bool flag;
    char i=0;
    int ret;
    char buffer[1024];
    struct input_event *ev;
  qDebug() << "rfid before --"<<endl;
   //  ret = read(fd,buffer , 1024);
        do{
        ret = read(fd, ev, sizeof(struct input_event));
        if ( ret < 0){
           qDebug() << "rfid Read failed"<<endl;
            }
        if (ev->code == 4 && ev->type == 4) {
             qDebug() << "rfid event :"<<endl;
                if (flag) {
                    char c = ((char)ev->value);
                    if (c == 39) {
                           // buffer[i++] = 0;
                    } else if (c == 40) {
                            break;
                    } else {
                                buffer[i++] = c - 29;
                    }
                }
            flag = !flag;
            }
        }while(1);
    //qDebug() << "rfid data :"<< buffer <<endl;


//        if (i > 0) {
//                int authenticated = 1;
//                    for (int j = 0; j < i; j++) {
//                                if (buffer[j] != authenticated_rfid[j]) {
//                                        authenticated = 0;
//                                        break;
//                                }
//                    }
//                    if (authenticated) {
//                            printf("\r\nAuthenticated user!\r\n");
//                            return 1;
//                    }
//                    else {
//                            printf("\r\nUnauthenticated user!\r\n");
//                             return 0;
//                    }
//        }
}
