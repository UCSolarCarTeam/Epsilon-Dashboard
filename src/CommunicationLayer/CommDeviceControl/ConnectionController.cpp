#include "ConnectionController.h"

ConnectionController::ConnectionController(QString exchangeName
        ,  QString queueName
        ,  QString ipAddress
        ,  quint16 port)
    : type_(CommDefines::Internet)
    , exchangeName_(exchangeName)
    , queueName_(queueName)
    , ipAddress_(ipAddress)
    , port_(port)
{
    if (type_ == CommDefines::Internet)
    {
        InternetConnectionService* internetConnectionService = new InternetConnectionService(exchangeName_, queueName_, ipAddress_, port_);
        internetConnectionService_ = internetConnectionService;
        connectToDataSource();
        channel_ = internetConnectionService->getChannel();
    }
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
    connectToConnectionService(internetConnectionService_);
    return internetConnectionService_->connectToDataSource();
}

void ConnectionController::disconnectFromDataSource()
{
    internetConnectionService_->disconnectFromDataSource();
    disconnectFromConnectionService(internetConnectionService_);
}

void ConnectionController::connectToConnectionService(I_ConnectionService* service)
{
    connect(service, SIGNAL(connectionFailed(QString)),
            this, SIGNAL(connectionFailed(QString)), Qt::UniqueConnection);
    connect(service, SIGNAL(connectionSucceeded()),
            this, SIGNAL(connectionSucceeded()), Qt::UniqueConnection);
}

void ConnectionController::disconnectFromConnectionService(I_ConnectionService* service)
{
    disconnect(service, 0, this, 0);
}

AmqpClient::Channel::ptr_t ConnectionController::getChannel()
{
    return channel_;
}
