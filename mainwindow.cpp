#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include "dcmodule.h"
#include <QtCore>
#include <QByteArray>
#include <QSqlQuery>
#include <QSqlError>
//#include <QListWidget>
#include <QtConcurrent>
#include <QFuture>
#include <QDebug>
#include <QDateTime>
//#include"Controller.h"
#include "keypad.h"
#include "stdlib.h"
uint Imd_F = 0;
qint16 pre_status = 0;
struct Parameter set_parameter;
QDateTime UpdateTime;
extern QQueue<int> queue;
extern QQueue<int> OCPPQueue;
extern QQueue<int> can_module;
extern Charger_Status CCS;
extern Charger_Status CCS2;
extern int can_fd,can2_fd;
//extern Charger_Status AC;
 uint8_t Current_Charger_Status;
extern QSqlDatabase m_data;
Rfid_Auth RAuth;
extern struct Config_Parameter_OCPP Ocpp_Setting;
extern struct LoadSharing Sharing;
 int Sleep_Timer = 0;
 extern QQueue<int> PLC_queue;
 stChargerUI_Info ChargerUI_Info;
 extern Can_Module_Recieve CAN_RX;
 stChargerUI_Info ChargerUI_Info_2;
 extern Can_Module_Transmit  CAN_TX, CAN_TX_2;
 unsigned char touch_driver;
//#define SIXTEE
// #define THIRTEE 1 /******* 130 pin for reset I2C Pin****************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mpController(std::make_unique<Controller>())
 {
    ui->setupUi(this);
#ifdef UI_Debug
     qDebug() << "UI thread" << QThread::currentThreadId();
#endif
     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 6 > /sys/class/backlight/backlight-display/brightness"));
     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 130 > /sys/class/gpio/export"));
     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo \"out\" > /sys/class/gpio/gpio130/direction"));
     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 1 > /sys/class/gpio/gpio130/value"));
     tempbind();
     On_Module(can_fd);
 //  On_Module_2();
     if(db->Init_Database() == true)
  {
       qDebug() << "Database Init succesfully..." << endl;

      if(db->selectocpp() == true)
      {
          qDebug() << "selectocpp succesfully..." << endl;
          ui->lineEdit_URL->setText( set_parameter.URL);
          ui->lineEdit_ServerPort->setText( QString::number(set_parameter.Port));

          if(set_parameter.Ocpp_Status == 1)
          {
              ui->OCPPEnable->setChecked(1);
          }
      }
      if(db->selectethernet() == true)
      {
          qDebug() << "selectethernet succesfully..." << endl;
          ui->lineEdit_LocalIP->setText( set_parameter.IP);
          ui->lineEdit_GatwayIP->setText( set_parameter.Getway);
          ui->lineEdit_SubnetMask->setText( set_parameter.SubnetMask);

          if(set_parameter.Network == 2)
          {
              ui->EthernetEnable->setChecked(1);
              ocpp_1->EthernetConfig(set_parameter.IP,set_parameter.Getway,set_parameter.SubnetMask,true) ;
          }
      }
      if(db->selectwifi() == true)
      {
          qDebug() << "selectwifi succesfully..." << endl;
          ui->lineEdit_SSID->setText( set_parameter.ssid);
          ui->lineEdit_Password_wifi->setText(set_parameter.password);
          if(set_parameter.Network == 1)
          {
              ocpp_1->WiFiConfig(set_parameter.ssid,set_parameter.password,true);
              ui->WIFIEnable->setChecked(1);
          }
      }
      if(db->selectPriceSetting() == true)
      {
          qDebug() << "selectPriceSetting succesfully..." << endl;
          //ui->lineEdit_timeby_charge->setText( QString::number(set_parameter.time_charges));
          ui->lineEdit_Unitby_charge->setText( QString::number(set_parameter.unit_charges));
      }
      if(db->selectSetting() == true)
      {
          qDebug() << "selectSetting succesfully..." << endl;
          ui->lineEdit_OverVolt->setText( QString::number(set_parameter.Over_Voltage));
          ui->lineEdit_UnderVolt->setText( QString::number(set_parameter.Under_Voltage));
          ui->lineEdit_OverCurrCCS->setText( QString::number(set_parameter.Over_Current_ccs));
      }
      if(db->selectDC_Profile() == true)
      {
          qDebug() << "selectDC_Profile succesfully..." << endl;

          ui->lineEdit_Max_I->setText( QString::number(set_parameter.DC_IMAX));
          ui->lineEdit_Min_I->setText( QString::number(set_parameter.DC_IMin));
          ui->lineEdit_Max_V->setText( QString::number(set_parameter.DC_VMAX));
          ui->lineEdit_Min_V->setText( QString::number(set_parameter.DC_VMin));
          ui->lineEdit_Min_P->setText( QString::number(set_parameter.DC_PMin));
          ui->lineEdit_Max_P->setText( QString::number(set_parameter.DC_PMAX));
      }
      if(db->selectGSM() == true)
      {
          qDebug() << "selectGSM succesfully..." << endl;
          if(set_parameter.GSM_IPV == 2)
          {
              ui->IPv4_radioButton->setChecked(1);
          }
          else if(set_parameter.GSM_IPV == 1)
          {
              ui->IPv6_radioButton->setChecked(1);
          }
          else if(set_parameter.GSM_IPV == 0)
          {
              ui->IPv4v6_radioButton->setChecked(1);
          }

          ui->lineEdit_APN->setText(set_parameter.GSM_APN);
          if(set_parameter.Network == 3)
          {
              ui->GSMEnable->setChecked(1);
              ocpp_1->GSM_connect(set_parameter.GSM_APN,set_parameter.GSM_IPV,true);
          }
      }
      if(db->selectOCPP_Key() == true)
      {
          qDebug() << "selectOCPP_Key succesfully..." << endl;
      }
      if(db->selectDisplay() == true)
      {

          ui->horizontalSlider->setValue(set_parameter.Brightness);
          ui->lineEdit_SleepTime->setText(QString::number(set_parameter.SleepTime));
          ui->lineEdit_TimeZone->setText(QString::number(set_parameter.TimeOffset,'f',2));
          int multipy = 1;
          int num = set_parameter.TimeOffset;
          int decimal = set_parameter.TimeOffset;
          while(num != 0)
          {
              num = (int)num/10;
              multipy =  multipy*10;
          }
          TMZOffset = (set_parameter.TimeOffset*100 - decimal*100)*60;
          TMZOffset += decimal*3600;
               qDebug() << "selectDisplay succesfully..." << TMZOffset <<endl;
      }
     if(db->SelectFirmwareUpgrade() == true)
     {
         qDebug() << "SelectFirmwareUpgrade succesfully..." << endl;
         ui->lineEdit_FW_servername->setText(set_parameter.FW_SN);
         ui->lineEdit_FW_path->setText(set_parameter.FW_Path);
         ui->lineEdit_FW_username->setText(set_parameter.FW_UN);
         ui->lineEdit_FW_password->setText(set_parameter.FW_PW);
     }
     if(db->selecAdmin_Setting(1) == true)
     {
         qDebug() << "select tempreture thresold..." << endl;
         ui->lineEdit_TempProtection->setText(QString::number(set_parameter.tempThresold));
         ui->checkBox_TempProtection->setChecked(set_parameter.tempThresold_ED);
     }
     if(db->selecAdmin_Setting(2) == true)
     {
         qDebug() << "select tempreture cuttoffoc..." << endl;
        ui->lineEdit_EndTime_CuttOfSoc->setText(QString::number(set_parameter.cutoffsoc));
        ui->checkBox_CuttofSoc->setChecked(set_parameter.cutoffsoc_ED);
     }
     if(db->selecAdmin_Setting(3) == true)
     {
         qDebug() << "select Door Lock..." << set_parameter.DoorlOCK_ED<<endl;
         ui->checkBox_DoorLock->setChecked(set_parameter.DoorlOCK_ED);
     }
     if(db->selecAdmin_Setting(4) == true)
     {
         qDebug() << "Serial Number..." << endl;
         ui->lineEdit_Serial_Number->setText(set_parameter.Serial_Number);
     }
     if(db->selecAdmin_Setting(5) == true)
     {
         qDebug() << "Test Mode..." << set_parameter.TestMode_ED<<endl;
         ui->checkBox_TestMode->setChecked(set_parameter.TestMode_ED);
         if(set_parameter.TestMode_ED == false)
         {
             QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>EV</span></p></body></html>"};
             ui->label_Test->setText(temp);
         }
         else
         {
             QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>TEST</span></p></body></html>"};
             ui->label_Test->setText(temp);
         }
     }
     if(db->selecAdmin_Setting(6) == true)
     {
         qDebug() << "Ground Fault..." <<set_parameter.GroundFault_ED<< endl;
         ui->checkBox_GroundFault->setChecked(set_parameter.GroundFault_ED);
     }
     if(db->selecAdmin_Setting(7) == true)
     {
         qDebug() << "Isulation Fault..." <<set_parameter.IsolationFault_ED<<endl;
         ui->checkBox_IsolationFault->setChecked(set_parameter.IsolationFault_ED);
     }
     if(db->selecAdmin_Setting(8) == true)
     {
         qDebug() << "TouchInterval_ED..." <<set_parameter.TouchInterval_ED<<endl;

         ui->lineEdit_TouchInterval->setText(QString::number(set_parameter.TouchInterval));
         ui->checkBox_TouchInterval->setChecked(set_parameter.TouchInterval_ED);         
     }
     if(db->selecAdmin_Setting(9) == true)
     {
         qDebug() << "PMIndividual_ED..." <<set_parameter.PMIndividual_ED<< endl;
         ui->checkBox_PMIndividual->setChecked(set_parameter.PMIndividual_ED);
     }
     if(db->selecAdmin_Setting(10) == true)
     {
         qDebug() << "LoadSharing_ED..." <<set_parameter.LoadSharing_ED<<endl;
         Sharing.Is_LoadSharing = set_parameter.LoadSharing_ED;
         ui->checkBox_LoadSharing->setChecked(set_parameter.LoadSharing_ED);
     }
    /* if(db->selecAdmin_Setting(11) == true)
     {
         qDebug() << "PreSLoadsharing_ED ..." <<set_parameter.PreSLoadsharing_ED<<endl;
         Sharing.Pre_LoadSharing = set_parameter.PreSLoadsharing_ED;
         ui->checkBox_PreSLoadsharing->setChecked(set_parameter.PreSLoadsharing_ED);
     }
     if(db->selecAdmin_Setting(12) == true)
     {
         qDebug() << "PostSLSharing_ED ..." <<set_parameter.PostSLSharing_ED<<endl;
         Sharing.During_Loadsharing = set_parameter.PostSLSharing_ED;
         ui->checkBox_PostSLSharing->setChecked(set_parameter.PostSLSharing_ED);
     }*/
  }
    /************************** Menubar *************************/
    On_Module(can2_fd);
     ui->label_car->setPixmap( QPixmap( ":/images/Welcome screen.png"));
     ui->label_car->setScaledContents( true );
     ui->label_car->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    /********************** Admin Image ***************************************/

     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("systemctl mask serial-getty@tty1.service"));
 //  QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("ip link set dev eth1 down"));

     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("systemctl stop serial-getty@tty1.service"));
     QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("systemctl disable serial-getty@tty1.service"));

    ui->pushButton_AdminIcon->setIcon(QIcon(":/images/Setting-1.png"));
    ui->pushButton_AdminIcon->setIconSize(QSize(90,62));

    /********************************************** BackGround Image *********************************/

    ui->stackedWidget->setStyleSheet("background-color:rgb(49, 68, 82)");
    /********************** CCS Finish Button********************************/
        connect(mpController.get(), &Controller::onWorkFinished,
            this, &MainWindow::workFinished);

        connect(mpController.get(), &Controller::onWorkProgress,
            this, &MainWindow::ACGunStatus);

#ifdef PLC_THREAD
        connect(mpController.get(), &Controller::onComboPlc,
            this, &MainWindow::CCS_relay_status);
#endif
    ocpp_1 = new OCPP(this);
    ocpp_1->Init();

    p.Timer_Init();
    connect(this, SIGNAL(sgnCharger_Start(int)), this, SLOT(Start_Charger(int)));
    connect(ocpp_1, SIGNAL(RmtCharger_Start(int)), this, SLOT(Remot_Start_Charger(int)));
    connect(ocpp_1, SIGNAL(RmtCharger_Stop(int)), this, SLOT(Remot_Stop_Charger(int)));

    QTimer::singleShot(7000, this, SLOT(StartRemoteApp()));
    nCount = 0;
    memset(&ChargerUI_Info, 0, sizeof(stChargerUI_Info));
    memset(&ChargerUI_Info_2, 0, sizeof(stChargerUI_Info));
    bTimeOut = false;
    pElapsedTime = nullptr;
    pElapsedTime_2 = nullptr;
    fd = open("/dev/watchdog0", O_WRONLY);
    ioctl(fd, WDIOC_SETTIMEOUT, &timeout);

    QTimer* timer1= new QTimer(this);
    connect(timer1, SIGNAL(timeout()),this,SLOT(TimeRead()));
    timer1->start(1000);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::TimeRead(){

    QString t = QDateTime::currentDateTime().addSecs(TMZOffset).toString("yyyy-MM-ddThh:mm:ss");
    ui->label_Time->setText(t);
    if(CCS.Tempreture_exhaust != 0)
    {
      QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>"+QString::number(CCS.Tempreture_exhaust) + " C</span></p></body></html>"};
      ui->label_TEx->setText(temp);
    }   

    if(set_parameter.TouchInterval_ED == true)
    {
        if(++touch_driver > set_parameter.TouchInterval)
        {
            if(touch_driver == (set_parameter.TouchInterval+1))
            {
                 QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 0 > /sys/class/gpio/gpio130/value"));
            }
            else if(touch_driver == (set_parameter.TouchInterval+2))
            {
                 QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 1 > /sys/class/gpio/gpio130/value"));
                  touch_driver = 0;
            }
        }
    }
    static int8_t Netwok_Status,ocpp_status;
    ioctl(fd, WDIOC_KEEPALIVE, 0);
    if(++Sleep_Timer >= set_parameter.SleepTime)
    {
        if(sleep_Mode  == false)
        {
            HMI_sleep_Mode();
        }        
        Sleep_Timer = set_parameter.SleepTime;
    }
    else
    {
        if(sleep_Mode == true)
        {
            HMI_WakeUP_Mode();
        }
    }

    if(currentpage == 2)
    {
        if(CCS.SCAN_TAGID == 2)
        {
             ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#eeeeec;'>RFID Read Succesfully</span></p><p><span style=' font-weight:600; color:#eeeeec;'>Please Wait..</span></p></body></html>"));

            if(set_parameter.check_OCPP == 1)
            {
                if(CCS.Status == Preparing && Current_Charger_Status == StartScreen_1)
                {
                    CCS.TadId = CCS.RfidTagId;
                    OCPPQueue.enqueue(G1_Authorise);
                }
                else if(CCS2.Status == Preparing && Current_Charger_Status == StartScreen_2)
                {
                    CCS2.TadId = CCS.RfidTagId;
                    OCPPQueue.enqueue(G2_Authorise);
                }
                else if(CCS.Status == Charging && Current_Charger_Status == StopScreen_1)
                {
                    if(CCS.TadId == CCS.RfidTagId)
                    {
                        OCPPQueue.enqueue(G1_StopTransaction);
                        ChargerUI_Info.ui_Charger_ErrorCode = U_StopByRfid;
                    }
                }
                else if(CCS2.Status == Charging && Current_Charger_Status == StopScreen_2)
                {
                    if(CCS2.TadId == CCS.RfidTagId)
                    {
                         OCPPQueue.enqueue(G2_StopTransaction);
                         ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByRfid;
                    }
                }
            }
            else if((Ocpp_Setting.LocalAuthListEnbl == true) && (Ocpp_Setting.LocalAuthOffln == true))
            {
                if(CCS.Status == Preparing && Current_Charger_Status == StartScreen_1)
                {
                   CCS.TadId = CCS.RfidTagId;
                   if(db->SearchTagId(CCS.RfidTagId) == true)
                   {
                      Start_Charger(1);
                   }
                }
                else if(CCS2.Status == Preparing && Current_Charger_Status == StartScreen_2)
                {
                    CCS2.TadId = CCS.RfidTagId;
                    if(db->SearchTagId(CCS.RfidTagId) == true)
                    {
                      Start_Charger(2);
                    }
                }
                else if(CCS.Status == Charging && Current_Charger_Status == StopScreen_1)
                {
                    CCS.TadId = CCS.RfidTagId;
                    if(db->SearchTagId(CCS.RfidTagId) == true)
                    {
                     // Stop_Charger(1);
                        ChargerUI_Info.ui_Charger_ErrorCode = U_StopByRfid;
                        CCS.Reson = Local;
                    }
                }
                else if(CCS2.Status == Charging && Current_Charger_Status == StopScreen_2)
                {
                    CCS2.TadId = CCS.RfidTagId;
                    if(db->SearchTagId(CCS.RfidTagId) == true)
                    {
                        ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByRfid;
                        CCS2.Reson = Local;
                    }
                }
                //OCPPQueue.enqueue(Tagid_search);
            }                      
            else
            {
                ui->label_charging_validation->setText("Local Authorisation Offline");
            }
            CCS.RfidTagId.clear();
            CCS.SCAN_TAGID = 1;
        }
    }
    else if(currentpage == 5 ) //|| CCS.Status == Charging)
    {
        if(CCS.SCAN_TAGID != -1)
        {
            CCS.SCAN_TAGID = 1;
        }        
    }
   if(Netwok_Status != set_parameter.Network_status)
    {
        if(CCS.SCAN_TAGID != -1)
        {
            CCS.SCAN_TAGID =1;
        }
        if(set_parameter.Network_status == 1)
        {
            ui->label_network->setPixmap( QPixmap( ":/images/WIFI-1.png") );
            ui->label_network->setScaledContents( true );
            ui->label_network->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        }
        else
        {
            ui->label_network->setPixmap( QPixmap( ":/images/WIFI-2.png") );
            ui->label_network->setScaledContents( true );
            ui->label_network->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        }        
        Netwok_Status = set_parameter.Network_status;
    }
    else if(ocpp_status != set_parameter.check_OCPP)
    {
        if(set_parameter.check_OCPP == 1)
        {
            ui->label_ocpp->setPixmap( QPixmap( ":/images/CLUD-1.png") );
            ui->label_ocpp->setScaledContents( true );
            ui->label_ocpp->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
            ui->label_CCS_Status->setText("No Error");
        }
        else
        {
            ui->label_ocpp->setPixmap( QPixmap( ":/images/CLUD-2.png") );
            ui->label_ocpp->setScaledContents( true );
            ui->label_ocpp->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
            if(set_parameter.Ocpp_Status == 1)
            {
                ui->label_CCS_Status->setText("OCPP Error");
            }
        }
        ocpp_status = set_parameter.check_OCPP;
    }
    else
    {
        if(CCS.SCAN_TAGID != -1)
        {
            CCS.SCAN_TAGID =1;
        }
        if((ChargerUI_Info_2.ui_Charger_ErrorCode == C_HardReset_Done) && (ChargerUI_Info.ui_Charger_ErrorCode == C_HardReset_Done))
        {
//          PLC_queue.enqueue(HardReset_state);
//          PLC_queue.enqueue(HardReset_state_2);
            CAN_TX_2.HardReset = 0xA5;
            CAN_TX.HardReset = 0xA5;
            p.IO_transmit();
            p.IO2_transmit();
            CAN_TX_2.HardReset = 0;
            CAN_TX.HardReset = 0;
            QProcess::execute("/bin/bash", QStringList() << "-c" << QString("reboot"));
        }
    }
   Charging_calculation();
 }

