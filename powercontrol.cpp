#include "powercontrol.h"
#include <algorithm>
#include <QDebug>
#include "cstring"
#include "tty.h"
//#include "chargercontrol.h"

PowerControl* PowerControl::Powerins = nullptr;
bool PowerControl::instanceFlag = false;
QObject* PowerControl::pParent = nullptr;
PowerControl::PowerControl(QObject *parent, int MdlCount) : QObject(parent)
{

    MdlInfoTimer = GroupTimer = nullptr;
    serialPort = new QSerialPort;

    memset(g_fVoltage, 0, sizeof(float)*2);
    memset(g_fTotalCurrent, 0, sizeof(float)*2);
    memset(g_fPower, 0, sizeof(float)*2);

    g_MdlCount = MdlCount;
    for(int i =0; i< MdlCount; i++)
    {
        stPowerModuleInfo powerMdl;
        memset(&powerMdl, 0, sizeof(stPowerModuleInfo));
        powerMdl.MdlNum = i;
        PowerMdlData.append(powerMdl);
        Tempvect.append(0);
    }

    //nCountMax = std::numeric_limits<quint32>::max();
    MdlInfoTimer_Count = 1;
    GroupTimer_Count = 1;

    g_bCalPowerGP1 =  g_bCalPowerGP2 = false;

    //connect(this, SIGNAL(sgnRequestPowerMDLData(QCanBusFrame)), (ChargerControl*)(pParent), SLOT(RequestPowerMDLData(QCanBusFrame)));

    MdlInfoTimer = new QTimer(this);
    connect(MdlInfoTimer, SIGNAL(timeout()), this, SLOT(MdlInfoTimerEvent()));
    MdlInfoTimer->setInterval(200);
    //MdlInfoTimer->start();


    GroupTimer = new QTimer(this);
    connect(GroupTimer, SIGNAL(timeout()), this, SLOT(GroupVoltageCurrentInfoTimerEvent()));
    GroupTimer->setInterval(100);
    //GroupTimer->start();

    DcComboPLC_1_time = DcComboPLC_1_time_old = 0;
    DcComboPLC_2_time = DcComboPLC_2_time_old = 0;
    ElapsedTime.start();

}
PowerControl::~PowerControl()
{
    SAFE_DELETE(MdlInfoTimer)
    SAFE_DELETE(GroupTimer)
    SAFE_DELETE(serialPort)
    PowerMdlData.clear();
}

PowerControl* PowerControl::getPowerInstance(int MdlCount)
{
    if(!PowerControl::Powerins)
    {

        PowerControl::Powerins = new PowerControl(nullptr, MdlCount);
        instanceFlag = true;
    }
    return Powerins;
}
void PowerControl::PurgeInsatace()
{
    if(Powerins)
    {
        delete Powerins;
        Powerins = nullptr;
        instanceFlag = false;
    }
}


void PowerControl::poll_read_ready(){
    int ret =  tty_read_ready(tty_fd);
    if (ret == 1) {
        emit readReady();
    }
}


bool PowerControl::ConnectMdlCan(QString portName)
{
    if (tty_fd != -1) {
        return false;
    }
    const char* dev_name = portName.toLocal8Bit().data();

    tty_fd = tty_init(dev_name);

    if( tty_fd < 0) {
        qDebug() << "Initialize tty device failed! " << dev_name << "\n\r";
        exit(EXIT_FAILURE);
    }

    int ret = tty_setting(tty_fd, 921600, 8, TTY_RS485_MODE, 0, 'n', 1);
    if(ret < 0) {
        qDebug() << "setting tty device %s failed! " << dev_name << "\n\r";
        exit(EXIT_FAILURE);
    }

    setCanBaudRate(125);
    setBinaryMode();
    SaveConfig();

    QTimer *timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(poll_read_ready()));
    timer->start();
    connect(this, &PowerControl::readReady, this, &PowerControl::receiveCanData);
