#pragma once

#include "I_RaceModeDashboardUI.h"
#include "FontLoader/FontLoader.h"

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
    QLabel& motorZeroFaultsLabel();
    QLabel& motorOneFaultsLabel();

    QWidget& leftTurnSignalWidget();
    QWidget& rightTurnSignalWidget();

    QWidget& motorResetButtonWidget();

    QProgressBar& stateOfChargeCapacityWidget();
    QLabel& prechargeStateLabel();

    QWidget& lowHeadlightIndicatorWidget();
    QWidget& highHeadlightIndicatorWidget();

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
    QScopedPointer<FontLoader> fontLoader_;
};
