#include <QTimer>
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
    const int FAULT_UPDATE_PERIOD = 1500;
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
    , faultsTimer_(new QTimer())
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
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateBatteryFaults()));
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateMotor0Faults()));
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateMotor1Faults()));
    faultsTimer_->start(FAULT_UPDATE_PERIOD);
    ui_.show();
}
RaceModeDashboardView::~RaceModeDashboardView()
{
}

void RaceModeDashboardView::connectBattery(BatteryPresenter& batteryPresenter)
{
    connect(&batteryPresenter, SIGNAL(aliveReceived(bool)),
            this, SLOT(aliveReceived(bool)));
    connect(&batteryPresenter, SIGNAL(packBatteryPowerReceived(double)),
            this, SLOT(packBatteryPowerReceived(double)));
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
    connect(&driverControlsPresenter, SIGNAL(auxReceived(bool)),
            this, SLOT(auxReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(forwardReceived(bool)),
            this, SLOT(forwardReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(reverseReceived(bool)),
            this, SLOT(reverseReceived(bool)));
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
    Q_UNUSED(motorDetailsPresenter);
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
        dashboardLabel.setStyleSheet(QString("color:%1").arg(faultLabel.color().name()));
        dashboardLabel.setText(faultLabel.text());
    }
    else
    {
        dashboardLabel.setText("");
    }
}

void RaceModeDashboardView::updateDriveStateLabel()
{
    if (forward_ && !(reverse_ || aux_))
    {
        ui_.driveModeValueLabel().setText("Drive");
    }
    else if (reverse_ && !(forward_ || aux_))
    {
        ui_.driveModeValueLabel().setText("Reverse");
    }
    else if (aux_ && !(forward_ || reverse_))
    {
        ui_.driveModeValueLabel().setText("Neutral");
    }
    else
    {
        ui_.driveModeValueLabel().setText("Invalid Mode");
    }
}

void RaceModeDashboardView::aliveReceived(bool)
{
}

void RaceModeDashboardView::prechargeStateReceived(QString prechargeState)
{
    ui_.prechargeStateLabel().setText(prechargeState);
}

void RaceModeDashboardView::packBatteryPowerReceived(double BatteryPower)
{
    ui_.batteryPowerLabel().setText(QString::number(BatteryPower, 'f', 1));
}

void RaceModeDashboardView::auxVoltageReceived(int auxVoltage)
{
    ui_.auxVoltageLabel().setText(QString::number(auxVoltage, 'f', 2));
}

void RaceModeDashboardView::packStateOfChargeReceived(double stateOfCharge)
{
    ui_.stateOfChargeCapacityWidget().setValue(stateOfCharge);

    // The rgb values for the progressbar are calculated with the intention of displaying a colour closer to red
    // for low values and a colour closer to green for higher values. These are calculated using linear equations
    // with a slope and intercept.

    // Default colour
    int red = RED_INITIAL;
    int green = GREEN_INITIAL;
    int blue = BLUE_INITIAL;

    // Calculated color
    red += int(RED_SLOPE * stateOfCharge);
    green += int(GREEN_SLOPE * stateOfCharge);

    QString r = QString::number(red);
    QString g = QString::number(green);
    QString b = QString::number(blue);

    QString rgb = QString("rgb(%1,%2,%3);").arg(r, g, b);

    ui_.stateOfChargeCapacityWidget().setStyleSheet(DEFAULT_STYLESHEET + rgb + "}");
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
}
void RaceModeDashboardView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
    batteryFaultsList_.updateLimits(batteryLimitFlags);
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

void RaceModeDashboardView::auxReceived(bool aux)
{
    aux_ = aux;
    updateDriveStateLabel();
}

void RaceModeDashboardView::forwardReceived(bool forward)
{
    forward_ = forward;
    updateDriveStateLabel();
}

void RaceModeDashboardView::reverseReceived(bool reverse)
{
    reverse_ = reverse;
    updateDriveStateLabel();
}
void RaceModeDashboardView::motorSetCurrentReceived(double setCurrent)
{
    ui_.setCurrentLabel().setText(QString::number(setCurrent * 100, 'f', 2));
}
void RaceModeDashboardView::motorActualSpeedReceived(double actualSpeed)
{
    ui_.actualSpeedLabel().setText(QString::number(qAbs(actualSpeed), 'f', 1));
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
    ui_.arrayPowerLabel().setText(QString::number(mpptPower, 'f', 1));
}

void RaceModeDashboardView::motorZeroErrorFlagsReceived(ErrorFlags flags)
{
    motorZeroFaultsList_.updateErrors(flags);
}

void RaceModeDashboardView::motorZeroLimitFlagsReceived(LimitFlags flags)
{
    motorZeroFaultsList_.updateLimits(flags);
}

void RaceModeDashboardView::motorOneErrorFlagsReceived(ErrorFlags flags)
{
    motorOneFaultsList_.updateErrors(flags);
}

void RaceModeDashboardView::motorOneLimitFlagsReceived(LimitFlags flags)
{
    motorOneFaultsList_.updateLimits(flags);
}

void RaceModeDashboardView::updateBatteryFaults()
{
    updateFaultLabel(ui_.batteryFaultsLabel(), batteryFaultsList_.nextActiveFault());
}

void RaceModeDashboardView::updateMotor0Faults()
{
    updateFaultLabel(ui_.motorZeroFaultsLabel(), motorZeroFaultsList_.nextActiveFault());
}

void RaceModeDashboardView::updateMotor1Faults()
{
    updateFaultLabel(ui_.motorOneFaultsLabel(), motorOneFaultsList_.nextActiveFault());
}
