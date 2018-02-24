#pragma once

class QIODevice;

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <QByteArray>
#include <QThread>

class InternetCommDevice : public QThread
{
    Q_OBJECT

public:
    void setQueueName(QString queueName);
    void setChannel(AmqpClient::Channel::ptr_t channel);
    virtual void run() override;

private:
    AmqpClient::Channel::ptr_t channel_;
    QString queueName_;

signals:
    void dataReceived(QByteArray data);
};
