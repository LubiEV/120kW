#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtConcurrent>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "powermdl.h"
#include "powercontrol.h"
#include "dccomboplc.h"
#include "cantoserialctrl.h"
#include <QDebug>
#include "modbus.h"
#include "database.h"
#include "imd.h"
#include <QTimer>
#include "keyboard/widgetKeyBoard.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QTranslator>
#include <QSqlDatabase>
#include"Controller.h"
#include"form.h"
#include <QNetworkInterface>
#include "ocpp.h"
#include "rfid.h"
#include <QTouchEvent>
#include <linux/watchdog.h>
enum KeyboardData{
  ChargebyTime=1,
    ChargebyUnit,
    Username,
    Password,
    RegUsername,
    RegPassword,
    RegConfirmPass,
    RegHintPass,
    ELocalIP,
    EGatewayIP,
    ESubnetmask,
    OServerURL,
    OServerPort,
    WifiSSID,
    WifiPassword,
    TimebyCharge,
    UnitbyCharge,
    OverVolt,
    UnderVolt,
    OverCurrCCS,
    OverCurrAC,
    Automatic,
    APN,
    DC_Max_V,
    DC_Min_V,
    DC_Max_I,
    DC_Min_I,
    DC_Max_P,
    DC_Min_P,
    DC_Serial_number,
    fw_SN,
    fw_Path,
    fw_UN,
    fw_PW,
    DS_DateTime,
    DS_SleepTime,
    DS_TMZOffset,
    ChargingsettingPassword,
    conformChargingsettingPassword,
    ChargingPassword,
    stopChargingPassword,
    TempThresold,
    CutoffSoc,
    TouchInterval
};
enum TypeOfKeyboard{
  Numeric_Keyboard,
     AScii_KeyBoard
};
enum SCREEN{
    MainScreen_1,
    ChargingScreen_1,
    ChargingScreen_2,
    StartScreen_1,
    StartScreen_2,
    StopScreen_1,
    StopScreen_2,
};
extern enum SessionStatus STATE;
class Form;
namespace Ui {
class MainWindow;
}

class  Controller;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();   
//   bool           bTimeOutPLC_1;
protected:
     void mousePressEvent(QMouseEvent* evt);
    widgetKeyBoard *getKeyboard();
    quint32 nTime;
    QString sTime;
    bool waitForResuming = false;
    int fd,timeout = 250;
    OCPP *ocpp_1 = nullptr;
    char v_ChargingFlow;
    char keynboard_Update;
    int currentpage;
    int nChargerMode;
    int pricebytime;
    int pricebyunit;
    int overvoltage;
    int undervoltage;
    int ccs_overcurrent;
    unsigned int TMZOffset=0;
   // unsigned char touch_driver =0;

    int rfidfd;    
    QDateTime dtStartTime;       
    bool sleep_Mode = false;
    void HMI_sleep_Mode();
    void HMI_WakeUP_Mode();
    void SetTimeOut();
    void SetTimeOut(QString ErrStr);
    void reset_Charging_Info();
    // Search_Tag tag_status;
    void StartUpdatetimer(bool bStart);
public:
    bool Display_log(int);
    int Log_index=0;
    int Max_Log_index;
    void CCSBILLING(Charger_Status *CCS,stChargerUI_Info cInfo);
    void update_Charging_Info(stChargerUI_Info cInfo);
    void Charging_calculation();

public slots:
  //  void Charging_End();
    void on_pushButton_EmergencyStopCCS_clicked();
    bool CCSStart();
private slots:    
    void workFinished(const QString& rResult);

private slots:    
    void CCS_relay_status(int);
    void ACGunStatus(int);
 //   void ACStatus(bool);
    void TimeRead();
   // void GunConnectStatus(bool);
    void Start_Charger(int nMode);
    void Remot_Start_Charger(int nMode);
    void Stop_Charger(int nMode);
    void Remot_Stop_Charger(int nMode);
    void End_Charger(void);
    void LoadSharingStatus(void);
    void LoadSharingStatus_2(void);
    void End_Charger_2(void);
    void ForcedStop(int nGroup);
    void chargingSchemeSlot(QString);
   void FirmwareUpdateStatus(bool status);
   void OpenSerial();
   void StartRemoteApp();
  // void Back_Connect(int nMode);
   #ifdef DONTUSE
   void DcCombo2Pluged(int nGroup, bool bPluged);
   void DcComboSessionStop(int nGroup);
#endif
   #ifdef DONTUSE
   void SetRelay(int nGroup, int state);

   void Charging_Info(stChargerUI_Info charginInfo);
#endif
   #ifdef DONTUSE
   void SetCurrentLimit(qint16 Cur_1, qint16 Cur_2);
#endif

  #ifdef DONTUSE
   void Update_DateTime();