void MainWindow::TagId_Search(QString tagid)
{
    bool ok ;
            ok = db->SearchTagId(tagid);

    if(ok == true)
    {
         qDebug() << "true \n";
         if(CCS.Status == Preparing)
         {
             if(CCSStart()==1)
             {
                  ui->stackedWidget->setCurrentIndex(5);
                 //OCPPQueue.enqueue(G1_Authorise);
             }
         }
         else if(CCS.Status == Charging)
         {
         //    emit pDcComboPLC_1 -> sgnCCS_Relay(G_Discharging);
             CCSBILLING(&CCS,ChargerUI_Info);
             CCS.Reson = Local;     
         }
       //  CCS.SCAN_TAGID = 0;
         ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#eeeeec;'>Tag id Success </span></p><p><span style=' font-weight:600; color:#eeeeec;'>Start charging </span></p></body></html>"));
    }
    else
    {
           ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#eeeeec;'>Tag id Failure </span></p><p><span style=' font-weight:600; color:#eeeeec;'>try Again </span></p></body></html>"));
            qDebug() << "Failed \n";
    }
    return;
}
void MainWindow::ACGunStatus(int mGun)
{
    static int bmGun;
    if(bmGun != mGun)
    {
        bmGun = mGun;
    }
    else
    {
        return;
    }
    qDebug()<< "AC GUN status : "<< mGun <<endl;
    if(mGun != 0)
    {
       if(mGun == M_Over_Voltage )
       {
           ui->label_CCS_Status->setText("Over voltage");
           CCS.Reson = Other;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
           ChargerUI_Info.ui_Charger_ErrorCode = M_Over_Voltage;
           ChargerUI_Info_2.ui_Charger_ErrorCode = M_Over_Voltage;
       }
       else if(mGun == M_Under_Voltage )
       {
           ui->label_CCS_Status->setText("Under voltage");
           CCS.Reson = Other;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
           ChargerUI_Info.ui_Charger_ErrorCode = M_Under_Voltage;
           ChargerUI_Info_2.ui_Charger_ErrorCode = M_Under_Voltage;
       }
       else if(mGun == M_Over_Current)
       {
           ui->label_CCS_Status->setText("Over Current CCS-02");
           CCS.Reson = Other;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
           ChargerUI_Info.ui_Charger_ErrorCode = M_Over_Current;
           ChargerUI_Info_2.ui_Charger_ErrorCode = M_Over_Current;
       }       
       else if(mGun == I_O_GNDFalut)
       {
           ui->label_CCS_Status->setText("Ground Fault Detection....");
           CCS.Reson = Other;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
           ChargerUI_Info.ui_Charger_ErrorCode = I_O_GNDFalut;
           ChargerUI_Info_2.ui_Charger_ErrorCode = I_O_GNDFalut;
       }
       /*else if(mGun == I_O_Isolation_Warning)
       {
           ui->label_CCS_Status->setText("Isolation Warning");
           CCS.Reson = Other;
           // ChargerUI_Info.ui_Charger_ErrorCode = I_O_GNDFalut;
           //  CCS_relay_status(G_faulted);
       }
       else if(mGun == I_O_Isolation_Fault)
       {
           ui->label_CCS_Status->setText("Isolation Fault Gun 1");
           CCS.Reson = Local;
           ChargerUI_Info.ui_Charger_ErrorCode = I_O_Isolation_Fault;
           CCS_relay_status(G_faulted);
       }
       else if(mGun == I2_O_Isolation_Fault)
       {
           ui->label_CCS_Status->setText("Isolation Fault Gun 2");
           CCS.Reson = Local;
           ChargerUI_Info_2.ui_Charger_ErrorCode = I_O_Isolation_Fault;
           CCS_relay_status(G_faulted_2);
       }*/
       else if(mGun == I_O_EMPress)
       {
           ui->label_CCS_Status->setText("Emergency Switch press");
           CCS2.Reson = CCS.Reson = EmergencyStop;
           ChargerUI_Info.ui_Charger_ErrorCode = I_O_EMPress;
           ChargerUI_Info_2.ui_Charger_ErrorCode = I_O_EMPress;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
       }
       else if(mGun == I_O_ResetKey)
       {
           ui->label_CCS_Status->setText("Reset Key Activate");           
          Remot_Stop_Charger(33);
          //    CCS_relay_status(G_faulted);
          //    CCS_relay_status(G_faulted_2);
       }
       else if(mGun == I_O_DoorLock)
       {
           ui->label_CCS_Status->setText("Door Open");
           CCS.Reson = Local;
           ChargerUI_Info.ui_Charger_ErrorCode = I_O_DoorLock;
           ChargerUI_Info_2.ui_Charger_ErrorCode = I_O_DoorLock;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
       }
       else if(mGun == CAN_Communication_Error)
       {
           ui->label_CCS_Status->setText("CAN0 Communication Error");
           CCS.Reson = Local;
           CCS_relay_status(G_faulted);
       }
       else if(mGun == CAN2_Communication_Error)
       {
           ui->label_CCS_Status->setText("CAN1 Communication Error");
           CCS2.Reson = Local;
           CCS_relay_status(G_faulted_2);
       }
      /* else if(mGun == EV_Disconnected)
       {
           ui->label_CCS_Status->setText("EV1 Disconnected");
            CCS.Reson = EVDisconnected;
            CCS_relay_status(G_faulted);
       } */
       else if(mGun == M_MeterFailure)
       {
           ui->label_CCS_Status->setText("EM meter failure");
            CCS.Reson = Other;
            ChargerUI_Info.ui_Charger_ErrorCode = M_MeterFailure;
            CCS_relay_status(G_faulted);
       }
       else if(mGun == P_Connect)
       {
          CCS_relay_status(G_Connected);
       }
       else if(mGun == P_Charging)
       {
           CCS_relay_status(G_charging);
       }
       else if(mGun == P_Disconnect)
       {
          CCS_relay_status(G_Discharging);
       }
       else if(mGun == P_Available || mGun == O_Available)
       {
           CCS_relay_status(G_Available);
       }
       else if(mGun == I_O_RCDdetect)
       {
           ui->label_CCS_Status->setText("RCD Fail detect");
           ChargerUI_Info.ui_Charger_ErrorCode = ChargerUI_Info_2.ui_Charger_ErrorCode = I_O_RCDdetect;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
       }
       else if(mGun == M_PowerSwitchFailure)
       {
           ui->label_CCS_Status->setText("Power Loss");
           ChargerUI_Info.ui_Charger_ErrorCode = M_PowerSwitchFailure;
           CCS_relay_status(G_faulted);
           CCS_relay_status(G_faulted_2);
       }
       else if(mGun == I_O_WaitForACMains)
       {
           ui->label_CCS_Status->setText("Wait, Resuming Operation");
           ChargerUI_Info.ui_Charger_ErrorCode = I_O_WaitForACMains;
            CCS_relay_status(G_faulted);
            CCS_relay_status(G_faulted_2);
       }
      /* else if(mGun == COmm_1_232_Fail)
       {
           ui->label_CCS_Status->setText("RS 232  1 Comm. Fail");
           ChargerUI_Info.ui_Charger_ErrorCode = COmm_1_232_Fail;
           CCS_relay_status(G_faulted);
       }
       else if(mGun == COmm_2_232_Fail)
       {
           ui->label_CCS_Status->setText("RS232 2 Comm. Fail");
           ChargerUI_Info_2.ui_Charger_ErrorCode = COmm_2_232_Fail;
           CCS_relay_status(G_faulted_2);
       }*/
       else if(mGun == P2_Connect)
       {
          CCS_relay_status(G_Connected_2);
       }
       else if(mGun == P2_Charging)
       {
           CCS_relay_status(G_charging_2);
       }
       else if(mGun == P2_Disconnect)
       {
          CCS_relay_status(G_Discharging_2);
       }
       else if(mGun == P2_Available || mGun == O2_Available)
       {
           CCS_relay_status(G_Available_2);
       }
       else if(mGun == I_O_NoError)
       {                      
           if((set_parameter.Ocpp_Status == 1) && (set_parameter.check_OCPP == 0))
           {
               ui->label_CCS_Status->setText("OCPP Error....");
           }
           else
           {
               ui->label_CCS_Status->setText("NO Error....");
           }

           CCS.Error = CCS2.Error = NoError;
           if(CCS.start != Charging_Start)
           {
                CCS_relay_status(G_Available);
                PLC_queue.enqueue(Report_state);
           }
           if(CCS2.start != Charging_Start)
           {
                CCS_relay_status(G_Available_2);
                PLC_queue.enqueue(Report_state_2);
           }
           return;
       }
    }
}
void MainWindow::OpenSerial()
{    
   // tempbind_2();
    qDebug()<<"can2 fd"<<can2_fd<<endl;
    On_Module(can2_fd);
}
void MainWindow::delay(int seconds){
    QTime dieTime= QTime::currentTime().addMSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::StartRemoteApp()
{   
    emit mpController->requestWork(10);
    emit mpController->Plc_relay(10);
    emit mpController->ComboPlc_Request(10);
}
void MainWindow::Start_Charger(int Gun)
{
  if((CCS.start == Charging_Stop) && (Gun == 1))
    {            
        SAFE_DELETE(pElapsedTime)                
        Sharing.G1_Need_Tb_LS = LS_No;
        memset(&ChargerUI_Info, 0, sizeof(stChargerUI_Info));
        pElapsedTime = new QElapsedTimer;
        pElapsedTime->start();
        QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G1 Processing...</span></p></body></html>"};
        ui->label_25->setText(temp);
        if(set_parameter.TestMode_ED == false)
        {
            CCS.start= Try_To_Start;
            PLC_queue.enqueue(Start_Charging);
        }
        else
        {
            CCS.start= Charging_Start;
            can_module.enqueue(Q_Charging);
            can_module.enqueue(Pm_On);
        }
        CCS.Start_Energy = CCS.Energy;
        CCS.StartTime = QDateTime::currentDateTime().addSecs(TMZOffset);
        ui->stackedWidget->setCurrentIndex(5);
        Current_Charger_Status = ChargingScreen_1;
    }
#ifdef M2
   else if((CCS2.start == Charging_Stop) && (Gun == 2))
    {
        SAFE_DELETE(pElapsedTime_2)
        Sharing.G2_Need_Tb_LS = LS_No;
        memset(&ChargerUI_Info_2, 0, sizeof(stChargerUI_Info));
        pElapsedTime_2 = new QElapsedTimer;
        pElapsedTime_2->start();
        QString temp1{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G2 Processing...</span></p></body></html>"};
        ui->label_25->setText(temp1);
        CCS2.Start_Energy = CCS2.Energy;        
        CCS2.StartTime = QDateTime::currentDateTime().addSecs(TMZOffset);
        if(set_parameter.TestMode_ED == false)
        {
            CCS2.start= Try_To_Start;
            PLC_queue.enqueue(Start_Charging_2);
        }
        else
        {
            CCS2.start= Charging_Start;
            can_module.enqueue(Q_Charging_2);
            can_module.enqueue(Pm_On_2);
        }
        ui->stackedWidget->setCurrentIndex(5);
        Current_Charger_Status = ChargingScreen_2;
    }
#endif  
}
void MainWindow::Remot_Start_Charger(int Gun)
{
    if((CCS.start == Charging_Stop) && (Gun == 1))
     {
//        if(Gun == 20)
//        {
//             ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#ffff00;'>RFID card Read Succesfully</span></p><p><span style=' font-weight:600; color:#ffff00;'>Please wait for charging</span></p></body></html>"));
//        }
         SAFE_DELETE(pElapsedTime)
         Sharing.G1_Need_Tb_LS = LS_No;
         memset(&ChargerUI_Info, 0, sizeof(stChargerUI_Info));

         pElapsedTime = new QElapsedTimer;
         pElapsedTime->start();

         if(set_parameter.TestMode_ED == false)
         {
             CCS.start= Try_To_Start;
             PLC_queue.enqueue(Start_Charging);
         }
         else
         {
             CCS.start= Charging_Start;
             can_module.enqueue(Q_Charging);
         }

         CCS.Start_Energy = CCS.Energy;
         CCS.StartTime = QDateTime::currentDateTime().addSecs(TMZOffset);

         QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G1 Processing...</span></p></body></html>"};
         ui->label_25->setText(temp);
         ui->stackedWidget->setCurrentIndex(5);
         Current_Charger_Status = ChargingScreen_1;
     }
#ifdef M2
     else if((CCS2.start == Charging_Stop) && (Gun == 2))
     {
         SAFE_DELETE(pElapsedTime_2)
         Sharing.G2_Need_Tb_LS = LS_No;
         memset(&ChargerUI_Info_2, 0, sizeof(stChargerUI_Info));
         pElapsedTime_2 = new QElapsedTimer;
         pElapsedTime_2->start();
         if(set_parameter.TestMode_ED == false)
         {
             CCS2.start= Try_To_Start;
             PLC_queue.enqueue(Start_Charging_2);
         }
         else
         {
             CCS2.start= Charging_Start;
             can_module.enqueue(Q_Charging_2);
         }
         CCS2.Start_Energy = CCS2.Energy;
         CCS2.StartTime = QDateTime::currentDateTime().addSecs(TMZOffset);
         QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G2 Processing...</span></p></body></html>"};
         ui->stackedWidget->setCurrentIndex(5);
         Current_Charger_Status = ChargingScreen_2;
         ui->label_25->setText(temp);
     }    
#endif
    else if(Gun == 3)
    {
         ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'>RFID Invalid</span></p><p><span style=' font-weight:600; color:#ffff00;'>Please Try Again</span></p></body></html>"));
    }
     else
      {
        ui->label_Stop_reason->setText("Please Remove the gun and Try again..");
      }
}
void MainWindow::Stop_Charger(int Gun)
{        
   if((CCS.start == Charging_Start) && (Gun == 1))
   {
       if(set_parameter.TestMode_ED == false)
       {
          PLC_queue.enqueue(Stop_Charging);
       }
       else
       {
          can_module.enqueue(Pm_Off);
          can_module.enqueue(Q_Available);
       }
       ChargerUI_Info.ui_ElapsedTime = (quint32)(pElapsedTime->elapsed());
   }
#ifdef M2
   if((CCS2.start == Charging_Start) && (Gun == 2))
   {
       if(set_parameter.TestMode_ED == false)
       {
          PLC_queue.enqueue(Stop_Charging_2);
       }
       else
       {
          can_module.enqueue(Pm_Off_2);
          can_module.enqueue(Q_Available_2);
       }       
       ChargerUI_Info_2.ui_ElapsedTime = (quint32)(pElapsedTime_2->elapsed());
   }
#endif
}
void MainWindow::Remot_Stop_Charger(int nMode)
{
    if(nMode == 20)
    {
        if(Current_Charger_Status == StopScreen_1)
        {
            ChargerUI_Info.ui_Charger_ErrorCode = U_StopByRfid;
            CCS.Reson = Local;
        }
        else if(Current_Charger_Status == StopScreen_2)
        {
            ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByRfid;
            CCS2.Reson = Local;
        }
        ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#ffff00;'>RFID card Read Succesfully</span></p><p><span style=' font-weight:600; color:#ffff00;'>Please wait for stop charging</span></p></body></html>"));
    }
#ifdef M2
    /*else if(nMode == 21)
    {
        ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByRfid;
        CCS2.Reson = Local;
    }*/
#endif
    else if(nMode == 1)
    {
         ChargerUI_Info.ui_Charger_ErrorCode = U_StopByRemote;       
         CCS.Reson = Remote;
    }
#ifdef M2
    else if(nMode == 2)
    {
         ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByRemote;       
         CCS2.Reson = Remote;         
    }
    else if(nMode == 3)
    {
         ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'>RFID Invalid</span></p><p><span style=' font-weight:600; color:#ffff00;'>Please Try Again</span></p></body></html>"));
    }
    else if(nMode == 55)
    {
        if(CCS2.start == Charging_Start)
        {
            ChargerUI_Info_2.ui_Charger_ErrorCode = C_SoftReset;
            CCS2.Reson = SoftReset;
        }
        if(CCS.start == Charging_Start)
        {
            ChargerUI_Info.ui_Charger_ErrorCode = C_SoftReset;
            CCS.Reson = SoftReset;
        }
    }
    else if(nMode == 33)
    {
        if(CCS2.start == Charging_Start && set_parameter.check_OCPP == true)
        {
            ChargerUI_Info_2.ui_Charger_ErrorCode = C_HardReset;
            CCS2.Reson = HardReset;
        }
        else
        {
            ChargerUI_Info_2.ui_Charger_ErrorCode = C_HardReset_Done;
        }
        if(CCS.start == Charging_Start && set_parameter.check_OCPP == true)
        {
            ChargerUI_Info.ui_Charger_ErrorCode = C_HardReset;
            CCS.Reson = HardReset;
        }
        else
        {
            ChargerUI_Info.ui_Charger_ErrorCode = C_HardReset_Done;
        }
    }
    else if(nMode == 56)
    {
        if(CCS.start == Charging_Start)
        {
            ChargerUI_Info.ui_Charger_ErrorCode = C_HardReset_Done;
        }

    }
    else if(nMode == 57)
    {                
            ChargerUI_Info_2.ui_Charger_ErrorCode = C_HardReset_Done;
    }
    else if(nMode == 76)
    {
        if(CCS2.start == Charging_Start)
        {
            ChargerUI_Info_2.ui_Charger_ErrorCode = C_ChangeAvailibility;
        }
        else
        {
            ACGunStatus(P2_Available);
        }
    }
    else if(nMode == 75)
    {
        if(CCS.start == Charging_Start)
        {
            ChargerUI_Info.ui_Charger_ErrorCode = C_ChangeAvailibility;
        }
        else
        {
            ACGunStatus(P_Available);
        }
    }
    else if(nMode == 78)
    {
            ACGunStatus(O2_Available);
    }
    else if(nMode == 77)
    {
            ACGunStatus(O_Available);
    }
    qDebug()<<"nMode"<<nMode <<endl;
#endif
    nMode = 0;
}
void MainWindow::End_Charger(void)
{
    PLC_queue.enqueue(HardReset_state);
    QString temp{"<html><head/><body><p><span style=' color:#ffff00;'>Done</span></p></body></html>"};
    ui->label_67->setText(temp);
    waitForResuming = false;
}
void MainWindow::LoadSharingStatus(void)
{
    if(CCS.Status == Available)
    {
        Sharing.G1_Is_Available_LS = LS_Available;
    }
    qDebug()<<"CCS Gun1 Status : "<<CCS.Status<<endl;
}
void MainWindow::LoadSharingStatus_2(void)
{
    if(CCS2.Status == Available)
    {
        Sharing.G2_Is_Available_LS = LS_Available;
    }
    qDebug()<<"CCS Gun2 Status : "<<CCS2.Status<<endl;
}
void MainWindow::End_Charger_2(void)
{
    PLC_queue.enqueue(HardReset_state_2);
    QString temp{"<html><head/><body><p><span style=' color:#ffff00;'>Done</span></p></body></html>"};
    ui->label_67->setText(temp);
    waitForResuming = false;
}
void MainWindow::CCS_relay_status(int status)
{
    if(status == G_Connected)
    {
        if(set_parameter.Availibility == 100 || set_parameter.Availibility == 101)
        {
            CCS.Status = Unavailable;
            ui->Status->setText("Unavailable");
            ui->pushButton_CCS->setIcon(QIcon(":/images/NGUN-1.png"));
            qDebug()<<"Gun1 Unavailable"<<endl;            
        }
        else
        {
            CCS.Status = Preparing;
            qDebug()<<"Gun1 Available"<<endl;
            ui->pushButton_CCS->setIcon(QIcon(":/images/NGUN-3.png"));
            ui->Status->setText("Connected");
        }
        Sharing.G1_Is_Available_LS = LS_NotAvailable;
        reconnect_flag = false;
        OCPPQueue.enqueue(G1_StatusNotification);        
        ui->label_CCS_Amount->setText(QString::number(0 ,'f',2));
        ui->label_CCS_Time_Front->setText(QString::number(0 ,'f',2));
        if(Sharing.Is_LoadSharing == true && Sharing.G2_Need_Tb_LS == LS_Active)
        {
            Sharing.G2_Need_Tb_LS = LS_No;
            CAN_TX_2.Load_Sharing = false;
            can_module.enqueue(Pm_Off);
        }
        if(CCS.Error == NoError)
        {
             ui->label_CCS_Status->setText("No Error..");
        }
    }
    else if(status == G_Discharging)
    {
        CCS.EndTime = QDateTime::currentDateTime().addSecs(TMZOffset);
        OCPPQueue.enqueue(G1_StopTransaction);
        OCPPQueue.enqueue(G1_StatusNotification);
        if(CCS.Error == NoError)
        {
            CCS.Status = Finishing;
        }

        ui->Status->setText("Finished");
     //   PLC_queue.enqueue(Report_state);
    }
    else if(status == G_EVDisconnected)
    {
        CCS.EndTime = QDateTime::currentDateTime().addSecs(TMZOffset);
        OCPPQueue.enqueue(G1_StopTransaction);
        OCPPQueue.enqueue(G1_StatusNotification);
        CCS.Status = Finishing;
        ui->Status->setText("EVDisconnect");
    }
    else if(status == G_charging)
    {
        CCS.Status = Charging;
        CCS.start  = Charging_Start;
        reconnect_flag =0;
        OCPPQueue.enqueue(G1_StartTransaction);
        OCPPQueue.enqueue(G1_StatusNotification);
        ui->Status->setText("Charging");
        Sharing.G1_Is_Available_LS = LS_NotAvailable;
        ui->pushButton_CCS->setIcon(QIcon(":/images/NGUN-4.png"));
        QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G1 Charging...</span></p></body></html>"};
        ui->label_25->setText(temp);
    }
    else if(status == G_faulted)
    {
        ui->Status->setText("Faulted");
        ui->pushButton_CCS->setIcon(QIcon(":/images/NGUN-2.png"));
        CCS.Status = Faulted;
        OCPPQueue.enqueue(G1_StatusNotification);
    }
    else if(status == G_Available)
    {
        if(set_parameter.Availibility == 100 || set_parameter.Availibility == 101)
        {
            CCS.Status = Unavailable;
            ui->Status->setText("Unavailable");
            qDebug()<<"Gun1 Unavailable"<<endl;
            Sharing.G1_Is_Available_LS = LS_NotAvailable;
        }
        else
        {
            CCS.Status = Available;
            qDebug()<<"Gun1 Available"<<endl;
            ui->Status->setText("Available");
        }

        QTimer::singleShot(300000, this, SLOT(LoadSharingStatus()));
        ui->pushButton_CCS->setIcon(QIcon(":/images/NGUN-1.png"));
        OCPPQueue.enqueue(G1_StatusNotification);
        if(ui->label_CCS_Status->text() == "Please Remove the gun1 and Try again..")
        {
          ui->label_CCS_Status->setText("No Error");
        }
    }
#ifdef M2
    else if(status == G_Connected_2)
    {
        if(set_parameter.Availibility == 100 || set_parameter.Availibility == 102)
        {
            CCS2.Status = Unavailable;
            ui->Status_2->setText("Unavailable");
            ui->pushButton_CCS_2->setIcon(QIcon(":/images/NGUN-1.png"));
            qDebug()<<"Gun2 Unavailable"<<endl;
        }
        else
        {
            CCS2.Status = Preparing;
            qDebug()<<"Gun2 Available"<<endl;
            ui->pushButton_CCS_2->setIcon(QIcon(":/images/NGUN-3.png"));
            ui->Status_2->setText("Connected");
        }
        Sharing.G2_Is_Available_LS = LS_NotAvailable;
         reconnect_flag_1 = false;
        OCPPQueue.enqueue(G2_StatusNotification);        
        if(Sharing.Is_LoadSharing == true && Sharing.G1_Need_Tb_LS == LS_Active)
        {
            Sharing.G1_Need_Tb_LS = LS_No;
            CAN_TX_2.Load_Sharing = false;
            can_module.enqueue(Pm_Off_2);
        }
        ui->label_CCS_Amount_3->setText(QString::number(0 ,'f',2));
        ui->label_CCS_Time_Front_3->setText(QString::number(0 ,'f',2));
    }
    else if(status == G_Discharging_2)
    {
        CCS2.EndTime = QDateTime::currentDateTime().addSecs(TMZOffset);
        OCPPQueue.enqueue(G2_StopTransaction);
        OCPPQueue.enqueue(G2_StatusNotification);
        if(CCS2.Error == NoError)
        {
            CCS2.Status = Finishing;
        }

        ui->Status_2->setText("Finished");
     //   PLC_queue.enqueue(Report_state_2);
    }
    else if(status == G_EVDisconnected_2)
    {
        CCS2.EndTime = QDateTime::currentDateTime().addSecs(TMZOffset);
        OCPPQueue.enqueue(G2_StopTransaction);
        OCPPQueue.enqueue(G2_StatusNotification);
        CCS2.Status = Finishing;
        ui->Status_2->setText("EVDisconnect");
    }
    else if(status == G_charging_2)
    {
        CCS2.Status = Charging;
        CCS2.start = Charging;
        reconnect_flag_1 = false;
        OCPPQueue.enqueue(G2_StartTransaction);
        OCPPQueue.enqueue(G2_StatusNotification);
        ui->Status_2->setText("Charging");
        QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G2 Charging...</span></p></body></html>"};
        ui->label_25->setText(temp);
        ui->pushButton_CCS_2->setIcon(QIcon(":/images/NGUN-4.png"));
        Sharing.G2_Is_Available_LS = LS_NotAvailable;
    }
    else if(status == G_faulted_2)
    {
        ui->Status_2->setText("Faulted");
        ui->pushButton_CCS_2->setIcon(QIcon(":/images/NGUN-2.png"));
        CCS2.Status = Faulted;
        OCPPQueue.enqueue(G2_StatusNotification);
        Sharing.G2_Is_Available_LS = LS_NotAvailable;
    }
    else if(status == G_Available_2)
    {
        if(set_parameter.Availibility == 100 || set_parameter.Availibility == 102)
        {
            CCS2.Status = Unavailable;
            ui->Status_2->setText("Unavailable");
            qDebug()<<"Gun2 Unavailable"<<endl;
        }
        else
        {
            CCS2.Status = Available;
            qDebug()<<"Gun2 Available"<<endl;
            ui->Status_2->setText("Available");
        }
    //    CCS2.ALM_status = false;
        reconnect_flag_1 = false;              
        if(ui->label_CCS_Status->text() == "Please Remove the gun2 and Try again..")
        {
          ui->label_CCS_Status->setText("No Error");
        }
        QTimer::singleShot(300000, this, SLOT(LoadSharingStatus_2()));
        ui->pushButton_CCS_2->setIcon(QIcon(":/images/NGUN-1.png"));
        OCPPQueue.enqueue(G2_StatusNotification);
    }
#endif
}
void MainWindow::ForcedStop(int nGroup)
{

}
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton_AdminIcon->setVisible(true);
    ui->label_lubi->setVisible(true);
}
bool MainWindow::CCSStart(){
    emit sgnCharger_Start(nChargerMode);    
    return 1;
}
void MainWindow::on_pushButton_CCS_clicked()
{
    if((set_parameter.Ocpp_Status == 1) && (set_parameter.check_OCPP == 0) )
    {
        ui->label_CCS_Status->setText("OCPP Error....");
        if(CCS.Status != Charging)
        {
            return;
        }       
    }
    if(set_parameter.TestMode_ED == true)
    {
        if((CCS.start == Charging_Stop) && (CCS.Error == NoError))
        {
            CCS.Setting_Time = CCS.Setting_Unit = 0;
            CCS.Automatic_Start = false;
            Current_Charger_Status = StartScreen_1;
            CCS.TadId.clear();
            ui->label_charging_validation->clear();
            ui->stackedWidget->setCurrentIndex(3);
        }
        else if(CCS.Status == Charging || CCS.start == Try_To_Start)
        {
            if(CCS.start == Try_To_Start)
            {
                  QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G1 Processing...</span></p></body></html>"};
                  ui->label_25->setText(temp);
            }
            else
            {
                QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G1 Charging...</span></p></body></html>"};
                ui->label_25->setText(temp);
            }
            Current_Charger_Status = ChargingScreen_1;
            ui->stackedWidget->setCurrentIndex(5);
        }
        return;
    }
    if((CCS.Status == Preparing && CCS.start == Charging_Stop) && (CCS.Error == NoError)){
        CCS.Setting_Time = CCS.Setting_Unit = 0;
        CCS.Automatic_Start = false;
        Current_Charger_Status = StartScreen_1;
        CCS.TadId.clear();
        ui->label_charging_validation->clear();
        ui->stackedWidget->setCurrentIndex(3);
        PLC_queue.enqueue(Report_state);
    }
    else if(CCS.Status == Charging || CCS.start == Try_To_Start){
        if(CCS.start == Try_To_Start)
        {
              QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G1 Processing...</span></p></body></html>"};
              ui->label_25->setText(temp);
        }
        else
        {
            QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G1 Charging...</span></p></body></html>"};
            ui->label_25->setText(temp);
        }
        Current_Charger_Status = ChargingScreen_1;
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        PLC_queue.enqueue(Report_state);
    }
}
void MainWindow::on_checkBox_clicked()
{

}
void MainWindow::on_pushButton_ChargingParamAC_clicked()
{

}
void MainWindow::on_pushButton_Save_charging_clicked()
{
    if(CCS.SCAN_TAGID == -1)
    {
        ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'>RFID card Reader Error </span></p><p><span style=' font-weight:600; color:#ffff00;'>Please Use Password</span></p></body></html>"));
    }
    else
    {
        ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#eeeeec;'>Keep RFID card or tag in</span></p><p><span style=' font-weight:600; color:#eeeeec;'>front of reader</span></p></body></html>"));
    }
    if(ui->lineEdit_ChangeTime->text() == "" && ui->lineEdit_ChangeUnit->text() == "" && (ui->checkBox->checkState() == Qt::Unchecked))
    {
        ui->label_charging_validation->setText("Please Select Option");
        return;
    }
    ui->stackedWidget->setCurrentIndex(2);
    if(Current_Charger_Status == StartScreen_1)
    {
        CCS.Setting_Time = ui->lineEdit_ChangeTime->text().toInt();
        CCS.Setting_Unit = ui->lineEdit_ChangeUnit->text().toInt();
        CCS.Automatic_Start = (ui->checkBox->checkState() == Qt::Checked) ? 1 : 0 ;
    }
#ifdef M2
   else if(Current_Charger_Status == StartScreen_2)
    {
        CCS2.Setting_Time = ui->lineEdit_ChangeTime->text().toInt();
        CCS2.Setting_Unit = ui->lineEdit_ChangeUnit->text().toInt();
        CCS2.Automatic_Start = (ui->checkBox->checkState() == Qt::Checked) ? 1 : 0 ;
    }
#endif
    ui->lineEdit_ChangeTime->clear();
    ui->lineEdit_ChangeUnit->clear();
}
void MainWindow::on_pushButton_EmergencyStopCCS_clicked()
{
    if(Current_Charger_Status == ChargingScreen_1 /*|| Current_Charger_Status == ChargingScreen_2*/)
    {
       Current_Charger_Status = StopScreen_1;
    }
    if(Current_Charger_Status == ChargingScreen_2 /*|| Current_Charger_Status == ChargingScreen_2*/)
    {
        Current_Charger_Status = StopScreen_2;
    }
    ui->label_rfidstatus->setText(tr("<html><head/><body><p><span style=' font-weight:600; color:#eeeeec;'>Keep RFID card or tag in</span></p><p><span style=' font-weight:600; color:#eeeeec;'>front of reader</span></p></body></html>"));
    ui->stackedWidget->setCurrentIndex(2);    
}
void MainWindow::on_pushButton_CCSPayment_clicked()
{
    if(waitForResuming == false)
    {
        ui->stackedWidget->setCurrentIndex(7);
    }
}
void MainWindow::on_pushButton_FinishCCS_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}
/********************* Admin *************************/
void MainWindow::on_pushButton_AdminIcon_clicked()
{
    if(CCS2.Status != Charging && CCS.Status != Charging)
    {
        ui->stackedWidget->setCurrentIndex(9);
    }
    ui->label_MessageLogin->clear();
}
void MainWindow::on_pushButton_Login_clicked()
{
    if(ui->lineEdit_Password->text()=="") {

         ui->label_MessageLogin->setText("Password fields are null");

       }else if(ui->lineEdit_Password->text()=="Factory") {
         ui->stackedWidget->setCurrentIndex(12);
        }
        else if(ui->lineEdit_Password->text()=="0000") {
             ui->stackedWidget->setCurrentIndex(11);
         }
        else if(db->selectLoginData("Admin",ui->lineEdit_Password->text())==1){
            ui->stackedWidget->setCurrentIndex(11);
           }
        else {
            ui->label_MessageLogin->setText("Incorrect Password");
       }    
    ui->lineEdit_Password->clear();
}
void MainWindow::on_pushButton_Signin_clicked()
{
    ui->stackedWidget_Admin->setCurrentIndex(4);
    ui->label_ChrgMsg->clear();
}

