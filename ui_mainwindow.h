/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "MY_LineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QLabel *label_Time;
    QPushButton *pushButton_AdminIcon;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_car;
    QPushButton *pushButton_3;
    QWidget *page_2;
    QPushButton *pushButton_CCS;
    QLabel *label_33;
    QLabel *label_CCS_Time_Front;
    QLabel *label_54;
    QLabel *label_32;
    QLabel *Status;
    QLabel *label_CCS_Amount;
    QLabel *label_58;
    QLabel *label_CCS_Status;
    QLabel *label_61;
    QLabel *label_66;
    QLabel *label_CCS_Amount_3;
    QLabel *Status_2;
    QLabel *label_CCS_Time_Front_3;
    QLabel *label_145;
    QLabel *label_143;
    QPushButton *pushButton_CCS_2;
    QLabel *label_144;
    QWidget *page_3;
    QLabel *label_RFIDimgCCS;
    QLabel *label_rfidstatus;
    QPushButton *pushButton_ChargeByPswd;
    QPushButton *pushButton_RFID_Next;
    QWidget *page_4;
    QPushButton *pushButton_Save_charging;
    QPushButton *pushButton_Back_charging;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_ChangeTime;
    QLineEdit *lineEdit_ChangeUnit;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QCheckBox *checkBox;
    QPushButton *pushButton_Keyboard_chargebytime;
    QPushButton *pushButton_Keyboard_charggebyunit;
    QLabel *label_charging_validation;
    QWidget *page_5;
    QLabel *label_waiting;
    QPushButton *pushButton_Error_Back;
    QWidget *page_6;
    QProgressBar *progressBar_CCS;
    QPushButton *pushButton_EmergencyStopCCS;
    QLabel *label_EvCurrent;
    QLabel *label_VoltageValue;
    QLabel *label_BatteryPercentage;
    QLabel *label_lbElapseTime;
    QPushButton *pushButton_Back_DuringCharging;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_Power_Consumption;
    QLabel *label_9;
    QLabel *label_Energy_Consumption;
    QLabel *label_25;
    QLabel *label_100;
    QLabel *label_Output_Power;
    QLabel *label_101;
    QLabel *label_Output_Current;
    QLabel *label_12;
    QLabel *t1_lbRemainTime;
    QLabel *lbl_ERROR_CODE;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_39;
    QLabel *label_Tempreture_plus;
    QLabel *label_Tempreture_minus;
    QLabel *label_59;
    QWidget *page_7;
    QPushButton *pushButton_CCSPayment;
    QLabel *label_Payment;
    QLabel *label_TotalPay;
    QLabel *label_41;
    QLabel *label_Paymen_Heading;
    QLabel *label_42;
    QLabel *label_CCS_ChargingEnergy;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_51;
    QLabel *label_55;
    QLabel *label_Stop_reason;
    QLabel *label_67;
    QWidget *page_8;
    QPushButton *pushButton_OuterFinishCCS;
    QPushButton *pushButton_FinishCCS;
    QLabel *label_27;
    QLabel *label_26;
    QWidget *page_15;
    QLabel *label_29;
    QLabel *label_53;
    QLabel *label_PowerConsum_AC;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_EnergyConsum_AC;
    QLabel *label_TotalEnergy_AC;
    QPushButton *pushButton_ChargingParamAC;
    QLabel *label_70;
    QLabel *label_77;
    QLabel *label_Voltage_AC;
    QLabel *label_Current_AC;
    QWidget *page_9;
    QPushButton *pushButton_Login;
    MY_LineEdit *lineEdit_Password;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_MessageLogin;
    QPushButton *pushButton_keyboard_password;
    QPushButton *pushButton_CancelLogin;
    QWidget *page_10;
    QPushButton *pushButton_chr_CancelLogin;
    QLabel *label_14;
    QLabel *label_74;
    QPushButton *pushButton_keyboard_chr_password;
    QPushButton *pushButton_chr_Login;
    QLineEdit *lineEdit_chr_Password;
    QLabel *label_Message_chr_Login;
    QWidget *page_11;
    QStackedWidget *stackedWidget_Admin;
    QWidget *page_12;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_22;
    QLineEdit *lineEdit_LocalIP;
    QLineEdit *lineEdit_GatwayIP;
    QLineEdit *lineEdit_SubnetMask;
    QPushButton *pushButton_Ether_Localip;
    QPushButton *pushButton_Ether_Gatewayip;
    QPushButton *pushButton_Ether_Subnet;
    QPushButton *pushButton_EthernetSetting;
    QPushButton *pushButton_EthernetSetting_Back;
    QCheckBox *EthernetEnable;
    QLabel *label_ethernet_status;
    QWidget *page_13;
    QLabel *label_18;
    QLabel *label_19;
    QFrame *frame;
    QLabel *label_20;
    QLabel *label_23;
    QPushButton *pushButton_Confirmocpp;
    QPushButton *pushButton_Return_OCPP;
    QLineEdit *lineEdit_URL;
    QLineEdit *lineEdit_ServerPort;
    QPushButton *pushButton_keyboard_serverPort;
    QPushButton *pushButton_Keyboard_serverURL;
    QCheckBox *OCPPEnable;
    QLabel *label_ocpp_saved;
    QWidget *page_24;
    QPushButton *pushButton_AdminEthernet;
    QPushButton *pushButton_AdminWifi;
    QPushButton *pushButton_Admin4G;
    QPushButton *pushButton_Nework_back;
    QWidget *page_25;
    QPushButton *pushButton_Signin;
    QPushButton *pushButton_Charging_psw;
    QPushButton *pushButton_Psw_Back;
    QWidget *page_26;
    QLineEdit *lineEdit_RegPassword;
    QLineEdit *lineEdit_RegConfirmPass;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_RegisterMsg;
    QPushButton *pushButton_Regi_confirmpass;
    QPushButton *pushButton_Regi_password;
    QPushButton *pushButton_SaveRegister;
    QPushButton *pushButton_BackAdminPsw;
    QWidget *page_14;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_WifiSetting;
    QLineEdit *lineEdit_SSID;
    QLineEdit *lineEdit_Password_wifi;
    QPushButton *pushButton_keyboard_SSID;
    QPushButton *pushButton_keyboard_wifiPass;
    QPushButton *pushButton_WifiSetting_back;
    QCheckBox *WIFIEnable;
    QLabel *label_wifi_saved;
    QWidget *page_16;
    QPushButton *pushButton_getOutfromPriceSett;
    QLabel *label_68;
    QLineEdit *lineEdit_Unitby_charge;
    QPushButton *pushButton_keyboard_Setting;
    QPushButton *pushButton_PriceSetting_back;
    QLabel *label_pricesetting_saved;
    QWidget *page_17;
    QPushButton *pushButton_Setting;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLineEdit *lineEdit_OverVolt;
    QLineEdit *lineEdit_UnderVolt;
    QLineEdit *lineEdit_OverCurrCCS;
    QPushButton *pushButton_keyboard_OverVolt;
    QPushButton *pushButton_keyboard_UnderVolt;
    QPushButton *pushButton_keyboard_OverCurrCCS;
    QPushButton *pushButton_Setting_Back;
    QLabel *label_Protection_saved;
    QWidget *page_20;
    QLineEdit *lineEdit_APN;
    QPushButton *pushButton_keyboard_APN;
    QLabel *label_APN;
    QRadioButton *IPv4_radioButton;
    QRadioButton *IPv6_radioButton;
    QRadioButton *IPv4v6_radioButton;
    QPushButton *pushButton_Cancel_gsm;
    QPushButton *pushButton_Save_gsm;
    QCheckBox *GSMEnable;
    QLabel *label_gsm_saved;
    QWidget *page_21;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_StartTime;
    QLineEdit *lineEdit_Txno;
    QLabel *label_46;
    QLabel *label_50;
    QLabel *label_40;
    QLabel *label_48;
    QLineEdit *lineEdit_TotalTime;
    QLabel *label_49;
    QLineEdit *lineEdit_EndTime;
    QLineEdit *lineEdit_reson;
    QLineEdit *GunNo;
    QLineEdit *lineEdit_ConsumeEnergy;
    QLabel *label_47;
    QLabel *label_31;
    QPushButton *pushbutton_history_up;
    QPushButton *pushbutton_history_clear;
    QPushButton *pushbutton_history_down;
    QPushButton *pushbutton_history_back;
    QLineEdit *Sr_No;
    QWidget *page_23;
    QLabel *label_28;
    QSlider *horizontalSlider;
    QPushButton *pushButton_KeyBord_TimeDate;
    QLabel *label_30;
    QLabel *label_52;
    QLabel *label_69;
    QPushButton *pushButton_KeyBord_sleeptime;
    QLineEdit *lineEdit_SleepTime;
    QLabel *label_71;
    QLineEdit *lineEdit_TimeZone;
    QPushButton *pushButton_KeyBord_Timezone;
    QLabel *label_72;
    QPushButton *pushButton_Save_Displaysetting;
    QPushButton *pushButton_Back_Display_setting;
    QLabel *label_displaysetting_status;
    QLineEdit *DateTime_SetTimedate;
    QWidget *page_28;
    QLineEdit *lineEdit_charging_Password;
    QLabel *label_16;
    QPushButton *pushButton_BackChargingPsw;
    QLabel *label_ChrgMsg;
    QLabel *label_73;
    QPushButton *pushButton_Chrg_password;
    QPushButton *pushButton_charging_confirmpass;
    QLineEdit *lineEdit_chrgConfirmPass;
    QPushButton *pushButton_ChargingSave;
    QListWidget *listWidget_9;
    QPushButton *pushButton_AdminOCPP;
    QPushButton *pushButton_Price_setting;
    QPushButton *pushButton_AdminSetting;
    QPushButton *pushButton_History_Page;
    QPushButton *pushButton_Display_setting;
    QPushButton *pushButton_Network;
    QPushButton *pushButton_Password;
    QWidget *page_19;
    QListWidget *listWidget_23;
    QStackedWidget *stackedWidget_Factory;
    QWidget *page_27;
    QPushButton *pushButton_Profile_Save;
    QLabel *label_Max_V;
    QLineEdit *lineEdit_Max_V;
    QPushButton *pushButton_keyboard_Max_V;
    QLineEdit *lineEdit_Max_I;
    QPushButton *pushButton_keyboard_Max_I;
    QLabel *label_Max_I;
    QLineEdit *lineEdit_Min_V;
    QPushButton *pushButton_keyboard_Min_V;
    QLabel *label_Min_V;
    QPushButton *pushButton_keyboard_Min_I;
    QLineEdit *lineEdit_Min_I;
    QLabel *label_Min_I;
    QPushButton *pushButton_keyboard_Max_P;
    QLineEdit *lineEdit_Max_P;
    QLabel *label_Max_P;
    QLineEdit *lineEdit_Min_P;
    QPushButton *pushButton_keyboard_Min_P;
    QLabel *label_Min_P;
    QPushButton *pushButton_Profile_Back;
    QLabel *label_Profiled_saved;
    QWidget *page_18;
    QPushButton *pushButton_Serial_Save;
    QPushButton *pushButton_SN_Back;
    QLabel *label_SN_saved;
    QWidget *gridWidget_2;
    QLabel *label_60;
    QLabel *label_62;
    QLabel *label_76;
    QLineEdit *lineEdit_TempProtection;
    QLineEdit *lineEdit_EndTime_CuttOfSoc;
    QCheckBox *checkBox_TempProtection;
    QLabel *label_78;
    QLineEdit *lineEdit_Serial_Number;
    QPushButton *pushButton_keyboard_Serial_Number;
    QPushButton *pushButton_keyboard_TProtection;
    QPushButton *pushButton_keyboard_CutoffSoc;
    QCheckBox *checkBox_DoorLock;
    QCheckBox *checkBox_CuttofSoc;
    QLabel *label_79;
    QCheckBox *checkBox_TestMode;
    QLabel *label_80;
    QLabel *label_81;
    QCheckBox *checkBox_GroundFault;
    QCheckBox *checkBox_IsolationFault;
    QWidget *page_22;
    QLineEdit *lineEdit_FW_password;
    QPushButton *pushButton_keyboard_FW_servername;
    QLineEdit *lineEdit_FW_username;
    QLabel *FW_S;
    QLabel *FW_P;
    QLabel *FW;
    QLabel *FW_PW;
    QPushButton *pushButton_keyboard_FW_password;
    QPushButton *pushButton_keyboard_FW_username;
    QLabel *FW_U;
    QPushButton *pushButton_FW_Update;
    QPushButton *pushButton_keyboard_FW_path;
    QLineEdit *lineEdit_FW_servername;
    QPushButton *pushButton_FW_Back;
    QLineEdit *lineEdit_FW_path;
    QWidget *page_30;
    QWidget *gridWidget_3;
    QLabel *label_85;
    QCheckBox *checkBox_LoadSharing;
    QLabel *label_86;
    QCheckBox *checkBox_PostSLSharing;
    QCheckBox *checkBox_PreSLoadsharing;
    QLabel *label_87;
    QLabel *label_88;
    QCheckBox *checkBox_PMIndividual;
    QPushButton *pushButton_keyboard_TouchInterval;
    QLabel *label_82;
    QCheckBox *checkBox_TouchInterval;
    QLineEdit *lineEdit_TouchInterval;
    QPushButton *pushButton_LS_Back;
    QPushButton *pushButton_LS_update;
    QLabel *label_LoadSharing;
    QPushButton *pushButton_AdminDcProfile;
    QPushButton *pushButton_Serial_Number;
    QPushButton *pushButton_FW;
    QPushButton *pushButton_Load_Sharing;
    QWidget *page_29;
    QPushButton *pushButton_keyboard_chr_password_8;
    QLabel *label_516;
    QLineEdit *lineEdit_chr_Password_8;
    QPushButton *pushButton_chr_Login_8;
    QPushButton *pushButton_chr_CancelLogin_8;
    QLabel *label_Message_chr_Login_8;
    QLabel *label_517;
    QLabel *label_lubi;
    QLabel *label_ocpp;
    QLabel *label_network;
    QLabel *label_TEx;
    QLabel *label_Test;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 800, 71));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setContextMenuPolicy(Qt::NoContextMenu);
