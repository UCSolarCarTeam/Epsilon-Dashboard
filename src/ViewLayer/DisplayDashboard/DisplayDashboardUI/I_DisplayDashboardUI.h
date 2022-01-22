#pragma once

#include <QLabel>
#include <QProgressBar>

class I_DisplayDashboardUI : public QWidget
{
    Q_OBJECT
public:
    virtual ~I_DisplayDashboardUI() {}

    virtual QLabel& actualSpeedLabel() = 0;

    virtual QLabel& array0VoltageLabel() = 0;
    virtual QLabel& array1VoltageLabel() = 0;
    virtual QLabel& array2VoltageLabel() = 0;
    virtual QLabel& array3VoltageLabel() = 0;

    virtual QLabel& array0CurrentLabel() = 0;
    virtual QLabel& array1CurrentLabel() = 0;
    virtual QLabel& array2CurrentLabel() = 0;
    virtual QLabel& array3CurrentLabel() = 0;

    virtual QLabel& motorZeroSetCurrentLabel() = 0;
    virtual QLabel& motorOneSetCurrentLabel() = 0;
    virtual QLabel& motorZeroPowerLabel() = 0;
    virtual QLabel& motorZeroPowerUnitsLabel() = 0;
    virtual QLabel& motorOnePowerLabel() = 0;
    virtual QLabel& motorOnePowerUnitsLabel() = 0;

    virtual QLabel& batteryFaultsLabel() = 0;
    virtual QLabel& motorZeroFaultsLabel() = 0;
    virtual QLabel& motorOneFaultsLabel() = 0;

    virtual QWidget& leftTurnSignalWidget() = 0;
    virtual QWidget& rightTurnSignalWidget() = 0;

    virtual QWidget& motorResetButtonWidget() = 0;

    virtual QProgressBar& stateOfChargeCapacityWidget() = 0;

    virtual QWidget& prechargeStateIconWidget() = 0;
    virtual QLabel& prechargeStateLabel() = 0;

    virtual QWidget& lowHeadlightIndicatorWidget() = 0;

    virtual QLabel& highCellTemperatureLabel() = 0;
    virtual QLabel& avgCellTemperatureLabel() = 0;
    virtual QLabel& lowestCellVoltageLabel() = 0;
    virtual QLabel& avgCellVoltageLabel() = 0;

    virtual QLabel& motorZeroBusVoltageLabel() = 0;
    virtual QLabel& motorOneBusVoltageLabel() = 0;
    virtual QLabel& motorZeroBusCurrentLabel() = 0;
    virtual QLabel& motorOneBusCurrentLabel() = 0;

    virtual QLabel& arrayPowerLabel() = 0;
    virtual QLabel& batteryPowerLabel() = 0;

    virtual QLabel& driveModeValueLabel() = 0;
};
