#pragma once

#include "I_RaceModeDashboardUI.h"

class FontLoader;

namespace Ui
{
    class RaceModeDashboardUI;
}
class RaceModeDashboardUI : public I_RaceModeDashboardUI
{
    Q_OBJECT

public:
    explicit RaceModeDashboardUI(bool isWindowed);
    ~RaceModeDashboardUI();


    QWidget& raceModeDashboard();

    QLabel& actualSpeedLabel();

    QLabel& auxVoltageLabel();

    QLabel& motorZeroSetCurrentLabel();
    QLabel& motorOneSetCurrentLabel();
    QLabel& motorZeroPowerLabel();
    QLabel& motorZeroPowerUnitsLabel();
    QLabel& motorOnePowerLabel();
    QLabel& motorOnePowerUnitsLabel();

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

    QLabel& highCellTemperatureLabel();
    QLabel& avgCellTemperatureLabel();
    QLabel& lowestCellVoltageLabel();
    QLabel& highCellVoltageLabel();

    QLabel& motorZeroBusVoltageLabel();
    QLabel& motorOneBusVoltageLabel();
    QLabel& motorZeroBusCurrentLabel();
    QLabel& motorOneBusCurrentLabel();

    QLabel& arrayPowerLabel();
    QLabel& batteryPowerLabel();

    QLabel& driveModeValueLabel();
private:
    Ui::RaceModeDashboardUI* ui_;
    QScopedPointer<FontLoader> fontLoader_;
};
