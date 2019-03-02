#pragma once

#include <QObject>

class I_CommunicationsMonitoringService : public QObject
{
    Q_OBJECT
public:
    virtual void start() = 0;
    virtual void stop() = 0;

signals:
    virtual void secondsSinceLastPacketReceivedUpdate(int secondsSinceLastPacketReceived)=0;
    virtual void packetsReceivedInLastMinuteUpdate(int packetsReceivedInLastMinute)=0;

    virtual void secondsSinceLastValidPacketReceivedUpdate(int secondsSinceLastValidPacketReceived)=0;
    virtual void validPacketsReceivedInLastMinuteUpdate(int validPacketsReceivedInLastMinute)=0;

    virtual void invalidPacketsReceivedInLastMinuteUpdate(int invalidPacketsReceivedInLastMinute)=0;
};
