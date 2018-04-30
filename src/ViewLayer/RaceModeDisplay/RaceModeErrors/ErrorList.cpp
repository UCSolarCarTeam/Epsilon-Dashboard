#include "ErrorList.h"

namespace
{
    int NUMBER_OF_MOTOR_ERRORS = 8;
}

ErrorList::ErrorList()
//    :errorList_({
//         FaultLabel(QString::fromLatin1("Motor Over Speed"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("Software Over Current"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("DC Bus Over Voltage"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("Bad Motor Position Hall Sequence"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("Watchdog Caused Last Reset"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("Config Read Error"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("Rail Under-Voltage Lock Out"), QString::fromLatin1("red"), 0, false)
//         ,FaultLabel(QString::fromLatin1("Desaturation Fault"), QString::fromLatin1("red"), 0, false)
//         })
    :errorList_(10)
{
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
