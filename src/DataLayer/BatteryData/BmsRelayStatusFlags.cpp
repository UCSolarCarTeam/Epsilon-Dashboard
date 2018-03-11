#include "BmsRelayStatusFlags.h"

BmsRelayStatusFlags::BmsRelayStatusFlags()
    : dischargeRelayEnabled_(false)
    , chargeRelayEnabled_(false)
    , chargerSafetyEnabled_(false)
    , malfunctionIndicatorActive_(false)
    , multiPurposeInputSignalStatus_(false)
    , alwaysOnSignalStatus_(false)
    , isReadySignalStatus_(false)
    , isChargingSignalStatus_(false)
{
}

bool BmsRelayStatusFlags::dischargeRelayEnabled() const
{
    return dischargeRelayEnabled_;
}

void BmsRelayStatusFlags::setDischargeRelayEnabled(bool dischargeRelayEnabled)
{
    dischargeRelayEnabled_ = dischargeRelayEnabled;
}

bool BmsRelayStatusFlags::chargeRelayEnabled() const
{
    return chargeRelayEnabled_;
}

void BmsRelayStatusFlags::setChargeRelayEnabled(bool chargeRelayEnabled)
{
    chargeRelayEnabled_ = chargeRelayEnabled;
}

bool BmsRelayStatusFlags::chargerSafetyEnabled() const
{
    return chargerSafetyEnabled_;
}

void BmsRelayStatusFlags::setChargerSafetyEnabled(bool chargerSafetyEnabled)
{
    chargerSafetyEnabled_ = chargerSafetyEnabled;
}

bool BmsRelayStatusFlags::malfunctionIndicatorActive() const
{
    return malfunctionIndicatorActive_;
}

void BmsRelayStatusFlags::setMalfunctionIndicatorActive(bool malfunctionIndicatorActive)
{
    malfunctionIndicatorActive_ = malfunctionIndicatorActive;
}

bool BmsRelayStatusFlags::multiPurposeInputSignalStatus() const
{
    return multiPurposeInputSignalStatus_;
}

void BmsRelayStatusFlags::setMultiPurposeInputSignalStatus(bool multiPurposeInputSignalStatus)
{
    multiPurposeInputSignalStatus_ = multiPurposeInputSignalStatus;
}

bool BmsRelayStatusFlags::alwaysOnSignalStatus() const
{
    return alwaysOnSignalStatus_;
}

void BmsRelayStatusFlags::setAlwaysOnSignalStatus(bool alwaysOnSignalStatus)
{
    alwaysOnSignalStatus_ = alwaysOnSignalStatus;
}

bool BmsRelayStatusFlags::isReadySignalStatus() const
{
    return isReadySignalStatus_;
}

void BmsRelayStatusFlags::setIsReadySignalStatus(bool isReadySignalStatus)
{
    isReadySignalStatus_ = isReadySignalStatus;
}

bool BmsRelayStatusFlags::isChargingSignalStatus() const
{
    return isChargingSignalStatus_;
}

void BmsRelayStatusFlags::setIsChargingSignalStatus(bool isChargingSignalStatus)
{
    isChargingSignalStatus_ = isChargingSignalStatus;
}
