#include "database.h"
#include "ocpp.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
extern struct Parameter set_parameter;
extern struct Config_Parameter_OCPP Ocpp_Setting;
QSqlDatabase m_data;
Database::Database(QObject *parent)
{
    qDebug()<<"database Contructure call" << endl;
}
Database::~Database()
{
//     QSqlDatabase db ;
        m_data.close();
}
bool Database::Init_Database()
{
    qDebug()<<"database Init call" << endl;
    QString path = "/home/sqlite_9";
    m_data = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    m_data.setDatabaseName(path);
    if(!m_data.open()){
#ifdef UI_Debug
        qDebug()<<"Failed to open database";
#endif
        return false;
    }
    else {
#ifdef UI_Debug
        qDebug()<<"Database Connected";
#endif
        return true;
    }
#ifdef UI_Debug
     qDebug()<< "database table" <<m_data.tables();
#endif

}
int Database::selectLoginData(QString user_name, QString user_password1){

    QSqlQuery query(m_data);
   query.exec("SELECT user_password from login_creadential where user_name='"+user_name+"'");

    bool result=0;
    if(query.exec() == false)
    {
       return false;
    }
    else{
        while (query.next()) {
        QString user_password = query.value(0).toString();
        if(user_password.compare(user_password1)){
            result=false;
        }
        else {

            result=true;
            break;
        }
       }
    }
    return result;
}
bool Database::saveUserData(QString user_name, QString user_password, QString user_passwod_confirm, int id)
{
        QSqlQuery query(m_data);
        query.prepare("UPDATE login_creadential SET user_password = (:user_password) where id=(:id)");
        query.bindValue(":user_password", user_password);
        query.bindValue(":id", id);
        if(query.exec())
        {
            return true;
        }
        else{
            return false;
        }
}
bool Database::saveDisplay(int SleepTime,int Brightness,qreal TimeOffset)
{
    QSqlQuery query(m_data);
    query.prepare("UPDATE Display SET SleepTime = (:SleepTime), Brightness = (:Brightness), TimeOffset = (:TimeOffset) where id= '1' ");
    query.bindValue(":SleepTime", SleepTime);
    query.bindValue(":Brightness", Brightness);
    query.bindValue(":TimeOffset", TimeOffset);
    if(query.exec())
    {
        return true;
    }
    else{
        return false;
    }
}
bool Database::saveOcppData(QString serverURL, int32_t serverPort)
{
    set_parameter.URL = serverURL;
    set_parameter.Port = serverPort;

    QSqlQuery query(m_data);
    query.prepare("UPDATE  ocpp SET serverURL = (:serverURL), serverPORT = (:serverPORT), Enable = (:Enable)  WHERE id = '1' ");
    query.bindValue(":serverURL", serverURL);
    query.bindValue(":serverPORT", serverPort);
    query.bindValue(":Enable", set_parameter.Ocpp_Status);
    if(query.exec())
    {
#ifdef UI_Debug
        qDebug() << "Ocpp values inserted.";
#endif
        return true;
    }
    else{
#ifdef UI_Debug
        qDebug() << "Ocpp Value not inserted!!!!!!!!!!!";
#endif
        return false;
    }
}

bool Database::saveEthernetData(QString localIP, QString gateWay, QString subnetMask)
{
    set_parameter.IP = localIP;
    set_parameter.Getway = gateWay;
    set_parameter.SubnetMask = subnetMask;

    QSqlQuery query(m_data);
    if(set_parameter.Network == 2)
    {
        saveNetworkDisable(Wifi_selection);
        saveNetworkDisable(GSM_selection);
        query.prepare("UPDATE ethernet SET localIP ='"+localIP+"',gateWay ='"+gateWay+"',subnetMask ='"+subnetMask+"' ,Enable = '1' WHERE Id='1' ");
    }
    else
    {
         query.prepare("UPDATE ethernet SET localIP ='"+localIP+"',gateWay ='"+gateWay+"',subnetMask ='"+subnetMask+"' ,Enable = '0' WHERE Id='1' ");
    }

    if(query.exec() == true)
    {
#ifdef UI_Debug
        qDebug() << "Ethernet  values inserted.";
#endif
        return true;
    }
    else{
#ifdef UI_Debug
         qDebug() << "Ethernet  Value not inserted!!!!!!!!!!!";
#endif
         return false;
    }
}

