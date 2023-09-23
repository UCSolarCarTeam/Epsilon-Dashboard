#include "InternetCommDevice.h"
#include <QDebug>

void InternetCommDevice::setQueueName(QString queueName)
{
    queueName_ = queueName;
}

/* void InternetCommDevice::setChannel(AmqpClient::Channel::ptr_t channel)
{
    channel_ = channel;
}
*/

void InternetCommDevice::run()
{
    // std::string consumer_tag = channel_->BasicConsume(queueName_.toStdString(), "", true, true, false);

    while (1)
    {
        // AmqpClient::Envelope::ptr_t envelope = channel_->BasicConsumeMessage(consumer_tag);
        // QString str = QString::fromStdString(envelope->Message()->Body());
        QString str = "test";
        QByteArray dat = str.toUtf8();

        qDebug("New data has been received");
        sleep(1000);
        emit dataReceived(dat);
    }
}
