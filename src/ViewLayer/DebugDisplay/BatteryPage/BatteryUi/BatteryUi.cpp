﻿#include "BatteryUi.h"
#include "ui_BatteryUi.h"
BatteryUi::BatteryUi() :
    ui_(new Ui::BatteryUi)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background;
    background.setBrush(QPalette::Background, bkgnd);
    this->setPalette(background);
}

BatteryUi::~BatteryUi()
{
    delete ui_;
}

QLabel& BatteryUi::packInfoCurrent()
{
    return *ui_->packInfoCurrent;
}

QLabel& BatteryUi::packInfoVoltage()
{
    return *ui_->packInfoVoltage;
}

QLabel& BatteryUi::packInfoAmphours()
{
    return *ui_->packInfoAmphours;
}

QLabel& BatteryUi::packInfoDepthofDischarge()
{
    return *ui_->packInfoDepthofDischarge;
}

QLabel& BatteryUi::BMSOn()
{
    return *ui_->BMSOn;
}

QLabel& BatteryUi::BMSCharging()
{
    return *ui_->BMSCharging;
}

QLabel& BatteryUi::BMSReady()
{
    return *ui_->BMSReady;
}

QLabel& BatteryUi::BMSDischargeRelayEnabled()
{
    return *ui_->BMSDischargeRelayEnabled;
}

QLabel& BatteryUi::BMSChargeRelayEnabled()
{
    return *ui_->BMSChargeRelayEnabled;
}

QLabel& BatteryUi::BMSChargerSafetyEnabled()
{
    return *ui_->BMSChargerSafetyEnabled;
}

QLabel& BatteryUi::malfunctionIndicatorActive()
{
    return *ui_->malfunctionIndicatorActive;
}

QLabel& BatteryUi::multipurposeInputSignalStatus()
{
    return *ui_->multipurposeInputSignalStatus;
}

QLabel& BatteryUi::fanSpeedLabel()
{
    return *ui_->fanSpeedLabel;
}
//seperate label and number on Ui
QWidget& BatteryUi::fanSpeed1()
{
    return *ui_->fanSpeed1;
}

QWidget& BatteryUi::fanSpeed2()
{
    return *ui_->fanSpeed2;
}

QWidget& BatteryUi::fanSpeed3()
{
    return *ui_->fanSpeed3;
}

QWidget& BatteryUi::fanSpeed4()
{
    return *ui_->fanSpeed4;
}

QWidget& BatteryUi::fanSpeed5()
{
    return *ui_->fanSpeed5;
}

QWidget& BatteryUi::fanSpeed6()
{
    return *ui_->fanSpeed6;
}

QWidget& BatteryUi::requestedSpeed1()
{
    return *ui_->requestedSpeed1;
}

QWidget& BatteryUi::requestedSpeed2()
{
    return *ui_->requestedSpeed2;
}

QWidget& BatteryUi::requestedSpeed3()
{
    return *ui_->requestedSpeed3;
}

QWidget& BatteryUi::requestedSpeed4()
{
    return *ui_->requestedSpeed4;
}

QWidget& BatteryUi::requestedSpeed5()
{
    return *ui_->requestedSpeed5;
}

QWidget& BatteryUi::requestedSpeed6()
{
    return *ui_->requestedSpeed6;
}

QLabel& BatteryUi::requestedSpeedLabel()
{
    return *ui_->requestedSpeedLabel;
}

QLabel& BatteryUi::tempHighLabel()
{
    return *ui_->tempHighLabel;
}

QLabel& BatteryUi::tempLowLabel()
{
    return *ui_->tempLowLabel;
}

QLabel& BatteryUi::tempHighThermistorIDLabel()
{
    return *ui_->tempHighThermistorIDLabel;
}

QLabel& BatteryUi::tempLowThermistorIDLabel()
{
    return *ui_->tempHighThermistorIDLabel;
}

QLabel& BatteryUi::internalTempLabel()
{
    return *ui_->internalTempLabel;
}

QLabel& BatteryUi::highCellVoltageLabel()
{
    return *ui_->highCellVoltageLabel;
}

QLabel& BatteryUi::lowCellVoltageLabel()
{
    return *ui_->lowCellVoltageLabel;
}

QLabel& BatteryUi::avgCellVoltageLabel()
{
    return *ui_->avgCellVoltageLabel;
}

QLabel& BatteryUi::highCellVoltageIDLabel()
{
    return *ui_->highCellVoltageIDLabel;
}

QLabel& BatteryUi::lowCellVoltageIDLabel()
{
    return *ui_->lowCellVoltageIDLabel;
}




