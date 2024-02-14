#include "modbus.h"
#include "Controller.h"
#include <QThreadPool>
#include <QRunnable>
#include <QTimer>
#include <QMutex>
#include "ocpp.h"
#include <QWaitCondition>
#include "rfid.h"

#define MAX_INPUT  255
#define TTY_RS485_MODE  1
//#define M2 1
//long int num3;
extern Charger_Status CCS;
extern Charger_Status CCS2;
QQueue<int> queue;
extern QMutex mutex1;
extern struct Parameter set_parameter;

static QWaitCondition  newdataAvailable;
enum Write_modbus
{
    EM_Init,
    EM_Current,
    EM_Voltage,
    EM_Power,
    EM_Unit,  
};

//#define MODBUS_DEBUG 1

const char* dev_name1 ="/dev/ttymxc3";
static unsigned int tty_baudrate = 19200; // 9600;
//int tty_fd = -1;
int fd,nread;
unsigned int ret4 = 0;
int flgFlow = 0;
int ttyMode = TTY_RS485_MODE;
char read_buff[100];

MODBUS::MODBUS(QObject *parent) //: QObject(parent)
{

}
uint16_t MODBUS::ModRTU_CRC(char buf[], int len)
{
  unsigned int crc = 0xFFFF;
  for (int pos = 0; pos < len; pos++) {
    crc ^= (uint16_t)buf[pos];          // XOR byte into least sig. byte of crc

    for (int i = 8; i != 0; i--) {    // Loop over each bit
      if ((crc & 0x0001) != 0) {      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}
int tty_init1(const char * tty)
{
    int fd;
    fd = open(tty, O_RDWR);
    if(fd < 0){
        perror("open tty");
    }
    return fd;
}
int tty_mode1(const int fd,  int mode)
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
int tty_setting1(int fd, int bitrate, int datasize, int mode, int flow, int par, int stop)
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
    case 600:
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
        perror("set_tty/tcsetattr");
        return -1;
    }

    tty_mode1(fd, TTY_RS485_MODE);
    return 0;

}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);

}