void MainWindow::on_pushButton_CancelLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_SaveRegister_clicked()
{
    if( ui->lineEdit_RegPassword->text()=="" || ui->lineEdit_RegConfirmPass->text()==""){
         ui->label_RegisterMsg->setText("fields are required");
        return;
    }
    else if(ui->lineEdit_RegPassword->text() == ui->lineEdit_RegConfirmPass->text()){
       bool ret =  db->saveUserData("Admin",ui->lineEdit_RegPassword->text(),ui->lineEdit_RegConfirmPass->text(),1);
        if(ret == true)
        {
             ui->label_RegisterMsg->setText("Saved Successfully Admin Password");
        }
        else
        {
            ui->label_RegisterMsg->setText("Failed to Save Admin Password");
        }
    }
    else
    {
        ui->label_RegisterMsg->setText("Password mismatch");
    }
    ui->lineEdit_RegPassword->clear();
    ui->lineEdit_RegConfirmPass->clear();
}
void MainWindow::on_pushButton_AdminOCPP_clicked()
{
    ui->label_ocpp_saved->clear();
    ui->stackedWidget_Admin->setCurrentIndex(1);
}

void MainWindow::on_pushButton_AdminEthernet_clicked()
{
    ui->label_ethernet_status->clear();
    ui->stackedWidget_Admin->setCurrentIndex(0);
}
void MainWindow::on_pushButton_AdminWifi_clicked()
{
    ui->label_wifi_saved->clear();
    ui->stackedWidget_Admin->setCurrentIndex(5);
}
void MainWindow::on_pushButton_Return_OCPP_clicked()
{
    bool Ocpp_checked = (ui->OCPPEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    ui->label_ocpp_saved->clear();    
    ui->lineEdit_URL->setText( set_parameter.URL);
    ui->lineEdit_ServerPort->setText( QString::number(set_parameter.Port));

    if(Ocpp_checked != set_parameter.Ocpp_Status)
    {
        ui->OCPPEnable->setChecked(set_parameter.Ocpp_Status);
    }
    ui->stackedWidget->setCurrentIndex(1);    
}
void MainWindow::on_pushButton_Confirmocpp_clicked()
{   
   bool Ocpp_checked = (ui->OCPPEnable->checkState() == Qt::Checked) ? 1 : 0;
   if(Ocpp_checked != set_parameter.Ocpp_Status)
   {
       set_parameter.Ocpp_Status = Ocpp_checked;
   }
   bool ret =  db->saveOcppData(ui->lineEdit_URL->text(), ui->lineEdit_ServerPort->text().toInt());
   if(ret == true)
   {
       ui->label_ocpp_saved->setText("Saved Successfully ");
   }
   else
   {
       ui->label_ocpp_saved->setText("Failed to Save ");
   }
}
void MainWindow::on_pushButton_EthernetSetting_clicked()
{    
    bool wifi_check = (ui->WIFIEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool gsm_check = (ui->GSMEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool Ethernet_check = (ui->EthernetEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool ret = db->saveEthernetData(ui->lineEdit_LocalIP->text(),ui->lineEdit_GatwayIP->text(), ui->lineEdit_SubnetMask->text());

    if(ret == true)
    {
        ui->label_ethernet_status->setText("Saved Successfully ");
    }
    else
    {
        ui->label_ethernet_status->setText("Failed to Save..");
    }

    if(Ethernet_check == true)
    {
        if(gsm_check == 1)
        {
            ocpp_1->Network_disable(3);
        }
        if(wifi_check == 1)
        {
            ocpp_1->Network_disable(1);
        }
        ui->WIFIEnable->setChecked(0);
        ui->GSMEnable->setChecked(0);
        ocpp_1->EthernetConfig(set_parameter.IP,set_parameter.Getway,set_parameter.SubnetMask, true) ;
        set_parameter.Network = 2;
    }    
    else if(gsm_check == false && wifi_check == false)
    {
        if(set_parameter.Network == 2)
        {
            ocpp_1->Network_disable(2);
            set_parameter.Network  =0;
        }           
    }
}
void MainWindow::on_pushButton_WifiSetting_clicked()
{
 //   ui->stackedWidget->setCurrentIndex(1);
    bool wifi_check = (ui->WIFIEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool gsm_check = (ui->GSMEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool Ethernet_check = (ui->EthernetEnable->checkState() == Qt::Checked) ? 1 : 0 ;

    if(wifi_check == true )
    {
        if(gsm_check == 1)
        {
            ocpp_1->Network_disable(3);
        }
        if(Ethernet_check == 1)
        {
            ocpp_1->Network_disable(2);
        }

        ocpp_1->WiFiConfig(ui->lineEdit_SSID->text(),ui->lineEdit_Password_wifi->text(),true);
        ui->EthernetEnable->setChecked(0);
        ui->GSMEnable->setChecked(0);
        set_parameter.Network = 1;
    }
    else if(gsm_check == false && Ethernet_check == false)
    {
        if(set_parameter.Network == 1)
        {
            ocpp_1->Network_disable(1);
        }
        set_parameter.Network = 0;
    }

    bool ret = db->saveWifiData(ui->lineEdit_SSID->text(), ui->lineEdit_Password_wifi->text());
    if(ret == true)
    {
          ui->label_wifi_saved->setText("Saved Successfully ");
    }
    else
    {
          ui->label_wifi_saved->setText("Failed to Save ");
    }
}

void MainWindow::on_pushButton_Price_setting_clicked()
{
    ui->label_pricesetting_saved->clear();
    ui->stackedWidget_Admin->setCurrentIndex(6);
}
void MainWindow::on_pushButton_getOutfromPriceSett_clicked()
{     
   bool ret = db->savePriceSetting(1, ui->lineEdit_Unitby_charge->text().toInt());
   if(ret == true)
   {
        ui->label_pricesetting_saved->setText("Saved Price Setting...");
   }
   else
   {
        ui->label_pricesetting_saved->setText("Failed to Save Price Setting..");
   }
}
void MainWindow::on_pushButton_AdminSetting_clicked()
{
    ui->label_Protection_saved->clear();
    ui->stackedWidget_Admin->setCurrentIndex(7);
}
void MainWindow::on_pushButton_Setting_clicked()
{   
    bool ret = db->saveSettingData(ui->lineEdit_OverVolt->text().toInt(), ui->lineEdit_UnderVolt->text().toInt(), ui->lineEdit_OverCurrCCS->text().toInt());   // ui->lineEdit_OverCurrAC->text())
    if(ret == true)
    {
        ui->label_Protection_saved->setText("Saved Successfully ");
    }
    else
    {
        ui->label_Protection_saved->setText("Failed to Save ");
    }
}
void MainWindow::on_pushButton_Profile_Save_clicked()
{
   bool ret =  db->saveDC_Profile(ui->lineEdit_Max_I->text().toInt() ,ui->lineEdit_Min_I->text().toInt(), ui->lineEdit_Max_V->text().toInt(), ui->lineEdit_Min_V->text().toInt() ,ui->lineEdit_Min_P->text().toInt(), ui->lineEdit_Max_P->text().toInt());
   if(ret == true)
   {
       ui->label_Profiled_saved->setText("Save DC Profile Setting");
   }
   else
   {
       ui->label_Profiled_saved->setText("Failed to Save DC Profile Setting");
   }   
}
void MainWindow::on_pushButton_Save_gsm_clicked()
{
    bool wifi_check = (ui->WIFIEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool gsm_check = (ui->GSMEnable->checkState() == Qt::Checked) ? 1 : 0 ;
    bool Ethernet_check = (ui->EthernetEnable->checkState() == Qt::Checked) ? 1 : 0 ; 
    if(gsm_check == true)
    {
        if(wifi_check == 1)
        {
            ocpp_1->Network_disable(1);
        }

        if(Ethernet_check == 1)
        {
            ocpp_1->Network_disable(2);
        }
        ui->WIFIEnable->setChecked(0);
        ui->EthernetEnable->setChecked(0);
        ocpp_1->GSM_connect(set_parameter.GSM_APN,set_parameter.GSM_IPV,true);
        set_parameter.Network = 3;
    }
    else if(Ethernet_check == false && wifi_check == false)
    {
        if(set_parameter.Network == 3)
        {
            ocpp_1->Network_disable(3);
        }
            set_parameter.Network = 0;
    }
    bool ret = db->saveGSMData(ui->lineEdit_APN->text(), set_parameter.GSM_IPV);
    if(ret == true)
    {
        ui->label_gsm_saved->setText("Saved Successfully ");
    }
    else
    {
        ui->label_gsm_saved->setText("Failed to Save.. ");
    }
}
void MainWindow::StartUpdatetimer(bool bStart)
{
    if(bStart)
    {
        updateTimer->start();
    }else
    {
        updateTimer->stop();
    }
}
void MainWindow::update_Charging_Info(stChargerUI_Info cInfo)
{
    ui->label_BatteryPercentage->setText(QString::number(cInfo.ui_Soc)+ "%");
    ui->progressBar_CCS->setValue(cInfo.ui_Soc);

    quint32   nTime = cInfo.ui_ElapsedTime;  
    ui->label_EvCurrent->setText(QString::number(cInfo.ui_Current,'f',2));
    ui->label_VoltageValue->setText(QString::number(cInfo.ui_Voltage , 'f',2));

    QString  sTime = QString::number((quint32)((nTime / 60)/60)).rightJustified(2, '0') + ":" +
            QString::number((quint32)((nTime / 60)%60)).rightJustified(2, '0') + ":" +
            QString::number((quint32)(nTime % 60)).rightJustified(2, '0');

    ui->label_lbElapseTime->setText(sTime);
    ui->label_Power_Consumption->setText(QString::number(cInfo.ui_Power,'f',2));    
    ui->label_Tempreture_minus->setText((QString::number(cInfo.Temp_DC_Neg)+ " C"));
    ui->label_Tempreture_plus->setText(QString::number(cInfo.Temp_DC_Pos)+ " C");

    ui->label_Energy_Consumption->setText(QString::number(cInfo.ui_Utilization , 'f',2));
    ui->label_Output_Power->setText(QString::number(cInfo.ui_DC_1_Voltage ,'f',2));
    ui->label_Output_Current->setText(QString::number(cInfo.ui_DC_1_Current,'f',2));
    sTime = QString::number(ChargerUI_Info.ui_Min).rightJustified(3, '0') + ":" +
                    QString::number(ChargerUI_Info.ui_Sec).rightJustified(2, '0');
    ui->t1_lbRemainTime->setText(sTime);

    if((cInfo.ui_Plc_Error_Code > 0)  || (cInfo.ui_Plc_Error_Code > 0 ))
    {
        //ui->lbl_ERROR_CODE->setText("Error : " + QString::number(cInfo.ui_Plc_Error_Code));
        //ui->lbl_ERROR_CODE->setVisible(true);
    }   
    else
    {
        // ui->lbl_ERROR_CODE->setText("Error : ");
        //ui->lbl_ERROR_CODE->setVisible(false);
        ui->lbl_ERROR_CODE->setText("NeedToLS :" + QString::number(Sharing.G1_Need_Tb_LS)+"G2_Avail."+QString::number(Sharing.G2_Is_Available_LS)+"Que:"+QString::number(can_module.length()));
    }
}
void MainWindow::Charging_calculation()
{
    quint32   nTime,nTime_1;
    float c;
    if(CCS.start == Try_To_Start || CCS.start == Charging_Start)
    {      
        ChargerUI_Info.ui_Utilization =  (float)(CCS.Energy - CCS.Start_Energy)/1000;
        ChargerUI_Info.ui_ElapsedTime = (quint32)(pElapsedTime->elapsed()/1000);
        nTime = ChargerUI_Info.ui_ElapsedTime;
        CCS.SOC = ChargerUI_Info.ui_Soc;
        if(CCS.start == Try_To_Start)
        {
            if(nTime > 120 )
            {
                ChargerUI_Info.ui_Charger_ErrorCode = T_TimeOut;
               /* ui->lbl_ERROR_CODE->setText("Start" + QString::number(ChargerUI_Info.ui_ElapsedTime));
                  ui->lbl_ERROR_CODE->setVisible(true);*/
            }            
        }        
        ChargerUI_Info.ui_DC_1_Voltage =  CCS.DC_Voltage_1;
        ChargerUI_Info.ui_DC_1_Current =  CCS.DC_Current_1;

        if(CCS.Automatic_Start == 1)
        {

        }
        else
        {
            if((nTime/60 >=  CCS.Setting_Time) && (CCS.Setting_Time != 0))
            {
                CCS.Reson = Local;
                ChargerUI_Info.ui_Charger_ErrorCode = U_StopByTimetoCharge;                                
            }
            else if((ChargerUI_Info.ui_Utilization >= (float)CCS.Setting_Unit) && (CCS.Setting_Unit != 0))
            {
                CCS.Reson = Local;
                ChargerUI_Info.ui_Charger_ErrorCode = U_StopByUnittoCharge;              
            }
        }
        if(set_parameter.cutoffsoc_ED == true)
        {
            if(ChargerUI_Info.ui_Soc >= set_parameter.cutoffsoc)
            {
                ChargerUI_Info.ui_Charger_ErrorCode = S_cuttofSoc;
            }
        }
        if((currentpage == 5) && (Current_Charger_Status == ChargingScreen_1))
        {           
            ChargerUI_Info.ui_Power =  CCS.Power/1000;
            ChargerUI_Info.Temp_DC_Neg = CCS.Tempreture_dcN;
            ChargerUI_Info.Temp_DC_Pos = CCS.Tempreture_dcP;
            this->update_Charging_Info(ChargerUI_Info);
        }
        else if(currentpage == 1)
        {
             c = (float)(ChargerUI_Info.ui_Utilization * set_parameter.unit_charges);
            ui->label_CCS_Amount->setText(QString::number(c ,'f',2));

            QString  sTime = QString::number((quint32)((nTime / 60)/60)).rightJustified(2, '0') + ":" +
                      QString::number((quint32)((nTime / 60)%60)).rightJustified(2, '0') + ":" +
                      QString::number((quint32)(nTime % 60)).rightJustified(2, '0');            
            ui->label_CCS_Time_Front->setText(sTime);
        }
        if(ChargerUI_Info.ui_Plc_Error_Code > 0 || ChargerUI_Info.ui_Charger_ErrorCode > 0)
        {
            if(CCS.start == Try_To_Start)
            {
                if(ChargerUI_Info.ui_Charger_ErrorCode > 0 || ChargerUI_Info.ui_Plc_Error_Code > 0)
                {
                 //   qDebug()<<"PLC Code: " << ChargerUI_Info.ui_Plc_Error_Code << "Charger Error Code: "<<ChargerUI_Info.ui_Charger_ErrorCode<<endl;
                     if(/* ChargerUI_Info.ui_Plc_Error_Code > 0 && */ reconnect_flag == 0)
                     {
                         PLC_queue.enqueue(HardReset_state);                         
                         reconnect_flag = 1;
                         ui->lbl_ERROR_CODE->setText("Reconnect");
                         ui->lbl_ERROR_CODE->setVisible(true);
                         SAFE_DELETE(pElapsedTime)
                         pElapsedTime = new QElapsedTimer;
                         pElapsedTime->start();
                         can_module.enqueue(Pm_Off);
                     }
                     else if(reconnect_flag == 1)
                     {
                        PLC_queue.enqueue(Report_state);
                        reconnect_flag = 0;
                        ui->stackedWidget->setCurrentIndex(1);
                        ui->label_CCS_Status->setText("Please Remove the gun1 and Try again..");
                     }
                    CCS.start = Charging_Stop;
                }
            }
            else if(CCS.start == Charging_Start )
            {
             Stop_Charger(1);
             CCS_relay_status(G_Discharging);
             CCS.start = Charging_Stop;
             if(Sharing.G1_Need_Tb_LS == LS_Active)
             {
                 Sharing.G1_Need_Tb_LS = LS_No;
             }
             QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>G1 Payment Details</span></p></body></html>"};
             ui->label_Payment->setText(temp);

             CCSBILLING(&CCS,ChargerUI_Info);
             if(ChargerUI_Info.ui_Charger_ErrorCode > 0 )
             {
                 ui->label_Stop_reason->setText(QString::number(ChargerUI_Info.ui_Charger_ErrorCode));
             }
             else if(ChargerUI_Info.ui_Plc_Error_Code > 0)
             {
                 ui->label_Stop_reason->setText("PLC Error : " + QString::number(ChargerUI_Info.ui_Plc_Error_Code));
             }
              c = (float)(ChargerUI_Info.ui_Utilization * set_parameter.unit_charges);
              ui->label_CCS_Amount->setText(QString::number(c ,'f',2));

            QString  sTime = QString::number((quint32)((nTime / 60)/60)).rightJustified(2, '0') + ":" +
                      QString::number((quint32)((nTime / 60)%60)).rightJustified(2, '0') + ":" +
                      QString::number((quint32)(nTime % 60)).rightJustified(2, '0');

            ui->label_CCS_Time_Front->setText(sTime);
            ui->stackedWidget->setCurrentIndex(6);
            }
            CCS.start = Charging_Stop;
        }
    }
    else if(CCS.start == Charging_Stop && reconnect_flag == 1)
    {
        ChargerUI_Info.ui_ElapsedTime = (quint32)(pElapsedTime->elapsed()/1000);
        if(ChargerUI_Info.ui_ElapsedTime > 60)
        {           
            Start_Charger(1);
        }
        if((currentpage == 5) && (Current_Charger_Status == ChargingScreen_1))
        {
            ChargerUI_Info.ui_Power    = CCS.Power/1000;
            ChargerUI_Info.Temp_DC_Neg = CCS.Tempreture_dcN;
            ChargerUI_Info.Temp_DC_Pos = CCS.Tempreture_dcP;
            this->update_Charging_Info(ChargerUI_Info);

            if(ChargerUI_Info.ui_Charger_ErrorCode > 0 )
            {
              ui->lbl_ERROR_CODE->setText("Ch_Err. : "+ QString::number(ChargerUI_Info.ui_Charger_ErrorCode)+" - Restart : " + QString::number(60 - ChargerUI_Info.ui_ElapsedTime));
            }
            else if(ChargerUI_Info.ui_Plc_Error_Code > 0)
            {
              ui->lbl_ERROR_CODE->setText("PLC_Err. : "+ QString::number(ChargerUI_Info.ui_Plc_Error_Code)+" - Restart : " + QString::number(60 - ChargerUI_Info.ui_ElapsedTime));
            }
            ui->lbl_ERROR_CODE->setVisible(true);
        }
    }
#ifdef M2
    if(CCS2.start == Try_To_Start || CCS2.start == Charging_Start)
    {      
        ChargerUI_Info_2.ui_Utilization =  (float)(CCS2.Energy - CCS2.Start_Energy)/1000;
        ChargerUI_Info_2.ui_ElapsedTime = (quint32)(pElapsedTime_2->elapsed()/1000);
        nTime_1 = ChargerUI_Info_2.ui_ElapsedTime;
        CCS2.SOC = ChargerUI_Info_2.ui_Soc;
        if(CCS2.start == Try_To_Start)
        {
            if(nTime_1 > 120)
            {
                ChargerUI_Info_2.ui_Charger_ErrorCode = T_TimeOut;
            }
        }
        ChargerUI_Info_2.ui_DC_1_Voltage =  CCS2.DC_Voltage_1;
         ChargerUI_Info_2.ui_DC_1_Current =  CCS2.DC_Current_1;
        if(CCS2.Automatic_Start == 1)
        {

        }
        else
        {
            if((nTime_1/60 >=  CCS2.Setting_Time) && (CCS2.Setting_Time != 0))
            {
                CCS2.Reson = Local;
                ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByTimetoCharge;
            }
            else if((ChargerUI_Info_2.ui_Utilization >= (float)CCS2.Setting_Unit) && (CCS2.Setting_Unit != 0))
            {
                CCS2.Reson = Local;
                ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByUnittoCharge;
            }
        }
        if(set_parameter.cutoffsoc_ED == true)
        {
            if(ChargerUI_Info_2.ui_Soc >= set_parameter.cutoffsoc)
            {
                ChargerUI_Info_2.ui_Charger_ErrorCode = S_cuttofSoc;
            }
        }
        if((currentpage == 5) && (Current_Charger_Status == ChargingScreen_2))
        {
            ChargerUI_Info_2.ui_Power =  CCS2.Power/1000;
            ChargerUI_Info_2.Temp_DC_Neg = CCS2.Tempreture_dcN;
            ChargerUI_Info_2.Temp_DC_Pos = CCS2.Tempreture_dcP;
            this->update_Charging_Info(ChargerUI_Info_2);
        }
        else if(currentpage == 1)
        {
            c = (float)(ChargerUI_Info_2.ui_Utilization * set_parameter.unit_charges);
            ui->label_CCS_Amount_3->setText(QString::number(c ,'f',2));

            QString  sTime = QString::number((quint32)((nTime_1 / 60)/60)).rightJustified(2, '0') + ":" +
                      QString::number((quint32)((nTime_1 / 60)%60)).rightJustified(2, '0') + ":" +
                      QString::number((quint32)(nTime_1 % 60)).rightJustified(2, '0');
            ui->label_CCS_Time_Front_3->setText(sTime);
        }
        if(ChargerUI_Info_2.ui_Plc_Error_Code > 0 || ChargerUI_Info_2.ui_Charger_ErrorCode > 0)
        {
            if(CCS2.start == Try_To_Start )
            {
                if(ChargerUI_Info_2.ui_Charger_ErrorCode > 0 || ChargerUI_Info_2.ui_Plc_Error_Code > 0)
                {
                     if(/* ChargerUI_Info_2.ui_Plc_Error_Code > 0 && */ reconnect_flag_1 == 0)
                     {
                         PLC_queue.enqueue(HardReset_state_2);
                         reconnect_flag_1 = 1;
                         ui->lbl_ERROR_CODE->setText("Reconnect");
                         ui->lbl_ERROR_CODE->setVisible(true);
                         SAFE_DELETE(pElapsedTime_2)
                         pElapsedTime_2 = new QElapsedTimer;
                         pElapsedTime_2->start();
                         can_module.enqueue(Pm_Off_2);
                     }
                     else if(reconnect_flag_1 == 1)
                     {
                         PLC_queue.enqueue(Report_state_2);
                         reconnect_flag_1 = 0;
                        ui->stackedWidget->setCurrentIndex(1);
                        ui->label_CCS_Status->setText("Please Remove the gun2 and Try again..");
                     }
                    CCS2.start =Charging_Stop;
                }
            }
            else if(CCS2.start == Charging_Start )
            {
                 CAN_TX_2.Load_Sharing = false;
                 Stop_Charger(2);
                 if(Sharing.G2_Need_Tb_LS == LS_Active)
                 {
                     Sharing.G2_Need_Tb_LS = LS_No;
                 }
                 CCS_relay_status(G_Discharging_2);
                 CCS2.start = Charging_Stop;

                 QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>G2 Payment Details</span></p></body></html>"};
                 ui->label_Payment->setText(temp);

                 CCSBILLING(&CCS2,ChargerUI_Info_2);
                 if(ChargerUI_Info_2.ui_Charger_ErrorCode > 0)
                 {
                     ui->label_Stop_reason->setText(QString::number(ChargerUI_Info_2.ui_Charger_ErrorCode));
                 }
                 else if(ChargerUI_Info_2.ui_Plc_Error_Code > 0)
                 {
                     ui->label_Stop_reason->setText("PLC Error : " + QString::number(ChargerUI_Info_2.ui_Plc_Error_Code));
                 }

                c = (float)(ChargerUI_Info_2.ui_Utilization * set_parameter.unit_charges);
                ui->label_CCS_Amount_3->setText(QString::number(c ,'f',2));

                QString  sTime = QString::number((quint32)((nTime_1 / 60)/60)).rightJustified(2, '0') + ":" +
                          QString::number((quint32)((nTime_1 / 60)%60)).rightJustified(2, '0') + ":" +
                          QString::number((quint32)(nTime_1 % 60)).rightJustified(2, '0');

                ui->label_CCS_Time_Front_3->setText(sTime);
                ui->stackedWidget->setCurrentIndex(6);
             }
              CCS2.start = Charging_Stop;
        }
    }
    else if(CCS2.start == Charging_Stop && reconnect_flag_1 == true)
    {
        ChargerUI_Info_2.ui_ElapsedTime = (quint32)(pElapsedTime_2->elapsed()/1000);
        if(ChargerUI_Info_2.ui_ElapsedTime > 60)
        {
            Start_Charger(2);
        }
        if((currentpage == 5) && (Current_Charger_Status == ChargingScreen_2))
        {
            ChargerUI_Info_2.ui_Power    = CCS2.Power/1000;
            ChargerUI_Info_2.Temp_DC_Neg = CCS2.Tempreture_dcN;
            ChargerUI_Info_2.Temp_DC_Pos = CCS2.Tempreture_dcP;
            this->update_Charging_Info(ChargerUI_Info_2);
            if(ChargerUI_Info.ui_Charger_ErrorCode > 0 )
            {
              ui->lbl_ERROR_CODE->setText("Ch_Err. : "+ QString::number(ChargerUI_Info_2.ui_Charger_ErrorCode)+" Restart : " + QString::number(60 - ChargerUI_Info_2.ui_ElapsedTime));
            }
            else if(ChargerUI_Info.ui_Plc_Error_Code > 0)
            {
              ui->lbl_ERROR_CODE->setText("PLC_Err. : "+ QString::number(ChargerUI_Info_2.ui_Plc_Error_Code)+" Restart : " + QString::number(60 - ChargerUI_Info_2.ui_ElapsedTime));
            }
            ui->lbl_ERROR_CODE->setVisible(true);
        } 
    }
#endif
}
void MainWindow::SetTimeOut()
{
    bTimeOut = true;
}
void MainWindow::SetTimeOut(QString ErrStr)
{
    bTimeOut = true;
}
void MainWindow::reset_Charging_Info()
{
    stChargerUI_Info dummyInfo;
    memset(&dummyInfo, 0, sizeof(stChargerUI_Info));
    update_Charging_Info(dummyInfo);
}
void MainWindow::CCSBILLING(Charger_Status *CCS, stChargerUI_Info cInfo)
{
    //ui->stackedWidget->setCurrentIndex(6);
    float c = (float)(cInfo.ui_Utilization * set_parameter.unit_charges);
    ui->label_TotalPay->setText(QString::number(c ,'f',2));

     quint32   nTime = cInfo.ui_ElapsedTime/1000;
     QString  sTime = QString::number((quint32)((nTime / 60)/60)).rightJustified(2, '0') + ":" +
               QString::number((quint32)((nTime / 60)%60)).rightJustified(2, '0') + ":" +
               QString::number((quint32)(nTime % 60)).rightJustified(2, '0');

    ui->label_Paymen_Heading->setText(sTime);
    ui->label_CCS_ChargingEnergy->setText(QString::number(cInfo.ui_Utilization ,'f',2));

    QString temp{"<html><head/><body><p><span style=' color:#ffff00;'>Wait for Finishing</span></p></body></html>"};
    ui->label_67->setText(temp);
    waitForResuming = true;
    if(CCS->conn == 1)
    {
        QTimer::singleShot(30000, this, SLOT(End_Charger()));
    }
    else if(CCS->conn == 2)
    {
        QTimer::singleShot(30000, this, SLOT(End_Charger_2()));
    }

    QString strReson = ocpp_1->resontostring(CCS->Reson);
    db->loging((int)CCS->conn,CCS->StartTime,CCS->EndTime,nTime/60,cInfo.ui_Utilization,strReson,CCS->TxnId);

    CCS->Automatic_Start = 0;
    CCS->Setting_Time = 0;
    CCS->Setting_Unit = 0;
}
bool MainWindow::Display_log(int index_log)
{
    QSqlQuery query(m_data);
    query.prepare("SELECT * FROM history where id = (:index_log) ");
    query.bindValue(":index_log", index_log);
    if(query.exec() == false)
    {
        qDebug() << "Read error.";
    }
    else{
        qDebug() << "Read Successs..";
        while (query.next()) {
            ui->Sr_No->setText(QString::number(query.value(0).toInt()));
            ui->GunNo->setText(QString::number(query.value(1).toInt()));
            ui->lineEdit_StartTime->setText(query.value(2).toDateTime().toString("yyyy-MM-ddThh:mm:ss"));
            ui->lineEdit_EndTime->setText(query.value(3).toDateTime().toString("yyyy-MM-ddThh:mm:ss"));
            ui->lineEdit_TotalTime->setText(QString::number( query.value(4).toInt()));
            ui->lineEdit_reson->setText(query.value(5).toString());
            ui->lineEdit_Txno->setText(QString::number(query.value(6).toUInt()));
            ui->lineEdit_ConsumeEnergy->setText(QString::number(query.value(7).toFloat()));
        }
    }
    return 0;
}
void MainWindow::DC_ProfileSlot(QString currentText){

   disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString)));
    form_Numeric->deleteLater();
    if(currentText == "")
    {
        return;
    }

    if(keynboard_Update == DC_Max_V){

        if(currentText.toInt() > 1000 ||  currentText.toInt() < 100)
        {
            ui->label_Profiled_saved->setText("Set DC Max Voltage 100V - 1000V");
            return;
        }
        ui->lineEdit_Max_V->setText(currentText);
    }
    else if (keynboard_Update == DC_Min_V) {

        ui->lineEdit_Min_V->setText(currentText);
    }
    else if (keynboard_Update == DC_Min_I) {
        ui->lineEdit_Min_I->setText(currentText);
    }
    else if (keynboard_Update == DC_Max_I) {
        if(currentText.toInt() < 0 ||  currentText.toInt() > 240)
        {
            ui->label_Profiled_saved->setText("Set DC MAX Current Range 0A - 240A ");
            return;
        }
        ui->lineEdit_Max_I->setText(currentText);
    }
    else if (keynboard_Update == DC_Min_P) {
#ifdef UI_Debug
        qDebug() << " keyPressed " << currentText;
#endif
        ui->lineEdit_Min_P->setText(currentText);
    }
    else if (keynboard_Update == DC_Max_P) {
        if(currentText.toInt() < 0 ||  currentText.toInt() > 120)
        {
            ui->label_Profiled_saved->setText("Set DC MAX Power 0kw - 120kw");
            return;
        }
        ui->lineEdit_Max_P->setText(currentText);
    }    
}
void MainWindow::Serial_number(QString currentText)
 {
     if(currentText == "")
     {
         return;
     }

     if(keynboard_Update == DC_Serial_number){
   //      disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
   //      form_Ascii->deleteLater();
         if(currentText.length() > 20)
         {
             ui->label_SN_saved->setText("Serial Number Length Max 20 char");
             return;
         }
         ui->lineEdit_Serial_Number->setText(currentText);
     }
     else if(keynboard_Update == TempThresold){

     //    disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
     //    form_Numeric->deleteLater();

         if(currentText.toInt() < 0 ||  currentText.toInt() > 120)
         {
             ui->label_SN_saved->setText("Set Tempreture Thresold Range 0 - 120C");
             return;
         }
         ui->lineEdit_TempProtection->setText(currentText);
     }
     else if(keynboard_Update == CutoffSoc){

     //    disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
     //    form_Numeric->deleteLater();

         if(currentText.toInt() < 50 ||  currentText.toInt() > 100)
         {
             ui->label_SN_saved->setText("Set Cutoff Soc Range 50 - 100");
             return;
         }
         ui->lineEdit_EndTime_CuttOfSoc->setText(currentText);
     }
     else if(keynboard_Update == TouchInterval){

     //    disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
     //    form_Numeric->deleteLater();

         if(currentText.toInt() < 5 ||  currentText.toInt() > 120)
         {
             ui->label_LoadSharing->setText("Set Cutoff Soc Range 5 - 120");
             return;
         }
         ui->lineEdit_TouchInterval->setText(currentText);
     }
 }
void MainWindow::Firmware_Upgrade(QString currentText)
 {
  disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Firmware_Upgrade(QString)));
  form_Ascii->deleteLater();
     if(currentText == "")
     {
         return;
     }
     if(keynboard_Update == fw_SN){
         ui->lineEdit_FW_servername->setText(currentText);
     }
     else if(keynboard_Update == fw_Path){
         ui->lineEdit_FW_path->setText(currentText);
     }
     else if(keynboard_Update == fw_UN){
         ui->lineEdit_FW_username->setText(currentText);
     }
     else if(keynboard_Update == fw_PW){
         ui->lineEdit_FW_password->setText(currentText);
     }
 }
void MainWindow::GSMSSlot(QString currentText){

    disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(GSMSSlot(QString)));
    form_Ascii->deleteLater();
    if(currentText == "")
    {
        return;
    }

    if(keynboard_Update == APN){
#ifdef UI_Debug
        qDebug() << " keyPressed " << currentText;
#endif
        ui->lineEdit_APN->setText(currentText);
    }    
}
void MainWindow::chargingSchemeSlot(QString currentText){

    disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(chargingSchemeSlot(QString)));
    form_Numeric->deleteLater();
    if(currentText == "")
    {
        return;
    }

    if(keynboard_Update==ChargebyTime){
        if(currentText.toInt() < 10 || currentText.toInt() > 9999)
        {
            ui->label_charging_validation->setText("set Charge by time range 10 - 9999");
            return;
        }
        ui->lineEdit_ChangeTime->setText(currentText);
    }
    else if (keynboard_Update==ChargebyUnit) {
        if(currentText.toInt() < 1 || currentText.toInt() > 9999)
        {
            ui->label_charging_validation->setText("set Charge by unit range 1 - 9999");
            return;
        }
        ui->lineEdit_ChangeUnit->setText(currentText);
    }    
}
void MainWindow::DisplaySetting(QString currentText)
{    
    if(keynboard_Update == DS_DateTime){

        disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(DisplaySetting(QString)));
        form_Ascii->deleteLater();

        if(currentText == "")
        {
            return;
        }

     UpdateTime = QDateTime::fromString(currentText,"yyyy-MM-dd hh:mm:ss"); // =  QDateTime::fromString(currentText,"yyyy-MM-dd hh:mm:ss"); //"yyyy-MM-ddThh:mm:ss"
     UpdateTime.setTimeSpec(Qt::UTC);

        qDebug()<< UpdateTime <<"Year Selection " <<UpdateTime.date().year()<< "Month" << UpdateTime.date().month() << "Date" << UpdateTime.toLocalTime().date().day()<< "hour : "<< UpdateTime.toLocalTime().time().hour()<< "Minute"<< UpdateTime.time().minute() << "Second" << UpdateTime.time().second()<< endl;
        if(UpdateTime.toLocalTime().date().day() < 0 || UpdateTime.toLocalTime().date().day() > 31)
        {
            ui->label_displaysetting_status->setText("set correct date ");
             return ;
        }
        else if(UpdateTime.toLocalTime().date().month() < 0 || UpdateTime.toLocalTime().date().month() > 12)
        {
            ui->label_displaysetting_status->setText("set correct month ");
             return ;
        }
        else if(UpdateTime.toLocalTime().date().year() < 2023 || UpdateTime.toLocalTime().date().year() > 2100)
        {
            ui->label_displaysetting_status->setText("set correct year ");
            qDebug()<<"Year Selection " <<UpdateTime.toLocalTime().date().year()<< endl;
            return ;
        }
        else if(UpdateTime.toLocalTime().time().hour() < 0 || UpdateTime.toLocalTime().time().hour() > 23)
        {
            ui->label_displaysetting_status->setText("set correct hour ");
            return ;
        }
        else if(UpdateTime.toLocalTime().time().minute() < 0 || UpdateTime.toLocalTime().time().minute() > 59)
        {
            ui->label_displaysetting_status->setText("set correct minute ");
            return ;
        }
        else if(UpdateTime.toLocalTime().time().second() < 0 || UpdateTime.toLocalTime().time().second() > 59)
        {
            ui->label_displaysetting_status->setText("set correct second ");
            return ;
        }
        ui->DateTime_SetTimedate->setText(currentText);
    }
    else if(keynboard_Update == DS_SleepTime){

        disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DisplaySetting(QString)));
        form_Numeric->deleteLater();
        if(currentText == "")
        {
            return;
        }
        if(currentText.toInt() < 20 || currentText.toInt() > 1000)
        {
            ui->label_displaysetting_status->setText("Set Sleep time Range 20s - 1000s ");
            return;
        }
        set_parameter.SleepTime = currentText.toInt();
        ui->lineEdit_SleepTime->setText(currentText);
    }
    else if(keynboard_Update == DS_TMZOffset){

        disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(DisplaySetting(QString)));
        form_Ascii->deleteLater();

        if(currentText == "")
        {
            return;
        }
        if(currentText.toFloat() <  0.00|| currentText.toFloat() > 24.00)
        {
            ui->label_displaysetting_status->setText("set TimeZone Offset 0.0h.m - 24.0h.m ");
            return;
        }
         set_parameter.TimeOffset = currentText.toFloat();
        ui->lineEdit_TimeZone->setText(currentText);
    }
}

