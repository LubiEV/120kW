#ifndef DCCOMBOPLC_H
#define DCCOMBOPLC_H

#include <QObject>
#include <QtMath>
#include <QDateTime>
#include <QElapsedTimer>
#include <QtSerialPort/QSerialPort>
//#include <QWebSocket>
#include "powermdl.h"
#include "dcplc.h"
#include "dccomboplc_2.h"
//#include "powercontrol.h"
#include "tty.h"
#include <QTimer>
#include "database.h"
/*
struct stStart
{
    quint8  start;          //start : 1 stop 2
    quint8  ChargerType;    //0: not selected, 1: DC_combo type 2, 2: GB type
    quint8  Dummy[6];

    stChargerStart(quint8 nStart, quint8 nCType)
    {
        start = nStart;
        ChargerType = nCType;
        memset(Dummy, 0, sizeof(Dummy));
    }
};
*/

class dcComboPLC : public QObject
{
    Q_OBJECT
public:
    explicit dcComboPLC(QObject* parent = nullptr, int nGroup = 0);//(QObject *parent = nullptr);
    ~dcComboPLC();
private:
     dcComboPLC *ptr_ccs;
     dccomboplc_2 *ptr2_ccs;

    //int g = 1;
    int tty_fd;
    void initValues();
    void DebugString(QString sMessage);

    QElapsedTimer*  plc_ElpaseTime;
    EVSEProcessingType eNumEVSEProcess;
    responseCodeType eNumresponseCode;

    quint32 g_SetVoltage; //mV
    float g_SetCurrent1; //mA
    float evTargetVoltage = 0;
    float evTargetCurrent = 0;
    float evMaxPowerLimit =0;
    volatile bool bcurrentDemand;

    quint8     Plc_Voltage;
    bool       bPLG;
    bool       bConnected;
    bool       bCharging;
    bool       bEmergencyStop;
    bool       ReachVoltage;

    quint8     bCabelCheck_Processing;
    quint8 evseStatusCode = 0;
    quint8 IsolationStatus;

    quint8    EV_SOC = 0;
    float     evVoltageMax = 0;
    float     evCurrentMax = 0;
    float     evDiscVoltageMax = 0;
    float     evDiscCurrentMax = 0;
    float     evseCurrent = 0;
    float     evseVoltage = 0;

    float imiuPlusResistor;
    float imiuMinusResistor;

    PhysicalValue MaxEVCurrentLimit;
    PhysicalValue MaxEVVoltageLimit;
    PhysicalValue MaxEVPowerLimit;

    PhysicalValue MaxEVSECurrentLimit;
    PhysicalValue MaxEVSEVoltageLimit;
    PhysicalValue MaxEVSEPowerLimit;

    PhysicalValue MinEVSECurrentLimit;
    PhysicalValue MinEVSEVoltageLimit;

    PhysicalValue EVSECurrent;
    PhysicalValue EVSEVoltage;

    quint8  ui_Min;
    quint8  ui_Sec;

    MsgID curChagerStep;       
    uint    ncabal_check=0;   
    int  OpenSerialPort(QString sPortName);
    void CloseSerialPort();
    void SendPLC(int fd, QByteArray aData);
    void recieveData(QByteArray aData,int fd);
    quint32 getChecksum(QByteArray aData);
    void SetPhysicalValue(PhysicalValue* pValue, qint8 nMutiplier, quint8 nUnit, qint16 nValue);
    void SetLimitCurrent(qint16 nCurrent);
    void Request_ReportSTATE(int tty_fd_PLC);
    void Charger_Start(int tty_fd_PLC);
    void Charger_Stop(int tty_fd_PLC);
    void SetAuthentication(EVSEProcessingType eProcessing);
    void SetResponseCodeType(responseCodeType eResponseCode);
    void EmergencyStop();
    void EVSE_RESET(int tty_fd_PLC);
signals:
#ifdef THREAD_CHANGES
    void readReady(void);
#endif
#ifdef DONTUSE
    void sgnSetRelay(int,int);
#endif
    void sgnCCS_Relay(int);
public slots:
#ifdef THREAD_CHANGES
    void poll_read_ready();
#endif
    void Start_Fast(int tty_fd_PLC);
    void readPLC_COM();
};
#endif // DCCOMBOPLC_H
