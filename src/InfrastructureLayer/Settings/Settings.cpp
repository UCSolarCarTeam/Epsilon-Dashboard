#include <QDebug>
#include <QSettings>

#include "Settings.h"

namespace
{
    const QSettings::Format SETTINGS_FILE_FORMAT = QSettings::IniFormat;
    const QString IP_ADDRESS = "SourceAddress/ipAddress";
    const QString DEFAULT_IP = "127.0.0.1";
    const QString PORT = "SourceAddress/port";
    const QString DEFAULT_PORT = "5672";
    const QString PACKET_TITLE = "JsonFormat/packetTitle";
    const QString EXCHANGE_NAME = "rabbitMQ/exchangeName";
    const QString QUEUE_NAME = "rabbitMQ/queueName";

}

Settings::Settings(QString filepath)
    : settings_(filepath, SETTINGS_FILE_FORMAT)
{
}

QString Settings::ipAddress() const
{
    return QString(settings_.value(IP_ADDRESS, DEFAULT_IP).toString());
}

quint16 Settings::port() const
{
    return (quint16)settings_.value(PORT, DEFAULT_PORT).toInt();
}

QString Settings::packetTitle() const
{
    return settings_.value(PACKET_TITLE).toString();
}

QString Settings::exchange() const
{
    return QString(settings_.value(EXCHANGE_NAME).toString());
}

QString Settings::queue() const
{
    return QString(settings_.value(QUEUE_NAME).toString());
}

void Settings::setQueueName(QString queueName)
{
    settings_.setValue(QUEUE_NAME, queueName);
}
