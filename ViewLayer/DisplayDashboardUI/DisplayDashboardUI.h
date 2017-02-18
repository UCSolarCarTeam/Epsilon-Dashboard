#pragma once

#include <QLabel>
#include <QProgressBar>

namespace Ui
{
    class DisplayDashboardUI;
}
class DisplayDashboardUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayDashboardUI();
    ~DisplayDashboardUI();

    QLabel& actualSpeedLabel();

    QLabel& array0VoltageLabel();
    QLabel& array1VoltageLabel();
    QLabel& array2VoltageLabel();

    QLabel& array0CurrentLabel();
    QLabel& array1CurrentLabel();
    QLabel& array2CurrentLabel();

    QLabel& setCurrentLabel();
    QLabel& motorPowerLabel();

    QLabel& batteryFaultsLabel();
    QLabel& motorFaultsLabel();

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
