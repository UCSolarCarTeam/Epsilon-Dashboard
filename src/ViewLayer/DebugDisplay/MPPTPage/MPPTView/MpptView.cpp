#include "MpptView.h"

namespace
{
const QString VOLTAGE_UNIT = "<sub>V</sub";
const QString CURRENT_UNIT = "<sub>A</sub>";
const QString POWER_UNIT = "<sub>W</sub>";
const QString TEMPERATURE_UNIT = "<sup>o</sup>C";
const QString MPPT_ALIVE = "background-color:rgb(93, 234, 140); \
                                border-radius:8px; \
                                border: 1px solid white;";
const QString MPPT_DEAD = "background-color:rgb(147, 147, 147); \
                               border-radius:8px; \
                               border: 1px solid white;";
}

MpptView::MpptView(MpptPresenter& mpptPresenter,
                   I_MpptUi& ui)
    : mpptPresenter_(mpptPresenter)
    , mpptZeroPower_(0)
    , mpptOnePower_(0)
    , mpptTwoPower_(0)
    , ui_(ui)
{
    connectMppt(mpptPresenter_);
}

MpptView::~MpptView()
{
}

void MpptView::connectMppt(MpptPresenter& mpptPresenter)
{
    connect(&mpptPresenter, SIGNAL(mpptReceived(int, Mppt)),
            this, SLOT(mpptReceived(int, Mppt)));
}

void MpptView::mpptReceived(int i, Mppt mppt)
{
    if (i == 0)
    {
        if (mppt.alive())
        {
            ui_.mppt0AliveIndicator().setStyleSheet(MPPT_ALIVE);
        }
        else
        {
            ui_.mppt0AliveIndicator().setStyleSheet(MPPT_DEAD);
        }

        mpptZeroPower_ = mppt.arrayCurrent() * mppt.arrayVoltage();

        ui_.mppt0ArrayVoltage().setText(QString::number(mppt.arrayVoltage()) + VOLTAGE_UNIT);
        ui_.mppt0ArrayCurrent().setText(QString::number(mppt.arrayCurrent()) + CURRENT_UNIT);
        ui_.mppt0ArrayPower().setText(QString::number(mpptZeroPower_) + POWER_UNIT);
        ui_.mppt0BatteryVoltage().setText(QString::number(mppt.batteryVoltage()) + VOLTAGE_UNIT);
        ui_.mppt0Temperature().setText(QString::number(mppt.temperature()) + TEMPERATURE_UNIT);
    }
    else if (i == 1)
    {
        if (mppt.alive())
        {
            ui_.mppt1AliveIndicator().setStyleSheet(MPPT_ALIVE);
        }
        else
        {
            ui_.mppt1AliveIndicator().setStyleSheet(MPPT_DEAD);
        }

        mpptOnePower_ = mppt.arrayCurrent() * mppt.arrayVoltage();

        ui_.mppt1ArrayVoltage().setText(QString::number(mppt.arrayVoltage()) + VOLTAGE_UNIT);
        ui_.mppt1ArrayCurrent().setText(QString::number(mppt.arrayCurrent()) + CURRENT_UNIT);
        ui_.mppt1ArrayPower().setText(QString::number(mpptOnePower_) + POWER_UNIT);
        ui_.mppt1BatteryVoltage().setText(QString::number(mppt.batteryVoltage()) + VOLTAGE_UNIT);
        ui_.mppt1Temperature().setText(QString::number(mppt.temperature()) + TEMPERATURE_UNIT);
    }
    else if (i == 2)
    {
        if (mppt.alive())
        {
            ui_.mppt2AliveIndicator().setStyleSheet(MPPT_ALIVE);
        }
        else
        {
            ui_.mppt2AliveIndicator().setStyleSheet(MPPT_DEAD);
        }

        mpptTwoPower_ = mppt.arrayCurrent() * mppt.arrayVoltage();

        ui_.mppt2ArrayVoltage().setText(QString::number(mppt.arrayVoltage()) + VOLTAGE_UNIT);
        ui_.mppt2ArrayCurrent().setText(QString::number(mppt.arrayCurrent()) + CURRENT_UNIT);
        ui_.mppt2ArrayPower().setText(QString::number(mpptTwoPower_) + POWER_UNIT);
        ui_.mppt2BatteryVoltage().setText(QString::number(mppt.batteryVoltage()) + VOLTAGE_UNIT);
        ui_.mppt2Temperature().setText(QString::number(mppt.temperature()) + TEMPERATURE_UNIT);
    }

    ui_.totalArrayPower().setText(QString::number(mpptZeroPower_ + mpptOnePower_ + mpptTwoPower_) + POWER_UNIT);
}
