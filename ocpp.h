#ifndef OCPP_H
#define OCPP_H

#include <QObject>
#include <QWebSocket>
#include "cstring"
#include<QThread>
#include<QDebug>
#include<QtCore>
#include <QNetworkInterface>
#include <QRandomGenerator>
#include<qjsonarray.h>
#include"database.h"

//#include "mainwindow.h"
//#include <QMainWindow>

struct Elf64Hdr{
    quint8     e_ident[16];         /* Magic number and other info */
    quint16    e_type;              /* Object file type */
    quint16    e_machine;           /* Architecture */
    quint32    e_version;           /* Object file version */
    quint64    e_entry;             /* Entry point virtual address */
    quint64    e_phoff;             /* Program header table file offset */
    quint64    e_shoff;             /* Section header table file offset */
    quint32    e_flags;             /* Processor-specific flags */
    quint16    e_ehsize;            /* ELF header size in bytes */
    quint16    e_phentsize;         /* Program header table entry size */
    quint16    e_phnum;             /* Program header table entry count */
    quint16    e_shentsize;         /* Section header table entry size */
    quint16    e_shnum;             /* Section header table entry count */
    quint16    e_shstrndx;          /* Section header string table index */
    Elf64Hdr()
    {

    }
};
enum SessionStatus{
  Charging_Stop,
   Try_To_Start,
   Charging_Start,
   Try_To_Stop,
};
enum enLoadSharing{    
    LS_No = 0,
    LS_Yes,
    LS_Active,
    LS_Available,
    LS_Occupie,
    LS_NotAvailable
};
enum OCPP_req : quint8
{
    init_EVSE = 0x00,
    G1_StatusNotification = 0x01,
    G2_StatusNotification = 0x02,
    G1_StartTransaction = 0x03,
    G2_StartTransaction = 0x04,
    G1_StopTransaction = 0x05,
    G2_StopTransaction = 0x06,
    G1_MeterValue = 0x07,
    G2_MeterValue = 0x08,
    G1_Authorise = 0x09,
    G2_Authorise = 0x0a,
    HeartBeat = 0x0b,
    ClockAlignData,
    ClockAlignData_2,   
    FirmwareStatusNotification,
    Tagid_search,
    TransactionBegin,
    TransactionBegin_2,
    TransactionEnd,
    TransactionEnd_2
};
enum OCPP_res : quint8
{
    BootNotification_res = 0x00,
    G1_StatusNotification_res = 0x01,
    G2_StatusNotification_res = 0x02,
    G1_StartTransaction_res = 0x03,
    G2_StartTransaction_res = 0x04,
    G1_StopTransaction_res = 0x05,
    G2_StopTransaction_res = 0x06,
    G1_MeterValue_res = 0x07,
    G2_MeterValue_res = 0x08,
    G1_Authorise_res = 0x09,
    G2_Authorise_res = 0x0a,
};
enum OCPP_Error : quint8
{
    ConnectorLockFailure = 0x00,
    EVCommunicationError,
    GroundFailure,
    HighTemperature,
    InternalError,
    LocalListConflict,
    NoError,
    OtherError,
    OverCurrentFailure,
    PowerMeterFailure,
    PowerSwitchFailure,
    ReaderFailure,
    ResetFailure,
    UnderVoltage,
    OverVoltage,
    WeakSignal    
};

enum OCPP_Reason : quint8
{
    EmergencyStop = 0x01,
    EVDisconnected,
    HardReset,
    Local,
    Other,
    PowerLoss,
    Reboot,
    Remote,
    SoftReset,
    UnlockCommand,
    DeAuthorized
};
enum OCPP_Status : quint8
{
    Available,
    Preparing,
    Charging,
    SuspendedEVSE,
    SuspendedEV,
    Finishing,
    Reserved,
    Unavailable,
    Faulted
};
enum OCPP_Key : quint8
{
    update_LocalAuthListEnbl =1,
    update_FailedTx_Intvl,
    update_StopTxInvalidId,
    update_ResetRetry,
    update_StatusDuration,
    update_MeterIntvl,
    update_LocalPreAuth,
    update_LocalAuthOffln,
    update_ClkAlgnIntvl,
    update_AuthRemotTx,
    update_AuthCachEnable,
    update_AllowOfflineTXUnknownId,
    update_HeartbeatIntvl,
    update_Operative,
    update_LocalListVersion,
};
struct Charger_Status
{
    int conn;
    quint8 start;
    quint8 Error;
    quint8 Reson;
    quint8 Status;
    quint8 OCPP_Pending_Tx;
    quint32 Energy;
    QDateTime StartTime;
    QDateTime  EndTime;

