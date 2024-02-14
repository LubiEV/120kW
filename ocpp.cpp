#include "ocpp.h"
#include <QQueue>

QQueue<int> OCPPQueue;

 Charger_Status CCS(1);
 Charger_Status CCS2(2);

extern qint32 kw_ccs;
extern float pmdc1_curr,pmdc2_curr;
volatile unsigned int timerval = 0, timeStatus = 0,timeClockAlign = 0,timeMeterval = 0,timeMeterval_2 = 0,timeStatus_2,timeClockAlign_2;
int counter = 0;
int connection_counter = 0;
extern struct Parameter set_parameter;
struct Config_Parameter_OCPP Ocpp_Setting;
struct LoadSharing Sharing;

OCPP::OCPP(QObject *parent): QObject(parent)
{

}
void OCPP::Init(void)
{
    QTimer *timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    timer->start();    
#ifdef OCPP
    qDebug()<<"Timer Event call "<< endl;
#endif
}
bool OCPP::EthernetConfig(QString ip , QString getway ,QString subnet, bool enable)
{   
    if(enable == true)
    {
         QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("/home/root/1.sh -ec %1 %2 %3").arg(ip).arg(getway).arg(subnet));
    }
    return WEXITSTATUS(1);
}
 bool OCPP::WiFiConfig(QString ssid, QString passwd, bool enable)
 {
    bool ret;
    if(enable == true)
    {
         ret = QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("/home/root/1.sh -wc %1 %2").arg(ssid).arg(passwd));
    }
    return ret;
 }
 bool OCPP::GSM_connect(QString APN, int IPV, bool enable)
 {
    QString command;
    bool ret;

        if(enable == true)
        {
             if(IPV == 0)
             {
                 command="/home/root/1.sh -gc "+ APN +' '+"-4 -6";
             }
             else if(IPV == 1)
             {
                 command="/home/root/1.sh -gc "+ APN +' '+"-6";
             }else if(IPV == 2)
             {
                   command="/home/root/1.sh -gc "+ APN +' '+"-4";
             }
               ret = QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("%1").arg(command));
        }

        return ret;
 }
