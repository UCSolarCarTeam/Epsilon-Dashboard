#include "DisplayDashboardView.h"


DisplayDashboardView::DisplayDashboardView(BatteryPresenter& batteryPresenter,
        BatteryFaultsPresenter& batteryFaultsPresenter,
        CMUPresenter& cmuPresenter,
        DriverControlsPresenter& driverControlsPresenter,
        KeyMotorPresenter& keyMotorPresenter,
        LightsPresenter& lightsPresenter,
        MPPTPresenter& mpptPresenter,
        MotorDetailsPresenter& motorDetailsPresenter,
        MotorFaultsPresenter& motorFaultsPresenter,
        DisplayDashboardUI &ui)
    : batteryPresenter_(batteryPresenter)
    , batteryFaultsPresenter_(batteryFaultsPresenter)
    , cmuPresenter_(cmuPresenter)
    , driverControlsPresenter_(driverControlsPresenter)
    , keyMotorPresenter_(keyMotorPresenter)
    , lightsPresenter_(lightsPresenter)
    , mpptPresenter_(mpptPresenter)
    , motorDetailsPresenter_(motorDetailsPresenter)
    , motorFaultsPresenter_(motorFaultsPresenter)
    , ui_(ui)
{
    connectBattery(batteryPresenter_);
    connectBatteryFaults(batteryFaultsPresenter_);
    connectCMU(cmuPresenter_);
    connectDriverControls(driverControlsPresenter_);
    connectKeyMotor(keyMotorPresenter_);
    connectLights(lightsPresenter_);
    connectMPPT(mpptPresenter_);
    connectMotorDetails(motorDetailsPresenter_);
    connectMotorFaults(motorFaultsPresenter_);
    //ui_.showMaximized();
    ui_.show();
}
DisplayDashboardView::~DisplayDashboardView()
{
}

void DisplayDashboardView::connectBattery(BatteryPresenter& batteryPresenter)
{
    connect(&batteryPresenter, SIGNAL(aliveReceived(bool)),
            this, SLOT(aliveReceived(bool)));
    connect(&batteryPresenter, SIGNAL(packSocPercentageReceived(double)),
            this, SLOT(packSocPercentageReceived(double)));
    connect(&batteryPresenter, SIGNAL(prechargeStateReceived(QString)),
            this, SLOT(prechargeStateReceived(QString)));
    connect(&batteryPresenter, SIGNAL(prechargeTimerElapsedReceived(bool)),
            this, SLOT(prechargeTimerElapsedReceived(bool)));
    connect(&batteryPresenter, SIGNAL(prechargeTimerCountReceived(double)),
            this, SLOT(prechargeTimerCountReceived(double)));
    connect(&batteryPresenter, SIGNAL(netPowerReceived(double)),
            this, SLOT(netPowerReceived(double)));
}

void DisplayDashboardView::connectBatteryFaults(BatteryFaultsPresenter& batteryFaultsPresenter)
{
    connect(&batteryFaultsPresenter, SIGNAL(batteryFaultsReceived(BatteryFaults)),
            this, SLOT(batteryFaultsReceived(BatteryFaults)));
}

void DisplayDashboardView::connectCMU(CMUPresenter& cmuPresenter)
{
    connect(&cmuPresenter, SIGNAL(cmuMaxCellTempReceived(double)),
            this, SLOT(cmuMaxCellTempReceived(double)));
    connect(&cmuPresenter, SIGNAL(cmuLowestCellVoltageReceived(double)),
            this, SLOT(cmuLowestCellVoltageReceived(double)));
    connect(&cmuPresenter, SIGNAL(cmuAverageCellTempReceived(double)),
            this, SLOT(cmuAverageCellTempReceived(double)));
    connect(&cmuPresenter, SIGNAL(cmuCellVoltageReceived(double)),
            this, SLOT(cmuCellVoltageReceived(double)));
}

void DisplayDashboardView::connectDriverControls(DriverControlsPresenter& driverControlsPresenter)
{
    connect(&driverControlsPresenter, SIGNAL(resetReceived(bool)),
            this, SLOT(resetReceived(bool)));
}

void DisplayDashboardView::connectKeyMotor(KeyMotorPresenter& keyMotorPresenter)
{
    connect(&keyMotorPresenter, SIGNAL(motorSetCurrentReceived(double setCurrent)),
            this, SLOT(motorSetCurrentReceived(double setCurrent)));
    connect(&keyMotorPresenter, SIGNAL(motorActualSpeedReceived(double actualSpeed)),
            this, SLOT(motorActualSpeedReceived(double actualSpeed)));
    connect(&keyMotorPresenter, SIGNAL(motorBusVoltageReceived(double busVoltage)),
            this, SLOT(motorBusVoltageReceived(double busVoltage)));
    connect(&keyMotorPresenter, SIGNAL(motorBusCurrentReceived(double busCurrent)),
            this, SLOT(motorBusCurrentReceived(double busCurrent)));
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
}

void DisplayDashboardView::connectMPPT(MPPTPresenter& mpptPresenter)
{
    connect(&mpptPresenter, SIGNAL(mpptZeroReceived(MPPT)),
            this, SLOT(mpptZeroReceived(MPPT)));
    connect(&mpptPresenter, SIGNAL(mpptOneReceived(MPPT)),
            this, SLOT(mpptOneReceived(MPPT)));
    connect(&mpptPresenter, SIGNAL(mpptTwoReceived(MPPT)),
            this, SLOT(mpptTwoReceived(MPPT)));
    connect(&mpptPresenter, SIGNAL(mpptPowerReceived(double)),
            this, SLOT(mpptPowerReceived(double)));
}