bool Database::saveWifiData(QString ss_Id, QString wifi_password)
{

    set_parameter.ssid = ss_Id;
    set_parameter.password = wifi_password;

    QSqlQuery query(m_data);
    if(set_parameter.Network == 1)
    {
        saveNetworkDisable(Ethernet_selection);
        saveNetworkDisable(GSM_selection);

        query.prepare("UPDATE wifi SET ssId='"+ss_Id+"',wifi_password = '"+wifi_password+"' , Enable = '1' WHERE id='1' ");
    }
    else
    {
        query.prepare("UPDATE wifi SET ssId='"+ss_Id+"',wifi_password = '"+wifi_password+"' , Enable = '0' WHERE id='1' ");
    }

    if(query.exec())
    {
#ifdef UI_Debug
        qDebug() << "Wifi  values inserted.";
#endif
        return true;
    }
    else{
#ifdef UI_Debug
        qDebug() << "Wifi  Value not inserted!!!!!!!!!!!";
#endif
        return false;
    }
}

bool Database::savePriceSetting(int32_t time_by_charge, int32_t unit_by_charge)
{
    set_parameter.time_charges = time_by_charge;

    set_parameter.unit_charges = unit_by_charge;
    QSqlQuery query(m_data);

    query.prepare("UPDATE  PriceSetting SET time_by_charge = (:time_by_charge), unit_by_charge = (:unit_by_charge) WHERE id = '1' ");

    query.bindValue(":time_by_charge", time_by_charge);

    query.bindValue(":unit_by_charge", unit_by_charge);


   if(query.exec() == true)
   {
#ifdef UI_Debug
       qDebug() << "Setting  values inserted.";
#endif
       return true;
   }
   else{
#ifdef UI_Debug
       qDebug() << "Setting  Value not inserted!!!!!!!!!!!";
#endif
       return false;
   }
}
bool Database::saveSettingData(int32_t overVoltage, int32_t underVoltage, int32_t overCurrent_CCS)
{
    set_parameter.Over_Current_ccs = overCurrent_CCS;
    set_parameter.Over_Voltage = overVoltage;
    set_parameter.Under_Voltage = underVoltage;
        QSqlQuery query(m_data);

    query.prepare("UPDATE  Setting SET OverVoltage = (:OverVoltage), UnderVoltage = (:UnderVoltage), OverCurrent = (:OverCurrent) WHERE id = '1' ");
    query.bindValue(":OverVoltage", overVoltage);
    query.bindValue(":UnderVoltage", underVoltage);
    query.bindValue(":OverCurrent", overCurrent_CCS);

       if(query.exec())
       {
#ifdef UI_Debug
           qDebug() << "Setting  values inserted.";
#endif
           return true;
       }
       else{
#ifdef UI_Debug
           qDebug() << "Setting  Value not inserted!!!!!!!!!!!";
#endif
           return false;
       }
}
bool Database::saveDC_Profile(int32_t Imax,int32_t Imin, int32_t Vmax, int32_t Vmin,int32_t Pmin, int32_t Pmax)
{
    set_parameter.DC_IMAX = Imax;
    set_parameter.DC_IMin = Imin;
    set_parameter.DC_VMAX = Vmax;
    set_parameter.DC_VMin = Vmin;
    set_parameter.DC_PMin = Pmin;
    set_parameter.DC_PMAX = Pmax;

    QSqlQuery query(m_data);
    query.prepare("UPDATE  DC_Profile SET Imax = (:Imax), Imin = (:Imin), Vmax = (:Vmax) , Vmin = (:Vmin), Pmin = (:Pmin), Pmax = (:Pmax)  WHERE id = '1' ");
    query.bindValue(":Imax", Imax);
    query.bindValue(":Imin", Imin);

    query.bindValue(":Vmax", Vmax);
    query.bindValue(":Vmin", Vmin);

    query.bindValue(":Pmin", Pmin);
    query.bindValue(":Pmax", Pmax);

       if(query.exec())
       {
#ifdef UI_Debug
           qDebug() << "Setting  values inserted.";
#endif
           return true;
       }
       else{
#ifdef UI_Debug
           qDebug() << "Setting  Value not inserted!!!!!!!!!!!";
#endif
           return false;
       }
}
bool Database::saveGSMData(QString APN,int IPV )
{
    set_parameter.GSM_APN = APN;
 //   set_parameter.GSM_IPV = IPV;
    QSqlQuery query(m_data);

    if(set_parameter.Network == 3)
    {

        saveNetworkDisable(Wifi_selection);
        saveNetworkDisable(Ethernet_selection);

        query.prepare("UPDATE  GSM SET APN = (:APN), IPV = (:IPV) ,Enable = '1' WHERE id = '1' ");
        query.bindValue(":APN", APN);
        query.bindValue(":IPV",  set_parameter.GSM_IPV);
    }
    else
    {
        query.prepare("UPDATE  GSM SET APN = (:APN), IPV = (:IPV), Enable = '0' WHERE id = '1' ");
        query.bindValue(":APN", APN);
        query.bindValue(":IPV",  set_parameter.GSM_IPV);
    }

       if(query.exec())
       {
#ifdef UI_Debug
           qDebug() << "Setting  values inserted.";
#endif
           return true;
       }
       else{
#ifdef UI_Debug
           qDebug() << "Setting  Value not inserted!!!!!!!!!!!";
#endif
           return false;
       }
}
bool Database::saveNetworkDisable(qint8 network)
{
    QSqlQuery query(m_data);

    if(network == Wifi_selection)
    {
        query.prepare("UPDATE wifi SET Enable = '0' WHERE id = '1' ");
    }
    if(network == Ethernet_selection)
    {
        query.prepare("UPDATE ethernet SET Enable = '0' WHERE Id = '1' ");
    }
    if(network == GSM_selection)
    {
         query.prepare("UPDATE GSM SET Enable = '0' WHERE Id = '1' ");
    }

    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "Network disable  values inserted.";
#endif
        return false;
    }
    else{
#ifdef UI_Debug
        qDebug() << "Network disable not inserted!!!!!!!!!!!";
#endif
        return true;
    }
}

