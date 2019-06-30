#pragma once

#include <QLabel>
#include <QProgressBar>

class I_RaceModeDashboardUI : public QWidget
{
    Q_OBJECT
public:
    virtual ~I_RaceModeDashboardUI() {}

    virtual QLabel& actualSpeedLabel() = 0;

    virtual QLabel& auxVoltageLabel() = 0;

    virtual QLabel& motorZeroSetCurrentLabel() = 0;
    virtual QLabel& motorOneSetCurrentLabel() = 0;
    virtual QLabel& motorZeroPowerLabel() = 0;
    virtual QLabel& motorOnePowerLabel() = 0;

    virtual QLabel& batteryFaultsLabel() = 0;
    virtual QLabel& motorZeroFaultsLabel() = 0;
    virtual QLabel& motorOneFaultsLabel() = 0;

    virtual QWidget& leftTurnSignalWidget() = 0;
    virtual QWidget& rightTurnSignalWidget() = 0;

    virtual QWidget& motorResetButtonWidget() = 0;

    virtual QProgressBar& stateOfChargeCapacityWidget() = 0;
    virtual QLabel& prechargeStateLabel() = 0;

    virtual QWidget& lowHeadlightIndicatorWidget() = 0;
    virtual QWidget& highHeadlightIndicatorWidget() = 0;

    virtual QLabel& maxCellTemperatureLabel() = 0;
    virtual QLabel& avgCellTemperatureLabel() = 0;
    virtual QLabel& lowestCellVoltageLabel() = 0;
    virtual QLabel& highCellVoltageLabel() = 0;

    virtual QLabel& motorZeroBusVoltageLabel() = 0;
    virtual QLabel& motorOneBusVoltageLabel() = 0;
    virtual QLabel& motorZeroBusCurrentLabel() = 0;
    virtual QLabel& motorOneBusCurrentLabel() = 0;

    virtual QLabel& arrayPowerLabel() = 0;
    virtual QLabel& batteryPowerLabel() = 0;

    virtual QLabel& driveModeValueLabel() = 0;
};
