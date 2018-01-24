#include "InternetCommDevice.h"
#include <QDebug>

void InternetCommDevice::setQueueName(QString queueName)
{
    queueName_ = queueName;
}

void InternetCommDevice::setChannel(AmqpClient::Channel::ptr_t channel)
{
    channel_ = channel;
}

void InternetCommDevice::run()
{
    while (1)
    {
        std::string consumer_tag = channel_->BasicConsume(queueName_.toStdString(), "", true, true, false);
        AmqpClient::Envelope::ptr_t envelope = channel_->BasicConsumeMessage(consumer_tag);
        QString str = QString::fromStdString(envelope->Message()->Body());
        QByteArray dat = str.toUtf8();

        qDebug("New data has been received");

        emit dataReceived(dat);
    }
}
