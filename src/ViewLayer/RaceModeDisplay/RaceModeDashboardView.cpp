#include "RaceModeDashboardView.h"
#include "../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../PresenterLayer/AuxBmsPresenter/AuxBmsPresenter.h"
#include "../../PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h"
#include "../../PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h"
#include "../../PresenterLayer/LightsPresenter/LightsPresenter.h"
#include "../../PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "../../PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "../../PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "../RaceModeDisplay/RaceModeDisplayUI/I_RaceModeDashboardUI.h"

namespace
{
    const double RED_SLOPE = -1;
    const int RED_INITIAL = 220;
    const double GREEN_SLOPE = 1.7;
    const int GREEN_INITIAL = 10;
    const int BLUE_INITIAL = 20;
    const QString DEFAULT_STYLESHEET = "QProgressBar:horizontal {\
            border: 1px solid white;\
            border-radius: 7px;\
            background: black;\
            }\
            QProgressBar::chunk:horizontal{\
            border-radius: 7px;\
            background: ";
    const QString TEMPERATURE_UNIT = "<sup>o</sup>";
    const float MV_TO_V = 1000;
}

RaceModeDashboardView::RaceModeDashboardView(BatteryPresenter& batteryPresenter,
        BatteryFaultsPresenter& batteryFaultsPresenter,
        AuxBmsPresenter& auxBmsPresenter,
        DriverControlsPresenter& driverControlsPresenter,
        KeyMotorPresenter& keyMotorPresenter,
        LightsPresenter& lightsPresenter,
        MpptPresenter& mpptPresenter,
        MotorDetailsPresenter& motorDetailsPresenter,
        MotorFaultsPresenter& motorFaultsPresenter,
        I_RaceModeDashboardUI& ui,
        MotorFaultList& motorZeroFaultsList,
        MotorFaultList& motorOneFaultsList,
        BatteryFaultList& batteryFaultsList)
    : batteryPresenter_(batteryPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , auxBmsPresenter_(auxBmsPresenter)
    , driverControlsPresenter_(driverControlsPresenter)
    , keyMotorPresenter_(keyMotorPresenter)
    , lightsPresenter_(lightsPresenter)
    , mpptPresenter_(mpptPresenter)
    , motorDetailsPresenter_(motorDetailsPresenter)
    , motorFaultsPresenter_(motorFaultsPresenter)
    , ui_(ui)
    , motorZeroFaultsList_(motorZeroFaultsList)
    , motorOneFaultsList_(motorOneFaultsList)
    , batteryFaultsList_(batteryFaultsList)
{
    connectBattery(batteryPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);
    connectAuxBms(auxBmsPresenter_);
    connectDriverControls(driverControlsPresenter_);
    connectKeyMotor(keyMotorPresenter_);
    connectLights(lightsPresenter_);
    connectMppt(mpptPresenter_);
    connectMotorDetails(motorDetailsPresenter_);
    connectMotorFaults(motorFaultsPresenter_);
    //ui_.showMaximized();
    ui_.show();
}
RaceModeDashboardView::~RaceModeDashboardView()
{
}

void RaceModeDashboardView::connectBattery(BatteryPresenter& batteryPresenter)
{
    connect(&batteryPresenter, SIGNAL(aliveReceived(bool)),
            this, SLOT(aliveReceived(bool)));
    connect(&batteryPresenter, SIGNAL(packNetPowerReceived(double)),
            this, SLOT(packNetPowerReceived(double)));
    connect(&batteryPresenter, SIGNAL(packStateOfChargeReceived(double)),
            this, SLOT(packStateOfChargeReceived(double)));
    connect(&batteryPresenter, SIGNAL(lowCellVoltageReceived(float)),
            this, SLOT(lowCellVoltageReceived(float)));
    connect(&batteryPresenter, SIGNAL(averageCellVoltageReceived(float)),
            this, SLOT(averageCellVoltageReceived(float)));
    connect(&batteryPresenter, SIGNAL(highTemperatureReceived(int)),
            this, SLOT(highTemperatureReceived(int)));
    connect(&batteryPresenter, SIGNAL(averageTemperatureReceived(int)),
            this, SLOT(averageTemperatureReceived(int)));
}

void RaceModeDashboardView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
}

void RaceModeDashboardView::connectAuxBms(AuxBmsPresenter& auxBmsPresenter)
{
    connect(&auxBmsPresenter, SIGNAL(prechargeStateReceived(QString)),
            this, SLOT(prechargeStateReceived(QString)));
    connect(&auxBmsPresenter, SIGNAL(auxVoltageReceived(int)),
            this, SLOT(auxVoltageReceived(int)));
}

void RaceModeDashboardView::connectDriverControls(DriverControlsPresenter& driverControlsPresenter)
{
    connect(&driverControlsPresenter, SIGNAL(resetReceived(bool)),
            this, SLOT(resetReceived(bool)));
}

