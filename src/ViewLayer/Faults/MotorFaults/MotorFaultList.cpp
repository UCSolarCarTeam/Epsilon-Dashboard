#include "MotorFaultList.h"

namespace
{
    int NUMBER_OF_MOTOR_ERRORS = 8;
    int NUMBER_OF_MOTOR_LIMITS = 7;
    //Motor errors
    QString MOTOR_OVER_SPEED = "Motor Over Speed";
    QString SOFTWARE_OVER_CURRENT = "Software Over Current";
    QString DC_BUS_OVER_VOLTAGE = "DC Bus Over Voltage";
    QString DESATURATION_FAULT = "Desaturation Fault";
    QString BAD_MOTOR_POSITION_HALL_SEQUENCE = "Bad Motor Position Hall Sequence";
    QString WATCHDOG_CAUSED_LAST_RESET = "Watchdog Caused Last Reset";
    QString CONFIG_READ_ERROR = "Config Read Error";
    QString RAIL_UNDER_VOLTAGE_LOCK_OUT = "Rail Under-Voltage Lock Out";
    //Motor limits
    QString OUTPUT_VOLTAGE_PWM_LIMIT = "Output Voltage PWM Limit";
    QString MOTOR_CURRENT_LIMIT = "Motor Current Limit";
    QString BUS_CURRENT_LIMIT = "Bus Current Limit";
    QString BUS_VOLTAGE_UPPER_LIMIT = "Bus Voltage Upper Limit";
    QString BUS_VOLTAGE_LOWER_LIMIT = "Bus Voltage Lower Limit";
    QString IPM_MOTOR_TEMPERATURE_LIMIT = "IPM or Motor Temperature Limit";
    QString VELOCITY_LIMIT = "Velocity Limit";
}

MotorFaultList::MotorFaultList()
    : errorLabels_(
{
    FaultLabel(MOTOR_OVER_SPEED, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(SOFTWARE_OVER_CURRENT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DC_BUS_OVER_VOLTAGE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DESATURATION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(WATCHDOG_CAUSED_LAST_RESET, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CONFIG_READ_ERROR, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultPriorities::MEDIUM_PRIORITY, false)
})
, limitLabels_(
{
    FaultLabel(OUTPUT_VOLTAGE_PWM_LIMIT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(MOTOR_CURRENT_LIMIT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(BUS_CURRENT_LIMIT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(BUS_VOLTAGE_UPPER_LIMIT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(BUS_VOLTAGE_LOWER_LIMIT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(IPM_MOTOR_TEMPERATURE_LIMIT, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(VELOCITY_LIMIT, FaultPriorities::LOW_PRIORITY, false)
})
{
}

MotorFaultList::~MotorFaultList()
{
}

FaultLabel MotorFaultList::determineHighestActivePriorityLabel() const
{
    int highestPriorityErrorIndex = -1;

    for (int i = 0; i < NUMBER_OF_MOTOR_ERRORS; i++)
    {
        if (errorLabels_[i].isActive())
        {
            if (highestPriorityErrorIndex == -1)
            {
                highestPriorityErrorIndex = i;
            }
            else if (errorLabels_[i].priority() < errorLabels_[highestPriorityErrorIndex].priority())
            {
                highestPriorityErrorIndex = i;
            }
        }
    }

    int highestPriorityLimitIndex = -1;

    for (int i = 0; i < NUMBER_OF_MOTOR_LIMITS; i++)
    {
        if (limitLabels_[i].isActive())
        {
            if (highestPriorityLimitIndex == -1)
            {
                highestPriorityLimitIndex = i;
            }
            else if (limitLabels_[i].priority() < limitLabels_[highestPriorityLimitIndex].priority())
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
        return errorLabels_[highestPriorityErrorIndex];
    }
    else if (highestPriorityErrorIndex == -1 && highestPriorityLimitIndex > -1)
    {
        return limitLabels_[highestPriorityLimitIndex];
    }
    else
    {
        if (errorLabels_[highestPriorityErrorIndex].priority() <= limitLabels_[highestPriorityLimitIndex].priority())
        {
            return errorLabels_[highestPriorityErrorIndex];
        }
        else
        {
            return limitLabels_[highestPriorityLimitIndex];
        }
    }
}

FaultLabel MotorFaultList::getHighestActivePriorityLabel() const
{
    return determineHighestActivePriorityLabel();
}

QVector<FaultLabel>& MotorFaultList::errorLabels()
{
    return errorLabels_;
}

QVector<FaultLabel>& MotorFaultList::limitLabels()
{
    return limitLabels_;
}

void MotorFaultList::updateErrors(const ErrorFlags& errorFlags)
{
    errorLabels_[0].setActive(errorFlags.motorOverSpeed());
    errorLabels_[1].setActive(errorFlags.softwareOverCurrent());
    errorLabels_[2].setActive(errorFlags.dcBusOverVoltage());
    errorLabels_[3].setActive(errorFlags.desaturationFault());
    errorLabels_[4].setActive(errorFlags.badMotorPositionHallSequence());
    errorLabels_[5].setActive(errorFlags.watchdogCausedLastReset());
    errorLabels_[6].setActive(errorFlags.configReadError());
    errorLabels_[7].setActive(errorFlags.railUnderVoltageLockOut());
}

void MotorFaultList::updateLimits(const LimitFlags& limitFlags)
{
    limitLabels_[0].setActive(limitFlags.outputVoltagePwmLimit());
    limitLabels_[1].setActive(limitFlags.motorCurrentLimit());
    limitLabels_[2].setActive(limitFlags.busCurrentLimit());
    limitLabels_[3].setActive(limitFlags.busVoltageUpperLimit());
    limitLabels_[4].setActive(limitFlags.busVoltageLowerLimit());
    limitLabels_[5].setActive(limitFlags.ipmOrMotorTemperatureLimit());
    limitLabels_[6].setActive(limitFlags.velocityLimit());
}

int MotorFaultList::numberOfActiveLabels() const
{
    int numberOfLabels = 0;

    for (int i = 0; i < errorLabels_.size(); i++)
    {
        if (errorLabels_[i].isActive())
        {
            numberOfLabels++;
        }
    }

    for (int i = 0; i < limitLabels_.size(); i++)
    {
        if (limitLabels_[i].isActive())
        {
            numberOfLabels++;
        }
    }

    return numberOfLabels;
}
