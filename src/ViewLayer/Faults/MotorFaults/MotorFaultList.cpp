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
    : faultLabels_(
{
    FaultLabel(MOTOR_OVER_SPEED, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(SOFTWARE_OVER_CURRENT, FaultPriorities::HIGH_PRIORITY, false, false)
    , FaultLabel(DC_BUS_OVER_VOLTAGE, FaultPriorities::HIGH_PRIORITY, false, false)
    , FaultLabel(DESATURATION_FAULT, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultPriorities::MEDIUM_PRIORITY, false, true)
    , FaultLabel(WATCHDOG_CAUSED_LAST_RESET, FaultPriorities::MEDIUM_PRIORITY, false, true)
    , FaultLabel(CONFIG_READ_ERROR, FaultPriorities::MEDIUM_PRIORITY, false, true)
    , FaultLabel(RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultPriorities::MEDIUM_PRIORITY, false, true)
    , FaultLabel(OUTPUT_VOLTAGE_PWM_LIMIT, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(MOTOR_CURRENT_LIMIT, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(BUS_CURRENT_LIMIT, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(BUS_VOLTAGE_UPPER_LIMIT, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(BUS_VOLTAGE_LOWER_LIMIT, FaultPriorities::HIGH_PRIORITY, false, true)
    , FaultLabel(IPM_MOTOR_TEMPERATURE_LIMIT, FaultPriorities::MEDIUM_PRIORITY, false, true)
    , FaultLabel(VELOCITY_LIMIT, FaultPriorities::LOW_PRIORITY, false, false)
})
, currentFault_(0)
{
}

MotorFaultList::~MotorFaultList()
{
}

FaultLabel MotorFaultList::nextActiveFault()
{
    for (int i = 0; i < (NUMBER_OF_MOTOR_ERRORS + NUMBER_OF_MOTOR_LIMITS); i++)
    {
        int faultIndex = currentFault_;
        currentFault_++;
        currentFault_ %= (NUMBER_OF_MOTOR_ERRORS + NUMBER_OF_MOTOR_LIMITS);

        if (faultLabels_[faultIndex].isActive())
        {
            return faultLabels_[faultIndex];
        }
    }

    return FaultLabel();
}

QVector<FaultLabel>& MotorFaultList::faultLabels()
{
    return faultLabels_;
}

void MotorFaultList::updateErrors(const ErrorFlags& errorFlags)
{
    faultLabels_[0].setActive(errorFlags.motorOverSpeed());
    faultLabels_[1].setActive(errorFlags.softwareOverCurrent());
    faultLabels_[2].setActive(errorFlags.dcBusOverVoltage());
    faultLabels_[3].setActive(errorFlags.desaturationFault());
    faultLabels_[4].setActive(errorFlags.badMotorPositionHallSequence());
    faultLabels_[5].setActive(errorFlags.watchdogCausedLastReset());
    faultLabels_[6].setActive(errorFlags.configReadError());
    faultLabels_[7].setActive(errorFlags.railUnderVoltageLockOut());
}

void MotorFaultList::updateLimits(const LimitFlags& limitFlags)
{
    faultLabels_[0 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.outputVoltagePwmLimit());
    faultLabels_[1 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.motorCurrentLimit());
    faultLabels_[2 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.busCurrentLimit());
    faultLabels_[3 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.busVoltageUpperLimit());
    faultLabels_[4 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.busVoltageLowerLimit());
    faultLabels_[5 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.ipmOrMotorTemperatureLimit());
    faultLabels_[6 + NUMBER_OF_MOTOR_ERRORS].setActive(limitFlags.velocityLimit());
}

int MotorFaultList::numberOfActiveLabels() const
{
    int numberOfLabels = 0;

    for (int i = 0; i < faultLabels_.size(); i++)
    {
        if (faultLabels_[i].isActive())
        {
            numberOfLabels++;
        }
    }

    return numberOfLabels;
}