int change_bit_rs485(int fd,int value)
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

    /*rs485 send - recv*/

    if(value==1)
        rs485conf.flags |= SER_RS485_RTS_AFTER_SEND;
    else if(value==0)
        rs485conf.flags &= ~SER_RS485_RTS_AFTER_SEND;
    else ;

    /* Set configure to device */
    res = ioctl(fd, TIOCSRS485, &rs485conf);
    if (res < 0) {
        perror("Ioctl error on setting 485 configure:");
        close(fd);
    }
    return res;
}/*******************************************************************************/
bool MODBUS::Current(){
    char write_current_buf_2[8] ={0x03,0x03,0x00,0x08,0x00,0x0c,0xc5,0xef};
    unsigned char i;
//#ifdef M2
    write(tty_fd, write_current_buf_2, sizeof(write_current_buf_2));
    QThread::msleep(100);

    change_bit_rs485(tty_fd,0);
    if(tty_read_ready(tty_fd) == false)
    {
        return false;
    }
    nread = read(tty_fd ,read_buff ,sizeof(read_buff));
    QThread::msleep(10);

    for(i = 0; i < sizeof(read_buff); i++)
    {
        if((read_buff[i] == 0x03) && (read_buff[i+1] == 0x03))
        {
            if(read_buff[i+2] == 0x18)
            {
                split_int.word = ModRTU_CRC((read_buff+i),27);
                if(split_int.byte[0] != read_buff[29] && split_int.byte[1] != read_buff[28])
                {
                    printf("CRC failed\r\n");
                    return false;
                }

                split_int.byte[1] = read_buff[i+3];
                split_int.byte[0] = read_buff[i+4];
                split_int.byte[3] = read_buff[i+5];
                split_int.byte[2] = read_buff[i+6]; //dcba
                CCS.voltage_L1  = ((float)split_int.dfloat > 600.0) ?  415.0 : split_int.dfloat; //vr

                split_int.byte[1] = read_buff[i+7];
                split_int.byte[0] = read_buff[i+8]; //dcba
                split_int.byte[3] = read_buff[i+9];
                split_int.byte[2] = read_buff[i+10];
                CCS.voltage_L2 = ((float)split_int.dfloat > 600.0 ) ?  415.0 : split_int.dfloat; //vy

                split_int.byte[1] = read_buff[i+11]; //dcba
                split_int.byte[0] = read_buff[i+12];
                split_int.byte[3] = read_buff[i+13];
                split_int.byte[2] = read_buff[i+14];
                CCS.voltage_L3 = ((float)split_int.dfloat > 600.0 ) ?  415.0 : split_int.dfloat; //vb

                split_int.byte[1] = read_buff[i+15]; //dcba
                split_int.byte[0] = read_buff[i+16];
                split_int.byte[3] = read_buff[i+17];
                split_int.byte[2] = read_buff[i+18];
                CCS.current_L1 = ((float)split_int.dfloat > 200.0 ) ?  10.0  : split_int.dfloat; //Ir

                split_int.byte[1] = read_buff[i+19];
                split_int.byte[0] = read_buff[i+20];
                split_int.byte[3] = read_buff[i+21];
                split_int.byte[2] = read_buff[i+22];
                CCS.current_L2  = ((float)split_int.dfloat > 200.0 ) ?  10.0  : split_int.dfloat; //Iy

                split_int.byte[1] = read_buff[i+23];
                split_int.byte[0] = read_buff[i+24];
                split_int.byte[3] = read_buff[i+25];
                split_int.byte[2] = read_buff[i+26];
                CCS.current_L3  = ((float)split_int.dfloat > 200.0 ) ?  10.0  : split_int.dfloat; //Ib
               //  printf("voltage VL1 = %f\n",CCS.voltage_L1);
            }
            break;
        }
    }
      return true;
}
bool MODBUS::PowerKW(){
    char write_power_buf_2[8] = {0x03,0x03,0x00,0x22,0x00,0x02,0x65,0xe3}; //{0x0read1,0x03,0x00,0x32,0x00,0x04,0xe5,0xc6};
    char read_power_buf[30];
    unsigned char i;

    write(tty_fd, write_power_buf_2, sizeof(write_power_buf_2));
    QThread::msleep(100);
    change_bit_rs485(tty_fd,0); // recv mode
    if(tty_read_ready(tty_fd) == false)
    {
        return false;
    }
    nread = read(tty_fd ,read_power_buf ,sizeof(read_power_buf));
    QThread::msleep(10);
    if (nread < 0) {
        printf("RECV[%3d]: ", nread);
    }

    for(i = 0; i < sizeof(read_power_buf); i++)
    {
        if((read_power_buf[i] == 0x03) && (read_power_buf[i+1] == 0x03))
        {   //i++;
            if(read_power_buf[i+2] == 0x04)
            {
                split_int.byte[1] = read_power_buf[i+3];
                split_int.byte[0] = read_power_buf[i+4];
                split_int.byte[3] = read_power_buf[i+5];
                split_int.byte[2] = read_power_buf[i+6];
            }
             printf("power_3 = %f\n",split_int.dfloat);
            break;
        }
    }
    CCS.Power = (float)split_int.dfloat;
    if(CCS.Power < 0)
    {
        CCS.Power = -CCS.Power;
    }
//#endif
    return true;
}
bool MODBUS::EnergyKWH(){
unsigned char i;
char write_kwh_buf_2[8] ={0x03,0x03,0x00,0x38,0x00,0x02,0x44,0x24};
 char read_kwh_buf[20];
    write(tty_fd, write_kwh_buf_2, sizeof(write_kwh_buf_2));

    QThread::msleep(100);

    change_bit_rs485(tty_fd,0); // recv mode

    if(tty_read_ready(tty_fd) == false)
    {
        return false;
    }
    nread = read(tty_fd ,read_kwh_buf ,sizeof(read_kwh_buf));

    QThread::msleep(10);

    for(i = 0; i < sizeof(read_kwh_buf); i++)
    {
        if((read_kwh_buf[i] == 0x03) && (read_kwh_buf[i+1] == 0x03))
        {
            if(read_kwh_buf[i+2] == 0x04)
            {
                split_int.byte[1] = read_kwh_buf[i+3];
                split_int.byte[0] = read_kwh_buf[i+4];
                split_int.byte[3] = read_kwh_buf[i+5];
                split_int.byte[2] = read_kwh_buf[i+6];
                printf("Energy_3 = %f\n",split_int.dfloat);
                break;
            }
        }
    }
    CCS.Energy = (unsigned int)split_int.dfloat;

    return true;
}

