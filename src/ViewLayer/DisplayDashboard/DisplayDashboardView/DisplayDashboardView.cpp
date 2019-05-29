#include "DisplayDashboardView.h"
#include <QDebug>

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
    const float MV_TO_V = 1000;
}

DisplayDashboardView::DisplayDashboardView(AuxBmsPresenter& auxBmsPresenter,
        BatteryPresenter& batteryPresenter,
        BatteryFaultsPresenter& batteryFaultsPresenter,
        DriverControlsPresenter& driverControlsPresenter,
        KeyMotorPresenter& keyMotorPresenter,
        LightsPresenter& lightsPresenter,
        MpptPresenter& mpptPresenter,
        MotorDetailsPresenter& motorDetailsPresenter,
        MotorFaultsPresenter& motorFaultsPresenter,
        I_DisplayDashboardUI& ui,
        MotorFaultList& motorZeroFaultsList,
        MotorFaultList& motorOneFaultsList,
        BatteryFaultList& batteryFaultsList)
    : auxBmsPresenter_(auxBmsPresenter)
    , batteryPresenter_(batteryPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
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
    connectAuxBms(auxBmsPresenter_);
    connectBattery(batteryPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);
    connectDriverControls(driverControlsPresenter_);
    connectKeyMotor(keyMotorPresenter_);
    connectLights(lightsPresenter_);
    connectMppt(mpptPresenter_);
    connectMotorDetails(motorDetailsPresenter_);
    connectMotorFaults(motorFaultsPresenter_);
    //ui_.showMaximized();
    ui_.show();
}
DisplayDashboardView::~DisplayDashboardView()
{}

void DisplayDashboardView::connectAuxBms(AuxBmsPresenter& auxBmsPresenter)
{
    connect(&auxBmsPresenter, SIGNAL(prechargeStateReceived(QString)),
            this, SLOT(prechargeStateReceived(QString)));
}

void DisplayDashboardView::connectBattery(BatteryPresenter& batteryPresenter)
{
    // TODO update to new battery data (depends on what should be shown in UI)
    connect(&batteryPresenter, SIGNAL(aliveReceived(bool)),
            this, SLOT(aliveReceived(bool)));
    connect(&batteryPresenter, SIGNAL(packNetPowerReceived(double)),
            this, SLOT(packNetPowerReceived(double)));
    connect(&batteryPresenter, SIGNAL(packStateOfChargeReceived(double)),
            this, SLOT(packStateOfChargeReceived(double)));
    connect(&batteryPresenter, SIGNAL(highTemperatureReceived(int)),
            this, SLOT(highTemperatureReceived(int)));
    connect(&batteryPresenter, SIGNAL(lowCellVoltageReceived(float)),
            this, SLOT(lowCellVoltageReceived(float)));
    connect(&batteryPresenter, SIGNAL(averageTemperatureReceived(int)),
            this, SLOT(averageTemperatureReceived(int)));
    connect(&batteryPresenter, SIGNAL(averageCellVoltageReceived(float)),
            this, SLOT(averageCellVoltageReceived(float)));
}

void DisplayDashboardView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
}

