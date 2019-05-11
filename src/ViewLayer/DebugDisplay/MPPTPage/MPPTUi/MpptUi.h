#pragma once
#include "I_MpptUi.h"
#include "FontLoader/FontLoader.h"

namespace Ui
{
    class MpptUi;
}

class MpptUi : public I_MpptUi
{
    Q_OBJECT
public:
    explicit MpptUi();
    ~MpptUi();

    QWidget& mppt0AliveIndicator();
    QWidget& mppt1AliveIndicator();
    QWidget& mppt2AliveIndicator();
    QWidget& mppt3AliveIndicator();

    QLabel& mppt0ArrayVoltage();
    QLabel& mppt1ArrayVoltage();
    QLabel& mppt2ArrayVoltage();
    QLabel& mppt3ArrayVoltage();

    QLabel& mppt0ArrayCurrent();
    QLabel& mppt1ArrayCurrent();
    QLabel& mppt2ArrayCurrent();
    QLabel& mppt3ArrayCurrent();

    QLabel& mppt0ArrayPower();
    QLabel& mppt1ArrayPower();
    QLabel& mppt2ArrayPower();
    QLabel& mppt3ArrayPower();

    QLabel& mppt0BatteryVoltage();
    QLabel& mppt1BatteryVoltage();
    QLabel& mppt2BatteryVoltage();
    QLabel& mppt3BatteryVoltage();

    QLabel& mppt0Temperature();
    QLabel& mppt1Temperature();
    QLabel& mppt2Temperature();
    QLabel& mppt3Temperature();

    QLabel& totalArrayPower();
private:
    Ui::MpptUi* ui_;
    QScopedPointer<FontLoader> fontLoader_;
};