//    connect(serialPort, &QSerialPort::readyRead, this, &PowerControl::receiveCanData);


    MdlInfoTimer = new QTimer(this);
    connect(MdlInfoTimer, SIGNAL(timeout()), this, SLOT(MdlInfoTimerEvent()));
    MdlInfoTimer->setInterval(200);
    MdlInfoTimer->start();

    GroupTimer = new QTimer(this);
    connect(GroupTimer, SIGNAL(timeout()), this, SLOT(GroupVoltageCurrentInfoTimerEvent()));
    GroupTimer->setInterval(100);
    GroupTimer->start();
    return true;

}

void PowerControl::DisConnectMdlCan()
{
    MdlInfoTimer->stop();
    GroupTimer->stop();
//    serialPort->close();

}

void PowerControl::GroupVoltageCurrentInfoTimerEvent()
{
    //if(GroupTimer_Count == nCountMax)
    //    GroupTimer_Count = 1;
    //int nRemain = GroupTimer_Count % 2;
    Read_Power_Mdl_Output_Tatal_Voltage_Current(0);

    //GroupTimer_Count++;
}

void PowerControl::MdlInfoTimerEvent()
{

    //int nRemain = MdlInfoTimer_Count % g_MdlCount;

    Read_Power_Mdl_Each_Info((quint32)0);
    //Read_Power_Mdl_Each_VAB_VBC_VCA((quint32)nRemain);
    //Read_Power_Mdl_Output_Each_Voltage_Current((quint32)nRemain);

    //MdlInfoTimer_Count++;
}

void PowerControl::receiveCanData()
{

    static QByteArray rcvData;
    int length=0;
    int size = 0;
    char cFlags = 0;
    char crcCheck=0;

    char frame[TTY_READ_BUFFER_SIZE];
    QByteArray databuf;
    tty_read(tty_fd, frame);
    databuf = QByteArray(reinterpret_cast<char*>(frame), TTY_READ_BUFFER_SIZE);

    rcvData.append( databuf );

    while(rcvData.size() > 1)
    {
        size = rcvData.size();
        if (size > 1 && rcvData.at(0) == 0x02)
        {
            if (size >= 18) //&& rcvData.at(1) == 0x00)
            {
                length = 18;
                crcCheck = 0;
                for(int i=1; i < length-2; i++)
                   crcCheck += rcvData.at(i);

                if(rcvData.at(length-2) == crcCheck && rcvData.at(length-1) == 0x03 ) //crc and EOF check
                {
                    cFlags = rcvData.at(3);
                    if (cFlags == 0x00)
                        cFlags = 1;
                    else if(cFlags == 0x40)
                        cFlags = 3;

                    if(rcvData.at(1) == 0x00)
                        processReceiveCommands(cFlags, rcvData.mid(4,length-3));
                    else
                    {
                       //command reply....
                    }
                    rcvData.remove(0, length);
                }
                else
                    rcvData.remove(0, 1);

            }
            else
                break;
        }
        else
            rcvData.remove(0, 1);
    }

}

void PowerControl::processReceiveCommands(int cmd, QByteArray data)
{
    QCanBusFrame canFrame;
    int dlc = 8;
    quint32 nCan_id =0;

    switch(cmd)
    {
        case 0: //11 bit ID CAN message received
        case 1: //11 bit CAN message received, message contains an additional 32 bit timestamp value.
            //dlc = data.size() - 2;
            //if(cmd == 1)
            //{
                //dlc -= 4;
                //canFrame.setTimeStamp(QCanBusFrame::TimeStamp::
                //                      fromMicroSeconds(fourByteToUint32(data.right(4).constData())));
            //}
            canFrame.setExtendedFrameFormat(false);
            canFrame.setFrameType(QCanBusFrame::DataFrame);
            nCan_id = (data.at(0) & 0x00ff)  | ((data.at(1)<< 8) & 0xff00 );
            canFrame.setFrameId(nCan_id);
            canFrame.setPayload(data.mid(4,dlc));
            readCanData(canFrame);


        break;

        case 2: //29 bit ID CAN message received
        case 3: //29 bit CAN message received, message contains an additional 32 bit timestamp value.
            //dlc = data.size() - 4;
            //if(cmd == 3)
               // dlc -= 4;

            canFrame.setExtendedFrameFormat(true);
            canFrame.setFrameType(QCanBusFrame::DataFrame);
            nCan_id = fourByteToUint32(data.left(4).constData());
            canFrame.setFrameId(nCan_id);
            canFrame.setPayload(data.mid(4, dlc));
            readCanData(canFrame);
        break;
    }
}
void PowerControl::receive_CanData(uint CanId, QByteArray aData)
{
    quint32 nFrame_id = CanId;
    stIdentifier* pIdentity = new stIdentifier(nFrame_id);
    DecodingCanData(pIdentity, aData);
    SAFE_DELETE(pIdentity)
}

