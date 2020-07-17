#include "MotorFaultsUpdater.h"
#include "../PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "MotorFaultsResources.h"
#include "Faults/FaultLabel/FaultLabel.h"

MotorFaultsUpdater::MotorFaultsUpdater(const MotorFaultsPresenter &presenter, I_FaultList &faultList)
    : motorFaultsPresenter_(presenter)
    , faultList_(faultList)
{
    connect(&motorFaultsPresenter_, SIGNAL(motorZeroErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorZeroErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter_, SIGNAL(motorZeroLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorZeroLimitFlagsReceived(LimitFlags)));
    connect(&motorFaultsPresenter_, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)),
            this, SLOT(motorOneErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsPresenter_, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
            this, SLOT(motorOneLimitFlagsReceived(LimitFlags)));
}

void MotorFaultsUpdater::motorZeroErrorFlagsReceived(ErrorFlags motorZeroErrorFlags)
{
    QMap<MotorFaults , FaultLabel>& faults = faultList_.faults();
    if(faults.contains(MotorFaults::MOTOR_OVER_SPEED))
    {
        faults[MotorFaults::MOTOR_OVER_SPEED].setActive(motorZeroErrorFlags.motorOverSpeed());
    }
    if(faults.contains(MotorFaults::SOFTWARE_OVER_CURRENT))
    {
        faults[MotorFaults::SOFTWARE_OVER_CURRENT].setActive(motorZeroErrorFlags.softwareOverCurrent());
    }
    if(faults.contains(MotorFaults::DC_BUS_OVER_VOLTAGE))
    {
        faults[MotorFaults::DC_BUS_OVER_VOLTAGE].setActive(motorZeroErrorFlags.dcBusOverVoltage());
    }
    if(faults.contains(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE))
    {
        faults[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE].setActive(motorZeroErrorFlags.badMotorPositionHallSequence());
    }
    if(faults.contains(MotorFaults::WATCHDOG_CAUSED_LAST_RESET))
    {
        faults[MotorFaults::WATCHDOG_CAUSED_LAST_RESET].setActive(motorZeroErrorFlags.watchdogCausedLastReset());
    }
    if(faults.contains(MotorFaults::CONFIG_READ_ERROR))
    {
        faults[MotorFaults::CONFIG_READ_ERROR].setActive(motorZeroErrorFlags.configReadError());
    }
    if(faults.contains(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT))
    {
        faults[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT].setActive(motorZeroErrorFlags.railUnderVoltageLockOut());
    }
    if(faults.contains(MotorFaults::DESATURATION_FAULT))
    {
        faults[MotorFaults::DESATURATION_FAULT].setActive(motorZeroErrorFlags.desaturationFault());
    }
}

void MotorFaultsUpdater::motorZeroLimitFlagsReceived(LimitFlags motorZeroLimitFlags)
{
    QMap<MotorFaults , FaultLabel>& faults = faultList_.faults();
    if(faults.contains(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT))
    {
        faults[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT].setActive(motorZeroLimitFlags.outputVoltagePwmLimit());
    }
    if(faults.contains(MotorFaults::MOTOR_CURRENT_LIMIT))
    {
        faults[MotorFaults::MOTOR_CURRENT_LIMIT].setActive(motorZeroLimitFlags.motorCurrentLimit());
    }
    if(faults.contains(MotorFaults::VELOCITY_LIMIT))
    {
        faults[MotorFaults::VELOCITY_LIMIT].setActive(motorZeroLimitFlags.velocityLimit());
    }
    if(faults.contains(MotorFaults::BUS_CURRENT_LIMIT))
    {
        faults[MotorFaults::BUS_CURRENT_LIMIT].setActive(motorZeroLimitFlags.busCurrentLimit());
    }
    if(faults.contains(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT))
    {
        faults[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT].setActive(motorZeroLimitFlags.busVoltageUpperLimit());
    }
    if(faults.contains(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT))
    {
        faults[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT].setActive(motorZeroLimitFlags.busVoltageLowerLimit());
    }
    if(faults.contains(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT))
    {
        faults[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT].setActive(motorZeroLimitFlags.ipmOrMotorTemperatureLimit());
    }
}

void MotorFaultsUpdater::motorOneErrorFlagsReceived(ErrorFlags motorOneErrorFlags)
{
    QMap<MotorFaults , FaultLabel>& faults = faultList_.faults();
    if(faults.contains(MotorFaults::MOTOR_OVER_SPEED))
    {
        faults[MotorFaults::MOTOR_OVER_SPEED].setActive(motorOneErrorFlags.motorOverSpeed());
    }
    if(faults.contains(MotorFaults::SOFTWARE_OVER_CURRENT))
    {
        faults[MotorFaults::SOFTWARE_OVER_CURRENT].setActive(motorOneErrorFlags.softwareOverCurrent());
    }
    if(faults.contains(MotorFaults::DC_BUS_OVER_VOLTAGE))
    {
        faults[MotorFaults::DC_BUS_OVER_VOLTAGE].setActive(motorOneErrorFlags.dcBusOverVoltage());
    }
    if(faults.contains(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE))
    {
        faults[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE].setActive(motorOneErrorFlags.badMotorPositionHallSequence());
    }
    if(faults.contains(MotorFaults::WATCHDOG_CAUSED_LAST_RESET))
    {
        faults[MotorFaults::WATCHDOG_CAUSED_LAST_RESET].setActive(motorOneErrorFlags.watchdogCausedLastReset());
    }
    if(faults.contains(MotorFaults::CONFIG_READ_ERROR))
    {
        faults[MotorFaults::CONFIG_READ_ERROR].setActive(motorOneErrorFlags.configReadError());
    }
    if(faults.contains(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT))
    {
        faults[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT].setActive(motorOneErrorFlags.railUnderVoltageLockOut());
    }
    if(faults.contains(MotorFaults::DESATURATION_FAULT))
    {
        faults[MotorFaults::DESATURATION_FAULT].setActive(motorOneErrorFlags.desaturationFault());
    }
}

void MotorFaultsUpdater::motorOneLimitFlagsReceived(LimitFlags motorOneLimitFlags)
{
    QMap<MotorFaults , FaultLabel>& faults = faultList_.faults();
    if(faults.contains(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT))
    {
        faults[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT].setActive(motorOneLimitFlags.outputVoltagePwmLimit());
    }
    if(faults.contains(MotorFaults::MOTOR_CURRENT_LIMIT))
    {
        faults[MotorFaults::MOTOR_CURRENT_LIMIT].setActive(motorOneLimitFlags.motorCurrentLimit());
    }
    if(faults.contains(MotorFaults::VELOCITY_LIMIT))
    {
        faults[MotorFaults::VELOCITY_LIMIT].setActive(motorOneLimitFlags.velocityLimit());
    }
    if(faults.contains(MotorFaults::BUS_CURRENT_LIMIT))
    {
        faults[MotorFaults::BUS_CURRENT_LIMIT].setActive(motorOneLimitFlags.busCurrentLimit());
    }
    if(faults.contains(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT))
    {
        faults[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT].setActive(motorOneLimitFlags.busVoltageUpperLimit());
    }
    if(faults.contains(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT))
    {
        faults[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT].setActive(motorOneLimitFlags.busVoltageLowerLimit());
    }
    if(faults.contains(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT))
    {
        faults[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT].setActive(motorOneLimitFlags.ipmOrMotorTemperatureLimit());
    }
}
