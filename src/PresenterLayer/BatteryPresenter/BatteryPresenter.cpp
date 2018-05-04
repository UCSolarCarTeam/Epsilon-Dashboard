#include "BatteryPresenter.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"

BatteryPresenter::BatteryPresenter(const I_BatteryData& batteryData)
    : batteryData_(batteryData)
{
    relayBatteryData();
}

void BatteryPresenter::relayBatteryData()
{
    connect(&batteryData_, SIGNAL(aliveReceived(const bool&)),
            this, SIGNAL(aliveReceived(bool)));
    connect(&batteryData_, SIGNAL(bmsRelayStatusReceived(BmsRelayStatusFlags)),
            this, SIGNAL(bmsRelayStatusReceived(BmsRelayStatusFlags)));
    connect(&batteryData_, SIGNAL(populatedCellsReceived(const int&)),
            this, SIGNAL(populatedCellsReceived(const int&)));
    connect(&batteryData_, SIGNAL(inputVoltage12VReceived(const double&)),
            this, SIGNAL(inputVoltage12VReceived(const double&)));
    connect(&batteryData_, SIGNAL(fanVoltageReceived(const double&)),
            this, SIGNAL(fanVoltageReceived(const double&)));
    connect(&batteryData_, SIGNAL(packCurrentReceived(const double&)),
            this, SIGNAL(packCurrentReceived(const double&)));
    connect(&batteryData_, SIGNAL(packVoltageReceived(const double&)),
            this, SIGNAL(packVoltageReceived(const double&)));
    connect(&batteryData_, SIGNAL(packStateOfChargeReceived(const double&)),
            this, SIGNAL(packStateOfChargeReceived(const double&)));
    connect(&batteryData_, SIGNAL(packAmphoursReceived(const double&)),
            this, SIGNAL(packAmphoursReceived(const double&)));
    connect(&batteryData_, SIGNAL(packDepthOfDischargeReceived(const double&)),
            this, SIGNAL(packDepthOfDischargeReceived(const double&)));
    connect(&batteryData_, SIGNAL(highTemperatureReceived(const int&)),
            this, SIGNAL(highTemperatureReceived(const int&)));
    connect(&batteryData_, SIGNAL(highThermistorIdReceived(const int&)),
            this, SIGNAL(highThermistorIdReceived(const int&)));
    connect(&batteryData_, SIGNAL(lowTemperatureReceived(const int&)),
            this, SIGNAL(lowTemperatureReceived(const int&)));
    connect(&batteryData_, SIGNAL(lowThermistorIdReceived(const int&)),
            this, SIGNAL(lowThermistorIdReceived(const int&)));
    connect(&batteryData_, SIGNAL(averageTemperatureReceived(const int&)),
            this, SIGNAL(averageTemperatureReceived(const int&)));
    connect(&batteryData_, SIGNAL(internalTemperatureReceived(const int&)),
            this, SIGNAL(internalTemperatureReceived(const int&)));
    connect(&batteryData_, SIGNAL(fanSpeedReceived(const int&)),
            this, SIGNAL(fanSpeedReceived(const int&)));
    connect(&batteryData_, SIGNAL(requestedFanSpeedReceived(const int&)),
            this, SIGNAL(requestedFanSpeedReceived(const int&)));
    connect(&batteryData_, SIGNAL(lowCellVoltageReceived(const int&)),
            this, SIGNAL(lowCellVoltageReceived(const int&)));
    connect(&batteryData_, SIGNAL(lowCellVoltageIdReceived(const int&)),
            this, SIGNAL(lowCellVoltageIdReceived(const int&)));
    connect(&batteryData_, SIGNAL(highCellVoltageReceived(const int&)),
            this, SIGNAL(highCellVoltageReceived(const int&)));
    connect(&batteryData_, SIGNAL(highCellVoltageIdReceived(const int&)),
            this, SIGNAL(highCellVoltageIdReceived(const int&)));
    connect(&batteryData_, SIGNAL(averageCellVoltageReceived(const int&)),
            this, SIGNAL(averageCellVoltageReceived(const int&)));
    connect(&batteryData_, SIGNAL(packNetPowerReceived(const double&)),
            this, SIGNAL(packNetPowerReceived(const double&)));
}
