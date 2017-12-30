#include <QUdpSocket>

#include "InternetCommDevice.h"
#include <QDebug>
#include <thread>

InternetCommDevice::InternetCommDevice(AmqpClient::Channel::ptr_t channel, QString queueName)
    : channel_(channel), queueName_(queueName)
{
    std::thread waitForData(&InternetCommDevice::handleJsonDataIncoming, this);
    waitForData.detach();
}

InternetCommDevice::~InternetCommDevice()
{
}

void InternetCommDevice::handleJsonDataIncoming()
{
    while(1){
    qDebug() << "Waiting for data...";
    //channel_->DeclareQueue(queueName_.toStdString());
    //channel_->BindQueue(queueName_.toStdString(), exchangeName_.toStdString());
    std::string consumer_tag = channel_->BasicConsume(queueName_.toStdString(), "", true, true, false);
    AmqpClient::Envelope::ptr_t envelope = channel_->BasicConsumeMessage(consumer_tag);
    QString str = QString::fromStdString(envelope->Message()->Body());
    QByteArray dat = str.toUtf8();
    qDebug() << "Data Received";
    emit dataReceived(dat);
    }
}