#if QT_CONFIG(tooltip)
        listWidget->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        listWidget->setAutoFillBackground(false);
        listWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        listWidget->setFrameShape(QFrame::Box);
        listWidget->setFrameShadow(QFrame::Sunken);
        listWidget->setLineWidth(1);
        listWidget->setMidLineWidth(1);
        listWidget->setAutoScroll(false);
        listWidget->setAutoScrollMargin(0);
        listWidget->setAlternatingRowColors(false);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setMovement(QListView::Free);
        listWidget->setProperty("isWrapping", QVariant(true));
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setLayoutMode(QListView::Batched);
        listWidget->setSpacing(-1);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setBatchSize(98);
        label_Time = new QLabel(centralWidget);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setGeometry(QRect(120, 20, 230, 31));
        QPalette palette;
        QBrush brush(QColor(238, 238, 236, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_Time->setPalette(palette);
        QFont font;
        font.setPointSize(12);
        label_Time->setFont(font);
        pushButton_AdminIcon = new QPushButton(centralWidget);
        pushButton_AdminIcon->setObjectName(QString::fromUtf8("pushButton_AdminIcon"));
        pushButton_AdminIcon->setGeometry(QRect(690, 0, 89, 61));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_AdminIcon->sizePolicy().hasHeightForWidth());
        pushButton_AdminIcon->setSizePolicy(sizePolicy);
        pushButton_AdminIcon->setFocusPolicy(Qt::NoFocus);
        pushButton_AdminIcon->setAutoFillBackground(false);
        pushButton_AdminIcon->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Setting-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/Setting-2.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_AdminIcon->setIcon(icon);
        pushButton_AdminIcon->setIconSize(QSize(90, 62));
        pushButton_AdminIcon->setFlat(true);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 70, 800, 410));
        stackedWidget->setContextMenuPolicy(Qt::NoContextMenu);
        stackedWidget->setToolTipDuration(15);
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_car = new QLabel(page);
        label_car->setObjectName(QString::fromUtf8("label_car"));
        label_car->setGeometry(QRect(0, 10, 800, 410));
        label_car->setSizeIncrement(QSize(0, 0));
        label_car->setContextMenuPolicy(Qt::NoContextMenu);
        label_car->setAcceptDrops(false);
        label_car->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        label_car->setFrameShape(QFrame::NoFrame);
        label_car->setFrameShadow(QFrame::Plain);
        label_car->setLineWidth(0);
        label_car->setMidLineWidth(0);
        label_car->setPixmap(QPixmap(QString::fromUtf8(":/images/Welcome screen.png")));
        label_car->setScaledContents(false);
        label_car->setIndent(0);
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(658, 350, 111, 51));
        QPalette palette1;
        QBrush brush2(QColor(2, 164, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_3->setPalette(palette1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        pushButton_CCS = new QPushButton(page_2);
        pushButton_CCS->setObjectName(QString::fromUtf8("pushButton_CCS"));
        pushButton_CCS->setGeometry(QRect(80, 30, 150, 120));
        sizePolicy.setHeightForWidth(pushButton_CCS->sizePolicy().hasHeightForWidth());
        pushButton_CCS->setSizePolicy(sizePolicy);
        pushButton_CCS->setMaximumSize(QSize(16777214, 16777215));
        pushButton_CCS->setMouseTracking(false);
        pushButton_CCS->setFocusPolicy(Qt::NoFocus);
        pushButton_CCS->setToolTipDuration(-1);
        pushButton_CCS->setLayoutDirection(Qt::LeftToRight);
        pushButton_CCS->setAutoFillBackground(false);
        pushButton_CCS->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/NGUN-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_CCS->setIcon(icon1);
        pushButton_CCS->setIconSize(QSize(150, 120));
        pushButton_CCS->setAutoDefault(false);
        pushButton_CCS->setFlat(true);
        label_33 = new QLabel(page_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(70, 250, 91, 31));
        label_33->setMouseTracking(true);
        label_33->setAutoFillBackground(false);
        label_33->setTextFormat(Qt::AutoText);
        label_33->setScaledContents(true);
        label_33->setMargin(0);
        label_33->setIndent(-1);
        label_CCS_Time_Front = new QLabel(page_2);
        label_CCS_Time_Front->setObjectName(QString::fromUtf8("label_CCS_Time_Front"));
        label_CCS_Time_Front->setGeometry(QRect(210, 300, 111, 31));
        label_CCS_Time_Front->setAutoFillBackground(false);
        label_CCS_Time_Front->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_CCS_Time_Front->setFrameShape(QFrame::StyledPanel);
        label_CCS_Time_Front->setFrameShadow(QFrame::Sunken);
        label_CCS_Time_Front->setScaledContents(true);
        label_CCS_Time_Front->setTextInteractionFlags(Qt::NoTextInteraction);
        label_54 = new QLabel(page_2);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(349, 300, 41, 31));
        label_54->setAutoFillBackground(false);
        label_54->setScaledContents(true);
        label_32 = new QLabel(page_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(70, 300, 71, 41));
        label_32->setLocale(QLocale(QLocale::English, QLocale::India));
        Status = new QLabel(page_2);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setGeometry(QRect(70, 180, 141, 40));
        Status->setBaseSize(QSize(0, 0));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush3(QColor(49, 68, 82, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(238, 238, 236, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Status->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        Status->setFont(font1);
        Status->setMouseTracking(true);
        Status->setAutoFillBackground(false);
        Status->setLineWidth(0);
        Status->setScaledContents(true);
        label_CCS_Amount = new QLabel(page_2);
        label_CCS_Amount->setObjectName(QString::fromUtf8("label_CCS_Amount"));
        label_CCS_Amount->setGeometry(QRect(210, 250, 111, 31));
        label_CCS_Amount->setAutoFillBackground(false);
        label_CCS_Amount->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_CCS_Amount->setFrameShape(QFrame::StyledPanel);
        label_CCS_Amount->setFrameShadow(QFrame::Sunken);
        label_CCS_Amount->setScaledContents(true);
        label_CCS_Amount->setTextInteractionFlags(Qt::NoTextInteraction);
        label_58 = new QLabel(page_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(60, 360, 91, 31));
        label_58->setMouseTracking(true);
        label_58->setAutoFillBackground(false);
        label_58->setTextFormat(Qt::AutoText);
        label_58->setScaledContents(true);
        label_58->setMargin(0);
        label_58->setIndent(-1);
        label_CCS_Status = new QLabel(page_2);
        label_CCS_Status->setObjectName(QString::fromUtf8("label_CCS_Status"));
        label_CCS_Status->setGeometry(QRect(200, 360, 381, 31));
        label_CCS_Status->setAutoFillBackground(false);
        label_CCS_Status->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color : red; "));
        label_CCS_Status->setFrameShape(QFrame::StyledPanel);
        label_CCS_Status->setFrameShadow(QFrame::Sunken);
        label_CCS_Status->setTextFormat(Qt::PlainText);
        label_CCS_Status->setScaledContents(true);
        label_CCS_Status->setTextInteractionFlags(Qt::NoTextInteraction);
        label_61 = new QLabel(page_2);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(349, 250, 41, 31));
        label_61->setAutoFillBackground(false);
        label_61->setScaledContents(true);
        label_66 = new QLabel(page_2);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setGeometry(QRect(660, 360, 91, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        label_66->setPalette(palette3);
        label_66->setMouseTracking(true);
        label_66->setAutoFillBackground(false);
        label_66->setTextFormat(Qt::AutoText);
        label_66->setScaledContents(true);
        label_66->setMargin(0);
        label_66->setIndent(-1);
        label_CCS_Amount_3 = new QLabel(page_2);
        label_CCS_Amount_3->setObjectName(QString::fromUtf8("label_CCS_Amount_3"));
        label_CCS_Amount_3->setGeometry(QRect(600, 240, 111, 31));
        label_CCS_Amount_3->setAutoFillBackground(false);
        label_CCS_Amount_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_CCS_Amount_3->setFrameShape(QFrame::StyledPanel);
        label_CCS_Amount_3->setFrameShadow(QFrame::Sunken);
        label_CCS_Amount_3->setScaledContents(true);
        label_CCS_Amount_3->setTextInteractionFlags(Qt::NoTextInteraction);
        Status_2 = new QLabel(page_2);
        Status_2->setObjectName(QString::fromUtf8("Status_2"));
        Status_2->setGeometry(QRect(600, 170, 141, 40));
        Status_2->setBaseSize(QSize(0, 0));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Status_2->setPalette(palette4);
        Status_2->setFont(font1);
        Status_2->setMouseTracking(true);
        Status_2->setAutoFillBackground(false);
        Status_2->setLineWidth(0);
        Status_2->setScaledContents(true);
        label_CCS_Time_Front_3 = new QLabel(page_2);
        label_CCS_Time_Front_3->setObjectName(QString::fromUtf8("label_CCS_Time_Front_3"));
        label_CCS_Time_Front_3->setGeometry(QRect(600, 290, 111, 31));
        label_CCS_Time_Front_3->setAutoFillBackground(false);
        label_CCS_Time_Front_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_CCS_Time_Front_3->setFrameShape(QFrame::StyledPanel);
        label_CCS_Time_Front_3->setFrameShadow(QFrame::Sunken);
        label_CCS_Time_Front_3->setScaledContents(true);
        label_CCS_Time_Front_3->setTextInteractionFlags(Qt::NoTextInteraction);
        label_145 = new QLabel(page_2);
        label_145->setObjectName(QString::fromUtf8("label_145"));
        label_145->setGeometry(QRect(460, 290, 71, 41));
        label_145->setLocale(QLocale(QLocale::English, QLocale::India));
        label_143 = new QLabel(page_2);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        label_143->setGeometry(QRect(460, 240, 91, 31));
        label_143->setMouseTracking(true);
        label_143->setAutoFillBackground(false);
        label_143->setTextFormat(Qt::AutoText);
        label_143->setScaledContents(true);
        label_143->setMargin(0);
        label_143->setIndent(-1);
        pushButton_CCS_2 = new QPushButton(page_2);
        pushButton_CCS_2->setObjectName(QString::fromUtf8("pushButton_CCS_2"));
        pushButton_CCS_2->setGeometry(QRect(600, 20, 150, 120));
        sizePolicy.setHeightForWidth(pushButton_CCS_2->sizePolicy().hasHeightForWidth());
        pushButton_CCS_2->setSizePolicy(sizePolicy);
        pushButton_CCS_2->setMaximumSize(QSize(16777214, 16777215));
        pushButton_CCS_2->setMouseTracking(false);
        pushButton_CCS_2->setFocusPolicy(Qt::NoFocus);
        pushButton_CCS_2->setToolTipDuration(-1);
        pushButton_CCS_2->setLayoutDirection(Qt::LeftToRight);
        pushButton_CCS_2->setAutoFillBackground(false);
        pushButton_CCS_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_CCS_2->setIcon(icon1);
        pushButton_CCS_2->setIconSize(QSize(150, 120));
        pushButton_CCS_2->setAutoDefault(false);
        pushButton_CCS_2->setFlat(true);
        label_144 = new QLabel(page_2);
        label_144->setObjectName(QString::fromUtf8("label_144"));
        label_144->setGeometry(QRect(740, 290, 41, 31));
        label_144->setAutoFillBackground(false);
        label_144->setScaledContents(true);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        label_RFIDimgCCS = new QLabel(page_3);
        label_RFIDimgCCS->setObjectName(QString::fromUtf8("label_RFIDimgCCS"));
        label_RFIDimgCCS->setGeometry(QRect(130, 110, 191, 181));
        label_RFIDimgCCS->setAutoFillBackground(false);
        label_RFIDimgCCS->setPixmap(QPixmap(QString::fromUtf8(":/images/RFID.png")));
        label_rfidstatus = new QLabel(page_3);
        label_rfidstatus->setObjectName(QString::fromUtf8("label_rfidstatus"));
        label_rfidstatus->setGeometry(QRect(430, 180, 291, 101));
        label_rfidstatus->setAutoFillBackground(false);
        label_rfidstatus->setStyleSheet(QString::fromUtf8("background-color:rgb(17, 31, 55)"));
        pushButton_ChargeByPswd = new QPushButton(page_3);
        pushButton_ChargeByPswd->setObjectName(QString::fromUtf8("pushButton_ChargeByPswd"));
        pushButton_ChargeByPswd->setGeometry(QRect(460, 40, 281, 71));
        pushButton_ChargeByPswd->setContextMenuPolicy(Qt::NoContextMenu);
        pushButton_ChargeByPswd->setAutoFillBackground(false);
        pushButton_ChargeByPswd->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_ChargeByPswd->setCheckable(true);
        pushButton_ChargeByPswd->setAutoDefault(true);
        pushButton_RFID_Next = new QPushButton(page_3);
        pushButton_RFID_Next->setObjectName(QString::fromUtf8("pushButton_RFID_Next"));
        pushButton_RFID_Next->setGeometry(QRect(10, 340, 131, 51));
        pushButton_RFID_Next->setCursor(QCursor(Qt::BlankCursor));
        pushButton_RFID_Next->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_RFID_Next->setCheckable(true);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        pushButton_Save_charging = new QPushButton(page_4);
        pushButton_Save_charging->setObjectName(QString::fromUtf8("pushButton_Save_charging"));
        pushButton_Save_charging->setGeometry(QRect(600, 310, 131, 51));
        pushButton_Save_charging->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Back_charging = new QPushButton(page_4);
        pushButton_Back_charging->setObjectName(QString::fromUtf8("pushButton_Back_charging"));
        pushButton_Back_charging->setGeometry(QRect(90, 310, 131, 51));
        pushButton_Back_charging->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_10 = new QLabel(page_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 80, 140, 51));
        QFont font2;
        font2.setStyleStrategy(QFont::PreferDefault);
        label_10->setFont(font2);
        label_11 = new QLabel(page_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(100, 160, 140, 51));
        lineEdit_ChangeTime = new QLineEdit(page_4);
        lineEdit_ChangeTime->setObjectName(QString::fromUtf8("lineEdit_ChangeTime"));
        lineEdit_ChangeTime->setGeometry(QRect(280, 80, 211, 51));
        QPalette palette5;
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        lineEdit_ChangeTime->setPalette(palette5);
        lineEdit_ChangeTime->setCursor(QCursor(Qt::BlankCursor));
        lineEdit_ChangeTime->setMouseTracking(false);
        lineEdit_ChangeTime->setFocusPolicy(Qt::NoFocus);
        lineEdit_ChangeTime->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_ChangeTime->setAcceptDrops(false);
        lineEdit_ChangeTime->setAutoFillBackground(false);
        lineEdit_ChangeTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_ChangeTime->setMaxLength(20);
        lineEdit_ChangeTime->setReadOnly(true);
        lineEdit_ChangeUnit = new QLineEdit(page_4);
        lineEdit_ChangeUnit->setObjectName(QString::fromUtf8("lineEdit_ChangeUnit"));
        lineEdit_ChangeUnit->setGeometry(QRect(280, 160, 211, 51));
        lineEdit_ChangeUnit->setMouseTracking(false);
        lineEdit_ChangeUnit->setFocusPolicy(Qt::NoFocus);
        lineEdit_ChangeUnit->setAcceptDrops(false);
        lineEdit_ChangeUnit->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_ChangeUnit->setMaxLength(20);
        lineEdit_ChangeUnit->setReadOnly(true);
        label_36 = new QLabel(page_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(580, 100, 101, 31));
        label_37 = new QLabel(page_4);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(580, 170, 67, 31));
        label_38 = new QLabel(page_4);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(130, 240, 90, 51));
        checkBox = new QCheckBox(page_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(290, 240, 151, 51));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        checkBox->setPalette(palette6);
        checkBox->setTristate(true);
        pushButton_Keyboard_chargebytime = new QPushButton(page_4);
        pushButton_Keyboard_chargebytime->setObjectName(QString::fromUtf8("pushButton_Keyboard_chargebytime"));
        pushButton_Keyboard_chargebytime->setGeometry(QRect(490, 80, 61, 51));
        pushButton_Keyboard_chargebytime->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_Keyboard_charggebyunit = new QPushButton(page_4);
        pushButton_Keyboard_charggebyunit->setObjectName(QString::fromUtf8("pushButton_Keyboard_charggebyunit"));
        pushButton_Keyboard_charggebyunit->setGeometry(QRect(490, 160, 61, 51));
        pushButton_Keyboard_charggebyunit->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_charging_validation = new QLabel(page_4);
        label_charging_validation->setObjectName(QString::fromUtf8("label_charging_validation"));
        label_charging_validation->setGeometry(QRect(180, 20, 471, 21));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_waiting = new QLabel(page_5);
        label_waiting->setObjectName(QString::fromUtf8("label_waiting"));
        label_waiting->setGeometry(QRect(130, 149, 240, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        label_waiting->setPalette(palette7);
        label_waiting->setMouseTracking(true);
        label_waiting->setLocale(QLocale(QLocale::English, QLocale::India));
        label_waiting->setScaledContents(false);
        pushButton_Error_Back = new QPushButton(page_5);
        pushButton_Error_Back->setObjectName(QString::fromUtf8("pushButton_Error_Back"));
        pushButton_Error_Back->setGeometry(QRect(50, 330, 101, 41));
        pushButton_Error_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        progressBar_CCS = new QProgressBar(page_6);
        progressBar_CCS->setObjectName(QString::fromUtf8("progressBar_CCS"));
        progressBar_CCS->setGeometry(QRect(660, 100, 110, 200));
        progressBar_CCS->setFocusPolicy(Qt::StrongFocus);
        progressBar_CCS->setContextMenuPolicy(Qt::DefaultContextMenu);
        progressBar_CCS->setToolTipDuration(3);
        progressBar_CCS->setAutoFillBackground(false);
        progressBar_CCS->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(115, 210, 22);"));
        progressBar_CCS->setValue(40);
        progressBar_CCS->setOrientation(Qt::Vertical);
        pushButton_EmergencyStopCCS = new QPushButton(page_6);
        pushButton_EmergencyStopCCS->setObjectName(QString::fromUtf8("pushButton_EmergencyStopCCS"));
        pushButton_EmergencyStopCCS->setGeometry(QRect(630, 330, 131, 51));
        pushButton_EmergencyStopCCS->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_EvCurrent = new QLabel(page_6);
        label_EvCurrent->setObjectName(QString::fromUtf8("label_EvCurrent"));
        label_EvCurrent->setGeometry(QRect(170, 160, 100, 31));
        label_EvCurrent->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_EvCurrent->setFrameShape(QFrame::Panel);
        label_VoltageValue = new QLabel(page_6);
        label_VoltageValue->setObjectName(QString::fromUtf8("label_VoltageValue"));
        label_VoltageValue->setGeometry(QRect(470, 160, 100, 31));
        label_VoltageValue->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_VoltageValue->setFrameShape(QFrame::Panel);
        label_BatteryPercentage = new QLabel(page_6);
        label_BatteryPercentage->setObjectName(QString::fromUtf8("label_BatteryPercentage"));
        label_BatteryPercentage->setGeometry(QRect(690, 50, 50, 31));
        label_BatteryPercentage->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_lbElapseTime = new QLabel(page_6);
        label_lbElapseTime->setObjectName(QString::fromUtf8("label_lbElapseTime"));
        label_lbElapseTime->setGeometry(QRect(170, 270, 100, 31));
        label_lbElapseTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_lbElapseTime->setFrameShape(QFrame::Panel);
        pushButton_Back_DuringCharging = new QPushButton(page_6);
        pushButton_Back_DuringCharging->setObjectName(QString::fromUtf8("pushButton_Back_DuringCharging"));
        pushButton_Back_DuringCharging->setGeometry(QRect(40, 340, 131, 51));
        pushButton_Back_DuringCharging->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_4 = new QLabel(page_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 270, 131, 41));
        label_4->setTextFormat(Qt::RichText);
        label_5 = new QLabel(page_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 160, 21, 31));
        label_7 = new QLabel(page_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 160, 110, 40));
        label_8 = new QLabel(page_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 100, 71, 41));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("P_ac"));
        label_8->setTextFormat(Qt::RichText);
        label_Power_Consumption = new QLabel(page_6);
        label_Power_Consumption->setObjectName(QString::fromUtf8("label_Power_Consumption"));
        label_Power_Consumption->setGeometry(QRect(170, 110, 100, 31));
        QFont font4;
        font4.setUnderline(false);
        label_Power_Consumption->setFont(font4);
        label_Power_Consumption->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_Power_Consumption->setFrameShape(QFrame::Panel);
        label_9 = new QLabel(page_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(590, 110, 41, 31));
        label_9->setTextFormat(Qt::RichText);
        label_Energy_Consumption = new QLabel(page_6);
        label_Energy_Consumption->setObjectName(QString::fromUtf8("label_Energy_Consumption"));
        label_Energy_Consumption->setGeometry(QRect(470, 110, 100, 31));
        label_Energy_Consumption->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_Energy_Consumption->setFrameShape(QFrame::Panel);
        label_Energy_Consumption->setScaledContents(true);
        label_25 = new QLabel(page_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(210, 20, 321, 51));
        label_100 = new QLabel(page_6);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setGeometry(QRect(20, 210, 100, 41));
        label_Output_Power = new QLabel(page_6);
        label_Output_Power->setObjectName(QString::fromUtf8("label_Output_Power"));
        label_Output_Power->setGeometry(QRect(470, 210, 100, 31));
        label_Output_Power->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_Output_Power->setFrameShape(QFrame::Panel);
        label_Output_Power->setScaledContents(true);
        label_101 = new QLabel(page_6);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setGeometry(QRect(290, 210, 21, 41));
        label_101->setTextFormat(Qt::RichText);
        label_Output_Current = new QLabel(page_6);
        label_Output_Current->setObjectName(QString::fromUtf8("label_Output_Current"));
        label_Output_Current->setGeometry(QRect(170, 210, 100, 31));
        label_Output_Current->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_Output_Current->setFrameShape(QFrame::Panel);
        label_Output_Current->setScaledContents(true);
        label_12 = new QLabel(page_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(310, 270, 150, 41));
        t1_lbRemainTime = new QLabel(page_6);
        t1_lbRemainTime->setObjectName(QString::fromUtf8("t1_lbRemainTime"));
        t1_lbRemainTime->setGeometry(QRect(470, 270, 100, 31));
        t1_lbRemainTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        t1_lbRemainTime->setFrameShape(QFrame::Panel);
        lbl_ERROR_CODE = new QLabel(page_6);
        lbl_ERROR_CODE->setObjectName(QString::fromUtf8("lbl_ERROR_CODE"));
        lbl_ERROR_CODE->setGeometry(QRect(190, 330, 210, 30));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        lbl_ERROR_CODE->setFont(font5);
        lbl_ERROR_CODE->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:red;"));
        lbl_ERROR_CODE->setTextFormat(Qt::PlainText);
        label_34 = new QLabel(page_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(290, 110, 30, 31));
        label_34->setFont(font3);
        label_34->setStyleSheet(QString::fromUtf8("P_ac"));
        label_34->setTextFormat(Qt::RichText);
        label_35 = new QLabel(page_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(290, 160, 21, 31));
        label_35->setFont(font3);
        label_35->setStyleSheet(QString::fromUtf8("P_ac"));
        label_35->setTextFormat(Qt::RichText);
        label_39 = new QLabel(page_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(590, 210, 31, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Tlwg Mono"));
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setWeight(50);
        label_39->setFont(font6);
        label_39->setStyleSheet(QString::fromUtf8(""));
        label_39->setFrameShape(QFrame::NoFrame);
        label_39->setFrameShadow(QFrame::Sunken);
        label_39->setTextFormat(Qt::RichText);
        label_Tempreture_plus = new QLabel(page_6);
        label_Tempreture_plus->setObjectName(QString::fromUtf8("label_Tempreture_plus"));
        label_Tempreture_plus->setGeometry(QRect(420, 330, 70, 31));
        label_Tempreture_plus->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_Tempreture_minus = new QLabel(page_6);
        label_Tempreture_minus->setObjectName(QString::fromUtf8("label_Tempreture_minus"));
        label_Tempreture_minus->setGeometry(QRect(510, 330, 70, 31));
        label_Tempreture_minus->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_59 = new QLabel(page_6);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(430, 370, 110, 30));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        pushButton_CCSPayment = new QPushButton(page_7);
        pushButton_CCSPayment->setObjectName(QString::fromUtf8("pushButton_CCSPayment"));
        pushButton_CCSPayment->setGeometry(QRect(629, 340, 131, 51));
        pushButton_CCSPayment->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_Payment = new QLabel(page_7);
        label_Payment->setObjectName(QString::fromUtf8("label_Payment"));
        label_Payment->setGeometry(QRect(180, 20, 341, 41));
        label_TotalPay = new QLabel(page_7);
        label_TotalPay->setObjectName(QString::fromUtf8("label_TotalPay"));
        label_TotalPay->setGeometry(QRect(200, 220, 180, 41));
        label_TotalPay->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_41 = new QLabel(page_7);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(20, 80, 150, 31));
        label_Paymen_Heading = new QLabel(page_7);
        label_Paymen_Heading->setObjectName(QString::fromUtf8("label_Paymen_Heading"));
        label_Paymen_Heading->setGeometry(QRect(200, 80, 180, 41));
        label_Paymen_Heading->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_Paymen_Heading->setScaledContents(true);
        label_42 = new QLabel(page_7);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(20, 150, 150, 31));
        label_CCS_ChargingEnergy = new QLabel(page_7);
        label_CCS_ChargingEnergy->setObjectName(QString::fromUtf8("label_CCS_ChargingEnergy"));
        label_CCS_ChargingEnergy->setGeometry(QRect(200, 150, 180, 41));
        label_CCS_ChargingEnergy->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_43 = new QLabel(page_7);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(410, 160, 41, 31));
        label_44 = new QLabel(page_7);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(20, 210, 141, 41));
        label_45 = new QLabel(page_7);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(410, 230, 41, 31));
        label_51 = new QLabel(page_7);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(410, 90, 90, 31));
        label_55 = new QLabel(page_7);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(20, 280, 131, 41));
        label_Stop_reason = new QLabel(page_7);
        label_Stop_reason->setObjectName(QString::fromUtf8("label_Stop_reason"));
        label_Stop_reason->setGeometry(QRect(200, 290, 180, 41));
        label_Stop_reason->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        label_67 = new QLabel(page_7);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(540, 110, 221, 31));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        pushButton_OuterFinishCCS = new QPushButton(page_8);
        pushButton_OuterFinishCCS->setObjectName(QString::fromUtf8("pushButton_OuterFinishCCS"));
        pushButton_OuterFinishCCS->setGeometry(QRect(150, 140, 121, 141));
        pushButton_OuterFinishCCS->setStyleSheet(QString::fromUtf8("background-color:rgb(7, 47, 95);\n"
""));
        pushButton_FinishCCS = new QPushButton(page_8);
        pushButton_FinishCCS->setObjectName(QString::fromUtf8("pushButton_FinishCCS"));
        pushButton_FinishCCS->setGeometry(QRect(160, 150, 101, 31));
        pushButton_FinishCCS->setStyleSheet(QString::fromUtf8("background-color:rgb(127, 127, 127);\n"
"color:rgb(255, 255, 255)"));
        label_27 = new QLabel(page_8);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(450, 160, 291, 71));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        label_27->setPalette(palette8);
        label_27->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        label_26 = new QLabel(page_8);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(250, 20, 351, 41));
        label_26->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        stackedWidget->addWidget(page_8);
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        label_29 = new QLabel(page_15);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(270, 30, 321, 41));
        label_53 = new QLabel(page_15);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(70, 130, 201, 31));
        label_PowerConsum_AC = new QLabel(page_15);
        label_PowerConsum_AC->setObjectName(QString::fromUtf8("label_PowerConsum_AC"));
        label_PowerConsum_AC->setGeometry(QRect(290, 130, 111, 31));
        label_PowerConsum_AC->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_56 = new QLabel(page_15);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(70, 210, 170, 41));
        label_57 = new QLabel(page_15);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(70, 300, 150, 41));
        label_EnergyConsum_AC = new QLabel(page_15);
        label_EnergyConsum_AC->setObjectName(QString::fromUtf8("label_EnergyConsum_AC"));
        label_EnergyConsum_AC->setGeometry(QRect(290, 220, 111, 31));
        label_EnergyConsum_AC->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_TotalEnergy_AC = new QLabel(page_15);
        label_TotalEnergy_AC->setObjectName(QString::fromUtf8("label_TotalEnergy_AC"));
        label_TotalEnergy_AC->setGeometry(QRect(290, 300, 111, 31));
        label_TotalEnergy_AC->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_ChargingParamAC = new QPushButton(page_15);
        pushButton_ChargingParamAC->setObjectName(QString::fromUtf8("pushButton_ChargingParamAC"));
        pushButton_ChargingParamAC->setGeometry(QRect(650, 350, 89, 51));
        pushButton_ChargingParamAC->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_70 = new QLabel(page_15);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(510, 130, 67, 30));
        label_77 = new QLabel(page_15);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setGeometry(QRect(510, 230, 67, 30));
        label_Voltage_AC = new QLabel(page_15);
        label_Voltage_AC->setObjectName(QString::fromUtf8("label_Voltage_AC"));
        label_Voltage_AC->setGeometry(QRect(630, 130, 111, 31));
        label_Voltage_AC->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_Current_AC = new QLabel(page_15);
        label_Current_AC->setObjectName(QString::fromUtf8("label_Current_AC"));
        label_Current_AC->setGeometry(QRect(630, 230, 111, 31));
        label_Current_AC->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_15);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        pushButton_Login = new QPushButton(page_9);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setGeometry(QRect(350, 230, 101, 41));
        pushButton_Login->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        lineEdit_Password = new MY_LineEdit(page_9);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(270, 140, 231, 50));
        lineEdit_Password->setCursor(QCursor(Qt::BlankCursor));
        lineEdit_Password->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lineEdit_Password->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_Password->setMaxLength(50);
        lineEdit_Password->setFrame(false);
        lineEdit_Password->setReadOnly(true);
        lineEdit_Password->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_Password->setClearButtonEnabled(true);
        label_6 = new QLabel(page_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(370, 70, 101, 50));
        label_13 = new QLabel(page_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(130, 150, 110, 21));
        label_MessageLogin = new QLabel(page_9);
        label_MessageLogin->setObjectName(QString::fromUtf8("label_MessageLogin"));
        label_MessageLogin->setGeometry(QRect(240, 310, 331, 31));
        pushButton_keyboard_password = new QPushButton(page_9);
        pushButton_keyboard_password->setObjectName(QString::fromUtf8("pushButton_keyboard_password"));
        pushButton_keyboard_password->setGeometry(QRect(500, 140, 70, 51));
        pushButton_keyboard_password->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_CancelLogin = new QPushButton(page_9);
        pushButton_CancelLogin->setObjectName(QString::fromUtf8("pushButton_CancelLogin"));
        pushButton_CancelLogin->setGeometry(QRect(20, 350, 101, 41));
        pushButton_CancelLogin->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        pushButton_chr_CancelLogin = new QPushButton(page_10);
        pushButton_chr_CancelLogin->setObjectName(QString::fromUtf8("pushButton_chr_CancelLogin"));
        pushButton_chr_CancelLogin->setGeometry(QRect(30, 350, 101, 41));
        pushButton_chr_CancelLogin->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_14 = new QLabel(page_10);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(320, 80, 240, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 16pt \"Ubuntu\";\n"
""));
        label_74 = new QLabel(page_10);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setGeometry(QRect(150, 170, 101, 21));
        pushButton_keyboard_chr_password = new QPushButton(page_10);
        pushButton_keyboard_chr_password->setObjectName(QString::fromUtf8("pushButton_keyboard_chr_password"));
        pushButton_keyboard_chr_password->setGeometry(QRect(520, 160, 51, 51));
        pushButton_keyboard_chr_password->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_chr_Login = new QPushButton(page_10);
        pushButton_chr_Login->setObjectName(QString::fromUtf8("pushButton_chr_Login"));
        pushButton_chr_Login->setGeometry(QRect(380, 250, 101, 41));
        pushButton_chr_Login->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        lineEdit_chr_Password = new QLineEdit(page_10);
        lineEdit_chr_Password->setObjectName(QString::fromUtf8("lineEdit_chr_Password"));
        lineEdit_chr_Password->setGeometry(QRect(290, 160, 231, 50));
        lineEdit_chr_Password->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lineEdit_chr_Password->setMaxLength(50);
        lineEdit_chr_Password->setFrame(false);
        lineEdit_chr_Password->setClearButtonEnabled(true);
        label_Message_chr_Login = new QLabel(page_10);
        label_Message_chr_Login->setObjectName(QString::fromUtf8("label_Message_chr_Login"));
        label_Message_chr_Login->setGeometry(QRect(270, 330, 331, 31));
        label_Message_chr_Login->setStyleSheet(QString::fromUtf8("color:red;"));
        stackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        stackedWidget_Admin = new QStackedWidget(page_11);
        stackedWidget_Admin->setObjectName(QString::fromUtf8("stackedWidget_Admin"));
        stackedWidget_Admin->setGeometry(QRect(140, -10, 681, 441));
        stackedWidget_Admin->setStyleSheet(QString::fromUtf8("color : white"));
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        label_21 = new QLabel(page_12);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(110, 70, 90, 21));
        label_24 = new QLabel(page_12);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(110, 190, 120, 31));
        label_22 = new QLabel(page_12);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(110, 140, 90, 21));
        lineEdit_LocalIP = new QLineEdit(page_12);
        lineEdit_LocalIP->setObjectName(QString::fromUtf8("lineEdit_LocalIP"));
        lineEdit_LocalIP->setGeometry(QRect(250, 70, 281, 41));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush12(QColor(0, 0, 0, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        lineEdit_LocalIP->setPalette(palette9);
        lineEdit_LocalIP->setAcceptDrops(false);
        lineEdit_LocalIP->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:black"));
        lineEdit_GatwayIP = new QLineEdit(page_12);
        lineEdit_GatwayIP->setObjectName(QString::fromUtf8("lineEdit_GatwayIP"));
        lineEdit_GatwayIP->setGeometry(QRect(250, 130, 281, 41));
        lineEdit_GatwayIP->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_SubnetMask = new QLineEdit(page_12);
        lineEdit_SubnetMask->setObjectName(QString::fromUtf8("lineEdit_SubnetMask"));
        lineEdit_SubnetMask->setGeometry(QRect(250, 190, 281, 41));
        lineEdit_SubnetMask->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        pushButton_Ether_Localip = new QPushButton(page_12);
        pushButton_Ether_Localip->setObjectName(QString::fromUtf8("pushButton_Ether_Localip"));
        pushButton_Ether_Localip->setGeometry(QRect(530, 70, 70, 41));
        pushButton_Ether_Localip->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_Ether_Gatewayip = new QPushButton(page_12);
        pushButton_Ether_Gatewayip->setObjectName(QString::fromUtf8("pushButton_Ether_Gatewayip"));
        pushButton_Ether_Gatewayip->setGeometry(QRect(530, 130, 70, 41));
        pushButton_Ether_Gatewayip->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_Ether_Subnet = new QPushButton(page_12);
        pushButton_Ether_Subnet->setObjectName(QString::fromUtf8("pushButton_Ether_Subnet"));
        pushButton_Ether_Subnet->setGeometry(QRect(530, 190, 70, 41));
        pushButton_Ether_Subnet->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_EthernetSetting = new QPushButton(page_12);
        pushButton_EthernetSetting->setObjectName(QString::fromUtf8("pushButton_EthernetSetting"));
        pushButton_EthernetSetting->setGeometry(QRect(480, 290, 131, 51));
        pushButton_EthernetSetting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_EthernetSetting_Back = new QPushButton(page_12);
        pushButton_EthernetSetting_Back->setObjectName(QString::fromUtf8("pushButton_EthernetSetting_Back"));
        pushButton_EthernetSetting_Back->setGeometry(QRect(80, 290, 131, 51));
        pushButton_EthernetSetting_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        EthernetEnable = new QCheckBox(page_12);
        EthernetEnable->setObjectName(QString::fromUtf8("EthernetEnable"));
        EthernetEnable->setGeometry(QRect(280, 260, 121, 41));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        EthernetEnable->setPalette(palette10);
        label_ethernet_status = new QLabel(page_12);
        label_ethernet_status->setObjectName(QString::fromUtf8("label_ethernet_status"));
        label_ethernet_status->setGeometry(QRect(130, 30, 471, 21));
        label_ethernet_status->setAutoFillBackground(false);
        label_ethernet_status->setStyleSheet(QString::fromUtf8("color :  yellow;"));
        stackedWidget_Admin->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        label_18 = new QLabel(page_13);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(80, 80, 271, 31));
        label_19 = new QLabel(page_13);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(80, 140, 161, 31));
        frame = new QFrame(page_13);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(370, 80, 121, 41));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 10, 91, 21));
        label_23 = new QLabel(page_13);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(80, 200, 151, 31));
        pushButton_Confirmocpp = new QPushButton(page_13);
        pushButton_Confirmocpp->setObjectName(QString::fromUtf8("pushButton_Confirmocpp"));
        pushButton_Confirmocpp->setGeometry(QRect(480, 290, 131, 51));
        pushButton_Confirmocpp->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Return_OCPP = new QPushButton(page_13);
        pushButton_Return_OCPP->setObjectName(QString::fromUtf8("pushButton_Return_OCPP"));
        pushButton_Return_OCPP->setGeometry(QRect(80, 290, 131, 51));
        pushButton_Return_OCPP->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        lineEdit_URL = new QLineEdit(page_13);
        lineEdit_URL->setObjectName(QString::fromUtf8("lineEdit_URL"));
        lineEdit_URL->setGeometry(QRect(270, 140, 291, 41));
        lineEdit_URL->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_URL->setMaxLength(32809);
        lineEdit_URL->setReadOnly(true);
        lineEdit_ServerPort = new QLineEdit(page_13);
        lineEdit_ServerPort->setObjectName(QString::fromUtf8("lineEdit_ServerPort"));
        lineEdit_ServerPort->setGeometry(QRect(270, 200, 131, 41));
        lineEdit_ServerPort->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_ServerPort->setReadOnly(true);
        pushButton_keyboard_serverPort = new QPushButton(page_13);
        pushButton_keyboard_serverPort->setObjectName(QString::fromUtf8("pushButton_keyboard_serverPort"));
        pushButton_keyboard_serverPort->setGeometry(QRect(400, 200, 70, 41));
        pushButton_keyboard_serverPort->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_Keyboard_serverURL = new QPushButton(page_13);
        pushButton_Keyboard_serverURL->setObjectName(QString::fromUtf8("pushButton_Keyboard_serverURL"));
        pushButton_Keyboard_serverURL->setGeometry(QRect(560, 140, 70, 41));
        pushButton_Keyboard_serverURL->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        OCPPEnable = new QCheckBox(page_13);
        OCPPEnable->setObjectName(QString::fromUtf8("OCPPEnable"));
        OCPPEnable->setGeometry(QRect(270, 260, 111, 41));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        OCPPEnable->setPalette(palette11);
        label_ocpp_saved = new QLabel(page_13);
        label_ocpp_saved->setObjectName(QString::fromUtf8("label_ocpp_saved"));
        label_ocpp_saved->setGeometry(QRect(110, 30, 431, 21));
        label_ocpp_saved->setLayoutDirection(Qt::LeftToRight);
        label_ocpp_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        label_ocpp_saved->setTextFormat(Qt::PlainText);
        stackedWidget_Admin->addWidget(page_13);
        page_24 = new QWidget();
        page_24->setObjectName(QString::fromUtf8("page_24"));
        pushButton_AdminEthernet = new QPushButton(page_24);
        pushButton_AdminEthernet->setObjectName(QString::fromUtf8("pushButton_AdminEthernet"));
        pushButton_AdminEthernet->setGeometry(QRect(430, 130, 110, 37));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush14(QColor(255, 255, 255, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush15(QColor(255, 255, 255, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush15);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush16(QColor(255, 255, 255, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        pushButton_AdminEthernet->setPalette(palette12);
        pushButton_AdminEthernet->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_AdminWifi = new QPushButton(page_24);
        pushButton_AdminWifi->setObjectName(QString::fromUtf8("pushButton_AdminWifi"));
        pushButton_AdminWifi->setGeometry(QRect(250, 130, 111, 37));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush17(QColor(255, 255, 255, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush17);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush18(QColor(255, 255, 255, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush18);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush19(QColor(255, 255, 255, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        pushButton_AdminWifi->setPalette(palette13);
        pushButton_AdminWifi->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Admin4G = new QPushButton(page_24);
        pushButton_Admin4G->setObjectName(QString::fromUtf8("pushButton_Admin4G"));
        pushButton_Admin4G->setGeometry(QRect(60, 130, 110, 37));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush20(QColor(255, 255, 255, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush20);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush21(QColor(255, 255, 255, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush21);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush22(QColor(255, 255, 255, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush22);
#endif
        pushButton_Admin4G->setPalette(palette14);
        pushButton_Admin4G->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Nework_back = new QPushButton(page_24);
        pushButton_Nework_back->setObjectName(QString::fromUtf8("pushButton_Nework_back"));
        pushButton_Nework_back->setGeometry(QRect(20, 340, 131, 51));
        pushButton_Nework_back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget_Admin->addWidget(page_24);
        page_25 = new QWidget();
        page_25->setObjectName(QString::fromUtf8("page_25"));
        pushButton_Signin = new QPushButton(page_25);
        pushButton_Signin->setObjectName(QString::fromUtf8("pushButton_Signin"));
        pushButton_Signin->setGeometry(QRect(50, 110, 191, 37));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush23(QColor(255, 255, 255, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush23);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush24(QColor(255, 255, 255, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush24);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush25(QColor(255, 255, 255, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush25);
#endif
        pushButton_Signin->setPalette(palette15);
        pushButton_Signin->setAutoFillBackground(false);
        pushButton_Signin->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Signin->setFlat(false);
        pushButton_Charging_psw = new QPushButton(page_25);
        pushButton_Charging_psw->setObjectName(QString::fromUtf8("pushButton_Charging_psw"));
        pushButton_Charging_psw->setGeometry(QRect(340, 110, 191, 37));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush26(QColor(255, 255, 255, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush26);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush27(QColor(255, 255, 255, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush27);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush28(QColor(255, 255, 255, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush28);
#endif
        pushButton_Charging_psw->setPalette(palette16);
        pushButton_Charging_psw->setAutoFillBackground(false);
        pushButton_Charging_psw->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Charging_psw->setFlat(false);
        pushButton_Psw_Back = new QPushButton(page_25);
        pushButton_Psw_Back->setObjectName(QString::fromUtf8("pushButton_Psw_Back"));
        pushButton_Psw_Back->setGeometry(QRect(20, 340, 131, 51));
        pushButton_Psw_Back->setAutoFillBackground(false);
        pushButton_Psw_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Psw_Back->setAutoDefault(true);
        stackedWidget_Admin->addWidget(page_25);
        page_26 = new QWidget();
        page_26->setObjectName(QString::fromUtf8("page_26"));
        lineEdit_RegPassword = new QLineEdit(page_26);
        lineEdit_RegPassword->setObjectName(QString::fromUtf8("lineEdit_RegPassword"));
        lineEdit_RegPassword->setGeometry(QRect(270, 140, 231, 41));
        lineEdit_RegPassword->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color: black;"));
        lineEdit_RegConfirmPass = new QLineEdit(page_26);
        lineEdit_RegConfirmPass->setObjectName(QString::fromUtf8("lineEdit_RegConfirmPass"));
        lineEdit_RegConfirmPass->setGeometry(QRect(270, 210, 231, 41));
        lineEdit_RegConfirmPass->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        label_15 = new QLabel(page_26);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(60, 150, 140, 31));
        label_17 = new QLabel(page_26);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(60, 210, 180, 31));
        label_RegisterMsg = new QLabel(page_26);
        label_RegisterMsg->setObjectName(QString::fromUtf8("label_RegisterMsg"));
        label_RegisterMsg->setGeometry(QRect(110, 60, 331, 21));
        pushButton_Regi_confirmpass = new QPushButton(page_26);
        pushButton_Regi_confirmpass->setObjectName(QString::fromUtf8("pushButton_Regi_confirmpass"));
        pushButton_Regi_confirmpass->setGeometry(QRect(500, 210, 70, 41));
        pushButton_Regi_confirmpass->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_Regi_password = new QPushButton(page_26);
        pushButton_Regi_password->setObjectName(QString::fromUtf8("pushButton_Regi_password"));
        pushButton_Regi_password->setGeometry(QRect(500, 140, 70, 41));
        pushButton_Regi_password->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_SaveRegister = new QPushButton(page_26);
        pushButton_SaveRegister->setObjectName(QString::fromUtf8("pushButton_SaveRegister"));
        pushButton_SaveRegister->setGeometry(QRect(460, 330, 131, 51));
        pushButton_SaveRegister->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_BackAdminPsw = new QPushButton(page_26);
        pushButton_BackAdminPsw->setObjectName(QString::fromUtf8("pushButton_BackAdminPsw"));
        pushButton_BackAdminPsw->setGeometry(QRect(40, 320, 131, 51));
        pushButton_BackAdminPsw->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget_Admin->addWidget(page_26);
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        label = new QLabel(page_14);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 80, 50, 31));
        label_3 = new QLabel(page_14);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 150, 100, 31));
        pushButton_WifiSetting = new QPushButton(page_14);
        pushButton_WifiSetting->setObjectName(QString::fromUtf8("pushButton_WifiSetting"));
        pushButton_WifiSetting->setGeometry(QRect(480, 290, 131, 51));
        pushButton_WifiSetting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        lineEdit_SSID = new QLineEdit(page_14);
        lineEdit_SSID->setObjectName(QString::fromUtf8("lineEdit_SSID"));
        lineEdit_SSID->setGeometry(QRect(240, 80, 261, 41));
        lineEdit_SSID->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_SSID->setMaxLength(50);
        lineEdit_SSID->setReadOnly(true);
        lineEdit_Password_wifi = new QLineEdit(page_14);
        lineEdit_Password_wifi->setObjectName(QString::fromUtf8("lineEdit_Password_wifi"));
        lineEdit_Password_wifi->setGeometry(QRect(240, 140, 261, 41));
        lineEdit_Password_wifi->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_Password_wifi->setMaxLength(50);
        lineEdit_Password_wifi->setReadOnly(true);
        pushButton_keyboard_SSID = new QPushButton(page_14);
        pushButton_keyboard_SSID->setObjectName(QString::fromUtf8("pushButton_keyboard_SSID"));
        pushButton_keyboard_SSID->setGeometry(QRect(500, 80, 70, 41));
        pushButton_keyboard_SSID->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_wifiPass = new QPushButton(page_14);
        pushButton_keyboard_wifiPass->setObjectName(QString::fromUtf8("pushButton_keyboard_wifiPass"));
        pushButton_keyboard_wifiPass->setGeometry(QRect(500, 140, 70, 41));
        pushButton_keyboard_wifiPass->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_WifiSetting_back = new QPushButton(page_14);
        pushButton_WifiSetting_back->setObjectName(QString::fromUtf8("pushButton_WifiSetting_back"));
        pushButton_WifiSetting_back->setGeometry(QRect(80, 290, 131, 51));
        pushButton_WifiSetting_back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        WIFIEnable = new QCheckBox(page_14);
        WIFIEnable->setObjectName(QString::fromUtf8("WIFIEnable"));
        WIFIEnable->setGeometry(QRect(301, 230, 111, 41));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        WIFIEnable->setPalette(palette17);
        label_wifi_saved = new QLabel(page_14);
        label_wifi_saved->setObjectName(QString::fromUtf8("label_wifi_saved"));
        label_wifi_saved->setGeometry(QRect(130, 30, 431, 21));
        label_wifi_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        stackedWidget_Admin->addWidget(page_14);
        page_16 = new QWidget();
        page_16->setObjectName(QString::fromUtf8("page_16"));
        pushButton_getOutfromPriceSett = new QPushButton(page_16);
        pushButton_getOutfromPriceSett->setObjectName(QString::fromUtf8("pushButton_getOutfromPriceSett"));
        pushButton_getOutfromPriceSett->setGeometry(QRect(480, 290, 131, 51));
        pushButton_getOutfromPriceSett->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_68 = new QLabel(page_16);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setGeometry(QRect(110, 140, 130, 41));
        lineEdit_Unitby_charge = new QLineEdit(page_16);
        lineEdit_Unitby_charge->setObjectName(QString::fromUtf8("lineEdit_Unitby_charge"));
        lineEdit_Unitby_charge->setGeometry(QRect(260, 140, 180, 41));
        lineEdit_Unitby_charge->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_Unitby_charge->setMaxLength(4);
        lineEdit_Unitby_charge->setReadOnly(true);
        pushButton_keyboard_Setting = new QPushButton(page_16);
        pushButton_keyboard_Setting->setObjectName(QString::fromUtf8("pushButton_keyboard_Setting"));
        pushButton_keyboard_Setting->setGeometry(QRect(440, 140, 70, 40));
        pushButton_keyboard_Setting->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_PriceSetting_back = new QPushButton(page_16);
        pushButton_PriceSetting_back->setObjectName(QString::fromUtf8("pushButton_PriceSetting_back"));
        pushButton_PriceSetting_back->setGeometry(QRect(80, 290, 131, 51));
        pushButton_PriceSetting_back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_pricesetting_saved = new QLabel(page_16);
        label_pricesetting_saved->setObjectName(QString::fromUtf8("label_pricesetting_saved"));
        label_pricesetting_saved->setGeometry(QRect(130, 40, 431, 21));
        label_pricesetting_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        stackedWidget_Admin->addWidget(page_16);
        page_17 = new QWidget();
        page_17->setObjectName(QString::fromUtf8("page_17"));
        pushButton_Setting = new QPushButton(page_17);
        pushButton_Setting->setObjectName(QString::fromUtf8("pushButton_Setting"));
        pushButton_Setting->setGeometry(QRect(480, 290, 131, 51));
        pushButton_Setting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_63 = new QLabel(page_17);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(120, 80, 130, 31));
        label_64 = new QLabel(page_17);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(120, 140, 140, 31));
        label_65 = new QLabel(page_17);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(120, 210, 150, 31));
        lineEdit_OverVolt = new QLineEdit(page_17);
        lineEdit_OverVolt->setObjectName(QString::fromUtf8("lineEdit_OverVolt"));
        lineEdit_OverVolt->setGeometry(QRect(280, 80, 180, 41));
        lineEdit_OverVolt->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_OverVolt->setMaxLength(4);
        lineEdit_OverVolt->setReadOnly(true);
        lineEdit_UnderVolt = new QLineEdit(page_17);
        lineEdit_UnderVolt->setObjectName(QString::fromUtf8("lineEdit_UnderVolt"));
        lineEdit_UnderVolt->setGeometry(QRect(280, 140, 180, 41));
        lineEdit_UnderVolt->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_UnderVolt->setMaxLength(4);
        lineEdit_UnderVolt->setReadOnly(true);
        lineEdit_OverCurrCCS = new QLineEdit(page_17);
        lineEdit_OverCurrCCS->setObjectName(QString::fromUtf8("lineEdit_OverCurrCCS"));
        lineEdit_OverCurrCCS->setGeometry(QRect(280, 200, 180, 41));
        lineEdit_OverCurrCCS->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        lineEdit_OverCurrCCS->setMaxLength(4);
        lineEdit_OverCurrCCS->setReadOnly(true);
        pushButton_keyboard_OverVolt = new QPushButton(page_17);
        pushButton_keyboard_OverVolt->setObjectName(QString::fromUtf8("pushButton_keyboard_OverVolt"));
        pushButton_keyboard_OverVolt->setGeometry(QRect(460, 80, 70, 41));
        pushButton_keyboard_OverVolt->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_UnderVolt = new QPushButton(page_17);
        pushButton_keyboard_UnderVolt->setObjectName(QString::fromUtf8("pushButton_keyboard_UnderVolt"));
        pushButton_keyboard_UnderVolt->setGeometry(QRect(460, 140, 70, 41));
        pushButton_keyboard_UnderVolt->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_OverCurrCCS = new QPushButton(page_17);
        pushButton_keyboard_OverCurrCCS->setObjectName(QString::fromUtf8("pushButton_keyboard_OverCurrCCS"));
        pushButton_keyboard_OverCurrCCS->setGeometry(QRect(460, 200, 70, 41));
        pushButton_keyboard_OverCurrCCS->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_Setting_Back = new QPushButton(page_17);
        pushButton_Setting_Back->setObjectName(QString::fromUtf8("pushButton_Setting_Back"));
        pushButton_Setting_Back->setGeometry(QRect(80, 290, 131, 51));
        pushButton_Setting_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_Protection_saved = new QLabel(page_17);
        label_Protection_saved->setObjectName(QString::fromUtf8("label_Protection_saved"));
        label_Protection_saved->setGeometry(QRect(150, 30, 431, 21));
        label_Protection_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        stackedWidget_Admin->addWidget(page_17);
        page_20 = new QWidget();
        page_20->setObjectName(QString::fromUtf8("page_20"));
        lineEdit_APN = new QLineEdit(page_20);
        lineEdit_APN->setObjectName(QString::fromUtf8("lineEdit_APN"));
        lineEdit_APN->setGeometry(QRect(170, 100, 180, 41));
        lineEdit_APN->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_APN->setMaxLength(50);
        lineEdit_APN->setReadOnly(true);
        pushButton_keyboard_APN = new QPushButton(page_20);
        pushButton_keyboard_APN->setObjectName(QString::fromUtf8("pushButton_keyboard_APN"));
        pushButton_keyboard_APN->setGeometry(QRect(350, 100, 70, 41));
        pushButton_keyboard_APN->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_APN = new QLabel(page_20);
        label_APN->setObjectName(QString::fromUtf8("label_APN"));
        label_APN->setGeometry(QRect(100, 110, 60, 30));
        IPv4_radioButton = new QRadioButton(page_20);
        IPv4_radioButton->setObjectName(QString::fromUtf8("IPv4_radioButton"));
        IPv4_radioButton->setGeometry(QRect(170, 170, 80, 23));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush29(QColor(239, 41, 41, 128));
        brush29.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush29);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush29);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        IPv4_radioButton->setPalette(palette18);
        IPv4_radioButton->setAutoFillBackground(false);
        IPv4_radioButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu\";"));
        IPv4_radioButton->setIconSize(QSize(23, 23));
        IPv6_radioButton = new QRadioButton(page_20);
        IPv6_radioButton->setObjectName(QString::fromUtf8("IPv6_radioButton"));
        IPv6_radioButton->setGeometry(QRect(300, 170, 80, 23));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush29);
#endif
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush29);
#endif
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        IPv6_radioButton->setPalette(palette19);
        IPv6_radioButton->setAutoFillBackground(false);
        IPv6_radioButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu\";"));
        IPv4v6_radioButton = new QRadioButton(page_20);
        IPv4v6_radioButton->setObjectName(QString::fromUtf8("IPv4v6_radioButton"));
        IPv4v6_radioButton->setGeometry(QRect(410, 170, 80, 23));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush29);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush29);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        IPv4v6_radioButton->setPalette(palette20);
        IPv4v6_radioButton->setAutoFillBackground(false);
        IPv4v6_radioButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu\";"));
        pushButton_Cancel_gsm = new QPushButton(page_20);
        pushButton_Cancel_gsm->setObjectName(QString::fromUtf8("pushButton_Cancel_gsm"));
        pushButton_Cancel_gsm->setGeometry(QRect(80, 290, 131, 51));
        pushButton_Cancel_gsm->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Save_gsm = new QPushButton(page_20);
        pushButton_Save_gsm->setObjectName(QString::fromUtf8("pushButton_Save_gsm"));
        pushButton_Save_gsm->setGeometry(QRect(480, 290, 131, 51));
        pushButton_Save_gsm->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        GSMEnable = new QCheckBox(page_20);
        GSMEnable->setObjectName(QString::fromUtf8("GSMEnable"));
        GSMEnable->setGeometry(QRect(270, 240, 121, 51));
        GSMEnable->setBaseSize(QSize(0, 0));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette21.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        GSMEnable->setPalette(palette21);
        label_gsm_saved = new QLabel(page_20);
        label_gsm_saved->setObjectName(QString::fromUtf8("label_gsm_saved"));
        label_gsm_saved->setGeometry(QRect(100, 40, 431, 21));
        label_gsm_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        stackedWidget_Admin->addWidget(page_20);
        page_21 = new QWidget();
        page_21->setObjectName(QString::fromUtf8("page_21"));
        gridLayoutWidget = new QWidget(page_21);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 531, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 10);
        lineEdit_StartTime = new QLineEdit(gridLayoutWidget);
        lineEdit_StartTime->setObjectName(QString::fromUtf8("lineEdit_StartTime"));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush30(QColor(239, 41, 41, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette22.setBrush(QPalette::Active, QPalette::BrightText, brush30);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush31(QColor(0, 0, 0, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Active, QPalette::PlaceholderText, brush31);
#endif
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::BrightText, brush30);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush32(QColor(0, 0, 0, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush32);
#endif
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::BrightText, brush30);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        QBrush brush33(QColor(0, 0, 0, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush33);
#endif
        lineEdit_StartTime->setPalette(palette22);
        lineEdit_StartTime->setCursor(QCursor(Qt::BlankCursor));
        lineEdit_StartTime->setMouseTracking(false);
        lineEdit_StartTime->setFocusPolicy(Qt::StrongFocus);
        lineEdit_StartTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_StartTime->setMaxLength(50);
        lineEdit_StartTime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_StartTime, 2, 1, 1, 1);

        lineEdit_Txno = new QLineEdit(gridLayoutWidget);
        lineEdit_Txno->setObjectName(QString::fromUtf8("lineEdit_Txno"));
        lineEdit_Txno->setMouseTracking(false);
        lineEdit_Txno->setFocusPolicy(Qt::NoFocus);
        lineEdit_Txno->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_Txno->setReadOnly(true);

        gridLayout->addWidget(lineEdit_Txno, 1, 1, 1, 1);

        label_46 = new QLabel(gridLayoutWidget);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout->addWidget(label_46, 2, 0, 1, 1);

        label_50 = new QLabel(gridLayoutWidget);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout->addWidget(label_50, 6, 0, 1, 1);

        label_40 = new QLabel(gridLayoutWidget);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout->addWidget(label_40, 1, 0, 1, 1);

        label_48 = new QLabel(gridLayoutWidget);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout->addWidget(label_48, 4, 0, 1, 1);

        lineEdit_TotalTime = new QLineEdit(gridLayoutWidget);
        lineEdit_TotalTime->setObjectName(QString::fromUtf8("lineEdit_TotalTime"));
        lineEdit_TotalTime->setMouseTracking(false);
        lineEdit_TotalTime->setFocusPolicy(Qt::NoFocus);
        lineEdit_TotalTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_TotalTime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_TotalTime, 4, 1, 1, 1);

        label_49 = new QLabel(gridLayoutWidget);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout->addWidget(label_49, 5, 0, 1, 1);

        lineEdit_EndTime = new QLineEdit(gridLayoutWidget);
        lineEdit_EndTime->setObjectName(QString::fromUtf8("lineEdit_EndTime"));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette23.setBrush(QPalette::Active, QPalette::BrightText, brush30);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette23.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette23.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush34(QColor(0, 0, 0, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Active, QPalette::PlaceholderText, brush34);
#endif
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::BrightText, brush30);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette23.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush35(QColor(0, 0, 0, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush35);
#endif
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::BrightText, brush30);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette23.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        QBrush brush36(QColor(0, 0, 0, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush36);
#endif
        lineEdit_EndTime->setPalette(palette23);
        lineEdit_EndTime->setMouseTracking(false);
        lineEdit_EndTime->setFocusPolicy(Qt::NoFocus);
        lineEdit_EndTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_EndTime->setReadOnly(true);

        gridLayout->addWidget(lineEdit_EndTime, 3, 1, 1, 1);

        lineEdit_reson = new QLineEdit(gridLayoutWidget);
        lineEdit_reson->setObjectName(QString::fromUtf8("lineEdit_reson"));
        lineEdit_reson->setMouseTracking(false);
        lineEdit_reson->setFocusPolicy(Qt::NoFocus);
        lineEdit_reson->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_reson->setReadOnly(true);

        gridLayout->addWidget(lineEdit_reson, 6, 1, 1, 1);

        GunNo = new QLineEdit(gridLayoutWidget);
        GunNo->setObjectName(QString::fromUtf8("GunNo"));
        GunNo->setMouseTracking(false);
        GunNo->setFocusPolicy(Qt::NoFocus);
        GunNo->setAutoFillBackground(false);
        GunNo->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        GunNo->setReadOnly(true);

        gridLayout->addWidget(GunNo, 0, 1, 1, 1);

        lineEdit_ConsumeEnergy = new QLineEdit(gridLayoutWidget);
        lineEdit_ConsumeEnergy->setObjectName(QString::fromUtf8("lineEdit_ConsumeEnergy"));
        lineEdit_ConsumeEnergy->setMouseTracking(false);
        lineEdit_ConsumeEnergy->setFocusPolicy(Qt::NoFocus);
        lineEdit_ConsumeEnergy->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_ConsumeEnergy->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ConsumeEnergy, 5, 1, 1, 1);

        label_47 = new QLabel(gridLayoutWidget);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout->addWidget(label_47, 3, 0, 1, 1);

        label_31 = new QLabel(gridLayoutWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout->addWidget(label_31, 0, 0, 1, 1);

        pushbutton_history_up = new QPushButton(page_21);
        pushbutton_history_up->setObjectName(QString::fromUtf8("pushbutton_history_up"));
        pushbutton_history_up->setGeometry(QRect(150, 360, 89, 41));
        pushbutton_history_up->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushbutton_history_clear = new QPushButton(page_21);
        pushbutton_history_clear->setObjectName(QString::fromUtf8("pushbutton_history_clear"));
        pushbutton_history_clear->setGeometry(QRect(10, 360, 89, 41));
        pushbutton_history_clear->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushbutton_history_down = new QPushButton(page_21);
        pushbutton_history_down->setObjectName(QString::fromUtf8("pushbutton_history_down"));
        pushbutton_history_down->setGeometry(QRect(420, 360, 89, 41));
        pushbutton_history_down->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushbutton_history_back = new QPushButton(page_21);
        pushbutton_history_back->setObjectName(QString::fromUtf8("pushbutton_history_back"));
        pushbutton_history_back->setGeometry(QRect(550, 360, 89, 41));
        pushbutton_history_back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        Sr_No = new QLineEdit(page_21);
        Sr_No->setObjectName(QString::fromUtf8("Sr_No"));
        Sr_No->setGeometry(QRect(270, 360, 120, 40));
        Sr_No->setMouseTracking(false);
        Sr_No->setFocusPolicy(Qt::NoFocus);
        Sr_No->setAutoFillBackground(false);
        Sr_No->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        Sr_No->setReadOnly(true);
        stackedWidget_Admin->addWidget(page_21);
        page_23 = new QWidget();
        page_23->setObjectName(QString::fromUtf8("page_23"));
        label_28 = new QLabel(page_23);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 80, 120, 31));
        horizontalSlider = new QSlider(page_23);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(160, 210, 461, 31));
        horizontalSlider->setStyleSheet(QString::fromUtf8("Background-color : rgb(255, 255, 255);"));
        horizontalSlider->setMinimum(4);
        horizontalSlider->setMaximum(8);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_KeyBord_TimeDate = new QPushButton(page_23);
        pushButton_KeyBord_TimeDate->setObjectName(QString::fromUtf8("pushButton_KeyBord_TimeDate"));
        pushButton_KeyBord_TimeDate->setGeometry(QRect(360, 70, 70, 41));
        pushButton_KeyBord_TimeDate->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_30 = new QLabel(page_23);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 210, 120, 31));
        label_52 = new QLabel(page_23);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(440, 70, 181, 31));
        label_69 = new QLabel(page_23);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setGeometry(QRect(10, 280, 120, 31));
        pushButton_KeyBord_sleeptime = new QPushButton(page_23);
        pushButton_KeyBord_sleeptime->setObjectName(QString::fromUtf8("pushButton_KeyBord_sleeptime"));
        pushButton_KeyBord_sleeptime->setGeometry(QRect(280, 270, 70, 41));
        pushButton_KeyBord_sleeptime->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        lineEdit_SleepTime = new QLineEdit(page_23);
        lineEdit_SleepTime->setObjectName(QString::fromUtf8("lineEdit_SleepTime"));
        lineEdit_SleepTime->setGeometry(QRect(160, 270, 120, 41));
        lineEdit_SleepTime->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        label_71 = new QLabel(page_23);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setGeometry(QRect(10, 140, 140, 31));
        lineEdit_TimeZone = new QLineEdit(page_23);
        lineEdit_TimeZone->setObjectName(QString::fromUtf8("lineEdit_TimeZone"));
        lineEdit_TimeZone->setGeometry(QRect(190, 130, 120, 41));
        lineEdit_TimeZone->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        pushButton_KeyBord_Timezone = new QPushButton(page_23);
        pushButton_KeyBord_Timezone->setObjectName(QString::fromUtf8("pushButton_KeyBord_Timezone"));
        pushButton_KeyBord_Timezone->setGeometry(QRect(310, 130, 70, 41));
        pushButton_KeyBord_Timezone->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_72 = new QLabel(page_23);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setGeometry(QRect(400, 140, 61, 31));
        pushButton_Save_Displaysetting = new QPushButton(page_23);
        pushButton_Save_Displaysetting->setObjectName(QString::fromUtf8("pushButton_Save_Displaysetting"));
        pushButton_Save_Displaysetting->setGeometry(QRect(440, 340, 131, 51));
        pushButton_Save_Displaysetting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Back_Display_setting = new QPushButton(page_23);
        pushButton_Back_Display_setting->setObjectName(QString::fromUtf8("pushButton_Back_Display_setting"));
        pushButton_Back_Display_setting->setGeometry(QRect(40, 340, 131, 51));
        pushButton_Back_Display_setting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_displaysetting_status = new QLabel(page_23);
        label_displaysetting_status->setObjectName(QString::fromUtf8("label_displaysetting_status"));
        label_displaysetting_status->setGeometry(QRect(80, 20, 431, 30));
        label_displaysetting_status->setStyleSheet(QString::fromUtf8("color : yellow"));
        DateTime_SetTimedate = new QLineEdit(page_23);
        DateTime_SetTimedate->setObjectName(QString::fromUtf8("DateTime_SetTimedate"));
        DateTime_SetTimedate->setGeometry(QRect(140, 70, 221, 40));
        DateTime_SetTimedate->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        DateTime_SetTimedate->setMaxLength(50);
        stackedWidget_Admin->addWidget(page_23);
        page_28 = new QWidget();
        page_28->setObjectName(QString::fromUtf8("page_28"));
        lineEdit_charging_Password = new QLineEdit(page_28);
        lineEdit_charging_Password->setObjectName(QString::fromUtf8("lineEdit_charging_Password"));
        lineEdit_charging_Password->setGeometry(QRect(250, 140, 231, 41));
        lineEdit_charging_Password->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black;"));
        label_16 = new QLabel(page_28);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(40, 150, 140, 31));
        pushButton_BackChargingPsw = new QPushButton(page_28);
        pushButton_BackChargingPsw->setObjectName(QString::fromUtf8("pushButton_BackChargingPsw"));
        pushButton_BackChargingPsw->setGeometry(QRect(20, 320, 131, 51));
        pushButton_BackChargingPsw->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_ChrgMsg = new QLabel(page_28);
        label_ChrgMsg->setObjectName(QString::fromUtf8("label_ChrgMsg"));
        label_ChrgMsg->setGeometry(QRect(160, 60, 331, 21));
        label_73 = new QLabel(page_28);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setGeometry(QRect(40, 210, 160, 31));
        pushButton_Chrg_password = new QPushButton(page_28);
        pushButton_Chrg_password->setObjectName(QString::fromUtf8("pushButton_Chrg_password"));
        pushButton_Chrg_password->setGeometry(QRect(480, 140, 70, 41));
        pushButton_Chrg_password->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_charging_confirmpass = new QPushButton(page_28);
        pushButton_charging_confirmpass->setObjectName(QString::fromUtf8("pushButton_charging_confirmpass"));
        pushButton_charging_confirmpass->setGeometry(QRect(480, 210, 70, 41));
        pushButton_charging_confirmpass->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        lineEdit_chrgConfirmPass = new QLineEdit(page_28);
        lineEdit_chrgConfirmPass->setObjectName(QString::fromUtf8("lineEdit_chrgConfirmPass"));
        lineEdit_chrgConfirmPass->setGeometry(QRect(250, 210, 231, 41));
        lineEdit_chrgConfirmPass->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color : black"));
        pushButton_ChargingSave = new QPushButton(page_28);
        pushButton_ChargingSave->setObjectName(QString::fromUtf8("pushButton_ChargingSave"));
        pushButton_ChargingSave->setGeometry(QRect(440, 330, 131, 51));
        pushButton_ChargingSave->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget_Admin->addWidget(page_28);
        listWidget_9 = new QListWidget(page_11);
        listWidget_9->setObjectName(QString::fromUtf8("listWidget_9"));
        listWidget_9->setGeometry(QRect(0, 0, 131, 410));
        listWidget_9->setFrameShape(QFrame::Panel);
        listWidget_9->setFrameShadow(QFrame::Sunken);
        listWidget_9->setMidLineWidth(1);
        pushButton_AdminOCPP = new QPushButton(page_11);
        pushButton_AdminOCPP->setObjectName(QString::fromUtf8("pushButton_AdminOCPP"));
        pushButton_AdminOCPP->setGeometry(QRect(10, 10, 110, 37));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette24.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette24.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_AdminOCPP->setPalette(palette24);
        pushButton_AdminOCPP->setFont(font4);
        pushButton_AdminOCPP->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Price_setting = new QPushButton(page_11);
        pushButton_Price_setting->setObjectName(QString::fromUtf8("pushButton_Price_setting"));
        pushButton_Price_setting->setGeometry(QRect(10, 110, 111, 37));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_Price_setting->setPalette(palette25);
        pushButton_Price_setting->setAutoFillBackground(false);
        pushButton_Price_setting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Price_setting->setFlat(false);
        pushButton_AdminSetting = new QPushButton(page_11);
        pushButton_AdminSetting->setObjectName(QString::fromUtf8("pushButton_AdminSetting"));
        pushButton_AdminSetting->setGeometry(QRect(10, 160, 110, 37));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette26.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_AdminSetting->setPalette(palette26);
        pushButton_AdminSetting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_History_Page = new QPushButton(page_11);
        pushButton_History_Page->setObjectName(QString::fromUtf8("pushButton_History_Page"));
        pushButton_History_Page->setGeometry(QRect(10, 260, 110, 37));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette27.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette27.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette27.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette27.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_History_Page->setPalette(palette27);
        pushButton_History_Page->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_History_Page->setFlat(false);
        pushButton_Display_setting = new QPushButton(page_11);
        pushButton_Display_setting->setObjectName(QString::fromUtf8("pushButton_Display_setting"));
        pushButton_Display_setting->setGeometry(QRect(10, 310, 110, 37));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette28.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette28.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette28.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette28.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette28.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_Display_setting->setPalette(palette28);
        pushButton_Display_setting->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Display_setting->setFlat(false);
        pushButton_Network = new QPushButton(page_11);
        pushButton_Network->setObjectName(QString::fromUtf8("pushButton_Network"));
        pushButton_Network->setGeometry(QRect(10, 60, 110, 37));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette29.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette29.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette29.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette29.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette29.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush37(QColor(0, 0, 0, 128));
        brush37.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette29.setBrush(QPalette::Active, QPalette::PlaceholderText, brush37);
