#include <QUdpSocket>

#include "CommDeviceManager.h"
#include <QDebug>

CommDeviceManager::CommDeviceManager(QUdpSocket& udpSocket)
    : udpSocket_(udpSocket)
{
}

CommDeviceManager::CommDeviceManager(AmqpClient::Channel::ptr_t channel, QString queueName)
    : udpSocket_(*new QUdpSocket()), queueName_(queueName), channel_(channel)
{
    connectToDevice(CommDefines::Internet);
}

CommDeviceManager::~CommDeviceManager()
{
}

void CommDeviceManager::connectToDevice(CommDefines::Type type)
{
    disconnectFromDevices();

    if (type == CommDefines::Udp)
    {
        connect(&udpSocket_, SIGNAL(readyRead()), this, SLOT(handleUdpDataIncoming()), Qt::UniqueConnection);
    }
    if (type == CommDefines::Internet)
    {
        InternetCommDevice *internetCommDevice = new InternetCommDevice();
        internetCommDevice->setQueueName(queueName_);
        internetCommDevice->setChannel(channel_);
        connect(internetCommDevice, &InternetCommDevice::dataReceived, this, &CommDeviceManager::handleJsonDataIncoming);
        connect(internetCommDevice, &InternetCommDevice::finished, internetCommDevice, &QObject::deleteLater);
        internetCommDevice->start();
    }
    // potential to add bluetooth here as a different input device
}

void CommDeviceManager::disconnectFromDevices()
{
    disconnect(&udpSocket_, 0, this, 0);
}

void CommDeviceManager::handleUdpDataIncoming()
{
    while (udpSocket_.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket_.pendingDatagramSize());
        udpSocket_.readDatagram(datagram.data(), datagram.size());

        if (!datagram.isEmpty())
        {
            emit dataReceived(datagram);
        }
    }
}

void CommDeviceManager::handleJsonDataIncoming(QByteArray data){
    if (!data.isEmpty()){
        emit dataReceived(data);
    }
}
