#ifndef DCPLC_H
#define DCPLC_H
#include <QtMath>
#include <QDateTime>
////////////////////////////////////////
struct stChargerUI_Info
{
    bool  ui_bPlc_Session;
    bool  bfastCharger;
    float ui_Current;
    float ui_Voltage;
    float ui_DC_1_Voltage;
    float ui_DC_2_Voltage;
    float ui_DC_1_Current;
    float ui_DC_2_Current;
    float ui_Power;
    quint32 ui_ElapsedTime;
    float ui_Utilization;
  //  uint32 ntime;
    quint8  ui_Min;
    quint8  ui_Sec;
    quint8  ui_StartSoc;
    quint8  ui_Soc;
    quint8  ui_Plc_Error_Code;
    quint8  ui_Plc_Voltage;
    quint8  Temp_DC_Pos;
    quint8  Temp_DC_Neg;
    quint8  Temp_DC_panel;
    quint16 ui_Charger_ErrorCode;
};

enum MsgID : quint8
{
    NONE_ID         = 0,
    SessionSetupReq = 0x02,
    SessionSetupRes = 0x82,
    ServiceDiscoveryReq = 0x03,
    ServiceDiscoveryRes = 0x83,
    ServicePaymentSelectionReq = 0x05,
    ServicePaymentSelectionRes = 0x85,
    ContractAuthenticationReq = 0x07,
    ContractAuthenticationRes = 0x87,
    ChargeParameterDiscoveryReq = 0x08,
    ChargeParameterDiscoveryRes = 0x88,
    PowerDeliveryReq = 0x09,
    PowerDeliveryRes = 0x89,
    CableCheckReq = 0x0F,
    CableCheckRes = 0x8F,
    PreChargeReq = 0x10,
    PreChargeRes = 0x90,
    CurrentDemandReq = 0x11,
    CurrentDemandRes = 0x91,
    WeldingDetectionReq = 0x12,
    WeldingDetectionRes = 0x92,
    SessionStopReq = 0x0C,
    SessionStopRes = 0x8C,
    ReportINITReq = 0xF1,
    ReportINITRes = 0x71,
    ReportSLAC = 0x72,
    ReportSDP = 0x73,
    ReportV2G = 0x74,
    ReportSTATE = 0x75,
    ReportSTATEReq = 0xF5
};

enum responseCodeType : quint8
{
    OK=0,
    OK_NewSessionEstablished=1,
    OK_OldSessionJoined=2,
    OK_CertificateExpiresSoon=3,
    FAILED=4,
    FAILED_SequenceError=5,
    FAILED_ServiceIDInvalid=6,
    FAILED_UnknownSession=7,
    FAILED_ServiceSelectionInvalid=8,
    FAILED_PaymentSelectionInvalid=9,
    FAILED_CertificateExpired=10,
    FAILED_SignatureError=11,
    FAILED_NoCertificateAvailable=12,
    FAILED_CertChainError=13,
    FAILED_ChallengeInvalid=14,
    FAILED_ContractCanceled=15,
    FAILED_WrongChargeParameter=16,
    FAILED_PowerDeliveryNotApplied=17,
    FAILED_TariffSelectionInvalid=18,
    FAILED_ChargingProfileInvalid=19,
    FAILED_EVSEPresentVoltageToLow=20,
    FAILED_MeteringSignatureNotValid=21,
    FAILED_WrongEnergyTransferType=22
};

