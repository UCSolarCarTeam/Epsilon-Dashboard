#include "DriverControlsPresenter.h"
#include "../../DataLayer/DriverControlsData/I_DriverControlsData.h"

DriverControlsPresenter::DriverControlsPresenter(const I_DriverControlsData& driverControlsData)
    : driverControlsData_(driverControlsData)
{
    relayDriverControlsData();
}

void DriverControlsPresenter::relayDriverControlsData()
{
    connect(&driverControlsData_, SIGNAL(aliveReceived(bool)),
            this, SIGNAL(aliveReceived(bool)));
    connect(&driverControlsData_, SIGNAL(headlightsOffReceived(bool)),
            this, SIGNAL(headlightsOffReceived(bool)));
    connect(&driverControlsData_, SIGNAL(headlightsLowReceived(bool)),
            this, SIGNAL(headlightsLowReceived(bool)));
    connect(&driverControlsData_, SIGNAL(headlightsHighReceived(bool)),
            this, SIGNAL(headlightsHighReceived(bool)));
    connect(&driverControlsData_, SIGNAL(signalRightReceived(bool)),
            this, SIGNAL(signalRightReceived(bool)));
    connect(&driverControlsData_, SIGNAL(signalLeftReceived(bool)),
            this, SIGNAL(signalLeftReceived(bool)));
    connect(&driverControlsData_, SIGNAL(hazardReceived(bool)),
            this, SIGNAL(hazardReceived(bool)));
    connect(&driverControlsData_, SIGNAL(interiorReceived(bool)),
            this, SIGNAL(interiorReceived(bool)));
    connect(&driverControlsData_, SIGNAL(auxReceived(bool)),
            this, SIGNAL(auxReceived(bool)));
    connect(&driverControlsData_, SIGNAL(volumeUpReceived(bool)),
            this, SIGNAL(volumeUpReceived(bool)));
    connect(&driverControlsData_, SIGNAL(volumeDownReceived(bool)),
            this, SIGNAL(volumeDownReceived(bool)));
    connect(&driverControlsData_, SIGNAL(nextSongReceived(bool)),
            this, SIGNAL(nextSongReceived(bool)));
    connect(&driverControlsData_, SIGNAL(prevSongReceived(bool)),
            this, SIGNAL(prevSongReceived(bool)));
    connect(&driverControlsData_, SIGNAL(accelerationReceived(double)),
            this, SIGNAL(accelerationReceived(double)));
    connect(&driverControlsData_, SIGNAL(regenBrakingReceived(double)),
            this, SIGNAL(regenBrakingReceived(double)));
    connect(&driverControlsData_, SIGNAL(brakesReceived(bool)),
            this, SIGNAL(brakesReceived(bool)));
    connect(&driverControlsData_, SIGNAL(forwardReceived(bool)),
            this, SIGNAL(forwardReceived(bool)));
    connect(&driverControlsData_, SIGNAL(reverseReceived(bool)),
            this, SIGNAL(reverseReceived(bool)));
    connect(&driverControlsData_, SIGNAL(pushToTalkReceived(bool)),
            this, SIGNAL(pushToTalkReceived(bool)));
    connect(&driverControlsData_, SIGNAL(hornReceived(bool)),
            this, SIGNAL(hornReceived(bool)));
    connect(&driverControlsData_, SIGNAL(resetReceived(bool)),
            this, SIGNAL(resetReceived(bool)));
}
