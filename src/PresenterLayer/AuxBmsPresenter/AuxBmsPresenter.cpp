#include "AuxBmsPresenter.h"
#include "../../DataLayer/AuxBmsData/I_AuxBmsData.h"

AuxBmsPresenter::AuxBmsPresenter(const I_AuxBmsData& auxBmsData)
    : auxBmsData_(auxBmsData)
{
    relayAuxBmsData();
}

void AuxBmsPresenter::relayAuxBmsData()
{
    connect(&auxBmsData_, SIGNAL(prechargeStateReceived(const QString&)),
            this, SIGNAL(prechargeStateReceived(const QString&)));
    connect(&auxBmsData_, SIGNAL(auxVoltageReceived(const int)),
            this, SIGNAL(auxVoltageReceived(const int)));
    connect(&auxBmsData_, SIGNAL(auxBmsAliveReceived(const bool)),
            this, SIGNAL(auxBmsAliveReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(strobeBmsLightReceived(const bool)),
            this, SIGNAL(strobeBmsLightReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(allowChargeReceived(const bool)),
            this, SIGNAL(allowChargeReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeTripHighTemperatureCurrentReceived(const bool)),
            this, SIGNAL(chargeTripHighTemperatureCurrentReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeTripHighVoltageReceived(const bool)),
            this, SIGNAL(chargeTripHighVoltageReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeTripPackCurrentReceived(const bool)),
            this, SIGNAL(chargeTripPackCurrentReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeTripPackCurrentReceived(const bool)),
            this, SIGNAL(dischargeTripPackCurrentReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeTripHighTemperatureCurrentReceived(const bool)),
            this, SIGNAL(dischargeTripHighTemperatureCurrentReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeTripLowVoltageReceived(const bool)),
            this, SIGNAL(dischargeTripLowVoltageReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(protectionTripReceived(const bool)),
            this, SIGNAL(protectionTripReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(highVoltageEnableStateReceived(const bool)),
            this, SIGNAL(highVoltageEnableStateReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(allowDischargeReceived(const bool)),
            this, SIGNAL(allowDischargeReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(orionCanReceivedRecentlyReceived(const bool)),
            this, SIGNAL(orionCanReceivedRecentlyReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeContactorErrorReceived(const bool)),
            this, SIGNAL(chargeContactorErrorReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeContactorErrorReceived(const bool)),
            this, SIGNAL(dischargeContactorErrorReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(commonContactorErrorReceived(const bool)),
            this, SIGNAL(commonContactorErrorReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeShouldTripReceived(const bool)),
            this, SIGNAL(dischargeShouldTripReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeShouldTripReceived(const bool)),
            this, SIGNAL(chargeShouldTripReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeOpenButShouldBeClosedReceived(const bool)),
            this, SIGNAL(chargeOpenButShouldBeClosedReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeOpenButShouldBeClosedReceived(const bool)),
            this, SIGNAL(dischargeOpenButShouldBeClosedReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(tripContactorDisconnectedUnexpectedlyReceived(const bool)),
            this, SIGNAL(tripContactorDisconnectedUnexpectedlyReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(tripOrionMessageTimeoutReceived(const bool)),
            this, SIGNAL(tripOrionMessageTimeoutReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(dischargeNotClosedHighCurrentReceived(const bool)),
            this, SIGNAL(dischargeNotClosedHighCurrentReceived(const bool)));
    connect(&auxBmsData_, SIGNAL(chargeNotClosedHighCurrentReceived(const bool)),
            this, SIGNAL(chargeNotClosedHighCurrentReceived(const bool)));
}