enum Error_Code : quint8
{
    GQ_NO_ERROR = 0,
    GQ_INIT_ERROR_GENERAL = 0x10,
    GQ_INIT_ERROR_IFADDR = 0x11,
    GQ_INIT_ERROR_THREAD = 0x12,
    GQ_INIT_ERROR_OPENCHANNEL = 0x13,
    GQ_INIT_ERROR_KEY = 0x14,
    GQ_SLAC_ERROR_GENERAL = 0x20,
    GQ_SLAC_ERROR_TIMER_INIT = 0x21,
    GQ_SLAC_ERROR_TIMER_TIMEOUT = 0x22,
    GQ_SLAC_ERROR_TIMER_MISC = 0x23,
    GQ_SLAC_ERROR_PARAM_TIMEOUT = 0x24,
    GQ_SLAC_ERROR_PARAM_SOCKET = 0x25,
    GQ_SLAC_ERROR_START_ATTEN_CHAR_TIMEOUT = 0x26,
    GQ_SLAC_ERROR_MNBC_SOUND_TIMEOUT = 0x27,
    GQ_SLAC_ERROR_ATTEN_CHAR_TIMEOUT = 0x28,
    GQ_SLAC_ERROR_ATTEN_CHAR_SOCKET = 0x29,
    GQ_SLAC_ERROR_VALIDATE_1_TIMEOUT = 0x2a,
    GQ_SLAC_ERROR_VALIDATE_1_SOCKET = 0x2b,
    GQ_SLAC_ERROR_VALIDATE_2_TIMEOUT = 0x2c,
    GQ_SLAC_ERROR_VALIDATE_2_SOCKET = 0x2d,
    GQ_SLAC_ERROR_BCB_TOGGLE_TIMEOUT = 0x2e,
    GQ_SLAC_ERROR_MATCH_TIMEOUT = 0x2f,
    GQ_SLAC_ERROR_MATCH_SOCKET = 0x30,
    GQ_SLAC_ERROR_READ_SOCKET = 0x31
    //GQ_SLAC_ERROR_SET_KEY = 0x32,
};

enum serviceCategoryType
{
    EVCharging=0,
    Internet=1,
    ContractCertificate=2,
    OtherCustom_=3
};

enum paymentOptionType
{
    Contract=0,
    ExternalPayment=1
};

/*enum Charger_state
{
    Start_Charging=1,
    Stop_Charging=2,
    Report_state =3,
    HardReset_state,
};*/

enum EVSESupportedEnergyTransferType
{
    AC_single_phase_core=0,
    AC_three_phase_core=1,
    DC_core=2,
    DC_extended=3,
    DC_combo_core=4,
    DC_dual=5,
    AC_core1p_DC_extended=6,
    AC_single_DC_core=7,
    AC_single_phase_three_phase_core_DC_extended=8,
    AC_core3p_DC_extended=9
};

enum EVSEProcessingType
{
    Finished=0,
    Ongoing=1
};

/*
enum EVRequestedEnergyTransferType
{
    AC_single_phase_core=0,
    AC_three_phase_core=1,
    DC_core=2,
    DC_extended=3,
    DC_combo=4,
    DC_unique=5
};
*/
enum EVSENotificationType
{
    None=0,
    StopCharging=1,
    ReNegotiation=2
}
;
enum EVSEIsolationStatus
{
    Invalid=0,  //An isolation test has not been carried out.
    Valid=1,    //The isolation test has been carried out successfully
                //and did not result in an isolation warning or fault.
    Warning=2,  //The measured isolation resistance
                //is below the warning level defined in IEC 61851-23.
    Fault=2     //The measured isolation resistance is
                //below the fault level defined in IEC 61851-23.
};
enum DC_EVSEStatusCodeType
{
    EVSE_NotReady=0,
    EVSE_Ready=1,
    EVSE_Shutdown=2,                  // charger stop request
    EVSE_UtilityInterruptEvent=3,
    EVSE_IsolationMonitoringActive=4,
    EVSE_EmergencyShutdown=5,
    EVSE_Malfunction=6,
    Reserved_8=7,
    Reserved_9=8,
    Reserved_A=9,
    Reserved_B=10,
    Reserved_C=11
};
enum StatusOfGQSE
{
    G_Connected =1,
    G_Disconnected =2,
    G_charging =3,
    G_Discharging =4,
    G_Available =5,
    G_faulted = 6,
    G_TimeOut = 7,
    G_Finished=8,
    G_CableCheck_Fault,
    G_PreCharge_Fault,
    G_CurrentDemand_Fault,
    G_EVDisconnected,
    /*************************************************/
    G_Connected_2,
    G_Disconnected_2,
    G_charging_2,
    G_Discharging_2,
    G_Available_2,
    G_faulted_2,
    G_TimeOut_2,
    G_Finished_2,
    G_CableCheck_Fault_2,
    G_PreCharge_Fault_2,
    G_CurrentDemand_Fault_2,
    G_EVDisconnected_2,
};
enum unitSymbolType
{
    h=0,
    m=1,
    s=2,
    A=3,
    Ah=4,
    V=5,
    VA=6,
    W=7,
    W_s=8,
    Wh=9
};
#pragma pack(push, 1)