void MainWindow::UserPasswordSlot(QString currtext)
{

    disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(UserPasswordSlot(QString)));
    form_Ascii->deleteLater();
    if(currtext == "")
    {
        return;
    }

    if (keynboard_Update==Password) {
        ui->lineEdit_Password->setText(currtext);
    }
    if (keynboard_Update==ChargingPassword) {
        ui->lineEdit_chr_Password->setText(currtext);
    }    
    if (keynboard_Update==stopChargingPassword) {
        ui->lineEdit_chr_Password_8->setText(currtext);
    }
}
void MainWindow::AdminSignInSlot(QString textValue)
{
    disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(AdminSignInSlot(QString)));
    form_Ascii->deleteLater();
    if(textValue == "")
    {
        return;
    }

      if (keynboard_Update==RegPassword) {
        ui->lineEdit_RegPassword->setText(textValue);
    }
    else if (keynboard_Update==RegConfirmPass) {
         ui->lineEdit_RegConfirmPass->setText(textValue);
    }
   else if (keynboard_Update==ChargingsettingPassword) {
        ui->lineEdit_charging_Password->setText(textValue);
    }
    else if (keynboard_Update==conformChargingsettingPassword) {
         ui->lineEdit_chrgConfirmPass->setText(textValue);
    }    
}
void MainWindow::EthernetSlot(QString e_text)
{
    disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(EthernetSlot(QString)));
    form_Ascii->deleteLater();

    if(e_text == "")
    {
        return;
    }

    if(keynboard_Update==ELocalIP){
       // qDebug() << " keyPressed " << e_text;
        ui->lineEdit_LocalIP->setText(e_text);
    }
    else if (keynboard_Update==EGatewayIP) {
        //qDebug() << " keyPressed " << e_text;
        ui->lineEdit_GatwayIP->setText(e_text);
    }
    else if (keynboard_Update==ESubnetmask) {
         ui->lineEdit_SubnetMask->setText(e_text);
    }    
}
void MainWindow::OcppSlot(QString o_text)
{
    if(keynboard_Update==OServerURL){
        disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(OcppSlot(QString)));
        form_Ascii->deleteLater();
        if(o_text == "")
        {
            return;
        }
        ui->lineEdit_URL->setText(o_text);
    }
    else if (keynboard_Update==OServerPort) {

         disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(OcppSlot(QString)));
         form_Numeric->deleteLater();
         if(o_text == "")
         {
             return;
         }
        ui->lineEdit_ServerPort->setText(o_text);

    }

}
void MainWindow::WifiSlot(QString w_text)
{
    disconnect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(WifiSlot(QString)));
     form_Ascii->deleteLater();
    if(w_text == "")
    {
        return;
    }
    if(keynboard_Update==WifiSSID){
       // qDebug() << " keyPressed " << e_text;
        ui->lineEdit_SSID->setText(w_text);

    }
    else if (keynboard_Update==WifiPassword) {
        //qDebug() << " keyPressed " << e_text;
        ui->lineEdit_Password_wifi->setText(w_text);
    }   
}
void MainWindow::PriceSettingSlot(QString p_text)
{
    disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(PriceSettingSlot(QString)));
    form_Numeric->deleteLater();
    if(p_text == "")
    {
        return;
    }
    if(keynboard_Update==TimebyCharge){

        if(p_text.toInt() < 0 || p_text.toInt() > 100)
        {
            ui->label_pricesetting_saved->setText("Set Time by Charge Range 0 - 100");
            return;
        }
     //   ui->lineEdit_timeby_charge->setText(p_text);
    }
    else if (keynboard_Update == UnitbyCharge) {
        if(p_text.toInt() < 0 || p_text.toInt() > 100)
        {
            ui->label_pricesetting_saved->setText("Set unit by Charge Range 0 - 100");
            return;
        }
        ui->lineEdit_Unitby_charge->setText(p_text);
    }
}
void MainWindow::SettingSlot(QString s_text)
{
    disconnect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(SettingSlot(QString)));
    form_Numeric->deleteLater();
        if(s_text == "")
        {
            return;
        }

    if(keynboard_Update==OverVolt){
        if(s_text.toInt() < 200 || s_text.toInt() > 600)
        {
            ui->label_Protection_saved->setText("Set Over Voltage Range 200V - 600V ");
            return;
        }
        ui->lineEdit_OverVolt->setText(s_text);

    }
    else if (keynboard_Update==UnderVolt) {
        //qDebug() << " keyPressed " << currtext;
        if(s_text.toInt() < 0 || s_text.toInt() > 415)
        {
            ui->label_Protection_saved->setText("Set Under Voltage Range 0V - 415V ");
            return;
        }
        ui->lineEdit_UnderVolt->setText(s_text);
    }
    else if (keynboard_Update==OverCurrCCS) {
        if(s_text.toInt() < 10 || s_text.toInt() > 200)
        {
            ui->label_Protection_saved->setText("Set Over Current Range 10A - 200A ");
            return;
        }
         ui->lineEdit_OverCurrCCS->setText(s_text);
    }

   /* else if (keynboard_Update==OverCurrAC) {
         ui->lineEdit_OverCurrAC->setText(s_text);
    }*/
}
void MainWindow::workFinished(const QString& rResult)
{

}
void MainWindow::on_pushButton_keyboard_password_clicked()
{

    keynboard_Update = Password;
    form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(UserPasswordSlot(QString)));
    if(form_Ascii == NULL)
     {
        qDebug() << "New Form"<<endl;
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_Regi_password_clicked() //changed
{
    keynboard_Update = RegPassword;
    form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(AdminSignInSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}
void MainWindow::on_pushButton_Regi_confirmpass_clicked() //changed
{
    keynboard_Update = RegConfirmPass;
   form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(AdminSignInSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}
/*
 * void MainWindow::on_pushButton_Regi_PassHint_clicked()
{
    keynboard_Update = RegHintPass;
    form = new Form(AScii_KeyBoard,this);

    connect(form,SIGNAL(changevalue(QString)),this,SLOT(AdminSignInSlot(QString)));
    if(form == NULL)
     {
        form = new Form();//
        form->show();
     }
    else
    {
        form->show();
    }
}
*/
void MainWindow::on_pushButton_Ether_Localip_clicked() //changed
{

    keynboard_Update = ELocalIP;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_LocalIP);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(EthernetSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_Ether_Gatewayip_clicked()
{
    keynboard_Update = EGatewayIP;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_GatwayIP);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(EthernetSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_Ether_Subnet_clicked()
{
    keynboard_Update = ESubnetmask;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_SubnetMask);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(EthernetSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_Keyboard_serverURL_clicked()
{
    keynboard_Update = OServerURL;
   form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_URL);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(OcppSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_keyboard_serverPort_clicked()
{
    keynboard_Update = OServerPort;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_ServerPort);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(OcppSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}

void MainWindow::on_pushButton_keyboard_SSID_clicked()
{
    keynboard_Update = WifiSSID;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_SSID);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(WifiSlot(QString))); //   void on_pushButton_keyboard_OverVolt_4_clicked();

    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_keyboard_wifiPass_clicked() //changed
{
    keynboard_Update = WifiPassword;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_Password_wifi);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(WifiSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_keyboard_PriceSett_clicked() //changed
{
    keynboard_Update = TimebyCharge; //   void on_pushButton_keyboard_OverVolt_4_clicked();
    form_Numeric = new Form(Numeric_Keyboard,this);
//    form_Numeric->setExternalLineEdit(/*ui->lineEdit_timeby_charge*/);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(PriceSettingSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}

void MainWindow::on_pushButton_keyboard_Setting_clicked() // changed
{
    keynboard_Update = UnitbyCharge;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Unitby_charge);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(PriceSettingSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}
void MainWindow::on_pushButton_keyboard_OverVolt_clicked()
{
    keynboard_Update = OverVolt;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_OverVolt);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(SettingSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}

void MainWindow::on_pushButton_keyboard_UnderVolt_clicked()
{
    keynboard_Update = UnderVolt;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_UnderVolt);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(SettingSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}

void MainWindow::on_pushButton_keyboard_OverCurrCCS_clicked()
{
    keynboard_Update = OverCurrCCS;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_OverCurrCCS);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(SettingSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}
void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    currentpage = arg1;
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_History_Page_clicked()
{
    //GO TO hmi screen
     ui->stackedWidget_Admin->setCurrentIndex(9);

    QSqlQuery query(m_data);
    query.prepare("SELECT max(id) FROM history");
    if(query.exec() == false)
    {
#ifdef UI_Debug
        qDebug() << "sr.number error.";
#endif
    }
    else{
#ifdef UI_Debug
        qDebug() << "sr. number value..";
#endif
        while (query.next()) {
        Max_Log_index = query.value(0).toInt();
#ifdef UI_Debug
        qDebug()<<Log_index;        
#endif
        }
    }
    qDebug()<<"Max_Log_index : "<< Max_Log_index<< endl;
Log_index = Max_Log_index ;
    Display_log(Max_Log_index);
}
void MainWindow::on_pushButton_keyboard_Max_V_clicked()
{
    keynboard_Update = DC_Max_V;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Max_V);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
}
void MainWindow::on_pushButton_keyboard_Min_V_clicked()
{
    keynboard_Update = DC_Min_V;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Min_V);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString))); //   void on_pushButton_keyboard_OverVolt_4_clicked();

    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }

#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
}
void MainWindow::on_pushButton_keyboard_Max_I_clicked()
{
    keynboard_Update = DC_Max_I;
   form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Max_I);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form_Numeric";
#endif
}
void MainWindow::on_pushButton_keyboard_Min_P_clicked()
{
    keynboard_Update = DC_Min_P;    
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Min_P);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form_Numeric";
#endif
}
void MainWindow::on_pushButton_keyboard_Min_I_clicked()
{
    keynboard_Update = DC_Min_I;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Min_I);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
}
void MainWindow::on_pushButton_keyboard_Max_P_clicked()
{
    keynboard_Update = DC_Max_P;
   form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_Max_P);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DC_ProfileSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
}
void MainWindow::on_pushButton_Keyboard_charggebyunit_clicked() //Need to change
{
    keynboard_Update = ChargebyUnit;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_ChangeUnit);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(chargingSchemeSlot(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
}
void MainWindow::on_pushButton_Admin4G_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
      ui->stackedWidget_Admin->setCurrentIndex(8);
}

