﻿#include "BatteryView.h"

namespace
{
    const QString BATTERY_ALIVE = "background-color:rgb(93, 234, 140); \
                              border-radius:8px; \
                              border: 1px solid white;";
    const QString BATTERY_DEAD = "background-color:rgb(147, 147, 147); \
                             border-radius:8px; \
                             border: 1px solid white;";

    const QString VOLTAGE_UNIT = "V";
    const QString MILLI_VOLTAGE_UNIT = "mV";
    const QString CURRENT_UNIT = "A";
    const QString AMPHOURS_UNIT = "Ah";
    const QString POWER_UNIT = "W";
    const QString PERCENT_UNIT = "%";
    const QString TEMPERATURE_UNIT = "<sup>o</sup>C";

    const QString ON = "color: rgb(250, 187, 28);";
    const QString OFF = "color: grey;";

    const QString FAN_ON = "background-color: rgb(250, 187, 28);";
    const QString REQUESTED_FAN_ON = "background-color: rgb(64, 161, 191);";
    const QString FAN_OFF = "background-color: grey;";

    const float MV_TO_V = 1000;
}

BatteryView::BatteryView(BatteryPresenter& batteryPresenter,
                         I_BatteryUi& ui, ProgressBar& bar)
    : batteryPresenter_(batteryPresenter)
    , ui_(ui)
    , bar_(bar)
{
    fanSpeedList_.append(&ui.fanSpeed1());
    fanSpeedList_.append(&ui.fanSpeed2());
    fanSpeedList_.append(&ui.fanSpeed3());
    fanSpeedList_.append(&ui.fanSpeed4());
    fanSpeedList_.append(&ui.fanSpeed5());
    fanSpeedList_.append(&ui.fanSpeed6());

    requestedFanSpeedList_.append(&ui.requestedSpeed1());
    requestedFanSpeedList_.append(&ui.requestedSpeed2());
    requestedFanSpeedList_.append(&ui.requestedSpeed3());
    requestedFanSpeedList_.append(&ui.requestedSpeed4());
    requestedFanSpeedList_.append(&ui.requestedSpeed5());
    requestedFanSpeedList_.append(&ui.requestedSpeed6());

    connectBattery(batteryPresenter_);
}

BatteryView::~BatteryView()
{
}

