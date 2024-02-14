#include "dccomboplc_2.h"
#include "dccomboplc.h"
#include <QDebug>
#include <QThread>
#include "ocpp.h"
#include "tty.h"
#include "dcmodule.h"
#define THRTEE 1
//#define SIXTEEN 1
Can_Module_Transmit   CAN_TX_2;
extern Can_Module_Transmit   CAN_TX;
Can_Module_Recieve CAN_RX_2;
extern struct Parameter set_parameter;
extern QQueue<int> can_module;
volatile int bIsolation_ok_2;
extern Charger_Status CCS2;
extern Charger_Status CCS;
extern int can_fd,can2_fd;
extern stChargerUI_Info ChargerUI_Info_2;
extern struct LoadSharing Sharing;
extern uint8_t plc_req_2;
extern QQueue<int> PLC_queue;
dccomboplc_2::dccomboplc_2(QObject *parent) : QObject(parent)
{
    evseStatusCode = EVSE_Ready;
    eNumEVSEProcess = Finished;
    eNumresponseCode = OK;
    ui_Min = ui_Sec = 0;
    initValues();
    plc_ElpaseTime = nullptr;

}
dccomboplc_2::~dccomboplc_2()
{

}
void dccomboplc_2::initValues()
{
    bEmergencyStop = false;
    bcurrentDemand = false;
    bPLG = false;
    EV_SOC = 0;
    Plc_Voltage = 12;
    evTargetCurrent = evTargetVoltage = 0;
    evseStatusCode = EVSE_Ready;
  //  memset(&ChargerUI_Info, 0, sizeof(stChargerUI_Info));
    curChagerStep = NONE_ID;
    plc_req_2 =0;
}
#ifdef THREAD_CHANGES
void dccomboplc_2::poll_read_ready(){
    int ret =  tty_read_ready(tty_fd);
    if (ret == 1) {
        emit readReady();
    }
}
#endif
int dccomboplc_2::OpenSerialPort(QString sPortName)
{
    int tty_fd;
    const char* dev_name = sPortName.toLocal8Bit().data();
    tty_fd = tty_init(dev_name);

    if (tty_fd == -1) {
        qDebug() << "Failed to init tty!\n\r";
        return -1;
    }

    int ret = tty_setting(tty_fd, 38400, 8, TTY_RS232_MODE, 0, 'n', 1);

    if (ret != 0) {
        qDebug() << "Failed set tty!\n\r";
        return -1;
    }

    return tty_fd;
}
void dccomboplc_2::DebugString(QString sMessage)
{

}
void dccomboplc_2::CloseSerialPort()
{

}
void dccomboplc_2::readPLC_COM(void)
{

}
void dccomboplc_2::recieveData(QByteArray aData,int fd)
{
    quint32 nTotalCur = 0;
    QByteArray DataBuffer;
   // qDebug() <<":recieveData Cmd " << QString::number(aData[2], 16).toUpper();

    switch(aData[2])
    {
        case ReportINITRes: {
            curChagerStep = ReportINITRes;
            qDebug() << "receive ReportINITRes";
            evseStatusCode = EVSE_Ready;
            stReportINIT* pReportINIT;// = NULL;
            pReportINIT = reinterpret_cast<stReportINIT*>(aData.data());
            QString strInfo(reinterpret_cast<const char*>(pReportINIT->INFO));
            ChargerUI_Info_2.ui_Plc_Error_Code = pReportINIT->ErrorCode;
#ifdef PLC_DEBUG
            qDebug() << strInfo;
#endif
            if(pReportINIT->ErrorCode == 0)
            {
                bcurrentDemand = false;
                stStartRequest* pStartReq = new stStartRequest();
                DataBuffer.append((char*)pStartReq, sizeof(stStartRequest));
                SAFE_DELETE(pStartReq)
            }else
            {
//#ifdef PLC_DEBUG
                qDebug() << "ReportINITRes ErrorCode : " << pReportINIT->ErrorCode;
//#endif
            }
            break;
        }
        case SessionSetupReq:{

            curChagerStep = SessionSetupReq;
            stSessionSetupReq* pSessionSetupReq;
            pSessionSetupReq = reinterpret_cast<stSessionSetupReq*>(aData.data());

            QString HexID;
            for(int i=0; i<8; i++)
            {
                HexID += QString::number(pSessionSetupReq->EVCCID[i], 16).toUpper() + " ";
            }

            qDebug() << "EVCCID = " << HexID;
            DebugString("Receive SessionSetupReq,  EVCCID - " + HexID);

            stSessionSetupRes* pSessionSetupRes = new stSessionSetupRes(1);
            DataBuffer.append((char*)pSessionSetupRes, sizeof(stSessionSetupRes));
            pSessionSetupRes->Checksum = getChecksum(DataBuffer);
            DataBuffer.clear();
            DataBuffer.append((char*)pSessionSetupRes, sizeof(stSessionSetupRes));
#ifdef PLC_DEBUG
            qDebug() << "send SessionSetupRes ";
#endif
            SAFE_DELETE(pSessionSetupRes)
            break;
        }
        case ServiceDiscoveryReq:{

                curChagerStep = ServiceDiscoveryReq;                
                stServiceDiscoveryReq* pServiceDiscoveryReq;// = NULL;
                pServiceDiscoveryReq = reinterpret_cast<stServiceDiscoveryReq*>(aData.data());
                if(pServiceDiscoveryReq->ServiceCategory == 0)
                {
#ifdef PLC_DEBUG
                    qDebug() << "receive ServiceDiscoveryReq - " << "ServiceCategory 0";
#endif
                    stServiceDiscoveryRes* pServiceDiscoveryRes = new stServiceDiscoveryRes(0);
                    DataBuffer.append((char*)pServiceDiscoveryRes, sizeof(stServiceDiscoveryRes));
                    pServiceDiscoveryRes->Checksum = getChecksum(DataBuffer);
                    DataBuffer.clear();
                    DataBuffer.append((char*)pServiceDiscoveryRes, sizeof(stServiceDiscoveryRes));
#ifdef PLC_DEBUG
                    qDebug() << "send ServiceDiscoveryRes ";
#endif
                    SAFE_DELETE(pServiceDiscoveryRes)
                }             
                break;
           }
        case ServicePaymentSelectionReq:{

                curChagerStep =  ServicePaymentSelectionReq;

                stServicePaymentSelectionReq* pServicePaymentSelectionReq;
                pServicePaymentSelectionReq = reinterpret_cast<stServicePaymentSelectionReq*>(aData.data());
                if(pServicePaymentSelectionReq->SelectedPaymentOption == 1 &&
                   pServicePaymentSelectionReq->NumOfServices == 1 &&
                   pServicePaymentSelectionReq->ServiceID[0] == 1)
                {
#ifdef PLC_DEBUG
                    qDebug() << "receive ServicePaymentSelectionReq ";
#endif
                    stServicePaymentSelectionRes* pServicePaymentSelectionRes = new stServicePaymentSelectionRes(0);
                    DataBuffer.append((char*)pServicePaymentSelectionRes, sizeof(stServicePaymentSelectionRes));
#ifdef PLC_DEBUG
                    qDebug() << "send ServicePaymentSelectionRes ";
#endif
                    SAFE_DELETE(pServicePaymentSelectionRes)
                }             
                break;
            }
        case ContractAuthenticationReq:{
                     curChagerStep =  ContractAuthenticationReq;
#ifdef PLC_DEBUG
                qDebug() << "receive ContractAuthenticationReq  ";
#endif
                eNumEVSEProcess = Finished;
                stContractAuthenticationRes* pContractAuthenticationRes = new stContractAuthenticationRes(eNumresponseCode, eNumEVSEProcess);
                DataBuffer.append((char*)pContractAuthenticationRes, sizeof(stContractAuthenticationRes));
#ifdef PLC_DEBUG
                qDebug() << "send ContractAuthenticationRes ";
#endif
                SAFE_DELETE(pContractAuthenticationRes)              
                break;
            }
        case ChargeParameterDiscoveryReq:{
                curChagerStep =  ChargeParameterDiscoveryReq;

#ifdef PLC_DEBUG
                qDebug() << "receive ChargeParameterDiscoveryReq  ";
#endif
                stChargeParameterDiscoveryReq* pChargeParameterDiscoveryReq;
                pChargeParameterDiscoveryReq = reinterpret_cast<stChargeParameterDiscoveryReq*>(aData.data());
                ChargerUI_Info_2.ui_Plc_Error_Code =  pChargeParameterDiscoveryReq->EVStatus_EVErrorCode;

                //SetEvFaultStatus(pChargeParameterDiscoveryReq->EVStatus_EVErrorCode);
                //EV_SOC = pChargeParameterDiscoveryReq->FullSOC;
                //qDebug() << "FullSOC = " << pChargeParameterDiscoveryReq->FullSOC;
                //qDebug() << "BulkSOC = " << pChargeParameterDiscoveryReq->BulkSOC;
                //ChargerUI_Info.ui_Plc1_Error_Code = pChargeParameterDiscoveryReq->EVStatus_EVErrorCode
                //SetPLC_ErrorCode(nPLC, pChargeParameterDiscoveryReq->EVStatus_EVErrorCode);

                UnitValue* uvMaxCurrentLimit = new UnitValue(&pChargeParameterDiscoveryReq->EVMaximumCurrentLimit);
                UnitValue* uvPowerLimit = new UnitValue(&pChargeParameterDiscoveryReq->EVMaximumPowerLimit);
                UnitValue* uvMaxEVMaxVoltageLimit = new UnitValue(&pChargeParameterDiscoveryReq->EVMaximumVoltageLimit);
                UnitValue* uvMaxEnergyCapacity = new UnitValue(&pChargeParameterDiscoveryReq->EVEnergyCapacity);
                UnitValue* uvMaxEnergyRequest = new UnitValue(&pChargeParameterDiscoveryReq->EVEnergyRequest);

                evDiscVoltageMax =  (float)uvMaxEVMaxVoltageLimit->fValue;
                evDiscCurrentMax =  (float)uvMaxCurrentLimit->fValue;

                qDebug() << "EVMaximumCurrentLimit = " << uvMaxCurrentLimit->sValue;
                qDebug() << "EVMaximumPowerLimit = " << uvPowerLimit->sValue;
                qDebug() << "EVMaximumVoltageLimit = " << uvMaxEVMaxVoltageLimit->sValue;
                qDebug() << "EVEnergyCapacity = " << uvMaxEnergyCapacity->sValue;
                qDebug() << "EVEnergyRequest = " << uvMaxEnergyRequest->sValue;

//                MaxEVSECurrentLimit = pChargeParameterDiscoveryReq->EVMaximumCurrentLimit;
//                MaxEVSEVoltageLimit = pChargeParameterDiscoveryReq->EVMaximumVoltageLimit;
//                MaxEVSEPowerLimit = pChargeParameterDiscoveryReq->EVMaximumPowerLimit;
                if(Sharing.Is_LoadSharing == true)
                {
                    if(evDiscCurrentMax > (float)set_parameter.DC_IMAX)
                    {
                        if(Sharing.Is_LoadSharing == true)
                        {
                            if(evDiscCurrentMax > (float)set_parameter.DC_IMAX)
                            {
                                Sharing.G2_Need_Tb_LS = LS_Yes;
                                Sharing.G1_Need_Tb_LS = LS_No;
                            //    can_module.enqueue(Pm_On_2);
                            }
                        }
                    }
                }
                memset(&EVSECurrent,0, sizeof(PhysicalValue));
                memset(&EVSEVoltage,0, sizeof(PhysicalValue));

                SetPhysicalValue(&MinEVSECurrentLimit, -1, 3, set_parameter.DC_IMin*10); //SET 1
                 qDebug()<<"DC Max Currrent" << set_parameter.DC_IMAX <<"DC_Min Current :" <<set_parameter.DC_IMin <<"DC Max Voltage : "<< set_parameter.DC_VMAX<< "DC V Min"<<set_parameter.DC_VMin<<"Power Min"<< set_parameter.DC_PMin<<"Power Pmax"<<set_parameter.DC_PMAX<<endl;
                SetPhysicalValue(&MinEVSEVoltageLimit, -1, 5, set_parameter.DC_VMin*10);
                SetPhysicalValue(&MaxEVSEVoltageLimit, -1, 5, set_parameter.DC_VMAX*10);
                SetPhysicalValue(&MaxEVSECurrentLimit, -1, 3, set_parameter.DC_IMAX*10);
                SetPhysicalValue(&MaxEVSEPowerLimit, 3, 7, set_parameter.DC_PMAX);

                stChargeParameterDiscoveryRes* pChargeParameterDiscoveryRes = new stChargeParameterDiscoveryRes(0, (quint8)evseStatusCode);
                pChargeParameterDiscoveryRes->EVSEMaximumCurrentLimit = MaxEVSECurrentLimit;
                pChargeParameterDiscoveryRes->EVSEMaximumVoltageLimit = MaxEVSEVoltageLimit;
                pChargeParameterDiscoveryRes->EVSEMaximumPowerLimit =   MaxEVSEPowerLimit;
                pChargeParameterDiscoveryRes->EVSEMinimumCurrentLimit = MinEVSECurrentLimit;
                pChargeParameterDiscoveryRes->EVSEMinimumVoltageLimit = MinEVSEVoltageLimit;

                PhysicalValue EVSECurrentRegulationTolerance;
                PhysicalValue EVSEPeakCurrentRipple;
                PhysicalValue EVSEEnergyToBeDelivered;

               SetPhysicalValue(&EVSECurrentRegulationTolerance, -1, 3, 200); //CHANGE FROM 10
                SetPhysicalValue(&EVSEPeakCurrentRipple, -1, 3, 320);          //CHANGE FROM 10
                SetPhysicalValue(&EVSEEnergyToBeDelivered, 3, 9, 35);

                pChargeParameterDiscoveryRes->EVSECurrentRegulationTolerance = EVSECurrentRegulationTolerance;
                pChargeParameterDiscoveryRes->EVSEPeakCurrentRipple = EVSEPeakCurrentRipple;
                pChargeParameterDiscoveryRes->EVSEEnergyToBeDelivered = EVSEEnergyToBeDelivered;
                pChargeParameterDiscoveryRes->SAScheduleTuple0_PMaxSchedule0_Pmax = 30000;

                DataBuffer.append((char*)pChargeParameterDiscoveryRes, sizeof(stChargeParameterDiscoveryRes));
                pChargeParameterDiscoveryRes->Checksum = getChecksum(DataBuffer);
                DataBuffer.clear();
                DataBuffer.append((char*)pChargeParameterDiscoveryRes, sizeof(stChargeParameterDiscoveryRes));
#ifdef PLC_DEBUG
                qDebug() << "send ChargeParameterDiscoveryRes ";
#endif
                SAFE_DELETE(uvMaxCurrentLimit)
                SAFE_DELETE(uvPowerLimit)
                SAFE_DELETE(uvMaxEVMaxVoltageLimit)
                SAFE_DELETE(uvMaxEnergyCapacity)
                SAFE_DELETE(uvMaxEnergyRequest)
                SAFE_DELETE(pChargeParameterDiscoveryRes)              
                break;
            }
        case PowerDeliveryReq:{
                curChagerStep =  PowerDeliveryReq;
                qDebug() << "receive PowerDeliveryReq  ";
                stPowerDeliveryReq* pPowerDeliveryReq;
                pPowerDeliveryReq = reinterpret_cast<stPowerDeliveryReq*>(aData.data());

                ChargerUI_Info_2.ui_Soc =  EV_SOC = pPowerDeliveryReq->EVStatus_EVRESSSOC;
                ChargerUI_Info_2.ui_Plc_Error_Code =  pPowerDeliveryReq->EVStatus_EVErrorCode;
                if(ChargerUI_Info_2.ui_Plc_Error_Code > 0)
                {
                    can_module.enqueue(Pm_Off_2);
                    CAN_TX_2.Dc_main =0;                   
                    bcurrentDemand = false;
                }
                    if(pPowerDeliveryReq->ReadyToChargeState == 0 )
                    {                        
                        can_module.enqueue(Pm_Off_2);
                        CAN_TX_2.Dc_main =0;
                        bcurrentDemand = false;
                        ChargerUI_Info_2.ui_Plc_Error_Code = EVNotReadyToCharge;
                    }
                    stPowerDeliveryRes* pPowerDeliveryRes = new stPowerDeliveryRes(0, evseStatusCode);//evseStatusCode
                    DataBuffer.append((char*)pPowerDeliveryRes, sizeof(stPowerDeliveryRes));
                    pPowerDeliveryRes->Checksum = getChecksum(DataBuffer);
                    DataBuffer.clear();
                    DataBuffer.append((char*)pPowerDeliveryRes, sizeof(stPowerDeliveryRes));
                    //qDebug() << "send evseStatusCode  " << evseStatusCode;
                    //qDebug() << "send PowerDeliveryRes ";
                    SAFE_DELETE(pPowerDeliveryRes)                
                break;
            }
        case CableCheckReq:{
                if(curChagerStep != CableCheckReq)
                {
                    curChagerStep  =  CableCheckReq;                                       
                    CAN_TX_2.Pm1_voltage = evDiscVoltageMax;
                    CAN_TX_2.Pm1_current = 0;
                    CAN_TX_2.Dc_main = 0xA5;
                    bIsolation_ok_2 = 0;                    
                    IsolationStatus = Valid;
                    evseStatusCode =  EVSE_IsolationMonitoringActive;
#ifdef PLC_DEBUG
                    qDebug() << "receive CableCheckReq  ";
#endif
                }
                stCableCheckReq* pCableCheckReq;
                pCableCheckReq = reinterpret_cast<stCableCheckReq*>(aData.data());
                ChargerUI_Info_2.ui_Plc_Error_Code =  pCableCheckReq->EVStatus_EVErrorCode;
                if(pCableCheckReq->EVStatus_EVErrorCode == 0)
                {
                   if(CCS2.DC_Voltage_1 >= (evDiscVoltageMax - 10))
                    {
                        if(CAN_RX_2.Electricl_Isolation > 100)
                        {
                             bIsolation_ok_2 = 1;
                        }
                        else
                        {
                            ChargerUI_Info_2.ui_Plc_Error_Code  = Isolation_Fault;
                            bIsolation_ok_2 = 2;
                            evseStatusCode = EVSE_NotReady;
                            IsolationStatus = Fault;

                        }                        
                       if(bIsolation_ok_2 == 1)
                        {
                              CAN_TX_2.Pm1_voltage = 100;
                              CAN_TX_2.Pm1_current = 0;

                                if(bIsolation_ok_2 == 1)
                                {
                                    if(evseStatusCode == EVSE_IsolationMonitoringActive)
                                    {
                                        evseStatusCode = EVSE_Ready;
                                        bCabelCheck_Processing = Finished;
                                    }
                                }
                        }
                        else
                        {
                            evseStatusCode =  EVSE_IsolationMonitoringActive;
                            bCabelCheck_Processing = Ongoing;
                        }
                   }
                }

                    stCableCheckRes* pCableCheckRes = new stCableCheckRes(0, evseStatusCode);
                    pCableCheckRes->EVSEStatus_EVSEIsolationStatus = 1;
                    pCableCheckRes->EVSEProcessing = (quint8)bCabelCheck_Processing;

                    DataBuffer.append((char*)pCableCheckRes, sizeof(stCableCheckRes));
                    pCableCheckRes->Checksum = getChecksum(DataBuffer);

                    DataBuffer.clear();
                    DataBuffer.append((char*)pCableCheckRes, sizeof(stCableCheckRes));

                    //qDebug() << "send evseStatusCode  " << evseStatusCode;
                    //qDebug() << "send EVSEStatus_EVSEIsolationStatus  " << pCableCheckRes->EVSEStatus_EVSEIsolationStatus;
                    //qDebug() << "send CableCheckRes ";
                    SAFE_DELETE(pCableCheckRes)                              
                break;
            }
        case PreChargeReq:{

                if(curChagerStep != PreChargeReq)
                {
                    curChagerStep  =  PreChargeReq;
                    CAN_TX_2.Pm1_current = 0;                      
                    CAN_TX_2.Pm1_voltage = 200;
                    CAN_TX_2.Dc_main = 0xA5;
                    can_module.enqueue(Pm_Power1_2);                                                     
                     bcurrentDemand = true;                                       
                }

                stPreChargeReq* pPreChargeReq;
                pPreChargeReq = reinterpret_cast<stPreChargeReq*>(aData.data());
                UnitValue* unitTargetVoltage = new UnitValue(&pPreChargeReq->EVTargetVoltage);
                UnitValue* unitTargetCurrent = new UnitValue(&pPreChargeReq->EVTargetCurrent);
                evTargetVoltage = unitTargetVoltage->fValue;
//                /****************** Display voltage value ********************/
                qDebug() << "preCharge Target Cur " <<nTotalCur << "A";
                qDebug() << "preCharge Target Volt " <<evTargetVoltage << "V";
#ifdef PLC_DEBUG
                qDebug() << "preCharge Target Cur " <<nTotalCur << "A";
                qDebug() << "preCharge Target Volt " <<evTargetVoltage << "V";
#endif
                stPreChargeRes* pPreChargeRes = new stPreChargeRes(0, evseStatusCode);
                ChargerUI_Info_2.ui_StartSoc = pPreChargeReq->EVStatus_EVRESSSOC;      
                ChargerUI_Info_2.ui_Plc_Error_Code = pPreChargeReq->EVStatus_EVErrorCode;

                if(ChargerUI_Info_2.ui_Plc_Error_Code > 0)
                {
                    can_module.enqueue(Pm_Off_2);
                    CAN_TX_2.Dc_main    =0;
                }
                evseVoltage = CCS2.DC_Voltage_1;              
                if(evseVoltage > evTargetVoltage)
                {
                     SetPhysicalValue(&EVSEVoltage, -1, 5, evTargetVoltage*10);
                }
                else
                {
                      SetPhysicalValue(&EVSEVoltage, -1, 5, evseVoltage*10);
                }

                pPreChargeRes->EVSEPresentVoltage = EVSEVoltage;
                pPreChargeRes->EVSEStatus_EVSEIsolationStatus = Valid;
                DataBuffer.append((char*)pPreChargeRes, sizeof(stPreChargeRes));
                pPreChargeRes->Checksum = getChecksum(DataBuffer);
                DataBuffer.clear();

                CAN_TX_2.Pm1_voltage = evTargetVoltage > evDiscVoltageMax ? evDiscVoltageMax : evTargetVoltage;
                can_module.enqueue(Pm_Power1_2);
                CAN_TX_2.Pm1_current = 1;
                bIsolation_ok_2 = 0;
                     
                DataBuffer.append((char*)pPreChargeRes, sizeof(stPreChargeRes));
                SAFE_DELETE(pPreChargeRes)
                SAFE_DELETE(unitTargetVoltage)
                SAFE_DELETE(unitTargetCurrent)
                break;
            }
        case CurrentDemandReq :{

            if(curChagerStep != CurrentDemandReq)
            {
               curChagerStep = CurrentDemandReq;
               can_module.enqueue(Q_Charging_2);
            }
            if(Sharing.Is_LoadSharing == true)
            {
                 if((Sharing.G2_Need_Tb_LS == LS_Yes) && (Sharing.G1_Is_Available_LS == LS_Available))
                {
                    can_module.enqueue(Pm_On);
                    Sharing.G1_Is_Available_LS = LS_Occupie;
                }
                else if((Sharing.G1_Is_Available_LS == LS_Occupie) && (Sharing.G2_Need_Tb_LS == LS_Yes))
                {
                    CAN_TX.Pm1_voltage = CAN_TX_2.Pm1_voltage;
                    if((CCS.DcOutputModule_1) >= (CAN_TX_2.Pm1_voltage - 10))
                    {
                        Sharing.G2_Need_Tb_LS = LS_Active;
                        CAN_TX_2.Load_Sharing = 0xA5;
                    }
                }
            }
#ifdef PLC_DEBUG
                qDebug() << "receive CurrentDemandReq  ";
#endif
                curChagerStep = CurrentDemandReq;
                bcurrentDemand = true;
                stCurrentDemandReq* pCurrentDemandReq;
                pCurrentDemandReq = reinterpret_cast<stCurrentDemandReq*>(aData.data());
                ChargerUI_Info_2.ui_Soc = EV_SOC = pCurrentDemandReq->EVStatus_EVRESSSOC;
                ChargerUI_Info_2.ui_Plc_Error_Code = pCurrentDemandReq->EVStatus_EVErrorCode;

                if(EV_SOC == 100 || pCurrentDemandReq->ChargingComplete == StopCharging)
                {
                    if(EV_SOC == 100)
                    {
                       ChargerUI_Info_2.ui_Plc_Error_Code = S_FullCharge;
                       CCS2.Reson = Other;
                    }

                    if(Sharing.G2_Need_Tb_LS == LS_Active && Sharing.Is_LoadSharing == true)
                    {
                        can_module.enqueue(Pm_Off);
                    }
                    can_module.enqueue(Pm_Off_2);
                    evseStatusCode = EVSE_Shutdown;
                }

#ifdef PLC_DEBUG
                qDebug()<<"the value of uisoc currentdemand :"<<ChargerUI_Info.ui_Soc ;
#endif
#ifdef PLC_DEBUG
                qDebug()<<"the value of error code :"<<ChargerUI_Info.ui_Plc_Error_Code ;
                qDebug() << "EVSEStatus_EVRESSSOC = " << EV_SOC;
#endif
                UnitValue* uvEVTargetCurrent = new UnitValue(&pCurrentDemandReq->EVTargetCurrent);
                UnitValue* uvEVTargetVoltage = new UnitValue(&pCurrentDemandReq->EVTargetVoltage);
                UnitValue* uvEVMaximumCurrentLimit = new UnitValue(&pCurrentDemandReq->EVMaximumCurrentLimit);
                UnitValue* uvEVMaximumVoltageLimit = new UnitValue(&pCurrentDemandReq->EVMaximumVoltageLimit);
                UnitValue* uvEVMaximumPowerLimit = new UnitValue(&pCurrentDemandReq->EVMaximumPowerLimit);
                UnitValue* uvRemainingTimeToFullSoC = new UnitValue(&pCurrentDemandReq->RemainingTimeToFullSoC);

                ChargerUI_Info_2.ui_Min = ui_Min = (quint8)((uint)uvRemainingTimeToFullSoC->fValue / 60);
                ChargerUI_Info_2.ui_Sec = ui_Sec = (quint8)((uint)uvRemainingTimeToFullSoC->fValue % 60);
                evVoltageMax = uvEVMaximumVoltageLimit->fValue;
#ifdef PLC_DEBUG
                qDebug() << "EVTargetCurrent = " << uvEVTargetCurrent->sValue;
                qDebug() << "uvEVTargetVoltage = " << uvEVTargetVoltage->sValue;
                qDebug() << "uvMaxEVTargetPower = " << uvEVMaximumPowerLimit->sValue;
#endif

#ifdef PLC_DEBUG
                qDebug() << "uvEVMaximumCurrentLimit = " << uvEVMaximumCurrentLimit->sValue;
                qDebug() << "uvEVMaximumVoltageLimit = " << uvEVMaximumVoltageLimit->sValue;
                qDebug() << "uvEVMaximumPowerLimit = " << uvEVMaximumPowerLimit->sValue;
#endif
                evTargetVoltage = uvEVTargetVoltage->fValue;
                evMaxPowerLimit = uvEVMaximumPowerLimit->fValue;
                g_SetCurrent1 =   uvEVTargetCurrent->fValue;

                stCurrentDemandRes* pCurrentDemandRes = new stCurrentDemandRes(0, evseStatusCode);
                pCurrentDemandRes->EVSECurrentLimitAchieved = 0;
                pCurrentDemandRes->EVSEVoltageAchieved = 0;
                pCurrentDemandRes->EVSEPowerLimitAchieved = 0;

                pCurrentDemandRes->EVSEMaximumCurrentLimit = MaxEVSECurrentLimit;  //pCurrentDemandReq->EVMaximumCurrentLimit;
                pCurrentDemandRes->EVSEMaximumPowerLimit = MaxEVSEPowerLimit;      //pCurrentDemandReq->EVMaximumPowerLimit;
                pCurrentDemandRes->EVSEMaximumVoltageLimit = MaxEVSEVoltageLimit;  //pCurrentDemandReq->EVMaximumVoltageLimit;

                ChargerUI_Info_2.ui_Voltage = uvEVTargetVoltage->fValue;
                ChargerUI_Info_2.ui_Current = uvEVTargetCurrent->fValue;
                ChargerUI_Info_2.ui_Power = evMaxPowerLimit;
#ifdef PLC_DEBUG
                qDebug() << "ui voltage = " <<ChargerUI_Info.ui_Voltage ;
                qDebug() << "ui current = " <<ChargerUI_Info.ui_Current ;
                qDebug()<<"ui power = "<<ChargerUI_Info.ui_Power;
#endif
                evseVoltage = CCS2.DC_Voltage_1;
                evseCurrent = CCS2.DC_Current_1;               
#ifdef PLC_DEBUG
                qDebug() << "EVSE Current " <<evseCurrent<<endl;
#endif

                if(evseCurrent > g_SetCurrent1) //Changed CCS230
                {
                     SetPhysicalValue(&EVSECurrent, -1, 3, g_SetCurrent1*10);
                }
                else
                {
                    SetPhysicalValue(&EVSECurrent, -1, 3, evseCurrent*10); //Changed CCS230
                }

                if(evseVoltage > evVoltageMax)
                {
                     SetPhysicalValue(&EVSEVoltage, -1, 5, evVoltageMax*10);
                }
                else
                {
                     SetPhysicalValue(&EVSEVoltage, -1, 5, evseVoltage*10);
                }

                pCurrentDemandRes->EVSEPresentCurrent = EVSECurrent;
                pCurrentDemandRes->EVSEPresentVoltage = EVSEVoltage;
                DataBuffer.append((char*)pCurrentDemandRes, sizeof(stCurrentDemandRes));
                pCurrentDemandRes->Checksum = getChecksum(DataBuffer);
                {
                   if(CAN_RX_2.Electricl_Isolation > 100)
                    {                       
                       //evTargetVoltage should be greater than DC_min and should be less than DC_max
                        if(evTargetVoltage < (float)set_parameter.DC_VMin || evTargetVoltage > (float)set_parameter.DC_VMAX)
                        {
                            ChargerUI_Info_2.ui_Charger_ErrorCode = Voltage_MissMatch;
                        }
                        if(Sharing.G2_Is_Available_LS == LS_Active && Sharing.Is_LoadSharing == true)
                        {
                            if(set_parameter.PMIndividual_ED == true)
                            {
                                CAN_TX_2.Pm1_current = CAN_TX.Pm1_current = g_SetCurrent1/2;
                            }
                            else
                            {
                                CAN_TX_2.Pm1_current = CAN_TX.Pm1_current = g_SetCurrent1/4;
                            }
                        }
                        else
                        {
                            if(set_parameter.PMIndividual_ED == true)
                            {
                                CAN_TX_2.Pm1_current = g_SetCurrent1;
                            }
                            else
                            {
                                CAN_TX_2.Pm1_current = g_SetCurrent1/2;
                            }
                        }
                      CAN_TX_2.Dc_main = 0xA5;
                   }
                   else
                   {
                        CAN_TX_2.Dc_main = 0;
                        can_module.enqueue(Pm_Off_2);
                        if(Sharing.G1_Is_Available_LS == LS_Active && Sharing.Is_LoadSharing == true)
                        {
                            can_module.enqueue(Pm_Off);
                        }
#ifdef PLC_DEBUG
                       qDebug() << "Isolation Fault " <<CAN_RX.Electricl_Isolation<<endl;
#endif
                       pCurrentDemandRes->EVSEStatus_EVSEIsolationStatus = Fault;
                       evseStatusCode = pCurrentDemandRes->EVSEStatus_EVSEStatusCode = EVSE_NotReady;
                       ChargerUI_Info_2.ui_Charger_ErrorCode = Isolation_Fault;
                   }
                }

                if(ChargerUI_Info_2.ui_Plc_Error_Code  > 0 || ChargerUI_Info_2.ui_Charger_ErrorCode > 0)
                {
                    evseStatusCode = EVSE_Shutdown;
                    can_module.enqueue(Pm_Off_2);
                    if(Sharing.G2_Is_Available_LS == LS_Active && Sharing.Is_LoadSharing == true)
                    {
                        can_module.enqueue(Pm_Off);
                    }
                }
                DataBuffer.clear();
                DataBuffer.append((char*)pCurrentDemandRes, sizeof(stCurrentDemandRes));
                SAFE_DELETE(uvEVTargetCurrent)
                SAFE_DELETE(uvEVTargetVoltage)
                SAFE_DELETE(uvEVMaximumCurrentLimit)
                SAFE_DELETE(uvEVMaximumVoltageLimit)
                SAFE_DELETE(uvEVMaximumPowerLimit)
                SAFE_DELETE(uvRemainingTimeToFullSoC)
                SAFE_DELETE(pCurrentDemandRes)
                break;
            }
        case WeldingDetectionReq:{
              curChagerStep   =  WeldingDetectionReq;
                bcurrentDemand = false;
                qDebug() << "receive WeldingDetectionReq  ";
                stWeldingDetectionReq* pWeldingDetectionReq;
                pWeldingDetectionReq = reinterpret_cast<stWeldingDetectionReq*>(aData.data());

                qDebug() << "EVSEStatus_EVReady " << pWeldingDetectionReq->EVSEStatus_EVReady;
                qDebug() << "EVStatus_EVErrorCode " << pWeldingDetectionReq->EVStatus_EVErrorCode;
                qDebug() << "EVRESSSOC " << pWeldingDetectionReq->EVStatus_EVRESSSOC;

                ChargerUI_Info_2.ui_Plc_Error_Code = pWeldingDetectionReq->EVStatus_EVErrorCode;
                if(pWeldingDetectionReq->EVSEStatus_EVReady == EVSE_NotReady)
                {
                    ChargerUI_Info_2.ui_Plc_Error_Code  = 4;
                    evseStatusCode = EVSE_NotReady;
                }
                stWeldingDetectionRes* pWeldingDetectionRes = new stWeldingDetectionRes(0, evseStatusCode);
                PhysicalValue EVSEVoltage_Welding;
                SetPhysicalValue(&EVSEVoltage_Welding, -1, 5, CCS2.DC_Voltage_1*5);
                pWeldingDetectionRes->EVSEPresentVoltage = EVSEVoltage_Welding;

                DataBuffer.append((char*)pWeldingDetectionRes, sizeof(stWeldingDetectionRes));
                pWeldingDetectionRes->Checksum = getChecksum(DataBuffer);
                DataBuffer.clear();
                DataBuffer.append((char*)pWeldingDetectionRes, sizeof(stWeldingDetectionRes));
                //qDebug() << "send stWeldingDetectionRes";
                CAN_TX_2.Pm1_voltage = 0;
                CAN_TX_2.Pm1_current = 0;
               // can_module.enqueue(Pm_Off_2);
                Off_Module(can2_fd);
                CAN_TX_2.Dc_main = 0;
                if(Sharing.G2_Is_Available_LS == LS_Active && Sharing.Is_LoadSharing == true)
                {
                    CAN_TX.Pm1_voltage  = 0;
                    CAN_TX.Pm1_current  = 0;
                    CAN_TX_2.Load_Sharing = 0;
                //    can_module.enqueue(Pm_Off);
                    Off_Module(can_fd);
                }
                SAFE_DELETE(pWeldingDetectionRes)
                break;
            }
        case SessionStopReq:{
               curChagerStep   =  SessionStopReq;
               qDebug() << "receive SessionStopReq  ";
               stSessionStopRes* pSessionStopRes = new stSessionStopRes(0);
               DataBuffer.append((char*)pSessionStopRes,sizeof(stSessionStopRes));
               SAFE_DELETE(pSessionStopRes)
              bcurrentDemand = false;
              CAN_TX_2.Pm1_voltage =0;
              CAN_TX_2.Pm1_current =0;
              can_module.enqueue(Pm_Off_2);
              if(Sharing.G2_Is_Available_LS == LS_Active && Sharing.Is_LoadSharing == true)
              {
                  CAN_TX.Pm1_voltage  =0;
                  CAN_TX.Pm1_current  =0;
                  can_module.enqueue(Pm_Off);
              }
                curChagerStep   = NONE_ID;
                break;
            }
        case ReportSLAC:{

            stReportSLAC* pReportSLAC;
            pReportSLAC = reinterpret_cast<stReportSLAC*>(aData.data());
            QString sDebug = "[SLAC]AverageAttenuation - " + QString::number(pReportSLAC->AverageAttenuation);
            ChargerUI_Info_2.ui_Plc_Error_Code = pReportSLAC->ErrorCode;
#ifdef PLC_ERROR
            if(ChargerUI_Info.ui_Plc_Error_Code > 0)
            {
                PLC_queue.enqueue(Report_state);
            }
#endif
            QString HexID;
            for(int i=0; i<6; i++)
            {
                HexID += QString::number(pReportSLAC->PEV_MAC[i], 16).toUpper() + " ";
            }
            HexID = "PEV_MAC: "  + HexID;
            qDebug()<< "Report Slac : "<<HexID<<endl;

            break;
            }
        case ReportSDP:{
            DebugString("receive ReportSDP");
            stReportSDP* pReportSDP;
            pReportSDP = reinterpret_cast<stReportSDP*>(aData.data());
            QString sDebug = "[SDP]Tcp_port : - " + QString::number(pReportSDP->Tcp_port) +
                             ", Sec : " + QString::number(pReportSDP->Tcp_port) +
                             ", Tcp : " + QString::number(pReportSDP->Tcp);
               ChargerUI_Info_2.ui_Plc_Error_Code = pReportSDP->ErrorCode;


            break;
        }
        case ReportV2G:{
                qDebug() << "receive ReportV2G  ";
                stReportV2G* pReportV2G;
                pReportV2G = reinterpret_cast<stReportV2G*>(aData.data());
                qDebug() << "ReportV2G Error_Code " << pReportV2G->ErrorCode;
               ChargerUI_Info_2.ui_Plc_Error_Code =  pReportV2G->ErrorCode;
                if(pReportV2G->ErrorCode > 0)
                {
                    ChargerUI_Info_2.ui_Plc_Error_Code = pReportV2G->ErrorCode;
                    if(curChagerStep == PreChargeReq ||curChagerStep  == CurrentDemandReq )
                    {
                      CAN_TX_2.Dc_main =  0;
                      CAN_TX_2.Pm1_voltage =0;
                      CAN_TX_2.Pm1_current =0;
                      can_module.enqueue(Pm_Off_2);

                      if(Sharing.G2_Is_Available_LS == LS_Active && Sharing.Is_LoadSharing == true)
                      {
                          CAN_TX.Pm1_voltage = 0;
                          CAN_TX.Pm1_current = 0;
                          CAN_TX_2.Load_Sharing = 0;
                          can_module.enqueue(Pm_Off);
                      }
                    }
                }
                break;
            }
        case ReportSTATE :{
            qDebug() << "receive ReportSTATE";
            curChagerStep  = NONE_ID;
            plc_req_2 = 0;
            stReportSTATE* pReportSTATE;
            pReportSTATE = reinterpret_cast<stReportSTATE*>(aData.data());                          
            if(pReportSTATE->type == 1)
            {
                if((pReportSTATE->info[0] == 9) && (Plc_Voltage == 6))
                {
                    CAN_TX_2.Dc_main      =0;
                    CAN_TX_2.Pm1_voltage  =0;
                    CAN_TX_2.Pm1_current  =0;

                    g_SetCurrent1 = 0;
                    bcurrentDemand = false;
                    evseStatusCode = EVSE_Shutdown;
                    if(CCS2.start == Charging_Start)
                    {
                        CCS2.Status = SuspendedEVSE;
                        CCS2.Reson = HardReset;
                        evseStatusCode = EVSE_Shutdown;
                        ChargerUI_Info_2.ui_Charger_ErrorCode = STAGE_B_DETECTED_2;
                    }
                    qDebug() << "EV SWITCH 6 TO 9 v detected" << evseStatusCode<< endl;
                }
                /*else if( (pReportSTATE->info[0] == 12) && (Plc_Voltage == 6))
                {
                    CAN_TX_2.Dc_main     =0;
                    CAN_TX_2.Pm1_voltage =0;
                    CAN_TX_2.Pm1_current =0;

                    if(CCS2.start == Charging_Start)
                    {
                        ChargerUI_Info_2.ui_Charger_ErrorCode = STAGE_B_DETECTED_2;
                        can_module.enqueue(Io_Card_2);
                        can_module.enqueue(Pm_Off_2);
                        CCS2.Status = SuspendedEV;
                    }
                    g_SetCurrent1 =  0;
                    bcurrentDemand = false;                  
                    evseStatusCode = EVSE_Shutdown;

                    qDebug() << "EV SWITCH 6 TO 12 v detected" << evseStatusCode<< endl;
                }*/
                else if( (pReportSTATE->info[0] == 9) && (Plc_Voltage == 12 /*0| CCS2.Status == Available*/)) //OK
                {
                     can_module.enqueue(Q_Connect_2);
                 //   if(CCS2.Status == Available)
                    {
                        PLC_queue.enqueue(Report_state_2);
                    }
                     CAN_TX_2.Dc_main     = 0;
                     CAN_TX_2.Pm1_voltage = 0;
                     CAN_TX_2.Pm1_current = 0;
                     if(CCS2.start == Charging_Start)                         
                     {
                         ChargerUI_Info_2.ui_Charger_ErrorCode = STAGE_B_DETECTED_2;
                     }
                   qDebug() << "EV SWITCH "<<Plc_Voltage <<" TO 9 v detected_2" << evseStatusCode<< endl;
                }
                else if((Plc_Voltage == 9 ) &&  pReportSTATE->info[0] == 12)
                {
                    CAN_TX_2.Dc_main = 0;
                    CAN_TX_2.Pm1_voltage =0;             //Connector Remove
                    CAN_TX_2.Pm1_current =0;
                    can_module.enqueue(Q_Available_2);
                    PLC_queue.enqueue(Report_state_2);
                    bcurrentDemand = false;
                    if(CCS2.start == Charging_Start)
                    {
                        ChargerUI_Info_2.ui_Charger_ErrorCode = STAGE_B_DETECTED_2;
                        g_SetCurrent1 =  0;
                        CCS2.Status = Finishing;
                        CCS2.Reson = EVDisconnected;
                        evseStatusCode = EVSE_Shutdown;
                     }
                }
                if(pReportSTATE->info[0] == 9)
                {
                    CAN_TX_2.Dc_main = 0;
                    CAN_TX_2.Precharge   =0;
                    CAN_TX_2.Pm1_voltage =0;             //Connector Remove
                    CAN_TX_2.Pm1_current =0;
                }
                Plc_Voltage = pReportSTATE->info[0];
                qDebug() << "Report cp Voltage = " << pReportSTATE->info[0] << " V";
            }
            break;
        }
    }
    plc_req_2 = curChagerStep;
    if(DataBuffer.length() > 7)
    {      
        SendPLC(fd, DataBuffer);
    }
}
void dccomboplc_2::SendPLC(int tty_fd_PLC_2, QByteArray aData)
{
    const std::size_t count = aData.size();
    unsigned char* hex = new unsigned char[count];
    std::memcpy(hex,aData.constData(),count);
    if (tty_fd_PLC_2 >= 0) {
        tty_write(tty_fd_PLC_2, (char*)hex, (int) count);
    } else {

        qDebug() << "Port not open\n\r";
    }
     SAFE_DELETE(hex)
      return;
}

