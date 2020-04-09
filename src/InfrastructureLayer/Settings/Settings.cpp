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
    const QString DEFAULT_PACKET_TITLE = "Gen5";
    const QString EXCHANGE_NAME = "rabbitMQ/exchangeName";
    const QString DEFAULT_EXCHANGE_NAME = "hermesExchange";
    const QString QUEUE_NAME = "rabbitMQ/queueName";
    const QString DEFAULT_QUEUE_NAME = "displayQueue";
    const QString LOGGING_ENABLED = "Logging/loggingEnabled";
    const QString CUSTOM_QUEUE_ENABLE = "rabbitMQ/customQueueName";

}

Settings::Settings(QString filepath)
    : settings_(filepath, SETTINGS_FILE_FORMAT)
{
    if (settings_.value(IP_ADDRESS).isNull())
    {
        setDefaultValue();
    }
}

QString Settings::ipAddress() const
{
    return QString(settings_.value(IP_ADDRESS).toString());
}

quint16 Settings::port() const
{
    return (quint16)settings_.value(PORT).toInt();
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

bool Settings::logging() const
{
    return settings_.value(LOGGING_ENABLED).toBool();
}
bool Settings::customQueueEnable() const
{
    return settings_.value(CUSTOM_QUEUE_ENABLE).toBool();
}

void Settings::setQueueName(QString queueName)
{
    settings_.setValue(QUEUE_NAME, queueName);
}

void Settings::setDefaultValue()
{
    settings_.setValue(IP_ADDRESS, DEFAULT_IP);
    settings_.setValue(PORT, DEFAULT_PORT);
    settings_.setValue(PACKET_TITLE, DEFAULT_PACKET_TITLE);
    settings_.setValue(EXCHANGE_NAME, DEFAULT_EXCHANGE_NAME);
    settings_.setValue(CUSTOM_QUEUE_ENABLE, false);
    settings_.setValue(LOGGING_ENABLED, true);
}
