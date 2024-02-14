#pragma once
#ifndef CANTOSERIALCTRL_H
#define CANTOSERIALCTRL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
//#include <QtSerialBus/QCanBusFrame>
#include <qvector.h>
#include <QTimer>

#define MAX_CHANNEL		4



//CAN RcvFrame 16byte  : IDE(32bit),RTR(31bit),Err(30bit),id(29bit)[4byte], data[8byte], time[2byte],channel(4bit),dlc(4bit),checksum[1byte]
//CAN SendFrame 16byte : IDE(32bit),RTR(31bit),Cmd(30bit),id(29bit)[4byte], data[8byte], time[2byte],channel(4bit),dlc(4bit),checksum[1byte]
//CAN SendFrame Cmd mode : id = 0 : Baudrate set [data0~1]
typedef struct
{
    uint32_t id : 29;
    uint32_t flagErr : 1;
    uint32_t flagRtr : 1;
    uint32_t flagIde : 1;

    uint8_t data[8];

    uint16_t timeStamp; //max 6553.5 ms
    uint8_t dlc : 4;
    uint8_t channel : 4;
    uint8_t timeStampHigh;
}CanRcvFrameType;

typedef struct
{
   uint32_t id : 29;         //ID 29bit
   uint32_t flagErr : 1;         //Remote Transmission Request
   uint32_t flagRtr : 1;         //Extended Identifier
   uint32_t flagIde : 1;         //Error State Indicator

   uint16_t timeStamp;      //TimeStampLow 2byte 0~65535 max 6553.5 ms
   uint8_t dlc : 4;         //DLC
   uint8_t channel : 4;      //CAN Channel 0:ch1 , 1:ch2
   uint8_t timeStampHigh;   //TimeStampHigh 1byte 0~255

   uint8_t data[8];
}canDataPackType;

typedef struct
{
    uint32_t id : 29;
    uint32_t flagSpare : 1; //
    uint32_t flagRtr : 1;   //
    uint32_t flagIde : 1;   // 1 : extend  0:standard

    uint8_t data[8];
    uint8_t cmd;
	uint8_t para;

    uint8_t dlc : 4;   // 8
    uint8_t channel : 4;
    uint8_t chksum;
}CanSendFrameType;

enum CanSendCommand
{
	scDataTx = 0,
	scBaudrateSet = 1,
	scModeSet = 2,
	scRxFilterSet = 3,
    scCanReset = 4,
    scConnected = 8,
    scDIOCtrl = 11
};

enum CanBaudRate
{
    cb100k,
    cb125k,
    cb250k,
    cb500k,
    cb1000k
};

enum CanBusError
{
    errCanBufferOverflow = 1,
    errCanTransmitTimeout = 2,
    errCanErrorCounterOverflow = 4,
    errCanBusOffError = 8,
    errUsbRs232SyntaxError = 16,
    errUsbRs232FormatError = 32,
    errUsbRs232BufferOverflow = 64
};


class CanToSerialCtrl : public QObject
{
    Q_OBJECT

    QSerialPort *serialPort;
    int m_Channel_MaxCount;
    //QVector<QCanBusFrame> *canData[MAX_CHANNEL];
    QList<QVector<canDataPackType>*> CanFrameList;

	unsigned int crc8_table[256];

    QTimer *SendTimer;
    QList<CanSendFrameType> SandList;

	void initCrc8();
	quint32 calCrc8(const char* buff);
    quint32  cal_Crc8(const char* buff);
	void receiveCmd();
	void onErrorOccurred(QSerialPort::SerialPortError error);

	CanBaudRate baudRate = cb250k;
	bool canListenOnlyMode = false;



public:
    explicit CanToSerialCtrl(QObject *parent = nullptr, int CAN_channel_Count = 1);
    ~CanToSerialCtrl();

    quint8 OUT_DIO;
    quint8 IN_DIO;
    quint8 IN_MAIN_SW;
    QString  slocLatitude;
    QString  slocLongitude;

    int m_ReconnectCount;

	bool isListenOnlyMode();
	CanBaudRate getCanBaudRate();
    bool connectDevice(QString portName = "");
    void disconnectDevice();
   
	

    qint64 framesAvailable(int channel) const;

    int error() const;
    void setSerialPortName(QString portName);
    int setCanBaudRate(CanBaudRate baudrate, int channel = 0);
	void setListenOnlyMode(bool status, int channel = 0);
	void setFilter(int BankNo, quint32 id, quint32 maskId, int channel = 0);

    int readFrame(QVector<canDataPackType>& rcvFrame, int channel = 0);
    bool writeFrame(CanSendFrameType& frame,  int channel = 0);

    void setCanChannelConnect(uint8_t Ch_Chonnect = 1);
    void setRelayDIO(int DIO_No, int state);

    //void setShutDown

    const int crcTable[256] = {
            0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
            0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
            0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
            0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
            0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
            0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
            0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
            0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
            0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
            0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
            0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
            0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
            0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
            0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
            0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
            0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
            0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
            0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
            0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
            0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
            0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
            0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
            0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
            0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
            0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
            0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
            0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
            0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
            0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
            0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
            0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
            0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3
    };
    

signals:
    void errorOccurred(int CanBusError);
    void framesReceived(int ch = 0);
    void framesWritten(qint64 framesCount);
    void SerialOpenSuccess();

public slots:
    void SendCanData();
    void ReconnectDevice();
    void StartCanConnect();
};

#endif // CANTOSERIALCTRL_H
