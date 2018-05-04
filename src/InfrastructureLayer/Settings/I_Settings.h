#pragma once

class I_Settings
{
public:
    virtual ~I_Settings() {}

    //configured by values in config.ini
    virtual QString ipAddress() const = 0;
    virtual quint16 port() const = 0;
    virtual QString packetTitle() const = 0;
    virtual QString exchange() const = 0;
    virtual QString queue() const = 0;

    virtual void setQueueName(QString queueName) = 0;
};