void RaceModeDashboardView::connectKeyMotor(KeyMotorPresenter& keyMotorPresenter)
{
    connect(&keyMotorPresenter, SIGNAL(motorSetCurrentReceived(double)),
            this, SLOT(motorSetCurrentReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorActualSpeedReceived(double)),
            this, SLOT(motorActualSpeedReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorBusVoltageReceived(double)),
            this, SLOT(motorBusVoltageReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorBusCurrentReceived(double)),
            this, SLOT(motorBusCurrentReceived(double)));
}

void RaceModeDashboardView::connectLights(LightsPresenter& lightsPresenter)
{
    connect(&lightsPresenter, SIGNAL(lowBeamsReceived(bool)),
            this, SLOT(lowBeamsReceived(bool)));
    connect(&lightsPresenter, SIGNAL(highBeamsReceived(bool)),
            this, SLOT(highBeamsReceived(bool)));
    connect(&lightsPresenter, SIGNAL(leftSignalReceived(bool)),
            this, SLOT(leftSignalReceived(bool)));
    connect(&lightsPresenter, SIGNAL(rightSignalReceived(bool)),
            this, SLOT(rightSignalReceived(bool)));
    connect(&lightsPresenter, SIGNAL(lightAliveReceived(bool)),
            this, SLOT(lightAliveReceived(bool)));
}

void RaceModeDashboardView::connectMppt(MpptPresenter& mpptPresenter)
{
    connect(&mpptPresenter, SIGNAL(mpptReceived(int, Mppt)),
            this, SLOT(mpptReceived(int, Mppt)));
    connect(&mpptPresenter, SIGNAL(mpptPowerReceived(double)),
            this, SLOT(mpptPowerReceived(double)));
}

void RaceModeDashboardView::connectMotorDetails(MotorDetailsPresenter& motorDetailsPresenter)
{
}

void RaceModeDashboardView::connectMotorFaults(MotorFaultsPresenter& motorFaultsPresenter)
{
    connect(&motorFaultsPresenter, SIGNAL(motorZeroErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorZeroErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorZeroLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorZeroLimitFlagsReceived(LimitFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorOneErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorOneLimitFlagsReceived(LimitFlags)));
}

void RaceModeDashboardView::updateFaultLabel(QLabel& dashboardLabel, FaultLabel faultLabel)
{
    if (faultLabel.priority() >= 0)
    {
        dashboardLabel.setStyleSheet(QString("font: 10pt \"Burlingame Pro\";\n color:%1").arg(faultLabel.color().name()));
        dashboardLabel.setText(faultLabel.text());
    }
    else
    {
        dashboardLabel.setText("");
    }
}

void RaceModeDashboardView::aliveReceived(bool)
{
}

void RaceModeDashboardView::prechargeStateReceived(QString prechargeState)
{
    ui_.prechargeStateLabel().setText(prechargeState);
}

void RaceModeDashboardView::packNetPowerReceived(double netPower)
{
    ui_.netPowerLabel().setText(QString::number(netPower, 'f', 1));
    ui_.powerOutLabel().setText(QString::number(qAbs(netPower - ui_.powerInLabel().text().toDouble()), 'f', 1));
}

void RaceModeDashboardView::auxVoltageReceived(int auxVoltage)
{
    ui_.auxVoltageLabel().setText(QString::number(auxVoltage, 'f', 2));
}

void RaceModeDashboardView::packStateOfChargeReceived(double stateOfCharge)
{
    ui_.stateOfChargeCapacityWidget().setValue(stateOfCharge);
}

void RaceModeDashboardView::lowCellVoltageReceived(float lowVoltage)
{
    ui_.lowestCellVoltageLabel().setText(QString::number(lowVoltage / MV_TO_V, 'f', 2));
}

void RaceModeDashboardView::averageCellVoltageReceived(float averageVoltage)
{
    ui_.avgCellVoltageLabel().setText(QString::number(averageVoltage / MV_TO_V, 'f', 2));
}

void RaceModeDashboardView::highTemperatureReceived(int highTemp)
{
    ui_.maxCellTemperatureLabel().setText(QString::number(highTemp) + " " + TEMPERATURE_UNIT);
}

void RaceModeDashboardView::averageTemperatureReceived(int avgTemp)
{
    ui_.avgCellTemperatureLabel().setText(QString::number(avgTemp) + " " + TEMPERATURE_UNIT);
}

void RaceModeDashboardView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
    batteryFaultsList_.updateErrors(batteryErrorFlags);
    updateFaultLabel(ui_.batteryFaultsLabel(), batteryFaultsList_.getHighestActivePriorityLabel());
}
void RaceModeDashboardView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
    batteryFaultsList_.updateLimits(batteryLimitFlags);
    updateFaultLabel(ui_.batteryFaultsLabel(), batteryFaultsList_.getHighestActivePriorityLabel());
}
void RaceModeDashboardView::resetReceived(bool reset)
{
    if (reset)
    {
        ui_.motorResetButtonWidget().setStyleSheet("background: url(:/Resources/MotorResetButton.png)");
    }
    else
    {
        ui_.motorResetButtonWidget().setStyleSheet("");
    }
}
void RaceModeDashboardView::motorSetCurrentReceived(double setCurrent)
{
    ui_.setCurrentLabel().setText(QString::number(setCurrent, 'f', 3));
}
void RaceModeDashboardView::motorActualSpeedReceived(double actualSpeed)
{
    ui_.actualSpeedLabel().setText(QString::number(actualSpeed, 'f', 1));
}
void RaceModeDashboardView::motorBusVoltageReceived(double busVoltage)
{
    ui_.busVoltageLabel().setText(QString::number(busVoltage, 'f', 2));
    busVoltage_ = busVoltage;
    setMotorPower();
}
void RaceModeDashboardView::motorBusCurrentReceived(double busCurrent)
{
    ui_.busCurrentLabel().setText(QString::number(busCurrent, 'f', 2));
    busCurrent_ = busCurrent;
    setMotorPower();
}