void PowerControl::startmdlinfo()
{
    MdlInfoTimer = new QTimer(this);
    connect(MdlInfoTimer, SIGNAL(timeout()), this, SLOT(MdlInfoTimerEvent()));
    MdlInfoTimer->setInterval(1000);
    MdlInfoTimer->start();

}

void PowerControl::StartTimer(bool bStart)
{
    if(bStart)
    {
        MdlInfoTimer->start();
        GroupTimer->start();
    }else
    {
        MdlInfoTimer->stop();
        GroupTimer->stop();
    }

}

void PowerControl::readCanData(QCanBusFrame CanFrame)
{
    if(CanFrame.isValid())
    {
        quint32 nFrame_id = CanFrame.frameId();
        stIdentifier* pIdentity = new stIdentifier(nFrame_id);
        DecodingCanData(pIdentity, CanFrame.payload());
        SAFE_DELETE(pIdentity)
    }

}

void PowerControl::readPowerMDl_Data(QCanBusFrame CanFrame)
{
    if(CanFrame.isValid())
    {
        quint32 nFrame_id = CanFrame.frameId();
        stIdentifier* pIdentity = new stIdentifier(nFrame_id);
        DecodingCanData(pIdentity, CanFrame.payload());
        SAFE_DELETE(pIdentity)
    }

}

void PowerControl::DecodingCanData(stIdentifier* piDentity, QByteArray aData)
{
    quint8 nSourceAddress = piDentity->can_SourceAddress;
    switch(piDentity->Cmd_No)
    {
        case 0x01:
            if(nSourceAddress < 2 )
            {
                //qDebug() << ElapsedTime.elapsed() << "ms";
                g_fVoltage[nSourceAddress]       = fourByteToFloat(aData.left(4));
                g_fTotalCurrent[nSourceAddress]  = fourByteToFloat(aData.right(4));
                if(nSourceAddress ==0)
                {
                    if(g_bCalPowerGP1)
                    {
                        if(DcComboPLC_1_time_old>0)
                        {
                            DcComboPLC_1_time = ElapsedTime.elapsed() - DcComboPLC_1_time_old;
                            //g_fPower[0] = g_fPower[0] + (g_fVoltage[0] * g_fTotalCurrent[0] * 0.1 / 3600);
                            if(DcComboPLC_1_time > 0)
                                g_fPower[0] = g_fPower[0] + ((g_fVoltage[0] * g_fTotalCurrent[0] * (DcComboPLC_1_time /1000.0) / 3600)*1.1);
                        }
                        DcComboPLC_1_time_old = ElapsedTime.elapsed();
                        //qDebug() << "P0 " << DcComboPLC_1_time;

                    }


                }else if(nSourceAddress == 1)
                {
                    if(g_bCalPowerGP2)
                    {
                        if(DcComboPLC_2_time_old > 0)
                        {
                            DcComboPLC_2_time = ElapsedTime.elapsed() - DcComboPLC_2_time_old;
                            if(DcComboPLC_2_time > 0)
                                g_fPower[1] = g_fPower[1] + ((g_fVoltage[1] * g_fTotalCurrent[1] * (DcComboPLC_2_time /1000.0) / 3600)*1.1);
                        }
                    }
                    DcComboPLC_2_time_old = ElapsedTime.elapsed();

                    //qDebug() << "P1 " << DcComboPLC_2_time;

                }


            }

            break;
        case 0x02:
            if(nSourceAddress < 2)
            {
                g_GroupLiveCount[nSourceAddress] = aData.at(2);
            }
            break;

        case 0x03:
            if(nSourceAddress< g_MdlCount)
            {
                int nModuleIndex = piDentity->can_SourceAddress;

                PowerMdlData[nModuleIndex].fVoltage = fourByteToFloat(aData.left(4));
                PowerMdlData[nModuleIndex].fCurrent = fourByteToFloat(aData.right(4));
            }

            break;
        case 0x04:
            if(nSourceAddress<g_MdlCount)
            {
                int nModuleIndex = piDentity->can_SourceAddress;
                PowerMdlData[nModuleIndex].GroupNum = aData.at(2);
                PowerMdlData[nModuleIndex].temperature =  Tempvect[nModuleIndex] = aData.at(4);
                SetPowerMdlState2(&PowerMdlData[nModuleIndex].state_Info2, aData.at(5));  //mdl state 2
                SetPowerMdlState1(&PowerMdlData[nModuleIndex].state_Info1, aData.at(6));  //mdl state 1
                PowerMdlData[nModuleIndex].OutputShort = aData.at(7) & 0x01; //mdl state 0
            }
            break;

        case 0x06:
            if(nSourceAddress< g_MdlCount)
            {
                int nModuleIndex = piDentity->can_SourceAddress;
                PowerMdlData[nModuleIndex].VAB = (quint16)(((aData.at(0)<<8) & 0xff00) | (aData.at(1) & 0XFF)) * 0.1;
                PowerMdlData[nModuleIndex].VBC = (quint16)(((aData.at(2)<<8) & 0xff00) | (aData.at(3) & 0XFF)) * 0.1;
                PowerMdlData[nModuleIndex].VCA = (quint16)(((aData.at(4)<<8) & 0xff00) | (aData.at(5) & 0XFF)) * 0.1;

            }
            break;

    }

}

