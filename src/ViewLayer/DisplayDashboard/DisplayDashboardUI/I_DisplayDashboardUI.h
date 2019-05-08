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

    virtual QLabel& setCurrentLabel() = 0;
    virtual QLabel& motorPowerLabel() = 0;

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
    virtual QWidget& highHeadlightIndicatorWidget() = 0;

    virtual QLabel& maxCellTemperatureLabel() = 0;
    virtual QLabel& avgCellTemperatureLabel() = 0;
    virtual QLabel& lowestCellVoltageLabel() = 0;
    virtual QLabel& avgCellVoltageLabel() = 0;

    virtual QLabel& busVoltageLabel() = 0;
    virtual QLabel& busCurrentLabel() = 0;

    virtual QLabel& powerInLabel() = 0;
    virtual QLabel& powerOutLabel() = 0;
    virtual QLabel& netPowerLabel() = 0;
};