#endif

   void TagId_Search(QString);
   void UserPasswordSlot(QString);
   void AdminSignInSlot(QString);
   void EthernetSlot(QString);
   void OcppSlot(QString);
   void WifiSlot(QString);
   void PriceSettingSlot(QString);
   void SettingSlot(QString);
   void DC_ProfileSlot(QString);
   void Serial_number(QString);
   void Firmware_Upgrade(QString);
   void GSMSSlot(QString);
   void DisplaySetting(QString);
    void on_pushButton_3_clicked();
    void on_pushButton_CCS_clicked();

    void on_pushButton_CCSPayment_clicked();
    void on_pushButton_FinishCCS_clicked();
    void on_pushButton_Login_clicked();
    void on_pushButton_Signin_clicked();
    void on_pushButton_CancelLogin_clicked();
    void on_pushButton_SaveRegister_clicked();
   // void on_pushButton_CancelRegister_clicked();
    void on_pushButton_Return_OCPP_clicked();
    void on_pushButton_Confirmocpp_clicked();
    void on_pushButton_AdminIcon_clicked();
    void on_pushButton_AdminOCPP_clicked();
    void on_pushButton_AdminEthernet_clicked();
    void on_pushButton_AdminWifi_clicked();
    void on_pushButton_EthernetSetting_clicked();
    void on_pushButton_WifiSetting_clicked();
   // void on_pushButton_RFID_Back_clicked();
    void on_pushButton_Price_setting_clicked();
    void on_pushButton_getOutfromPriceSett_clicked();
    void on_pushButton_Setting_clicked();
    void on_pushButton_AdminSetting_clicked();
 //   void on_pushButton_Back_Main_clicked();
    void on_checkBox_clicked();

 //   void on_pushButton_EneterParameter_clicked();

   // void on_pushButton_CCS_Charging_clicked();

    void on_pushButton_ChargingParamAC_clicked();

  //  void on_pushButton_Virtual_Keyboard_2_clicked();

 //   void on_pushButton_keyboard_username_clicked();

    void on_pushButton_keyboard_password_clicked();

 //   void on_pushButton_Regi_username_clicked();

    void on_pushButton_Regi_password_clicked();

    void on_pushButton_Regi_confirmpass_clicked();

  //  void on_pushButton_Regi_PassHint_clicked();

    void on_pushButton_Ether_Localip_clicked();

    void on_pushButton_Ether_Gatewayip_clicked();

    void on_pushButton_Ether_Subnet_clicked();

    void on_pushButton_Keyboard_serverURL_clicked();

    void on_pushButton_keyboard_serverPort_clicked();

    void on_pushButton_keyboard_SSID_clicked();

    void on_pushButton_keyboard_wifiPass_clicked();

    void on_pushButton_keyboard_PriceSett_clicked();

    void on_pushButton_keyboard_Setting_clicked();

    void on_pushButton_keyboard_OverVolt_clicked();

    void on_pushButton_keyboard_UnderVolt_clicked();

    void on_pushButton_keyboard_OverCurrCCS_clicked();

 //   void on_pushButton_keyboard_OverCurrAC_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_History_Page_clicked();

   // void on_lineEdit_Password_editingFinished();

    void on_pushButton_keyboard_Max_V_clicked();

    void on_pushButton_keyboard_Min_V_clicked();

    void on_pushButton_keyboard_Max_I_clicked();

 //   void on_pushButton_keyboard_OverVolt_4_clicked();
  //  void on_pushButton_keyboard_Max_I_2_clicked();

    void on_pushButton_keyboard_Min_P_clicked();

    void on_pushButton_Admin4G_clicked();

   // void on_pushButton_AdminOCPP_2_clicked();

    void on_pushButton_AdminDcProfile_clicked();

    void on_IPv4v6_radioButton_clicked();

    void on_IPv6_radioButton_clicked();

    void on_IPv4_radioButton_clicked();

    void on_pushButton_keyboard_APN_clicked();

    void on_pushButton_keyboard_Min_I_clicked();

    void on_pushButton_keyboard_Max_P_clicked();

    void on_pushButton_Save_charging_clicked();

    void on_pushButton_Keyboard_chargebytime_clicked();

    void on_pushButton_Keyboard_charggebyunit_clicked();

    void on_pushButton_Profile_Save_clicked();

    void on_pushButton_Profile_Back_clicked();

    void on_pushButton_Save_gsm_clicked();

    void on_pushButton_Cancel_gsm_clicked();

    void on_pushButton_WifiSetting_back_clicked();

    void on_pushButton_Setting_Back_clicked();

    void on_pushButton_PriceSetting_back_clicked();

    void on_WIFIEnable_clicked(bool checked);

    void on_EthernetEnable_clicked(bool checked);

    void on_GSMEnable_clicked(bool checked);

    void on_OCPPEnable_clicked(bool checked);

    void on_pushbutton_history_back_clicked();

    void on_pushButton_Serial_Number_clicked();
    void on_pushButton_keyboard_Serial_Number_clicked();

    void on_pushButton_Back_charging_clicked();

    void on_pushButton_FW_clicked();

    void on_pushButton_keyboard_FW_servername_clicked();

    void on_pushButton_keyboard_FW_path_clicked();



    void on_pushButton_keyboard_FW_password_clicked();

    void on_pushButton_keyboard_FW_username_clicked();

    void on_pushButton_Serial_Save_clicked();

    void on_pushButton_FW_Update_clicked();

    void on_pushbutton_history_clear_clicked();

    void on_pushbutton_history_up_clicked();

    void on_pushbutton_history_down_clicked();

    void on_pushButton_EthernetSetting_Back_clicked();

    void on_pushButton_FW_Back_clicked();

    //void on_lineEdit_Unitby_charge_cursorPositionChanged(int arg1, int arg2);

    //void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_KeyBord_TimeDate_clicked();

    void on_pushButton_Back_Display_setting_clicked();

    void on_pushButton_Save_Displaysetting_clicked();

    void on_pushButton_KeyBord_Timezone_clicked();

    void on_pushButton_KeyBord_sleeptime_clicked();

   // void on_pushButton_History_Page_2_clicked();

    void on_pushButton_Display_setting_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_Charging_psw_clicked();

    void on_pushButton_Psw_Back_clicked();

    void on_pushButton_Password_clicked();

    void on_pushButton_Network_clicked();

    void on_pushButton_Nework_back_clicked();

    void on_pushButton_Chrg_password_clicked();

    void on_pushButton_charging_confirmpass_clicked();

    void on_pushButton_ChargingSave_clicked();

  //  void on_pushButton_ChargeByPswd_clicked();

    void on_pushButton_keyboard_chr_password_clicked();

    void on_pushButton_chr_Login_clicked();

    void on_pushButton_chr_CancelLogin_clicked();

    void on_pushButton_BackAdminPsw_clicked();

    void on_pushButton_BackChargingPsw_clicked();

    void on_pushButton_SN_Back_clicked();

    void on_pushButton_Back_DuringCharging_clicked();

