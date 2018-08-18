#include "BatteryData.h"
#include <QDebug>

BatteryData::BatteryData()
{
}

BatteryData::~BatteryData()
{
}

// ------ data getter ------ //

bool BatteryData::alive() const
{
    return alive_;
}

BmsRelayStatusFlags BatteryData::bmsRelayStatus() const
{
    return bmsRelayStatus_;
}

int BatteryData::populatedCells() const
{
    return populatedCells_;
}

double BatteryData::inputVoltage12V() const
{
    return inputVoltage12V_;
}

double BatteryData::fanVoltage() const
{
    return fanVoltage_;
}

double BatteryData::packCurrent() const
{
    return packCurrent_;
}

double BatteryData::packVoltage() const
{
    return packVoltage_;
}

double BatteryData::packStateOfCharge() const
{
    return packStateOfCharge_;
}

double BatteryData::packAmphours() const
{
    return packAmphours_;
}

double BatteryData::packDepthOfDischarge() const
{
    return packDepthOfDischarge_;
}

int BatteryData::highTemperature() const
{
    return highTemperature_;
}

int BatteryData::highThermistorId() const
{
    return highThermistorId_;
}

int BatteryData::lowTemperature() const
{
    return lowTemperature_;
}

int BatteryData::lowThermistorId() const
{
    return lowThermistorId_;
}

int BatteryData::averageTemperature() const
{
    return averageTemperature_;
}

int BatteryData::internalTemperature() const
{
    return internalTemperature_;
}

int BatteryData::fanSpeed() const
{
    return fanSpeed_;
}

int BatteryData::requestedFanSpeed() const
{
    return requestedFanSpeed_;
}

int BatteryData::lowCellVoltage() const
{
    return lowCellVoltage_;
}

int BatteryData::lowCellVoltageId() const
{
    return lowCellVoltageId_;
}

int BatteryData::highCellVoltage() const
{
    return highCellVoltage_;
}

int BatteryData::highCellVoltageId() const
{
    return highCellVoltageId_;
}

int BatteryData::averageCellVoltage() const
{
    return averageCellVoltage_;
}

double BatteryData::packNetPower() const
{
    return packNetPower_;
}

// ------ data setter ------ //

void BatteryData::setAlive(const bool& alive)
{
    alive_ = alive;
    emit aliveReceived(alive_);
}

void BatteryData::setBmsRelayStatus(const BmsRelayStatusFlags& bmsRelayStatus)
{
    bmsRelayStatus_ = bmsRelayStatus;
    emit bmsRelayStatusReceived(bmsRelayStatus_);
}

void BatteryData::setPopulatedCells(const int& populatedCells)
{
    populatedCells_ = populatedCells;
    emit populatedCellsReceived(populatedCells_);
}

void BatteryData::setInputVoltage12V(const double& inputVoltage12V)
{
    inputVoltage12V_ = inputVoltage12V;
    emit inputVoltage12VReceived(inputVoltage12V_);
}

void BatteryData::setFanVoltage(const double& fanVoltage)
{
    fanVoltage_ = fanVoltage;
    emit fanVoltageReceived(fanVoltage_);
}

void BatteryData::setPackCurrent(const double& packCurrent)
{
    packCurrent_ = packCurrent;
    packNetPower_ = packVoltage_ * packCurrent;
    emit packCurrentReceived(packCurrent_);
    emit packNetPowerReceived(packNetPower_);
}

void BatteryData::setPackVoltage(const double& packVoltage)
{
    packVoltage_ = packVoltage;
    packNetPower_ = packVoltage * packCurrent_;
    emit packVoltageReceived(packVoltage_);
    emit packNetPowerReceived(packNetPower_);
}

void BatteryData::setPackStateOfCharge(const double& packStateOfCharge)
{
    packStateOfCharge_ = packStateOfCharge;
    emit packStateOfChargeReceived(packStateOfCharge_);
}

void BatteryData::setPackAmphours(const double& packAmphours)
{
    packAmphours_ = packAmphours;
    emit packAmphoursReceived(packAmphours_);
}

void BatteryData::setPackDepthOfDischarge(const double& packDepthOfDischarge)
{
    packDepthOfDischarge_ = packDepthOfDischarge;
    emit packDepthOfDischargeReceived(packDepthOfDischarge_);
}

void BatteryData::setHighTemperature(const int& highTemperature)
{
    highTemperature_ = highTemperature;
    emit highTemperatureReceived(highTemperature_);
}

void BatteryData::setHighThermistorId(const int& highThermistorId)
{
    highThermistorId_ = highThermistorId;
    emit highThermistorIdReceived(highThermistorId_);
}

void BatteryData::setLowTemperature(const int& lowTemperature)
{
    lowTemperature_ = lowTemperature;
    emit lowTemperatureReceived(lowTemperature_);
}

void BatteryData::setLowThermistorId(const int& lowThermistorId)
{
    lowThermistorId_ = lowThermistorId;
    emit lowThermistorIdReceived(lowThermistorId_);
}

void BatteryData::setAverageTemperature(const int& averageTemperature)
{
    averageTemperature_ = averageTemperature;
    emit averageTemperatureReceived(averageTemperature_);
}

void BatteryData::setInternalTemperature(const int& internalTemperature)
{
    internalTemperature_ = internalTemperature;
    emit internalTemperatureReceived(internalTemperature_);
}

void BatteryData::setFanSpeed(const int& fanSpeed)
{
    fanSpeed_ = fanSpeed;
    emit fanSpeedReceived(fanSpeed_);
}

void BatteryData::setRequestedFanSpeed(const int& requestedFanSpeed)
{
    requestedFanSpeed_ = requestedFanSpeed;
    emit requestedFanSpeedReceived(requestedFanSpeed_);
}

void BatteryData::setLowCellVoltage(const float& lowCellVoltage)
{
    lowCellVoltage_ = lowCellVoltage;
    emit lowCellVoltageReceived(lowCellVoltage_);
}

void BatteryData::setLowCellVoltageId(const int& lowCellVoltageId)
{
    lowCellVoltageId_ = lowCellVoltageId;
    emit lowCellVoltageIdReceived(lowCellVoltageId_);
}

void BatteryData::setHighCellVoltage(const float& highCellVoltage)
{
    highCellVoltage_ = highCellVoltage;
    emit highCellVoltageReceived(highCellVoltage_);
}

void BatteryData::setHighCellVoltageId(const int& highCellVoltageId)
{
    highCellVoltageId_ = highCellVoltageId;
    emit highCellVoltageIdReceived(highCellVoltageId_);
}

void BatteryData::setAverageCellVoltage(const float& averageCellVoltage)
{
    averageCellVoltage_ = averageCellVoltage;
    emit averageCellVoltageReceived(averageCellVoltage_);
}
