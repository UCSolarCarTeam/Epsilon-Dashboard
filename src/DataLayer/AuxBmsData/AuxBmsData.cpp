#include "AuxBmsData.h"
#include "QDebug"

AuxBmsData::AuxBmsData()
{
}

AuxBmsData::~AuxBmsData()
{
}

// ------ data getter ------ //

QString AuxBmsData::prechargeState() const
{
    return prechargeState_;
}

int AuxBmsData::auxVoltage() const
{
    return auxVoltage_;
}

bool AuxBmsData::auxBmsAlive() const
{
    return auxBmsAlive_;
}

bool AuxBmsData::strobeBmsLight() const
{
    return strobeBmsLight_;
}

bool AuxBmsData::allowCharge() const
{
    return allowCharge_;
}

bool AuxBmsData::chargeTripHighTemperatureCurrent() const
{
    return chargeTripHighTemperatureCurrent_;
}

bool AuxBmsData::chargeTripHighVoltage() const
{
    return chargeTripHighVoltage_;
}

bool AuxBmsData::chargeTripPackCurrent() const
{
    return chargeTripPackCurrent_;
}

bool AuxBmsData::dischargeTripPackCurrent() const
{
    return dischargeTripPackCurrent_;
}

bool AuxBmsData::dischargeTripHighTemperatureCurrent() const
{
    return dischargeTripHighTemperatureCurrent_;
}

bool AuxBmsData::dischargeTripLowVoltage() const
{
    return dischargeTripLowVoltage_;
}

bool AuxBmsData::protectionTrip() const
{
    return protectionTrip_;
}

bool AuxBmsData::highVoltageEnableState() const
{
    return highVoltageEnableState_;
}

bool AuxBmsData::allowDischarge() const
{
    return allowDischarge_;
}

bool AuxBmsData::orionCanReceivedRecently() const
{
    return orionCanReceivedRecently_;
}

bool AuxBmsData::chargeContactorError() const
{
    return chargeContactorError_;
}

bool AuxBmsData::dischargeContactorError() const
{
    return dischargeContactorError_;
}

bool AuxBmsData::commonContactorError() const
{
    return commonContactorError_;
}

bool AuxBmsData::dischargeShouldTrip() const
{
    return dischargeShouldTrip_;
}

bool AuxBmsData::chargeShouldTrip() const
{
    return chargeShouldTrip_;
}

bool AuxBmsData::chargeOpenButShouldBeClosed() const
{
    return chargeOpenButShouldBeClosed_;
}

bool AuxBmsData::dischargeOpenButShouldBeClosed() const
{
    return dischargeOpenButShouldBeClosed_;
}

// ------ data setter ------ //

void AuxBmsData::setPrechargeState(const QString& prechargeState)
{
    if (QString::compare(prechargeState, "CHARGE_ENGAGED") == 0)
    {
        prechargeState_ = "Charge Engaged";
    }
    else if (QString::compare(prechargeState, "COMMON_ENGAGED") == 0)
    {
        prechargeState_ = "Common Engaged";
    }
    else if (QString::compare(prechargeState, "DISCHARGE_ENGAGED") == 0)
    {
        prechargeState_ = "Discharge Engaged";
    }
    else if (QString::compare(prechargeState, "ALL_ENGAGED") == 0)
    {
        prechargeState_ = "All Engaged";
    }
    else if (QString::compare(prechargeState, "OFF") == 0)
    {
        prechargeState_ = "Off";
    }

    emit prechargeStateReceived(prechargeState_);
}

void AuxBmsData::setAuxVoltage(const int auxVoltage)
{
    auxVoltage_ = auxVoltage;
    emit auxVoltageReceived(auxVoltage_);
}

void AuxBmsData::setAuxBmsAlive(const bool auxBmsAlive)
{
    auxBmsAlive_ = auxBmsAlive;
    emit auxBmsAliveReceived(auxBmsAlive_);
}

void AuxBmsData::setStrobeBmsLight(const bool strobeBmsLight)
{
    strobeBmsLight_ = strobeBmsLight;
    emit strobeBmsLightReceived(strobeBmsLight_);
}

void AuxBmsData::setAllowCharge(const bool allowCharge)
{
    allowCharge_ = allowCharge;
    emit allowChargeReceived(allowCharge_);
}