//    void on_pushButton_RFID_Next_clicked(bool checked);

    void on_pushButton_Error_Back_clicked();

 //   void on_pushButton_ChargeByPswd_pressed();

    void on_pushButton_RFID_Next_pressed();

 //   void on_pushButton_ALM_clicked(bool checked);

 //   void on_pushButton_ALM_clicked();

//    void on_pushButton_ALM_clicked();

    void on_pushButton_ChargeByPswd_clicked();

   // void on_pushButton_Back_charging_clicked(bool checked);

 //   void on_pushButton_chr_Login_3_clicked();

    //void on_pushButton_chr_Login_3_clicked();

    void on_pushButton_keyboard_chr_password_8_clicked();

    void on_pushButton_chr_Login_8_clicked();

//    void on_pushButton_RFID_Next_clicked();

    //void on_pushButton_chr_Login_8_pressed();

    void on_pushButton_CCS_2_clicked();

    void on_pushButton_chr_CancelLogin_8_clicked();

    void on_pushButton_keyboard_TProtection_released();

    void on_pushButton_keyboard_CutoffSoc_released();

 //   void on_checkBox_TempProtection_pressed();

   /* void on_checkBox_TempProtection_clicked(bool checked);

    void on_checkBox_CuttofSoc_clicked(bool checked);

    void on_checkBox_DoorLock_clicked(bool checked);
    */

    void on_pushButton_Load_Sharing_clicked();

    void on_pushButton_LS_Back_clicked();

    void on_pushButton_LS_update_clicked();

    void on_pushButton_keyboard_TouchInterval_clicked();

private:
    Ui::MainWindow *ui;
 //   std::unique_ptr<MODBUS> mpController;
    std::unique_ptr<Controller> mpController;
    Dcmodule p;
    MODBUS mod;

  //  CanToSerialCtrl *m_pCanToSerial;
   // PowerControl* pPowerCtrl;

  //  Charger CCS;
   QElapsedTimer * pElapsedTime;
    QElapsedTimer * pElapsedTime_2;
    widgetKeyBoard  *myKeyboard;
    Form *form_Ascii;
    Form *form_Numeric;
    QTimer          *m_pUi_DateTimer;

    MODBUS *m_mod;
    bool bTimeOut;
    Database *db;

    RFID *rf;
    QTimer      *updateTimer;
    quint32     nCount;
  //  bool bConnected_1;
    bool reconnect_flag = false;
    bool reconnect_flag_1 = false;
    void delay(int);

signals:
#ifdef DONTUSE
    void sgnSetCurrent_Limit(qint16, qint16);
#endif
    void sgnForceStop(int);
    void sgnCharger_Stop(int);
    void sgnCharging_End(int);
    void sgnCharger_TimeOUT(int);
    void sgnCharger_Start(int);
    void sgnBack(int);
    void signalPlcmod(int);
};
#endif // MAINWINDOW_H