quint32 dccomboplc_2::getChecksum(QByteArray aData)
{
    quint32 nChecksum = 0;
    int nIndex = sizeof(Msg_Header);
    for(int i = nIndex; i <= aData.length() - 4; i++)
    {
        nChecksum += aData[i];
    }
    return nChecksum;
}

void dccomboplc_2::SetPhysicalValue(PhysicalValue* pValue, qint8 nMutiplier, quint8 nUnit, qint16 nValue)
{
    pValue->Multiplier = nMutiplier;
    pValue->Unit = nUnit;
    pValue->Value = nValue;
}
void dccomboplc_2::Request_ReportSTATE(int tty_fd_PLC)
{
    stReportSTATEReq* rReportSTATEReq = new stReportSTATEReq((quint8)1);
    QByteArray DataBuffer;
    DataBuffer.append((char*)rReportSTATEReq, sizeof(stReportSTATEReq));    
    rReportSTATEReq->Checksum = getChecksum(DataBuffer);
    SendPLC(tty_fd_PLC, DataBuffer);
    SAFE_DELETE(rReportSTATEReq)
     return;
}
void dccomboplc_2::Charger_Stop( int tty_fd_PLC)
{
    if(curChagerStep < PowerDeliveryReq)
    {
        stAllStopReq* rAllStopReq = new stAllStopReq();
        QByteArray DataBuffer;
        DataBuffer.append((char*)rAllStopReq, sizeof(stAllStopReq));
        rAllStopReq->Checksum = getChecksum(DataBuffer);
        SendPLC(tty_fd_PLC, DataBuffer);
        curChagerStep = NONE_ID;
        plc_req_2 =0;
        SAFE_DELETE(rAllStopReq)                
    }else
    {
         can_module.enqueue(Pm_Off_2);
         evseStatusCode =EVSE_Shutdown;
         plc_req_2 =0;
       //  bcurrentDemand = false;
    }
    return;
}

