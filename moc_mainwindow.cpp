/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[164];
    char stringdata0[4759];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "sgnForceStop"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "sgnCharger_Stop"
QT_MOC_LITERAL(4, 41, 15), // "sgnCharging_End"
QT_MOC_LITERAL(5, 57, 18), // "sgnCharger_TimeOUT"
QT_MOC_LITERAL(6, 76, 16), // "sgnCharger_Start"
QT_MOC_LITERAL(7, 93, 7), // "sgnBack"
QT_MOC_LITERAL(8, 101, 12), // "signalPlcmod"
QT_MOC_LITERAL(9, 114, 38), // "on_pushButton_EmergencyStopCC..."
QT_MOC_LITERAL(10, 153, 8), // "CCSStart"
QT_MOC_LITERAL(11, 162, 12), // "workFinished"
QT_MOC_LITERAL(12, 175, 7), // "rResult"
QT_MOC_LITERAL(13, 183, 16), // "CCS_relay_status"
QT_MOC_LITERAL(14, 200, 11), // "ACGunStatus"
QT_MOC_LITERAL(15, 212, 8), // "TimeRead"
QT_MOC_LITERAL(16, 221, 13), // "Start_Charger"
QT_MOC_LITERAL(17, 235, 5), // "nMode"
QT_MOC_LITERAL(18, 241, 19), // "Remot_Start_Charger"
QT_MOC_LITERAL(19, 261, 12), // "Stop_Charger"
QT_MOC_LITERAL(20, 274, 18), // "Remot_Stop_Charger"
QT_MOC_LITERAL(21, 293, 11), // "End_Charger"
QT_MOC_LITERAL(22, 305, 17), // "LoadSharingStatus"
QT_MOC_LITERAL(23, 323, 19), // "LoadSharingStatus_2"
QT_MOC_LITERAL(24, 343, 13), // "End_Charger_2"
QT_MOC_LITERAL(25, 357, 10), // "ForcedStop"
QT_MOC_LITERAL(26, 368, 6), // "nGroup"
QT_MOC_LITERAL(27, 375, 18), // "chargingSchemeSlot"
QT_MOC_LITERAL(28, 394, 20), // "FirmwareUpdateStatus"
QT_MOC_LITERAL(29, 415, 6), // "status"
QT_MOC_LITERAL(30, 422, 10), // "OpenSerial"
QT_MOC_LITERAL(31, 433, 14), // "StartRemoteApp"
QT_MOC_LITERAL(32, 448, 12), // "TagId_Search"
QT_MOC_LITERAL(33, 461, 16), // "UserPasswordSlot"
QT_MOC_LITERAL(34, 478, 15), // "AdminSignInSlot"
QT_MOC_LITERAL(35, 494, 12), // "EthernetSlot"
QT_MOC_LITERAL(36, 507, 8), // "OcppSlot"
QT_MOC_LITERAL(37, 516, 8), // "WifiSlot"
QT_MOC_LITERAL(38, 525, 16), // "PriceSettingSlot"
QT_MOC_LITERAL(39, 542, 11), // "SettingSlot"
QT_MOC_LITERAL(40, 554, 14), // "DC_ProfileSlot"
QT_MOC_LITERAL(41, 569, 13), // "Serial_number"
QT_MOC_LITERAL(42, 583, 16), // "Firmware_Upgrade"
QT_MOC_LITERAL(43, 600, 8), // "GSMSSlot"
QT_MOC_LITERAL(44, 609, 14), // "DisplaySetting"
QT_MOC_LITERAL(45, 624, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(46, 648, 25), // "on_pushButton_CCS_clicked"
QT_MOC_LITERAL(47, 674, 32), // "on_pushButton_CCSPayment_clicked"
QT_MOC_LITERAL(48, 707, 31), // "on_pushButton_FinishCCS_clicked"
QT_MOC_LITERAL(49, 739, 27), // "on_pushButton_Login_clicked"
QT_MOC_LITERAL(50, 767, 28), // "on_pushButton_Signin_clicked"
QT_MOC_LITERAL(51, 796, 33), // "on_pushButton_CancelLogin_cli..."
QT_MOC_LITERAL(52, 830, 34), // "on_pushButton_SaveRegister_cl..."
QT_MOC_LITERAL(53, 865, 33), // "on_pushButton_Return_OCPP_cli..."
QT_MOC_LITERAL(54, 899, 33), // "on_pushButton_Confirmocpp_cli..."
QT_MOC_LITERAL(55, 933, 31), // "on_pushButton_AdminIcon_clicked"
QT_MOC_LITERAL(56, 965, 31), // "on_pushButton_AdminOCPP_clicked"
QT_MOC_LITERAL(57, 997, 35), // "on_pushButton_AdminEthernet_c..."
QT_MOC_LITERAL(58, 1033, 31), // "on_pushButton_AdminWifi_clicked"
QT_MOC_LITERAL(59, 1065, 37), // "on_pushButton_EthernetSetting..."
QT_MOC_LITERAL(60, 1103, 33), // "on_pushButton_WifiSetting_cli..."
QT_MOC_LITERAL(61, 1137, 35), // "on_pushButton_Price_setting_c..."
QT_MOC_LITERAL(62, 1173, 41), // "on_pushButton_getOutfromPrice..."
QT_MOC_LITERAL(63, 1215, 29), // "on_pushButton_Setting_clicked"
QT_MOC_LITERAL(64, 1245, 34), // "on_pushButton_AdminSetting_cl..."
QT_MOC_LITERAL(65, 1280, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(66, 1300, 37), // "on_pushButton_ChargingParamAC..."
QT_MOC_LITERAL(67, 1338, 39), // "on_pushButton_keyboard_passwo..."
QT_MOC_LITERAL(68, 1378, 35), // "on_pushButton_Regi_password_c..."
QT_MOC_LITERAL(69, 1414, 38), // "on_pushButton_Regi_confirmpas..."
QT_MOC_LITERAL(70, 1453, 35), // "on_pushButton_Ether_Localip_c..."
QT_MOC_LITERAL(71, 1489, 37), // "on_pushButton_Ether_Gatewayip..."
QT_MOC_LITERAL(72, 1527, 34), // "on_pushButton_Ether_Subnet_cl..."
QT_MOC_LITERAL(73, 1562, 40), // "on_pushButton_Keyboard_server..."
QT_MOC_LITERAL(74, 1603, 41), // "on_pushButton_keyboard_server..."
QT_MOC_LITERAL(75, 1645, 35), // "on_pushButton_keyboard_SSID_c..."
QT_MOC_LITERAL(76, 1681, 39), // "on_pushButton_keyboard_wifiPa..."
QT_MOC_LITERAL(77, 1721, 40), // "on_pushButton_keyboard_PriceS..."
QT_MOC_LITERAL(78, 1762, 38), // "on_pushButton_keyboard_Settin..."
QT_MOC_LITERAL(79, 1801, 39), // "on_pushButton_keyboard_OverVo..."
QT_MOC_LITERAL(80, 1841, 40), // "on_pushButton_keyboard_UnderV..."
QT_MOC_LITERAL(81, 1882, 42), // "on_pushButton_keyboard_OverCu..."
QT_MOC_LITERAL(82, 1925, 31), // "on_stackedWidget_currentChanged"
QT_MOC_LITERAL(83, 1957, 4), // "arg1"
QT_MOC_LITERAL(84, 1962, 34), // "on_pushButton_History_Page_cl..."
QT_MOC_LITERAL(85, 1997, 36), // "on_pushButton_keyboard_Max_V_..."
QT_MOC_LITERAL(86, 2034, 36), // "on_pushButton_keyboard_Min_V_..."
QT_MOC_LITERAL(87, 2071, 36), // "on_pushButton_keyboard_Max_I_..."
QT_MOC_LITERAL(88, 2108, 36), // "on_pushButton_keyboard_Min_P_..."
QT_MOC_LITERAL(89, 2145, 29), // "on_pushButton_Admin4G_clicked"
QT_MOC_LITERAL(90, 2175, 36), // "on_pushButton_AdminDcProfile_..."
QT_MOC_LITERAL(91, 2212, 29), // "on_IPv4v6_radioButton_clicked"
QT_MOC_LITERAL(92, 2242, 27), // "on_IPv6_radioButton_clicked"
QT_MOC_LITERAL(93, 2270, 27), // "on_IPv4_radioButton_clicked"
QT_MOC_LITERAL(94, 2298, 34), // "on_pushButton_keyboard_APN_cl..."
QT_MOC_LITERAL(95, 2333, 36), // "on_pushButton_keyboard_Min_I_..."
QT_MOC_LITERAL(96, 2370, 36), // "on_pushButton_keyboard_Max_P_..."
QT_MOC_LITERAL(97, 2407, 35), // "on_pushButton_Save_charging_c..."
QT_MOC_LITERAL(98, 2443, 43), // "on_pushButton_Keyboard_charge..."
QT_MOC_LITERAL(99, 2487, 44), // "on_pushButton_Keyboard_chargg..."
QT_MOC_LITERAL(100, 2532, 34), // "on_pushButton_Profile_Save_cl..."
QT_MOC_LITERAL(101, 2567, 34), // "on_pushButton_Profile_Back_cl..."
QT_MOC_LITERAL(102, 2602, 30), // "on_pushButton_Save_gsm_clicked"
QT_MOC_LITERAL(103, 2633, 32), // "on_pushButton_Cancel_gsm_clicked"
QT_MOC_LITERAL(104, 2666, 38), // "on_pushButton_WifiSetting_bac..."
QT_MOC_LITERAL(105, 2705, 34), // "on_pushButton_Setting_Back_cl..."
QT_MOC_LITERAL(106, 2740, 39), // "on_pushButton_PriceSetting_ba..."
QT_MOC_LITERAL(107, 2780, 21), // "on_WIFIEnable_clicked"
QT_MOC_LITERAL(108, 2802, 7), // "checked"
QT_MOC_LITERAL(109, 2810, 25), // "on_EthernetEnable_clicked"
QT_MOC_LITERAL(110, 2836, 20), // "on_GSMEnable_clicked"
QT_MOC_LITERAL(111, 2857, 21), // "on_OCPPEnable_clicked"
QT_MOC_LITERAL(112, 2879, 34), // "on_pushbutton_history_back_cl..."
QT_MOC_LITERAL(113, 2914, 35), // "on_pushButton_Serial_Number_c..."
QT_MOC_LITERAL(114, 2950, 44), // "on_pushButton_keyboard_Serial..."
QT_MOC_LITERAL(115, 2995, 35), // "on_pushButton_Back_charging_c..."
QT_MOC_LITERAL(116, 3031, 24), // "on_pushButton_FW_clicked"
QT_MOC_LITERAL(117, 3056, 44), // "on_pushButton_keyboard_FW_ser..."
QT_MOC_LITERAL(118, 3101, 38), // "on_pushButton_keyboard_FW_pat..."
QT_MOC_LITERAL(119, 3140, 42), // "on_pushButton_keyboard_FW_pas..."
QT_MOC_LITERAL(120, 3183, 42), // "on_pushButton_keyboard_FW_use..."
QT_MOC_LITERAL(121, 3226, 33), // "on_pushButton_Serial_Save_cli..."
QT_MOC_LITERAL(122, 3260, 31), // "on_pushButton_FW_Update_clicked"
QT_MOC_LITERAL(123, 3292, 35), // "on_pushbutton_history_clear_c..."
QT_MOC_LITERAL(124, 3328, 32), // "on_pushbutton_history_up_clicked"
QT_MOC_LITERAL(125, 3361, 34), // "on_pushbutton_history_down_cl..."
QT_MOC_LITERAL(126, 3396, 42), // "on_pushButton_EthernetSetting..."
QT_MOC_LITERAL(127, 3439, 29), // "on_pushButton_FW_Back_clicked"
QT_MOC_LITERAL(128, 3469, 38), // "on_pushButton_KeyBord_TimeDat..."
QT_MOC_LITERAL(129, 3508, 42), // "on_pushButton_Back_Display_se..."
QT_MOC_LITERAL(130, 3551, 41), // "on_pushButton_Save_Displayset..."
QT_MOC_LITERAL(131, 3593, 38), // "on_pushButton_KeyBord_Timezon..."
QT_MOC_LITERAL(132, 3632, 39), // "on_pushButton_KeyBord_sleepti..."
QT_MOC_LITERAL(133, 3672, 37), // "on_pushButton_Display_setting..."
QT_MOC_LITERAL(134, 3710, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(135, 3743, 5), // "value"
QT_MOC_LITERAL(136, 3749, 34), // "on_pushButton_Charging_psw_cl..."
QT_MOC_LITERAL(137, 3784, 30), // "on_pushButton_Psw_Back_clicked"
QT_MOC_LITERAL(138, 3815, 30), // "on_pushButton_Password_clicked"
QT_MOC_LITERAL(139, 3846, 29), // "on_pushButton_Network_clicked"
QT_MOC_LITERAL(140, 3876, 33), // "on_pushButton_Nework_back_cli..."
QT_MOC_LITERAL(141, 3910, 35), // "on_pushButton_Chrg_password_c..."
QT_MOC_LITERAL(142, 3946, 42), // "on_pushButton_charging_confir..."
QT_MOC_LITERAL(143, 3989, 34), // "on_pushButton_ChargingSave_cl..."
QT_MOC_LITERAL(144, 4024, 43), // "on_pushButton_keyboard_chr_pa..."
QT_MOC_LITERAL(145, 4068, 31), // "on_pushButton_chr_Login_clicked"
QT_MOC_LITERAL(146, 4100, 37), // "on_pushButton_chr_CancelLogin..."
QT_MOC_LITERAL(147, 4138, 34), // "on_pushButton_BackAdminPsw_cl..."
QT_MOC_LITERAL(148, 4173, 37), // "on_pushButton_BackChargingPsw..."
QT_MOC_LITERAL(149, 4211, 29), // "on_pushButton_SN_Back_clicked"
QT_MOC_LITERAL(150, 4241, 41), // "on_pushButton_Back_DuringChar..."
QT_MOC_LITERAL(151, 4283, 32), // "on_pushButton_Error_Back_clicked"
QT_MOC_LITERAL(152, 4316, 31), // "on_pushButton_RFID_Next_pressed"
QT_MOC_LITERAL(153, 4348, 34), // "on_pushButton_ChargeByPswd_cl..."
QT_MOC_LITERAL(154, 4383, 45), // "on_pushButton_keyboard_chr_pa..."
QT_MOC_LITERAL(155, 4429, 33), // "on_pushButton_chr_Login_8_cli..."
QT_MOC_LITERAL(156, 4463, 27), // "on_pushButton_CCS_2_clicked"
QT_MOC_LITERAL(157, 4491, 39), // "on_pushButton_chr_CancelLogin..."
QT_MOC_LITERAL(158, 4531, 43), // "on_pushButton_keyboard_TProte..."
QT_MOC_LITERAL(159, 4575, 41), // "on_pushButton_keyboard_Cutoff..."
QT_MOC_LITERAL(160, 4617, 34), // "on_pushButton_Load_Sharing_cl..."
QT_MOC_LITERAL(161, 4652, 29), // "on_pushButton_LS_Back_clicked"
QT_MOC_LITERAL(162, 4682, 31), // "on_pushButton_LS_update_clicked"
QT_MOC_LITERAL(163, 4714, 44) // "on_pushButton_keyboard_TouchI..."

    },
    "MainWindow\0sgnForceStop\0\0sgnCharger_Stop\0"
    "sgnCharging_End\0sgnCharger_TimeOUT\0"
    "sgnCharger_Start\0sgnBack\0signalPlcmod\0"
    "on_pushButton_EmergencyStopCCS_clicked\0"
    "CCSStart\0workFinished\0rResult\0"
    "CCS_relay_status\0ACGunStatus\0TimeRead\0"
    "Start_Charger\0nMode\0Remot_Start_Charger\0"
    "Stop_Charger\0Remot_Stop_Charger\0"
    "End_Charger\0LoadSharingStatus\0"
    "LoadSharingStatus_2\0End_Charger_2\0"
    "ForcedStop\0nGroup\0chargingSchemeSlot\0"
    "FirmwareUpdateStatus\0status\0OpenSerial\0"
    "StartRemoteApp\0TagId_Search\0"
    "UserPasswordSlot\0AdminSignInSlot\0"
    "EthernetSlot\0OcppSlot\0WifiSlot\0"
    "PriceSettingSlot\0SettingSlot\0"
    "DC_ProfileSlot\0Serial_number\0"
    "Firmware_Upgrade\0GSMSSlot\0DisplaySetting\0"
    "on_pushButton_3_clicked\0"
    "on_pushButton_CCS_clicked\0"
    "on_pushButton_CCSPayment_clicked\0"
    "on_pushButton_FinishCCS_clicked\0"
    "on_pushButton_Login_clicked\0"
    "on_pushButton_Signin_clicked\0"
    "on_pushButton_CancelLogin_clicked\0"
    "on_pushButton_SaveRegister_clicked\0"
    "on_pushButton_Return_OCPP_clicked\0"
    "on_pushButton_Confirmocpp_clicked\0"
    "on_pushButton_AdminIcon_clicked\0"
    "on_pushButton_AdminOCPP_clicked\0"
    "on_pushButton_AdminEthernet_clicked\0"
    "on_pushButton_AdminWifi_clicked\0"
    "on_pushButton_EthernetSetting_clicked\0"
    "on_pushButton_WifiSetting_clicked\0"
    "on_pushButton_Price_setting_clicked\0"
    "on_pushButton_getOutfromPriceSett_clicked\0"
    "on_pushButton_Setting_clicked\0"
    "on_pushButton_AdminSetting_clicked\0"
    "on_checkBox_clicked\0"
    "on_pushButton_ChargingParamAC_clicked\0"
    "on_pushButton_keyboard_password_clicked\0"
    "on_pushButton_Regi_password_clicked\0"
    "on_pushButton_Regi_confirmpass_clicked\0"
    "on_pushButton_Ether_Localip_clicked\0"
    "on_pushButton_Ether_Gatewayip_clicked\0"
    "on_pushButton_Ether_Subnet_clicked\0"
    "on_pushButton_Keyboard_serverURL_clicked\0"
    "on_pushButton_keyboard_serverPort_clicked\0"
    "on_pushButton_keyboard_SSID_clicked\0"
    "on_pushButton_keyboard_wifiPass_clicked\0"
    "on_pushButton_keyboard_PriceSett_clicked\0"
    "on_pushButton_keyboard_Setting_clicked\0"
    "on_pushButton_keyboard_OverVolt_clicked\0"
    "on_pushButton_keyboard_UnderVolt_clicked\0"
    "on_pushButton_keyboard_OverCurrCCS_clicked\0"
    "on_stackedWidget_currentChanged\0arg1\0"
    "on_pushButton_History_Page_clicked\0"
    "on_pushButton_keyboard_Max_V_clicked\0"
    "on_pushButton_keyboard_Min_V_clicked\0"
    "on_pushButton_keyboard_Max_I_clicked\0"
    "on_pushButton_keyboard_Min_P_clicked\0"
    "on_pushButton_Admin4G_clicked\0"
    "on_pushButton_AdminDcProfile_clicked\0"
    "on_IPv4v6_radioButton_clicked\0"
    "on_IPv6_radioButton_clicked\0"
    "on_IPv4_radioButton_clicked\0"
    "on_pushButton_keyboard_APN_clicked\0"
    "on_pushButton_keyboard_Min_I_clicked\0"
    "on_pushButton_keyboard_Max_P_clicked\0"
    "on_pushButton_Save_charging_clicked\0"
    "on_pushButton_Keyboard_chargebytime_clicked\0"
    "on_pushButton_Keyboard_charggebyunit_clicked\0"
    "on_pushButton_Profile_Save_clicked\0"
    "on_pushButton_Profile_Back_clicked\0"
    "on_pushButton_Save_gsm_clicked\0"
    "on_pushButton_Cancel_gsm_clicked\0"
    "on_pushButton_WifiSetting_back_clicked\0"
    "on_pushButton_Setting_Back_clicked\0"
    "on_pushButton_PriceSetting_back_clicked\0"
    "on_WIFIEnable_clicked\0checked\0"
    "on_EthernetEnable_clicked\0"
    "on_GSMEnable_clicked\0on_OCPPEnable_clicked\0"
    "on_pushbutton_history_back_clicked\0"
    "on_pushButton_Serial_Number_clicked\0"
    "on_pushButton_keyboard_Serial_Number_clicked\0"
    "on_pushButton_Back_charging_clicked\0"
    "on_pushButton_FW_clicked\0"
    "on_pushButton_keyboard_FW_servername_clicked\0"
    "on_pushButton_keyboard_FW_path_clicked\0"
    "on_pushButton_keyboard_FW_password_clicked\0"
    "on_pushButton_keyboard_FW_username_clicked\0"
    "on_pushButton_Serial_Save_clicked\0"
    "on_pushButton_FW_Update_clicked\0"
    "on_pushbutton_history_clear_clicked\0"
    "on_pushbutton_history_up_clicked\0"
    "on_pushbutton_history_down_clicked\0"
    "on_pushButton_EthernetSetting_Back_clicked\0"
    "on_pushButton_FW_Back_clicked\0"
    "on_pushButton_KeyBord_TimeDate_clicked\0"
    "on_pushButton_Back_Display_setting_clicked\0"
    "on_pushButton_Save_Displaysetting_clicked\0"
    "on_pushButton_KeyBord_Timezone_clicked\0"
    "on_pushButton_KeyBord_sleeptime_clicked\0"
    "on_pushButton_Display_setting_clicked\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_pushButton_Charging_psw_clicked\0"
    "on_pushButton_Psw_Back_clicked\0"
    "on_pushButton_Password_clicked\0"
    "on_pushButton_Network_clicked\0"
    "on_pushButton_Nework_back_clicked\0"
    "on_pushButton_Chrg_password_clicked\0"
    "on_pushButton_charging_confirmpass_clicked\0"
    "on_pushButton_ChargingSave_clicked\0"
    "on_pushButton_keyboard_chr_password_clicked\0"
    "on_pushButton_chr_Login_clicked\0"
    "on_pushButton_chr_CancelLogin_clicked\0"
    "on_pushButton_BackAdminPsw_clicked\0"
    "on_pushButton_BackChargingPsw_clicked\0"
    "on_pushButton_SN_Back_clicked\0"
    "on_pushButton_Back_DuringCharging_clicked\0"
    "on_pushButton_Error_Back_clicked\0"
    "on_pushButton_RFID_Next_pressed\0"
    "on_pushButton_ChargeByPswd_clicked\0"
    "on_pushButton_keyboard_chr_password_8_clicked\0"
    "on_pushButton_chr_Login_8_clicked\0"
    "on_pushButton_CCS_2_clicked\0"
    "on_pushButton_chr_CancelLogin_8_clicked\0"
    "on_pushButton_keyboard_TProtection_released\0"
    "on_pushButton_keyboard_CutoffSoc_released\0"
    "on_pushButton_Load_Sharing_clicked\0"
    "on_pushButton_LS_Back_clicked\0"
    "on_pushButton_LS_update_clicked\0"
    "on_pushButton_keyboard_TouchInterval_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     155,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  789,    2, 0x06 /* Public */,
       3,    1,  792,    2, 0x06 /* Public */,
       4,    1,  795,    2, 0x06 /* Public */,
       5,    1,  798,    2, 0x06 /* Public */,
       6,    1,  801,    2, 0x06 /* Public */,
       7,    1,  804,    2, 0x06 /* Public */,
       8,    1,  807,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  810,    2, 0x0a /* Public */,
      10,    0,  811,    2, 0x0a /* Public */,
      11,    1,  812,    2, 0x08 /* Private */,
      13,    1,  815,    2, 0x08 /* Private */,
      14,    1,  818,    2, 0x08 /* Private */,
      15,    0,  821,    2, 0x08 /* Private */,
      16,    1,  822,    2, 0x08 /* Private */,
      18,    1,  825,    2, 0x08 /* Private */,
      19,    1,  828,    2, 0x08 /* Private */,
      20,    1,  831,    2, 0x08 /* Private */,
      21,    0,  834,    2, 0x08 /* Private */,
      22,    0,  835,    2, 0x08 /* Private */,
      23,    0,  836,    2, 0x08 /* Private */,
      24,    0,  837,    2, 0x08 /* Private */,
      25,    1,  838,    2, 0x08 /* Private */,
      27,    1,  841,    2, 0x08 /* Private */,
      28,    1,  844,    2, 0x08 /* Private */,
      30,    0,  847,    2, 0x08 /* Private */,
      31,    0,  848,    2, 0x08 /* Private */,
      32,    1,  849,    2, 0x08 /* Private */,
      33,    1,  852,    2, 0x08 /* Private */,
      34,    1,  855,    2, 0x08 /* Private */,
      35,    1,  858,    2, 0x08 /* Private */,
      36,    1,  861,    2, 0x08 /* Private */,
      37,    1,  864,    2, 0x08 /* Private */,
      38,    1,  867,    2, 0x08 /* Private */,
      39,    1,  870,    2, 0x08 /* Private */,
      40,    1,  873,    2, 0x08 /* Private */,
      41,    1,  876,    2, 0x08 /* Private */,
      42,    1,  879,    2, 0x08 /* Private */,
      43,    1,  882,    2, 0x08 /* Private */,
      44,    1,  885,    2, 0x08 /* Private */,
      45,    0,  888,    2, 0x08 /* Private */,
      46,    0,  889,    2, 0x08 /* Private */,
      47,    0,  890,    2, 0x08 /* Private */,
      48,    0,  891,    2, 0x08 /* Private */,
      49,    0,  892,    2, 0x08 /* Private */,
      50,    0,  893,    2, 0x08 /* Private */,
      51,    0,  894,    2, 0x08 /* Private */,
      52,    0,  895,    2, 0x08 /* Private */,
      53,    0,  896,    2, 0x08 /* Private */,
      54,    0,  897,    2, 0x08 /* Private */,
      55,    0,  898,    2, 0x08 /* Private */,
      56,    0,  899,    2, 0x08 /* Private */,
      57,    0,  900,    2, 0x08 /* Private */,
      58,    0,  901,    2, 0x08 /* Private */,
      59,    0,  902,    2, 0x08 /* Private */,
      60,    0,  903,    2, 0x08 /* Private */,
      61,    0,  904,    2, 0x08 /* Private */,
      62,    0,  905,    2, 0x08 /* Private */,
      63,    0,  906,    2, 0x08 /* Private */,
      64,    0,  907,    2, 0x08 /* Private */,
      65,    0,  908,    2, 0x08 /* Private */,
      66,    0,  909,    2, 0x08 /* Private */,
      67,    0,  910,    2, 0x08 /* Private */,
      68,    0,  911,    2, 0x08 /* Private */,
      69,    0,  912,    2, 0x08 /* Private */,
      70,    0,  913,    2, 0x08 /* Private */,
      71,    0,  914,    2, 0x08 /* Private */,
      72,    0,  915,    2, 0x08 /* Private */,
      73,    0,  916,    2, 0x08 /* Private */,
      74,    0,  917,    2, 0x08 /* Private */,
      75,    0,  918,    2, 0x08 /* Private */,
      76,    0,  919,    2, 0x08 /* Private */,
      77,    0,  920,    2, 0x08 /* Private */,
      78,    0,  921,    2, 0x08 /* Private */,
      79,    0,  922,    2, 0x08 /* Private */,
      80,    0,  923,    2, 0x08 /* Private */,
      81,    0,  924,    2, 0x08 /* Private */,
      82,    1,  925,    2, 0x08 /* Private */,
      84,    0,  928,    2, 0x08 /* Private */,
      85,    0,  929,    2, 0x08 /* Private */,
      86,    0,  930,    2, 0x08 /* Private */,
      87,    0,  931,    2, 0x08 /* Private */,
      88,    0,  932,    2, 0x08 /* Private */,
      89,    0,  933,    2, 0x08 /* Private */,
      90,    0,  934,    2, 0x08 /* Private */,
      91,    0,  935,    2, 0x08 /* Private */,
      92,    0,  936,    2, 0x08 /* Private */,
      93,    0,  937,    2, 0x08 /* Private */,
      94,    0,  938,    2, 0x08 /* Private */,
      95,    0,  939,    2, 0x08 /* Private */,
      96,    0,  940,    2, 0x08 /* Private */,
      97,    0,  941,    2, 0x08 /* Private */,
      98,    0,  942,    2, 0x08 /* Private */,
      99,    0,  943,    2, 0x08 /* Private */,
     100,    0,  944,    2, 0x08 /* Private */,
     101,    0,  945,    2, 0x08 /* Private */,
     102,    0,  946,    2, 0x08 /* Private */,
     103,    0,  947,    2, 0x08 /* Private */,
     104,    0,  948,    2, 0x08 /* Private */,
     105,    0,  949,    2, 0x08 /* Private */,
     106,    0,  950,    2, 0x08 /* Private */,
     107,    1,  951,    2, 0x08 /* Private */,
     109,    1,  954,    2, 0x08 /* Private */,
     110,    1,  957,    2, 0x08 /* Private */,
     111,    1,  960,    2, 0x08 /* Private */,
     112,    0,  963,    2, 0x08 /* Private */,
     113,    0,  964,    2, 0x08 /* Private */,
     114,    0,  965,    2, 0x08 /* Private */,
     115,    0,  966,    2, 0x08 /* Private */,
     116,    0,  967,    2, 0x08 /* Private */,
     117,    0,  968,    2, 0x08 /* Private */,
     118,    0,  969,    2, 0x08 /* Private */,
     119,    0,  970,    2, 0x08 /* Private */,
     120,    0,  971,    2, 0x08 /* Private */,
     121,    0,  972,    2, 0x08 /* Private */,
     122,    0,  973,    2, 0x08 /* Private */,
     123,    0,  974,    2, 0x08 /* Private */,
     124,    0,  975,    2, 0x08 /* Private */,
     125,    0,  976,    2, 0x08 /* Private */,
     126,    0,  977,    2, 0x08 /* Private */,
     127,    0,  978,    2, 0x08 /* Private */,
     128,    0,  979,    2, 0x08 /* Private */,
     129,    0,  980,    2, 0x08 /* Private */,
     130,    0,  981,    2, 0x08 /* Private */,
     131,    0,  982,    2, 0x08 /* Private */,
     132,    0,  983,    2, 0x08 /* Private */,
     133,    0,  984,    2, 0x08 /* Private */,
     134,    1,  985,    2, 0x08 /* Private */,
     136,    0,  988,    2, 0x08 /* Private */,
     137,    0,  989,    2, 0x08 /* Private */,
     138,    0,  990,    2, 0x08 /* Private */,
     139,    0,  991,    2, 0x08 /* Private */,
     140,    0,  992,    2, 0x08 /* Private */,
     141,    0,  993,    2, 0x08 /* Private */,
     142,    0,  994,    2, 0x08 /* Private */,
     143,    0,  995,    2, 0x08 /* Private */,
     144,    0,  996,    2, 0x08 /* Private */,
     145,    0,  997,    2, 0x08 /* Private */,
     146,    0,  998,    2, 0x08 /* Private */,
     147,    0,  999,    2, 0x08 /* Private */,
     148,    0, 1000,    2, 0x08 /* Private */,
     149,    0, 1001,    2, 0x08 /* Private */,
     150,    0, 1002,    2, 0x08 /* Private */,
     151,    0, 1003,    2, 0x08 /* Private */,
     152,    0, 1004,    2, 0x08 /* Private */,
     153,    0, 1005,    2, 0x08 /* Private */,
     154,    0, 1006,    2, 0x08 /* Private */,
     155,    0, 1007,    2, 0x08 /* Private */,
     156,    0, 1008,    2, 0x08 /* Private */,
     157,    0, 1009,    2, 0x08 /* Private */,
     158,    0, 1010,    2, 0x08 /* Private */,
     159,    0, 1011,    2, 0x08 /* Private */,
     160,    0, 1012,    2, 0x08 /* Private */,
     161,    0, 1013,    2, 0x08 /* Private */,
     162,    0, 1014,    2, 0x08 /* Private */,
     163,    0, 1015,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   83,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  108,
    QMetaType::Void, QMetaType::Bool,  108,
    QMetaType::Void, QMetaType::Bool,  108,
    QMetaType::Void, QMetaType::Bool,  108,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  135,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sgnForceStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sgnCharger_Stop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sgnCharging_End((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sgnCharger_TimeOUT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sgnCharger_Start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sgnBack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signalPlcmod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_EmergencyStopCCS_clicked(); break;
        case 8: { bool _r = _t->CCSStart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->workFinished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->CCS_relay_status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->ACGunStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->TimeRead(); break;
        case 13: _t->Start_Charger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->Remot_Start_Charger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->Stop_Charger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->Remot_Stop_Charger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->End_Charger(); break;
        case 18: _t->LoadSharingStatus(); break;
        case 19: _t->LoadSharingStatus_2(); break;
        case 20: _t->End_Charger_2(); break;
        case 21: _t->ForcedStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->chargingSchemeSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->FirmwareUpdateStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->OpenSerial(); break;
        case 25: _t->StartRemoteApp(); break;
        case 26: _t->TagId_Search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->UserPasswordSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->AdminSignInSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->EthernetSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->OcppSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->WifiSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->PriceSettingSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->SettingSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->DC_ProfileSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->Serial_number((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->Firmware_Upgrade((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->GSMSSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: _t->DisplaySetting((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 39: _t->on_pushButton_3_clicked(); break;
        case 40: _t->on_pushButton_CCS_clicked(); break;
        case 41: _t->on_pushButton_CCSPayment_clicked(); break;
        case 42: _t->on_pushButton_FinishCCS_clicked(); break;
        case 43: _t->on_pushButton_Login_clicked(); break;
        case 44: _t->on_pushButton_Signin_clicked(); break;
        case 45: _t->on_pushButton_CancelLogin_clicked(); break;
        case 46: _t->on_pushButton_SaveRegister_clicked(); break;
        case 47: _t->on_pushButton_Return_OCPP_clicked(); break;
        case 48: _t->on_pushButton_Confirmocpp_clicked(); break;
        case 49: _t->on_pushButton_AdminIcon_clicked(); break;
        case 50: _t->on_pushButton_AdminOCPP_clicked(); break;
        case 51: _t->on_pushButton_AdminEthernet_clicked(); break;
        case 52: _t->on_pushButton_AdminWifi_clicked(); break;
        case 53: _t->on_pushButton_EthernetSetting_clicked(); break;
        case 54: _t->on_pushButton_WifiSetting_clicked(); break;
        case 55: _t->on_pushButton_Price_setting_clicked(); break;
        case 56: _t->on_pushButton_getOutfromPriceSett_clicked(); break;
        case 57: _t->on_pushButton_Setting_clicked(); break;
        case 58: _t->on_pushButton_AdminSetting_clicked(); break;
        case 59: _t->on_checkBox_clicked(); break;
        case 60: _t->on_pushButton_ChargingParamAC_clicked(); break;
        case 61: _t->on_pushButton_keyboard_password_clicked(); break;
        case 62: _t->on_pushButton_Regi_password_clicked(); break;
        case 63: _t->on_pushButton_Regi_confirmpass_clicked(); break;
        case 64: _t->on_pushButton_Ether_Localip_clicked(); break;
        case 65: _t->on_pushButton_Ether_Gatewayip_clicked(); break;
        case 66: _t->on_pushButton_Ether_Subnet_clicked(); break;
        case 67: _t->on_pushButton_Keyboard_serverURL_clicked(); break;
        case 68: _t->on_pushButton_keyboard_serverPort_clicked(); break;
        case 69: _t->on_pushButton_keyboard_SSID_clicked(); break;
        case 70: _t->on_pushButton_keyboard_wifiPass_clicked(); break;
        case 71: _t->on_pushButton_keyboard_PriceSett_clicked(); break;
        case 72: _t->on_pushButton_keyboard_Setting_clicked(); break;
        case 73: _t->on_pushButton_keyboard_OverVolt_clicked(); break;
        case 74: _t->on_pushButton_keyboard_UnderVolt_clicked(); break;
        case 75: _t->on_pushButton_keyboard_OverCurrCCS_clicked(); break;
        case 76: _t->on_stackedWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->on_pushButton_History_Page_clicked(); break;
        case 78: _t->on_pushButton_keyboard_Max_V_clicked(); break;
        case 79: _t->on_pushButton_keyboard_Min_V_clicked(); break;
        case 80: _t->on_pushButton_keyboard_Max_I_clicked(); break;
        case 81: _t->on_pushButton_keyboard_Min_P_clicked(); break;
        case 82: _t->on_pushButton_Admin4G_clicked(); break;
        case 83: _t->on_pushButton_AdminDcProfile_clicked(); break;
        case 84: _t->on_IPv4v6_radioButton_clicked(); break;
        case 85: _t->on_IPv6_radioButton_clicked(); break;
        case 86: _t->on_IPv4_radioButton_clicked(); break;
        case 87: _t->on_pushButton_keyboard_APN_clicked(); break;
        case 88: _t->on_pushButton_keyboard_Min_I_clicked(); break;
        case 89: _t->on_pushButton_keyboard_Max_P_clicked(); break;
        case 90: _t->on_pushButton_Save_charging_clicked(); break;
        case 91: _t->on_pushButton_Keyboard_chargebytime_clicked(); break;
        case 92: _t->on_pushButton_Keyboard_charggebyunit_clicked(); break;
        case 93: _t->on_pushButton_Profile_Save_clicked(); break;
        case 94: _t->on_pushButton_Profile_Back_clicked(); break;
        case 95: _t->on_pushButton_Save_gsm_clicked(); break;
        case 96: _t->on_pushButton_Cancel_gsm_clicked(); break;
        case 97: _t->on_pushButton_WifiSetting_back_clicked(); break;
        case 98: _t->on_pushButton_Setting_Back_clicked(); break;
        case 99: _t->on_pushButton_PriceSetting_back_clicked(); break;
        case 100: _t->on_WIFIEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 101: _t->on_EthernetEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 102: _t->on_GSMEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 103: _t->on_OCPPEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 104: _t->on_pushbutton_history_back_clicked(); break;
        case 105: _t->on_pushButton_Serial_Number_clicked(); break;
        case 106: _t->on_pushButton_keyboard_Serial_Number_clicked(); break;
        case 107: _t->on_pushButton_Back_charging_clicked(); break;
        case 108: _t->on_pushButton_FW_clicked(); break;
        case 109: _t->on_pushButton_keyboard_FW_servername_clicked(); break;
        case 110: _t->on_pushButton_keyboard_FW_path_clicked(); break;
        case 111: _t->on_pushButton_keyboard_FW_password_clicked(); break;
        case 112: _t->on_pushButton_keyboard_FW_username_clicked(); break;
        case 113: _t->on_pushButton_Serial_Save_clicked(); break;
        case 114: _t->on_pushButton_FW_Update_clicked(); break;
        case 115: _t->on_pushbutton_history_clear_clicked(); break;
        case 116: _t->on_pushbutton_history_up_clicked(); break;
        case 117: _t->on_pushbutton_history_down_clicked(); break;
        case 118: _t->on_pushButton_EthernetSetting_Back_clicked(); break;
        case 119: _t->on_pushButton_FW_Back_clicked(); break;
        case 120: _t->on_pushButton_KeyBord_TimeDate_clicked(); break;
        case 121: _t->on_pushButton_Back_Display_setting_clicked(); break;
        case 122: _t->on_pushButton_Save_Displaysetting_clicked(); break;
        case 123: _t->on_pushButton_KeyBord_Timezone_clicked(); break;
        case 124: _t->on_pushButton_KeyBord_sleeptime_clicked(); break;
        case 125: _t->on_pushButton_Display_setting_clicked(); break;
        case 126: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 127: _t->on_pushButton_Charging_psw_clicked(); break;
        case 128: _t->on_pushButton_Psw_Back_clicked(); break;
        case 129: _t->on_pushButton_Password_clicked(); break;
        case 130: _t->on_pushButton_Network_clicked(); break;
        case 131: _t->on_pushButton_Nework_back_clicked(); break;
        case 132: _t->on_pushButton_Chrg_password_clicked(); break;
        case 133: _t->on_pushButton_charging_confirmpass_clicked(); break;
        case 134: _t->on_pushButton_ChargingSave_clicked(); break;
        case 135: _t->on_pushButton_keyboard_chr_password_clicked(); break;
        case 136: _t->on_pushButton_chr_Login_clicked(); break;
        case 137: _t->on_pushButton_chr_CancelLogin_clicked(); break;
        case 138: _t->on_pushButton_BackAdminPsw_clicked(); break;
        case 139: _t->on_pushButton_BackChargingPsw_clicked(); break;
        case 140: _t->on_pushButton_SN_Back_clicked(); break;
        case 141: _t->on_pushButton_Back_DuringCharging_clicked(); break;
        case 142: _t->on_pushButton_Error_Back_clicked(); break;
        case 143: _t->on_pushButton_RFID_Next_pressed(); break;
        case 144: _t->on_pushButton_ChargeByPswd_clicked(); break;
        case 145: _t->on_pushButton_keyboard_chr_password_8_clicked(); break;
        case 146: _t->on_pushButton_chr_Login_8_clicked(); break;
        case 147: _t->on_pushButton_CCS_2_clicked(); break;
        case 148: _t->on_pushButton_chr_CancelLogin_8_clicked(); break;
        case 149: _t->on_pushButton_keyboard_TProtection_released(); break;
        case 150: _t->on_pushButton_keyboard_CutoffSoc_released(); break;
        case 151: _t->on_pushButton_Load_Sharing_clicked(); break;
        case 152: _t->on_pushButton_LS_Back_clicked(); break;
        case 153: _t->on_pushButton_LS_update_clicked(); break;
        case 154: _t->on_pushButton_keyboard_TouchInterval_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sgnForceStop)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sgnCharger_Stop)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sgnCharging_End)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sgnCharger_TimeOUT)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sgnCharger_Start)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sgnBack)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPlcmod)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 155)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 155;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 155)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 155;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sgnForceStop(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sgnCharger_Stop(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sgnCharging_End(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sgnCharger_TimeOUT(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sgnCharger_Start(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::sgnBack(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::signalPlcmod(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