struct PhysicalValue
{
   qint8    Multiplier;
   quint8   Unit;
   qint16   Value;

};

static QString  getUnit(int nUnit)
{
    QString sUnit;
    switch (nUnit) {
        case 0 : sUnit = "h"; break;
        case 1 : sUnit = "m"; break;
        case 2 : sUnit = "s"; break;
        case 3 : sUnit = "A"; break;
        case 4 : sUnit = "Ah"; break;
        case 5 : sUnit = "V"; break;
        case 6 : sUnit = "VA"; break;
        case 7 : sUnit = "W"; break;
        case 8: sUnit = "W_s"; break;
        case 9 : sUnit = "Wh"; break;
    }
    return sUnit;
};
struct UnitValue
{
    QString sValue;
    QString sUnit;
    float   fValue;
    UnitValue(PhysicalValue* pValue)
    {
        fValue =  pValue->Value * qPow(10, pValue->Multiplier);
        sUnit = getUnit(pValue->Unit);
        sValue = QString::number(fValue) + sUnit;
    }
};

struct Msg_Header
{
    //quint8 chSign[2] = {'W','J'};
    quint8 chSign[2] = {'K','R'};
    quint8 Msg_ID;
    quint8 Msg_LEN;
};
struct stSessionSetupReq
{
    Msg_Header MsgHeader;
    quint8 EVCCIDLength;
    quint8 Padding[3];
    quint8 EVCCID[8];
    quint32 Checksum;
};

