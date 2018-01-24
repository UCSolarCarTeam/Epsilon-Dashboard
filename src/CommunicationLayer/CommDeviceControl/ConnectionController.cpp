#include "ConnectionController.h"

ConnectionController::ConnectionController(I_ConnectionService& internet)
    : type_(CommDefines::Internet)
    , internet_(internet)
{
}

ConnectionController::~ConnectionController()
{
}

void ConnectionController::setDeviceType(CommDefines::Type type)
{
    type_ = type;
}

bool ConnectionController::connectToDataSource()
{
    disconnectFromDataSource();
    connectToConnectionService(internet_);
    return internet_.connectToDataSource();
}

void ConnectionController::disconnectFromDataSource()
{
    internet_.disconnectFromDataSource();
    disconnectFromConnectionService(internet_);
}

void ConnectionController::connectToConnectionService(I_ConnectionService& service)
{
    connect(&service, SIGNAL(connectionFailed(QString)),
            this, SIGNAL(connectionFailed(QString)), Qt::UniqueConnection);
    connect(&service, SIGNAL(connectionSucceeded()),
            this, SIGNAL(connectionSucceeded()), Qt::UniqueConnection);
}

void ConnectionController::disconnectFromConnectionService(I_ConnectionService& service)
{
    disconnect(&service, 0, this, 0);
}
