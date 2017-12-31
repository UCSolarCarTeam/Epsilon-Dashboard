#pragma once

#include <QScopedPointer>
#include "CommDeviceControl/InternetConnectionService.h"

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
    InternetConnectionService& internetConnectionService();
    CommDeviceManager& commDeviceManager();

private:
    // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
    QScopedPointer<CommunicationContainerPrivate> impl_;
};