#endif
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette29.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette29.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette29.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette29.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette29.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush38(QColor(0, 0, 0, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette29.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush38);
#endif
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette29.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette29.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette29.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush39(QColor(0, 0, 0, 128));
        brush39.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette29.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush39);
#endif
        pushButton_Network->setPalette(palette29);
        pushButton_Network->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"color:black;border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Password = new QPushButton(page_11);
        pushButton_Password->setObjectName(QString::fromUtf8("pushButton_Password"));
        pushButton_Password->setGeometry(QRect(10, 210, 110, 37));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette30.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette30.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette30.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush40(QColor(0, 0, 0, 128));
        brush40.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette30.setBrush(QPalette::Active, QPalette::PlaceholderText, brush40);
#endif
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette30.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush41(QColor(0, 0, 0, 128));
        brush41.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette30.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush41);
#endif
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette30.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette30.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette30.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush42(QColor(0, 0, 0, 128));
        brush42.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette30.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush42);
#endif
        pushButton_Password->setPalette(palette30);
        pushButton_Password->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"color:black;border: 1px solid #FFFFFF;border-radius:10px;"));
        stackedWidget->addWidget(page_11);
        page_19 = new QWidget();
        page_19->setObjectName(QString::fromUtf8("page_19"));
        page_19->setEnabled(true);
        listWidget_23 = new QListWidget(page_19);
        listWidget_23->setObjectName(QString::fromUtf8("listWidget_23"));
        listWidget_23->setGeometry(QRect(-10, 0, 151, 401));
        listWidget_23->setStyleSheet(QString::fromUtf8("background-color:rgb(49,68,82)"));
        listWidget_23->setBatchSize(100);
        stackedWidget_Factory = new QStackedWidget(page_19);
        stackedWidget_Factory->setObjectName(QString::fromUtf8("stackedWidget_Factory"));
        stackedWidget_Factory->setEnabled(true);
        stackedWidget_Factory->setGeometry(QRect(140, 0, 681, 441));
        page_27 = new QWidget();
        page_27->setObjectName(QString::fromUtf8("page_27"));
        pushButton_Profile_Save = new QPushButton(page_27);
        pushButton_Profile_Save->setObjectName(QString::fromUtf8("pushButton_Profile_Save"));
        pushButton_Profile_Save->setGeometry(QRect(490, 310, 131, 51));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette31.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette31.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette31.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette31.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette31.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette31.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_Profile_Save->setPalette(palette31);
        pushButton_Profile_Save->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_Max_V = new QLabel(page_27);
        label_Max_V->setObjectName(QString::fromUtf8("label_Max_V"));
        label_Max_V->setGeometry(QRect(0, 100, 130, 31));
        lineEdit_Max_V = new QLineEdit(page_27);
        lineEdit_Max_V->setObjectName(QString::fromUtf8("lineEdit_Max_V"));
        lineEdit_Max_V->setEnabled(true);
        lineEdit_Max_V->setGeometry(QRect(140, 100, 130, 41));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette32.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette32.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette32.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette32.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette32.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette32.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette32.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette32.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette32.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette32.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette32.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette32.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette32.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette32.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette32.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Max_V->setPalette(palette32);
        lineEdit_Max_V->setAutoFillBackground(false);
        lineEdit_Max_V->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_keyboard_Max_V = new QPushButton(page_27);
        pushButton_keyboard_Max_V->setObjectName(QString::fromUtf8("pushButton_keyboard_Max_V"));
        pushButton_keyboard_Max_V->setGeometry(QRect(270, 100, 51, 41));
        QPalette palette33;
        QBrush brush43(QColor(1, 120, 240, 255));
        brush43.setStyle(Qt::SolidPattern);
        palette33.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette33.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette33.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette33.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette33.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette33.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette33.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette33.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette33.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette33.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette33.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette33.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette33.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette33.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette33.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette33.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette33.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette33.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_Max_V->setPalette(palette33);
        pushButton_keyboard_Max_V->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_Max_V->setAutoFillBackground(false);
        pushButton_keyboard_Max_V->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_Max_V->setAutoRepeatDelay(300);
        pushButton_keyboard_Max_V->setFlat(false);
        lineEdit_Max_I = new QLineEdit(page_27);
        lineEdit_Max_I->setObjectName(QString::fromUtf8("lineEdit_Max_I"));
        lineEdit_Max_I->setGeometry(QRect(140, 160, 130, 41));
        QPalette palette34;
        palette34.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette34.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette34.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette34.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette34.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette34.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette34.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette34.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette34.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette34.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette34.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette34.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette34.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette34.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette34.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette34.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette34.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette34.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette34.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette34.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette34.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Max_I->setPalette(palette34);
        lineEdit_Max_I->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_keyboard_Max_I = new QPushButton(page_27);
        pushButton_keyboard_Max_I->setObjectName(QString::fromUtf8("pushButton_keyboard_Max_I"));
        pushButton_keyboard_Max_I->setGeometry(QRect(270, 160, 51, 41));
        QPalette palette35;
        palette35.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette35.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette35.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette35.setBrush(QPalette::Active, QPalette::Window, brush43);
        palette35.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette35.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette35.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette35.setBrush(QPalette::Inactive, QPalette::Window, brush43);
        palette35.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette35.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette35.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette35.setBrush(QPalette::Disabled, QPalette::Window, brush43);
        pushButton_keyboard_Max_I->setPalette(palette35);
        pushButton_keyboard_Max_I->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_Max_I = new QLabel(page_27);
        label_Max_I->setObjectName(QString::fromUtf8("label_Max_I"));
        label_Max_I->setGeometry(QRect(0, 160, 130, 31));
        lineEdit_Min_V = new QLineEdit(page_27);
        lineEdit_Min_V->setObjectName(QString::fromUtf8("lineEdit_Min_V"));
        lineEdit_Min_V->setGeometry(QRect(470, 90, 130, 41));
        QPalette palette36;
        palette36.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette36.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette36.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette36.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette36.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette36.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette36.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette36.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette36.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette36.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette36.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette36.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette36.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette36.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette36.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette36.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette36.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette36.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette36.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette36.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette36.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Min_V->setPalette(palette36);
        lineEdit_Min_V->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_keyboard_Min_V = new QPushButton(page_27);
        pushButton_keyboard_Min_V->setObjectName(QString::fromUtf8("pushButton_keyboard_Min_V"));
        pushButton_keyboard_Min_V->setGeometry(QRect(600, 90, 51, 41));
        QPalette palette37;
        palette37.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette37.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette37.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette37.setBrush(QPalette::Active, QPalette::Window, brush43);
        palette37.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette37.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette37.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette37.setBrush(QPalette::Inactive, QPalette::Window, brush43);
        palette37.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette37.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette37.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette37.setBrush(QPalette::Disabled, QPalette::Window, brush43);
        pushButton_keyboard_Min_V->setPalette(palette37);
        pushButton_keyboard_Min_V->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_Min_V->setFlat(false);
        label_Min_V = new QLabel(page_27);
        label_Min_V->setObjectName(QString::fromUtf8("label_Min_V"));
        label_Min_V->setGeometry(QRect(340, 100, 120, 31));
        pushButton_keyboard_Min_I = new QPushButton(page_27);
        pushButton_keyboard_Min_I->setObjectName(QString::fromUtf8("pushButton_keyboard_Min_I"));
        pushButton_keyboard_Min_I->setGeometry(QRect(600, 150, 51, 41));
        QPalette palette38;
        palette38.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette38.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette38.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette38.setBrush(QPalette::Active, QPalette::Window, brush43);
        palette38.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette38.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette38.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette38.setBrush(QPalette::Inactive, QPalette::Window, brush43);
        palette38.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette38.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette38.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette38.setBrush(QPalette::Disabled, QPalette::Window, brush43);
        pushButton_keyboard_Min_I->setPalette(palette38);
        pushButton_keyboard_Min_I->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        lineEdit_Min_I = new QLineEdit(page_27);
        lineEdit_Min_I->setObjectName(QString::fromUtf8("lineEdit_Min_I"));
        lineEdit_Min_I->setGeometry(QRect(470, 150, 130, 41));
        QPalette palette39;
        palette39.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette39.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette39.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette39.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette39.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette39.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette39.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette39.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette39.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette39.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette39.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette39.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette39.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette39.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette39.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette39.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette39.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette39.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette39.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette39.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette39.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Min_I->setPalette(palette39);
        lineEdit_Min_I->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        label_Min_I = new QLabel(page_27);
        label_Min_I->setObjectName(QString::fromUtf8("label_Min_I"));
        label_Min_I->setGeometry(QRect(340, 160, 120, 31));
        pushButton_keyboard_Max_P = new QPushButton(page_27);
        pushButton_keyboard_Max_P->setObjectName(QString::fromUtf8("pushButton_keyboard_Max_P"));
        pushButton_keyboard_Max_P->setGeometry(QRect(270, 220, 51, 41));
        QPalette palette40;
        palette40.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette40.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette40.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette40.setBrush(QPalette::Active, QPalette::Window, brush43);
        palette40.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette40.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette40.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette40.setBrush(QPalette::Inactive, QPalette::Window, brush43);
        palette40.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette40.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette40.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette40.setBrush(QPalette::Disabled, QPalette::Window, brush43);
        pushButton_keyboard_Max_P->setPalette(palette40);
        pushButton_keyboard_Max_P->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        lineEdit_Max_P = new QLineEdit(page_27);
        lineEdit_Max_P->setObjectName(QString::fromUtf8("lineEdit_Max_P"));
        lineEdit_Max_P->setGeometry(QRect(140, 220, 130, 41));
        QPalette palette41;
        palette41.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette41.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette41.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette41.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette41.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette41.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette41.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette41.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette41.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette41.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette41.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette41.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette41.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette41.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette41.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette41.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette41.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette41.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette41.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette41.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette41.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Max_P->setPalette(palette41);
        lineEdit_Max_P->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        label_Max_P = new QLabel(page_27);
        label_Max_P->setObjectName(QString::fromUtf8("label_Max_P"));
        label_Max_P->setGeometry(QRect(0, 220, 120, 31));
        lineEdit_Min_P = new QLineEdit(page_27);
        lineEdit_Min_P->setObjectName(QString::fromUtf8("lineEdit_Min_P"));
        lineEdit_Min_P->setGeometry(QRect(470, 210, 130, 41));
        QPalette palette42;
        palette42.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette42.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette42.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette42.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette42.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette42.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette42.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette42.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette42.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette42.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette42.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette42.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette42.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette42.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette42.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette42.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette42.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette42.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette42.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette42.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette42.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Min_P->setPalette(palette42);
        lineEdit_Min_P->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_keyboard_Min_P = new QPushButton(page_27);
        pushButton_keyboard_Min_P->setObjectName(QString::fromUtf8("pushButton_keyboard_Min_P"));
        pushButton_keyboard_Min_P->setGeometry(QRect(600, 210, 51, 41));
        QPalette palette43;
        palette43.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette43.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette43.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette43.setBrush(QPalette::Active, QPalette::Window, brush43);
        palette43.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette43.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette43.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette43.setBrush(QPalette::Inactive, QPalette::Window, brush43);
        palette43.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette43.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette43.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette43.setBrush(QPalette::Disabled, QPalette::Window, brush43);
        pushButton_keyboard_Min_P->setPalette(palette43);
        pushButton_keyboard_Min_P->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_Min_P = new QLabel(page_27);
        label_Min_P->setObjectName(QString::fromUtf8("label_Min_P"));
        label_Min_P->setGeometry(QRect(340, 220, 120, 31));
        pushButton_Profile_Back = new QPushButton(page_27);
        pushButton_Profile_Back->setObjectName(QString::fromUtf8("pushButton_Profile_Back"));
        pushButton_Profile_Back->setEnabled(true);
        pushButton_Profile_Back->setGeometry(QRect(90, 310, 131, 51));
        QPalette palette44;
        palette44.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette44.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette44.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette44.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette44.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette44.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_Profile_Back->setPalette(palette44);
        pushButton_Profile_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_Profiled_saved = new QLabel(page_27);
        label_Profiled_saved->setObjectName(QString::fromUtf8("label_Profiled_saved"));
        label_Profiled_saved->setGeometry(QRect(110, 30, 431, 21));
        label_Profiled_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        stackedWidget_Factory->addWidget(page_27);
        page_18 = new QWidget();
        page_18->setObjectName(QString::fromUtf8("page_18"));
        pushButton_Serial_Save = new QPushButton(page_18);
        pushButton_Serial_Save->setObjectName(QString::fromUtf8("pushButton_Serial_Save"));
        pushButton_Serial_Save->setGeometry(QRect(440, 340, 131, 51));
        QPalette palette45;
        QBrush brush44(QColor(255, 255, 0, 255));
        brush44.setStyle(Qt::SolidPattern);
        palette45.setBrush(QPalette::Active, QPalette::WindowText, brush44);
        palette45.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette45.setBrush(QPalette::Active, QPalette::Text, brush44);
        palette45.setBrush(QPalette::Active, QPalette::ButtonText, brush44);
        palette45.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette45.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush45(QColor(255, 255, 0, 128));
        brush45.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette45.setBrush(QPalette::Active, QPalette::PlaceholderText, brush45);
