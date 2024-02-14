#pragma once
#ifndef POWERMDL_H
#define POWERMDL_H

#include <algorithm>
#include <qglobal.h>
#include <memory.h>
#include <QString>

#define  SAFE_DELETE(p)             { if(p) { delete (p);     (p)=NULL; } }
#define STX 0x02
#define ETX 0x03
enum RelayNum
{
    MC_1 = 0,
    MC_2 = 1,
    Relay1P = 2,
    Relay1N = 3,
    Relay2P = 4,
    Relay2N = 5,
    EVSE_1 = 10,
    EVSE_2 = 11
};

enum DIO_Num
{
    EMG_SW = 4,
    FUSE1_SW = 5,
    FUSE2_SW = 6,
    BACK_DOOR = 8
};


enum ChargerStep
{
    selectChargerMode = 0,
    ConnectGun = 1,
    ChargingGun   = 2,
    ChargerFinish = 3

};
enum CanChannel
{
    BoardCan = 0,
    ModuleCan = 1,
    Gbt1Can = 2,
    Gbt2Can = 3
};

//enum usbCanBaudRate
//{
//    cb10k = 10,
//    cb20k = 20,
//    cb50k = 50,
//    cb125k = 125,
//    cb250k = 250,
//    cb500k = 500,
//    cb1000k = 1000
//};

enum PowerModule_Err
{
    Noraml  = 0x00,
    Cmd_Invalid = 0x02,
    Data_Invalid = 0x03,
    InStart_Processing = 0x07
};
enum PowerModule_Group
{
    Group0 = 0,
    Group1 = 1
};
enum Main_Relay
{
    Relay_OFF = 0,
    Relay_ON = 1
};

enum PowerModule_ONOFF
{
    MDL_ON = 0,
    MDL_OFF = 1
};

#pragma pack(push, 1)
struct cmdPacket
{
    quint8  Type;
    quint8  Dummy;
    quint8  Cmd;
    quint8  Values[4];
    quint8  Dummys[8];

    cmdPacket(quint8  type, quint8  cmd, uint nValue)
    {
        Type = type;
        Dummy = 0;
        Cmd = cmd;
        Values[0] = (quint8)(nValue & 0xff);
        Values[1] = (quint8)((nValue >> 8) & 0xff);
        Values[2] = (quint8)((nValue >> 16) & 0xff);
        Values[3] = (quint8)(nValue >> 24);
        memset(Dummys, 0, sizeof(Dummys));
    }
};

struct MsgPacket
{
    quint8  Type = 0x00;
    quint8  DLC ;
    quint8  Flags; //RTR 0x20, Can Extended 0x40, Can Stadard 0x00
    quint32 CanID;
    quint8  CanData[8];

    MsgPacket(quint32  canID, QByteArray aData, quint8 nDLC = 8, quint8 uFlags = 0x40)
    {
        //Type = type;
        memset(CanData, 0, sizeof(CanData));
        DLC = nDLC;
        Flags = uFlags;
        CanID = canID;
        memcpy(CanData, aData.constData(), sizeof(CanData));
    }
};

//********* power module Control ********//
struct stIdentifier
{
    quint8 can_SourceAddress;
    quint8 can_DestAddress;
    quint8 Cmd_No;
    quint8 Device_No;
    quint8 Err_Code;
    stIdentifier(quint32 Id_Value)
    {
        can_SourceAddress = Id_Value & 0xff;
        can_DestAddress = (Id_Value >> 8) & 0xff;
        Cmd_No = (Id_Value >> 16) & 0x3F;
        Device_No = (Id_Value >> 22) & 0x0F;
        Err_Code = (Id_Value >> 26) & 0x07;
    }
};

struct stState_Info2
{
    bool PowerLimit       ;
    bool mdlIDRepetition  ;
    bool LoadUnsharing    ;
    bool InputPhaseLost   ;
    bool InputUnbalance   ;
    bool InputUnderVoltage;
    bool InputOverVoltage ;
    bool mdlPFCsideIsOff  ;
};

struct stState_Info1
{
    bool mdlOffState      ;
    bool mdlFault         ;
    bool mdlProtect       ;
    bool FanFault         ;
    bool OverTemperature  ;
    bool OutputOverVoltage;
    bool Walk_IN          ;
    bool CommInterrupt    ;
};

struct stPowerModuleInfo
{
    int   MdlNum;
    int   GroupNum;

    float fVoltage;
    float fCurrent;
    int   temperature; //-128 ~ 127 C
    stState_Info1 state_Info1;
    stState_Info2 state_Info2;
    bool        OutputShort;
    float VAB;
    float VBC;
    float VCA;
};

struct sCharger_DIO
{
    bool bEMG_SW; // >> 4
    bool bFUSE1;  // >> 5
    bool bFUSE2;  // >> 6
    bool bDOOR;   // >> 8
};

struct stChargingInfo
{
    QString BusNumber;
    QString startTime;
    QString elapseTime;
    QString startSoc;
    QString endSoc;
    QString ChargingPower;
};

#pragma pack(pop)

quint32 static fourByteToUint32(const char * data)
{
    return (quint32)(((data[3] << 24) & 0xFF000000) | ((data[2] << 16) & 0xFF0000) | ((data[1] << 8) & 0xFF00) | (data[0] & 0xFF));
}

float static fourByteToFloat(QByteArray aData)
{
    float fValue;

    std::reverse(aData.begin(), aData.end());
    fValue = *(reinterpret_cast<const float*>(aData.constData()));

    return fValue;
}
#endif // POWERMDL_H
