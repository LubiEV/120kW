/******************************************************************************
* Copyright (C), 2016-2017, Sunny.Guo
* FileName: tty.c
* Author: Sunny.Guo
* Version: 1.0
* Date: 2017�� 01�� 19�� ������ 10:12:50 CST
* Description: tty operation functions
*
* History:
*  <author>  	<time>   	<version >   	<desc>
*  Sunny.Guo   	19/01/2017      1.0     	create this moudle
*
* Licensed under GPLv2 or later, see file LICENSE in this source tree.
*******************************************************************************/
#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <net/if.h>
#endif
#include <sys/types.h>
#include <linux/input.h>
#include "common.h"
#include "tty.h"
#include <QMutex>
QMutex mutex;
/******************************************************************************
  Function:       tty_init
  Description:    initialize tty device
  Input:          tty    	--  tty device name, such as '/dev/ttyO0', '/dev/ttyO5'

  Output:
  Return:         int		-- return the tty fd
  Others:         NONE
*******************************************************************************/
int				tty_init(const char * tty)
{
    int fd;
    fd = open(tty, O_RDWR);
    if(fd < 0){
        dbg_perror("open tty");
        }
    return fd;
}
int	rfid_init(const char * keypad)
{
    int pfd;
    char name[256] = "unknown";
    pfd = open(keypad, O_RDONLY|O_NONBLOCK); //O_NONBLOCK
    if (pfd < 0) {
        dbg_perror("Open keys event node failed\n");
    }

             ioctl (pfd, EVIOCGRAB,1);
  //   ioctl (pfd, EVIOCGNAME (sizeof (name)), name);
     printf ("Reading From : %s (%s)\n", keypad, name);
    return pfd;
}
/******************************************************************************
  Function:       tty_setting
  Description:    set the tty device's mode and bitrate
  Input:          fd       --  tty device fd
                  bitrate --  tty baudrate
                  mode	   --  tty mode, 1: rs485; 0: rs232
                  flow	   --  cts/rts flow control
                  par	   --  odd/even
                  stop	   --  number of stop bits

  Output:
  Return:         int 	   --  tty setting status 0:success
  Others:         NONE
*******************************************************************************/
int tty_setting(int fd, int bitrate, int datasize, int mode, int flow, int par, int stop)
{
    struct termios newtio;

    /* ignore modem control lines and enable receiver */
    memset(&newtio, 0, sizeof(newtio));
    newtio.c_cflag = newtio.c_cflag |= CLOCAL | CREAD;
    if(flow == 1)
    {
        newtio.c_cflag = newtio.c_cflag |= CLOCAL | CREAD | CRTSCTS;
    }

    newtio.c_cflag &= ~CSIZE;

    /* set character size */
    switch (datasize) {
    case 8:
        newtio.c_cflag |= CS8;
        break;
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 6:
        newtio.c_cflag |= CS6;
        break;
    case 5:
        newtio.c_cflag |= CS5;
        break;
    default:
        newtio.c_cflag |= CS8;
        break;
    }

    /* set the parity */
    switch (par) {
    case 'o':
    case 'O':
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'e':
    case 'E':
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'n':
    case 'N':
        newtio.c_cflag &= ~PARENB;
        break;
    default:
        newtio.c_cflag &= ~PARENB;
        break;
    }

    /* set the stop bits */
    switch (stop) {
    case 1:
        newtio.c_cflag &= ~CSTOPB;
        break;
    case 2:
        newtio.c_cflag |= CSTOPB;
        break;
    default:
        newtio.c_cflag &= ~CSTOPB;
        break;
    }

    /* set output and input baud rate */
    switch (bitrate) {
    case 0:
        cfsetospeed(&newtio, B0);
        cfsetispeed(&newtio, B0);
        break;
    case 50:
        cfsetospeed(&newtio, B50);
        cfsetispeed(&newtio, B50);
        break;
    case 75:
        cfsetospeed(&newtio, B75);
        cfsetispeed(&newtio, B75);
        break;
    case 110:
        cfsetospeed(&newtio, B110);
        cfsetispeed(&newtio, B110);
        break;
    case 134:
        cfsetospeed(&newtio, B134);
        cfsetispeed(&newtio, B134);
        break;
    case 150:
        cfsetospeed(&newtio, B150);
        cfsetispeed(&newtio, B150);
        break;
    case 200:
        cfsetospeed(&newtio, B200);
        cfsetispeed(&newtio, B200);
        break;
    case 300:
        cfsetospeed(&newtio, B300);
        cfsetispeed(&newtio, B300);
        break;
    case 600://O_NONBLOCK
        cfsetospeed(&newtio, B600);
        cfsetispeed(&newtio, B600);
        break;
    case 1200:
        cfsetospeed(&newtio, B1200);
        cfsetispeed(&newtio, B1200);
        break;
    case 1800:
        cfsetospeed(&newtio, B1800);
        cfsetispeed(&newtio, B1800);
        break;
    case 2400:
        cfsetospeed(&newtio, B2400);
        cfsetispeed(&newtio, B2400);
        break;
    case 4800:
        cfsetospeed(&newtio, B4800);
        cfsetispeed(&newtio, B4800);
        break;
    case 9600:
        cfsetospeed(&newtio, B9600);
        cfsetispeed(&newtio, B9600);
        break;
    case 19200:
        cfsetospeed(&newtio, B19200);
        cfsetispeed(&newtio, B19200);
        break;
    case 38400:
        cfsetospeed(&newtio, B38400);
        cfsetispeed(&newtio, B38400);
        break;
    case 57600:
        cfsetospeed(&newtio, B57600);
        cfsetispeed(&newtio, B57600);
        break;
    case 115200:
        cfsetospeed(&newtio, B115200);
        cfsetispeed(&newtio, B115200);
        break;
    case 230400:
        cfsetospeed(&newtio, B230400);
        cfsetispeed(&newtio, B230400);
        break;
    default:
        cfsetospeed(&newtio, B9600);
        cfsetispeed(&newtio, B9600);
        break;
    }

    /* set timeout in deciseconds for non-canonical read */
    newtio.c_cc[VTIME] = 0;
    /* set minimum number of characters for non-canonical read */
    newtio.c_cc[VMIN] = 1;

    /* flushes data received but not read */
    tcflush(fd, TCIFLUSH);
    /* set the parameters associated with the terminal from
       the termios structure and the change occurs immediately */
    if((tcsetattr(fd, TCSANOW, &newtio))!=0) {
        dbg_perror("set_tty/tcsetattr");
        return -1;
    }

    tty_mode(fd, mode);
    return 0;

}