struct stSessionSetupRes
{
    Msg_Header MsgHeader;
    quint8 ResCode;
    quint8 Padding[3];
    quint32 DateTimeNow = 0x060C07E5;
    quint8 EVSEIDLength;
    quint8 Padding2[3];
    quint8 EVSEID[32];
    quint32 Checksum;
    stSessionSetupRes(quint8 nResCode = 0)
    {
        MsgHeader.Msg_ID = SessionSetupRes;//0x82;
        MsgHeader.Msg_LEN = sizeof(stSessionSetupRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEIDLength = 1;
        memset(Padding,0, sizeof(Padding));
        memset(EVSEID,0, sizeof(EVSEID));
        Checksum = 0;
        QDateTime currentDateTime = QDateTime::currentDateTimeUtc();
        DateTimeNow = currentDateTime.toTime_t();
    }
};
struct stServiceDiscoveryReq
{
    Msg_Header  MsgHeader;
    quint8      ServiceCategory;
    quint8      Padding[3];
    quint32     Checksum;
};
struct stServiceDiscoveryRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint16     ServiceID;
    quint8      ServiceCategory;
    quint8      EnergyTransferType;
    quint8      NumOfOptions;
    quint8      Options[2];
    quint8      Padding2;
    quint32     Checksum;
    stServiceDiscoveryRes(quint8 nResCode = 0)
    {
        MsgHeader.Msg_ID = ServiceDiscoveryRes;//0x83;
        MsgHeader.Msg_LEN = sizeof(stServiceDiscoveryRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        memset(Padding,0, sizeof(Padding));
        ServiceID = 1;
        ServiceCategory = 0;
        EnergyTransferType = 3;
        NumOfOptions = 1;
        Options[0] = 1;
        Options[1] = 0;
        Padding2 = 0;
        Checksum = 0;
    }
};

struct stServicePaymentSelectionReq
{
    Msg_Header  MsgHeader;
    quint8      SelectedPaymentOption;
    quint8      NumOfServices;
    quint8      ServiceID[4];
    quint8      Padding[2];
    quint32     Checksum;

};

struct stServicePaymentSelectionRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint32     Checksum;
    stServicePaymentSelectionRes(quint8 nResCode = 0)
    {
        MsgHeader.Msg_ID = ServicePaymentSelectionRes;//0x85;
        MsgHeader.Msg_LEN = sizeof(stServicePaymentSelectionRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        memset(Padding,0, sizeof(Padding));
        Checksum = 0;
    }
};

struct stContractAuthenticationReq
{
    Msg_Header  MsgHeader;
    quint32     Checksum;
};
struct stContractAuthenticationRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      EVSEProcessing;
    quint8      Padding[2];
    quint32     Checksum;
    stContractAuthenticationRes(quint8 nResCode = 0, quint8 nEVSEProcessing = 0)
    {
        MsgHeader.Msg_ID = ContractAuthenticationRes;//0x87;
        MsgHeader.Msg_LEN = sizeof(stContractAuthenticationRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEProcessing = nEVSEProcessing;
        memset(Padding,0, sizeof(Padding));
        Checksum = 0;
    }
};
struct stChargeParameterDiscoveryReq
{
    Msg_Header  MsgHeader;
    quint8      EVRequestedEngergyTransferType;
    quint8      Padding[3];
    quint8      EVStatus_EVReady;
    quint8      EVStatus_EVCabinConditioning;
    quint8      EVStatus_EVRESSConditioning;
    quint8      EVStatus_EVErrorCode;
    quint8      EVStatus_EVRESSSOC;
    quint8      Padding2[3];
    PhysicalValue     EVMaximumCurrentLimit;
    PhysicalValue     EVMaximumPowerLimit;
    PhysicalValue     EVMaximumVoltageLimit;
    PhysicalValue     EVEnergyCapacity;
    PhysicalValue     EVEnergyRequest;
    quint8      FullSOC;
    quint8      BulkSOC;
    quint8      Padding3[2];
    qint32      Checksum;
};

struct stChargeParameterDiscoveryRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint8      EVSEProcessing;
    quint8      Padding2[3];
    quint8      EVSEStatus_EVSEIsolationStatus;
    quint8      EVSEStatus_EVSEStatusCode;
    quint8      EVSEStatus_EVSENotification;
    quint8      Padding3;
    quint32     EVSEStatus_NotificationMaxDelay = 0;       //CHANGED
    PhysicalValue     EVSEMaximumCurrentLimit;
    PhysicalValue     EVSEMaximumPowerLimit;
    PhysicalValue     EVSEMaximumVoltageLimit;
    PhysicalValue     EVSEMinimumCurrentLimit;
    PhysicalValue     EVSEMinimumVoltageLimit;
    PhysicalValue     EVSECurrentRegulationTolerance;
    PhysicalValue     EVSEPeakCurrentRipple;
    PhysicalValue     EVSEEnergyToBeDelivered;
    quint8      NumOfSAScheduleTuples =1;
    quint8      Padding4[3];
    quint16     SAScheduleTuple0_SAScheduleTupleID = 10;
    quint16     SAScheduleTuple0_PMaxScheduleID= 20;
    quint8      SAScheduleTuple0_NumOfEntries =1 ;
    quint8      Padding5[3];
    quint16     SAScheduleTuple0_PMaxSchedule0_Pmax;
    quint8      Padding6[2];
    quint32     SAScheduleTuple0_PMaxSchedule0_Start = 0;
    quint16     SAScheduleTuple0_PMaxSchedule1_Pmax=0;
    quint8      Padding7[2];
    quint32     SAScheduleTuple0_PMaxSchedule1_Start = 0;
    quint8      SAScheduleTuple0_durationvalid = 1;
    quint8      Padding8[3];
    quint32     SAScheduleTuple0_duration = 86400;
    quint16     SAScheduleTuple1_SAScheduleTupleID = 11;
    quint16     SAScheduleTuple1_PMaxScheduleID = 21;
    quint8      SAScheduleTuple1_NumOfEntries = 2;
    quint8      Padding9[3];
    quint16     SAScheduleTuple1_PMaxSchedule0_Pmax=0; //CHANGED
    quint8      Padding10[2];
    quint32     SAScheduleTuple1_PMaxSchedule0_Start = 0;
    quint16     SAScheduleTuple1_PMaxSchedule1_Pmax=0;
    quint8      Padding11[2];
    quint32     SAScheduleTuple1_PMaxSchedule1_Start=0;
    quint8      SAScheduleTuple1_durationvalid=1;
    quint8      Padding12[3];
    quint32     SAScheduleTuple1_duration=0;
    quint32     Checksum;
    stChargeParameterDiscoveryRes(quint8 nResCode = 0, quint8 uEvseStatus = 0)
    {
        MsgHeader.Msg_ID = ChargeParameterDiscoveryRes;//0x85;
        MsgHeader.Msg_LEN = sizeof(stChargeParameterDiscoveryRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;

        EVSEProcessing = Finished;
        EVSEStatus_EVSEIsolationStatus = Valid;
        EVSEStatus_EVSEStatusCode = uEvseStatus;
        EVSEStatus_EVSENotification = None;

        Checksum = 0;

        memset(Padding,0, sizeof(Padding));
        memset(Padding2,0, sizeof(Padding2));
        Padding3 = 0;
        memset(Padding4,0, sizeof(Padding4));
        memset(Padding5,0, sizeof(Padding5));
        memset(Padding6,0, sizeof(Padding6));
        memset(Padding7,0, sizeof(Padding7));
        memset(Padding8,0, sizeof(Padding8));
        memset(Padding9,0, sizeof(Padding9));
        memset(Padding10,0, sizeof(Padding10));
        memset(Padding11,0, sizeof(Padding11));
        memset(Padding12,0, sizeof(Padding12));
    }
};

struct stPowerDeliveryReq
{
    Msg_Header  MsgHeader;
    quint8      ReadyToChargeState;     //1 이면 충전 시작, 0 충전정지
    quint8      Padding[3];
    quint8      EVStatus_EVReady;     //1 이면 EV ready
    quint8      EVStatus_EVCabinConditioning;
    quint8      EVStatus_EVRESSConditioning;
    quint8      EVStatus_EVErrorCode;
    quint8      EVStatus_EVRESSSOC;
    quint8      Padding2[3];
    quint8      BulkChargingComplete;
    quint8      ChargingComplete;
    quint8      Padding3[2];
    quint16     SAScheduleTupleID; //앞서 충전기가 제공한 ID들 중 EV가 선택한 ID
    quint8      Padding4[2];
    quint8      NumOfProfileEntries;
    quint8      Padding5[3];

