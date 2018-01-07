#pragma once

class QIODevice;
class QUdpSocket;

#include "CommDefines.h"
#include "I_CommDevice.h"
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <QTimer>
#include <thread>

class InternetCommDevice : public I_CommDevice
{
    Q_OBJECT
public:
    InternetCommDevice(AmqpClient::Channel::ptr_t channel, QString queueName);
    virtual ~InternetCommDevice();

private slots:
    void handleJsonDataIncoming();

private:
    AmqpClient::Channel::ptr_t channel_;
    QString queueName_;
};
