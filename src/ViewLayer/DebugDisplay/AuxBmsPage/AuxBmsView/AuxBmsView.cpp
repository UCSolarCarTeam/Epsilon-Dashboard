#include <QLabel>

#include "AuxBmsView.h"
#include "../PresenterLayer/AuxBmsPresenter/AuxBmsPresenter.h"
#include "AuxBmsPage/AuxBmsUi/I_AuxBmsUi.h"

namespace
{
    const QString ALIVE = "background-color:rgb(93, 234, 140); \
                              border-radius:8px; \
                              border: 1px solid white;";
    const QString DEAD = "background-color:rgb(147, 147, 147); \
                             border-radius:8px; \
                             border: 1px solid white;";

    const QString VOLTAGE_UNIT = "V";

    const QString ON = "color: rgb(250, 187, 28);";
    const QString OFF = "color: grey;";
}


AuxBmsView::AuxBmsView(AuxBmsPresenter& auxBmsPresenter,
                       I_AuxBmsUi& ui)
    : presenter_(auxBmsPresenter)
    , ui_(ui)
{
    connectAuxBms(presenter_);
}

void AuxBmsView::connectAuxBms(AuxBmsPresenter& auxBmsPresenter)
{
    connect(&auxBmsPresenter, SIGNAL(auxBmsAliveReceived(const bool)),
            this, SLOT(auxBmsAliveReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(strobeBmsLightReceived(const bool)),
            this, SLOT(strobeBmsReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(allowChargeReceived(const bool)),
            this, SLOT(allowChargeReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(auxVoltageReceived(const int)),
            this, SLOT(auxVoltageReceived(const int)));
    connect(&auxBmsPresenter, SIGNAL(prechargeStateReceived(const QString)),
            this, SLOT(prechargeStateReceived(const QString)));
    connect(&auxBmsPresenter, SIGNAL(chargeTripHighTemperatureCurrentReceived(const bool)),
            this, SLOT(chargeTripHighTemperatureCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeTripHighVoltageReceived(const bool)),
            this, SLOT(chargeTripHighVoltageReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeTripPackCurrentReceived(const bool)),
            this, SLOT(chargeTripPackCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeTripPackCurrentReceived(const bool)),
            this, SLOT(dischargeTripPackCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeTripHighTemperatureCurrentReceived(const bool)),
            this, SLOT(dischargeTripHighTemperatureCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeTripLowVoltageReceived(const bool)),
            this, SLOT(dischargeTripLowVoltageReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(protectionTripReceived(const bool)),
            this, SLOT(protectionTripReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(highVoltageEnableStateReceived(const bool)),
            this, SLOT(highVoltageEnableStateReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(allowDischargeReceived(const bool)),
            this, SLOT(allowDischargeReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(orionCanReceivedRecentlyReceived(const bool)),
            this, SLOT(orionCanReceivedRecentlyReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeContactorErrorReceived(const bool)),
            this, SLOT(chargeContactorErrorReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeContactorErrorReceived(const bool)),
            this, SLOT(dischargeContactorErrorReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(commonContactorErrorReceived(const bool)),
            this, SLOT(commonContactorErrorReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeShouldTripReceived(const bool)),
            this, SLOT(dischargeShouldTripReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeShouldTripReceived(const bool)),
            this, SLOT(chargeShouldTripReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeOpenButShouldBeClosedReceived(const bool)),
            this, SLOT(chargeOpenButShouldBeClosedReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeOpenButShouldBeClosedReceived(const bool)),
            this, SLOT(dischargeOpenButShouldBeClosedReceived(const bool)));
}
void AuxBmsView::auxVoltageReceived(const int auxVoltage)
{
    ui_.voltage().setText(QString::number(auxVoltage) + " " + VOLTAGE_UNIT);
}

void AuxBmsView::auxBmsAliveReceived(const bool auxBmsAlive)
{
    if (auxBmsAlive)
    {
        ui_.alive().setStyleSheet(ALIVE);
    }
    else
    {
        ui_.alive().setStyleSheet(DEAD);
    }
}

void AuxBmsView::strobeBmsReceived(const bool strobe)
{
    if (strobe)
    {
        ui_.strobeBms().setStyleSheet(ON);
    }
    else
    {
        ui_.strobeBms().setStyleSheet(OFF);
    }
}

void AuxBmsView::allowChargeReceived(const bool allowCharge)
{

    if (allowCharge)
    {
        ui_.allowCharge().setStyleSheet(ON);
    }
    else
    {
        ui_.allowCharge().setStyleSheet(OFF);
    }
}

void AuxBmsView::prechargeStateReceived(const QString prechargeState)
{
    ui_.prechargeState().setText(prechargeState);
}

void AuxBmsView::chargeTripHighTemperatureCurrentReceived(const bool highTemperatureCurrent)
{
    if (highTemperatureCurrent)
    {
        ui_.chargeTripHighTemperatureCurrent().setStyleSheet(ON);
    }
    else
    {
        ui_.chargeTripHighTemperatureCurrent().setStyleSheet(OFF);
    }
}

void AuxBmsView::chargeTripHighVoltageReceived(const bool highVoltage)
{
    if (highVoltage)
    {
        ui_.chargeTripHighVoltage().setStyleSheet(ON);
    }
    else
    {
        ui_.chargeTripHighVoltage().setStyleSheet(OFF);
    }
}

void AuxBmsView::chargeTripPackCurrentReceived(const bool chargeTripPackCurrent)
{
    if (chargeTripPackCurrent)
    {
        ui_.chargeTripPackCurrent().setStyleSheet(ON);
    }
    else
    {
        ui_.chargeTripPackCurrent().setStyleSheet(OFF);
    }
}

void AuxBmsView::dischargeTripPackCurrentReceived(const bool dischargeTripPackCurrent)
{
    if (dischargeTripPackCurrent)
    {
        ui_.dischargeTripPackCurrent().setStyleSheet(ON);
    }
    else
    {
        ui_.dischargeTripPackCurrent().setStyleSheet(OFF);
    }
}

void AuxBmsView::dischargeTripHighTemperatureCurrentReceived(const bool dischargeTripHighTemperatureCurrent)
{
    if (dischargeTripHighTemperatureCurrent)
    {
        ui_.dischargeTripHighTemperatureCurrent().setStyleSheet(ON);
    }
    else
    {
        ui_.dischargeTripHighTemperatureCurrent().setStyleSheet(OFF);
    }
}

void AuxBmsView::dischargeTripLowVoltageReceived(const bool lowVoltage)
{
    if (lowVoltage)
    {
        ui_.dischargeTripLowVoltage().setStyleSheet(ON);
    }
    else
    {
        ui_.dischargeTripLowVoltage().setStyleSheet(OFF);
    }
}

void AuxBmsView::protectionTripReceived(const bool protectionTrip)
{
    if (protectionTrip)
    {
        ui_.protectionTrip().setStyleSheet(ON);
    }
    else
    {
        ui_.protectionTrip().setStyleSheet(OFF);
    }
}

void AuxBmsView::highVoltageEnableStateReceived(const bool highVoltageEnableState)
{
    if (highVoltageEnableState)
    {
        ui_.highVoltageEnableState().setStyleSheet(ON);
    }
    else
    {
        ui_.highVoltageEnableState().setStyleSheet(OFF);
    }
}

void AuxBmsView::allowDischargeReceived(const bool allowDischarge)
{
    if (allowDischarge)
    {
        ui_.allowDischarge().setStyleSheet(ON);
    }
    else
    {
        ui_.allowDischarge().setStyleSheet(OFF);
    }
}

void AuxBmsView::orionCanReceivedRecentlyReceived(const bool orionCanReceivedRecently)
{
    if (orionCanReceivedRecently)
    {
        ui_.orionCanReceivedRecently().setStyleSheet(ON);
    }
    else
    {
        ui_.orionCanReceivedRecently().setStyleSheet(OFF);
    }
}

void AuxBmsView::chargeContactorErrorReceived(const bool chargeContactorError)
{
    if (chargeContactorError)
    {
        ui_.chargeContactorError().setStyleSheet(ON);
    }
    else
    {
        ui_.chargeContactorError().setStyleSheet(OFF);
    }
}

void AuxBmsView::dischargeContactorErrorReceived(const bool dischargeContactorError)
{
    if (dischargeContactorError)
    {
        ui_.dischargeContactorError().setStyleSheet(ON);
    }
    else
    {
        ui_.dischargeContactorError().setStyleSheet(OFF);
    }
}

void AuxBmsView::commonContactorErrorReceived(const bool commonContactorError)
{
    if (commonContactorError)
    {
        ui_.commonContactorError().setStyleSheet(ON);
    }
    else
    {
        ui_.commonContactorError().setStyleSheet(OFF);
    }
}

void AuxBmsView::dischargeShouldTripReceived(const bool dischargeShouldTrip)
{
    if (dischargeShouldTrip)
    {
        ui_.dischargeShouldTrip().setStyleSheet(ON);
    }
    else
    {
        ui_.dischargeShouldTrip().setStyleSheet(OFF);
    }
}

void AuxBmsView::chargeShouldTripReceived(const bool chargeShouldTrip)
{
    if (chargeShouldTrip)
    {
        ui_.chargeShouldTrip().setStyleSheet(ON);
    }
    else
    {
        ui_.chargeShouldTrip().setStyleSheet(OFF);
    }
}

void AuxBmsView::chargeOpenButShouldBeClosedReceived(const bool chargeOpenButShouldBeClosed)
{
    if (chargeOpenButShouldBeClosed)
    {
        ui_.chargeOpenButShouldBeClosed().setStyleSheet(ON);
    }
    else
    {
        ui_.chargeOpenButShouldBeClosed().setStyleSheet(OFF);
    }
}

void AuxBmsView::dischargeOpenButShouldBeClosedReceived(const bool dischargeOpenButShouldBeClosed)
{
    if (dischargeOpenButShouldBeClosed)
    {
        ui_.dischargeOpenButShouldBeClosed().setStyleSheet(ON);
    }
    else
    {
        ui_.dischargeOpenButShouldBeClosed().setStyleSheet(OFF);
    }
}
