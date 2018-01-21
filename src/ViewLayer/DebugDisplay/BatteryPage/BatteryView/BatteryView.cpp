#include "BatteryView.h"

namespace
{
    const QString BATTERY_ALIVE = "background-color:rgb(93, 234, 140); \
                              border-radius:8px; \
                              border: 1px solid white;";
    const QString BATTERY_DEAD = "background-color:rgb(147, 147, 147); \
                             border-radius:8px; \
                             border: 1px solid white;";

    const QString VOLTAGE_UNIT = "<sub>V</sub";
    const QString MILLI_VOLTAGE_UNIT = "<sub>mV</sub";
    const QString CURRENT_UNIT = "<sub>A</sub>";
    const QString AMPHOURS_UNIT = "<sub>Ah</sub";
    const QString PERCENT_UNIT = "<sub>%</sub";
    const QString TEMPERATURE_UNIT = "<sup>o</sup>C";
    const QString ON = "color: orange;";

    const QString OFF = "color: grey;";
}

BatteryView::BatteryView(BatteryPresenter& batteryPresenter,
                         I_BatteryUi& ui)
    : batteryPresenter_(batteryPresenter)
    , ui_(ui)
{
    connectBattery(batteryPresenter_);
}

BatteryView::~BatteryView()
{
}

void BatteryView::connectBattery(BatteryPresenter& batteryPresenter)
{
    connect(&batteryPresenter, SIGNAL(aliveReceived(const bool)),
            this, SLOT(aliveReceived(bool)));

    connect(&batteryPresenter, SIGNAL(bmsRelayStatusReceived(BmsRelayStatusFlags)),
            this, SLOT(bmsRelayStatusReceived(BmsRelayStatusFlags)));

    connect(&batteryPresenter, SIGNAL(populatedCellsReceived(const int)),
            this, SLOT(populatedCellsReceived(const int)));

    connect(&batteryPresenter, SIGNAL(inputVoltage12VReceived(const double)),
            this, SLOT(inputVoltage12VReceived(const double)));

    connect(&batteryPresenter, SIGNAL(fanVoltageReceived(const double)),
            this, SLOT(fanVoltageReceived(const double)));

    connect(&batteryPresenter, SIGNAL(packCurrentReceived(double)),
            this, SLOT(packCurrentReceived(double)));

    connect(&batteryPresenter, SIGNAL(packVoltageReceived(const double)),
            this, SLOT(packVoltageReceived(const double)));

    connect(&batteryPresenter, SIGNAL(packStateofChargeReceived(const double)),
            this, SLOT(packStateofChargeReceived(const double)));

    connect(&batteryPresenter, SIGNAL(packAmphoursReceived(const double)),
            this, SLOT(packAmphoursReceived(const double)));

    connect(&batteryPresenter, SIGNAL(packDepthOfDischargeReceived(const double)),
            this, SLOT(packDepthOfDischargeReceived(const double)));

    connect(&batteryPresenter, SIGNAL(highTemperatureReceived(const int)),
            this, SLOT(highTemperatureReceived(const int)));

    connect(&batteryPresenter, SIGNAL(highThermistorIdReceived(const int)),
            this, SLOT(highThermistorIdReceived(const int)));

    connect(&batteryPresenter, SIGNAL(lowTemperatureReceived(const int)),
            this, SLOT(lowTemperatureReceived(const int)));

    connect(&batteryPresenter, SIGNAL(lowThermistorIdReceived(const int)),
            this, SLOT(lowThermistorIdReceived(const int)));

    connect(&batteryPresenter, SIGNAL(averageTemperatureReceived(const int)),
            this, SLOT(averageTemperatureReceived(const int)));

    connect(&batteryPresenter, SIGNAL(internalTemperatureReceived(const int)),
            this, SLOT(internalTemperatureReceived(const int)));

    connect(&batteryPresenter, SIGNAL(fanSpeedReceived(const int)),
            this, SLOT(fanSpeedReceived(const int)));

    connect(&batteryPresenter, SIGNAL(requestedFanSpeedReceived(const int)),
            this, SLOT(requestedFanSpeedReceived(const int)));

    connect(&batteryPresenter, SIGNAL(lowCellVoltageReceived(const int)),
            this, SLOT(lowCellVoltageReceived(const int)));

    connect(&batteryPresenter, SIGNAL(lowCellVoltageIdReceived(const int)),
            this, SLOT(lowCellVoltageIdReceived(const int)));

    connect(&batteryPresenter, SIGNAL(highCellVoltageReceived(const int)),
            this, SLOT(highCellVoltageReceived(const int)));

    connect(&batteryPresenter, SIGNAL(highCellVoltageIdReceived(const int)),
            this, SLOT(highCellVoltageIdReceived(const int)));

    connect(&batteryPresenter, SIGNAL(averageCellVoltageReceived(const int)),
            this, SLOT(averageCellVoltageReceived(const int)));

    connect(&batteryPresenter, SIGNAL(prechargeStateReceived(const QString)),
            this, SLOT(prechargeStateReceived(const QString)));

    connect(&batteryPresenter, SIGNAL(auxVoltageReceived(const int)),
            this, SLOT(auxVoltageReceived(const int)));

    connect(&batteryPresenter, SIGNAL(auxBmsAliveReceived(const bool)),
            this, SLOT(auxBmsAliveReceived(const bool)));

    connect(&batteryPresenter, SIGNAL(packNetPowerReceived(const double)),
            this, SLOT(packNetPowerReceived(const double)));
}




