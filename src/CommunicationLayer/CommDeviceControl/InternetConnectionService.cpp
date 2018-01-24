#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <QDebug>
#include <QString>
#include <QTimer>

#include "../../InfrastructureLayer/Settings/I_Settings.h"
#include "InternetConnectionService.h"

namespace
{
    quint32 SLEEP_TIME_MILLISECONDS = 2000;
}

InternetConnectionService::InternetConnectionService(
    QString exchangeName
    ,  QString queueName
    ,  QString ipAddress
    ,  quint16 port)
    : exchangeName_(exchangeName)
    , queueName_(queueName)
    , ipAddress_(ipAddress)
    , port_(port)
    , connectionRetryTimer_(new QTimer(this))
{
    QObject::connect(this, SIGNAL(setupChannelSignal()), this, SLOT(connectToDataSource()));
    connectionRetryTimer_.setSingleShot(true);
    connect(&connectionRetryTimer_, SIGNAL(timeout()), this, SLOT(connectToDataSource()));
    connectToDataSource();
}

InternetConnectionService::~InternetConnectionService()
{
}


void InternetConnectionService::setupChannel()
{
    qWarning() << "InternetConnectionService: Attempting to connect to exchange" << exchangeName_ << "at" << ipAddress_ << port_;

    try
    {
        channel_ = AmqpClient::Channel::Create(ipAddress_.toStdString(), port_);
        channel_->DeclareExchange(exchangeName_.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
        channel_->DeclareQueue(queueName_.toStdString());
        channel_->BindQueue(queueName_.toStdString(), exchangeName_.toStdString());
    }
    catch (AmqpClient::ChannelException&)
    {
        if (channel_ == NULL)
        {
            qWarning() << "Connection failed, retrying in" << SLEEP_TIME_MILLISECONDS << "ms";
            connectionRetryTimer_.start(SLEEP_TIME_MILLISECONDS);
            return;
        }
        else
        {
            qWarning() << " InternetConnectionService: Error declaring/binding exchange or queue, Channel Exception";
            throw;
        }
    }
    catch (AmqpClient::ChannelErrorException&)
    {
        qWarning() << " InternetConnectionService: Error creating channel, Channel Error Exception";
        throw;
    }
    catch (AmqpClient::AmqpResponseLibraryException&)
    {
        qWarning() << " InternetConnectionService: Severe error declaring/binding exchange or queue, Channel is unusable; Amqp Response Library Exception";
        qWarning() << " Exiting Program";
        exit(EXIT_FAILURE);
    }
    catch (AmqpClient::ConnectionException& e)
    {
        qWarning() << " InternetConnectionService: Severe error declaring/binding exchange or queue, Channel is unusable; Connection Exception";
        qWarning() << " Exiting Program";
        exit(EXIT_FAILURE);
    }
    catch (AmqpClient::AmqpException::exception&)
    {
        qWarning() << " InternetConnectionService: Error creating channel, Unknown Exception";
        throw;
    }

    qDebug("Successful connection to RabbitMQ Server");
}

bool InternetConnectionService::connectToDataSource()
{
    try
    {
        setupChannel();
    }
    catch (AmqpClient::AmqpException::exception& e)
    {
        qWarning() << "Connection failed, retrying in" << SLEEP_TIME_MILLISECONDS << "ms";
        connectionRetryTimer_.start(SLEEP_TIME_MILLISECONDS);
        return false;
    }

    return true;
}

void InternetConnectionService::disconnectFromDataSource()
{
    qDebug("Resetting the channel...");
    channel_->UnbindQueue(queueName_.toStdString(), exchangeName_.toStdString());
    channel_.reset();
}

AmqpClient::Channel::ptr_t InternetConnectionService::getChannel()
{
    return channel_;
}
