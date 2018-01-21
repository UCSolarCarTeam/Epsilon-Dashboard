#pragma once
#include <QWidget>
#include <QLabel>

class I_BatteryUi: public QWidget
{
public:
    virtual ~I_BatteryUi() {}

    virtual QWidget& aliveWidget() = 0;

    virtual QLabel& packInfoCurrent() = 0;
    virtual QLabel& packInfoVoltage() = 0;
    virtual QLabel& packInfoAmphours() = 0;
    virtual QLabel& packInfoDepthofDischarge() = 0;

    virtual QLabel& BMSOn() = 0;
    virtual QLabel& BMSCharging() = 0;
    virtual QLabel& BMSReady() = 0;
    virtual QLabel& BMSDischargeRelayEnabled() = 0;
    virtual QLabel& BMSChargeRelayEnabled() = 0;
    virtual QLabel& BMSChargerSafetyEnabled() = 0;

    virtual QLabel& malfunctionIndicatorActive() = 0;
    virtual QLabel& multipurposeInputSignalStatus() = 0;

    virtual QLabel& fanSpeedLabel() = 0; //seperate label and number on Ui
    virtual QWidget& fanSpeed1() = 0;
    virtual QWidget& fanSpeed2() = 0;
    virtual QWidget& fanSpeed3() = 0;
    virtual QWidget& fanSpeed4() = 0;
    virtual QWidget& fanSpeed5() = 0;
    virtual QWidget& fanSpeed6() = 0;

    virtual QWidget& requestedSpeed1() = 0;
    virtual QWidget& requestedSpeed2() = 0;
    virtual QWidget& requestedSpeed3() = 0;
    virtual QWidget& requestedSpeed4() = 0;
    virtual QWidget& requestedSpeed5() = 0;
    virtual QWidget& requestedSpeed6() = 0;
    virtual QLabel& requestedSpeedLabel() = 0;

    virtual QLabel& fanVoltage() = 0;

    virtual QLabel& tempHighLabel() = 0;
    virtual QLabel& tempLowLabel() = 0;
    virtual QLabel& tempAvgLabel() = 0;
    virtual QLabel& tempHighThermistorIDLabel() = 0;
    virtual QLabel& tempLowThermistorIDLabel() = 0;
    virtual QLabel& internalTempLabel() = 0;

    virtual QLabel&	highCellVoltageLabel() = 0;
    virtual QLabel& lowCellVoltageLabel() = 0;
    virtual QLabel& avgCellVoltageLabel() = 0;
    virtual QLabel& highCellVoltageIDLabel() = 0;
    virtual QLabel& lowCellVoltageIDLabel() = 0;

    virtual QLabel& populatedCellsLabel() = 0;
    virtual QLabel& inputVoltage12VLabel() = 0;
    virtual QLabel& prechargeStateLabel() = 0;
    virtual QLabel& auxVoltageLabel() = 0;

    virtual QWidget& auxBmsAliveWidget() = 0;
};