bool MODBUS::Current_2(){
    char write_current_buf_2[8] ={0x04,0x03,0x00,0x08,0x00,0x0c,0xc4,0x58};
    unsigned char i;

//#ifdef M2
    write(tty_fd, write_current_buf_2, sizeof(write_current_buf_2));
    QThread::msleep(100);

    change_bit_rs485(tty_fd,0);
    if(tty_read_ready(tty_fd) == false)
    {
        return false;
    }
    nread = read(tty_fd ,read_buff ,sizeof(read_buff));
    QThread::msleep(10);

    for(i = 0; i < sizeof(read_buff); i++)
    {
        if((read_buff[i] == 0x04) && (read_buff[i+1] == 0x03))
        {
            if(read_buff[i+2] == 0x18)
            {
                split_int.byte[1] = read_buff[i+3];
                split_int.byte[0] = read_buff[i+4];
                split_int.byte[3] = read_buff[i+5];
                split_int.byte[2] = read_buff[i+6]; //dcba
                CCS.voltage_L1  = ((float)split_int.dfloat > 600.0 ) ?  415.0  : split_int.dfloat; //vr

                split_int.byte[1] = read_buff[i+7];
                split_int.byte[0] = read_buff[i+8]; //dcba
                split_int.byte[3] = read_buff[i+9];
                split_int.byte[2] = read_buff[i+10];
                CCS.voltage_L2 = ((float)split_int.dfloat > 600.0 ) ?  415.0  : split_int.dfloat; //vy

                split_int.byte[1] = read_buff[i+11]; //dcba
                split_int.byte[0] = read_buff[i+12];
                split_int.byte[3] = read_buff[i+13];
                split_int.byte[2] = read_buff[i+14];
                CCS.voltage_L3 = ((float)split_int.dfloat > 600.0 ) ?  415.0  : split_int.dfloat; //vb

                split_int.byte[1] = read_buff[i+15]; //dcba
                split_int.byte[0] = read_buff[i+16];
                split_int.byte[3] = read_buff[i+17];
                split_int.byte[2] = read_buff[i+18];
                CCS.current_L1 = ((float)split_int.dfloat > 200.0 ) ?  10.0  : split_int.dfloat; //Ir

                split_int.byte[1] = read_buff[i+19];
                split_int.byte[0] = read_buff[i+20];
                split_int.byte[3] = read_buff[i+21];
                split_int.byte[2] = read_buff[i+22];
                CCS.current_L2  = ((float)split_int.dfloat > 200.0 ) ?  10.0  : split_int.dfloat; //Iy

                split_int.byte[1] = read_buff[i+23];
                split_int.byte[0] = read_buff[i+24];
                split_int.byte[3] = read_buff[i+25];
                split_int.byte[2] = read_buff[i+26];
                CCS.current_L3  = ((float)split_int.dfloat > 200.0 ) ?  10.0  : split_int.dfloat; //Ib
                 printf("currentL3_4 = %f\n",split_int.dfloat);
            }
            break;
        }
    }
//#endif
      return true;
}
bool MODBUS::PowerKW_2(){
    char write_power_buf_2[8] = {0x04,0x03,0x00,0x22,0x00,0x02,0x64,0x54}; //{0x0read1,0x03,0x00,0x32,0x00,0x04,0xe5,0xc6};
    char read_power_buf[30];
    unsigned char i;

    write(tty_fd, write_power_buf_2, sizeof(write_power_buf_2));
    QThread::msleep(100);
    change_bit_rs485(tty_fd,0); // recv mode
    if(tty_read_ready(tty_fd) == false)
    {
        return false;
    }
    nread = read(tty_fd ,read_power_buf ,sizeof(read_power_buf));
    QThread::msleep(10);
    if (nread < 0) {
        printf("RECV[%3d]: ", nread);
    }

    for(i = 0; i < sizeof(read_power_buf); i++)
    {
        if((read_power_buf[i] == 0x04) && (read_power_buf[i+1] == 0x03))
        {   //i++;
            if(read_power_buf[i+2] == 0x04)
            {
                split_int.byte[1] = read_power_buf[i+3];
                split_int.byte[0] = read_power_buf[i+4];
                split_int.byte[3] = read_power_buf[i+5];
                split_int.byte[2] = read_power_buf[i+6];
            }
            printf("power_4 = %f\n",split_int.dfloat);
            break;
        }
    }

    CCS.Power = (float)split_int.dfloat;
    if(CCS.Power < 0)
    {
        CCS.Power = -CCS.Power;
    }
//#endif

    return true;
}
bool MODBUS::EnergyKWH_2(){
unsigned char i;
char write_kwh_buf_2[8] ={0x04,0x03,0x00,0x38,0x00,0x02,0x45,0x93};
 char read_kwh_buf[20];
    write(tty_fd, write_kwh_buf_2, sizeof(write_kwh_buf_2));

    QThread::msleep(100);

    change_bit_rs485(tty_fd,0); // recv mode

    if(tty_read_ready(tty_fd) == false)
    {
        return false;
    }
    nread = read(tty_fd ,read_kwh_buf ,sizeof(read_kwh_buf));

    QThread::msleep(10);

    for(i = 0; i < sizeof(read_kwh_buf); i++)
    {
        if((read_kwh_buf[i] == 0x04) && (read_kwh_buf[i+1] == 0x03))
        {
            if(read_kwh_buf[i+2] == 0x04)
            {
                split_int.byte[1] = read_kwh_buf[i+3];
                split_int.byte[0] = read_kwh_buf[i+4];
                split_int.byte[3] = read_kwh_buf[i+5];
                split_int.byte[2] = read_kwh_buf[i+6];
//#ifdef MODBUS_DEBUG
                printf("Energy_4 = %f\n",split_int.dfloat);
                break;
            }
        }
    }
    CCS.Energy = (unsigned int)split_int.dfloat;

    return true;
}


