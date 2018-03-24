#include "AuxBmsPresenter.h"
#include "../../DataLayer/AuxBmsData/I_AuxBmsData.h"

AuxBmsPresenter::AuxBmsPresenter(const I_AuxBmsData &auxBmsData)
    : auxBmsData_(auxBmsData)
{
    relayAuxBmsData();
}

void AuxBmsPresenter::relayAuxBmsData()
{
    connect(&auxBmsData_, SIGNAL(prechargeStateReceived(const QString&)),
            this, SIGNAL(prechargeStateReceived(const QString&)));
    connect(&auxBmsData_, SIGNAL(auxVoltageReceived(const int&)),
            this, SIGNAL(auxVoltageReceived(const int&)));
    connect(&auxBmsData_, SIGNAL(auxBmsAliveReceived(const bool&)),
            this, SIGNAL(auxBmsAliveReceived(bool)));
    connect(&auxBmsData_, SIGNAL(strobeBmsLightRecieved(const bool&)),
            this, SIGNAL(strobeBmsLightReceived(bool)));
    connect(&auxBmsData_, SIGNAL(allowChargeRecieved(const bool&)),
            this, SIGNAL(allowChargeReceieved(bool)));
    connect(&auxBmsData_, SIGNAL(contactorErrorRecieved(const bool&)),
            this, SIGNAL(contactorErrorReceieved(bool)));
}