#endif
        palette45.setBrush(QPalette::Inactive, QPalette::WindowText, brush44);
        palette45.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::Text, brush44);
        palette45.setBrush(QPalette::Inactive, QPalette::ButtonText, brush44);
        palette45.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush46(QColor(255, 255, 0, 128));
        brush46.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette45.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush46);
#endif
        palette45.setBrush(QPalette::Disabled, QPalette::WindowText, brush44);
        palette45.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette45.setBrush(QPalette::Disabled, QPalette::Text, brush44);
        palette45.setBrush(QPalette::Disabled, QPalette::ButtonText, brush44);
        palette45.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette45.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush47(QColor(255, 255, 0, 128));
        brush47.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette45.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush47);
#endif
        pushButton_Serial_Save->setPalette(palette45);
        pushButton_Serial_Save->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"color: yellow; border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_SN_Back = new QPushButton(page_18);
        pushButton_SN_Back->setObjectName(QString::fromUtf8("pushButton_SN_Back"));
        pushButton_SN_Back->setEnabled(true);
        pushButton_SN_Back->setGeometry(QRect(40, 340, 131, 51));
        QPalette palette46;
        palette46.setBrush(QPalette::Active, QPalette::WindowText, brush44);
        palette46.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette46.setBrush(QPalette::Active, QPalette::Text, brush44);
        palette46.setBrush(QPalette::Active, QPalette::ButtonText, brush44);
        palette46.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette46.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush48(QColor(255, 255, 0, 128));
        brush48.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette46.setBrush(QPalette::Active, QPalette::PlaceholderText, brush48);