void DisplayDashboardView::connectDriverControls(DriverControlsPresenter& driverControlsPresenter)
{
    connect(&driverControlsPresenter, SIGNAL(resetReceived(bool)),
            this, SLOT(resetReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(brakesReceived(bool)),
            this, SLOT(brakesReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(forwardReceived(bool)),
            this, SLOT(forwardReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(reverseReceived(bool)),
            this, SLOT(reverseReceived(bool)));
}

void DisplayDashboardView::connectKeyMotor(KeyMotorPresenter& keyMotorPresenter)
{
    connect(&keyMotorPresenter, SIGNAL(motorSetPowerReceived(double)),
            this, SLOT(motorSetPowerReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorSetCurrentReceived(double)),
            this, SLOT(motorSetCurrentReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorActualSpeedReceived(double)),
            this, SLOT(motorActualSpeedReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorBusVoltageReceived(double)),
            this, SLOT(motorBusVoltageReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorBusCurrentReceived(double)),
            this, SLOT(motorBusCurrentReceived(double)));
}

void DisplayDashboardView::connectLights(LightsPresenter& lightsPresenter)
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

void DisplayDashboardView::connectMppt(MpptPresenter& mpptPresenter)
{
    connect(&mpptPresenter, SIGNAL(mpptReceived(int, Mppt)),
            this, SLOT(mpptReceived(int, Mppt)));
    connect(&mpptPresenter, SIGNAL(mpptPowerReceived(double)),
            this, SLOT(mpptPowerReceived(double)));
}

void DisplayDashboardView::connectMotorDetails(MotorDetailsPresenter& motorDetailsPresenter)
{
    Q_UNUSED(motorDetailsPresenter);
}

void DisplayDashboardView::connectMotorFaults(MotorFaultsPresenter& motorFaultsPresenter)
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

void DisplayDashboardView::updateFaultLabel(QLabel& dashboardLabel, FaultLabel faultLabel)
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

void DisplayDashboardView::updateDriveStateLabel()
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

void DisplayDashboardView::aliveReceived(bool)
{
}
void DisplayDashboardView::prechargeStateReceived(QString prechargeState)
{
    ui_.prechargeStateLabel().setText(prechargeState);
}

void DisplayDashboardView::packNetPowerReceived(double netPower)
{
    ui_.netPowerLabel().setText(QString::number(netPower, 'f', 2));
}

/*
 * TODO UI has to be updated w.r.t. the changes in the protocol
 */
void DisplayDashboardView::packStateOfChargeReceived(double packSocPercentage)
{
    ui_.stateOfChargeCapacityWidget().setValue(packSocPercentage);

    // The rgb values for the progressbar are calculated with the intention of displaying a colour closer to red
    // for low values and a colour closer to green for higher values. These are calculated using linear equations
    // with a slope and intercept.

    // Default colour
    int red = RED_INITIAL;
    int green = GREEN_INITIAL;
    int blue = BLUE_INITIAL;

    // Calculated color
    red += int(RED_SLOPE * packSocPercentage);
    green += int(GREEN_SLOPE * packSocPercentage);

    QString r = QString::number(red);
    QString g = QString::number(green);
    QString b = QString::number(blue);

    QString rgb = QString("rgb(%1,%2,%3);").arg(r, g, b);

    ui_.stateOfChargeCapacityWidget().setStyleSheet(DEFAULT_STYLESHEET + rgb + "}");
}
void DisplayDashboardView::highTemperatureReceived(int maxCellTemp)
{
    ui_.maxCellTemperatureLabel().setNum(maxCellTemp);
}
void DisplayDashboardView::lowCellVoltageReceived(float lowestCellVoltage)
{
    ui_.lowestCellVoltageLabel().setNum(lowestCellVoltage / MV_TO_V);
}
void DisplayDashboardView::averageTemperatureReceived(int averageCellTemp)
{
    ui_.avgCellTemperatureLabel().setNum(averageCellTemp);
}
void DisplayDashboardView::averageCellVoltageReceived(float averageVoltage)
{
    ui_.avgCellVoltageLabel().setNum(averageVoltage / MV_TO_V);
}
void DisplayDashboardView::errorFlagsReceived(BatteryErrorFlags batteryErrorFlags)
{
    batteryFaultsList_.updateErrors(batteryErrorFlags);
    updateFaultLabel(ui_.batteryFaultsLabel(), batteryFaultsList_.getHighestActivePriorityLabel());
}
void DisplayDashboardView::limitFlagsReceived(BatteryLimitFlags batteryLimitFlags)
{
    batteryFaultsList_.updateLimits(batteryLimitFlags);
    updateFaultLabel(ui_.batteryFaultsLabel(), batteryFaultsList_.getHighestActivePriorityLabel());
}

void DisplayDashboardView::resetReceived(bool reset)
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

void DisplayDashboardView::auxReceived(bool aux)
{
    aux_ = aux;
    updateDriveStateLabel();
}

void DisplayDashboardView::forwardReceived(bool forward)
{
    forward_ = forward;
    updateDriveStateLabel();
}

void DisplayDashboardView::reverseReceived(bool reverse)
{
    reverse_ = reverse;
    updateDriveStateLabel();
}

void DisplayDashboardView::motorSetPowerReceived(double setPower)
{
    ui_.motorPowerLabel().setText(QString::number(setPower, 'f', 2));
}
void DisplayDashboardView::motorSetCurrentReceived(double setCurrent)
{
    ui_.setCurrentLabel().setText(QString::number(setCurrent, 'f', 3));
}
void DisplayDashboardView::motorActualSpeedReceived(double actualSpeed)
{
    ui_.actualSpeedLabel().setText(QString::number(actualSpeed, 'f', 1));
}
void DisplayDashboardView::motorBusVoltageReceived(double busVoltage)
{
    ui_.busVoltageLabel().setText(QString::number(busVoltage, 'f', 2));
}
void DisplayDashboardView::motorBusCurrentReceived(double busCurrent)
{
    ui_.busCurrentLabel().setText(QString::number(busCurrent, 'f', 3));
}

void DisplayDashboardView::lowBeamsReceived(bool lowBeams)
{
    if (lowBeams)
    {
        ui_.lowHeadlightIndicatorWidget().setStyleSheet("background: url(:/Resources/LowHeadlightIndicator.png)");
    }
    else
    {
        ui_.lowHeadlightIndicatorWidget().setStyleSheet("");
    }
}
void DisplayDashboardView::highBeamsReceived(bool highBeams)
{
    if (highBeams)
    {
        ui_.highHeadlightIndicatorWidget().setStyleSheet("background: url(:/Resources/HighHeadlightIndicator.png)");
    }
    else
    {
        ui_.highHeadlightIndicatorWidget().setStyleSheet("");
    }
}
void DisplayDashboardView::leftSignalReceived(bool leftSignal)
{
    if (leftSignal)
    {
        ui_.leftTurnSignalWidget().setStyleSheet("background: url(:/Resources/TurnSignalLeft.png);");
    }
    else
    {
        ui_.leftTurnSignalWidget().setStyleSheet("");
    }
}
void DisplayDashboardView::rightSignalReceived(bool rightSignal)
{
    if (rightSignal)
    {
        ui_.rightTurnSignalWidget().setStyleSheet("background: url(:/Resources/TurnSignalRight.png);");
    }
    else
    {
        ui_.rightTurnSignalWidget().setStyleSheet("");
    }
}
void DisplayDashboardView::lightAliveReceived(bool)
{
    // TODO
}
void DisplayDashboardView::mpptReceived(int i, Mppt mppt)
{
    if (i == 0)
    {
        ui_.array0CurrentLabel().setNum(mppt.arrayCurrent());
        ui_.array0VoltageLabel().setNum(mppt.arrayVoltage());
        mpptZeroPower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }
    else if (i == 1)
    {
        ui_.array1CurrentLabel().setNum(mppt.arrayCurrent());
        ui_.array1VoltageLabel().setNum(mppt.arrayVoltage());
        mpptOnePower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }
    else if (i == 2)
    {
        ui_.array2CurrentLabel().setNum(mppt.arrayCurrent());
        ui_.array2VoltageLabel().setNum(mppt.arrayVoltage());
        mpptTwoPower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }
    else if (i == 3)
    {
        ui_.array3CurrentLabel().setNum(mppt.arrayCurrent());
        ui_.array3VoltageLabel().setNum(mppt.arrayVoltage());
        mpptThreePower_ = mppt.arrayCurrent() * mppt.arrayVoltage();
    }


    mpptPowerReceived(mpptZeroPower_ + mpptOnePower_ + mpptTwoPower_ + mpptThreePower_);
}

void DisplayDashboardView::mpptPowerReceived(double mpptPower)
{
    ui_.powerInLabel().setText(QString::number(mpptPower, 'f', 0));
}

void DisplayDashboardView::motorZeroErrorFlagsReceived(ErrorFlags motorZeroErrorFlags)
{
    motorZeroFaultsList_.updateErrors(motorZeroErrorFlags);
    updateFaultLabel(ui_.motorZeroFaultsLabel(), motorZeroFaultsList_.getHighestActivePriorityLabel());
}
void DisplayDashboardView::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
    motorZeroFaultsList_.updateLimits(motorZeroLimitFlags);
    updateFaultLabel(ui_.motorZeroFaultsLabel(), motorZeroFaultsList_.getHighestActivePriorityLabel());
}
void DisplayDashboardView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
    motorOneFaultsList_.updateErrors(motorOneErrorFlags);
    updateFaultLabel(ui_.motorOneFaultsLabel(), motorOneFaultsList_.getHighestActivePriorityLabel());
}
void DisplayDashboardView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
    motorOneFaultsList_.updateLimits(motorOneLimitFlags);
    updateFaultLabel(ui_.motorOneFaultsLabel(), motorOneFaultsList_.getHighestActivePriorityLabel());
}
