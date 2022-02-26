#include "DisplayDashboardView.h"
#include <QDebug>
#include <QTimer>

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
    const int FAULT_UPDATE_PERIOD = 1500;
}

DisplayDashboardView::DisplayDashboardView(AuxBmsPresenter& auxBmsPresenter,
        BatteryPresenter& batteryPresenter,
        DriverControlsPresenter& driverControlsPresenter,
        KeyMotorPresenter& keyMotorPresenter,
        LightsPresenter& lightsPresenter,
        MpptPresenter& mpptPresenter,
        MotorDetailsPresenter& motorDetailsPresenter,
        I_DisplayDashboardUI& ui,
        I_MotorFaultList& motorZeroFaultsList,
        I_MotorFaultList& motorOneFaultsList,
        I_BatteryFaultList& batteryFaultsList)
    : auxBmsPresenter_(auxBmsPresenter)
    , batteryPresenter_(batteryPresenter)
    , driverControlsPresenter_(driverControlsPresenter)
    , keyMotorPresenter_(keyMotorPresenter)
    , lightsPresenter_(lightsPresenter)
    , mpptPresenter_(mpptPresenter)
    , motorDetailsPresenter_(motorDetailsPresenter)
    , ui_(ui)
    , motorZeroFaultsList_(motorZeroFaultsList)
    , motorOneFaultsList_(motorOneFaultsList)
    , batteryFaultsList_(batteryFaultsList)
    , faultsTimer_(new QTimer())
{
    connectAuxBms(auxBmsPresenter_);
    connectBattery(batteryPresenter_);
    connectDriverControls(driverControlsPresenter_);
    connectKeyMotor(keyMotorPresenter_);
    connectLights(lightsPresenter_);
    connectMppt(mpptPresenter_);
    connectMotorDetails(motorDetailsPresenter_);
    //ui_.showMaximized();
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateBatteryFaults()));
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateMotor0Faults()));
    connect(faultsTimer_.data(), SIGNAL(timeout()), this, SLOT(updateMotor1Faults()));
    faultsTimer_->start(FAULT_UPDATE_PERIOD);
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

void DisplayDashboardView::motorZeroReceived(KeyMotor motorZero)
{
    ui_.motorZeroSetCurrentLabel().setNum(motorZero.setCurrent());
    ui_.motorZeroBusCurrentLabel().setNum(motorZero.busCurrent());
    ui_.motorZeroBusVoltageLabel().setNum(motorZero.busVoltage());
}

void DisplayDashboardView::motorOneReceived(KeyMotor motorOne)
{
    ui_.motorOneSetCurrentLabel().setNum(motorOne.setCurrent());
    ui_.motorOneBusCurrentLabel().setNum(motorOne.busCurrent());
    ui_.motorOneBusVoltageLabel().setNum(motorOne.busVoltage());
}

void DisplayDashboardView::connectDriverControls(DriverControlsPresenter& driverControlsPresenter)
{
    connect(&driverControlsPresenter, SIGNAL(resetReceived(bool)),
            this, SLOT(resetReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(forwardReceived(bool)),
            this, SLOT(forwardReceived(bool)));
    connect(&driverControlsPresenter, SIGNAL(reverseReceived(bool)),
            this, SLOT(reverseReceived(bool)));
}

void DisplayDashboardView::connectKeyMotor(KeyMotorPresenter& keyMotorPresenter)
{
    connect(&keyMotorPresenter, SIGNAL(motorZeroBusPowerReceived(double)),
            this, SLOT(motorZeroBusPowerReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorOneBusPowerReceived(double)),
            this, SLOT(motorOneBusPowerReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorActualSpeedReceived(double)),
            this, SLOT(motorActualSpeedReceived(double)));
    connect(&keyMotorPresenter, SIGNAL(motorZeroReceived(KeyMotor)),
            this, SLOT(motorZeroReceived(KeyMotor)));
    connect(&keyMotorPresenter, SIGNAL(motorOneReceived(KeyMotor)),
            this, SLOT(motorOneReceived(KeyMotor)));
}

void DisplayDashboardView::connectLights(LightsPresenter& lightsPresenter)
{
    connect(&lightsPresenter, SIGNAL(lowBeamsReceived(bool)),
            this, SLOT(lowBeamsReceived(bool)));
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

void DisplayDashboardView::updateFaultLabel(QLabel& dashboardLabel, FaultDisplayData faultLabel)
{
    if (faultLabel.priority() >= 0)
    {
        dashboardLabel.setStyleSheet(QString("color:%1").arg(faultLabel.color().name()));
        dashboardLabel.setText(faultLabel.name());
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

void DisplayDashboardView::packNetPowerReceived(double batteryPower)
{
    ui_.batteryPowerLabel().setText(QString::number(batteryPower, 'f', 2));
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
void DisplayDashboardView::highTemperatureReceived(int highCellTemp)
{
    ui_.highCellTemperatureLabel().setNum(highCellTemp);
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

void DisplayDashboardView::motorZeroBusPowerReceived(double motorPower)
{
    if (motorPower > 1000.0)
    {
        motorPower = motorPower / 1000;
        ui_.motorZeroPowerUnitsLabel().setText("kW");
    }
    else
    {
        ui_.motorZeroPowerUnitsLabel().setText("W");
    }

    ui_.motorZeroPowerLabel().setText(QString::number(motorPower, 'f', 2));
}
void DisplayDashboardView::motorOneBusPowerReceived(double motorPower)
{
    if (motorPower > 1000.0)
    {
        motorPower = motorPower / 1000;
        ui_.motorOnePowerUnitsLabel().setText("kW");
    }
    else
    {
        ui_.motorOnePowerUnitsLabel().setText("W");
    }

    ui_.motorOnePowerLabel().setText(QString::number(motorPower, 'f', 2));
}

void DisplayDashboardView::motorActualSpeedReceived(double actualSpeed)
{
    ui_.actualSpeedLabel().setText(QString::number(qAbs(actualSpeed), 'f', 1));
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
    ui_.arrayPowerLabel().setText(QString::number(mpptPower, 'f', 0));
}

void DisplayDashboardView::updateBatteryFaults()
{
    updateFaultLabel(ui_.batteryFaultsLabel(), batteryFaultsList_.nextActiveFault());
}

void DisplayDashboardView::updateMotor0Faults()
{
    updateFaultLabel(ui_.motorZeroFaultsLabel(), motorZeroFaultsList_.nextActiveFault());
}

void DisplayDashboardView::updateMotor1Faults()
{
    updateFaultLabel(ui_.motorOneFaultsLabel(), motorOneFaultsList_.nextActiveFault());
}