    quint32     ProfileEntry0_ChargingProfileEntryStart;
    quint16     ProfileEntry0_ChargingProfileEntryMaxPower;
    quint8      Padding6[2];
    quint32     ProfileEntry1_ChargingProfileEntryStart;
    quint16     ProfileEntry1_ChargingProfileEntryMaxPower;
    quint8      Padding7[2];
    quint32     ProfileEntry2_ChargingProfileEntryStart;
    quint16     ProfileEntry2_ChargingProfileEntryMaxPower;
    quint8      Padding8[2];
    quint32     ProfileEntry3_ChargingProfileEntryStart;
    quint16     ProfileEntry3_ChargingProfileEntryMaxPower;
    quint8      Padding9[2];
    quint32     ProfileEntry4_ChargingProfileEntryStart;
    quint16     ProfileEntry4_ChargingProfileEntryMaxPower;
    quint8      Padding10[2];
    quint32     ProfileEntry5_ChargingProfileEntryStart;
    quint16     ProfileEntry5_ChargingProfileEntryMaxPower;
    quint8      Padding11[2];
    quint32     ProfileEntry6_ChargingProfileEntryStart;
    quint16     ProfileEntry6_ChargingProfileEntryMaxPower;
    quint8      Padding12[2];
    quint32     ProfileEntry7_ChargingProfileEntryStart;
    quint16     ProfileEntry7_ChargingProfileEntryMaxPower;
    quint8      Padding13[2];
    quint32     ProfileEntry8_ChargingProfileEntryStart;
    quint16     ProfileEntry8_ChargingProfileEntryMaxPower;
    quint8      Padding14[2];
    quint32     ProfileEntry9_ChargingProfileEntryStart;
    quint16     ProfileEntry9_ChargingProfileEntryMaxPower;
    quint8      Padding15[2];

};

struct stPowerDeliveryRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint8      EVSEStatus_EVSEIsolationStatus;
    quint8      EVSEStatus_EVSEStatusCode;
    quint8      EVSEStatus_EVSENotification;
    quint8      Padding2;
    quint32     EVSEStatus_NotificationMaxDelay;
    quint32     Checksum;