#endif
        palette46.setBrush(QPalette::Inactive, QPalette::WindowText, brush44);
        palette46.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette46.setBrush(QPalette::Inactive, QPalette::Text, brush44);
        palette46.setBrush(QPalette::Inactive, QPalette::ButtonText, brush44);
        palette46.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette46.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush49(QColor(255, 255, 0, 128));
        brush49.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette46.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush49);
#endif
        palette46.setBrush(QPalette::Disabled, QPalette::WindowText, brush44);
        palette46.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette46.setBrush(QPalette::Disabled, QPalette::Text, brush44);
        palette46.setBrush(QPalette::Disabled, QPalette::ButtonText, brush44);
        palette46.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette46.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush50(QColor(255, 255, 0, 128));
        brush50.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette46.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush50);
#endif
        pushButton_SN_Back->setPalette(palette46);
        pushButton_SN_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"color:yellow;border: 1px solid #FFFFFF;border-radius:10px;"));
        label_SN_saved = new QLabel(page_18);
        label_SN_saved->setObjectName(QString::fromUtf8("label_SN_saved"));
        label_SN_saved->setGeometry(QRect(70, 20, 431, 21));
        label_SN_saved->setStyleSheet(QString::fromUtf8("color : yellow"));
        gridWidget_2 = new QWidget(page_18);
        gridWidget_2->setObjectName(QString::fromUtf8("gridWidget_2"));
        gridWidget_2->setGeometry(QRect(10, 60, 611, 261));
        label_60 = new QLabel(gridWidget_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(1, 100, 220, 30));
        label_62 = new QLabel(gridWidget_2);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(1, 50, 223, 30));
        label_76 = new QLabel(gridWidget_2);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        label_76->setGeometry(QRect(1, 140, 220, 30));
        lineEdit_TempProtection = new QLineEdit(gridWidget_2);
        lineEdit_TempProtection->setObjectName(QString::fromUtf8("lineEdit_TempProtection"));
        lineEdit_TempProtection->setGeometry(QRect(234, 50, 150, 30));
        lineEdit_TempProtection->setMouseTracking(false);
        lineEdit_TempProtection->setFocusPolicy(Qt::NoFocus);
        lineEdit_TempProtection->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_TempProtection->setReadOnly(true);
        lineEdit_EndTime_CuttOfSoc = new QLineEdit(gridWidget_2);
        lineEdit_EndTime_CuttOfSoc->setObjectName(QString::fromUtf8("lineEdit_EndTime_CuttOfSoc"));
        lineEdit_EndTime_CuttOfSoc->setGeometry(QRect(234, 140, 150, 30));
        QPalette palette47;
        palette47.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette47.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette47.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette47.setBrush(QPalette::Active, QPalette::BrightText, brush30);
        palette47.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette47.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette47.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush51(QColor(0, 0, 0, 128));
        brush51.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette47.setBrush(QPalette::Active, QPalette::PlaceholderText, brush51);