void BatteryView::updateProgress(double stateOfCharge)
{
    bar_.setProgress(stateOfCharge / 100);
    bar_.update();
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

    connect(&batteryPresenter, SIGNAL(packStateOfChargeReceived(const double)),
            this, SLOT(packStateOfChargeReceived(const double)));
    //ui_.progressBarContainer().addWidget(&bar_);

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

    connect(&batteryPresenter, SIGNAL(lowCellVoltageReceived(const float)),
            this, SLOT(lowCellVoltageReceived(const float)));

    connect(&batteryPresenter, SIGNAL(lowCellVoltageIdReceived(const int)),
            this, SLOT(lowCellVoltageIdReceived(const int)));

    connect(&batteryPresenter, SIGNAL(highCellVoltageReceived(const float)),
            this, SLOT(highCellVoltageReceived(const float)));

    connect(&batteryPresenter, SIGNAL(highCellVoltageIdReceived(const int)),
            this, SLOT(highCellVoltageIdReceived(const int)));

    connect(&batteryPresenter, SIGNAL(averageCellVoltageReceived(const float)),
            this, SLOT(averageCellVoltageReceived(const float)));

    connect(&batteryPresenter, SIGNAL(packNetPowerReceived(const double)),
            this, SLOT(packNetPowerReceived(const double)));
    ui_.progressBarContainer().addWidget(&bar_);
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

void BatteryView::bmsRelayStatusReceived(BmsRelayStatusFlags BmsRelayStatus)
{
    if (BmsRelayStatus.alwaysOnSignalStatus())
    {
        ui_.BmsOn().setStyleSheet(ON);
    }
    else
    {
        ui_.BmsOn().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.isChargingSignalStatus())
    {
        ui_.BmsCharging().setStyleSheet(ON);
    }
    else
    {
        ui_.BmsCharging().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.isReadySignalStatus())
    {
        ui_.BmsReady().setStyleSheet(ON);
    }
    else
    {
        ui_.BmsReady().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.dischargeRelayEnabled())
    {
        ui_.BmsDischargeRelayEnabled().setStyleSheet(ON);
    }
    else
    {
        ui_.BmsDischargeRelayEnabled().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.chargeRelayEnabled())
    {
        ui_.BmsChargeRelayEnabled().setStyleSheet(ON);
    }
    else
    {
        ui_.BmsChargeRelayEnabled().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.chargerSafetyEnabled())
    {
        ui_.BmsChargerSafetyEnabled().setStyleSheet(ON);
    }
    else
    {
        ui_.BmsChargerSafetyEnabled().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.malfunctionIndicatorActive())
    {
        ui_.malfunctionIndicatorActive().setStyleSheet(ON);
    }
    else
    {
        ui_.malfunctionIndicatorActive().setStyleSheet(OFF);
    }

    if (BmsRelayStatus.multiPurposeInputSignalStatus())
    {
        ui_.multipurposeInputSignalStatus().setStyleSheet(ON);
    }
    else
    {
        ui_.multipurposeInputSignalStatus().setStyleSheet(OFF);
    }
}

void BatteryView::populatedCellsReceived(int populatedCells)
{
    ui_.populatedCellsLabel().setNum(populatedCells);
}

void BatteryView::inputVoltage12VReceived(double inputVoltage)
{
    ui_.inputVoltage12VLabel().setText(QString::number(inputVoltage) + " " + VOLTAGE_UNIT);
}


void BatteryView::fanVoltageReceived(double fanVoltage)
{
    ui_.fanVoltage().setText(QString::number(fanVoltage) + " " + VOLTAGE_UNIT);
}

void BatteryView::packCurrentReceived(double packCurrent)
{
    ui_.packInfoCurrent().setText(QString::number(packCurrent) + " " + CURRENT_UNIT);
}

void BatteryView::packVoltageReceived(double packVoltage)
{
    ui_.packInfoVoltage().setText(QString::number(packVoltage) + " " + VOLTAGE_UNIT);
}

void BatteryView::packStateOfChargeReceived(double packStateOfCharge)
{
    updateProgress(packStateOfCharge);
}

void BatteryView::packAmphoursReceived(double packAmphours)
{
    ui_.packInfoAmphours().setText(QString::number(packAmphours) + " " + AMPHOURS_UNIT);
}

void BatteryView::packDepthOfDischargeReceived(double packDepthOfDischarge)
{
    ui_.packInfoDepthofDischarge().setText(QString::number(packDepthOfDischarge) + " " + PERCENT_UNIT);
}

void BatteryView::highTemperatureReceived(int highTemperature)
{
    ui_.tempHighLabel().setText(QString::number(highTemperature) + " " + TEMPERATURE_UNIT);
}

void BatteryView::highThermistorIdReceived(int highThermistorId)
{
    ui_.tempHighThermistorIDLabel().setNum(highThermistorId);
}

void BatteryView::lowTemperatureReceived(int lowTemperature)
{
    ui_.tempLowLabel().setText(QString::number(lowTemperature) + " " + TEMPERATURE_UNIT);
}

void BatteryView::lowThermistorIdReceived(int lowThermistorId)
{
    ui_.tempLowThermistorIDLabel().setNum(lowThermistorId);
}

void BatteryView::averageTemperatureReceived(int averageTemperature)
{
    ui_.tempAvgLabel().setText(QString::number(averageTemperature) + TEMPERATURE_UNIT);
}

void BatteryView::internalTemperatureReceived(int internalTemperature)
{
    ui_.internalTempLabel().setText(QString::number(internalTemperature) + " " + TEMPERATURE_UNIT);
}

void BatteryView::fanSpeedReceived(int fanSpeed)
{
    ui_.fanSpeedLabel().setNum(fanSpeed);

    for (int i = 0; i < fanSpeedList_.size(); i++)
    {
        if (i < fanSpeed)
        {
            fanSpeedList_[i]->setStyleSheet(FAN_ON);
        }
        else
        {
            fanSpeedList_[i]->setStyleSheet(FAN_OFF);
        }
    }
}

void BatteryView::requestedFanSpeedReceived(int requestedFanSpeed)
{
    ui_.requestedFanSpeedLabel().setNum(requestedFanSpeed);

    for (int i = 0; i < fanSpeedList_.size(); i++)
    {
        if (i < requestedFanSpeed)
        {
            requestedFanSpeedList_[i]->setStyleSheet(REQUESTED_FAN_ON);
        }
        else
        {
            requestedFanSpeedList_[i]->setStyleSheet(FAN_OFF);
        }
    }
}

void BatteryView::lowCellVoltageReceived(float lowCellVoltage)
{
    ui_.lowCellVoltageLabel().setText(QString::number(lowCellVoltage / MV_TO_V, 'f', 3) + " " + VOLTAGE_UNIT);
}

void BatteryView::lowCellVoltageIdReceived(int lowCellVoltageId)
{
    ui_.lowCellVoltageIDLabel().setNum(lowCellVoltageId);
}

void BatteryView::highCellVoltageReceived(float highCellVoltage)
{
    ui_.highCellVoltageLabel().setText(QString::number(highCellVoltage / MV_TO_V, 'f', 3) + " " + VOLTAGE_UNIT);
}

void BatteryView::highCellVoltageIdReceived(int highCellVoltageId)
{
    ui_.highCellVoltageIDLabel().setNum(highCellVoltageId);
}

void BatteryView::averageCellVoltageReceived(float avgCellVoltage)
{
    ui_.avgCellVoltageLabel().setText(QString::number(avgCellVoltage / MV_TO_V, 'f', 3) + " " + VOLTAGE_UNIT);
}

void BatteryView::packNetPowerReceived(double packNetPower)
{
    ui_.packNetPower().setText(QString::number(packNetPower, 'f', 2) + " " + POWER_UNIT);
}
