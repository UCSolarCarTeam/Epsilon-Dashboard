#pragma once
#include "I_BatteryUi.h"
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
namespace Ui
{
    class BatteryUi;
}

class BatteryUi : public I_BatteryUi
{
    Q_OBJECT

public:
    explicit BatteryUi();
    ~BatteryUi();

    QWidget& aliveWidget();

    QLabel& packInfoCurrent();
    QLabel& packInfoVoltage();
    QLabel& packInfoAmphours();
    QLabel& packInfoDepthofDischarge();
    QLabel& packNetPower();

    QLabel& BmsOn();
    QLabel& BmsCharging();
    QLabel& BmsReady();
    QLabel& BmsDischargeRelayEnabled();
    QLabel& BmsChargeRelayEnabled();
    QLabel& BmsChargerSafetyEnabled();

    QLabel& malfunctionIndicatorActive();
    QLabel& multipurposeInputSignalStatus();

    QLabel& fanSpeedLabel(); //seperate label and number on Ui
    QWidget& fanSpeed1();
    QWidget& fanSpeed2();
    QWidget& fanSpeed3();
    QWidget& fanSpeed4();
    QWidget& fanSpeed5();
    QWidget& fanSpeed6();

    QWidget& requestedSpeed1();
    QWidget& requestedSpeed2();
    QWidget& requestedSpeed3();
    QWidget& requestedSpeed4();
    QWidget& requestedSpeed5();
    QWidget& requestedSpeed6();
    QLabel& requestedFanSpeedLabel();

    QLabel& fanVoltage();

    QLabel& tempHighLabel();
    QLabel& tempLowLabel();
    QLabel& tempAvgLabel();
    QLabel& tempHighThermistorIDLabel();
    QLabel& tempLowThermistorIDLabel();
    QLabel& internalTempLabel();

    QLabel& highCellVoltageLabel();
    QLabel& lowCellVoltageLabel();
    QLabel& avgCellVoltageLabel();
    QLabel& highCellVoltageIDLabel();
    QLabel& lowCellVoltageIDLabel();

    QLabel& populatedCellsLabel();
    QLabel& inputVoltage12VLabel();
    QLabel& prechargeStateLabel();
    QLabel& auxVoltageLabel();

    QWidget& auxBmsAliveWidget();
    QVBoxLayout& progressBarContainer();

    QLabel& strobeBMSLabel();
    QLabel& allowChargeLabel();
    QLabel& contactorErrorLabel();
    QLabel& highVoltageEnableLabel();

private:
    Ui::BatteryUi* ui_;
};

