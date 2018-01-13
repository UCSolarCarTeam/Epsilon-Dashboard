#include "InternetCommDevice.h"
#include <QDebug>

InternetCommDevice::InternetCommDevice(AmqpClient::Channel::ptr_t channel, QString queueName)
    : channel_(channel), queueName_(queueName)
{
    std::thread waitForData(&InternetCommDevice::handleJsonDataIncoming, this);
    waitForData.detach();
}

InternetCommDevice::~InternetCommDevice()
{
    std::terminate();
}

void InternetCommDevice::handleJsonDataIncoming()
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
