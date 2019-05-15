#pragma once

#include "I_DisplayDashboardUI.h"

namespace Ui
{
    class DisplayDashboardUI;
}
class DisplayDashboardUI : public I_DisplayDashboardUI
{
    Q_OBJECT

public:
    explicit DisplayDashboardUI(bool isWindowed);
    ~DisplayDashboardUI();

    QLabel& actualSpeedLabel();

    QLabel& array0VoltageLabel();
    QLabel& array1VoltageLabel();
    QLabel& array2VoltageLabel();
    QLabel& array3VoltageLabel();

    QLabel& array0CurrentLabel();
    QLabel& array1CurrentLabel();
    QLabel& array2CurrentLabel();
    QLabel& array3CurrentLabel();

    QLabel& setCurrentLabel();
    QLabel& motorPowerLabel();

    QLabel& batteryFaultsLabel();
    QLabel& motorZeroFaultsLabel();
    QLabel& motorOneFaultsLabel();

    QWidget& leftTurnSignalWidget();
    QWidget& rightTurnSignalWidget();

    QWidget& motorResetButtonWidget();

    QProgressBar& stateOfChargeCapacityWidget();

    QWidget& prechargeStateIconWidget();
    QLabel& prechargeStateLabel();

    QWidget& lowHeadlightIndicatorWidget();
    QWidget& highHeadlightIndicatorWidget();

    QWidget& thermometerWidget();
    QLabel& maxCellTemperatureLabel();
    QLabel& avgCellTemperatureLabel();
    QLabel& lowestCellVoltageLabel();
    QLabel& avgCellVoltageLabel();

    QLabel& busVoltageLabel();
    QLabel& busCurrentLabel();

    QLabel& powerInLabel();
    QLabel& powerOutLabel();
    QLabel& netPowerLabel();

private:
    Ui::DisplayDashboardUI* ui_;

};
