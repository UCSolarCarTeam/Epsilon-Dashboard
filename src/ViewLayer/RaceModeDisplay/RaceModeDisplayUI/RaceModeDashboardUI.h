#pragma once

#include "I_RaceModeDashboardUI.h"

namespace Ui
{
    class RaceModeDashboardUI;
}
class RaceModeDashboardUI : public I_RaceModeDashboardUI
{
    Q_OBJECT

public:
    explicit RaceModeDashboardUI();
    ~RaceModeDashboardUI();


    QLabel& actualSpeedLabel();

    QLabel& auxVoltageLabel();

    QLabel& setCurrentLabel();
    QLabel& motorPowerLabel();

    QLabel& batteryFaultsLabel();
    QWidget& motorFaultsWidget();
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
    Ui::RaceModeDashboardUI* ui_;
};
