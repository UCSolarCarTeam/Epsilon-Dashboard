#pragma once

#include "I_DisplayDashboardUI.h"

class FontLoader;

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

    QLabel& motorZeroSetCurrentLabel();
    QLabel& motorOneSetCurrentLabel();
    QLabel& motorOnePowerLabel();
    QLabel& motorZeroPowerLabel();

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

    QLabel& maxCellTemperatureLabel();
    QLabel& avgCellTemperatureLabel();
    QLabel& lowestCellVoltageLabel();
    QLabel& avgCellVoltageLabel();

    QLabel& motorZeroBusVoltageLabel();
    QLabel& motorOneBusVoltageLabel();
    QLabel& motorZeroBusCurrentLabel();
    QLabel& motorOneBusCurrentLabel();

    QLabel& arrayPowerLabel();
    QLabel& batteryPowerLabel();

    QLabel& driveModeValueLabel();

private:
    Ui::DisplayDashboardUI* ui_;
    QScopedPointer<FontLoader> fontLoader_;
};