    float current_L1;
    float current_L2;
    float current_L3;

    float voltage_L3;
    float voltage_L2;
    float voltage_L1;

    float DC_Voltage_1;
    float DC_Voltage_2;

    float DcOutputModule_1;
    float DcOutputModule_2;

    float DC_Current_1;
    float DC_Current_2;

    quint32 Start_Energy;
    double End_Energy;
    float  Power;
    QString TadId;
    QString RfidTagId;
    quint64 TxnId;
    quint8 SOC;
    qint8 SCAN_TAGID;

    quint8   Tempreture_exhaust;
    quint8   Tempreture_dcP;
    quint8   Tempreture_dcN;
    quint32  Setting_Time;
    quint32  Setting_Unit;
    quint8   Automatic_Start;
    quint8   TimeOut;   
    quint32 PM_Status;
    quint32 PM_Status_2;
    Charger_Status(int con)
    {
        conn = con,
        TimeOut = 0;
        Error = NoError;
        OCPP_Pending_Tx = 0;
        Reson = Other;
        Status = Available;
        SCAN_TAGID = 0;
        Energy = 0;
        start =  0;
        Start_Energy = 0;
        End_Energy = 0;
        voltage_L3 = voltage_L2 = voltage_L1 = 415;
    }
};

struct Parameter
{
   QString URL;
   int32_t Port;
   QString IP;
   QString SubnetMask;
   QString Getway;
   QString ssid;
   QString password;
   QString GSM_APN;
   int8_t GSM_IPV;
   int8_t Network;
   int8_t Ocpp_Status;
    int8_t check_OCPP;
   int8_t Network_status;
   int time_charges;
   int unit_charges;
   int Over_Voltage;
   int Under_Voltage;
   int Over_Current_ccs;
   int DC_IMAX;
   int DC_PMAX;
   int DC_VMAX;
   int DC_IMin;
   int DC_PMin;
   int DC_VMin;
   QString Serial_Number;
   QString FW_SN;
   QString FW_Path;
   QString FW_UN;
   QString FW_PW;
   unsigned int  FW_Port;
   int SleepTime;
   int Brightness;
   float TimeOffset;
    int tempThresold;
    int cutoffsoc;
    bool tempThresold_ED;
    bool cutoffsoc_ED;
    bool DoorlOCK_ED;
    bool TestMode_ED;
    bool GroundFault_ED;
    bool IsolationFault_ED;
    bool LoadSharing_ED;
    bool PostSLSharing_ED;
    bool PreSLoadsharing_ED;
    bool PMIndividual_ED;
    bool TouchInterval_ED;
    int TouchInterval;
    int Availibility;
    Parameter() {
        Ocpp_Status =0;
        Network_status =0;
        time_charges =0;
        unit_charges =0;
        tempThresold =65;
        cutoffsoc_ED = false;
        tempThresold_ED = false;
        DoorlOCK_ED = true;
        TestMode_ED = false;
        cutoffsoc = 100;
        Over_Voltage =0;
        Under_Voltage =0;
        Over_Current_ccs =0;
        TouchInterval_ED = false;
        PostSLSharing_ED = false;
        PreSLoadsharing_ED = false;
        PMIndividual_ED = false;
        LoadSharing_ED = false;
        TouchInterval = 120;
        DC_IMAX =0;
        DC_PMAX =0;
        DC_VMAX =0;
        DC_IMin =0;
        DC_PMin =0;
        DC_VMin =0;
        Brightness = 6;
        SleepTime = 30;
        Serial_Number = "420420";
    }
};
struct Config_Parameter_OCPP{

    bool LocalAuthListEnbl;
    bool StopTxInvalidId;
    bool LocalPreAuth;
    bool LocalAuthOffln;
    bool AuthRemotTx;
    bool AuthCachEnable;
    int Operative;
    unsigned int FailedTx_Intvl;
    unsigned char FailedAttempt;
    unsigned char ResetRetry;
    unsigned int StatusDuration;
    unsigned int MeterIntvl;
    unsigned int ClkAlgnIntvl;
    unsigned int HeartbeatIntvl;
    unsigned int LocalListVersion;
    bool AllowOfflineTXUnknownId;