void MainWindow::on_pushButton_AdminDcProfile_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
    ui->label_Profiled_saved->clear();
    ui->stackedWidget_Factory->setCurrentIndex(0);
}
void MainWindow::on_IPv4v6_radioButton_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
    set_parameter.GSM_IPV = 0;
}
void MainWindow::on_IPv6_radioButton_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
     set_parameter.GSM_IPV = 1;
}
void MainWindow::on_IPv4_radioButton_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
     set_parameter.GSM_IPV = 2;
}

void MainWindow::on_pushButton_keyboard_APN_clicked()
{
    keynboard_Update = APN;
   form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_APN);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(GSMSSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form_Ascii";
#endif
}
void MainWindow::on_pushButton_Keyboard_chargebytime_clicked()  //Need to Change
{
    keynboard_Update = ChargebyTime;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_ChangeTime);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(chargingSchemeSlot(QString)));
    if(form_Numeric == NULL)
    {
        form_Numeric = new Form();//
        form_Numeric->show();
    }
    else
    {
        form_Numeric->show();
    }

#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
}

void MainWindow::on_pushButton_Profile_Back_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_Profiled_saved->clear();
}

void MainWindow::on_pushButton_Cancel_gsm_clicked()
{
    ui->label_gsm_saved->clear();
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
    if(set_parameter.GSM_IPV == 2)
    {
        ui->IPv4_radioButton->setChecked(1);
    }
    else if(set_parameter.GSM_IPV == 1)
    {
        ui->IPv6_radioButton->setChecked(1);
    }
    else if(set_parameter.GSM_IPV == 0)
    {
        ui->IPv4v6_radioButton->setChecked(1);
    }

    ui->lineEdit_APN->setText(set_parameter.GSM_APN);
//    if(set_parameter.Network == 3)
//    {
//        ui->GSMEnable->setChecked(1);
//        ocpp_1->GSM_connect(set_parameter.GSM_APN,set_parameter.GSM_IPV,true);
//    }
     ui->stackedWidget_Admin->setCurrentIndex(2);
}