    stPowerDeliveryRes(quint8 nResCode = 0, quint8 uEvseStatus = 0)
    {
        MsgHeader.Msg_ID = PowerDeliveryRes;
        MsgHeader.Msg_LEN = sizeof(stPowerDeliveryRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEStatus_EVSEIsolationStatus = 1;
        EVSEStatus_EVSEStatusCode = uEvseStatus;
        EVSEStatus_EVSENotification = None;
        EVSEStatus_NotificationMaxDelay = 0;

        memset(Padding,0, sizeof(Padding));
        Padding2 =0;
        Checksum = 0;
    }
};
struct stCableCheckReq
{
    Msg_Header  MsgHeader;
    quint8      EVSEStatus_EVReady;     //1 이면 EV ready
    quint8      EVStatus_EVCabinConditioning;
    quint8      EVStatus_EVRESSConditioning;
    quint8      EVStatus_EVErrorCode;
    quint8      EVStatus_EVRESSSOC;
    quint8      Padding[3];
    quint32     Checksum;
};

struct stCableCheckRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint8      EVSEProcessing;
    quint8      Padding2[3];
    quint8      EVSEStatus_EVSEIsolationStatus;
    quint8      EVSEStatus_EVSEStatusCode;
    quint8      EVSEStatus_EVSENotification;
    quint8      Padding3;
    quint32     EVSEStatus_NotificationMaxDelay;
    quint32     Checksum;
    stCableCheckRes(quint8 nResCode, quint8 uEvseStatus)
    {
        MsgHeader.Msg_ID = CableCheckRes;
        MsgHeader.Msg_LEN = sizeof(stCableCheckRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEProcessing = Finished;
        EVSEStatus_EVSEIsolationStatus = 1;
        EVSEStatus_EVSEStatusCode = uEvseStatus;
        EVSEStatus_EVSENotification = None;
        EVSEStatus_NotificationMaxDelay = 0;
        memset(Padding,0, sizeof(Padding));
        memset(Padding2,0, sizeof(Padding2));
        Padding3 = 0;
    }
};
struct stPreChargeReq
{
    Msg_Header  MsgHeader;
    quint8      EVSEStatus_EVReady;     //1 이면 EV ready
    quint8      EVStatus_EVCabinConditioning;
    quint8      EVStatus_EVRESSConditioning;
    quint8      EVStatus_EVErrorCode;
    quint8      EVStatus_EVRESSSOC;
    quint8      Padding[3];
    PhysicalValue   EVTargetVoltage;
    PhysicalValue   EVTargetCurrent;
    quint32     Checksum;
};

struct stPreChargeRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint8      EVSEStatus_EVSEIsolationStatus;
    quint8      EVSEStatus_EVSEStatusCode;
    quint8      EVSEStatus_EVSENotification;
    quint8      Padding2;
    quint32     EVSEStatus_NotificationMaxDelay;
    PhysicalValue   EVSEPresentVoltage;
    quint32     Checksum;
    stPreChargeRes(quint8 nResCode = 0, quint8 uEvseStatus=0)
    {
        MsgHeader.Msg_ID = PreChargeRes;
        MsgHeader.Msg_LEN = sizeof(stPreChargeRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEStatus_EVSEIsolationStatus = Valid;
        EVSEStatus_EVSEStatusCode = uEvseStatus;
        EVSEStatus_EVSENotification = None;
        EVSEStatus_NotificationMaxDelay = 0;
        memset(Padding,0, sizeof(Padding));
        Padding2 = 0;
    }
};

struct stCurrentDemandReq
{
    Msg_Header  MsgHeader;
    quint8      EVSEStatus_EVReady;     //1 이면 EV ready
    quint8      EVStatus_EVCabinConditioning;
    quint8      EVStatus_EVRESSConditioning;
    quint8      EVStatus_EVErrorCode;
    quint8      EVStatus_EVRESSSOC;
    quint8      Padding[3];
    PhysicalValue   EVTargetCurrent;
    PhysicalValue   EVMaximumVoltageLimit;
    PhysicalValue   EVMaximumCurrentLimit;
    PhysicalValue   EVMaximumPowerLimit;
    quint8          BulkChargingComplete;
    quint8          ChargingComplete;
    quint8          Padding2[2];
    PhysicalValue   RemainingTimeToFullSoC;
    PhysicalValue   RemainingTimeToBulkSoC;
    PhysicalValue   EVTargetVoltage;
    quint32     Checksum;
};

struct stCurrentDemandRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint8      EVSEStatus_EVSEIsolationStatus;
    quint8      EVSEStatus_EVSEStatusCode;
    quint8      EVSEStatus_EVSENotification;
    quint8      Padding2;
    quint32     EVSEStatus_NotificationMaxDelay;
    PhysicalValue   EVSEPresentVoltage;
    PhysicalValue   EVSEPresentCurrent;
    quint8          EVSECurrentLimitAchieved;
    quint8          EVSEVoltageAchieved;
    quint8          EVSEPowerLimitAchieved;
    quint8          Padding3;
    PhysicalValue   EVSEMaximumVoltageLimit;
    PhysicalValue   EVSEMaximumCurrentLimit;
    PhysicalValue   EVSEMaximumPowerLimit;
    quint32     Checksum;
    stCurrentDemandRes(quint8 nResCode = 0, quint8 uEvseStatus = 0)
    {
        MsgHeader.Msg_ID = CurrentDemandRes;
        MsgHeader.Msg_LEN = sizeof(stCurrentDemandRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEStatus_EVSEIsolationStatus = Valid;
        EVSEStatus_EVSEStatusCode = uEvseStatus;
        EVSEStatus_EVSENotification = None;
        EVSEStatus_NotificationMaxDelay = 0;
        //EVSEPresentVoltage = value;
        memset(Padding,0, sizeof(Padding));
        Padding2 = 0;
        Padding3 = 0;
    }
};
struct stWeldingDetectionReq
{
    Msg_Header  MsgHeader;
    quint8      EVSEStatus_EVReady;     //1 이면 EV ready
    quint8      EVStatus_EVCabinConditioning;
    quint8      EVStatus_EVRESSConditioning;
    quint8      EVStatus_EVErrorCode;
    quint8      EVStatus_EVRESSSOC;
    quint8      Padding[3];
    quint32     Checksum;
};

struct stWeldingDetectionRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint8      EVSEStatus_EVSEIsolationStatus;
    quint8      EVSEStatus_EVSEStatusCode;
    quint8      EVSEStatus_EVSENotification;
    quint8      Padding2;
    quint32     EVSEStatus_NotificationMaxDelay;
    PhysicalValue   EVSEPresentVoltage;
    quint32     Checksum;
    stWeldingDetectionRes(quint8 nResCode = 0, quint8 uEvseStatus = 0)
    {
        MsgHeader.Msg_ID = WeldingDetectionRes;
        MsgHeader.Msg_LEN = sizeof(stWeldingDetectionRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        EVSEStatus_EVSEIsolationStatus = Valid;
        EVSEStatus_EVSEStatusCode = uEvseStatus;
        EVSEStatus_EVSENotification = None;
        EVSEStatus_NotificationMaxDelay = 0;
        //EVSEPresentVoltage = value;
        memset(Padding,0, sizeof(Padding));
        Padding2 = 0;
    }
};
struct stSessionStopReq
{
    Msg_Header  MsgHeader;
    quint32     Checksum;
};

struct stSessionStopRes
{
    Msg_Header  MsgHeader;
    quint8      ResCode;
    quint8      Padding[3];
    quint32     Checksum;
    stSessionStopRes(quint8 nResCode = 0)
    {
        MsgHeader.Msg_ID = SessionStopRes;
        MsgHeader.Msg_LEN = sizeof(stSessionStopRes) - sizeof(Msg_Header) - sizeof(Checksum);
        ResCode = nResCode;
        memset(Padding,0, sizeof(Padding));
        Checksum = 0;
    }
};

struct stReportINITReq
{
    Msg_Header  MsgHeader;
    quint8 chSign[4] = {0x00,0x02,0x00, 0x02};
    quint32 Checksum;
    stReportINITReq()
    {
        MsgHeader.Msg_ID = ReportINITReq;
        MsgHeader.Msg_LEN = 4;
        //chSign[4] = {'I','N','I', 'T'};
        Checksum = 4;
    }
};

struct stReportINIT
{
    Msg_Header  MsgHeader;
    quint8      ErrorCode;
    quint8      Dummy[3];
    quint8      MajorVersion;
    quint8      MinorVersion;
    quint8      ReleaseVersion;
    quint8      InfoLen;
    quint8        INFO[24]; //"UM-REL-20150302-01"
    quint32     Checksum;
};

struct stStartRequest
{
    Msg_Header  MsgHeader;
    quint8      Info[4] = {0, 0, 0, 3};
    quint32     Checksum;
    stStartRequest()
    {
        MsgHeader.Msg_ID = 0xFC;
        MsgHeader.Msg_LEN = 4;
        memset(Info,0, sizeof(Info));
        Checksum = 0;
    }
};

struct stStartResponse
{
    Msg_Header  MsgHeader;
    quint8      Info[4];
    quint32     Checksum;
};

struct stReportSLAC
{
    Msg_Header  MsgHeader;
    quint8      ErrorCode;
    quint8      Padding[3];
    quint8      AverageAttenuation;  //AverageAttenuation 40 보다 크면 중지 노이즈 값
    quint8      Padding2;
    quint8      PEV_MAC[6];
    quint32     Checksum;
};

struct stReportSDP
{
    Msg_Header  MsgHeader;
    quint8      ErrorCode;
    quint8      Padding[3];
    quint16     Tcp_port;
    quint8      Sec;
    quint8      Tcp;
    quint32     Checksum;
};

struct stReportV2G
{
    Msg_Header  MsgHeader;
    quint8      ErrorCode;
    quint8      Dummy[3];
    quint32     Checksum;
};

struct stValidateReq
{
    Msg_Header  MsgHeader;      //ID : 0x75
    quint8      ErrorCode;
    quint8      Timer;           //0 – 100ms, 1- 200ms
    quint8      Padding[3];
    quint32     Checksum;
};

struct stValidateRes
{
    Msg_Header  MsgHeader;      //ID : 0x75
    quint8      ErrorCode;
    quint32     ToggleNum;
    quint32     Checksum;
    stValidateRes(quint32 toggleNum)
    {
        MsgHeader.Msg_ID = 0xF5;
        MsgHeader.Msg_LEN = 4;
        ToggleNum = toggleNum;
    }
};


struct stReportSTATEReq
{
    Msg_Header  MsgHeader;
    quint8      type; //1 = CP State, 2 = PD State,
    quint8      info[3];
    quint32     Checksum;
    stReportSTATEReq(quint8 nType)
    {
        MsgHeader.Msg_ID = ReportSTATEReq;
        MsgHeader.Msg_LEN = 4;
        type = nType;
        memset(info,0, sizeof(info));
        Checksum = 0;
    }
};

struct stReportSTATE
{
    Msg_Header  MsgHeader;
    quint8      type;       //type = 1
    quint8      info[3];    //info[0] = cp voltage
    quint32     Checksum;   //type = 2
                            //info[0] = PD type (1,2)
                            //PDtype = 1, Info[1] = (0=UNPLUG, 1=S3CLOSE, 2=S3OPEN)
                            //PDtype = 2, Info[1] = (0=UNPLUG, 1=PLUG)
};

struct stAllStopReq
{
    Msg_Header  MsgHeader;
    quint8      info[4] = {'S','T','O','P'};
    quint32     Checksum;
    stAllStopReq()
    {

        MsgHeader.Msg_ID = 0xFE;
        MsgHeader.Msg_LEN = 4;
        //memset(info,0, sizeof(info));
        Checksum = 0;
        //Checksum = std::accumulate(info, info+4, 0);
    }
};

struct stEVSE_RESET_Req
{
    Msg_Header  MsgHeader;
    quint8      info[4] = {'H','R','S','T'};
    quint32     Checksum;
    stEVSE_RESET_Req()
    {

        MsgHeader.Msg_ID = 0xFE;
        MsgHeader.Msg_LEN = 4;
        //memset(info,0, sizeof(info));
        Checksum = 0;
        //Checksum = std::accumulate(info, info+4, 0);
    }
};
struct stPLC_STATUS
{
    int EVCC_Req_state;
    bool CurrentDemand;
    quint8 Charging_status;
    unsigned int  EVCC_to_EVSE_Delay;

    stPLC_STATUS() {
        EVCC_Req_state =0;
        CurrentDemand = 0;
        EVCC_to_EVSE_Delay =0;
        Charging_status =0;
    }
};
#pragma pack(pop)
#endif
