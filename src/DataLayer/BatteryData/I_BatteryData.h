#pragma once

#include "BmsRelayStatusFlags.h"

#include <QObject>
#include <QString>

class I_BatteryData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_BatteryData() {}

    /* Data "Gets" */
    virtual bool alive() const = 0;
    virtual BmsRelayStatusFlags bmsRelayStatus() const = 0;
    virtual int populatedCells() const = 0;
    virtual double inputVoltage12V() const = 0;
    virtual double fanVoltage() const = 0;
    virtual double packCurrent() const = 0;
    virtual double packVoltage() const = 0;
    virtual double packStateOfCharge() const = 0;
    virtual double packAmphours() const = 0;
    virtual double packDepthOfDischarge() const = 0;
    virtual int highTemperature() const = 0;
    virtual int highThermistorId() const = 0;
    virtual int lowTemperature() const = 0;
    virtual int lowThermistorId() const = 0;
    virtual int averageTemperature() const = 0;
    virtual int internalTemperature() const = 0;
    virtual int fanSpeed() const = 0;
    virtual int requestedFanSpeed() const = 0;
    virtual int lowCellVoltage() const = 0;
    virtual int lowCellVoltageId() const = 0;
    virtual int highCellVoltage() const = 0;
    virtual int highCellVoltageId() const = 0;
    virtual int averageCellVoltage() const = 0;
    virtual double packNetPower() const = 0;

    /* Data "Sets" */
    virtual void setAlive(const bool& alive) = 0;
    virtual void setBmsRelayStatus(const BmsRelayStatusFlags&) = 0;
    virtual void setPopulatedCells(const int&) = 0;
    virtual void setInputVoltage12V(const double&) = 0;
    virtual void setFanVoltage(const double&) = 0;
    virtual void setPackCurrent(const double&) = 0;
    virtual void setPackVoltage(const double&) = 0;
    virtual void setPackStateOfCharge(const double&) = 0;
    virtual void setPackAmphours(const double&) = 0;
    virtual void setPackDepthOfDischarge(const double&) = 0;
    virtual void setHighTemperature(const int&) = 0;
    virtual void setHighThermistorId(const int&) = 0;
    virtual void setLowTemperature(const int&) = 0;
    virtual void setLowThermistorId(const int&) = 0;
    virtual void setAverageTemperature(const int&) = 0;
    virtual void setInternalTemperature(const int&) = 0;
    virtual void setFanSpeed(const int&) = 0;
    virtual void setRequestedFanSpeed(const int&) = 0;
    virtual void setLowCellVoltage(const float&) = 0;
    virtual void setLowCellVoltageId(const int&) = 0;
    virtual void setHighCellVoltage(const float&) = 0;
    virtual void setHighCellVoltageId(const int&) = 0;
    virtual void setAverageCellVoltage(const float&) = 0;

signals:
    void aliveReceived(const bool& alive);
    void bmsRelayStatusReceived(BmsRelayStatusFlags);
    void populatedCellsReceived(const int&);
    void inputVoltage12VReceived(const double&);
    void fanVoltageReceived(const double&);
    void packCurrentReceived(const double&);
    void packVoltageReceived(const double&);
    void packStateOfChargeReceived(const double&);
    void packAmphoursReceived(const double&);
    void packDepthOfDischargeReceived(const double&);
    void highTemperatureReceived(const int&);
    void highThermistorIdReceived(const int&);
    void lowTemperatureReceived(const int&);
    void lowThermistorIdReceived(const int&);
    void averageTemperatureReceived(const int&);
    void internalTemperatureReceived(const int&);
    void fanSpeedReceived(const int&);
    void requestedFanSpeedReceived(const int&);
    void lowCellVoltageReceived(const float&);
    void lowCellVoltageIdReceived(const int&);
    void highCellVoltageReceived(const float&);
    void highCellVoltageIdReceived(const int&);
    void averageCellVoltageReceived(const float&);
    void packNetPowerReceived(const double&);
};
