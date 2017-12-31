#include "LightsPresenter.h"
#include "../../DataLayer/LightsData/I_LightsData.h"

LightsPresenter::LightsPresenter(const I_LightsData& lightsData)
    : lightsData_(lightsData)
{
    relayLightsData();
}

void LightsPresenter::relayLightsData()
{
    connect(&lightsData_, SIGNAL(lowBeamsReceived(bool)),
            this, SIGNAL(lowBeamsReceived(bool)));
    connect(&lightsData_, SIGNAL(highBeamsReceived(bool)),
            this, SIGNAL(highBeamsReceived(bool)));
    connect(&lightsData_, SIGNAL(brakesReceived(bool)),
            this, SIGNAL(brakesReceived(bool)));
    connect(&lightsData_, SIGNAL(leftSignalReceived(bool)),
            this, SIGNAL(leftSignalReceived(bool)));
    connect(&lightsData_, SIGNAL(rightSignalReceived(bool)),
            this, SIGNAL(rightSignalReceived(bool)));
    connect(&lightsData_, SIGNAL(bmsStrobeLightReceived(bool)),
            this, SIGNAL(bmsStrobeLightReceived(bool)));
    connect(&lightsData_, SIGNAL(aliveReceived(bool)),
            this, SIGNAL(lightAliveReceived(bool)));
}