void MainWindow::on_pushButton_WifiSetting_back_clicked()
{
  HMI_WakeUP_Mode();
  Sleep_Timer = 0;
  touch_driver = 0;
  ui->label_wifi_saved->clear();
  ui->stackedWidget_Admin->setCurrentIndex(2);
  ui->lineEdit_SSID->setText( set_parameter.ssid);
  ui->lineEdit_Password_wifi->setText(set_parameter.password);

    //  if(set_parameter.Network == 1)
    //  {
    //      ocpp_1->WiFiConfig(set_parameter.ssid,set_parameter.password,true);
    //      ui->WIFIEnable->setChecked(1);
    //  }

}

void MainWindow::on_pushButton_Setting_Back_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
    ui->label_Protection_saved->clear();
    ui->lineEdit_OverVolt->setText( QString::number(set_parameter.Over_Voltage));
    ui->lineEdit_UnderVolt->setText( QString::number(set_parameter.Under_Voltage));
    ui->lineEdit_OverCurrCCS->setText( QString::number(set_parameter.Over_Current_ccs));
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_PriceSetting_back_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver = 0;
    //ui->lineEdit_timeby_charge->setText( QString::number(set_parameter.time_charges));
    ui->lineEdit_Unitby_charge->setText( QString::number(set_parameter.unit_charges));
    ui->label_pricesetting_saved->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_WIFIEnable_clicked(bool checked)
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;