void PowerControl::SetPowerMdlState1(stState_Info1* pState1, char cData)
{
    pState1->mdlOffState        = cData & 0x01;
    pState1->mdlFault           = (cData >> 1) & 0x01;
    pState1->mdlProtect         = (cData >> 2) & 0x01;
    pState1->FanFault           = (cData >> 3) & 0x01;
    pState1->OverTemperature    = (cData >> 4) & 0x01;
    pState1->OutputOverVoltage  = (cData >> 5) & 0x01;
    pState1->Walk_IN            = (cData >> 6) & 0x01;
    pState1->CommInterrupt      = (cData >> 7) & 0x01;
}

void PowerControl::SetPowerMdlState2(stState_Info2* pState2, char cData)
{
    pState2->PowerLimit         = cData & 0x01;
    pState2->mdlIDRepetition    = (cData >> 1) & 0x01;
    pState2->LoadUnsharing      = (cData >> 2) & 0x01;
    pState2->InputPhaseLost     = (cData >> 3) & 0x01;
    pState2->InputUnbalance     = (cData >> 4) & 0x01;
    pState2->InputUnderVoltage  = (cData >> 5) & 0x01;
    pState2->InputOverVoltage   = (cData >> 6) & 0x01;
    pState2->mdlPFCsideIsOff    = (cData >> 7) & 0x01;
}

void PowerControl::Read_Power_Mdl_Output_Tatal_Voltage_Current(quint32 aGroup)
{
    char data[8] = {0,};
    QByteArray aData;
    aData.append(data, 8);
    quint32 Can_id = getPowerModuleCan_ID(0x01, 0x0B, aGroup);
    CanWrite(Can_id, aData);

}

void PowerControl::Read_Power_Mdl_Count(quint32 aGroup)
{
    char data[8] = {0,};
    QByteArray aData;
    aData.append(data, 8);
    quint32 Can_id = getPowerModuleCan_ID(0x02, 0x0B, aGroup);
    CanWrite(Can_id, aData);

}

void PowerControl::Read_Power_Mdl_Output_Each_Voltage_Current(quint32 nMdlNum) //MdlNum = source Address
{
    char data[8] = {0,};
    QByteArray aData;
    aData.append(data, 8);
    quint32 Can_id = getPowerModuleCan_ID(0x03, 0x0A, nMdlNum);
    CanWrite(Can_id, aData);

}

void PowerControl::Read_Power_Mdl_Each_Info(quint32 nMdlNum) //MdlNum = source Address
{
    char data[8] = {0,};
    QByteArray aData;
    aData.append(data,8);
    quint32 Can_id = getPowerModuleCan_ID(0x04, 0x0A, nMdlNum);
    CanWrite(Can_id, aData);

}