bool Database::saveFirmwareUpgrade(QString Servername,QString Path ,int Port, QString Username,QString Password)
{

    QSqlQuery query(m_data);
    query.prepare("UPDATE  FirmwareUpgrade SET ServerName = (:Servername), Port = (:Port), Path = (:Path), username = (:Username), Password = (:Password) WHERE id = '1' ");
    query.bindValue(":Servername", Servername);
    query.bindValue(":Port", Port);
    query.bindValue(":Path", Path);
    query.bindValue(":Username", Username);
    query.bindValue(":Password", Password);

       if(query.exec())
       {
           return true;
       }
       else{
           return false;
       }
}
bool Database::selectocpp()
{
    QSqlQuery query = m_data.exec("SELECT * FROM ocpp");

#ifdef UI_Debug
    qDebug() << query.isValid() <<endl;
#endif
    if(query.lastError().isValid())
    {
#ifdef UI_Debug
         qDebug() << "Ocpp value not Selected.";
         qDebug() << query.lastError().text() <<endl;
#endif
    }
    else{
#ifdef UI_Debug
            qDebug() << "Ocpp value is Selected";
#endif
            while (query.next()) {

            set_parameter.URL = query.value(1).toString();
            set_parameter.Port = query.value(2).toUInt();
            set_parameter.Ocpp_Status = query.value(3).toUInt();
        }
     return true;
    }
    return false;
}