void DisplayDashboardView::connectMotorDetails(MotorDetailsPresenter& motorDetailsPresenter)
{
}

void DisplayDashboardView::connectMotorFaults(MotorFaultsPresenter& motorFaultsPresenter)
{
    connect(&motorFaultsPresenter, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorOneErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorOneLimitFlagsReceived(LimitFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorTwoErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorTwoErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter, SIGNAL(motorTwoLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorTwoLimitFlagsReceived(LimitFlags)));
}

void DisplayDashboardView::aliveReceived(bool)
{
}
void DisplayDashboardView::packSocPercentageReceived(double packSocPercentage)
{
    ui_.stateOfChargeCapacityWidget().setValue(packSocPercentage);

    if (packSocPercentage > 85)
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(20,180,20)");
    }
    else if ((packSocPercentage > 70) && (packSocPercentage <= 85))
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(90,190,20)");
    }
    else if ((packSocPercentage > 55) && (packSocPercentage <= 70))
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(160,200,20)");
    }
    else if ((packSocPercentage > 40) && (packSocPercentage <= 55))
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(240,210,20)");
    }
    else if ((packSocPercentage > 25) && (packSocPercentage <= 40))
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(240,150,20)");
    }
    else if ((packSocPercentage > 10) && (packSocPercentage <= 25))
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(240,90,20)");
    }
    else
    {
        ui_.stateOfChargeCapacityWidget().setStyleSheet("QProgressBar::chunk:horizontal{background: rgb(240,20,20)");
    }
}
void DisplayDashboardView::prechargeStateReceived(QString prechargeState)
{
}
void DisplayDashboardView::prechargeTimerElapsedReceived(bool prechargeTimerElapsed)
{
}
void DisplayDashboardView::prechargeTimerCountReceived(double prechargeTimerCount)
{
}

void DisplayDashboardView::netPowerReceived(double netPower)
{
    ui_.netPowerLabel().setNum(netPower);
    ui_.powerOutLabel().setNum(netPower - ui_.powerInLabel().text().toDouble());
}

void DisplayDashboardView::batteryFaultsReceived(BatteryFaults)
{
}

void DisplayDashboardView::cmuMaxCellTempReceived(double maxCellTemp)
{
    ui_.maxCellTemperatureLabel().setNum(maxCellTemp);
}
void DisplayDashboardView::cmuLowestCellVoltageReceived(double lowestCellVoltage)
{
    ui_.lowestCellVoltageLabel().setNum(lowestCellVoltage);
}
void DisplayDashboardView::cmuAverageCellTempReceived(double averageCellTemp)
{
    ui_.avgCellTemperatureLabel().setNum(averageCellTemp);
}
void DisplayDashboardView::cmuAverageVoltageReceived(double averageVoltage)
{
    ui_.avgCellVoltageLabel().setNum(averageVoltage);
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
void DisplayDashboardView::motorSetCurrentReceived(double setCurrent)
{
    ui_.setCurrentLabel().setNum(setCurrent);
}
void DisplayDashboardView::motorActualSpeedReceived(double actualSpeed)
{
    ui_.actualSpeedLabel().setNum(actualSpeed);
}
void DisplayDashboardView::motorBusVoltageReceived(double busVoltage)
{
    ui_.busVoltageLabel().setNum(busVoltage);
}
void DisplayDashboardView::motorBusCurrentReceived(double busCurrent)
{
    ui_.busCurrentLabel().setNum(busCurrent);
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
        ui_.leftTurnSignalWidget().setStyleSheet("background: url(:/Resources/TurnSignaLeft.png);");
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
        ui_.rightTurnSignalWidget().setStyleSheet("background: url(:/Resources/TurnSignaRight.png);");
    }
    else
    {
        ui_.rightTurnSignalWidget().setStyleSheet("");
    }
}
void DisplayDashboardView::mpptZeroReceived(MPPT mpptZero)
{
    ui_.array0CurrentLabel().setNum(mpptZero.arrayCurrent());
    ui_.array0VoltageLabel().setNum(mpptZero.arrayVoltage());
}
void DisplayDashboardView::mpptOneReceived(MPPT mpptOne)
{
    ui_.array1CurrentLabel().setNum(mpptOne.arrayCurrent());
    ui_.array1VoltageLabel().setNum(mpptOne.arrayVoltage());
}
void DisplayDashboardView::mpptTwoReceived(MPPT mpptTwo)
{
    ui_.array2CurrentLabel().setNum(mpptTwo.arrayCurrent());
    ui_.array2VoltageLabel().setNum(mpptTwo.arrayVoltage());
}
void DisplayDashboardView::mpptPowerReceived(double mpptPower)
{
    ui_.powerInLabel().setNum(mpptPower);
    ui_.powerOutLabel().setNum(ui_.netPowerLabel().text().toDouble() - mpptPower);
}

void DisplayDashboardView::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
}
void DisplayDashboardView::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
}
void DisplayDashboardView::motorTwoErrorFlagsReceived(ErrorFlags motorTwoErrorFlags)
{
}
void DisplayDashboardView::motorTwoLimitFlagsReceived(LimitFlags motorTwoLimitFlags)
{
}
