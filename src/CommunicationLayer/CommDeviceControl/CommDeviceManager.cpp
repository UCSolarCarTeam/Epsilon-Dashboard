#include "CommDeviceManager.h"
#include <QDebug>

CommDeviceManager::CommDeviceManager(AmqpClient::Channel::ptr_t channel, QString queueName)
    : queueName_(queueName)
    , channel_(channel)
{
    connectToDevice(CommDefines::Internet);
}

CommDeviceManager::~CommDeviceManager()
{
}

void CommDeviceManager::connectToDevice(CommDefines::Type type)
{
    if (type == CommDefines::Internet)
    {
        InternetCommDevice* internetCommDevice = new InternetCommDevice();
        internetCommDevice->setQueueName(queueName_);
        internetCommDevice->setChannel(channel_);
        connect(internetCommDevice, &InternetCommDevice::dataReceived, this, &CommDeviceManager::handleJsonDataIncoming);
        connect(internetCommDevice, &InternetCommDevice::finished, internetCommDevice, &QObject::deleteLater);
        internetCommDevice->start();
    }

    // potential to add bluetooth here as a different input device
}

void CommDeviceManager::handleJsonDataIncoming(QByteArray data)
{
    if (!data.isEmpty())
    {
        emit dataReceived(data);
    }
    else
    {
        qWarning() << "Warning: Data received is empty!";
    }
}
