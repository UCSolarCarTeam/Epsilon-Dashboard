#pragma once

#include <QLabel>


class I_MpptUi: public QWidget
{
    Q_OBJECT
public:
    virtual ~I_MpptUi() {}

    virtual QWidget& mppt0AliveIndicator() = 0;
    virtual QWidget& mppt1AliveIndicator() = 0;
    virtual QWidget& mppt2AliveIndicator() = 0;

    virtual QLabel& mppt0ArrayVoltage() = 0;
    virtual QLabel& mppt1ArrayVoltage() = 0;
    virtual QLabel& mppt2ArrayVoltage() = 0;

    virtual QLabel& mppt0ArrayCurrent() = 0;
    virtual QLabel& mppt1ArrayCurrent() = 0;
    virtual QLabel& mppt2ArrayCurrent() = 0;

    virtual QLabel& mppt0ArrayPower() = 0;
    virtual QLabel& mppt1ArrayPower() = 0;
    virtual QLabel& mppt2ArrayPower() = 0;

    virtual QLabel& mppt0BatteryVoltage() = 0;
    virtual QLabel& mppt1BatteryVoltage() = 0;
    virtual QLabel& mppt2BatteryVoltage() = 0;

    virtual QLabel& mppt0Temperature() = 0;
    virtual QLabel& mppt1Temperature() = 0;
    virtual QLabel& mppt2Temperature() = 0;

    virtual QLabel& totalArrayPower() = 0;
};
