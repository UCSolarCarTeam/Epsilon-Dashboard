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

bool AuxBmsData::contactorError() const
{
    return contactorError_;
}

bool AuxBmsData::highVoltageEnable() const
{
    return highVoltageEnable_;
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

void AuxBmsData::setAuxVoltage(const int& auxVoltage)
{
    auxVoltage_ = auxVoltage;
    emit auxVoltageReceived(auxVoltage_);
}

void AuxBmsData::setAuxBmsAlive(const bool& auxBmsAlive)
{
    auxBmsAlive_ = auxBmsAlive;
    emit auxBmsAliveReceived(auxBmsAlive_);
}

void AuxBmsData::setStrobeBmsLight(const bool& strobeBmsLight)
{
    strobeBmsLight_ = strobeBmsLight;
    emit strobeBmsLightReceived(strobeBmsLight_);
}

void AuxBmsData::setAllowCharge(const bool& allowCharge)
{
    allowCharge_ = allowCharge;
    emit allowChargeReceived(allowCharge_);
}

void AuxBmsData::setContactorError(const bool& contactorError)
{
    contactorError_ = contactorError;
    emit contactorErrorReceived(contactorError_);
}

void AuxBmsData::setHighVoltageEnable(const bool& highVoltageEnable)
{
    highVoltageEnable_ = highVoltageEnable;
    emit highVoltageEnableReceived(highVoltageEnable_);
}

