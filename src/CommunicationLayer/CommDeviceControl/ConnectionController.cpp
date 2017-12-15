#include "ConnectionController.h"

ConnectionController::ConnectionController(I_ConnectionService& udp)
    : type_(CommDefines::Udp)
    , udp_(udp)
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
    connectToConnectionService(udp_);
    return udp_.connectToDataSource();
}

void ConnectionController::disconnectFromDataSource()
{
    udp_.disconnectFromDataSource();
    disconnectFromConnectionService(udp_);
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