//    if(checked == true)
//    {
//         set_parameter.Network =1;
//    }
//    else
//    {
//          if(set_parameter.Network == 1)
//          {
//             // set_parameter.Network  =0;
//          }
//    }
}

void MainWindow::on_EthernetEnable_clicked(bool checked)
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_GSMEnable_clicked(bool checked)
{

}
void MainWindow::on_OCPPEnable_clicked(bool checked)
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0; 
    touch_driver =0;
}
void MainWindow::on_pushbutton_history_back_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::mousePressEvent(QMouseEvent* evt)
{
   // qDebug()<<"Touch ---------" <<endl;
    Q_UNUSED(evt);

    if(evt->button() == Qt::LeftButton)
    {
   //     qDebug() << "left button"<<endl;
    }

    if(evt->button() == Qt::MiddleButton){
   //     qDebug() << "Middle button"<<endl;
    }

    if(evt->button() == Qt::RightButton){
   //     qDebug() << "Right button"<<endl;
    }    
    Sleep_Timer = 0;
    touch_driver =0;
    HMI_WakeUP_Mode();
}
void MainWindow::HMI_sleep_Mode()
{
     qDebug() << "Sleep Mode"<<endl;
    sleep_Mode = true;    
    QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 0 > /sys/class/backlight/backlight-display/brightness"));
}
void MainWindow::HMI_WakeUP_Mode()
{
    if(sleep_Mode == true)
    {
        qDebug() << "Wake UP mode"<<endl;       
         QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo 6 > /sys/class/backlight/backlight-display/brightness"));
         sleep_Mode = false;
    }
}
void MainWindow::on_pushButton_Serial_Number_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
    ui->stackedWidget_Factory->setCurrentIndex(1);
}

void MainWindow::on_pushButton_keyboard_Serial_Number_clicked()
{
    keynboard_Update = DC_Serial_number;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_Serial_Number);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_Back_charging_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
    if(Current_Charger_Status == StartScreen_1)
    {
       CCS.Setting_Time = 0;   //ui->lineEdit_ChangeTime->text().toInt();
       CCS.Setting_Unit = 0;   //ui->lineEdit_ChangeUnit->text().toInt();
       CCS.Automatic_Start = 0;//(bool)ui->checkBox;
    }
    #ifdef M2
    else if(Current_Charger_Status == StartScreen_1)
    {
        CCS2.Setting_Time = 0;  //ui->lineEdit_ChangeTime->text().toInt();
        CCS2.Setting_Unit = 0;  //ui->lineEdit_ChangeUnit->text().toInt();
        CCS2.Automatic_Start = 0; //(bool)ui->checkBox;
    }
#endif
Current_Charger_Status = MainScreen_1;
   ui->lineEdit_ChangeTime->clear();
   ui->lineEdit_ChangeUnit->clear();
#ifdef M2
  ui->label_25->setText("Gun 2 Charging..");