void BatteryView::aliveReceived(bool alive)
{
    if (alive)
    {
        ui_.aliveWidget().setStyleSheet(BATTERY_ALIVE);
    }
    else
    {
        ui_.aliveWidget().setStyleSheet(BATTERY_DEAD);
    }
}

void BatteryView::bmsRelayStatusReceived(BmsRelayStatusFlags)
{

}

void BatteryView::populatedCellsReceived(int populatedCells)
{
    ui_.populatedCellsLabel().setNum(populatedCells);
}

void BatteryView::inputVoltage12VReceived(double inputVoltage)
{
    ui_.inputVoltage12VLabel().setText(QString::number(inputVoltage) + VOLTAGE_UNIT);
}


void BatteryView::fanVoltageReceived(double fanVoltage)
{
    ui_.fanVoltage().setText(QString::number(fanVoltage) + VOLTAGE_UNIT);
}

void BatteryView::packCurrentReceived(double packCurrent)
{
    ui_.packInfoCurrent().setText(QString::number(packCurrent) + CURRENT_UNIT);
}

void BatteryView::packVoltageReceived(double packVoltage)
{
    ui_.packInfoVoltage().setText(QString::number(packVoltage) + VOLTAGE_UNIT);
}

void BatteryView::packStateOfChargeReceived(double packStateOfCharge)
{

}

void BatteryView::packAmphoursReceived(double packAmphours)
{
    ui_.packInfoAmphours().setText(QString::number(packAmphours) + AMPHOURS_UNIT);
}

void BatteryView::packDepthOfDischargeReceived(double packDepthOfDischarge)
{
    ui_.packInfoDepthofDischarge().setText(QString::number(packDepthOfDischarge) + PERCENT_UNIT);
}

void BatteryView::highTemperatureReceived(int highTemperature)
{
    ui_.tempHighLabel().setText(QString::number(highTemperature) + TEMPERATURE_UNIT);
}

void BatteryView::highThermistorIdReceived(int highThermistorId)
{
    ui_.tempHighThermistorIDLabel().setNum(highThermistorId);
}

void BatteryView::lowTemperatureReceived(int lowTemperature)
{
    ui_.tempLowLabel().setText(QString::number(lowTemperature) + TEMPERATURE_UNIT);
}

void BatteryView::lowThermistorIdReceived(int lowThermistorId)
{
    ui_.tempLowThermistorIDLabel().setNum(lowThermistorId);
}

void BatteryView::averageTemperatureReceived(int averageTemperature)
{
    averageTemperature = (lowTemperature + highTemperature) / 2;
    ui_.tempAvgLabel().setText(QString::number(averageTemperature) + TEMPERATURE_UNIT);
}

void BatteryView::internalTemperatureReceived(int internalTemperature)
{

}

void BatteryView::fanSpeedReceived(int fanSpeed)
{

}

void BatteryView::requestedFanSpeedReceived(int requestedFanSpeed)
{

}

void BatteryView::lowCellVoltageReceived(int lowCellVoltage)
{

}

void BatteryView::lowCellVoltageIdReceived(int lowCellVoltageId)
{

}

void BatteryView::highCellVoltageReceived(int highCellVoltage)
{

}

void BatteryView::highCellVoltageIdReceived(int highCellVoltageId)
{

}

void BatteryView::averageCellVoltageReceived(int averageCellVoltage)
{

}

void BatteryView::prechargeStateReceived(QString prechargeState)
{

}

void BatteryView::auxVoltageReceived(int auxVoltage)
{

}

void BatteryView::auxBmsAliveReceived(bool auxBmsAlive)
{
    if (auxBmsAlive)
    {
        ui_.auxBmsAliveWidget().setStyleSheet(BATTERY_ALIVE);
    }
    else
    {
        ui_.auxBmsAliveWidget().setStyleSheet(BATTERY_DEAD);
    }

}

void BatteryView::packNetPowerReceived(double packNetPower)
{

}