#endif
        palette47.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette47.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette47.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette47.setBrush(QPalette::Inactive, QPalette::BrightText, brush30);
        palette47.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette47.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette47.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush52(QColor(0, 0, 0, 128));
        brush52.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette47.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush52);
#endif
        palette47.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette47.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette47.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette47.setBrush(QPalette::Disabled, QPalette::BrightText, brush30);
        palette47.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette47.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette47.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        QBrush brush53(QColor(0, 0, 0, 128));
        brush53.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette47.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush53);
#endif
        lineEdit_EndTime_CuttOfSoc->setPalette(palette47);
        lineEdit_EndTime_CuttOfSoc->setMouseTracking(false);
        lineEdit_EndTime_CuttOfSoc->setFocusPolicy(Qt::NoFocus);
        lineEdit_EndTime_CuttOfSoc->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_EndTime_CuttOfSoc->setReadOnly(true);
        checkBox_TempProtection = new QCheckBox(gridWidget_2);
        checkBox_TempProtection->setObjectName(QString::fromUtf8("checkBox_TempProtection"));
        checkBox_TempProtection->setGeometry(QRect(480, 50, 80, 30));
        QPalette palette48;
        palette48.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette48.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette48.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette48.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette48.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush54(QColor(255, 255, 255, 128));
        brush54.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette48.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette48.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette48.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette48.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette48.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette48.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette48.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette48.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette48.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette48.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette48.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette48.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette48.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        checkBox_TempProtection->setPalette(palette48);
        label_78 = new QLabel(gridWidget_2);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setGeometry(QRect(0, 0, 220, 30));
        lineEdit_Serial_Number = new QLineEdit(gridWidget_2);
        lineEdit_Serial_Number->setObjectName(QString::fromUtf8("lineEdit_Serial_Number"));
        lineEdit_Serial_Number->setEnabled(true);
        lineEdit_Serial_Number->setGeometry(QRect(234, 1, 150, 30));
        QPalette palette49;
        palette49.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette49.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette49.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette49.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette49.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette49.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette49.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette49.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette49.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette49.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette49.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette49.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette49.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette49.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette49.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette49.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette49.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette49.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette49.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette49.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette49.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_Serial_Number->setPalette(palette49);
        lineEdit_Serial_Number->setAutoFillBackground(false);
        lineEdit_Serial_Number->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_keyboard_Serial_Number = new QPushButton(gridWidget_2);
        pushButton_keyboard_Serial_Number->setObjectName(QString::fromUtf8("pushButton_keyboard_Serial_Number"));
        pushButton_keyboard_Serial_Number->setGeometry(QRect(386, 1, 80, 30));
        QPalette palette50;
        palette50.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette50.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette50.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette50.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette50.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette50.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette50.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette50.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette50.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette50.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette50.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette50.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette50.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette50.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette50.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette50.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette50.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette50.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_Serial_Number->setPalette(palette50);
        pushButton_keyboard_Serial_Number->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_Serial_Number->setAutoFillBackground(false);
        pushButton_keyboard_Serial_Number->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_Serial_Number->setAutoRepeatDelay(300);
        pushButton_keyboard_Serial_Number->setFlat(false);
        pushButton_keyboard_TProtection = new QPushButton(gridWidget_2);
        pushButton_keyboard_TProtection->setObjectName(QString::fromUtf8("pushButton_keyboard_TProtection"));
        pushButton_keyboard_TProtection->setGeometry(QRect(386, 50, 80, 30));
        QPalette palette51;
        palette51.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette51.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette51.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette51.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette51.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette51.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette51.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette51.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette51.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette51.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette51.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette51.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette51.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette51.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette51.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette51.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette51.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette51.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_TProtection->setPalette(palette51);
        pushButton_keyboard_TProtection->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_TProtection->setAutoFillBackground(false);
        pushButton_keyboard_TProtection->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_TProtection->setAutoRepeatDelay(300);
        pushButton_keyboard_TProtection->setFlat(false);
        pushButton_keyboard_CutoffSoc = new QPushButton(gridWidget_2);
        pushButton_keyboard_CutoffSoc->setObjectName(QString::fromUtf8("pushButton_keyboard_CutoffSoc"));
        pushButton_keyboard_CutoffSoc->setGeometry(QRect(386, 140, 80, 30));
        QPalette palette52;
        palette52.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette52.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette52.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette52.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette52.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette52.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette52.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette52.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette52.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette52.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette52.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette52.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette52.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette52.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette52.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette52.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette52.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette52.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_CutoffSoc->setPalette(palette52);
        pushButton_keyboard_CutoffSoc->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_CutoffSoc->setAutoFillBackground(false);
        pushButton_keyboard_CutoffSoc->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_CutoffSoc->setAutoRepeatDelay(300);
        pushButton_keyboard_CutoffSoc->setFlat(false);
        checkBox_DoorLock = new QCheckBox(gridWidget_2);
        checkBox_DoorLock->setObjectName(QString::fromUtf8("checkBox_DoorLock"));
        checkBox_DoorLock->setGeometry(QRect(234, 100, 72, 23));
        QPalette palette53;
        palette53.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette53.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette53.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette53.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette53.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette53.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette53.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette53.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette53.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette53.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette53.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette53.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette53.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette53.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette53.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette53.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette53.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette53.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        checkBox_DoorLock->setPalette(palette53);
        checkBox_CuttofSoc = new QCheckBox(gridWidget_2);
        checkBox_CuttofSoc->setObjectName(QString::fromUtf8("checkBox_CuttofSoc"));
        checkBox_CuttofSoc->setGeometry(QRect(480, 140, 72, 23));
        QPalette palette54;
        palette54.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette54.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette54.setBrush(QPalette::Active, QPalette::Light, brush7);
        palette54.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush55(QColor(127, 127, 127, 255));
        brush55.setStyle(Qt::SolidPattern);
        palette54.setBrush(QPalette::Active, QPalette::Dark, brush55);
        QBrush brush56(QColor(170, 170, 170, 255));
        brush56.setStyle(Qt::SolidPattern);
        palette54.setBrush(QPalette::Active, QPalette::Mid, brush56);
        palette54.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette54.setBrush(QPalette::Active, QPalette::BrightText, brush7);
        palette54.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette54.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette54.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette54.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette54.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush57(QColor(255, 255, 220, 255));
        brush57.setStyle(Qt::SolidPattern);
        palette54.setBrush(QPalette::Active, QPalette::ToolTipBase, brush57);
        palette54.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette54.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette54.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette54.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::Dark, brush55);
        palette54.setBrush(QPalette::Inactive, QPalette::Mid, brush56);
        palette54.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::BrightText, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette54.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette54.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette54.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette54.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush57);
        palette54.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette54.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette54.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette54.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette54.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette54.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette54.setBrush(QPalette::Disabled, QPalette::Dark, brush55);
        palette54.setBrush(QPalette::Disabled, QPalette::Mid, brush56);
        palette54.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette54.setBrush(QPalette::Disabled, QPalette::BrightText, brush7);
        palette54.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette54.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette54.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette54.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette54.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette54.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush57);
        palette54.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette54.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        checkBox_CuttofSoc->setPalette(palette54);
        label_79 = new QLabel(gridWidget_2);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(0, 180, 220, 30));
        checkBox_TestMode = new QCheckBox(gridWidget_2);
        checkBox_TestMode->setObjectName(QString::fromUtf8("checkBox_TestMode"));
        checkBox_TestMode->setGeometry(QRect(230, 180, 72, 23));
        QPalette palette55;
        palette55.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette55.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette55.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette55.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette55.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette55.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette55.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette55.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette55.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette55.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette55.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette55.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette55.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette55.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette55.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette55.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette55.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette55.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_TestMode->setPalette(palette55);
        label_80 = new QLabel(page_18);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        label_80->setGeometry(QRect(10, 300, 220, 30));
        label_81 = new QLabel(page_18);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setGeometry(QRect(10, 270, 220, 30));
        checkBox_GroundFault = new QCheckBox(page_18);
        checkBox_GroundFault->setObjectName(QString::fromUtf8("checkBox_GroundFault"));
        checkBox_GroundFault->setGeometry(QRect(240, 270, 72, 23));
        QPalette palette56;
        palette56.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette56.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette56.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette56.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette56.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette56.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette56.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette56.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette56.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette56.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette56.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette56.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette56.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette56.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette56.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette56.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette56.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette56.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette56.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette56.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette56.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_GroundFault->setPalette(palette56);
        checkBox_IsolationFault = new QCheckBox(page_18);
        checkBox_IsolationFault->setObjectName(QString::fromUtf8("checkBox_IsolationFault"));
        checkBox_IsolationFault->setGeometry(QRect(240, 300, 72, 23));
        QPalette palette57;
        palette57.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette57.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette57.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette57.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette57.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette57.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette57.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette57.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette57.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette57.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette57.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette57.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette57.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette57.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette57.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette57.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette57.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette57.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_IsolationFault->setPalette(palette57);
        stackedWidget_Factory->addWidget(page_18);
        page_22 = new QWidget();
        page_22->setObjectName(QString::fromUtf8("page_22"));
        lineEdit_FW_password = new QLineEdit(page_22);
        lineEdit_FW_password->setObjectName(QString::fromUtf8("lineEdit_FW_password"));
        lineEdit_FW_password->setEnabled(true);
        lineEdit_FW_password->setGeometry(QRect(200, 250, 210, 41));
        QPalette palette58;
        palette58.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette58.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette58.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette58.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette58.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette58.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette58.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette58.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette58.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette58.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette58.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette58.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette58.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette58.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette58.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette58.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette58.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette58.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette58.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette58.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette58.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_FW_password->setPalette(palette58);
        lineEdit_FW_password->setAutoFillBackground(false);
        lineEdit_FW_password->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_keyboard_FW_servername = new QPushButton(page_22);
        pushButton_keyboard_FW_servername->setObjectName(QString::fromUtf8("pushButton_keyboard_FW_servername"));
        pushButton_keyboard_FW_servername->setGeometry(QRect(410, 70, 70, 41));
        QPalette palette59;
        palette59.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette59.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette59.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette59.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette59.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette59.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette59.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette59.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette59.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette59.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette59.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette59.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette59.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette59.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette59.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette59.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette59.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette59.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_FW_servername->setPalette(palette59);
        pushButton_keyboard_FW_servername->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_FW_servername->setAutoFillBackground(false);
        pushButton_keyboard_FW_servername->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_FW_servername->setAutoRepeatDelay(300);
        pushButton_keyboard_FW_servername->setFlat(false);
        lineEdit_FW_username = new QLineEdit(page_22);
        lineEdit_FW_username->setObjectName(QString::fromUtf8("lineEdit_FW_username"));
        lineEdit_FW_username->setEnabled(true);
        lineEdit_FW_username->setGeometry(QRect(200, 190, 210, 41));
        QPalette palette60;
        palette60.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette60.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette60.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette60.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette60.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette60.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette60.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette60.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette60.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette60.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette60.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette60.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette60.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette60.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette60.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette60.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette60.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette60.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette60.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette60.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette60.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_FW_username->setPalette(palette60);
        lineEdit_FW_username->setAutoFillBackground(false);
        lineEdit_FW_username->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        FW_S = new QLabel(page_22);
        FW_S->setObjectName(QString::fromUtf8("FW_S"));
        FW_S->setGeometry(QRect(30, 70, 130, 31));
        FW_P = new QLabel(page_22);
        FW_P->setObjectName(QString::fromUtf8("FW_P"));
        FW_P->setGeometry(QRect(30, 140, 81, 31));
        FW = new QLabel(page_22);
        FW->setObjectName(QString::fromUtf8("FW"));
        FW->setGeometry(QRect(230, 10, 150, 31));
        FW_PW = new QLabel(page_22);
        FW_PW->setObjectName(QString::fromUtf8("FW_PW"));
        FW_PW->setGeometry(QRect(30, 250, 81, 31));
        pushButton_keyboard_FW_password = new QPushButton(page_22);
        pushButton_keyboard_FW_password->setObjectName(QString::fromUtf8("pushButton_keyboard_FW_password"));
        pushButton_keyboard_FW_password->setGeometry(QRect(410, 250, 70, 41));
        QPalette palette61;
        palette61.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette61.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette61.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette61.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette61.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette61.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette61.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette61.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette61.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette61.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette61.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette61.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette61.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette61.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette61.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette61.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette61.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette61.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_FW_password->setPalette(palette61);
        pushButton_keyboard_FW_password->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_FW_password->setAutoFillBackground(false);
        pushButton_keyboard_FW_password->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_FW_password->setAutoRepeatDelay(300);
        pushButton_keyboard_FW_password->setFlat(false);
        pushButton_keyboard_FW_username = new QPushButton(page_22);
        pushButton_keyboard_FW_username->setObjectName(QString::fromUtf8("pushButton_keyboard_FW_username"));
        pushButton_keyboard_FW_username->setGeometry(QRect(410, 190, 70, 41));
        QPalette palette62;
        palette62.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette62.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette62.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette62.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette62.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette62.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette62.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette62.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette62.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette62.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette62.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette62.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette62.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette62.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette62.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette62.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette62.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette62.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_FW_username->setPalette(palette62);
        pushButton_keyboard_FW_username->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_FW_username->setAutoFillBackground(false);
        pushButton_keyboard_FW_username->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_FW_username->setAutoRepeatDelay(300);
        pushButton_keyboard_FW_username->setFlat(false);
        FW_U = new QLabel(page_22);
        FW_U->setObjectName(QString::fromUtf8("FW_U"));
        FW_U->setGeometry(QRect(30, 200, 81, 31));
        pushButton_FW_Update = new QPushButton(page_22);
        pushButton_FW_Update->setObjectName(QString::fromUtf8("pushButton_FW_Update"));
        pushButton_FW_Update->setGeometry(QRect(490, 320, 131, 51));
        QPalette palette63;
        palette63.setBrush(QPalette::Active, QPalette::WindowText, brush44);
        palette63.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette63.setBrush(QPalette::Active, QPalette::Text, brush44);
        palette63.setBrush(QPalette::Active, QPalette::ButtonText, brush44);
        palette63.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette63.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush58(QColor(255, 255, 0, 128));
        brush58.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette63.setBrush(QPalette::Active, QPalette::PlaceholderText, brush58);
