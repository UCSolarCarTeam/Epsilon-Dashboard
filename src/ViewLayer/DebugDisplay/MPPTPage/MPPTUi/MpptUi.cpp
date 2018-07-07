#include"MpptUi.h"
#include "ui_MpptUi.h"

MpptUi::MpptUi() :
    ui_(new Ui::MpptUi)
{
    ui_->setupUi(this);
    QPixmap bkgnd(":/Resources/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette background;
    background.setBrush(QPalette::Background, bkgnd);
    this->setPalette(background);
}

MpptUi::~MpptUi()
{
    delete ui_;
}

QWidget& MpptUi::mppt0AliveIndicator()
{
    return *ui_->mppt0AliveIndicator;
}

QWidget& MpptUi::mppt1AliveIndicator()
{
    return *ui_->mppt1AliveIndicator;
}

QWidget& MpptUi::mppt2AliveIndicator()
{
    return *ui_->mppt2AliveIndicator;
}

QWidget& MpptUi::mppt3AliveIndicator()
{
    return *ui_->mppt3AliveIndicator;
}

QLabel& MpptUi::mppt0ArrayVoltage()
{
    return *ui_->mppt0ArrayVoltage;
}

QLabel& MpptUi::mppt1ArrayVoltage()
{
    return *ui_->mppt1ArrayVoltage;
}

QLabel& MpptUi::mppt2ArrayVoltage()
{
    return *ui_->mppt2ArrayVoltage;
}

QLabel& MpptUi::mppt3ArrayVoltage()
{
    return *ui_->mppt3ArrayVoltage;
}

QLabel& MpptUi::mppt0ArrayCurrent()
{
    return *ui_->mppt0ArrayCurrent;
}

QLabel& MpptUi::mppt1ArrayCurrent()
{
    return *ui_->mppt1ArrayCurrent;
}

QLabel& MpptUi::mppt2ArrayCurrent()
{
    return *ui_->mppt2ArrayCurrent;
}

QLabel& MpptUi::mppt3ArrayCurrent()
{
    return *ui_->mppt3ArrayCurrent;
}

QLabel& MpptUi::mppt0ArrayPower()
{
    return *ui_->mppt0ArrayPower;
}

QLabel& MpptUi::mppt1ArrayPower()
{
    return *ui_->mppt1ArrayPower;
}

QLabel& MpptUi::mppt2ArrayPower()
{
    return *ui_->mppt2ArrayPower;
}

QLabel& MpptUi::mppt3ArrayPower()
{
    return *ui_->mppt3ArrayPower;
}

QLabel& MpptUi::mppt0BatteryVoltage()
{
    return *ui_->mppt0BatteryVoltage;
}

QLabel& MpptUi::mppt1BatteryVoltage()
{
    return *ui_->mppt1BatteryVoltage;
}

QLabel& MpptUi::mppt2BatteryVoltage()
{
    return *ui_->mppt2BatteryVoltage;
}

QLabel& MpptUi::mppt3BatteryVoltage()
{
    return *ui_->mppt3BatteryVoltage;
}

QLabel& MpptUi::mppt0Temperature()
{
    return *ui_->mppt0Temperature;
}

QLabel& MpptUi::mppt1Temperature()
{
    return *ui_->mppt1Temperature;
}

QLabel& MpptUi::mppt2Temperature()
{
    return *ui_->mppt2Temperature;
}

QLabel& MpptUi::mppt3Temperature()
{
    return *ui_->mppt3Temperature;
}

QLabel& MpptUi::totalArrayPower()
{
    return *ui_->totalArrayPower;
}