void AuxBmsData::setChargeTripHighTemperatureCurrent(const bool highTemperatureCurrent)
{
    chargeTripHighTemperatureCurrent_ = highTemperatureCurrent;
    emit chargeTripHighTemperatureCurrentReceived(chargeTripHighTemperatureCurrent_);
}

void AuxBmsData::setChargeTripHighVoltage(const bool highVoltage)
{
    chargeTripHighVoltage_ = highVoltage;
    emit chargeTripHighVoltageReceived(chargeTripHighVoltage_);
}

void AuxBmsData::setChargeTripPackCurrent(const bool packCurrent)
{
    chargeTripPackCurrent_ = packCurrent;
    emit chargeTripPackCurrentReceived(chargeTripPackCurrent_);
}

void AuxBmsData::setDischargeTripPackCurrent(const bool packCurrent)
{
    dischargeTripPackCurrent_ = packCurrent;
    emit dischargeTripPackCurrentReceived(dischargeTripPackCurrent_);
}

void AuxBmsData::setDischargeTripHighTemperatureCurrent(const bool highTemperatureCurrent)
{
    dischargeTripHighTemperatureCurrent_ = highTemperatureCurrent;
    emit dischargeTripHighTemperatureCurrentReceived(dischargeTripHighTemperatureCurrent_);
}

void AuxBmsData::setDischargeTripLowVoltage(const bool dischargeTripLowVoltage)
{
    dischargeTripLowVoltage_ = dischargeTripLowVoltage;
    emit dischargeTripLowVoltageReceived(dischargeTripLowVoltage_);
}

void AuxBmsData::setProtectionTrip(const bool protectionTrip)
{
    protectionTrip_ = protectionTrip;
    emit protectionTripReceived(protectionTrip_);
}

void AuxBmsData::setHighVoltageEnableState(const bool highVoltageEnableState)
{
    highVoltageEnableState_ = highVoltageEnableState;
    emit highVoltageEnableStateReceived(highVoltageEnableState_);
}

void AuxBmsData::setAllowDischarge(const bool allowDischarge)
{
    allowDischarge_ = allowDischarge;
    emit allowDischargeReceived(allowDischarge_);
}

void AuxBmsData::setOrionCanReceivedRecently(const bool orionCANReceivedRecently)
{
    orionCanReceivedRecently_ = orionCANReceivedRecently;
    emit orionCanReceivedRecentlyReceived(orionCanReceivedRecently_);
}

void AuxBmsData::setChargeContactorError(const bool chargeContactorError)
{
    chargeContactorError_ = chargeContactorError;
    emit chargeContactorErrorReceived(chargeContactorError_);
}

void AuxBmsData::setDischargeContactorError(const bool dischargeContactorError)
{
    dischargeContactorError_ = dischargeContactorError;
    emit dischargeContactorErrorReceived(dischargeContactorError_);
}

void AuxBmsData::setCommonContactorError(const bool commonContactorError)
{
    commonContactorError_ = commonContactorError;
    emit commonContactorErrorReceived(commonContactorError_);
}

void AuxBmsData::setDischargeShouldTrip(const bool dischargeShouldTrip)
{
    dischargeShouldTrip_ = dischargeShouldTrip;
    emit dischargeShouldTripReceived(dischargeShouldTrip_);
}

void AuxBmsData::setChargeShouldTrip(const bool chargeShouldTrip)
{
    chargeShouldTrip_ = chargeShouldTrip;
    emit chargeShouldTripReceived(chargeShouldTrip_);
}

void AuxBmsData::setChargeOpenButShouldBeClosed(const bool chargeOpenButShouldBeClosed)
{
    chargeOpenButShouldBeClosed_ = chargeOpenButShouldBeClosed;
    emit chargeOpenButShouldBeClosedReceived(chargeOpenButShouldBeClosed_);
}

void AuxBmsData::setDischargeOpenButShouldBeClosed(const bool dischargeOpenButShouldBeClosed)
{
    dischargeOpenButShouldBeClosed_ = dischargeOpenButShouldBeClosed;
    emit dischargeOpenButShouldBeClosedReceived(dischargeOpenButShouldBeClosed_);
}