    Config_Parameter_OCPP()
    {
        LocalAuthListEnbl =1;
        FailedTx_Intvl = 300;
        StopTxInvalidId = true;
        ResetRetry =2;
        StatusDuration = 300;
        MeterIntvl = 300;
        LocalPreAuth = true;
        LocalAuthOffln = true;
        ClkAlgnIntvl = 900;
        AuthRemotTx = true;
        AuthCachEnable = false;
        AllowOfflineTXUnknownId = false;
        LocalListVersion =0;
        HeartbeatIntvl = 300;
        Operative = true;
    }
};
struct LoadSharing
{
    bool Is_LoadSharing;
    quint8 G1_Need_Tb_LS;
    quint8 G2_Need_Tb_LS;
    quint8 G1_Is_Available_LS;
    quint8 G2_Is_Available_LS;
    LoadSharing() {
         G1_Need_Tb_LS = G2_Need_Tb_LS = 0;
         G1_Is_Available_LS = G2_Is_Available_LS =  1;
    }
};
enum NetworkSelection
{
    Wifi_selection = 1,
    Ethernet_selection,
    GSM_selection,
};

class OCPP: public QObject
{
    Q_OBJECT
    Database *db;
public:
    explicit OCPP(QObject* parent = nullptr);
    QWebSocket m_webSocket;
    QNetworkInterface ifaces;
    QStringList list;
    QTime time;
    QDate date;
    QString MsgId;
    QString OCPP_URL;
    bool OCPP_Live = 0;
    bool m_Live = 0;
    u_int8_t trytoconnect = 0;
    bool BootSuccess=0;
    quint16 interval_Time = 300;
    bool m_Popen= 0;
    QString strError;
    QString strStatus;
    QString strReson;
    QString datetime;
    qint64 value;
    QRandomGenerator generator;

    QString RandomBootNotification;

    QString RandomAuthorised_G1;
    QString RandomAuthorised_G2;

    QString RandomMeterValue_G1;
    QString RandomMeterValue_G2;

    QString RandomStartTrans_G1;
    QString RandomStartTrans_G2;

    QString RandomStopTrans_G1;
    QString RandomStoptTrans_G2;

     void open(void);
     void close(void);
     bool isPeripharalConnect(quint8 con);
     bool isConnectOCPP(void);
     bool EthernetConfig(QString ip , QString getway ,QString subnet,bool enable);
     bool WiFiConfig(QString ssid,QString passwd,bool enable);
     bool GSM_connect(QString APN, int IPV, bool enable);
     bool Network_disable(int8_t network);
     void BootNotification_req(QString RandomNumber, QString chargePointVendor,QString SerialNo);
     void HeartBeat_req(QString RandomNumber);
     void StatusNotification_req(QString RandomNumber,int connector,QString error,QString status,QString datetime);
     void Authorise_req(QString RandomNumber,QString IdTag);
     void StartTransaction_req(QString RandomNumber,int connector,QString IdTag,double metervalue,int reservationId,QString datetime);
     void StopTransaction_req(QString RandomNumber,QString IdTag,int stopValue,QString reason,unsigned long int txId,QString datetime);
     void Metervalue_req(QString RandomNumber,int connector,unsigned long int txId,qint8 SOC,float Tempreture,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString datetime);
     void Metervalue_req_begin(QString RandomNumber,int connector,unsigned long int txId,qint8 SOC,float Tempreture,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString datetime);
     void Metervalue_req_end(QString RandomNumber,int connector,unsigned long int txId,qint8 SOC,float Tempreture,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString datetime);
     void Remote_res(QString MsgId,QString status);
     void getconfig_response(QString RandomNumber,int interval);
     void Metervalue_ClockAlign_req(QString RandomNumber,int connector,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString DateTime);

     QString errortostring(char);
     QString statustostring(char);
     QString resontostring(char);
     QString currentDateTime(void);
 public :
     bool replyFinished(QString FileName,long File_Size);
     bool Start_Sh(QString FileName);

    void ocpp_run(void);
    void Init(void);
  //   ~OCPP();
public slots:
   void onOCPPConnected(void);
   void onOCPPdisConnected();
   void TimerEvent(void);
   void onOcppTextMessageReceived(const QString message);
signals:
   void RmtCharger_Start(int);
   void RmtCharger_Stop(int);
};
#endif // OCPP_H
