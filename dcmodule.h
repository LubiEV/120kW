#ifndef DCMODULE_H
#define DCMODULE_H

#include <QObject>
#include <QObject>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <qqueue.h>
#include<QThread>
#include <QDebug>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>
#include"keypad.h"
#include "dccomboplc.h"
#include "dccomboplc_2.h"

#include "rfid.h"
#define BuffSize 100
//#define M2
using namespace std;

enum CAN_QUEUE : quint8
{
    Pm_Off,
    Pm_On,
    Pm_Power1,
    Pm_Power2,
    Io_Card,
    read_V12,
    read_I12,
    Cable_Check,
    Start_Charging,
    Stop_Charging,
    Report_state,
    HardReset_state,
    Q_Connect,
    Q_Discharge,
    Q_Charging,
    Q_Available,
    Pm_Off_2,
    Pm_On_2,
    Pm_Power1_2,
    Pm_Power2_2,
    Io_Card_2,
    read_V12_2,
    read_I12_2,
    Cable_Check_2,
    Start_Charging_2,
    Stop_Charging_2,
    Report_state_2,
    HardReset_state_2,
    Q_Connect_2,
    Q_Discharge_2,
    Q_Charging_2,
    Q_Available_2,
    P_read_Status,
    P_read_Status_2,
    RS232_ReadError_1,
    RS232_ReadError_2,
    V_read_PhaseA_1,
    V_read_PhaseB_1,
    V_read_PhaseC_1,
    V_read_PhaseA_2,
    V_read_PhaseB_2,
    V_read_PhaseC_2,
};
enum I_O_ERROR : quint8
{
    I_O_NoError = 1,
    I_O_EMPress, //emergency press 2
    I_O_ResetKey, // press reset key 3
    I_O_DoorLock, // Open Door 4
    I_O_GNDFalut, // ground fault 5
    M_Over_Voltage, // Over voltage  6
    M_Under_Voltage, // under voltage 7
    M_Over_Current,  //  Over voltage   8
    CAN_Communication_Error, // CAN 1 Communication Error 9
    CAN2_Communication_Error, // CAN 2 Communication Error 10
    EV_Disconnected,         //EV Disconnected 11
    U_StopByPassword,        //Charging Stop by Password 12
    U_StopByRfid,           // Charging Stop By RFID 13
    U_StopByRemote,         //  Charging Stop By Remote 14
    U_StopByTimetoCharge,   // Charging Stop By Time 15
    U_StopByUnittoCharge,   // Charging Stop By Unit 16
    M_MeterFailure,         // Energy Meter Failure 17
    M_PowerSwitchFailure,   // Power Switch Failure 18
    P_Connect,              // 19
    P_Charging,             // 20
    P_Disconnect,           // 21
    P_Available,            // 22
    I2_O_GNDFalut,         // GUN2 Ground Fault 23
    C2_Communication_Error,  // 24
    EV2_Disconnected,        // 25
    P2_Connect,  //26
    P2_Charging,  //27
    P2_Disconnect, //28
    P2_Available,  //29
    I_O2_GNDFalut,      // GUN 2 Ground Fault Detection 30
    I_O_RCDdetect,       // RCD Fail Detection 31
    S_cuttofSoc,         // Charging Stop By Cutt Off SOC 32
    S_stopByTempreture,  // Charging Stop By Tempreture 33
    I_O_WaitForACMains,  // AC Main Conntactor Trip 34
    T_TimeOut,           // Time Out 35
    S_FullCharge,        // Charging Full 36
    Isolation_Fault,     // Isolation Fault 37
    EVNotReadyToCharge,   // EV Not Ready To Charge 38
    COmm_1_232_Fail,      // Gun 1 Serial Communication Fail 39
    COmm_2_232_Fail,        // Gun 2 Serial Coomunication Fail 40
    STAGE_B_DETECTED, // Gun 1 Stage B detection 41
    STAGE_B_DETECTED_2, // Gun2 Stage B detection 42
    STAGE_UNDEFINE,     // Undefine Stage 43
    C_SoftReset,        // Soft reset  44
    C_HardReset,        // Hard reset  45
    C_ChangeAvailibility, // Charging Stop By OCPP InOperative API 46
    C_HardReset_Done,  // Charging Stop by reset Key 47
    O_Available,      // Available for gun1 48
    O2_Available,     // Available for gun2 49
    Voltage_MissMatch, // Voltage MissMatch 50
};
struct Can_Module_Transmit
{
    float    Pm1_voltage;
    quint16    Pm2_voltage;
    float   Pm1_current;
    quint32    Pm2_current;
    quint8    Ac_main;
    quint8    Dc_main;
    quint8    Load_Sharing;
    quint8    Precharge;
    quint8   Fault;
    quint8   HardReset;