int tty_read_ready(int fd) {

    if(fd <= 0)
    {
        return 0;
    }
     mutex.lock();
    struct timeval tv;
    fd_set fds;
    int ret;

    unsigned int timeout = TTY_READ_TIMEOUT_USEC;
    tv.tv_sec = 0;
    tv.tv_usec = timeout ;

    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    if(timeout > 0){
        ret = select(fd+1, &fds, NULL, NULL, &tv);
        if(ret < 0){
            printf("select tty\r\n");
            }
        }
    if(FD_ISSET(fd, &fds)){
        mutex.unlock();
        return 1;        
        }
    mutex.unlock();
    return 0;
}

int	tty_read(int fd, char *frame)
{
    mutex.lock();
    int ret = read(fd, frame, TTY_READ_BUFFER_SIZE);
    mutex.unlock();
    return ret;
}

int	tty_write(int fd, char *frame, int len)
{
    int ret = -1;
    ret = write(fd, frame, len);
    if(ret < 0){
        dbg_perror("tty write!");
        }
    return ret;
}

int tty_mode(const int fd,  int mode)
{
    struct serial_rs485 rs485conf;
    int res;
    /* Get configure from device */
    res = ioctl(fd, TIOCGRS485, &rs485conf);
    if (res < 0) {
        perror("Ioctl error on getting 485 configure:");
        close(fd);
        return res;
    }

    /* Set enable/disable to configure */
    if(mode == TTY_RS485_MODE){
        // Enable rs485 mode
        rs485conf.flags |= SER_RS485_ENABLED;
        }
    else{
        // Disable rs485 mode
        rs485conf.flags &= ~(SER_RS485_ENABLED);
        }

    rs485conf.delay_rts_before_send = 0x00000004;

    /* Set configure to device */
    res = ioctl(fd, TIOCSRS485, &rs485conf);
    if (res < 0) {
        perror("Ioctl error on setting 485 configure:");
        close(fd);
    }

    return res;
}
int rfid_read(int pfd,struct input_event ev[])
{
    int size = sizeof(struct input_event);
    int rd;
        rd =  read (pfd, ev,(size*64));
        if(rd == -1)
         {
           printf("Error \r\n");
         }
       // printf("read size %d\n ", size*64);
     return rd;
}
int rfid_read_ready(int fd)
{
    struct timeval tv;
    int ret = 0;
    fd_set key_ev_fds;

    unsigned int timeout = TTY_READ_TIMEOUT_USEC;
    tv.tv_sec = 0;
    tv.tv_usec = timeout ;

    FD_ZERO(&key_ev_fds);
    FD_SET(fd, &key_ev_fds);

    ret = select(sizeof(key_ev_fds)+1, &key_ev_fds, NULL, NULL, &tv);
    if ( ret < 0){
        return -1;
        dbg_perror("select key event failed");

        }
    if(FD_ISSET(fd, &key_ev_fds)){
          return 1;
        }
    return 0;
}

