#pragma once

#include <QScopedPointer>

class BusinessContainer;
class InfrastructureContainer;
class CommunicationContainerPrivate;
class ConnectionController;

class CommDeviceManager;
class I_JsonReceiver;

class CommunicationContainer
{
public:
    explicit CommunicationContainer(BusinessContainer& businessContainer, InfrastructureContainer& infrastructureContainer);
    ~CommunicationContainer();

    I_JsonReceiver& jsonReceiver();
    ConnectionController& connectionController();
    CommDeviceManager& commDeviceManager();

private:
    // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
    QScopedPointer<CommunicationContainerPrivate> impl_;
};
