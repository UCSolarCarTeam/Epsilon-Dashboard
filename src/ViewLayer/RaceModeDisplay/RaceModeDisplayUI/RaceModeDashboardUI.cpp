#include "RaceModeDashboardUI.h"
#include "ui_RaceModeDashboardUI.h"
#include "FontLoader/FontLoader.h"

#include <QDesktopWidget>
#include <QApplication>

RaceModeDashboardUI::RaceModeDashboardUI(bool isWindowed)
    : ui_(new Ui::RaceModeDashboardUI)
    , fontLoader_(new FontLoader())
{
    ui_->setupUi(this);

    if (!isWindowed)
    {
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    }

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignRight,
            size(),
            QApplication::desktop()->screenGeometry()
        )
    );
    //Font loading
    ui_->actualSpeedLabel->setFont(fontLoader_->loadFont(Font::LCD, 45, true));
    ui_->stateOfChargeCapacityWidget->setFont(fontLoader_->loadFont(Font::LCD, 20, false));

    show();
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

QLabel& RaceModeDashboardUI::motorZeroSetCurrentLabel()
{
    return *ui_->motorZeroSetCurrentLabel;
}

QLabel& RaceModeDashboardUI::motorOneSetCurrentLabel()
{
    return *ui_->motorOneSetCurrentLabel;
}

QLabel& RaceModeDashboardUI::motorZeroPowerLabel()
{
    return *ui_->motorZeroPowerLabel;
}

QLabel& RaceModeDashboardUI::motorOnePowerLabel()
{
    return *ui_->motorOnePowerLabel;
}

QLabel& RaceModeDashboardUI::batteryFaultsLabel()
{
    return *ui_->batteryFaultsLabel;
}

QLabel& RaceModeDashboardUI::motorZeroFaultsLabel()
{
    return *ui_->motorZeroFaultsLabel;
}

QLabel& RaceModeDashboardUI::motorOneFaultsLabel()
{
    return *ui_->motorOneFaultsLabel;
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

QLabel& RaceModeDashboardUI::motorZeroBusVoltageLabel()
{
    return *ui_->motorZeroBusVoltageLabel;
}

QLabel& RaceModeDashboardUI::motorOneBusVoltageLabel()
{
    return *ui_->motorOneBusVoltageLabel;
}

QLabel& RaceModeDashboardUI::motorZeroBusCurrentLabel()
{
    return *ui_->motorZeroBusCurrentLabel;
}

QLabel& RaceModeDashboardUI::motorOneBusCurrentLabel()
{
    return *ui_->motorOneBusCurrentLabel;
}

QLabel& RaceModeDashboardUI::arrayPowerLabel()
{
    return *ui_->arrayPowerLabel;
}

QLabel& RaceModeDashboardUI::batteryPowerLabel()
{
    return *ui_->batteryPowerLabel;
}

QLabel& RaceModeDashboardUI::driveModeValueLabel()
{
    return *ui_->driveModeValueLabel;
}

