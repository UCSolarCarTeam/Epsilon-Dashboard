#pragma once

#include "I_CommunicationsMonitoringService.h"
#include <QObject>
#include <QTimer>

class CommunicationsMonitoringService : public I_CommunicationsMonitoringService
{
    Q_OBJECT
public:
    CommunicationsMonitoringService();
    virtual ~CommunicationsMonitoringService() {}

    void start();
    void stop();

private slots:
    void validPacketReceived();
    void invalidPacketReceived();
    void update();
    void decrementPacketsReceivedInLastMinute();
    void decrementValidPacketsReceivedInLastMinute();
    void decrementInvalidPacketsReceivedInLastMinute();

signals:
    void secondsSinceLastPacketReceivedUpdate(int secondsSinceLastPacketReceived);
    void packetsReceivedInLastMinuteUpdate(int packetsReceivedInLastMinute);

    void secondsSinceLastValidPacketReceivedUpdate(int secondsSinceLastValidPacketReceived);
    void validPacketsReceivedInLastMinuteUpdate(int validPacketsReceivedInLastMinute);

    void invalidPacketsReceivedInLastMinuteUpdate(int invalidPacketsReceivedInLastMinute);

private:
    QTimer updateTimer_;
    int secondsSinceLastPacketReceived_;
    int packetsReceivedInLastMinute_;
    int secondsSinceLastValidPacketReceived_;
    int validPacketsReceivedInLastMinute_;
    int invalidPacketsReceivedInLastMinute_;

};
