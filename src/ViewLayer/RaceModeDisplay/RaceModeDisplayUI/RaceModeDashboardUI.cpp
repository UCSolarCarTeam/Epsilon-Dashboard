#include "RaceModeDashboardUI.h"
#include "ui_RaceModeDashboardUI.h"

RaceModeDashboardUI::RaceModeDashboardUI()
    : ui_(new Ui::RaceModeDashboardUI)
{
    ui_->setupUi(this);
}

RaceModeDashboardUI::~RaceModeDashboardUI()
{
    delete ui_;
}

QLabel& RaceModeDashboardUI::actualSpeedLabel()
{
    return *ui_->actualSpeedLabel;
}

QLabel& RaceModeDashboardUI::auxVoltageLabel()
{
    return *ui_->auxVoltageLabel;
}

QLabel& RaceModeDashboardUI::setCurrentLabel()
{
    return *ui_->setCurrentLabel;
}

QLabel& RaceModeDashboardUI::motorPowerLabel()
{
    return *ui_->motorPowerLabel;
}

QLabel& RaceModeDashboardUI::batteryFaultsLabel()
{
    return *ui_->batteryFaultsLabel;
}

QLabel& RaceModeDashboardUI::motorFaultsLabel()
{
    return *ui_->motorFaultsLabel;
}

QWidget& RaceModeDashboardUI::leftTurnSignalWidget()
{
    return *ui_->leftTurnSignalWidget;
}

QWidget& RaceModeDashboardUI::rightTurnSignalWidget()
{
    return *ui_->rightTurnSignalWidget;
}

QWidget& RaceModeDashboardUI::motorResetButtonWidget()
{
    return *ui_->motorResetButtonWidget;
}

QProgressBar& RaceModeDashboardUI::stateOfChargeCapacityWidget()
{
    return *ui_->stateOfChargeCapacityWidget;
}

QWidget& RaceModeDashboardUI::prechargeStateIconWidget()
{
    return *ui_->prechargeStateIconWidget;
}

QLabel& RaceModeDashboardUI::prechargeStateLabel()
{
    return *ui_->prechargeStateLabel;
}

QWidget& RaceModeDashboardUI::lowHeadlightIndicatorWidget()
{
    return *ui_->lowHeadlightIndicatorWidget;
}

QWidget& RaceModeDashboardUI::highHeadlightIndicatorWidget()
{
    return *ui_->highHeadlightIndicatorWidget;
}

QWidget& RaceModeDashboardUI::thermometerWidget()
{
    return *ui_->thermometerWidget;
}

QLabel& RaceModeDashboardUI::maxCellTemperatureLabel()
{
    return *ui_->maxCellTemperatureLabel;
}

QLabel& RaceModeDashboardUI::avgCellTemperatureLabel()
{
    return *ui_->avgCellTemperatureLabel;
}

QLabel& RaceModeDashboardUI::lowestCellVoltageLabel()
{
    return *ui_->lowestCellVoltageLabel;
}

QLabel& RaceModeDashboardUI::avgCellVoltageLabel()
{
    return *ui_->avgCellVoltageLabel;
}

QLabel& RaceModeDashboardUI::busVoltageLabel()
{
    return *ui_->busVoltageLabel;
}

QLabel& RaceModeDashboardUI::busCurrentLabel()
{
    return *ui_->busCurrentLabel;
}

QLabel& RaceModeDashboardUI::powerInLabel()
{
    return *ui_->powerInLabel;
}

QLabel& RaceModeDashboardUI::powerOutLabel()
{
    return *ui_->powerOutLabel;
}

QLabel& RaceModeDashboardUI::netPowerLabel()
{
    return *ui_->netPowerLabel;
}