bool OCPP::isPeripharalConnect(quint8 Network)
{    
    unsigned int flags = ifaces.flags();
    bool isRunning;

    if(Network == Wifi_selection)
    {
        ifaces = QNetworkInterface::interfaceFromName("wlan0");
        isRunning = (bool)(flags & QNetworkInterface::IsRunning);
    }
    else if(Network == Ethernet_selection)
    {
        ifaces = QNetworkInterface::interfaceFromName("eth1");
        isRunning = (bool)(flags & QNetworkInterface::IsRunning);

    }
    else if(Network == GSM_selection)
    {
        ifaces = QNetworkInterface::interfaceFromName("wwan0");
        isRunning = (bool)(flags & QNetworkInterface::IsRunning);
    }
     if(isRunning)
     {
         return 1;
     }
     else
     {
         return 0;
     }
}
bool OCPP::Network_disable(int8_t Network)
{
    bool ret;
    if(Network == Wifi_selection)
    {
         ret = QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("/home/root/1.sh -wd"));
    }
    else if(Network == Ethernet_selection)
    {
        ret = QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("/home/root/1.sh -ed"));
    }
    else if(Network == GSM_selection)
    {
        QString command="/home/root/1.sh -gd";
        ret = QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("%1").arg(command));
    }
    return ret;
}
bool OCPP::isConnectOCPP(void)
{
    return this->OCPP_Live;
}
void OCPP::TimerEvent(void)
{
//    qDebug()<<"1 Second Timer Call"<<endl;

    if(++connection_counter > 5)
    {
        if(isPeripharalConnect(set_parameter.Network) == 1)
        {
            set_parameter.Network_status = 1;
            if(isConnectOCPP() == 1)
            {
                if(set_parameter.Ocpp_Status == 0)
                {
                    onOCPPdisConnected();
                }
                else
                {
                    m_Live = 1;
                    set_parameter.check_OCPP = 1;
                }
                trytoconnect = 0;
            }
            else
            {
                if(set_parameter.Ocpp_Status == 1)
                {
                    if(++trytoconnect > 15)
                     {
                        if(this->m_Popen == 0)
                        {
                            open();
                        }
                        else
                        {
                            close();
                        }                        
                        trytoconnect = 0;
                     }
                }
                set_parameter.check_OCPP =0;
            }
        }
        else
        {
            set_parameter.Network_status = 0;
            set_parameter.check_OCPP =0;
            if(isConnectOCPP() == 1)
            {
                m_webSocket.close();           
            }

            OCPP_Live = 0;
            BootSuccess = 0;
            trytoconnect = 0;
        }
    }

    if( OCPP_Live && BootSuccess)
    {
        ++timerval;                       
        if(timerval >= Ocpp_Setting.HeartbeatIntvl)
        {
            OCPPQueue.enqueue(HeartBeat);
            timerval = 0;
        }

        if(CCS2.Status == Charging)
        {
            if(++timeMeterval_2 > Ocpp_Setting.MeterIntvl)
            {
                OCPPQueue.enqueue(G2_MeterValue);
                timeMeterval_2 =0;
            }
        }
        else
        {
            if(++timeStatus_2 > Ocpp_Setting.StatusDuration)
            {
                OCPPQueue.enqueue(G2_StatusNotification);
                timeStatus_2 = 0;
            }

            if(++timeClockAlign_2 > Ocpp_Setting.ClkAlgnIntvl)
            {
                OCPPQueue.enqueue(ClockAlignData_2);
                timeClockAlign_2 =0;
            }
        }

        if(CCS.Status == Charging)
        {
            if(++timeMeterval > Ocpp_Setting.MeterIntvl)
            {
                OCPPQueue.enqueue(G1_MeterValue);
                timeMeterval =0;
            }
        }
        else
        {
            if(++timeStatus > Ocpp_Setting.StatusDuration)
            {
                OCPPQueue.enqueue(G1_StatusNotification);
                timeStatus = 0;
            }

            if(++timeClockAlign > Ocpp_Setting.ClkAlgnIntvl)
            {
                OCPPQueue.enqueue(ClockAlignData);
                timeClockAlign =0;
            }
        }
    }

    if(++counter > 3)
    {       
        counter = 0;
        //if(OCPP_Live)
        {
            ocpp_run();
        }
        /*else if(OCPPQueue.isEmpty() == false)
        {
            OCPPQueue.clear();
        }*/
    }
}
QString OCPP::currentDateTime(void)
{
    QString timestamp;
    timestamp = QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ssZ");
    return timestamp;
}
void OCPP::ocpp_run(void)
{
    int flag;
        if(OCPPQueue.isEmpty() == false)
        {
           flag = OCPPQueue.dequeue();
           if(OCPP_Live == 0)
           {
               if(flag != Tagid_search)
               {
                   return;
               }
           }
        }
        else
        {
            return;
        }

        //if(len == 0)
        {
             value = generator.generate() & std::numeric_limits<qint64>::max();
#ifdef OCPP
            qDebug() << "OCPP random Number" << flag << endl;
#endif

            switch(flag)
            {
                case init_EVSE :
                {
                       RandomBootNotification = QString::number(value);
                       BootNotification_req(RandomBootNotification,"Lubi",set_parameter.Serial_Number);
                       break;
                }
                case G1_StatusNotification :
                {
                    strError = errortostring(CCS.Error);
                    strStatus = statustostring(CCS.Status);
                    datetime  = currentDateTime();
                    StatusNotification_req((QString::number(value)),1,strError, strStatus, datetime);
                    break;
                }
                case G2_StatusNotification :
                {
                    strError = errortostring(CCS2.Error);
                    strStatus = statustostring(CCS2.Status);
                    datetime  = currentDateTime();
                    StatusNotification_req((QString::number(value)),2,strError, strStatus, datetime);
                    break;
                }
                case G1_StartTransaction :
                {
                    datetime  = currentDateTime();
                    RandomStartTrans_G1 = QString::number(value);
                    StartTransaction_req(RandomStartTrans_G1,1,CCS.TadId,CCS.Energy,0,datetime);
                    break;
                }
                case G2_StartTransaction :
                {
                    RandomStartTrans_G2 = QString::number(value);
                    StartTransaction_req(RandomStartTrans_G2,2,CCS2.TadId,CCS2.Energy,0,datetime);
                    break;
                }
                case G1_Authorise :
                {
                    RandomAuthorised_G1 = QString::number(value);
                    Authorise_req(RandomAuthorised_G1,CCS.TadId);
                    break;
                }
                case G2_Authorise :
                {
                    RandomAuthorised_G2 = QString::number(value);
                    Authorise_req(RandomAuthorised_G2,CCS2.TadId);
                    break;
                }
                case G1_MeterValue :
                {
                    datetime  = currentDateTime();
                    Metervalue_req(QString::number(value),1,CCS.TxnId,CCS.SOC,CCS.Tempreture_exhaust,CCS.DC_Current_1,CCS.current_L2,CCS.current_L3,CCS.DC_Voltage_1,CCS.voltage_L2,CCS.voltage_L3,(float)CCS.Power,CCS.Energy,datetime);
                    break;
                }
                case TransactionBegin :
                {
                    datetime  = currentDateTime();
                    Metervalue_req_begin(QString::number(value),1,CCS.TxnId,CCS.SOC,CCS.Tempreture_exhaust,CCS.DC_Current_1,CCS.current_L2,CCS.current_L3,CCS.DC_Voltage_1,CCS.voltage_L2,CCS.voltage_L3,(float)CCS.Power,CCS.Energy,datetime);
                    break;
                }
                case TransactionEnd :
                {
                    datetime  = currentDateTime();
                    Metervalue_req_end(QString::number(value),1,CCS.TxnId,CCS.SOC,CCS.Tempreture_exhaust,CCS.DC_Current_1,CCS.current_L2,CCS.current_L3,CCS.DC_Voltage_1,CCS.voltage_L2,CCS.voltage_L3,(float)CCS.Power,CCS.Energy,datetime);
                    break;
                }
                case G2_MeterValue :
                {
                    datetime  = currentDateTime();
                    Metervalue_req(QString::number(value),2,CCS2.TxnId,CCS2.SOC,CCS.Tempreture_exhaust,CCS2.DC_Current_1,CCS2.current_L2,CCS2.current_L3,CCS2.DC_Voltage_1,CCS2.voltage_L2,CCS2.voltage_L3,(float)CCS2.Power,CCS2.Energy,datetime);
                    break;
                }
                case TransactionBegin_2 :
                {
                    datetime  = currentDateTime();
                    Metervalue_req_begin(QString::number(value),2,CCS2.TxnId,CCS2.SOC,CCS.Tempreture_exhaust,CCS2.DC_Current_1,CCS2.current_L2,CCS2.current_L3,CCS2.DC_Voltage_1,CCS2.voltage_L2,CCS2.voltage_L3,(float)CCS2.Power,CCS2.Energy,datetime);
                    break;
                }
                case TransactionEnd_2 :
                {
                    datetime  = currentDateTime();
                    Metervalue_req_end(QString::number(value),2,CCS2.TxnId,CCS2.SOC,CCS.Tempreture_exhaust,CCS2.DC_Current_1,CCS2.current_L2,CCS2.current_L3,CCS2.DC_Voltage_1,CCS2.voltage_L2,CCS2.voltage_L3,(float)CCS2.Power,CCS2.Energy,datetime);
                    break;
                }
                case G1_StopTransaction :
                {
                    datetime  = currentDateTime();
                    RandomStopTrans_G1 = QString::number(value);
                    strReson = resontostring(CCS.Reson);
                    StopTransaction_req(RandomStopTrans_G1,CCS.TadId,(unsigned int)CCS.Energy,strReson,CCS.TxnId,datetime);
                    break;
                }
                case G2_StopTransaction :
                {
                    datetime  = currentDateTime();
                    RandomStoptTrans_G2 = QString::number(value);
                    strReson = resontostring(CCS2.Reson);
                    StopTransaction_req(RandomStoptTrans_G2,CCS2.TadId,(unsigned int)CCS2.Energy,strReson,CCS2.TxnId,datetime);
                    break;
                }
                case HeartBeat :
                {
                    HeartBeat_req(QString::number(value));
                    break;
                }
                case ClockAlignData:
                {
                    datetime  = currentDateTime();
                    Metervalue_ClockAlign_req(QString::number(value),1,CCS.current_L1,CCS.current_L2,CCS.current_L3,CCS.voltage_L1,CCS.voltage_L2,CCS.voltage_L3,CCS.Power,CCS.Energy,datetime);
                    break;
                }
                case ClockAlignData_2:
                {
                    datetime  = currentDateTime();
                    Metervalue_ClockAlign_req(QString::number(value),2,CCS2.current_L1,CCS2.current_L2,CCS2.current_L3,CCS2.voltage_L1,CCS2.voltage_L2,CCS2.voltage_L3,CCS2.Power,CCS2.Energy,datetime);
                    break;
                }
                case Tagid_search :
                     {
                        if(CCS.Status == Preparing)
                        {
                             if( db->SearchTagId(CCS.TadId) == true)
                             {
                                emit(RmtCharger_Start(1));
                             }
                        }
                        else if(CCS.Status == Charging || CCS2.Status == Charging)
                        {
                            if( db->SearchTagId(CCS.TadId) == true)
                            {
                                emit(RmtCharger_Stop(20));
                            }
                        }
                        CCS.Reson = Local;
                        break;
                      }
                default:
                {

                }
            };
    }
}
void OCPP::open(void)
{
    qDebug() << "OCPP Open port" << endl;
    this ->m_Popen = 1;
    connect(&m_webSocket, &QWebSocket::connected,this,&OCPP::onOCPPConnected);
    connect(&m_webSocket, &QWebSocket::disconnected,this,&OCPP::onOCPPdisConnected);    
    //m_webSocket.open(QUrl("ws://ocpp.grid-scape.com/services/CentralSystemServiceJson16/LUBI-BS-007"));
    // m_webSocket.open(QUrl("ws://113.20.17.179:8080"));
    /* QUrl url;
       url.setScheme("ws");
       url.setHost("113.20.17.179");
       url.setPort(8080);
  //     url.setPath("/cp3");
       url.isValid();
       m_webSocket.open (QUrl(url));
*/
    //   qDebug()<<url.toString() << "is valod? =" << url.isValid()<<endl;
    m_webSocket.open(QUrl((set_parameter.URL)));
}
void OCPP::close()
{
     this ->m_Popen = 0;
    qDebug() << "OCPP close" << endl;
    OCPP_Live = 0;
    disconnect(&m_webSocket, &QWebSocket::connected,this,&OCPP::onOCPPConnected);
    disconnect(&m_webSocket, &QWebSocket::disconnected,this,&OCPP::onOCPPdisConnected);
    m_webSocket.flush();
}
void OCPP::onOCPPConnected()
{
    qDebug() << "OCPP connected" << endl;    
    OCPP_Live = 1;
    if(CCS.OCPP_Pending_Tx == 1 && CCS.Status != Charging)
    {
         OCPPQueue.enqueue(G1_StopTransaction);
    }
    else /*if(CCS.Status == Available || )*/
    {
        OCPPQueue.enqueue(init_EVSE);
    }   
   connect(&m_webSocket, &QWebSocket::textMessageReceived,this,&OCPP::onOcppTextMessageReceived);
}
void OCPP::onOCPPdisConnected()
{
    qDebug() << "OCPP disconnected" << endl;
    OCPP_Live = 0;
    disconnect(&m_webSocket, &QWebSocket::textMessageReceived,this,&OCPP::onOcppTextMessageReceived);
    disconnect(&m_webSocket, &QWebSocket::connected,this,&OCPP::onOCPPConnected);
    disconnect(&m_webSocket, &QWebSocket::disconnected,this,&OCPP::onOCPPdisConnected);
    m_webSocket.close();
}
void OCPP::onOcppTextMessageReceived(QString message)
{
    qDebug() << "OCPP Recieved" << message <<endl;
    QByteArray data = message.toUtf8();
       QJsonDocument doc = QJsonDocument::fromJson(data);
       if (doc.isNull()) {
           qDebug() << "Parse failed";
       }

       QJsonArray json_array = doc.array();
       if(json_array.isEmpty()){
           qDebug() << "The array is empty";
           return;
       }

     qDebug() << json_array.at(0).toDouble();
     qDebug() << json_array.at(1).toString();

     if(json_array.at(0).toDouble() == 2)
     {
        QString MsgId = json_array.at(1).toString();
        QJsonObject root_obj = json_array.at(3).toObject();
        QVariantMap root_map = root_obj.toVariantMap();

        if(json_array.at(2).toString() == "RemoteStartTransaction")
        {
            int conn =  root_map["connectorId"].toDouble();
            if((conn == 1) && (CCS.Status == Preparing))
            {
                CCS.TadId = root_map["idTag"].toString();
                CCS.Reson = Remote;
                CCS.Automatic_Start =1;
                counter = 0;
                emit(RmtCharger_Start(1));
                Remote_res(MsgId,"Accepted");
            }
            if((conn == 2) && (CCS2.Status == Preparing))
            {
                CCS2.TadId = root_map["idTag"].toString();
                CCS2.Reson = Remote;
                CCS2.Automatic_Start =1;
                counter = 0;
                emit(RmtCharger_Start(2));
                Remote_res(MsgId,"Accepted");
            }
            else
            {
                Remote_res(MsgId,"Rejected");
            }
        }
        else if(json_array.at(2).toString() == "RemoteStopTransaction")
        {
           if(CCS.TxnId == root_map["transactionId"].toDouble())
           {
                // valid
               Remote_res(MsgId,"Accepted");
               counter = 0;           
               emit(RmtCharger_Stop(1));
           }
           else if(CCS2.TxnId == root_map["transactionId"].toDouble())
           {
                // valid
               Remote_res(MsgId,"Accepted");
               counter = 0;
               emit(RmtCharger_Stop(2));
           }

           else
           {
               // invalid
               Remote_res(MsgId,"Rejected");
           }
        }
        else if(json_array.at(2).toString() == "GetConfiguration")
        {
              QJsonArray array  = root_obj.value("key").toArray();

              qDebug() << "key object = " << array[0].toString();
              QString  Key = array.at(0).toString().toUtf8();
               qDebug() << "key = " << Key << endl;

            if(Key == NULL)
            {
                getconfig_response(MsgId,Ocpp_Setting.HeartbeatIntvl);
            }
            else if(Key == "NumberOfConnectors")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"NumberOfConnectors\",\"readonly\":true,\"value\":\"1\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "MeterValueSampleInterval")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MeterValueSampleInterval\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.MeterIntvl));
            }
            else if(Key == "HeartbeatInterval")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"HeartbeatInterval\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.HeartbeatIntvl));
            }
            else if(Key == "MeterValuesSampledDataMaxLength")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MeterValuesSampledDataMaxLength\",\"readonly\":true,\"value\":\"4\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "MinimumStatusDuration")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MinimumStatusDuration\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.StatusDuration));
            }
            else if(Key == "ResetRetries")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"ResetRetries\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.ResetRetry));
            }
            else if(Key == "AuthorizationCacheEnabled")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"AuthorizationCacheEnabled\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.AuthCachEnable ==true) ? "true" : "false"));
            }
            else if(Key == "LocalPreAuthorize")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"LocalPreAuthorize\",\"readonly\":true,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.LocalPreAuth ==true) ? "true" : "false"));
            }
            else if(Key == "ReserveConnectorZeroSupported")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"ReserveConnectorZeroSupported\",\"readonly\":true,\"value\":\"False\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "SendLocalListMaxLength")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"SendLocalListMaxLength\",\"readonly\":true,\"value\":\"10\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "LocalAuthListEnabled")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"LocalAuthListEnabled\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.LocalAuthListEnbl ==true) ? "true" : "false"));
            }
            else if(Key == "WebSocketPingInterval")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"WebSocketPingInterval\",\"readonly\":true,\"value\":\"300\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "TransactionMessageRetryInterval")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"TransactionMessageRetryInterval\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.FailedTx_Intvl));
            }
            else if(Key == "TransactionMessageAttempts")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"TransactionMessageAttempts\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.FailedAttempt));
            }
            else if(Key == "StopTxnSampledDataMaxLength")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"StopTxnSampledDataMaxLength\",\"readonly\":true,\"value\":\"1\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "StopTxnSampledData")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"StopTxnSampledData\",\"readonly\":true,\"value\":\"Energy.Active.Import.Register\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "StopTxnAlignedData")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"StopTxnAlignedData\",\"readonly\":true,\"value\":\"Energy.Active.Import.Register\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "StopTransactionOnInvalidId")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"StopTransactionOnInvalidId\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.StopTxInvalidId) == true ? "true" : "false"));
            }
            else if(Key == "StopTransactionOnEVSideDisconnect")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"StopTransactionOnEVSideDisconnect\",\"readonly\":false,\"value\":\"true\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "MeterValuesSampledData")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MeterValuesSampledData\",\"readonly\":true,\"value\":\"Current.Import,Power.Active.Import,Voltage,Energy.Active.Import.Register\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "MeterValuesAlignedDataMaxLength")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MeterValuesAlignedDataMaxLength\",\"readonly\":true,\"value\":\"4\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "MeterValuesAlignedData")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MeterValuesAlignedData\",\"readonly\":true,\"value\":\"Current.Import,Power.Active.Import,Voltage,Energy.Active.Import.Register\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "MaxEnergyOnInvalidId")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"MaxEnergyOnInvalidId\",\"readonly\":false,\"value\":\"0\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "LocalAuthorizeOffline")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"LocalAuthorizeOffline\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.LocalAuthOffln == true) ? "true" : "false"));
            }
            else if(Key == "ConnectionTimeOut")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"ConnectionTimeOut\",\"readonly\":true,\"value\":\"0\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }
            else if(Key == "ClockAlignedDataInterval")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"ClockAlignedDataInterval\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg(Ocpp_Setting.ClkAlgnIntvl));
            }
            else if(Key == "AuthorizeRemoteTxRequests")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"AuthorizeRemoteTxRequests\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.AuthRemotTx == true) ? "true" : "false"));
            }
            else if(Key == "AllowOfflineTxForUnknownId")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"AllowOfflineTxForUnknownId\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(MsgId).arg((Ocpp_Setting.AllowOfflineTXUnknownId == true) ? "true" : "false"));
            }
            /*else if(Key == "MaxChargeCurrent")
            {
                m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"AllowOfflineTxForUnknownId\",\"readonly\":false,\"value\":\"false\"}],\"unknownKey\":[\"\"]}]").arg(MsgId));
            }*/
            else
            {
                 Remote_res(MsgId,"NotSupported");
            }
        }
        else if(json_array.at(2).toString() == "ChangeConfiguration")
        {
            QString Key = root_map["key"].toString();
            if(Key == "NumberOfConnectors")
            {

            }
            else if(Key == "MeterValueSampleInterval")
            {
                Ocpp_Setting.MeterIntvl =root_map["value"].toInt();
                db->saveOCPP_Key(Ocpp_Setting.MeterIntvl,update_MeterIntvl);
            }
            else if(Key == "HeartbeatInterval")
            {
                Ocpp_Setting.HeartbeatIntvl = root_map["value"].toInt();
               db->saveOCPP_Key(Ocpp_Setting.HeartbeatIntvl,update_HeartbeatIntvl);
                qDebug() << "Heartbeat interbval = " << Ocpp_Setting.HeartbeatIntvl << endl;
            }
            else if(Key == "MeterValuesSampledDataMaxLength")
            {

            }
            else if(Key == "MinimumStatusDuration")
            {
                Ocpp_Setting.StatusDuration = root_map["value"].toInt();
                 db->saveOCPP_Key(Ocpp_Setting.StatusDuration,update_StatusDuration);
            }
            else if(Key == "ResetRetries")
            {
                Ocpp_Setting.ResetRetry = root_map["value"].toInt();
                db->saveOCPP_Key(Ocpp_Setting.ResetRetry,update_ResetRetry);
            }
            else if(Key == "AuthorizationCacheEnabled")
            {
                if(root_map["value"].toString() == "true")
                {
                    Ocpp_Setting.AuthCachEnable = 1;
                }
                else
                {
                    Ocpp_Setting.AuthCachEnable = 0;
                }
                 db->saveOCPP_Key(Ocpp_Setting.AuthCachEnable,update_AuthCachEnable);
            }
            else if(Key == "LocalPreAuthorize")
            {
                if(root_map["value"].toString() == "true")
                {
                    Ocpp_Setting.LocalPreAuth = 1;
                }
                else
                {
                    Ocpp_Setting.LocalPreAuth = 0;
                }
                db->saveOCPP_Key(Ocpp_Setting.LocalPreAuth,update_LocalPreAuth);
            }
            else if(Key == "ReserveConnectorZeroSupported")
            {

            }
            else if(Key == "SendLocalListMaxLength")
            {

            }
            else if(Key == "LocalAuthListEnabled")
            {

            }
            else if(Key == "WebSocketPingInterval")
            {

            }
            else if(Key == "TransactionMessageRetryInterval")
            {
                Ocpp_Setting.FailedTx_Intvl = root_map["value"].toInt();
                db->saveOCPP_Key(Ocpp_Setting.FailedTx_Intvl,update_FailedTx_Intvl);
            }
            else if(Key == "TransactionMessageAttempts")
            {
                Ocpp_Setting.FailedAttempt = root_map["value"].toInt();
                db->saveOCPP_Key(Ocpp_Setting.FailedAttempt,update_FailedTx_Intvl);
            }
            else if(Key == "StopTxnSampledDataMaxLength")
            {

            }
            else if(Key == "StopTxnAlignedData")
            {

            }
            else if(Key == "StopTransactionOnInvalidId")
            {
                    if(root_map["value"].toString() == "true")
                    {
                        Ocpp_Setting.StopTxInvalidId = 1;
                        qDebug() << "StopTransactionOnInvalidId = " << Ocpp_Setting.StopTxInvalidId << endl;
                    }
                    else
                    {
                        Ocpp_Setting.StopTxInvalidId = 0;
                    }
                    db->saveOCPP_Key(Ocpp_Setting.StopTxInvalidId,update_StopTxInvalidId);
            }
            else if(Key == "StopTransactionOnEVSideDisconnect")
            {

            }
            else if(Key == "MeterValuesSampledData")
            {

            }
            else if(Key == "MeterValuesAlignedDataMaxLength")
            {

            }
            else if(Key == "MeterValuesAlignedData")
            {

            }
            else if(Key == "MaxEnergyOnInvalidId")
            {

            }
            else if(Key == "LocalAuthorizeOffline")
            {
                if(root_map["value"].toString() == "true")
                {
                    Ocpp_Setting.LocalAuthOffln = 1;
                }
                else
                {
                    Ocpp_Setting.LocalAuthOffln = 0;
                }
                 db->saveOCPP_Key(Ocpp_Setting.LocalAuthOffln,update_LocalAuthOffln);
            }
            else if(Key == "ConnectionTimeOut")
            {

            }
            else if(Key == "ClockAlignedDataInterval")
            {
                    Ocpp_Setting.ClkAlgnIntvl = root_map["value"].toInt();
                    db->saveOCPP_Key(Ocpp_Setting.ClkAlgnIntvl,update_ClkAlgnIntvl);
            }
            else if(Key == "AuthorizeRemoteTxRequests")
            {
                if(root_map["value"].toString() == "true")
                {
                    Ocpp_Setting.AuthRemotTx = 1;
                }
                else
                {
                    Ocpp_Setting.AuthRemotTx = 0;
                }
                  db->saveOCPP_Key(Ocpp_Setting.AuthRemotTx,update_AuthRemotTx);
            }
            else if(Key == "AllowOfflineTxForUnknownId")
            {
                if(root_map["value"].toString() == "true")
                {
                    Ocpp_Setting.AllowOfflineTXUnknownId = 1;
                }
                else
                {
                    Ocpp_Setting.AllowOfflineTXUnknownId = 0;
                }
                db->saveOCPP_Key(Ocpp_Setting.AllowOfflineTXUnknownId,update_AllowOfflineTXUnknownId);
            }
             Remote_res(MsgId,"Accepted");
        }
        else if(json_array.at(2).toString() == "Reset")
        {
            if(root_map["type"].toString() == "Hard")
            {
                    RmtCharger_Stop(33);
            }
            else if(root_map["type"].toString() == "Soft")
            {
                   RmtCharger_Stop(55);
            }
            Remote_res(MsgId,"Accepted");
        }
        else if(json_array.at(2).toString() == "ChangeAvailability")
        {
            int connector = root_map["connectorId"].toInt();
            if(root_map["type"].toString() == "Operative")
            {
                set_parameter.Availibility = 0 + connector;
                db->saveOCPP_Key(set_parameter.Availibility,update_Operative);

                  if(connector == 0)
                  {                                           
                      if(CCS.Status == Unavailable)
                      {
                         emit(RmtCharger_Stop(77));
                      }
                      if(CCS2.Status == Unavailable)
                      {
                            emit(RmtCharger_Stop(78));
                      }
                  }
                  else if(connector == 1)
                  {
                      if(CCS.Status == Unavailable)
                      {
                         emit(RmtCharger_Stop(77));
                          qDebug()<<"status: Unavailable G1: "<<set_parameter.Availibility<<endl;
                      }
                  }
                  else if(connector == 2)
                  {
                      if(CCS2.Status == Unavailable)
                      {
                            emit(RmtCharger_Stop(78));
                          qDebug()<<"status: Unavailable G2: "<<set_parameter.Availibility<<endl;
                      }
                  }
            }
            else if(root_map["type"].toString() == "Inoperative")
            {
                  set_parameter.Availibility = 100+connector;
                  db->saveOCPP_Key(set_parameter.Availibility,update_Operative);
                  if(connector == 0)
                  {
                      if(CCS.Status != Unavailable)
                      {
                          emit(RmtCharger_Stop(75));
                      }

                      if(CCS2.Status != Unavailable)
                      {
                          emit(RmtCharger_Stop(76));
                      }
                  }
                     // CCS.Status = CCS2.Status = Unavailable;
                  else if(connector == 1)
                  {
                     // CCS.Status = Unavailable;
                      if(CCS.Status != Unavailable)
                      {
                        emit(RmtCharger_Stop(75));
                      }
                  }
                  else if(connector == 2)
                  {                      
                      if(CCS2.Status != Unavailable)
                      {
                          emit(RmtCharger_Stop(76));
                      }                     
                  }
            }                        
            Remote_res(MsgId,"Accepted");
        }

        else if(json_array.at(2).toString() == "TriggerMessage")
        {
           int conn = root_map["connectorId"].toInt();

            if(root_map["requestedMessage"].toString() == "BootNotification")
            {
                  OCPPQueue.enqueue(init_EVSE);
            }
            else if(root_map["requestedMessage"].toString() == "FirmwareStatusNotification")
            {

            }
            else if(root_map["requestedMessage"].toString() == "Heartbeat")
            {
                    OCPPQueue.enqueue(HeartBeat);
            }
            else if(root_map["requestedMessage"].toString() == "MeterValues")
            {
                    OCPPQueue.enqueue(ClockAlignData);
            }
            else if(root_map["requestedMessage"].toString() == "StatusNotification")
            {
                    OCPPQueue.enqueue(G1_StatusNotification);
            }
            else
            {
                Remote_res(MsgId,"NotImplemented");
            }
        }
        else if(json_array.at(2).toString() == "GetLocalListVersion")
        {
            m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"listVersion\": %2}]").arg(MsgId).arg(Ocpp_Setting.LocalListVersion));
        }
        else if(json_array.at(2).toString() == "SendLocalList")
        {
            Remote_res(MsgId,"Accepted");

            int version = root_map["listVersion"].toInt();
            QString update_type = root_map["updateType"].toString();
            if(update_type == "Full")
            {
                db->Deleterfid();
                Ocpp_Setting.LocalListVersion = version;
                db->saveOCPP_Key(version,update_LocalListVersion);
            }
            QJsonArray array  = root_map["localAuthorizationList"].toJsonArray();
            int i;
            foreach (const QJsonValue & value, array)
            {
                QJsonObject obj = value.toObject();
                QJsonValue val = obj.value(QString("idTag"));
                QVariant tag_id_info=  obj["idTagInfo"].toVariant();
                QVariantMap map = tag_id_info.toMap();

                qDebug()<< "Id Tag:" << val.toString() << endl;
                qDebug()<< "Status: "<<map["status"].toString() << "expiryDate:"<< map["expiryDate"].toString() << endl;
                db->Addrfid( i,val.toString() , map["status"].toString(),  map["expiryDate"].toDateTime(), "");
                i++;
            }

        }
        else if(json_array.at(2).toString() == "UnlockConnector")
        {
            int conn = root_map["connectorId"].toInt();
            Remote_res(MsgId,"NotSupported");
        }
     }
     else if(json_array.at(0).toDouble() == 3)
     {
        if(json_array.count() >= 3)
        {
            QJsonObject root_obj = json_array.at(2).toObject();
           if(RandomBootNotification == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();

               interval_Time =  root_map["interval"].toDouble();

               QDateTime datetime = root_map["currentTime"].toDateTime();
               qDebug()<<"Boot Date Time " <<  datetime.toString() << "Time Zone " << datetime.timeZone()<< endl;
               QDateTime(datetime.date(),datetime.time(),datetime.timeZone());               
                 if(root_map["status"].toString() == "Accepted")
                 {
                    BootSuccess = 1;
                    OCPPQueue.enqueue(G1_StatusNotification);
                    OCPPQueue.enqueue(G2_StatusNotification);
                 }
                 else
                 {
                      BootSuccess = 0;
                 }             
                    qDebug()<< root_map["interval"].toDouble();
                    qDebug()<< root_map["status"].toString();
           }
           else if(RandomStartTrans_G1 == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();
               CCS.TxnId = (qint64)root_map["transactionId"].toDouble();
               QVariantMap tagidinfo =  root_map["idTagInfo"].toMap();

               if(tagidinfo["status"].toString() == "Accepted")
               {
                    //success
                    emit(RmtCharger_Start(1));
                   CCS.OCPP_Pending_Tx = 1;                   
                   OCPPQueue.enqueue(TransactionBegin);
             //      OCPPQueue.enqueue(G1_StatusNotification);
               }
               else
               {
                   OCPPQueue.enqueue(G1_StopTransaction);
                    CCS.Reson = DeAuthorized;
                    emit(RmtCharger_Stop(1));
                     CCS.OCPP_Pending_Tx = 0;
               }
           }
           else if(RandomStopTrans_G1 == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();
               QVariantMap tagidinfo =  root_map["idTagInfo"].toMap();
               if(CCS.Reson == HardReset)
               {
                    emit(RmtCharger_Stop(56));
               }
               if(tagidinfo["status"].toString() == "Accepted")
               {
                   //success
                   //CCS.Reson = Other;
                    CCS.OCPP_Pending_Tx = 0;
                    OCPPQueue.enqueue(TransactionEnd);
                 // OCPPQueue.enqueue(G1_StatusNotification);                      change 5.29
                 //  CCS.Status = Finishing;
               }               
           }
           else if(RandomAuthorised_G1 == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();
               QVariantMap tagidinfo =  root_map["idTagInfo"].toMap();

               if(tagidinfo["status"].toString() == "Accepted")
               {
                   //success
                   //OCPPQueue.enqueue(G1_StartTransaction);
                   emit(RmtCharger_Start(1));
                   counter = 0;
               }
               else
               {   //OCPPQueue.enqueue(G1_StopTransaction);
                   //CCS.Reson = DeAuthorized;
                   // emit(RmtCharger_Stop(1));
               }
           }
           else if(RandomStartTrans_G2 == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();
               CCS2.TxnId = (qint64)root_map["transactionId"].toDouble();
               QVariantMap tagidinfo =  root_map["idTagInfo"].toMap();

               if(tagidinfo["status"].toString() == "Accepted")
               {
                    //success
                    emit(RmtCharger_Start(2));
                   OCPPQueue.enqueue(TransactionBegin_2);
                   CCS2.OCPP_Pending_Tx = 1;
               //    OCPPQueue.enqueue(G2_StatusNotification);
               }
               else
               {
                   OCPPQueue.enqueue(G2_StopTransaction);
                    CCS2.Reson = DeAuthorized;
                    emit(RmtCharger_Stop(2));
                     CCS2.OCPP_Pending_Tx = 0;
               }
           }
           else if(RandomStoptTrans_G2 == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();
               QVariantMap tagidinfo =  root_map["idTagInfo"].toMap();

               if(tagidinfo["status"].toString() == "Accepted")
               {
                   if(CCS2.Reson == HardReset)
                   {
                        emit(RmtCharger_Stop(57));
                   }
                   //success
                   //CCS.Reson = Other;
                    CCS2.OCPP_Pending_Tx = 0;
                    OCPPQueue.enqueue(TransactionEnd_2);                                   
               }
           }
           else if(RandomAuthorised_G2 == json_array.at(1).toString())
           {
               QVariantMap root_map = root_obj.toVariantMap();
               QVariantMap tagidinfo =  root_map["idTagInfo"].toMap();

               if(tagidinfo["status"].toString() == "Accepted")
               {
                   //success
                   //OCPPQueue.enqueue(G1_StartTransaction);
                   emit(RmtCharger_Start(2));
                   counter = 0;
               }
               else
               {   //OCPPQueue.enqueue(G1_StopTransaction);
                   //CCS.Reson = DeAuthorized;
                   // emit(RmtCharger_Stop(1));
               }
           }
        }
     }
}
void OCPP::BootNotification_req(QString RandomNumber, QString chargePointVendor,QString SerialNo)
{
    qDebug() << "BootNotification" <<endl;

//  m_webSocket.sendTextMessage(QStringLiteral("[2,\"%1\",\"BootNotification\",{\"chargePointVendor\":\"%2\",\"chargePointModel\":\"EVSEDC30K\"}]").arg(RandomNumber).arg(chargePointVendor)); //arg(RandumNumber,OCPP.vendor_id,"ACHYBD",OCPP.serial_no

    m_webSocket.sendTextMessage(QStringLiteral("[2,\"%1\",\"BootNotification\",{\"chargePointVendor\":\"%2\",\"chargePointModel\":\"%3\",\"chargePointSerialNumber\":\"%4\",\"firmwareVersion\":\"V1.0.1\"}]").arg(RandomNumber).arg(chargePointVendor).arg("ccs2").arg(SerialNo));
}
void OCPP::HeartBeat_req(QString RandomNumber)
{
    qDebug() << "HeartBeat" <<endl;
     m_webSocket.sendTextMessage(QStringLiteral("[2,\"%1\",\"Heartbeat\",{}]").arg(RandomNumber));
}
void OCPP::StatusNotification_req(QString RandomNumber,int connector,QString error,QString status,QString datetime)
{
     m_webSocket.sendTextMessage(QStringLiteral("[2,\"%1\",\"StatusNotification\",{\"connectorId\":%2,\"errorCode\":\"%3\",\"status\":\"%4\",\"timestamp\":\"%5\",\"vendorId\":\"LUBI-AC-2021\",\"vendorErrorCode\":\"0\"}]").arg(RandomNumber).arg(connector).arg(error).arg(status).arg(datetime));
}
void OCPP::Authorise_req(QString RandomNumber,QString IdTag)
{
     m_webSocket.sendTextMessage(QStringLiteral("[2,\"%1\",\"Authorize\",{\"idTag\":\"%2\"}]").arg(RandomNumber).arg(IdTag));
}
void OCPP::StartTransaction_req(QString RandomNumber,int connector,QString IdTag,double metervalue,int reservationId,QString datetime)
{
    m_webSocket.sendTextMessage(QStringLiteral("[2,\"%1\",\"StartTransaction\",{\"reservationId\": %2,\"timestamp\": \"%3\",\"meterStart\": %4,\"idTag\": \"%5\",\"connectorId\": %6}]").arg(RandomNumber).arg(reservationId).arg(datetime).arg(metervalue).arg(IdTag).arg(connector));
    qDebug()<<"Start Metervalue : " << metervalue<<endl;
}
void OCPP::StopTransaction_req(QString RandomNumber,QString IdTag,int stopValue,QString reason,unsigned long int txId,QString datetime)
{
    m_webSocket.sendTextMessage(QString("[2,\"%1\",\"StopTransaction\",{\"idTag\":\"%2\",\"meterStop\":%3,\"timestamp\":\"%4\",\"transactionId\":%5,\"reason\":\"%6\"}]").arg(RandomNumber).arg(IdTag).arg(stopValue).arg(datetime).arg(txId).arg(reason));
    qDebug()<<"Stop Metervalue : " << stopValue<<endl;
}
void OCPP::Metervalue_req(QString RandomNumber,int connector,unsigned long int txId,qint8 SOC,float Tempreture,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString datetime)
{
     m_webSocket.sendTextMessage(QString("[2,\"%1\",\"MeterValues\",{\"transactionId\":%2,\"connectorId\":%3,\"meterValue\":[{\"timestamp\": \"%4\",\"sampledValue\":[{\"unit\":\"A\",\"measurand\":\"Current.Import\",\"format\":\"Raw\",\"context\":\"Sample.Periodic\",\"value\":\"%5\"},{\"unit\":\"V\",\"measurand\":\"Voltage\",\"format\":\"Raw\",\"context\":\"Sample.Periodic\",\"value\":\"%6\"},{\"unit\":\"W\",\"measurand\":\"Power.Active.Import\",\"format\":\"Raw\",\"context\":\"Sample.Periodic\",\"value\":\"%7\"}, {\"unit\":\"Wh\",\"measurand\":\"Energy.Active.Import.Register\",\"format\":\"Raw\",\"context\":\"Sample.Periodic\",\"value\":\"%8\"},{\"unit\":\"Celsius\",\"measurand\":\"Temperature\",\"format\":\"Raw\",\"value\":\"%9\"},{\"unit\":\"Percent\",\"measurand\":\"SoC\",\"format\":\"Raw\",\"value\":\"%10\"}]}]}]").arg(RandomNumber).arg(txId).arg(connector).arg(datetime).arg(IL1).arg(VL1).arg(power).arg(energy).arg(Tempreture).arg(SOC));
     qDebug()<<"Metervalue : " << energy<<endl;
}
void OCPP::Metervalue_req_begin(QString RandomNumber,int connector,unsigned long int txId,qint8 SOC,float Tempreture,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString datetime)
{
     m_webSocket.sendTextMessage(QString("[2,\"%1\",\"MeterValues\",{\"transactionId\":%2,\"connectorId\":%3,\"meterValue\":[{\"timestamp\": \"%4\",\"sampledValue\":[{\"unit\":\"A\",\"measurand\":\"Current.Import\",\"format\":\"Raw\",\"context\":\"Transaction.Begin\",\"value\":\"%5\"},{\"unit\":\"V\",\"measurand\":\"Voltage\",\"format\":\"Raw\",\"context\":\"Transaction.Begin\",\"value\":\"%6\"},{\"unit\":\"W\",\"measurand\":\"Power.Active.Import\",\"format\":\"Raw\",\"context\":\"Transaction.Begin\",\"value\":\"%7\"}, {\"unit\":\"Wh\",\"measurand\":\"Energy.Active.Import.Register\",\"format\":\"Raw\",\"context\":\"Transaction.Begin\",\"value\":\"%8\"},{\"unit\":\"Celsius\",\"measurand\":\"Temperature\",\"format\":\"Raw\",\"value\":\"%9\"},{\"unit\":\"Percent\",\"measurand\":\"SoC\",\"format\":\"Raw\",\"value\":\"%10\"}]}]}]").arg(RandomNumber).arg(txId).arg(connector).arg(datetime).arg(IL1).arg(VL1).arg(power).arg(energy).arg(Tempreture).arg(SOC));
     qDebug()<<"Metervalue : " << energy<<endl;
}
void OCPP::Metervalue_req_end(QString RandomNumber,int connector,unsigned long int txId,qint8 SOC,float Tempreture,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString datetime)
{
     m_webSocket.sendTextMessage(QString("[2,\"%1\",\"MeterValues\",{\"transactionId\":%2,\"connectorId\":%3,\"meterValue\":[{\"timestamp\": \"%4\",\"sampledValue\":[{\"unit\":\"A\",\"measurand\":\"Current.Import\",\"format\":\"Raw\",\"context\":\"Transaction.End\",\"value\":\"%5\"},{\"unit\":\"V\",\"measurand\":\"Voltage\",\"format\":\"Raw\",\"context\":\"Transaction.End\",\"value\":\"%6\"},{\"unit\":\"W\",\"measurand\":\"Power.Active.Import\",\"format\":\"Raw\",\"context\":\"Transaction.End\",\"value\":\"%7\"}, {\"unit\":\"Wh\",\"measurand\":\"Energy.Active.Import.Register\",\"format\":\"Raw\",\"context\":\"Transaction.End\",\"value\":\"%8\"},{\"unit\":\"Celsius\",\"measurand\":\"Temperature\",\"format\":\"Raw\",\"value\":\"%9\"},{\"unit\":\"Percent\",\"measurand\":\"SoC\",\"format\":\"Raw\",\"value\":\"%10\"}]}]}]").arg(RandomNumber).arg(txId).arg(connector).arg(datetime).arg(IL1).arg(VL1).arg(power).arg(energy).arg(Tempreture).arg(SOC));
     qDebug()<<"Metervalue : " << energy<<endl;
}
void OCPP::Remote_res(QString MsgId,QString status)
{
    m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"status\":\"%2\"}]").arg(MsgId).arg(status));
}
void OCPP::getconfig_response(QString RandomNumber,int interval)
{
    m_webSocket.sendTextMessage(QString("[3,\"%1\",{\"configurationKey\":[{\"key\":\"SupportedFeatureProfiles\",\"readonly\":true,\"value\":\"Core,FirmwareManagement,RemoteTrigger\"},{\"key\":\"LocalPreAuthorize\",\"readonly\":true,\"value\":\"False\"},{\"key\":\"AuthorizationCacheEnabled\",\"readonly\":true,\"value\":\"False\"},{\"key\":\"MinimumStatusDuration\",\"readonly\":false,\"value\":\"60\"},{\"key\":\"ResetRetries\",\"readonly\":false,\"value\":\"2\"},{\"key\":\"StopTransactionOnEVSideDisconnect\",\"readonly\":true,\"value\":\"false\"},{\"key\":\"UnlockConnectorOnEVSideDisconnect\",\"readonly\":true,\"value\":\"false\"},{\"key\":\"NumberOfConnectors\",\"readonly\":true,\"value\":\"3\"},{\"key\":\"MeterValueSampleInterval\",\"readonly\":false,\"value\":\"60\"},{\"key\":\"MeterValuesSampledDataMaxLength\",\"readonly\":false,\"value\":\"4\"},{\"key\":\"HeartbeatInterval\",\"readonly\":false,\"value\":\"%2\"}],\"unknownKey\":[\"\"]}]").arg(RandomNumber).arg(interval));
}
void OCPP::Metervalue_ClockAlign_req(QString RandomNumber,int connector,float IL1,float IL2,float IL3,float VL1,float VL2,float VL3,float power,float energy,QString DateTime)
{
    m_webSocket.sendTextMessage(QString("[2,\"%1\",\"MeterValues\",{\"connectorId\":1,\"meterValue\":[{\"timestamp\": \"%2\",\"sampledValue\":[{\"unit\":\"A\",\"measurand\":\"Current.Import\",\"phase\":\"L1\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"value\":\"%3\"},{\"unit\":\"A\",\"measurand\":\"Current.Import\",\"phase\":\"L2\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"value\":\"%4\"},{\"unit\":\"A\",\"measurand\":\"Current.Import\",\"phase\":\"L3\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"value\":\"%5\"},{\"unit\":\"V\",\"measurand\":\"Voltage\",\"phase\":\"L1-L2\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"value\":\"%6\"},{\"unit\":\"V\",\"measurand\":\"Voltage\",\"phase\":\"L2-L3\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"value\":\"%7\"},{\"unit\":\"V\",\"measurand\":\"Voltage\",\"phase\":\"L3-L1\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"value\":\"%8\"},{\"unit\":\"W\",\"measurand\":\"Power.Active.Import\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"context\":\"Sample.Clock\",\"value\":\"%9\"},{\"unit\":\"Wh\",\"measurand\":\"Energy.Active.Import.Register\",\"format\":\"Raw\",\"context\":\"Sample.Clock\",\"context\":\"Sample.Clock\",\"value\":\"%10\"}]}]}]").arg(RandomNumber).arg(DateTime).arg(IL1).arg(IL2).arg(IL3).arg(VL1).arg(VL2).arg(VL3).arg(power).arg(energy));//RandumNumber,,DateTime,current,power,voltage,energy);
}
QString OCPP::errortostring(char error)
{
    QString ret;
    if(error == 0)
    {
        ret = "ConnectorLockFailure";
    }
    else if(error == 1)
    {
        ret = "EVCommunicationError";
    }
    else if(error == 2)
    {
        ret = "GroundFailure";
    }
    else if(error == 3)
    {
        ret = "HighTemperature";
    }
    else if(error == 4)
    {
        ret = "InternalError";
    }
    else if(error == 5)
    {
        ret = "LocalListConflict";
    }
    else if(error == 6)
    {
        ret = "NoError";
    }
    else if(error == 7)
    {
        ret = "OtherError";
    }
    else if(error == 8)
    {
        ret = "OverCurrentFailure";
    }
    else if(error == 9)
    {
        ret = "PowerMeterFailure";
    }
    else if(error == 10)
    {
        ret = "PowerSwitchFailure";
    }
    else if(error == 11)
    {
        ret = "ReaderFailure";
    }
    else if(error == 12)
    {
        ret = "ResetFailure";
    }
    else if(error == 13)
    {
        ret = "UnderVoltage";
    }
    else if(error == 14)
    {
        ret = "OverVoltage";
    }
    else if(error == 15)
    {
        ret = "WeakSignal";
    }
    return ret;
}
QString OCPP::resontostring(char status)
{
    QString ret;
    if(status == EmergencyStop)
     {
       ret = "EmergencyStop";
    }
    else if(status == EVDisconnected)
    {
        ret = "EVDisconnected" ;
    }
    else if(status == HardReset)
    {
        ret = "HardReset";
    }
    else if(status == Local)
    {
        ret = "Local";
    }
    else if(status == Other)
    {
        ret = "Other";
    }
    else if(status == PowerLoss)
    {
        ret = "PowerLoss";
    }
    else if(status == Reboot)
    {
        ret = "Reboot";
    }
    else if(status == Remote)
    {
        ret = "Remote";
    }
    else if(status == SoftReset){
        ret = "SoftReset";
    }
    else if(status == UnlockCommand)
    {
        ret = "UnlockCommand";
    }
    else if(status == DeAuthorized)
    {
        ret = "DeAuthorized";
    }
    return ret;
}
QString OCPP::statustostring(char status)
{
    QString ret;
    if(status == Available)
    {
       ret = "Available";
    }
    else if(status == Preparing)
    {
        ret = "Preparing";
    }
    else if(status == Charging)
    {
        ret = "Charging";
    }
    else if(status == SuspendedEVSE)
    {
        ret = "SuspendedEVSE";
    }
    else if(status == SuspendedEV)
    {
        ret = "SuspendedEV";
    }
    else if(status == Finishing)
    {
        ret = "Finishing";
    }
    else if(status == Reserved)
    {
        ret = "Reserved";
    }
    else if(status == Unavailable)
    {
        ret = "Unavailable";
    }
    else if(status == Faulted){
        ret = "Faulted";
    }
    return ret;
}
bool OCPP::replyFinished(QString FileName,long File_Size)
{
    bool status;
    QFile *file = new QFile(FileName);
    file->setPermissions(QFile::ExeOwner | QFile::ExeUser | QFile::ExeGroup);
    Elf64Hdr *header;
    QByteArray aData;
    char payload[] = {0x7f, 0x45 ,0x4c, 0x46, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    //  "7F 45 4C 46 1 1 1 3 0 0 0 0 0 0 0 0 "
    if(file->open(QFile::ReadOnly) == true)
    {
        file->seek(0);
        aData = file->read(sizeof(Elf64Hdr));
        header =  reinterpret_cast<Elf64Hdr*>(aData.data());
        if(file->size() != File_Size )
        {
            qDebug()<<"Mis-Match length..."<<endl;
            status = false;
        }
        else
        {
            if((strncmp((char *)header->e_ident,payload,16)) == 0)
            {
                qDebug()<<"Match identification "<<endl;
                status = true;
            }
            else
            {
                qDebug()<<"Mis-Match identification "<<endl;
                status = false;
            }
        }
        file->flush();
        file->close();
    }
    delete file;
    return status;
}
bool OCPP::Start_Sh(QString FileName)
{
    QFile readFile("/usr/bin/start.sh");
    QString strAll;
    if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
    {
        QTextStream stream(&readFile);
        strAll=stream.readAll();
    }
    else
    {
        return false;
    }
    readFile.close();
    QStringList strList;
    strList=strAll.split("\n");

    for(int i=0;i<strList.size();i++)
    {
        if(strList.at(i).startsWith("/home/root/"))
        {
            QString tempStr=strList.at(i);
            qDebug() << tempStr;
            tempStr.replace(0,tempStr.length(),"/home/root/"+FileName+" -platform linuxfb &");
            qDebug() << tempStr;
            strList.replace(i,tempStr);
            //                 qDebug() << strList.at(i);
        }
    }
    QFile writeFile("/usr/bin/start.sh");
    if(writeFile.open((QIODevice::WriteOnly|QIODevice::Text)))
    {
        QTextStream stream(&writeFile);
        for(int i=0;i<strList.size();i++)
        {
            stream<<strList.at(i)<<'\n';
        }
    }
    writeFile.close();
    return true;
}