#endif
    ui->checkBox->setChecked(false);
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_FW_clicked()
{
    ui->stackedWidget_Factory->setCurrentIndex(2); 
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_keyboard_FW_servername_clicked()
{
    keynboard_Update = fw_SN;
   form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_FW_servername);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Firmware_Upgrade(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_keyboard_FW_path_clicked()
{
    keynboard_Update = fw_Path;
   form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_FW_path);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Firmware_Upgrade(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}

void MainWindow::on_pushButton_keyboard_FW_password_clicked()
{
    keynboard_Update = fw_PW;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_FW_password);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Firmware_Upgrade(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_keyboard_FW_username_clicked()
{
    keynboard_Update = fw_UN;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_FW_username);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(Firmware_Upgrade(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}

void MainWindow::on_pushButton_Serial_Save_clicked()
{
    bool tempreture_check = (ui->checkBox_TempProtection->checkState() == Qt::Checked) ? 1 : 0 ;
    bool cutsoc_check = (ui->checkBox_CuttofSoc->checkState() == Qt::Checked) ? 1 : 0;
    bool doorlock_check = (ui->checkBox_DoorLock->checkState() == Qt::Checked) ? 1 : 0;
    bool TestMode_check = (ui->checkBox_TestMode->checkState() == Qt::Checked) ? 1 : 0;
    bool Ground_fault = (ui->checkBox_GroundFault->checkState() == Qt::Checked) ? 1 : 0;
    bool Isolation_fault = (ui->checkBox_IsolationFault->checkState() == Qt::Checked) ? 1 : 0;
qDebug()<<"Setting Save"<<endl;

   // if(sleep_Mode == true)
    {
        HMI_WakeUP_Mode();
        Sleep_Timer = 0;
        touch_driver =0;
    }
      if(set_parameter.Serial_Number.toStdString() !=  ui->lineEdit_Serial_Number->text().toStdString())
      {
            set_parameter.Serial_Number = ui->lineEdit_Serial_Number->text();
             db->saveAdmin_Setting(4,set_parameter.Serial_Number,4,true);
             ui->label_SN_saved->setText("Serial Number Saved");
      }
      else if(set_parameter.tempThresold != ui->lineEdit_TempProtection->text().toInt() || set_parameter.tempThresold_ED != tempreture_check)
      {
          set_parameter.tempThresold_ED = tempreture_check;
          set_parameter.tempThresold = ui->lineEdit_TempProtection->text().toInt();
         db->saveAdmin_Setting(1,"Thresold tempreture",set_parameter.tempThresold, set_parameter.tempThresold_ED);
         ui->label_SN_saved->setText("Thresold Tempreture Saved");
      }
     else if((set_parameter.cutoffsoc != ui->lineEdit_EndTime_CuttOfSoc->text().toInt()) || set_parameter.cutoffsoc_ED != cutsoc_check)
      {
          set_parameter.cutoffsoc_ED = cutsoc_check;
          set_parameter.cutoffsoc = ui->lineEdit_EndTime_CuttOfSoc->text().toInt();
         db->saveAdmin_Setting(2,"Cutt Off SOC",set_parameter.cutoffsoc, set_parameter.cutoffsoc_ED);
         ui->label_SN_saved->setText("CUTT OFF SOC Saved");
      }
      else if(set_parameter.DoorlOCK_ED != doorlock_check)
      {
         set_parameter.DoorlOCK_ED = doorlock_check;
         ui->label_SN_saved->setText("Door Lock Check Saved");
         db->saveAdmin_Setting(3,"Doorlock",0, set_parameter.DoorlOCK_ED);
      }
      else if(set_parameter.TestMode_ED != TestMode_check)
      {
          set_parameter.TestMode_ED = TestMode_check;
          if(set_parameter.TestMode_ED == false)
          {
              QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>EV</span></p></body></html>"};
              PLC_queue.enqueue(Report_state);
              ui->label_Test->setText(temp);
          }
          else
          {
              QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>TEST</span></p></body></html>"};
              ui->label_Test->setText(temp);
          }
         ui->label_SN_saved->setText("Test Mode Check Saved");
         db->saveAdmin_Setting(5,"TestMode",100, set_parameter.TestMode_ED);
      }
      else if(set_parameter.GroundFault_ED != Ground_fault)
      {
          set_parameter.GroundFault_ED = Ground_fault;
          ui->label_SN_saved->setText("Ground Fault Check Saved");
          db->saveAdmin_Setting(6,"GroundFault",101, set_parameter.GroundFault_ED);
      }
      else if(set_parameter.IsolationFault_ED != Isolation_fault)
      {
          set_parameter.IsolationFault_ED = Isolation_fault;
          ui->label_SN_saved->setText("Isolation_fault Check Saved");
          db->saveAdmin_Setting(7,"InsulatedFault",102, set_parameter.IsolationFault_ED);
      }
}

void MainWindow::on_pushButton_FW_Update_clicked()
{
    if(sleep_Mode == true)
    {
        HMI_WakeUP_Mode();
    }
    Sleep_Timer = 0;

    if(set_parameter.Network_status != 1)
    {
        ui->FW->setText("Netwrork Error....");
        return;
    }

    if((ui->lineEdit_FW_servername->text() == "") || (ui->lineEdit_FW_path->text() == "") || (ui->lineEdit_FW_username->text() == "") || (ui->lineEdit_FW_password->text() == ""))
    {
        return;
    }
    // connect(ocpp_1, SIGNAL(update_status(bool)), this, SLOT(FirmwareUpdateStatus(bool)));

    set_parameter.FW_SN = ui->lineEdit_FW_servername->text();
    set_parameter.FW_Path = ui->lineEdit_FW_path->text();
    set_parameter.FW_UN = ui->lineEdit_FW_username->text();
    set_parameter.FW_PW = ui->lineEdit_FW_password->text();
    db->saveFirmwareUpgrade( set_parameter.FW_SN,set_parameter.FW_Path,21,set_parameter.FW_UN ,set_parameter.FW_PW);

    QString FileName;
    bool status = false;
    QProcess *msic_process;
    msic_process = new QProcess(this);
    connect(msic_process, SIGNAL(finished(int)), this, SLOT(FirmwareUpdateStatus(int)));
    if(set_parameter.FW_Path.startsWith("/"))
    {
        QStringList tmp = set_parameter.FW_Path.split("/");
        qDebug() <<"Temp."<< tmp[tmp.count()-1];
        FileName = tmp[tmp.count()-1];
        msic_process->start("/bin/bash", QStringList() << "-c" << QString("/home/root/uftp.sh %1 %2 %3 %4 %5").arg(set_parameter.FW_SN).arg(set_parameter.FW_UN).arg(set_parameter.FW_PW).arg(set_parameter.FW_Path).arg(FileName));
    }
    else
    {
        QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>Invalid Path..</span></p></body></html>"};
        ui->FW->setText(temp);
        return;
    }
    msic_process->waitForFinished();
    QTextStream stream(msic_process->readAll().data());
    QString line,Length;
    do {

        line = stream.readLine().trimmed();
        if( line.startsWith("Not") )
        {
            if(line == "Not Connected.")
            {
                qDebug() <<"Not Connected."<< line;
                status = false;
                break;
            }
        }
        else if(line.startsWith("150"))
        {
            Length =   line.mid ( line.indexOf ( "(" ) + 1,(line.indexOf ( ")" ) - line.indexOf ( "(" ) - 7) );
            qDebug()<<"Length: "<<Length<<endl;
        }
        else if(line.startsWith("226"))
        {
            if(line == "226 Transfer complete.")
            {
                qDebug() <<"226 Transfer complete."<< line;
                if(ocpp_1->replyFinished(FileName,Length.toLong()) == true)
                {
                    if(ocpp_1->Start_Sh(FileName) == true)
                    {
                        status = true;
                    }
                }
                break;
            }
        }
    } while (!line.isNull());
    if(status == true)
    {
        QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>Complete...</span></p></body></html>"};
        ui->FW->setText(temp);
        QProcess::execute("/bin/bash", QStringList() << "-c" << QString("reboot"));
    }
    else
    {
        QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>Fail...</span></p></body></html>"};
        ui->FW->setText(temp);
    }
}
void MainWindow::on_pushbutton_history_clear_clicked()
{
    if(sleep_Mode == true)
    {
        HMI_WakeUP_Mode();        
    }
    Sleep_Timer = 0;
    touch_driver =0;
    db->DeleteHistory();
    ui->GunNo->setText("       ");
    ui->lineEdit_StartTime->setText("        ");
    ui->lineEdit_EndTime->setText("          ");
    ui->lineEdit_TotalTime->setText("         ");
    ui->lineEdit_reson->setText("            ");
    ui->lineEdit_Txno->setText("             ");
    ui->lineEdit_ConsumeEnergy->setText("      ");
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushbutton_history_up_clicked()
{
    if(sleep_Mode == true)
    {
        HMI_WakeUP_Mode();
    }
    Sleep_Timer =  0;
    touch_driver = 0;
    if(Log_index > 0)
    {
        Display_log(Log_index--);
        qDebug()<<"Log_index : "<< Log_index<< endl;
    }
}
void MainWindow::on_pushbutton_history_down_clicked()
{
    if(sleep_Mode == true)
    {
        HMI_WakeUP_Mode();
    }
      Sleep_Timer = 0;
      touch_driver =0;
     if(++Log_index > Max_Log_index)
     {
        Log_index  = Max_Log_index;
     }
     Display_log(Log_index );
     qDebug()<<"Log_index : "<< Log_index<< endl;
}

void MainWindow::on_pushButton_EthernetSetting_Back_clicked()
{
    ui->label_ethernet_status->clear();
    ui->lineEdit_LocalIP->setText(set_parameter.IP);
    ui->lineEdit_SubnetMask->setText(set_parameter.SubnetMask);
    ui->lineEdit_GatwayIP->setText(set_parameter.Getway);
    ui->stackedWidget_Admin->setCurrentIndex(2);
}
void MainWindow::on_pushButton_FW_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_KeyBord_TimeDate_clicked()
{
    keynboard_Update = DS_DateTime;
   form_Ascii = new Form(AScii_KeyBoard,this);
    ui->DateTime_SetTimedate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    form_Ascii->setExternalLineEdit(ui->DateTime_SetTimedate);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(DisplaySetting(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }

    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_Back_Display_setting_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
    ui->label_displaysetting_status->clear();
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_Save_Displaysetting_clicked()
{
    bool ret;
    ret = db->saveDisplay(set_parameter.SleepTime,set_parameter.Brightness,set_parameter.TimeOffset);
    if(ret == true)
    {
        ui->label_displaysetting_status->setText("Save Display Setting ");
    }  

    QString string = UpdateTime.toString("\"yyyy-MM-dd hh:mm\"");
    QString dateTimeString ("date -s ");
    dateTimeString.append(string);
    int systemDateTimeStatus= system(dateTimeString.toStdString().c_str());
    if (systemDateTimeStatus == -1)
    {
        qDebug() << "Failed to change date time";
    }
    int systemHwClockStatus = system("/sbin/hwclock -w");
    if (systemHwClockStatus == -1 )
    {
        qDebug() << "Failed to sync hardware clock";
    }
    int multipy = 1;
    int num = set_parameter.TimeOffset;
    int decimal = set_parameter.TimeOffset;
    while(num != 0)
    {
        num = (int)num/10;
        multipy =  multipy*10;
    }
    TMZOffset = (set_parameter.TimeOffset*100 - decimal*100)*60;
    TMZOffset += decimal*3600;
}
void MainWindow::on_pushButton_KeyBord_Timezone_clicked()
{
    keynboard_Update = DS_TMZOffset;
    form_Ascii = new Form(AScii_KeyBoard,this);
    form_Ascii->setExternalLineEdit(ui->lineEdit_TimeZone);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(DisplaySetting(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}

void MainWindow::on_pushButton_KeyBord_sleeptime_clicked()
{
    keynboard_Update = DS_SleepTime;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_SleepTime);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(DisplaySetting(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
        form_Numeric->show();
    }

    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}


void MainWindow::on_pushButton_Display_setting_clicked()
{
    ui->stackedWidget_Admin->setCurrentIndex(10);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<"slider : " << value << endl;
    QProcess::startDetached("/bin/bash", QStringList() << "-c" << QString("echo \"%1\" > /sys/class/backlight/backlight-display/brightness").arg(value));
}
void MainWindow::on_pushButton_Charging_psw_clicked()
{
      HMI_WakeUP_Mode();
      Sleep_Timer = 0;
      touch_driver =0;
      ui->stackedWidget_Admin->setCurrentIndex(11);
      ui->label_ChrgMsg->clear();
}

void MainWindow::on_pushButton_Psw_Back_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
  //  ui->label_displaysetting_status->clear();
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_Password_clicked()
{
    ui->stackedWidget_Admin->setCurrentIndex(3);
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::on_pushButton_Network_clicked()
{
    ui->stackedWidget_Admin->setCurrentIndex(2);
}
void MainWindow::on_pushButton_Nework_back_clicked()
{
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Chrg_password_clicked()
{
    keynboard_Update = ChargingsettingPassword;
   form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(AdminSignInSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}
void MainWindow::on_pushButton_charging_confirmpass_clicked()
{
    keynboard_Update = conformChargingsettingPassword;
    form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(AdminSignInSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();//
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}
void MainWindow::on_pushButton_ChargingSave_clicked()
{
    if( ui->lineEdit_charging_Password->text()=="" || ui->lineEdit_chrgConfirmPass->text()==""){
         ui->label_ChrgMsg->setText("fields are required");
        return;

    }
    else if(ui->lineEdit_charging_Password->text() == ui->lineEdit_chrgConfirmPass->text()){
       bool ret =  db->saveUserData("Charging",ui->lineEdit_charging_Password->text(),ui->lineEdit_chrgConfirmPass->text(),2);
       if(ret == true)
       {
            ui->label_ChrgMsg->setText("Saved Successfully Charging Password");
       }
       else
       {
            ui->label_ChrgMsg->setText("Fail to Save Charging Password");
       }
    }
    else
    {
        ui->label_ChrgMsg->setText("Password Mismatch");
    }

    ui->lineEdit_charging_Password->clear();
    ui->lineEdit_chrgConfirmPass->clear();
}
void MainWindow::on_pushButton_keyboard_chr_password_clicked()
{
    keynboard_Update = ChargingPassword;
    form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(UserPasswordSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}
void MainWindow::on_pushButton_chr_Login_clicked()
{
    qDebug()<<"Charging login page" <<endl;

        if(ui->lineEdit_chr_Password->text()=="") {
         ui->label_Message_chr_Login->setText("Password fields are null");
       }else if(db->selectLoginData("Charging",ui->lineEdit_chr_Password->text()) == true){
           if(set_parameter.TestMode_ED == true && (Current_Charger_Status == StartScreen_1))
           {
               Start_Charger(1);
               CCS.Reson = Local;
           }
           else
           {
            if((CCS.Status == Preparing) && (Current_Charger_Status == StartScreen_1))
            {                            
                Start_Charger(1);
                CCS.Reson = Local;                
            }
#ifdef M2
            if(set_parameter.TestMode_ED == true && (Current_Charger_Status == StartScreen_2))
            {
                Start_Charger(2);
                CCS2.Reson = Local;
            }
            else
            {
                if((CCS2.Status == Preparing) && (Current_Charger_Status == StartScreen_2))
                {
                Start_Charger(2);
                CCS2.Reson = Local;
               // Current_Charger_Status = 6;
             //   ui->stackedWidget->setCurrentIndex(5);
                }
            }
#endif
           }
        }
        else {

            ui->label_Message_chr_Login->setText("Incorrect password");
       }
    ui->lineEdit_chr_Password->clear();
    return;
}
void MainWindow::on_pushButton_chr_CancelLogin_clicked()
{
    ui->label_Message_chr_Login->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_BackAdminPsw_clicked()
{
    ui->stackedWidget_Admin->setCurrentIndex(3);
}

void MainWindow::on_pushButton_BackChargingPsw_clicked()
{
    ui->stackedWidget_Admin->setCurrentIndex(3);
}

void MainWindow::on_pushButton_SN_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_SN_saved->clear();
}

void MainWindow::on_pushButton_Back_DuringCharging_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    Current_Charger_Status = MainScreen_1;
    ui->label_SN_saved->clear();
}

void MainWindow::on_pushButton_Error_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_RFID_Next_pressed()
{   
    qDebug() << "Rfifd Back presss."<<endl;
    Current_Charger_Status = MainScreen_1;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ChargeByPswd_clicked()
{
    ui->lineEdit_chr_Password->clear();
    ui->lineEdit_chr_Password_8->clear();
    if(Current_Charger_Status == StartScreen_1 ||  Current_Charger_Status == StartScreen_2)
    {
        ui->stackedWidget->setCurrentIndex(10);
    }
    else if(Current_Charger_Status == StopScreen_1 ||  Current_Charger_Status == StopScreen_2)
    {
       ui->stackedWidget->setCurrentIndex(13);
    }
}
void MainWindow::on_pushButton_keyboard_chr_password_8_clicked()
{
    keynboard_Update = stopChargingPassword;
    form_Ascii = new Form(AScii_KeyBoard,this);
    connect(form_Ascii,SIGNAL(changevalue(QString)),this,SLOT(UserPasswordSlot(QString)));
    if(form_Ascii == NULL)
     {
        form_Ascii = new Form();
        form_Ascii->show();
     }
    else
    {
        form_Ascii->show();
    }
}

void MainWindow::on_pushButton_chr_Login_8_clicked()
{
    qDebug()<<"Stop Charging login page" <<endl;

        if(ui->lineEdit_chr_Password_8->text()=="") {
         ui->label_Message_chr_Login_8->setText("Password fields are null");
       }else if(db->selectLoginData("Charging",ui->lineEdit_chr_Password_8->text()) == true){
            if((CCS.Status == Charging) && (Current_Charger_Status == StopScreen_1))
            {
                CCS.Reson = Local;               
                ChargerUI_Info.ui_Charger_ErrorCode = U_StopByPassword;
            }
#ifdef M2
            else if((CCS2.Status == Charging) && (Current_Charger_Status == StopScreen_2))
            {
                CCS2.Reson = Local;             
                ChargerUI_Info_2.ui_Charger_ErrorCode = U_StopByPassword;
            }
#endif
        }
        else {

            ui->label_Message_chr_Login_8->setText("Incorrect password");
       }
      //  Current_Charger_Status = MainScreen_1;
         ui->lineEdit_chr_Password_8->clear();
    return;
}

#ifdef M2
void MainWindow::on_pushButton_CCS_2_clicked()
{
    if((set_parameter.Ocpp_Status == 1) && (set_parameter.check_OCPP == 0) )
    {
        ui->label_CCS_Status->setText("OCPP Error....");
        if(CCS2.Status == Charging)
        {

        }
        else
        {
            return;
        }
    }

    if(set_parameter.TestMode_ED == true)
    {
        if((CCS2.start == Charging_Stop) && (CCS2.Error == NoError))
        {
            CCS2.Setting_Time = CCS2.Setting_Unit = 0;
            CCS2.Automatic_Start = false;
            Current_Charger_Status =  StartScreen_2;
            CCS2.TadId.clear();
            ui->label_charging_validation->clear();
            ui->stackedWidget->setCurrentIndex(3);            
        }
        else if(CCS2.Status == Charging || CCS2.start == Try_To_Start)
        {
            if(CCS2.start == Try_To_Start)
            {
                  QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#f1c40f;'>G2 Processing...</span></p></body></html>"};
                  ui->label_25->setText(temp);
            }
            else
            {
                QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G2 Charging...</span></p></body></html>"};
                ui->label_25->setText(temp);
            }
            Current_Charger_Status = ChargingScreen_2;
            ui->stackedWidget->setCurrentIndex(5);
        }
        return;
    }

    if((CCS2.Status == Preparing) && (CCS2.Error == NoError)){
        CCS2.Setting_Time = CCS2.Setting_Unit = 0;
        CCS2.Automatic_Start = false;
        Current_Charger_Status = StartScreen_2;
        ui->label_charging_validation->clear();
        ui->stackedWidget->setCurrentIndex(3);
        QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G2 Charging...</span></p></body></html>"};
        ui->label_25->setText(temp);
        PLC_queue.enqueue(Report_state_2);
    }
    else if(CCS2.Status == Charging){
        Current_Charger_Status = ChargingScreen_2;
        QString temp{"<html><head/><body><p><span style=' font-size:16pt; font-weight:600; color:#00cc00;'>G2 Charging...</span></p></body></html>"};
        ui->label_25->setText(temp);
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        PLC_queue.enqueue(Report_state_2);
    }
}
#endif
void MainWindow::on_pushButton_chr_CancelLogin_8_clicked()
{
       ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_keyboard_TProtection_released()
{
    keynboard_Update = TempThresold;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_TempProtection);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
    if(form_Numeric == NULL)
    {
        form_Numeric = new Form();//
        form_Numeric->show();
    }
    else
    {
         form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}

void MainWindow::on_pushButton_keyboard_CutoffSoc_released()
{
    keynboard_Update = CutoffSoc;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_EndTime_CuttOfSoc);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
    if(form_Numeric == NULL)
     {
        form_Numeric = new Form();//
        form_Numeric->show();
     }
    else
    {
         form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
void MainWindow::FirmwareUpdateStatus(bool status)
{
    if(status == true)
    {
        QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>Update Successfully</span></p></body></html>"};
        ui->FW->setText(temp);
        QProcess::execute("/bin/bash", QStringList() << "-c" << QString("mv FW ARAI_30K"));
        QProcess::execute("/bin/bash", QStringList() << "-c" << QString("chmod 777 ARAI_30K"));
        QProcess::execute("/bin/bash", QStringList() << "-c" << QString("reboot"));
    }
    else
    {
        QString temp{"<html><head/><body><p><span style=' color:#ffffff;'>Fail....</span></p></body></html>"};
        ui->FW->setText(temp);
    }
}
void MainWindow::on_pushButton_Load_Sharing_clicked()
{
    ui->stackedWidget_Factory->setCurrentIndex(3);
}

void MainWindow::on_pushButton_LS_Back_clicked()
{
        ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_LS_update_clicked()
{
    bool LoadSharing = (ui->checkBox_LoadSharing->checkState() == Qt::Checked) ? 1 : 0 ;
    bool PostSLSharing = (ui->checkBox_PostSLSharing->checkState() == Qt::Checked) ? 1 : 0;
    bool PreSLoadsharing = (ui->checkBox_PreSLoadsharing->checkState() == Qt::Checked) ? 1 : 0;
    bool PMIndividual = (ui->checkBox_PMIndividual->checkState() == Qt::Checked) ? 1 : 0;
    bool TouchInterval = (ui->checkBox_TouchInterval->checkState() == Qt::Checked) ? 1 : 0;

    if(set_parameter.LoadSharing_ED != LoadSharing)
    {
        Sharing.Is_LoadSharing =  set_parameter.LoadSharing_ED = LoadSharing;
         db->saveAdmin_Setting(10,"loadsharing",100,LoadSharing);
    }
   /* if(set_parameter.PostSLSharing_ED != PostSLSharing)
    {
       Sharing.During_Loadsharing =  set_parameter.PostSLSharing_ED = PostSLSharing;

         db->saveAdmin_Setting(12,"postloadsharing",100,PostSLSharing);
    }
    if(set_parameter.PreSLoadsharing_ED != PreSLoadsharing)
    {
       Sharing.Pre_LoadSharing = set_parameter.PreSLoadsharing_ED = PreSLoadsharing;
         db->saveAdmin_Setting(11,"PreSLoadsharing",100,PreSLoadsharing);
    }*/
    if(set_parameter.PMIndividual_ED != PMIndividual)
    {
        set_parameter.PMIndividual_ED = PMIndividual;
       db->saveAdmin_Setting(9,"PMIndividual",100,PMIndividual);
    }

    if((set_parameter.TouchInterval !=  ui->lineEdit_TouchInterval->text().toInt()) || (set_parameter.TouchInterval_ED != TouchInterval))
    {
         set_parameter.TouchInterval =  ui->lineEdit_TouchInterval->text().toInt();
         set_parameter.TouchInterval_ED = TouchInterval;
         db->saveAdmin_Setting(8,"Touch Interval",set_parameter.TouchInterval,TouchInterval);
         ui->label_LoadSharing->setText("Touch Interval....");
    }
    touch_driver = 0;
    Sleep_Timer  = 0;
}

void MainWindow::on_pushButton_keyboard_TouchInterval_clicked()
{
    keynboard_Update = TouchInterval;
    form_Numeric = new Form(Numeric_Keyboard,this);
    form_Numeric->setExternalLineEdit(ui->lineEdit_TouchInterval);
    connect(form_Numeric,SIGNAL(changevalue(QString)),this,SLOT(Serial_number(QString)));
    if(form_Numeric == NULL)
    {
        form_Numeric = new Form();//
        form_Numeric->show();
    }
    else
    {
         form_Numeric->show();
    }
#ifdef UI_Debug
    qDebug() << " keyPressed " <<"After form";
#endif
    HMI_WakeUP_Mode();
    Sleep_Timer = 0;
    touch_driver =0;
}