    Can_Module_Transmit()
    {
       Pm1_voltage = 0;
       Pm2_voltage = 0;
       Pm1_current = 0;
       Pm2_current = 0;

       Ac_main = 0xA5;
       Dc_main = 0;
       Precharge = 0;
       HardReset = 0;
       Fault = 0;
    }
};

struct Rfid_Auth
{
    char data[10];
    bool Auth;

    Rfid_Auth()
    {
        Auth = 0;
    }
};
struct PowerModuleOutput
{
    float pmdc1_volt;
    float pmdc2_volt;
    float pmdc1_curr;
    float pmdc2_curr;

    PowerModuleOutput()
    {
       pmdc1_volt = 0;
       pmdc2_volt = 0;
       pmdc1_curr = 0;
       pmdc2_curr = 0;
    }
};

struct Can_Module_Recieve
{
    quint8    Status_Imd;
    quint8    Error_Imd;
    quint16   Electricl_Isolation;
    quint8    Em_switch;
    bool    Dlk1_sensor;
    quint8    Reset_Key;
    float     Tempreture;
    quint8  AC_02_Status;
    quint8  AC_Main_Contactor_res;
    quint8  DC_Main_Contactor_res;
    quint8  DC_LoadSharing_Plus_Contactor_res;
    quint8  DC_LoadSharing_Minus_Contactor_res;
    quint8  Precharge_Contactor_res;
    quint8  RCD_Detect;

    Can_Module_Recieve()
    {
        Status_Imd = 0x00;
        Error_Imd = 0x00;
        Electricl_Isolation = 0x00;
        Em_switch = 0x00;
        Dlk1_sensor = 0x00;
     //   Dlk2_sensor = 0x00;
        Reset_Key = 0x00;
     //   Smoke_detector = 0x00;
        Tempreture = 0x00;
        AC_02_Status = 0x00;
        AC_Main_Contactor_res = 0x00;
        DC_Main_Contactor_res = 0x00;
        Precharge_Contactor_res = 0x00;
        RCD_Detect  = 0x00;
    }
};
typedef union {

    float f;

    struct

    {
        unsigned int mantissa : 23;

        unsigned int exponent : 8;

        unsigned int sign : 1;

    } raw;

} myfloat;
int tempbind();

int powerdc(int fd,float voltage,float current);
void rcvP12_v(int fd);
void rcvP12_i(int fd);
void rcvS12(int fd,unsigned char phase);
bool Off_Module(int fd);
bool On_Module(int fd);
#ifdef M2
int tempbind_2();
int powerdc_2(float voltage,float current);
void rcvP12_v_2(void);
void rcvP12_i_2(void);
void rcvS12_2(void);
bool Off_Module_2();
bool On_Module_2();
#endif


class Dcmodule : public QObject
{
    Q_OBJECT
public:
    explicit Dcmodule(QObject *parent = nullptr);    
    const char* rfid_dev_name = "/dev/input/event4";     

    int can_setting(const char* can, const int bitrate, int enable);
    int can_setting1( const long int baud_size,int enable);
#ifdef BOOT
     int boot_dc1();
     int boot_dc2();
#endif
     void IO_transmit();
#ifdef M2
     void IO2_transmit();
#endif
     void Timer_Init();
     void Imd_StatusBit(unsigned char hex);
private:
 #ifdef NO_THREAD
     dcComboPLC *ptr_ccs;
     dccomboplc_2 *ptr2_ccs;
#endif
     RFID *ptr_rf;
signals:
    void send_signal(int);
public slots:
    void TimerEvent(void);
    void TestModeEvent(void);
    void can_module_run(void);
};

#endif // DCMODULE_H