void dccomboplc_2::EmergencyStop()
{
    evseStatusCode = EVSE_EmergencyShutdown;//EVSE_Shutdown;
   // bEmergencyStop = true;
}
void dccomboplc_2::EVSE_RESET(int tty_fd_PLC)
{
    stEVSE_RESET_Req* pEVSE_RESET = new stEVSE_RESET_Req();
    QByteArray DataBuffer;
    DataBuffer.append((char*)pEVSE_RESET, sizeof(stEVSE_RESET_Req));
    pEVSE_RESET->Checksum = getChecksum(DataBuffer);
    SendPLC(tty_fd_PLC, DataBuffer);
    SAFE_DELETE(pEVSE_RESET)
}
void dccomboplc_2::Start_Fast(int tty_fd_PLC)
{
    evseStatusCode = EVSE_Ready;//EVSE_Ready;
    bcurrentDemand = false;
    ui_Min = 0;
    ui_Sec = 0;
    EV_SOC = 0;
    curChagerStep =NONE_ID;
    bEmergencyStop = false;
    memset(&ChargerUI_Info_2, 0, sizeof(stChargerUI_Info));

    eNumEVSEProcess = Finished;
    eNumresponseCode = OK;

    stReportINITReq* rInitReq = new stReportINITReq();
    QByteArray DataBuffer;
    DataBuffer.append((char*)rInitReq, sizeof(stReportINITReq));
    SendPLC(tty_fd_PLC, DataBuffer);
    SAFE_DELETE(rInitReq)
    return;

}
void dccomboplc_2::Charger_Start(int tty_fd_PLC)
{
    evseStatusCode = EVSE_Ready;//EVSE_Ready;
    bcurrentDemand = false;
    ui_Min = 0;
    ui_Sec = 0;
    EV_SOC = 0;
    can_module.enqueue(Pm_On_2);
    memset(&ChargerUI_Info_2, 0, sizeof(stChargerUI_Info));
    curChagerStep = NONE_ID;
    plc_req_2 =0;
    bEmergencyStop = false;
    eNumEVSEProcess = Finished;
    eNumresponseCode = OK;

    stReportINITReq* rInitReq = new stReportINITReq();
    QByteArray DataBuffer;
    DataBuffer.append((char*)rInitReq, sizeof(stReportINITReq));
    SendPLC(tty_fd_PLC, DataBuffer);
    SAFE_DELETE(rInitReq)
    qDebug() << "Start Charger";
    return;
}
