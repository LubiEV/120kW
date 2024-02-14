#ifndef POWERCONTROL_H
#define POWERCONTROL_H



#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialBus/QCanBusFrame>
#include <QVector>
#include <QTimer>
#include <QElapsedTimer>
#include "powermdl.h"
#include "tty.h"

class PowerControl : public QObject
{
    Q_OBJECT

private:
    explicit PowerControl(QObject *parent = nullptr, int MdlCount=20);
    static PowerControl* Powerins;
    static  bool instanceFlag;


public:
    static PowerControl* getPowerInstance(int MdlCount=1);
    static void PurgeInsatace();
    static QObject *pParent;

    //explicit PowerControl(QObject *parent = nullptr, int MdlCount=20);
    ~PowerControl();
    bool ConnectMdlCan(QString portName);
    void DisConnectMdlCan();

    void Read_Power_Mdl_Output_Tatal_Voltage_Current(quint32 aGroup);
    void Read_Power_Mdl_Count(quint32 aGroup);

    //nMdlNum 0 ~ 19
    void Read_Power_Mdl_Output_Each_Voltage_Current(quint32 nMdlNum); //MdlNum = source Address
    void Read_Power_Mdl_Each_Info(quint32 nMdlNum); //MdlNum = source Address
    void Read_Power_Mdl_Each_VAB_VBC_VCA(quint32 nMdlNum); //MdlNum = source Address


    //***********************************************************************************************************
    void Set_Power_Mdl_ALL_ON_OFF(quint32 aGroup, int nOn); // On : 0 Off : 1 , Group 0 or 1
    //nCurrent mA, nVoltage mV, Group 0 or 1
    void Set_Power_Mdl_Output_Tatal_Voltage_Current(quint32 aGroup, quint32 nCurrent, quint32 nVoltage = 750000);
    void Set_Power_Mdl_Output_Each_Voltage_Current(quint32 aGroup, quint32 nCurrent, quint32 nVoltage = 750000);
    //***********************************************************************************************************
    void Set_Power_Mdl_Output_Tatal_Voltage_Current_brocast(quint32 nCurrent, quint32 nVoltage = 750000);

    //power calculate group 1
    void Set_Power_Calculate_GP1(bool bCal);
    //power calculate group 2
    void Set_Power_Calculate_GP2(bool bCal);

    void Set_Power_Calculate_GP(int nGroup, bool bCal);


    //power reset 0
    void Reset_Power_GP1();
    void Reset_Power_GP2();
    void Reset_Power_GP(int nGroup);


    //powermodule 20EA (0 ~ 19)
    stPowerModuleInfo getEachModuleInfo(int MdlNum);
    //group total voltage ( V ) 0 ~ 1
    float getGroupVoltage(int GroupNum);
    //group total current ( A ) 0 ~ 1
    float getGroupCurrent(int GroupNum);
    float getTotalCurrent();
    //group power (W/h) 0 ~ 1
    float getGroupPower(int GroupNum);
    float getTotalPower();
    int   getGroupLiveCount(int GroupNum);
    void setCanBaudRate(uint nBaudRate);
    void setBinaryMode();
    void SaveConfig();

    int  getMaxTemp();
    void receive_CanData(uint CanId, QByteArray aData);
    void startmdlinfo();

    void StartTimer(bool bStart);

private:
    int tty_fd = -1;
    QSerialPort *serialPort;
    QVector<stPowerModuleInfo> PowerMdlData;

    QTimer *MdlInfoTimer, *GroupTimer;//, *timer3;

    quint32 MdlInfoTimer_Count, GroupTimer_Count;//, nCountMax;

    int     g_MdlCount;
    float   g_fVoltage[2];
    float   g_fTotalCurrent[2];
    float   g_fPower[2];
    int     g_GroupLiveCount[2];
    //quint32 g_SetVoltage;
    QVector<int> Tempvect;

    bool    g_bCalPowerGP1, g_bCalPowerGP2;
    QElapsedTimer  ElapsedTime;
    qint64         DcComboPLC_1_time;
    qint64         DcComboPLC_1_time_old;
    qint64         DcComboPLC_2_time;
    qint64         DcComboPLC_2_time_old;

    void receiveCanData();
    void processReceiveCommands(int cmd, QByteArray data);
    void readCanData(QCanBusFrame CanFrame);
    quint8 getChecksum(QByteArray aData);
    //void readCanData(QCanBusFrame CanFrame);
    void DecodingCanData(stIdentifier* piDentity, QByteArray aData);

    void SetPowerMdlState1(stState_Info1* pState1, char cData);
    void SetPowerMdlState2(stState_Info2* pState2, char cData);




    quint32 getPowerModuleCan_ID(quint32 nCommand, quint32 nDevice_No = 0x0A, quint32 DestAddr= 0x3F , quint32 sourceAddr = 0xF0);
    void CanWrite(quint32 Can_id, QByteArray aData);

public :
    signals:

        void readReady(void);
        void sgnRequestPowerMDLData(QCanBusFrame);


public slots:

    void poll_read_ready();
    void MdlInfoTimerEvent();
    void GroupVoltageCurrentInfoTimerEvent();

    void readPowerMDl_Data(QCanBusFrame CanFrame);

};

#endif // POWERCONTROL_H

