#include "CommunicationsMonitoringService.h"
#include <QDebug>

CommunicationsMonitoringService::CommunicationsMonitoringService()
    : secondsSinceLastPacketReceived_(0)
    , packetsReceivedInLastMinute_(0)
    , secondsSinceLastValidPacketReceived_(0)
    , validPacketsReceivedInLastMinute_(0)
    , invalidPacketsReceivedInLastMinute_(0)
{
    /*
    connect(&jsonReceiver_, SIGNAL(packetInterpreted(const KeyDriverControlTelemetry&)),
            this, SLOT(validPacketReceived()));
    connect(&jsonReceiver_, SIGNAL(packetInterpreted(const DriverControlDetails&)),
            this, SLOT(validPacketReceived()));
    connect(&jsonReceiver_, SIGNAL(packetInterpreted(const FaultsMessage&)),
            this, SLOT(validPacketReceived()));
    connect(&jsonReceiver_, SIGNAL(packetInterpreted(const BatteryDataMessage&)),
            this, SLOT(validPacketReceived()));
    connect(&jsonReceiver_, SIGNAL(packetInterpreted(const CmuDataMessage&)),
            this, SLOT(validPacketReceived()));*/
    connect(&updateTimer_, SIGNAL(timeout()),
            this, SLOT(update()));
    updateTimer_.setInterval(1000); // update every second
    updateTimer_.setSingleShot(false);
}

void CommunicationsMonitoringService::start()
{
    updateTimer_.start();
}

void CommunicationsMonitoringService::stop()
{
    updateTimer_.stop();
}

void CommunicationsMonitoringService::validPacketReceived()
{
    validPacketsReceivedInLastMinute_++;
    secondsSinceLastValidPacketReceived_ = 0;
    QTimer::singleShot(60000, this, SLOT(decrementValidPacketsReceivedInLastMinute()));
    packetsReceivedInLastMinute_++;
    secondsSinceLastPacketReceived_ = 0;
    QTimer::singleShot(60000, this, SLOT(decrementPacketsReceivedInLastMinute()));
}
void CommunicationsMonitoringService::invalidPacketReceived()
{
    invalidPacketsReceivedInLastMinute_++;
    QTimer::singleShot(60000, this, SLOT(decrementInvalidPacketsReceivedInLastMinute()));
    packetsReceivedInLastMinute_++;
    secondsSinceLastPacketReceived_ = 0;
    QTimer::singleShot(60000, this, SLOT(decrementPacketsReceivedInLastMinute()));
}

void CommunicationsMonitoringService::update()
{
    secondsSinceLastPacketReceived_++;
    secondsSinceLastValidPacketReceived_++;
    emit secondsSinceLastPacketReceivedUpdate(secondsSinceLastPacketReceived_);
    emit packetsReceivedInLastMinuteUpdate(packetsReceivedInLastMinute_);
    emit secondsSinceLastValidPacketReceivedUpdate(secondsSinceLastValidPacketReceived_);
    emit validPacketsReceivedInLastMinuteUpdate(validPacketsReceivedInLastMinute_);
    emit invalidPacketsReceivedInLastMinuteUpdate(invalidPacketsReceivedInLastMinute_);
}

void CommunicationsMonitoringService::decrementPacketsReceivedInLastMinute()
{
    packetsReceivedInLastMinute_--;
}
void CommunicationsMonitoringService::decrementValidPacketsReceivedInLastMinute()
{
    validPacketsReceivedInLastMinute_--;
}
void CommunicationsMonitoringService::decrementInvalidPacketsReceivedInLastMinute()
{
    invalidPacketsReceivedInLastMinute_--;
}