#endif
        palette63.setBrush(QPalette::Inactive, QPalette::WindowText, brush44);
        palette63.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette63.setBrush(QPalette::Inactive, QPalette::Text, brush44);
        palette63.setBrush(QPalette::Inactive, QPalette::ButtonText, brush44);
        palette63.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette63.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush59(QColor(255, 255, 0, 128));
        brush59.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette63.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush59);
#endif
        palette63.setBrush(QPalette::Disabled, QPalette::WindowText, brush44);
        palette63.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette63.setBrush(QPalette::Disabled, QPalette::Text, brush44);
        palette63.setBrush(QPalette::Disabled, QPalette::ButtonText, brush44);
        palette63.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette63.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush60(QColor(255, 255, 0, 128));
        brush60.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette63.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush60);
#endif
        pushButton_FW_Update->setPalette(palette63);
        pushButton_FW_Update->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"color: yellow; border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_keyboard_FW_path = new QPushButton(page_22);
        pushButton_keyboard_FW_path->setObjectName(QString::fromUtf8("pushButton_keyboard_FW_path"));
        pushButton_keyboard_FW_path->setGeometry(QRect(410, 130, 70, 41));
        QPalette palette64;
        palette64.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette64.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette64.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette64.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette64.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette64.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette64.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette64.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette64.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette64.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette64.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette64.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette64.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette64.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette64.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette64.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette64.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette64.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_FW_path->setPalette(palette64);
        pushButton_keyboard_FW_path->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_FW_path->setAutoFillBackground(false);
        pushButton_keyboard_FW_path->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_FW_path->setAutoRepeatDelay(300);
        pushButton_keyboard_FW_path->setFlat(false);
        lineEdit_FW_servername = new QLineEdit(page_22);
        lineEdit_FW_servername->setObjectName(QString::fromUtf8("lineEdit_FW_servername"));
        lineEdit_FW_servername->setEnabled(true);
        lineEdit_FW_servername->setGeometry(QRect(200, 70, 211, 41));
        QPalette palette65;
        palette65.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette65.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette65.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette65.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette65.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette65.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette65.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette65.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette65.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette65.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette65.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette65.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette65.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette65.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette65.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette65.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette65.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette65.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette65.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette65.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette65.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_FW_servername->setPalette(palette65);
        lineEdit_FW_servername->setAutoFillBackground(false);
        lineEdit_FW_servername->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_FW_Back = new QPushButton(page_22);
        pushButton_FW_Back->setObjectName(QString::fromUtf8("pushButton_FW_Back"));
        pushButton_FW_Back->setEnabled(true);
        pushButton_FW_Back->setGeometry(QRect(30, 320, 131, 51));
        QPalette palette66;
        palette66.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette66.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette66.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette66.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette66.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette66.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette66.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette66.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette66.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette66.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette66.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette66.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_FW_Back->setPalette(palette66);
        pushButton_FW_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        lineEdit_FW_path = new QLineEdit(page_22);
        lineEdit_FW_path->setObjectName(QString::fromUtf8("lineEdit_FW_path"));
        lineEdit_FW_path->setEnabled(true);
        lineEdit_FW_path->setGeometry(QRect(200, 130, 210, 41));
        QPalette palette67;
        palette67.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette67.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette67.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette67.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette67.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette67.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette67.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette67.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette67.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette67.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette67.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette67.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette67.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette67.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette67.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette67.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette67.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette67.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette67.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette67.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette67.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        lineEdit_FW_path->setPalette(palette67);
        lineEdit_FW_path->setAutoFillBackground(false);
        lineEdit_FW_path->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        stackedWidget_Factory->addWidget(page_22);
        page_30 = new QWidget();
        page_30->setObjectName(QString::fromUtf8("page_30"));
        gridWidget_3 = new QWidget(page_30);
        gridWidget_3->setObjectName(QString::fromUtf8("gridWidget_3"));
        gridWidget_3->setGeometry(QRect(20, 60, 611, 261));
        label_85 = new QLabel(gridWidget_3);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        label_85->setGeometry(QRect(0, 20, 220, 30));
        checkBox_LoadSharing = new QCheckBox(gridWidget_3);
        checkBox_LoadSharing->setObjectName(QString::fromUtf8("checkBox_LoadSharing"));
        checkBox_LoadSharing->setGeometry(QRect(270, 20, 72, 23));
        QPalette palette68;
        palette68.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette68.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette68.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette68.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette68.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette68.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette68.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette68.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette68.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette68.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette68.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette68.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette68.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette68.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette68.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette68.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette68.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette68.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_LoadSharing->setPalette(palette68);
        label_86 = new QLabel(gridWidget_3);
        label_86->setObjectName(QString::fromUtf8("label_86"));
        label_86->setGeometry(QRect(0, 60, 240, 30));
        checkBox_PostSLSharing = new QCheckBox(gridWidget_3);
        checkBox_PostSLSharing->setObjectName(QString::fromUtf8("checkBox_PostSLSharing"));
        checkBox_PostSLSharing->setGeometry(QRect(270, 60, 72, 23));
        QPalette palette69;
        palette69.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette69.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette69.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette69.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette69.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette69.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette69.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette69.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette69.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette69.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette69.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette69.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette69.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette69.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette69.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette69.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette69.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette69.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_PostSLSharing->setPalette(palette69);
        checkBox_PreSLoadsharing = new QCheckBox(gridWidget_3);
        checkBox_PreSLoadsharing->setObjectName(QString::fromUtf8("checkBox_PreSLoadsharing"));
        checkBox_PreSLoadsharing->setGeometry(QRect(270, 100, 72, 23));
        QPalette palette70;
        palette70.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette70.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette70.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette70.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette70.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette70.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette70.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette70.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette70.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette70.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette70.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette70.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette70.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette70.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette70.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette70.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette70.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette70.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_PreSLoadsharing->setPalette(palette70);
        label_87 = new QLabel(gridWidget_3);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        label_87->setGeometry(QRect(0, 100, 240, 30));
        label_88 = new QLabel(gridWidget_3);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        label_88->setGeometry(QRect(0, 140, 240, 30));
        checkBox_PMIndividual = new QCheckBox(gridWidget_3);
        checkBox_PMIndividual->setObjectName(QString::fromUtf8("checkBox_PMIndividual"));
        checkBox_PMIndividual->setGeometry(QRect(270, 140, 72, 23));
        QPalette palette71;
        palette71.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette71.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette71.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette71.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette71.setBrush(QPalette::Active, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette71.setBrush(QPalette::Active, QPalette::PlaceholderText, brush54);
#endif
        palette71.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette71.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette71.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette71.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette71.setBrush(QPalette::Inactive, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette71.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette71.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette71.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette71.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette71.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette71.setBrush(QPalette::Disabled, QPalette::Window, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette71.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush54);
#endif
        checkBox_PMIndividual->setPalette(palette71);
        pushButton_keyboard_TouchInterval = new QPushButton(gridWidget_3);
        pushButton_keyboard_TouchInterval->setObjectName(QString::fromUtf8("pushButton_keyboard_TouchInterval"));
        pushButton_keyboard_TouchInterval->setGeometry(QRect(392, 180, 80, 30));
        QPalette palette72;
        palette72.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette72.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette72.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette72.setBrush(QPalette::Active, QPalette::Base, brush43);
        palette72.setBrush(QPalette::Active, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette72.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette72.setBrush(QPalette::Inactive, QPalette::Button, brush43);
        palette72.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette72.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette72.setBrush(QPalette::Inactive, QPalette::Base, brush43);
        palette72.setBrush(QPalette::Inactive, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette72.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette72.setBrush(QPalette::Disabled, QPalette::Button, brush43);
        palette72.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette72.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette72.setBrush(QPalette::Disabled, QPalette::Base, brush43);
        palette72.setBrush(QPalette::Disabled, QPalette::Window, brush43);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette72.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_keyboard_TouchInterval->setPalette(palette72);
        pushButton_keyboard_TouchInterval->setFocusPolicy(Qt::ClickFocus);
        pushButton_keyboard_TouchInterval->setAutoFillBackground(false);
        pushButton_keyboard_TouchInterval->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        pushButton_keyboard_TouchInterval->setAutoRepeatDelay(300);
        pushButton_keyboard_TouchInterval->setFlat(false);
        label_82 = new QLabel(gridWidget_3);
        label_82->setObjectName(QString::fromUtf8("label_82"));
        label_82->setGeometry(QRect(0, 180, 220, 30));
        checkBox_TouchInterval = new QCheckBox(gridWidget_3);
        checkBox_TouchInterval->setObjectName(QString::fromUtf8("checkBox_TouchInterval"));
        checkBox_TouchInterval->setGeometry(QRect(486, 180, 72, 23));
        QPalette palette73;
        palette73.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette73.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette73.setBrush(QPalette::Active, QPalette::Light, brush7);
        palette73.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        palette73.setBrush(QPalette::Active, QPalette::Dark, brush55);
        palette73.setBrush(QPalette::Active, QPalette::Mid, brush56);
        palette73.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette73.setBrush(QPalette::Active, QPalette::BrightText, brush7);
        palette73.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette73.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette73.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette73.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette73.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette73.setBrush(QPalette::Active, QPalette::ToolTipBase, brush57);
        palette73.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette73.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette73.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette73.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::Dark, brush55);
        palette73.setBrush(QPalette::Inactive, QPalette::Mid, brush56);
        palette73.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::BrightText, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette73.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette73.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette73.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette73.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush57);
        palette73.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette73.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette73.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette73.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette73.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette73.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette73.setBrush(QPalette::Disabled, QPalette::Dark, brush55);
        palette73.setBrush(QPalette::Disabled, QPalette::Mid, brush56);
        palette73.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette73.setBrush(QPalette::Disabled, QPalette::BrightText, brush7);
        palette73.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette73.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette73.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette73.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette73.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette73.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush57);
        palette73.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette73.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        checkBox_TouchInterval->setPalette(palette73);
        lineEdit_TouchInterval = new QLineEdit(gridWidget_3);
        lineEdit_TouchInterval->setObjectName(QString::fromUtf8("lineEdit_TouchInterval"));
        lineEdit_TouchInterval->setGeometry(QRect(240, 180, 150, 30));
        QPalette palette74;
        palette74.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette74.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette74.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette74.setBrush(QPalette::Active, QPalette::BrightText, brush30);
        palette74.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette74.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette74.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush61(QColor(0, 0, 0, 128));
        brush61.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette74.setBrush(QPalette::Active, QPalette::PlaceholderText, brush61);
#endif
        palette74.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette74.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette74.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette74.setBrush(QPalette::Inactive, QPalette::BrightText, brush30);
        palette74.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette74.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette74.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush62(QColor(0, 0, 0, 128));
        brush62.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette74.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush62);
#endif
        palette74.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette74.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette74.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette74.setBrush(QPalette::Disabled, QPalette::BrightText, brush30);
        palette74.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette74.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette74.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        QBrush brush63(QColor(0, 0, 0, 128));
        brush63.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette74.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush63);
#endif
        lineEdit_TouchInterval->setPalette(palette74);
        lineEdit_TouchInterval->setMouseTracking(false);
        lineEdit_TouchInterval->setFocusPolicy(Qt::NoFocus);
        lineEdit_TouchInterval->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color : black;"));
        lineEdit_TouchInterval->setReadOnly(true);
        pushButton_LS_Back = new QPushButton(page_30);
        pushButton_LS_Back->setObjectName(QString::fromUtf8("pushButton_LS_Back"));
        pushButton_LS_Back->setEnabled(true);
        pushButton_LS_Back->setGeometry(QRect(20, 340, 131, 51));
        QPalette palette75;
        palette75.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette75.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette75.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette75.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette75.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette75.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette75.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette75.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette75.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette75.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette75.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette75.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        pushButton_LS_Back->setPalette(palette75);
        pushButton_LS_Back->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_LS_update = new QPushButton(page_30);
        pushButton_LS_update->setObjectName(QString::fromUtf8("pushButton_LS_update"));
        pushButton_LS_update->setGeometry(QRect(480, 340, 131, 51));
        QPalette palette76;
        palette76.setBrush(QPalette::Active, QPalette::WindowText, brush44);
        palette76.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette76.setBrush(QPalette::Active, QPalette::Text, brush44);
        palette76.setBrush(QPalette::Active, QPalette::ButtonText, brush44);
        palette76.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette76.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush64(QColor(255, 255, 0, 128));
        brush64.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette76.setBrush(QPalette::Active, QPalette::PlaceholderText, brush64);
#endif
        palette76.setBrush(QPalette::Inactive, QPalette::WindowText, brush44);
        palette76.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette76.setBrush(QPalette::Inactive, QPalette::Text, brush44);
        palette76.setBrush(QPalette::Inactive, QPalette::ButtonText, brush44);
        palette76.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette76.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush65(QColor(255, 255, 0, 128));
        brush65.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette76.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush65);
#endif
        palette76.setBrush(QPalette::Disabled, QPalette::WindowText, brush44);
        palette76.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette76.setBrush(QPalette::Disabled, QPalette::Text, brush44);
        palette76.setBrush(QPalette::Disabled, QPalette::ButtonText, brush44);
        palette76.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette76.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush66(QColor(255, 255, 0, 128));
        brush66.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette76.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush66);
#endif
        pushButton_LS_update->setPalette(palette76);
        pushButton_LS_update->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"color: yellow; border: 1px solid #FFFFFF;border-radius:10px;"));
        label_LoadSharing = new QLabel(page_30);
        label_LoadSharing->setObjectName(QString::fromUtf8("label_LoadSharing"));
        label_LoadSharing->setGeometry(QRect(80, 20, 431, 21));
        label_LoadSharing->setStyleSheet(QString::fromUtf8("color : yellow"));
        stackedWidget_Factory->addWidget(page_30);
        pushButton_AdminDcProfile = new QPushButton(page_19);
        pushButton_AdminDcProfile->setObjectName(QString::fromUtf8("pushButton_AdminDcProfile"));
        pushButton_AdminDcProfile->setEnabled(true);
        pushButton_AdminDcProfile->setGeometry(QRect(10, 20, 110, 37));
        QPalette palette77;
        palette77.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette77.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette77.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette77.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette77.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette77.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette77.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette77.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette77.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette77.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette77.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette77.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette77.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette77.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette77.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette77.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette77.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette77.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_AdminDcProfile->setPalette(palette77);
        pushButton_AdminDcProfile->setFont(font4);
        pushButton_AdminDcProfile->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_AdminDcProfile->setAutoDefault(false);
        pushButton_Serial_Number = new QPushButton(page_19);
        pushButton_Serial_Number->setObjectName(QString::fromUtf8("pushButton_Serial_Number"));
        pushButton_Serial_Number->setEnabled(true);
        pushButton_Serial_Number->setGeometry(QRect(10, 70, 110, 37));
        QPalette palette78;
        palette78.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette78.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette78.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette78.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette78.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette78.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette78.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette78.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette78.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette78.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette78.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette78.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette78.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette78.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette78.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette78.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette78.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette78.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_Serial_Number->setPalette(palette78);
        pushButton_Serial_Number->setFont(font4);
        pushButton_Serial_Number->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Serial_Number->setAutoDefault(false);
        pushButton_FW = new QPushButton(page_19);
        pushButton_FW->setObjectName(QString::fromUtf8("pushButton_FW"));
        pushButton_FW->setEnabled(true);
        pushButton_FW->setGeometry(QRect(10, 120, 110, 37));
        QPalette palette79;
        palette79.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette79.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette79.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette79.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette79.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette79.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette79.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette79.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette79.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette79.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette79.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette79.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette79.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette79.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette79.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette79.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette79.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette79.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_FW->setPalette(palette79);
        pushButton_FW->setFont(font4);
        pushButton_FW->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_FW->setAutoDefault(false);
        pushButton_Load_Sharing = new QPushButton(page_19);
        pushButton_Load_Sharing->setObjectName(QString::fromUtf8("pushButton_Load_Sharing"));
        pushButton_Load_Sharing->setEnabled(true);
        pushButton_Load_Sharing->setGeometry(QRect(10, 170, 110, 37));
        QPalette palette80;
        palette80.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette80.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette80.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette80.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette80.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette80.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette80.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette80.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette80.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette80.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette80.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette80.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette80.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette80.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette80.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette80.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette80.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette80.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pushButton_Load_Sharing->setPalette(palette80);
        pushButton_Load_Sharing->setFont(font4);
        pushButton_Load_Sharing->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_Load_Sharing->setAutoDefault(false);
        stackedWidget->addWidget(page_19);
        page_29 = new QWidget();
        page_29->setObjectName(QString::fromUtf8("page_29"));
        pushButton_keyboard_chr_password_8 = new QPushButton(page_29);
        pushButton_keyboard_chr_password_8->setObjectName(QString::fromUtf8("pushButton_keyboard_chr_password_8"));
        pushButton_keyboard_chr_password_8->setGeometry(QRect(560, 140, 70, 51));
        pushButton_keyboard_chr_password_8->setStyleSheet(QString::fromUtf8("background-color:rgb(1,120,240)"));
        label_516 = new QLabel(page_29);
        label_516->setObjectName(QString::fromUtf8("label_516"));
        label_516->setGeometry(QRect(380, 60, 261, 31));
        label_516->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 16pt \"Ubuntu\";\n"
