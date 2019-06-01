#pragma once

#include "I_BatteryData.h"

class BatteryData : public I_BatteryData
{
public:
    BatteryData();
    virtual ~BatteryData();

    /* Data getter */
    bool alive() const;
    BmsRelayStatusFlags bmsRelayStatus() const;
    int populatedCells() const;
    double inputVoltage12V() const;
    double fanVoltage() const;
    double packCurrent() const;
    double packVoltage() const;
    double packStateOfCharge() const;
    double packAmphours() const;
    double packDepthOfDischarge() const;
    int highTemperature() const;
    int highThermistorId() const;
    int lowTemperature() const;
    int lowThermistorId() const;
    int averageTemperature() const;
    int internalTemperature() const;
    int fanSpeed() const;
    int requestedFanSpeed() const;
    int lowCellVoltage() const;
    int lowCellVoltageId() const;
    int highCellVoltage() const;
    int highCellVoltageId() const;
    int averageCellVoltage() const;
    double packBatteryPower() const;

    /* Data setter */
    void setAlive(const bool& alive);
    void setBmsRelayStatus(const BmsRelayStatusFlags& bmsRelayStatus);
    void setPopulatedCells(const int& populatedCells);
    void setInputVoltage12V(const double& inputVoltage12V);
    void setFanVoltage(const double& fanVoltage);
    void setPackCurrent(const double& packCurrent);
    void setPackVoltage(const double& packVoltage);
    void setPackStateOfCharge(const double& packStateOfCharge);
    void setPackAmphours(const double& packAmphours);
    void setPackDepthOfDischarge(const double& packDepthOfDischarge);
    void setHighTemperature(const int& highTemperature);
    void setHighThermistorId(const int& highThermistorId);
    void setLowTemperature(const int& lowTemperature);
    void setLowThermistorId(const int& lowThermistorId);
    void setAverageTemperature(const int& averageTemperature);
    void setInternalTemperature(const int& internalTemperature);
    void setFanSpeed(const int& fanSpeed);
    void setRequestedFanSpeed(const int& requestedFanSpeed);
    void setLowCellVoltage(const float& lowCellVoltage);
    void setLowCellVoltageId(const int& lowCellVoltageId);
    void setHighCellVoltage(const float& highCellVoltage);
    void setHighCellVoltageId(const int& highCellVoltageId);
    void setAverageCellVoltage(const float& averageCellVoltage);

private:
    bool alive_;
    BmsRelayStatusFlags bmsRelayStatus_;
    int populatedCells_;
    double inputVoltage12V_;
    double fanVoltage_;
    double packCurrent_;
    double packVoltage_;
    double packStateOfCharge_;
    double packAmphours_;
    double packDepthOfDischarge_;
    int highTemperature_;
    int highThermistorId_;
    int lowTemperature_;
    int lowThermistorId_;
    int averageTemperature_;
    int internalTemperature_;
    int fanSpeed_;
    int requestedFanSpeed_;
    int lowCellVoltage_;
    int lowCellVoltageId_;
    int highCellVoltage_;
    int highCellVoltageId_;
    int averageCellVoltage_;
    double packBatteryPower_; // calculated based on pack current and voltage
};

