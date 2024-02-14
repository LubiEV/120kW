#include "cantoserialctrl.h"
#include <qdebug.h>
#include <QSerialPortInfo>
#include <QMessageBox>

void CanToSerialCtrl::initCrc8()
{
	const uint polynomial = 0x04C11DB7;
	int i;
	int j;
	unsigned int crc;

	for (i = 0; i < 256; i++) {
        crc = static_cast<quint32>(i << 24);
		for (j = 0; j < 8; j++) {
			if (crc & 0x80000000)
			{
				crc = (crc << 1) ^ polynomial;
			}
			else
			{
				crc <<= 1;
			}
			//crc = (crc >> 1) ^ ((crc & 1) ? 0x4c11db7 : 0);
		}
		crc8_table[i] = crc ;
    }
}

quint32 CanToSerialCtrl::cal_Crc8(const char* buff)
{
    quint32  crc = 0x00;
    uint8_t crctemp = 0;
    //QString s;
    for (int i = 0; i < 15; i++)
    {
        crctemp = crc ^ (*buff++);
        //crc = crcTable[(crc)^(*buff++)];
        crc = crcTable[crctemp];

    }
    return crc;
}

unsigned int CanToSerialCtrl::calCrc8(const char* buff)
{
	quint32 crc = 0xffffffff;

	for (int i = 0; i < 15; i++)
	{
		crc = crc8_table[((crc >> 24) ^ *buff++) & 0xff] ^ (crc << 8) ;
	}
	return crc;
}

CanToSerialCtrl::CanToSerialCtrl(QObject *parent, int CAN_channel_Count) : QObject(parent)
{
    //initCrc8();
    OUT_DIO = IN_DIO = IN_MAIN_SW = 0;
    m_ReconnectCount = 0;

	serialPort = new QSerialPort;

	connect(serialPort, &QSerialPort::errorOccurred, this, &CanToSerialCtrl::onErrorOccurred);

//    for (int i = 0; i < MAX_CHANNEL; i++)
//    {
//        canData[i] = new QVector<QCanBusFrame>;
//    }

    m_Channel_MaxCount = CAN_channel_Count;
    for(int j = 0; j<m_Channel_MaxCount; j++)
    {
        CanFrameList.append(new QVector<canDataPackType>);
    }

    //QVector<QCanBusFrame> *CanFrame = CanFrameList.at(0);
}

CanToSerialCtrl::~CanToSerialCtrl()
{
    if (serialPort->isOpen())
        serialPort->close();

    delete serialPort;

    while (!CanFrameList.isEmpty())
        delete CanFrameList.takeFirst();

}
bool CanToSerialCtrl::isListenOnlyMode()
{
	return canListenOnlyMode;
}
CanBaudRate CanToSerialCtrl::getCanBaudRate()
{
	return baudRate;
}
bool CanToSerialCtrl::connectDevice(QString portName)
{
    
	if (portName == "")	// Auto Port Scan
	{
		const auto infos = QSerialPortInfo::availablePorts();
		for (const QSerialPortInfo& info : infos)
		{
			QString s = QObject::tr("Port: ") + info.portName() + "\n"
				+ QObject::tr("Location: ") + info.systemLocation() + "\n"
				+ QObject::tr("Description: ") + info.description() + "\n"
				+ QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
				+ QObject::tr("Serial number: ") + info.serialNumber() + "\n"
				+ QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
				+ QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
				+ QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
			qDebug() << s;
			if (info.vendorIdentifier() == 0x483 && info.productIdentifier() == 0x5740)
				serialPort->setPortName(info.portName());
		}
	}
	else
		serialPort->setPortName(portName);

    serialPort->setBaudRate(921600);
    //serialPort->setBaudRate(115200);
    serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
	serialPort->setReadBufferSize(4096);

    if (!serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << QObject::tr("Failed to open port %1, error: %2")
            .arg(serialPort->portName())
            .arg(serialPort->errorString())
            << endl;
        return false;
    }
    connect(serialPort, &QSerialPort::errorOccurred, this, &CanToSerialCtrl::onErrorOccurred);

    return true;
}
void CanToSerialCtrl::disconnectDevice()
{
    if (serialPort->isOpen())
    {
        serialPort->close();
        disconnect(serialPort, &QSerialPort::readyRead, this, &CanToSerialCtrl::receiveCmd);
        disconnect(serialPort, &QSerialPort::errorOccurred, this, &CanToSerialCtrl::onErrorOccurred);
    }
}
int CanToSerialCtrl::readFrame(QVector<canDataPackType> &rcvFrame, int channel)
{
	if (channel >= m_Channel_MaxCount)
		return -1;

	if (!CanFrameList.at(channel)->isEmpty())
	{
		rcvFrame = *CanFrameList.at(channel);
		CanFrameList.at(channel)->clear();
		return rcvFrame.size();
	}   
    else
        return 0;
}

qint64 CanToSerialCtrl::framesAvailable(int channel) const
{
    return CanFrameList.at(channel)->count();
}

int CanToSerialCtrl::error() const
{
    return 0;
}

void CanToSerialCtrl::setSerialPortName(QString portName)
{
    serialPort->setPortName(portName);
}

int CanToSerialCtrl::setCanBaudRate(CanBaudRate baudrate, int channel)
{
    CanSendFrameType sendFrame = { };

	sendFrame.cmd = scBaudrateSet;
    sendFrame.para = baudrate;	//baudrate value
    sendFrame.channel = channel;
    
	
    return writeFrame(sendFrame, channel);
}

