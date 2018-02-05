#pragma once

#include "I_ConnectionService.h"
#include "InternetConnectionService.h"
#include "CommDefines.h"
#include <SimpleAmqpClient/SimpleAmqpClient.h>

class ConnectionController : public I_ConnectionService
{
    Q_OBJECT
public:
    ConnectionController(QString exchangeName, QString queueName, QString ipAddress, quint16 port);
    virtual ~ConnectionController();

public:
    void setDeviceType(CommDefines::Type type);
    bool connectToDataSource();
    void disconnectFromDataSource();
    AmqpClient::Channel::ptr_t getChannel();

private:
    void connectToConnectionService(I_ConnectionService *service);
    void disconnectFromConnectionService(I_ConnectionService* service);

private:
    CommDefines::Type type_;
    QString exchangeName_;
    QString queueName_;
    QString ipAddress_;
    quint16 port_;
    AmqpClient::Channel::ptr_t channel_;
    //InternetConnectionService* internetConnectionService_;
    I_ConnectionService* internetConnectionService_;
};