void PowerControl::Read_Power_Mdl_Each_VAB_VBC_VCA(quint32 nMdlNum) //MdlNum = source Address
{
    char data[8] = {0,};
    QByteArray aData;
    aData.append(data,8);
    quint32 Can_id = getPowerModuleCan_ID(0x06, 0x0A, nMdlNum);
    CanWrite(Can_id, aData);
}

void PowerControl::Set_Power_Mdl_ALL_ON_OFF(quint32 aGroup, int nOn) // On : 0 Off : 1
{

}
void PowerControl::Set_Power_Mdl_Output_Tatal_Voltage_Current_brocast(quint32 nCurrent, quint32 nVoltage)
{
    QByteArray aData, aVol, aCur;


    aVol.append(reinterpret_cast<const char*>(&nVoltage), sizeof(quint32));
    std::reverse(aVol.begin(), aVol.end());

    aCur.append(reinterpret_cast<const char*>(&nCurrent), sizeof(quint32));
    std::reverse(aCur.begin(), aCur.end());

    aData.append(aVol).append(aCur);
    quint32 Can_id = getPowerModuleCan_ID(0x1B);
    CanWrite(Can_id, aData);
}

void PowerControl::Set_Power_Mdl_Output_Tatal_Voltage_Current(quint32 aGroup, quint32 nCurrent, quint32 nVoltage)
{

    //char data[8] = {0,};
    //data[0] =

    QByteArray aData, aVol, aCur;


    aVol.append(reinterpret_cast<const char*>(&nVoltage), sizeof(quint32));
    std::reverse(aVol.begin(), aVol.end());

    aCur.append(reinterpret_cast<const char*>(&nCurrent), sizeof(quint32));
    std::reverse(aCur.begin(), aCur.end());

    aData.append(aVol).append(aCur);
    quint32 Can_id = getPowerModuleCan_ID(0x1B, 0x0B, aGroup);
    CanWrite(Can_id, aData);




}

void PowerControl::Set_Power_Mdl_Output_Each_Voltage_Current(quint32 aGroup, quint32 nCurrent, quint32 nVoltage)
{
    QByteArray aData, aVol, aCur;

    aVol.append(reinterpret_cast<const char*>(&nVoltage), sizeof(quint32));
    std::reverse(aVol.begin(), aVol.end());

    aCur.append(reinterpret_cast<const char*>(&nCurrent), sizeof(quint32));
    std::reverse(aCur.begin(), aCur.end());

    aData.append(aVol).append(aCur);
    quint32 Can_id = getPowerModuleCan_ID(0x1C, 0x0B, aGroup);
    CanWrite(Can_id, aData);
}

void PowerControl::CanWrite(quint32 Can_id, QByteArray aData)
{
    QCanBusFrame    canFrame;
    //QByteArray      SendData;
    //quint8          nChecksum = 0;

    canFrame.setFrameId(Can_id);
    canFrame.setPayload(aData);
    canFrame.setExtendedFrameFormat(true);

    emit sgnRequestPowerMDLData(canFrame);

    /*
    MsgPacket* pMsgPacket = new MsgPacket(canFrame.frameId(), canFrame.payload());
    SendData.append((char*)pMsgPacket, sizeof(MsgPacket));
    nChecksum = getChecksum(SendData);
    SendData.prepend(STX).append(nChecksum).append(ETX);

    if(serialPort->isOpen())
    {
        serialPort->write(SendData);
    }
    SAFE_DELETE(pMsgPacket);
    */
}
quint32 PowerControl::getPowerModuleCan_ID(quint32 nCommand, quint32 nDevice_No, quint32 DestAddr , quint32 sourceAddr)
{
    quint32 nCan_ID = 0;
    nCan_ID = nCan_ID | (nDevice_No <<22) |(nCommand << 16) | (DestAddr << 8) | sourceAddr;
    return nCan_ID;
}
quint8 PowerControl::getChecksum(QByteArray aData)
{
    quint8 checkusm = 0;
    //accumulate : QByteArray value sum
    return std::accumulate(aData.begin(), aData.end(), checkusm);
}

