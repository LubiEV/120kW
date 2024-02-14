#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
struct Search_Tag
{
  QString TAGID;
  QString status;
  QDateTime Expiery_time;
  Search_Tag()
  {
   // status = NULL;
  //  TAGID = NULL;
  }

};
class Database:public QObject
{
    Q_OBJECT
public:
    Database(QObject *parent = nullptr);
 //   QSqlDatabase m_data;
    ~Database();
    struct Search_Tag ret_tag;
    bool Init_Database();
    int selectLoginData(QString user_name,QString user_password);
    bool saveUserData(QString user_name, QString user_password, QString user_passwod_confirm, int id);
    bool saveOcppData(QString serverURL,int32_t serverPort);
    bool saveEthernetData( QString localIP,QString gateWay,QString subnetMask);
    bool saveNetworkDisable(qint8 network);
    bool saveWifiData( QString ss_Id,QString wifi_password);
    bool savePriceSetting(int32_t time_by_charge,int32_t unit_by_charge);
    bool saveSettingData(int32_t overVoltage,int32_t underVoltage, int32_t overCurrent_CCS);
    bool saveGSMData(QString APN,int IPV );
    bool saveDC_Profile(int32_t Imax,int32_t Imin, int32_t Vmax, int32_t Vmin,int32_t Pmin, int32_t Pmax);    
    bool saveFirmwareUpgrade(QString Servername,QString Path ,int Port, QString Username,QString Password);
    bool saveAdmin_Setting(int id,QString parameter,int value,bool ED);

    bool saveDisplay(int SleepTime,int Brightness,qreal TimeOffset );
    bool selectocpp();
    bool selectOCPP_Key();
    bool selectethernet();
    bool selectwifi();
    bool selectPriceSetting();
    bool selectSetting();
    bool selectDC_Profile(); //
    bool selectGSM();
    bool selectDisplay();
    bool selecAdmin_Setting(int);
    void Deleterfid();
    void DeleteHistory();
    void saveOCPP_Key(quint16 Key_value, quint8 Key_type);
    bool Addrfid(int id ,QString tagid ,QString Status, QDateTime expieryTag,QString ParentTag);
    bool SearchTagId(QString tagid);
    bool SelectFirmwareUpgrade(void);
    void loging(int GunNo,QDateTime Start_time,QDateTime End_Time,int Total_time,float total_energy,QString reson,quint64 TxId);

signals:
    void signalSelectCurrent(int);

};

#endif // DATABASE_H