void CanToSerialCtrl::setListenOnlyMode(bool status, int channel)
{
    CanSendFrameType sendFrame{};

	sendFrame.cmd = scModeSet;
	sendFrame.para = (status)?1:0;	
	sendFrame.channel = channel;


	writeFrame(sendFrame, channel);
}

void CanToSerialCtrl::setFilter(int BankNo, quint32 id, quint32 maskId, int channel)
{
    CanSendFrameType sendFrame{};

	sendFrame.cmd = scRxFilterSet;
	sendFrame.para = BankNo;	//Filter Bank No
    quint32* dp = reinterpret_cast<quint32*>(sendFrame.data);
	*(dp++) = id;
	*dp = maskId;

	sendFrame.channel = channel;


	writeFrame(sendFrame, channel);
}

void CanToSerialCtrl::receiveCmd()
{
    
    //int length = 0;
    //int size = 0;
    int checkSum = 0;
	bool isValidDataRcv = false;
	static int timeStamp = 0;

	if (serialPort->bytesAvailable() < 16)
		return;
	
    const QByteArray rcvData = serialPort->readAll();


    int idx=0;
    int nCH = 0;

    CanRcvFrameType* rcvFrame= nullptr;


	while ( rcvData.size() > idx + 15)
    {
        checkSum =  cal_Crc8(rcvData.constData()+idx) & 0xff;
		
        
        //Start char  and length check
		if (checkSum == quint8(rcvData.at(15 + idx)))
		{
            QByteArray data;

            data.setRawData(rcvData.constData(),sizeof(CanRcvFrameType));
            rcvFrame = reinterpret_cast<CanRcvFrameType*>(data.data());

            //rcvFrame = (CanRcvFrameType*)(rcvData.constData() + idx);
            //quint32 id = rcvFrame->id;
			//rcvFrame->id = id << 24 | id >> 24 | ((id & 0xff00) << 8) | ((id & 0xff0000) >> 8);
			if (!rcvFrame->flagIde)
				rcvFrame->id &= 0x7ff;


			timeStamp += rcvFrame->timeStamp;
			if (timeStamp > 0xffffff)
				timeStamp -= 0xffffff;

			rcvFrame->timeStamp = timeStamp & 0xffff;
			rcvFrame->timeStampHigh = (timeStamp >> 16) & 0xff;

            canDataPackType CanDataPack;
            memset(&CanDataPack, 0, sizeof(canDataPackType));
            memcpy(&CanDataPack, rcvFrame, 4);
            memcpy(CanDataPack.data, rcvFrame->data, 8);
            memcpy(&CanDataPack.timeStamp, &rcvFrame->timeStamp, 4);

            if (rcvFrame->channel < m_Channel_MaxCount)
                CanFrameList.at(rcvFrame->channel)->append(CanDataPack);

			idx += 16;
            nCH = rcvFrame->channel;
			isValidDataRcv = true;
		}
		else
			idx++;
    }

	if(isValidDataRcv)
        emit framesReceived(nCH);
    // qDebug() << rcvData.toHex();
}

void CanToSerialCtrl::onErrorOccurred(QSerialPort::SerialPortError error)
{
    qDebug() << "CanSerialPort Error : " << error;

    if (error != QSerialPort::NoError)
    {
        ++m_ReconnectCount;
        disconnectDevice();

        if(m_ReconnectCount > 5)
        {
            QMessageBox::critical(nullptr, tr("Critical Error"), serialPort->errorString());
            return;
        }
        QTimer::singleShot(1000, this, SLOT(ReconnectDevice()));

    }else if(error == QSerialPort::NoError)
    {

        QTimer::singleShot(500, this, SLOT(StartCanConnect()));

    }
}

void CanToSerialCtrl::ReconnectDevice()
{
    qDebug() << "reconnect serialport";
    connectDevice("");


}

void CanToSerialCtrl::StartCanConnect()
{
    emit SerialOpenSuccess();
}

bool CanToSerialCtrl::writeFrame( CanSendFrameType &frame,  int channel )
{

	frame.channel = channel;
    frame.chksum = cal_Crc8(reinterpret_cast<const char*>(&frame));

    //SandList.append(frame);

    //return true;
    return serialPort->write(reinterpret_cast<char*>(&frame), sizeof(frame)) > 0;



}

void CanToSerialCtrl::setCanChannelConnect(uint8_t Ch_Chonnect)
{
    CanSendFrameType sendFrame = { };


    sendFrame.data[0] = cb125k;
    sendFrame.data[1] = 0;
    sendFrame.data[2] = cb125k;
    sendFrame.data[3] = 0;


    sendFrame.cmd = scConnected;
    sendFrame.para = Ch_Chonnect; //bit0: ch1, bit1: ch2, bit2: ch3, bit3: ch4,
    sendFrame.channel = 0;

    writeFrame(sendFrame, 0);

}

void CanToSerialCtrl::setRelayDIO(int DIO_No, int state)
{
    if (DIO_No >= 0 && DIO_No <= 7)
    {
        if (state)
            OUT_DIO |= 1 << DIO_No;
        else
            OUT_DIO &= ~(1 << DIO_No);
    }
}

void CanToSerialCtrl::SendCanData()
{
    CanSendFrameType    aFrame;
    if(SandList.count() > 0)
    {
        aFrame = SandList.takeFirst();
        if(serialPort->isOpen())
            serialPort->write(reinterpret_cast<char*>(&aFrame), sizeof(aFrame));
    }
}