void RaceModeDashboardView::setMotorPower()
{
    ui_.motorPowerLabel().setText(QString::number((busVoltage_ * busCurrent_), 'f', 2));
}

void RaceModeDashboardView::lowBeamsReceived(bool lowBeams)
{
    if (lowBeams)
    {
        ui_.lowHeadlightIndicatorWidget().setStyleSheet("border-image: url(:/Resources/LowHeadlightIndicator.png) 0 0 0 0 stretch stretch");
    }
    else
    {
        ui_.lowHeadlightIndicatorWidget().setStyleSheet("");
    }
}
void RaceModeDashboardView::highBeamsReceived(bool highBeams)
{
    if (highBeams)
    {
        ui_.highHeadlightIndicatorWidget().setStyleSheet("border-image: url(:/Resources/HighHeadlightIndicator.png) 0 0 0 0 stretch stretch");
    }
    else
    {
        ui_.highHeadlightIndicatorWidget().setStyleSheet("");
    }
}
void RaceModeDashboardView::leftSignalReceived(bool leftSignal)
{
    if (leftSignal)
    {
        ui_.leftTurnSignalWidget().setStyleSheet("border-image: url(:/Resources/TurnSignalLeft.png) 0 0 0 0 stretch stretch;");
    }
    else
    {
        ui_.leftTurnSignalWidget().setStyleSheet("");
    }
}
void RaceModeDashboardView::rightSignalReceived(bool rightSignal)
{
    if (rightSignal)
    {
        ui_.rightTurnSignalWidget().setStyleSheet("border-image: url(:/Resources/TurnSignalRight.png) 0 0 0 0 stretch stretch;");
    }
    else
    {
        ui_.rightTurnSignalWidget().setStyleSheet("");
    }
}
void RaceModeDashboardView::lightAliveReceived(bool)
{

}

void RaceModeDashboardView::mpptReceived(int i, Mppt mppt)
{
    if (i == 0)
    {
        mpptZeroPower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }

    else if (i == 1)
    {
        mpptOnePower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }

    else if (i == 2)
    {
        mpptTwoPower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }
    else if (i == 3)
    {
        mpptThreePower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }

    mpptPowerReceived(mpptZeroPower_ + mpptOnePower_ + mpptTwoPower_ + mpptThreePower_);
}

void RaceModeDashboardView::mpptPowerReceived(double mpptPower)
{
    ui_.powerInLabel().setText(QString::number(mpptPower, 'f', 1));
    ui_.powerOutLabel().setText(QString::number(qAbs(ui_.netPowerLabel().text().toDouble() - mpptPower), 'f', 1));
}

void RaceModeDashboardView::motorZeroErrorFlagsReceived(ErrorFlags flags)
{
    motorZeroFaultsList_.updateErrors(flags);
    updateFaultLabel(ui_.motorZeroFaultsLabel(), motorZeroFaultsList_.getHighestActivePriorityLabel());
}

void RaceModeDashboardView::motorZeroLimitFlagsReceived(LimitFlags flags)
{
    motorZeroFaultsList_.updateLimits(flags);
    updateFaultLabel(ui_.motorZeroFaultsLabel(), motorZeroFaultsList_.getHighestActivePriorityLabel());
}

void RaceModeDashboardView::motorOneErrorFlagsReceived(ErrorFlags flags)
{
    motorOneFaultsList_.updateErrors(flags);
    updateFaultLabel(ui_.motorOneFaultsLabel(), motorOneFaultsList_.getHighestActivePriorityLabel());
}

void RaceModeDashboardView::motorOneLimitFlagsReceived(LimitFlags flags)
{
    motorOneFaultsList_.updateLimits(flags);
    updateFaultLabel(ui_.motorOneFaultsLabel(), motorOneFaultsList_.getHighestActivePriorityLabel());
}