bool MODBUS::Rishabh_DC(){
    char write_current_buf_2[8] ={0x02,0x04,0x00,0x00,0x00,0x08,0xf1,0xff};
    char write_current_buf_1[8] ={0x01,0x04,0x00,0x00,0x00,0x08,0xf1,0xcc};
    unsigned char i;

    write(tty_fd, write_current_buf_1, sizeof(write_current_buf_1));
    QThread::msleep(100);
    change_bit_rs485(tty_fd,0);
    if(tty_read_ready(tty_fd) == false)
    {
        printf("Not Available Byte ");
        return false; 
    }

    nread = read(tty_fd ,read_buff ,sizeof(read_buff));
    QThread::msleep(10);
    for(i = 0; i < sizeof(read_buff); i++)
    {
        //printf(" 0x%02x ",read_buff[i]);
        if((read_buff[i] == 0x01) && (read_buff[i+1] == 0x04))
        {
            if(read_buff[i+2] == 0x10)
            {
                split_int.byte[3] = read_buff[i+3];
                split_int.byte[2] = read_buff[i+4];
                split_int.byte[1] = read_buff[i+5];
                split_int.byte[0] = read_buff[i+6];
                CCS.DC_Voltage_1  = (float)split_int.dfloat; //vr

                split_int.byte[3] = read_buff[i+7];
                split_int.byte[2] = read_buff[i+8];
                split_int.byte[1] = read_buff[i+9];
                split_int.byte[0] = read_buff[i+10]; // current
                CCS.DC_Current_1 = (float)split_int.dfloat;

                split_int.byte[3] = read_buff[i+11];
                split_int.byte[2] = read_buff[i+12];
                split_int.byte[1] = read_buff[i+13];
                split_int.byte[0] = read_buff[i+14]; // power
                CCS.Power = (float)split_int.dfloat;

                split_int.byte[3] = read_buff[i+15]; //dcba
                split_int.byte[2] = read_buff[i+16];
                split_int.byte[1] = read_buff[i+17];
                split_int.byte[0] = read_buff[i+18];
                CCS.Energy = (float)split_int.dfloat*1000;
                //qDebug()<<"DC voltage : "<< CCS.DC_Voltage_1 <<"DC Current : "<< CCS.DC_Current_1 << "DC Power: "<<CCS.Power<<endl;
            }
            break;
        }        
    }
//---------------------------------------------------------------------------------------//
#ifdef M2
    write(tty_fd, write_current_buf_2, sizeof(write_current_buf_2));
    QThread::msleep(100);
    change_bit_rs485(tty_fd,0); // recv mode
    if(tty_read_ready(tty_fd) == false)
    {
        qDebug()<<"Not Available Byte_2 "<<endl;
        return false;
    }

    nread = read(tty_fd ,read_buff ,sizeof(read_buff));
    QThread::msleep(10);
    for(i = 0; i < sizeof(read_buff); i++)
    {
       // printf(" 0x%02x ",read_buff[i]);
        if((read_buff[i] == 0x02) && (read_buff[i+1] == 0x04))
        {
            if(read_buff[i+2] == 0x10)
            {
                split_int.byte[3] = read_buff[i+3];
                split_int.byte[2] = read_buff[i+4];
                split_int.byte[1] = read_buff[i+5];
                split_int.byte[0] = read_buff[i+6];
                CCS2.DC_Voltage_1  = (float)split_int.dfloat; //vr

                split_int.byte[3] = read_buff[i+7];
                split_int.byte[2] = read_buff[i+8];
                split_int.byte[1] = read_buff[i+9];
                split_int.byte[0] = read_buff[i+10]; // current
                CCS2.DC_Current_1 = (float)split_int.dfloat;

                split_int.byte[3] = read_buff[i+11];
                split_int.byte[2] = read_buff[i+12];
                split_int.byte[1] = read_buff[i+13];
                split_int.byte[0] = read_buff[i+14]; // power
                CCS2.Power = (float)split_int.dfloat;

                split_int.byte[3] = read_buff[i+15]; //dcba
                split_int.byte[2] = read_buff[i+16];
                split_int.byte[1] = read_buff[i+17];
                split_int.byte[0] = read_buff[i+18];
                CCS2.Energy = (float)split_int.dfloat*1000;
                //qDebug()<<"DC voltage_2 : "<< CCS2.DC_Voltage_1 <<"DC Current_2 : "<< CCS2.DC_Current_1 << "DC Power_2: "<<CCS2.Power<<endl;
            }
            break;
        }
    }
#endif
      return true;
}
void MODBUS::Initialization()
{
    tty_fd = tty_init1(dev_name1);
    if( tty_fd < 0){
        printf("Initialize tty device %s failed!\r\n", dev_name1);
        exit(EXIT_FAILURE);
    }

    ret4= tty_setting1(tty_fd, tty_baudrate, 8, ttyMode, flgFlow, 'n', 1);
    if(ret4 < 0){
        printf("setting tty device %s failed!\r\n", dev_name1);
        exit(EXIT_FAILURE);
    }
     printf("Initialize tty device %s and fd : %d\r\n", dev_name1,tty_fd);
}
void MODBUS::Dcplcfunction()
{
    qDebug() << "Modbus thread" << QThread::currentThreadId();
    MODBUS d;  
    int flag=0;
    int len = -1;
    unsigned char M1_Fail,M2_Fail;
    d.m_ccs_dcmain_status = 0;
    d.m_ccs_precharge_status = 0;
    d.Initialization();       
    QThread::msleep(1000);
    while(1)
    {       
            len = queue.isEmpty();
            if(len == 0)
            {
               flag = queue.dequeue();
            }            
            if(len == 0)
            {               
                 switch(flag)
                 {
                    case EM_Init :
                                     // QThread::msleep(5000);
                                     // qDebug()<<"Modbus Init"<<endl;
                                     // d.Initialization();
                                     break;
                    case EM_Current :
                        //            qDebug()<<"Modbus send Meter value"<<endl;
                                    d.Rishabh_DC();
                                    d.Current();
#ifdef AC_METER
                                    d.Current();
                                    d.Current_2();
#endif
                                    break;                   
                    case EM_Power :
                                    qDebug()<<"Modbus send Meter value"<<endl;
                                    d.PowerKW();
                                    d.PowerKW_2();
                                    break;
                     case EM_Unit :
                                    qDebug()<<"Modbus send Meter value"<<endl;
                                    d.EnergyKWH();
                                    d.EnergyKWH_2();
                                    break;
                 };
            }
            else
            {              
                queue.enqueue(EM_Current);
#ifdef AC_METER
                queue.enqueue(EM_Power);
                queue.enqueue(EM_Voltage);
                queue.enqueue(EM_Unit);
#endif
            }
            QThread::msleep(500);
    }
    /*****************************************************************************************/
}
