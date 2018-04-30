#include "ErrorList.h"
#include <QDebug>

namespace
{
    int NUMBER_OF_MOTOR_ERRORS = 8;
    QString MOTOR_OVER_SPEED = "Motor Over Speed";
    QString SOFTWARE_OVER_CURRENT = "Software Over Current";
    QString DC_BUS_OVER_VOLTAGE = "DC Bus Over Voltage";
    QString BAD_MOTOR_POSITION_HALL_SEQUENCE = "Bad Motor Position Hall Sequence";
    QString WATCHDOG_CAUSED_LAST_RESET = "Watchdog Caused Last Reset";
    QString CONFIG_READ_ERROR = "Config Read Error";
    QString RAIL_UNDER_VOLTAGE_LOCK_OUT = "Rail Under-Voltage Lock Out";
    QString DESATURATION_FAULT = "Desaturation Fault";
    QString RED = "red";
}

ErrorList::ErrorList()
    :errorList_({
                FaultLabel(MOTOR_OVER_SPEED, RED, 0, false)
                ,FaultLabel(SOFTWARE_OVER_CURRENT, RED, 0, false)
                ,FaultLabel(DC_BUS_OVER_VOLTAGE, RED, 0, false)
                ,FaultLabel(BAD_MOTOR_POSITION_HALL_SEQUENCE, RED, 0, false)
                ,FaultLabel(WATCHDOG_CAUSED_LAST_RESET,RED, 0, false)
                ,FaultLabel(CONFIG_READ_ERROR, RED, 0, false)
                ,FaultLabel(RAIL_UNDER_VOLTAGE_LOCK_OUT, RED, 0, false)
                ,FaultLabel(DESATURATION_FAULT, RED, 0, false)
                })
{
//   QVector<FaultLabel> errorList({
//         FaultLabel(MOTOR_OVER_SPEED, RED, 0, false)
//         ,FaultLabel(SOFTWARE_OVER_CURRENT, RED, 0, false)
//         ,FaultLabel(DC_BUS_OVER_VOLTAGE, RED, 0, false)
//         ,FaultLabel(BAD_MOTOR_POSITION_HALL_SEQUENCE, RED, 0, false)
//         ,FaultLabel(WATCHDOG_CAUSED_LAST_RESET,RED, 0, false)
//         ,FaultLabel(CONFIG_READ_ERROR, RED, 0, false)
//         ,FaultLabel(RAIL_UNDER_VOLTAGE_LOCK_OUT, RED, 0, false)
//         ,FaultLabel(DESATURATION_FAULT, RED, 0, false)
//         });
//   errorList_ = errorList;
}

ErrorList::~ErrorList()
{
}

FaultLabel ErrorList::getHighestActivePriority() const
{
    for (int i = 0; i < NUMBER_OF_MOTOR_ERRORS; i++)
    {
        if(errorList_[i].isActive())
        {
            return errorList_[i];
        }
    }
    return FaultLabel();
}

QVector<FaultLabel> ErrorList::getErrorLabelList() const
{
    return errorList_;
}

void ErrorList::updateFaults(const ErrorFlags& errorFlags)
{
    errorList_[0].setIsActive(errorFlags.motorOverSpeed());
    errorList_[1].setIsActive(errorFlags.softwareOverCurrent());
    errorList_[2].setIsActive(errorFlags.dcBusOverVoltage());
    errorList_[3].setIsActive(errorFlags.badMotorPositionHallSequence());
    errorList_[4].setIsActive(errorFlags.watchdogCausedLastReset());
    errorList_[5].setIsActive(errorFlags.configReadError());
    errorList_[6].setIsActive(errorFlags.railUnderVoltageLockOut());
    errorList_[7].setIsActive(errorFlags.desaturationFault());
}