bool Database::selectethernet()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM ethernet WHERE id ='1'");
    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "Ethernet  value not Selected.";
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "Ethernet value is Selected";
#endif
        while (query.next()) {
            set_parameter.IP  = query.value(1).toString();
            set_parameter.Getway  = query.value(2).toString();
            set_parameter.SubnetMask = query.value(3).toString();
            if(query.value(4).toInt() == 1)
            {
                set_parameter.Network = 2;
            }
        }
        return true;
    }
    return false;
}
bool Database::selectwifi()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM wifi WHERE id ='1'");
    query.exec();
    if(query.exec()== false)
    {
#ifdef UI_Debug
        qDebug() << "Wifi ssid value not Selected.";
         qDebug() << query.lastError().text() <<endl;
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "Wifi ssid value is Selected";
#endif
        while (query.next()) {
            set_parameter.ssid  = query.value(1).toString();
         set_parameter.password  = query.value(2).toString();
         if(query.value(3).toInt() == 1)
         {
             set_parameter.Network = 1;
         }
        }
        return true;
    }
    return false;
}
bool Database::selectPriceSetting()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM PriceSetting WHERE id ='1'");

    if(query.exec()== false)
    {
#ifdef UI_Debug
        qDebug() << "Price Setting time by charge value not Selected.";
#endif
    }
    else{
#ifdef UI_Debug
            qDebug() << "Price Setting time by charge value is Selected";
#endif
        while (query.next()) {
             set_parameter.time_charges  = query.value(1).toInt();
             set_parameter.unit_charges = query.value(2).toInt();
        }
        return true;
    }
    return false;
}
bool Database::selectSetting()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM Setting WHERE id ='1'");
    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "Setting Over Volt value not Selected.";
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "Setting Over Volt value is Selected";
#endif
        while (query.next()) {

        set_parameter.Over_Voltage = query.value(1).toInt();
        set_parameter.Under_Voltage = query.value(2).toInt();
        set_parameter.Over_Current_ccs = query.value(3).toInt();
        }

        return true;
    }
    return false;
}
bool Database::selectDC_Profile()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM DC_Profile WHERE id ='1'");
    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "Setting  DC Profile value not Selected.";
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "Setting DC Profile value is Selected";
#endif
        while (query.next()) {
            set_parameter.DC_IMAX = query.value(1).toInt();
            set_parameter.DC_IMin = query.value(2).toInt();
            set_parameter.DC_VMAX = query.value(3).toInt();
            set_parameter.DC_VMin = query.value(4).toInt();
            set_parameter.DC_PMin = query.value(5).toInt();
            set_parameter.DC_PMAX = query.value(6).toInt();
        }
        return true;
    }
    return false;
}
bool Database::selectGSM()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM GSM WHERE id ='1'");
    query.exec();
    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "GSM value not Selected.";
         qDebug() << query.lastError().text() <<endl;
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "GSM value is Selected";
#endif
        while (query.next()) {
          set_parameter.GSM_APN  = query.value(1).toString();
          set_parameter.GSM_IPV  = query.value(2).toInt();

         if(query.value(3).toInt() == 1)
         {
             set_parameter.Network = 3;
         }
        }
        return true;
    }
    return false;
}
bool Database::selectOCPP_Key()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM OCPP_KEY WHERE id ='1'");
    query.exec();
    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "GSM value not Selected.";
         qDebug() << query.lastError().text() <<endl;
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "GSM value is Selected";
#endif
        while (query.next()) {
             Ocpp_Setting.LocalAuthListEnbl = query.value(1).toBool();
             Ocpp_Setting.StopTxInvalidId = query.value(2).toBool();
             Ocpp_Setting.LocalPreAuth = query.value(3).toBool();
             Ocpp_Setting.LocalAuthOffln = query.value(4).toBool();
             Ocpp_Setting.AuthRemotTx = query.value(5).toBool();
             Ocpp_Setting.AuthCachEnable = query.value(6).toBool();            
             Ocpp_Setting.FailedTx_Intvl = query.value(7).toInt();
             Ocpp_Setting.FailedAttempt = query.value(8).toInt();
             Ocpp_Setting.ResetRetry =  query.value(9).toInt();
             Ocpp_Setting.StatusDuration = query.value(10).toInt();
             Ocpp_Setting.MeterIntvl = query.value(11).toInt();
             Ocpp_Setting.ClkAlgnIntvl = query.value(12).toInt();
             Ocpp_Setting.HeartbeatIntvl = query.value(13).toInt();
             Ocpp_Setting.AllowOfflineTXUnknownId = query.value(14).toInt();
             Ocpp_Setting.Operative = set_parameter.Availibility = query.value(15).toInt();
        }
        return true;
    }
    return false;
}
bool Database::selectDisplay()
{
    QSqlQuery query(m_data);
    int id;
    query.prepare("SELECT * FROM Display WHERE Id ='1'");
    query.exec();
    if(query.exec() == false)
    {
        return false;
    }
    else{

        while (query.next()) {
          set_parameter.SleepTime  = query.value(0).toInt();
          set_parameter.Brightness  = query.value(1).toInt();
          id = query.value(2).toInt();
          set_parameter.TimeOffset = (float)query.value(3).toReal();
        }
        return true;
    }
    return false;
}
bool Database::selecAdmin_Setting(int id)
{
    int id_rec;
    QString Parameter_Name;
    int value;
    bool ED;
    QSqlQuery query(m_data);

    query.prepare("SELECT * FROM Admin_Setting WHERE Id = (:id)");
    query.bindValue(":id", id);
    if(query.exec() == false)
    {
        return false;
    }
    else{

        while (query.next()) {
          id_rec  = query.value(0).toInt();
          Parameter_Name  = query.value(1).toString();
          value  = query.value(2).toInt();
          ED = query.value(3).toBool();
        }

        if(id_rec == 1)
        {
            set_parameter.tempThresold = value;
            set_parameter.tempThresold_ED = ED;
        }else if(id_rec == 2)
        {
            set_parameter.cutoffsoc = value;
            set_parameter.cutoffsoc_ED = ED;
        }
        else if(id_rec == 3)
        {
            set_parameter.DoorlOCK_ED = ED;
        }
        else if(id_rec == 4)
        {
            set_parameter.Serial_Number = Parameter_Name;
        }
        else if(id_rec == 5)
        {
            set_parameter.TestMode_ED = ED;
        }
        else if(id_rec == 6)
        {
            set_parameter.GroundFault_ED = ED;
        }
        else if(id_rec == 7)
        {
            set_parameter.IsolationFault_ED = ED;
        }
        else if(id_rec == 8)
        {
            set_parameter.TouchInterval_ED = ED;
            set_parameter.TouchInterval = value;
        }
        else if(id_rec == 9)
        {
            set_parameter.PMIndividual_ED = ED;
        }
        else if(id_rec == 10)
        {
          set_parameter.LoadSharing_ED = ED;
        }
        else if(id_rec == 11)
        {
            set_parameter.PreSLoadsharing_ED = ED;
        }
        else if(id_rec == 12)
        {
            set_parameter.PostSLSharing_ED = ED;
        }
        return true;
    }
    return false;
}
void Database::loging(int GunNo,QDateTime Start_time,QDateTime End_Time,int Total_time,float total_energy,QString reson,quint64 TxId)
{
    int id=0;
    QSqlQuery query(m_data);
    query.prepare("SELECT max(id) FROM history");
    if(query.exec()== false)
    {

    }
    else{
#ifdef UI_Debug
        qDebug() << "id tag value..";
#endif
        while (query.next()) {
        id = query.value(0).toInt();
        qDebug()<<"Maximum History Log : "<<id <<endl;
        }
    }
    id++;
    query.prepare("INSERT INTO history(id,GunNo,start_time,end_time,total_time,reson,Transaction_Id,total_energy)"
                     "VALUES(:id,:GunNo,:Start_time,:end_time,:total_time,:reson,:TxId,:total_energy)");
       query.bindValue(":id", id);
       query.bindValue(":GunNo",GunNo);
       query.bindValue(":Start_time", Start_time);
       query.bindValue(":end_time", End_Time);
       query.bindValue(":total_time", Total_time);
       query.bindValue(":total_energy", total_energy);
       query.bindValue(":reson", reson);
       query.bindValue(":TxId", TxId);

        if(query.exec() == true)
        {
            qDebug() << "data login successfully.";
        }
        else{
            qDebug() << "error on data login";
        }
}
bool Database::saveAdmin_Setting(int id,QString parameter,int value,bool ED)
{
 QSqlQuery query(m_data);
 query.prepare("UPDATE Admin_Setting SET Parameter = (:parameter), Value = (:value), ED = (:ED) WHERE id = (:id)");
 query.bindValue(":id", id);
 query.bindValue(":parameter", parameter);
 query.bindValue(":value", value);
 query.bindValue(":ED", ED);

 if(query.exec() == false)
 {
     qDebug() << "saveAdmin_Setting UPDATE Fail";
 }
 else{
     qDebug() << "saveAdmin_Setting UPDATE Success";
 }
 return true;
}
void Database::saveOCPP_Key(quint16 Key_value, quint8 Key_type)
{
    QSqlQuery query(m_data);
    qDebug() << "Save In Key" <<endl;

    if(Key_type == update_LocalAuthListEnbl)
    {
        query.prepare("UPDATE OCPP_KEY SET LocalAuthListEN = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_FailedTx_Intvl)
    {
        query.prepare("UPDATE OCPP_KEY SET FailedTx_Intvl = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_StopTxInvalidId)
    {
        query.prepare("UPDATE OCPP_KEY SET StopTxInvalidI = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_ResetRetry)
    {
        query.prepare("UPDATE OCPP_KEY SET ResetRetry = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_StatusDuration)
    {
        query.prepare("UPDATE OCPP_KEY SET StatusDuration = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_MeterIntvl)
    {
        query.prepare("UPDATE OCPP_KEY SET MeterIntvl = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_LocalPreAuth)
    {
        query.prepare("UPDATE OCPP_KEY SET LocalPreAuth = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_LocalAuthOffln)
    {
        query.prepare("UPDATE OCPP_KEY SET LocalAuthOffln = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_ClkAlgnIntvl)
    {
        query.prepare("UPDATE OCPP_KEY SET ClkAlgnIntvl = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_AuthRemotTx)
    {
        query.prepare("UPDATE OCPP_KEY SET AuthRemotTx = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_AuthCachEnable)
    {
        query.prepare("UPDATE OCPP_KEY SET AuthCachEnable = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_AllowOfflineTXUnknownId)
    {
        query.prepare("UPDATE OCPP_KEY SET AllowOfflineTXUnknownId = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_HeartbeatIntvl)
    {
        query.prepare("UPDATE OCPP_KEY SET HeartbeatIntvl = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_Operative)
    {
        qDebug()<< "Update Operative" << endl;
        query.prepare("UPDATE OCPP_KEY SET Operative = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    else if(Key_type == update_LocalListVersion)
    {
        query.prepare("UPDATE OCPP_KEY SET LocalListVersion = (:Key_value) WHERE id='1' ");
        query.bindValue(":Key_value", Key_value);
    }
    if(query.exec())
    {
        qDebug() << "Key UPDATE Fail";
    }
    else{
        qDebug() << "Key UPDATE Success";
    }
}
void Database::Deleterfid()
{
    QSqlQuery query(m_data);

       query.prepare("DELETE FROM rfid");
       if(query.exec() == false)
       {
           qDebug() << " RFID Delete Failed .";
       }
       else{
             qDebug() << " RFID Delete Success .";
       }
}
void Database::DeleteHistory()
{
    QSqlQuery query(m_data);
       query.prepare("DELETE FROM history");
       if(query.exec() == false)
       {
           qDebug() << " history Delete Failed .";
       }
       else{
             qDebug() << " history Delete Success .";
       }
}
bool Database::Addrfid(int id,QString tagid ,QString Status, QDateTime expieryTag,QString ParentTag)
{
    QSqlQuery query(m_data);
    query.prepare("INSERT INTO rfid(id,tagid,status,expiryTag,parentTagid)"
                     "VALUES (:id,:tagid,:Status,:expieryTag,:ParentTag)");

       query.bindValue(":id",id);
       query.bindValue(":tagid", tagid);
       query.bindValue(":Status", Status);
       query.bindValue(":expieryTag", expieryTag);
       query.bindValue(":ParentTag", ParentTag);

        if(query.exec() == false)
        {
            qDebug() << " RFID Adding Failed .";
        }
        else{
            qDebug() << "RFID Adding Success";
        }
        return true;
}
bool Database::SearchTagId(QString tagid)
{
    qDebug() << "in serch tag";
    QString Tagid_1;
    QString Status;
    int SrN;

    QSqlQuery query(m_data);      
    query.prepare("SELECT * FROM rfid where tagid = '"+tagid+"'");

    if(query.exec() == false)
    {
         qDebug() << "id tag error.";
    }
    else{
        while (query.next()) {
            qDebug() << "id tag read successfully...";
            SrN = query.value(0).toInt();
            Tagid_1 = query.value(1).toString();
            Status = query.value(2).toString();
          }            
    }
    if(Tagid_1 == tagid)
    {
         return true;
    }
    return false;
}
bool Database::SelectFirmwareUpgrade()
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM FirmwareUpgrade where id = '1'");
    quint8 id;

    if(query.exec() == false)
    {
         qDebug() << "firmware upgrade error.";
    }
    else{
        while (query.next()) {
               id  = query.value(0).toInt();
              set_parameter.FW_SN  = query.value(1).toString();
              set_parameter.FW_Port  = query.value(2).toInt();
              set_parameter.FW_Path  = query.value(3).toString();
              set_parameter.FW_UN  = query.value(4).toString();
              set_parameter.FW_PW  = query.value(5).toString();
            }
            return true;
    }
    return false;
}
