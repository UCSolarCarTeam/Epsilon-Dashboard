#include "FaultList.h"
#include <QDebug>

namespace
{
    int NUMBER_OF_MOTOR_ERRORS = 8;
    int NUMBER_OF_MOTOR_LIMITS = 7;
    //Motor errors
    QString MOTOR_OVER_SPEED = "Motor Over Speed";
    QString SOFTWARE_OVER_CURRENT = "Software Over Current";
    QString DC_BUS_OVER_VOLTAGE = "DC Bus Over Voltage";
    QString BAD_MOTOR_POSITION_HALL_SEQUENCE = "Bad Motor Position Hall Sequence";
    QString WATCHDOG_CAUSED_LAST_RESET = "Watchdog Caused Last Reset";
    QString CONFIG_READ_ERROR = "Config Read Error";
    QString RAIL_UNDER_VOLTAGE_LOCK_OUT = "Rail Under-Voltage Lock Out";
    QString DESATURATION_FAULT = "Desaturation Fault";
    //Motor limits
    QString OUTPUT_VOLTAGE_PWM_LIMIT = "Output Voltage PWM Limit";
    QString MOTOR_CURRENT_LIMIT = "Motor Current Limit";
    QString VELOCITY_LIMIT = "Velocity Limit";
    QString BUS_CURRENT_LIMIT = "Bus Current Limit";
    QString BUS_VOLTAGE_UPPER_LIMIT = "Bus Voltage Upper Limit";
    QString BUS_VOLTAGE_LOWER_LIMIT = "Bus Voltage Lower Limit";
    QString IPM_MOTOR_TEMPERATURE_LIMIT = "IPM or Motor Temperature Limit";

    QString RED = "red";
    QString YELLOW = "yellow";
}

FaultList::FaultList()
    : errorList_(
{
    FaultLabel(MOTOR_OVER_SPEED, RED, 0, false)
    , FaultLabel(SOFTWARE_OVER_CURRENT, RED, 0, false)
    , FaultLabel(DC_BUS_OVER_VOLTAGE, RED, 0, false)
    , FaultLabel(BAD_MOTOR_POSITION_HALL_SEQUENCE, RED, 0, false)
    , FaultLabel(WATCHDOG_CAUSED_LAST_RESET, RED, 0, false)
    , FaultLabel(CONFIG_READ_ERROR, RED, 0, false)
    , FaultLabel(RAIL_UNDER_VOLTAGE_LOCK_OUT, RED, 0, false)
    , FaultLabel(DESATURATION_FAULT, RED, 0, false)
})
, limitList_({FaultLabel(OUTPUT_VOLTAGE_PWM_LIMIT, YELLOW, 1, false)
              , FaultLabel(MOTOR_CURRENT_LIMIT, YELLOW, 1, false)
              , FaultLabel(VELOCITY_LIMIT, YELLOW, 1, false)
              , FaultLabel(BUS_CURRENT_LIMIT, YELLOW, 1, false)
              , FaultLabel(BUS_VOLTAGE_UPPER_LIMIT, YELLOW, 1, false)
              , FaultLabel(BUS_VOLTAGE_LOWER_LIMIT, YELLOW, 1, false)
              , FaultLabel(IPM_MOTOR_TEMPERATURE_LIMIT, YELLOW, 1, false)
             })
{
}

FaultList::~FaultList()
{
}

FaultLabel FaultList::getHighestActivePriorityLabel() const
{

    int highestPriorityErrorIndex = -1;

    for (int i = 0; i < NUMBER_OF_MOTOR_ERRORS; i++)
    {
        if (errorList_[i].isActive())
        {
            if (highestPriorityErrorIndex == -1)
            {
                highestPriorityErrorIndex = i;
            }
            else if (errorList_[i].priority() > errorList_[highestPriorityErrorIndex].priority())
            {
                highestPriorityErrorIndex = i;
            }
        }
    }

    int highestPriorityLimitIndex = -1;

    for (int i = 0; i < NUMBER_OF_MOTOR_LIMITS; i++)
    {
        if (limitList_[i].isActive())
        {
            if (highestPriorityLimitIndex == -1)
            {
                highestPriorityLimitIndex = i;
            }
            else if (errorList_[i].priority() > errorList_[highestPriorityLimitIndex].priority())
            {
                highestPriorityLimitIndex = i;
            }
        }
    }

    //Returns the FaultLabel with the highest priority, where 0 is the highest priority, 1 is the second highest etc.
    if (highestPriorityErrorIndex == -1 && highestPriorityLimitIndex == -1)
    {
        return FaultLabel();
    }
    else if (highestPriorityErrorIndex > -1 && highestPriorityLimitIndex == -1)
    {
        return errorList_[highestPriorityErrorIndex];
    }
    else if (highestPriorityErrorIndex == -1 && highestPriorityLimitIndex > -1)
    {
        return limitList_[highestPriorityLimitIndex];
    }
    else
    {
        if (errorList_[highestPriorityErrorIndex].priority() <= limitList_[highestPriorityLimitIndex].priority())
        {
            return errorList_[highestPriorityErrorIndex];
        }
        else
        {
            return limitList_[highestPriorityLimitIndex];
        }
    }
}

QVector<FaultLabel> FaultList::getErrorLabelList() const
{
    return errorList_;
}

QVector<FaultLabel> FaultList::getLimitLabelList() const
{
    return limitList_;
}

void FaultList::updateErrors(const ErrorFlags& errorFlags)
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

void FaultList::updateLimits(const LimitFlags& limitFlags)
{
    limitList_[0].setIsActive(limitFlags.outputVoltagePwmLimit());
    limitList_[1].setIsActive(limitFlags.motorCurrentLimit());
    limitList_[2].setIsActive(limitFlags.velocityLimit());
    limitList_[3].setIsActive(limitFlags.busCurrentLimit());
    limitList_[4].setIsActive(limitFlags.busVoltageUpperLimit());
    limitList_[5].setIsActive(limitFlags.busVoltageLowerLimit());
    limitList_[6].setIsActive(limitFlags.ipmOrMotorTemperatureLimit());
}
