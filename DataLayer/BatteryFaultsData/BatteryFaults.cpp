#include "BatteryFaults.h"
#include <QDebug>

BatteryFaults::BatteryFaults()
{
}

BatteryFaults::~BatteryFaults()
{
}

bool BatteryFaults::cellOverVoltage() const
{
    return cellOverVoltage_;
}

bool BatteryFaults::cellUnderVoltage() const
{
    return cellUnderVoltage_;
}

bool BatteryFaults::cellOverTemperature() const
{
    return cellOverTemperature_;
}

bool BatteryFaults::measurementUntrusted() const
{
    return measurementUntrusted_;
}

bool BatteryFaults::CMUCOMMTIMEOUT() const
{
    return CMUCOMMTIMEOUT_;
}

bool BatteryFaults::vehicleCommTimeout() const
{
    return vehicleCommTimeout_;
}

bool BatteryFaults::bmuIsInSetupMode() const
{
    return bmuIsInSetupMode_;
}

bool BatteryFaults::cmuCanBusPowerStatus() const
{
    // Note: This fault flag actually means everything is okay.
    return !cmuCanBusPowerStatus_;
}

bool BatteryFaults::packIsolationTestFailure() const
{
    return packIsolationTestFailure_;
}

bool BatteryFaults::softwareOverCurrentMeasured() const
{
    return softwareOverCurrentMeasured_;
}

bool BatteryFaults::canSupplyIsLow() const
{
    return canSupplyIsLow_;
}

bool BatteryFaults::contactorIsStuck() const
{
    return contactorIsStuck_;
}

bool BatteryFaults::cmuDetectedExtraCellPresent() const
{
    return cmuDetectedExtraCellPresent_;
}

void BatteryFaults::setCellOverVoltage(bool cellOverVoltage)
{
    cellOverVoltage_ = cellOverVoltage;
}

void BatteryFaults::setCellUnderVoltage(bool cellUnderVoltage)
{
    cellUnderVoltage_ = cellUnderVoltage;
}

void BatteryFaults::setCellOverTemperature(bool cellOverTemperature)
{
    cellOverTemperature_ = cellOverTemperature;
}

void BatteryFaults::setMeasurementUntrusted(bool measurementUntrusted)
{
    measurementUntrusted_ = measurementUntrusted;
}

void BatteryFaults::setCMUCOMMTIMEOUT(bool CMUCOMMTIMEOUT)
{
    CMUCOMMTIMEOUT_ = CMUCOMMTIMEOUT;
}

void BatteryFaults::setVehicleCommTimeout(bool vehicleCommTimeout)
{
    vehicleCommTimeout_ = vehicleCommTimeout;
}

void BatteryFaults::setBmuIsInSetupMode(bool bmuIsInSetupMode)
{
    bmuIsInSetupMode_ = bmuIsInSetupMode;
}

void BatteryFaults::setCmuCanBusPowerStatus(bool cmuCanBusPowerStatus)
{
    cmuCanBusPowerStatus_ = cmuCanBusPowerStatus;
}

void BatteryFaults::setPackIsolationTestFailure(bool packIsolationTestFailure)
{
    packIsolationTestFailure_ = packIsolationTestFailure;
}

void BatteryFaults::setSoftwareOverCurrentMeasured(bool softwareOverCurrentMeasured)
{
    softwareOverCurrentMeasured_ = softwareOverCurrentMeasured;
}

void BatteryFaults::setCanSupplyIsLow(bool canSupplyIsLow)
{
    canSupplyIsLow_ = canSupplyIsLow;
}

void BatteryFaults::setContactorIsStuck(bool contactorIsStuck)
{
    contactorIsStuck_ = contactorIsStuck;
}

void BatteryFaults::setCmuDetectedExtraCellPresent(bool cmuDetectedExtraCellPresent)
{
    cmuDetectedExtraCellPresent_ = cmuDetectedExtraCellPresent;
}