void PowerControl::Set_Power_Calculate_GP(int nGroup, bool bCal)
{
    if(nGroup == 0)
        g_bCalPowerGP1 = bCal;
    else
        g_bCalPowerGP2 = bCal;

    if(!bCal)
    {
       g_fPower[nGroup] = 0;
    }

}
void PowerControl::Set_Power_Calculate_GP1(bool bCal)
{
    g_bCalPowerGP1 = bCal;
    if(!bCal)
    {
       g_fPower[0] = 0;
    }
}

void PowerControl::Set_Power_Calculate_GP2(bool bCal)
{
    g_bCalPowerGP2 = bCal;
    if(!bCal)
    {
       g_fPower[1] = 0;
    }
}
void PowerControl::Reset_Power_GP(int nGroup)
{
    g_fPower[nGroup] = 0;
}

void PowerControl::Reset_Power_GP1()
{
    g_fPower[0] = 0;
}

void PowerControl::Reset_Power_GP2()
{
    g_fPower[1] = 0;
}

stPowerModuleInfo PowerControl::getEachModuleInfo(int MdlNum)
{
    return PowerMdlData[MdlNum];
}
float PowerControl::getGroupVoltage(int GroupNum)
{
    return g_fVoltage[GroupNum];
}

float PowerControl::getGroupCurrent(int GroupNum)
{
    return g_fTotalCurrent[GroupNum];
}

float PowerControl::getTotalCurrent()
{
    return  g_fTotalCurrent[0] + g_fTotalCurrent[1];
}
float PowerControl::getTotalPower()
{
    return g_fPower[0] + g_fPower[1];
}

int PowerControl::getGroupLiveCount(int GroupNum)
{
    return g_GroupLiveCount[GroupNum];
}
float PowerControl::getGroupPower(int GroupNum)
{
    return g_fPower[GroupNum];
}

void PowerControl::SaveConfig()
{
    cmdPacket* pCmd = new cmdPacket(0x88, 0x0A, 0);
    QByteArray aData;
    quint8 CheckSum = 0;
    aData.append((char*)pCmd, sizeof(cmdPacket));
    CheckSum = getChecksum(aData);
    aData.prepend(STX).append(CheckSum).append(ETX);
    const std::size_t count = aData.size();
    unsigned char* hex =new unsigned char[count];
    std::memcpy(hex,aData.constData(),count);
    if (tty_fd >= 0) {
        tty_write(tty_fd, (char*)hex, (int)count);
    }
    SAFE_DELETE(pCmd);
    return;
    if(serialPort->isOpen())
        serialPort->write(aData);
}

int PowerControl::getMaxTemp()
{
    return *std::max_element(Tempvect.constBegin(), Tempvect.constEnd());
}


void PowerControl::setBinaryMode()
{
    cmdPacket* pCmd = new cmdPacket(0x88, 0x05, 1);
    QByteArray aData;
    quint8 CheckSum = 0;
    aData.append((char*)pCmd, sizeof(cmdPacket));
    CheckSum = getChecksum(aData);
    aData.prepend(STX).append(CheckSum).append(ETX);

    const std::size_t count = aData.size();
    unsigned char* hex =new unsigned char[count];
    std::memcpy(hex,aData.constData(),count);
    if (tty_fd >= 0) {
        tty_write(tty_fd, (char*) hex, (int)count);
    }
    SAFE_DELETE(pCmd)
    return;

    if(serialPort->isOpen())
        serialPort->write(aData);

}

void PowerControl::setCanBaudRate(uint nBaudRate)
{
    cmdPacket* pCmd = new cmdPacket(0x88, 0x03, nBaudRate);
    QByteArray aData;
    quint8 CheckSum = 0;
    aData.append((char*)pCmd, sizeof(cmdPacket));
    CheckSum = getChecksum(aData);
    //append((char*)&crc16, sizeof(ushort))
    aData.prepend(STX).append(CheckSum).append(ETX);

    const std::size_t count = aData.size();
    unsigned char* hex =new unsigned char[count];
    std::memcpy(hex,aData.constData(),count);
    if (tty_fd >= 0) {
        tty_write(tty_fd, (char*)hex, count);
    }
    return;
    if(serialPort->isOpen())
        serialPort->write(aData);
}
