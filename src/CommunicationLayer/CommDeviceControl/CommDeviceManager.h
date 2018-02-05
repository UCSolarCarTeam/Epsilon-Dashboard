#pragma once

class QIODevice;
class QUdpSocket;

#include "CommDefines.h"
#include "I_CommDevice.h"
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include "InternetCommDevice.h"
#include "ConnectionController.h"

class CommDeviceManager : public I_CommDevice
{
    Q_OBJECT
public:
    CommDeviceManager(AmqpClient::Channel::ptr_t channel, QString queueName);
    virtual ~CommDeviceManager();

    void connectToDevice(CommDefines::Type type);
    void disconnectFromDevices();

private slots:
    void handleJsonDataIncoming(QByteArray);

private:
    QString queueName_;
    AmqpClient::Channel::ptr_t channel_;
};