""));
        lineEdit_chr_Password_8 = new QLineEdit(page_29);
        lineEdit_chr_Password_8->setObjectName(QString::fromUtf8("lineEdit_chr_Password_8"));
        lineEdit_chr_Password_8->setGeometry(QRect(330, 140, 231, 50));
        lineEdit_chr_Password_8->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255)"));
        lineEdit_chr_Password_8->setMaxLength(50);
        lineEdit_chr_Password_8->setFrame(false);
        lineEdit_chr_Password_8->setClearButtonEnabled(true);
        pushButton_chr_Login_8 = new QPushButton(page_29);
        pushButton_chr_Login_8->setObjectName(QString::fromUtf8("pushButton_chr_Login_8"));
        pushButton_chr_Login_8->setGeometry(QRect(410, 230, 101, 41));
        pushButton_chr_Login_8->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        pushButton_chr_CancelLogin_8 = new QPushButton(page_29);
        pushButton_chr_CancelLogin_8->setObjectName(QString::fromUtf8("pushButton_chr_CancelLogin_8"));
        pushButton_chr_CancelLogin_8->setGeometry(QRect(70, 330, 101, 41));
        pushButton_chr_CancelLogin_8->setStyleSheet(QString::fromUtf8("background-color:rgb(2,164,255);\n"
"border: 1px solid #FFFFFF;border-radius:10px;"));
        label_Message_chr_Login_8 = new QLabel(page_29);
        label_Message_chr_Login_8->setObjectName(QString::fromUtf8("label_Message_chr_Login_8"));
        label_Message_chr_Login_8->setGeometry(QRect(300, 310, 331, 31));
        label_Message_chr_Login_8->setStyleSheet(QString::fromUtf8("color:red;"));
        label_517 = new QLabel(page_29);
        label_517->setObjectName(QString::fromUtf8("label_517"));
        label_517->setGeometry(QRect(190, 150, 101, 21));
        stackedWidget->addWidget(page_29);
        label_lubi = new QLabel(centralWidget);
        label_lubi->setObjectName(QString::fromUtf8("label_lubi"));
        label_lubi->setGeometry(QRect(0, 0, 114, 61));
        label_lubi->setContextMenuPolicy(Qt::NoContextMenu);
        label_lubi->setAutoFillBackground(false);
        label_lubi->setPixmap(QPixmap(QString::fromUtf8(":/images/NLubi Logo.png")));
        label_lubi->setScaledContents(true);
        label_ocpp = new QLabel(centralWidget);
        label_ocpp->setObjectName(QString::fromUtf8("label_ocpp"));
        label_ocpp->setGeometry(QRect(600, 0, 71, 67));
        label_ocpp->setPixmap(QPixmap(QString::fromUtf8(":/images/CLUD-2.png")));
        label_network = new QLabel(centralWidget);
        label_network->setObjectName(QString::fromUtf8("label_network"));
        label_network->setGeometry(QRect(510, 0, 68, 67));
        label_network->setPixmap(QPixmap(QString::fromUtf8(":/images/WIFI-2.png")));
        label_TEx = new QLabel(centralWidget);
        label_TEx->setObjectName(QString::fromUtf8("label_TEx"));
        label_TEx->setGeometry(QRect(420, 20, 80, 31));
        label_TEx->setMouseTracking(true);
        label_TEx->setAutoFillBackground(false);
        label_TEx->setTextFormat(Qt::AutoText);
        label_TEx->setScaledContents(true);
        label_TEx->setMargin(0);
        label_TEx->setIndent(-1);
        label_Test = new QLabel(centralWidget);
        label_Test->setObjectName(QString::fromUtf8("label_Test"));
        label_Test->setGeometry(QRect(350, 20, 60, 31));
        label_Test->setMouseTracking(true);
        label_Test->setAutoFillBackground(false);
        label_Test->setTextFormat(Qt::AutoText);
        label_Test->setScaledContents(true);
        label_Test->setMargin(0);
        label_Test->setIndent(-1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        pushButton_CCS->setDefault(false);
        pushButton_CCS_2->setDefault(false);
        stackedWidget_Admin->setCurrentIndex(11);
        pushButton_AdminEthernet->setDefault(true);
        pushButton_AdminWifi->setDefault(true);
        pushButton_Admin4G->setDefault(true);
        pushButton_Signin->setDefault(true);
        pushButton_Charging_psw->setDefault(true);
        pushButton_AdminOCPP->setDefault(true);
        pushButton_Price_setting->setDefault(true);
        pushButton_AdminSetting->setDefault(true);
        pushButton_History_Page->setDefault(true);
        pushButton_Display_setting->setDefault(true);
        pushButton_Network->setDefault(true);
        pushButton_Password->setDefault(true);
        stackedWidget_Factory->setCurrentIndex(3);
        pushButton_Profile_Save->setDefault(true);
        pushButton_keyboard_Max_V->setDefault(true);
        pushButton_keyboard_Max_I->setDefault(true);
        pushButton_keyboard_Min_V->setDefault(true);
        pushButton_keyboard_Min_I->setDefault(true);
        pushButton_keyboard_Max_P->setDefault(true);
        pushButton_keyboard_Min_P->setDefault(true);
        pushButton_Profile_Back->setDefault(true);
        pushButton_Serial_Save->setDefault(true);
        pushButton_SN_Back->setDefault(true);
        pushButton_keyboard_Serial_Number->setDefault(true);
        pushButton_keyboard_TProtection->setDefault(true);
        pushButton_keyboard_CutoffSoc->setDefault(true);
        pushButton_keyboard_FW_servername->setDefault(true);
        pushButton_keyboard_FW_password->setDefault(true);
        pushButton_keyboard_FW_username->setDefault(true);
        pushButton_FW_Update->setDefault(true);
        pushButton_keyboard_FW_path->setDefault(true);
        pushButton_FW_Back->setDefault(true);
        pushButton_keyboard_TouchInterval->setDefault(true);
        pushButton_LS_Back->setDefault(true);
        pushButton_LS_update->setDefault(true);
        pushButton_AdminDcProfile->setDefault(true);
        pushButton_Serial_Number->setDefault(true);
        pushButton_FW->setDefault(true);
        pushButton_Load_Sharing->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Time->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#eeeeec;\">TextLabel</span></p></body></html>", nullptr));
        pushButton_AdminIcon->setText(QString());
        label_car->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_CCS->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_CCS->setText(QString());
        label_33->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Amount</span></p></body></html>", nullptr));
        label_CCS_Time_Front->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Min</span></p></body></html>", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Time</span></p></body></html>", nullptr));
        Status->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#eeeeec;\">Available</span></p></body></html>", nullptr));
        label_CCS_Amount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Status</span></p></body></html>", nullptr));
        label_CCS_Status->setText(QCoreApplication::translate("MainWindow", "No Error", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Rs</span></p></body></html>", nullptr));
        label_66->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">V0.01</p></body></html>", nullptr));
        label_CCS_Amount_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Status_2->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#eeeeec;\">Available</span></p></body></html>", nullptr));
        label_CCS_Time_Front_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_145->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Time</span></p></body></html>", nullptr));
        label_143->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Amount</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_CCS_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_CCS_2->setText(QString());
        label_144->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Min</span></p></body></html>", nullptr));
        label_RFIDimgCCS->setText(QString());
        label_rfidstatus->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#eeeeec;\">Keep RFID card or tag in front of reader </span></p></body></html>", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_ChargeByPswd->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        pushButton_ChargeByPswd->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_ChargeByPswd->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton_RFID_Next->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_Save_charging->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_Back_charging->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Charge By Time</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Charge By kWh</span></p></body></html>", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Minutes</span></p></body></html>", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Unit</span></p></body></html>", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Automatic</span></p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        pushButton_Keyboard_chargebytime->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_Keyboard_charggebyunit->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_charging_validation->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_waiting->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">waiting</span></p></body></html>", nullptr));
        pushButton_Error_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_EmergencyStopCCS->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_EvCurrent->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        label_VoltageValue->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Voltage</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_VoltageValue->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_BatteryPercentage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_lbElapseTime->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        pushButton_Back_DuringCharging->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Charging Time</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#eeeeec;\">V</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">EV Demand</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">AC</span></p></body></html>", nullptr));
        label_Power_Consumption->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#eeeeec;\">kWh</span></p></body></html>", nullptr));
        label_Energy_Consumption->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#eeeeec;\">Charging Parameters</span></p></body></html>", nullptr));
        label_100->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Output DC</span></p></body></html>", nullptr));
        label_Output_Power->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_101->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#eeeeec;\">A</span></p></body></html>", nullptr));
        label_Output_Current->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Remaining Time</span></p></body></html>", nullptr));
        t1_lbRemainTime->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        lbl_ERROR_CODE->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#eeeeec;\">kW</span></p></body></html>", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#eeeeec;\">A</span></p></body></html>", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#eeeeec;\">V</span></p></body></html>", nullptr));
        label_Tempreture_plus->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_Tempreture_minus->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Gun Temp.</span></p></body></html>", nullptr));
        pushButton_CCSPayment->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label_Payment->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#eeeeec;\">Payment</span></p></body></html>", nullptr));
        label_TotalPay->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Charging Duration</span></p></body></html>", nullptr));
        label_Paymen_Heading->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Energy Consumed</span></p></body></html>", nullptr));
        label_CCS_ChargingEnergy->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">KWh</span></p></body></html>", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Total Amount</span></p></body></html>", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Rs</span></p></body></html>", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">Minutes</span></p></body></html>", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\"  font-size:12pt; font-weight:600; color:#eeeeec;\">Reason</span></p></body></html>", nullptr));
        label_Stop_reason->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">0</span></p></body></html>", nullptr));
        label_67->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">Wait for Finishing</span></p></body></html>", nullptr));
        pushButton_OuterFinishCCS->setText(QString());
        pushButton_FinishCCS->setText(QCoreApplication::translate("MainWindow", "FINISH", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Charging is completed </p><p>Please touch &quot;Finish&quot; button</p></body></html>", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; color:#eeeeec;\">Charging is completed</span></p></body></html>", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">AC-02 Charging Parameter</span></p></body></html>", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "Power Consumption", nullptr));
        label_PowerConsum_AC->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "Energy Consumption", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "Total Energy", nullptr));
        label_EnergyConsum_AC->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_TotalEnergy_AC->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_ChargingParamAC->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "Voltage", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "Current", nullptr));
        label_Voltage_AC->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_Current_AC->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "Login ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; color:#ffffff;\">Admin</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#eeeeec;\">Password</span></p></body></html>", nullptr));
        label_MessageLogin->setText(QString());
        pushButton_keyboard_password->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_CancelLogin->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_chr_CancelLogin->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Start Charging</span></p></body></html>", nullptr));
        label_74->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#eeeeec;\">Password</span></p></body></html>", nullptr));
        pushButton_keyboard_chr_password->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        pushButton_chr_Login->setText(QCoreApplication::translate("MainWindow", "Login ", nullptr));
        label_Message_chr_Login->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Local IP</span></p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Subnet Mask</span></p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Gateway IP</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_LocalIP->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>background-color:rgb(255,255,255)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Ether_Localip->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_Ether_Gatewayip->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_Ether_Subnet->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_EthernetSetting->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_EthernetSetting_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        EthernetEnable->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_ethernet_status->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fce94f;\"><br/></span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">OCPP Available Integration</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Server URL</span></p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#0725ed;\">OCPP 1.6</span></p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Server Port</span></p></body></html>", nullptr));
        pushButton_Confirmocpp->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_Return_OCPP->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_keyboard_serverPort->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_Keyboard_serverURL->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        OCPPEnable->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_ocpp_saved->setText(QString());
        pushButton_AdminEthernet->setText(QCoreApplication::translate("MainWindow", "Ethernet", nullptr));
        pushButton_AdminWifi->setText(QCoreApplication::translate("MainWindow", "Wifi", nullptr));
        pushButton_Admin4G->setText(QCoreApplication::translate("MainWindow", "4G", nullptr));
        pushButton_Nework_back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_Signin->setText(QCoreApplication::translate("MainWindow", "Admin Password", nullptr));
        pushButton_Charging_psw->setText(QCoreApplication::translate("MainWindow", "Charging Password", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_Psw_Back->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        pushButton_Psw_Back->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_Psw_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Password</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Confirm Password </span></p></body></html>", nullptr));
        label_RegisterMsg->setText(QString());
        pushButton_Regi_confirmpass->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_Regi_password->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_SaveRegister->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_BackAdminPsw->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">SSID</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Password</span></p></body></html>", nullptr));
        pushButton_WifiSetting->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_keyboard_SSID->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_keyboard_wifiPass->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_WifiSetting_back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        WIFIEnable->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_wifi_saved->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fce94f;\"><br/></span></p></body></html>", nullptr));
        pushButton_getOutfromPriceSett->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Rs/kWh</span></p></body></html>", nullptr));
        pushButton_keyboard_Setting->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_PriceSetting_back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_pricesetting_saved->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fce94f;\"><br/></span></p></body></html>", nullptr));
        pushButton_Setting->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Over Voltage</span></p></body></html>", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Under Voltage</span></p></body></html>", nullptr));
        label_65->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Over Current</span></p></body></html>", nullptr));
        pushButton_keyboard_OverVolt->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_keyboard_UnderVolt->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_keyboard_OverCurrCCS->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_Setting_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_Protection_saved->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fcaf3e;\"><br/></span></p></body></html>", nullptr));
        pushButton_keyboard_APN->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_APN->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#eeeeec;\">APN </span></p></body></html>", nullptr));
        IPv4_radioButton->setText(QCoreApplication::translate("MainWindow", "IP V4", nullptr));
        IPv6_radioButton->setText(QCoreApplication::translate("MainWindow", "IP V6", nullptr));
        IPv4v6_radioButton->setText(QCoreApplication::translate("MainWindow", "IP V4V6", nullptr));
        pushButton_Cancel_gsm->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_Save_gsm->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        GSMEnable->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_gsm_saved->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fce94f;\"><br/></span></p></body></html>", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Start Time</span></p></body></html>", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Reason</span></p></body></html>", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Transaction No</span></p></body></html>", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Total Time</span></p></body></html>", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">   Consumed Energy  </span></p></body></html>", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">End Time</span></p></body></html>", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Gun No</span></p></body></html>", nullptr));
        pushbutton_history_up->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        pushbutton_history_clear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        pushbutton_history_down->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        pushbutton_history_back->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Set Date Time</p></body></html>", nullptr));
        pushButton_KeyBord_TimeDate->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Brightness</p></body></html>", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>YYYY-MM-dd hh:mm:ss </p></body></html>", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Sleep Time</p></body></html>", nullptr));
        pushButton_KeyBord_sleeptime->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Time Zone Offset</p></body></html>", nullptr));
        pushButton_KeyBord_Timezone->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_72->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>5.30</p></body></html>", nullptr));
        pushButton_Save_Displaysetting->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_Back_Display_setting->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_displaysetting_status->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fce94f;\"><br/></span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Password</span></p></body></html>", nullptr));
        pushButton_BackChargingPsw->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_ChrgMsg->setText(QString());
        label_73->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Confirm Password </span></p></body></html>", nullptr));
        pushButton_Chrg_password->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_charging_confirmpass->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_ChargingSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_AdminOCPP->setText(QCoreApplication::translate("MainWindow", "OCPP", nullptr));
        pushButton_Price_setting->setText(QCoreApplication::translate("MainWindow", "Price Setting", nullptr));
        pushButton_AdminSetting->setText(QCoreApplication::translate("MainWindow", "Protections", nullptr));
        pushButton_History_Page->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        pushButton_Display_setting->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        pushButton_Network->setText(QCoreApplication::translate("MainWindow", "Network", nullptr));
        pushButton_Password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton_Profile_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_Max_V->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Max_Voltage</span></p></body></html>", nullptr));
        pushButton_keyboard_Max_V->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        pushButton_keyboard_Max_I->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        label_Max_I->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Max_Current</span></p></body></html>", nullptr));
        pushButton_keyboard_Min_V->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        label_Min_V->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Min_Voltage</span></p></body></html>", nullptr));
        pushButton_keyboard_Min_I->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        label_Min_I->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Min_Current</span></p></body></html>", nullptr));
        pushButton_keyboard_Max_P->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        label_Max_P->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Max_Power</span></p></body></html>", nullptr));
        pushButton_keyboard_Min_P->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        label_Min_P->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Min_Power</span></p></body></html>", nullptr));
        pushButton_Profile_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_Profiled_saved->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fcaf3e;\"><br/></span></p></body></html>", nullptr));
        pushButton_Serial_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_SN_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_SN_saved->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fcaf3e;\"><br/></span></p></body></html>", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Door Lock sensor</span></p></body></html>", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Temperature Threshold </span></p></body></html>", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Cut Off SOC</span></p></body></html>", nullptr));
        checkBox_TempProtection->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Serial  No</span></p></body></html>", nullptr));
        pushButton_keyboard_Serial_Number->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_keyboard_TProtection->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_keyboard_CutoffSoc->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        checkBox_DoorLock->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        checkBox_CuttofSoc->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Test Mode</span></p></body></html>", nullptr));
        checkBox_TestMode->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_80->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Isolation Fault</span></p></body></html>", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Ground Fault</span></p></body></html>", nullptr));
        checkBox_GroundFault->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        checkBox_IsolationFault->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        pushButton_keyboard_FW_servername->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        FW_S->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">Server Name</span></p></body></html>", nullptr));
        FW_P->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">Path</span></p></body></html>", nullptr));
        FW->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#fce94f;\">Firmware Update</span></p></body></html>", nullptr));
        FW_PW->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">Password</span></p></body></html>", nullptr));
        pushButton_keyboard_FW_password->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_keyboard_FW_username->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        FW_U->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">Username</span></p></body></html>", nullptr));
        pushButton_FW_Update->setText(QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
        pushButton_keyboard_FW_path->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        pushButton_FW_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_85->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Load sharing</span></p></body></html>", nullptr));
        checkBox_LoadSharing->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_86->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Post Start Load sharing</span></p></body></html>", nullptr));
        checkBox_PostSLSharing->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        checkBox_PreSLoadsharing->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Pre Start Load sharing</span></p></body></html>", nullptr));
        label_88->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Individual Power Module</span></p></body></html>", nullptr));
        checkBox_PMIndividual->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        pushButton_keyboard_TouchInterval->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_82->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"left\"><span style=\" font-weight:600; color:#eeeeec;\">Touch Refresh Interval</span></p></body></html>", nullptr));
        checkBox_TouchInterval->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        pushButton_LS_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_LS_update->setText(QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
        label_LoadSharing->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#fcaf3e;\"><br/></span></p></body></html>", nullptr));
        pushButton_AdminDcProfile->setText(QCoreApplication::translate("MainWindow", "DC Profile", nullptr));
        pushButton_Serial_Number->setText(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        pushButton_FW->setText(QCoreApplication::translate("MainWindow", "FW Update", nullptr));
        pushButton_Load_Sharing->setText(QCoreApplication::translate("MainWindow", "Load Sharing", nullptr));
        pushButton_keyboard_chr_password_8->setText(QCoreApplication::translate("MainWindow", "Keypad", nullptr));
        label_516->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Stop Charging</span></p></body></html>", nullptr));
        pushButton_chr_Login_8->setText(QCoreApplication::translate("MainWindow", "Login ", nullptr));
        pushButton_chr_CancelLogin_8->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_Message_chr_Login_8->setText(QString());
        label_517->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#eeeeec;\">Password</span></p></body></html>", nullptr));
        label_lubi->setText(QString());
        label_ocpp->setText(QString());
        label_network->setText(QString());
        label_TEx->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">PT 35 C</span></p></body></html>", nullptr));
        label_Test->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">T</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
