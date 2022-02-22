#include "MotorFaultPopulator.h"
#include "MotorFaultsResources.h"
#include "Faults/FaultPriorities/FaultPriorities.h"
#include "I_MotorFaultList.h"


MotorFaultPopulator::MotorFaultPopulator(I_MotorFaultList& faultListZero,
                                         I_MotorFaultList& faultListOne)
    :faultListZero_(faultListZero)
    , faultListOne_(faultListOne)
{

}

void MotorFaultPopulator::populateFaults()
{
    faultListZero_.faults().insert(MotorFaults::MOTOR_OVER_SPEED, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_OVER_SPEED], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::SOFTWARE_OVER_CURRENT, FaultDisplayData(motorFaultsTexts[MotorFaults::SOFTWARE_OVER_CURRENT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::DC_BUS_OVER_VOLTAGE, FaultDisplayData(motorFaultsTexts[MotorFaults::DC_BUS_OVER_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::DESATURATION_FAULT, FaultDisplayData(motorFaultsTexts[MotorFaults::DESATURATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultDisplayData(motorFaultsTexts[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::WATCHDOG_CAUSED_LAST_RESET, FaultDisplayData(motorFaultsTexts[MotorFaults::WATCHDOG_CAUSED_LAST_RESET], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::CONFIG_READ_ERROR, FaultDisplayData(motorFaultsTexts[MotorFaults::CONFIG_READ_ERROR], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultDisplayData(motorFaultsTexts[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::MOTOR_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BUS_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::VELOCITY_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::VELOCITY_LIMIT], FaultPriorities::LOW_PRIORITY, false));

    faultListOne_.faults().insert(MotorFaults::MOTOR_OVER_SPEED, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_OVER_SPEED], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::SOFTWARE_OVER_CURRENT, FaultDisplayData(motorFaultsTexts[MotorFaults::SOFTWARE_OVER_CURRENT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::DC_BUS_OVER_VOLTAGE, FaultDisplayData(motorFaultsTexts[MotorFaults::DC_BUS_OVER_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::DESATURATION_FAULT, FaultDisplayData(motorFaultsTexts[MotorFaults::DESATURATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultDisplayData(motorFaultsTexts[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::WATCHDOG_CAUSED_LAST_RESET, FaultDisplayData(motorFaultsTexts[MotorFaults::WATCHDOG_CAUSED_LAST_RESET], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::CONFIG_READ_ERROR, FaultDisplayData(motorFaultsTexts[MotorFaults::CONFIG_READ_ERROR], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultDisplayData(motorFaultsTexts[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::MOTOR_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BUS_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::VELOCITY_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::VELOCITY_LIMIT], FaultPriorities::LOW_PRIORITY, false));
}

void MotorFaultPopulator::populateRaceFaults()
{
    faultListZero_.faults().insert(MotorFaults::MOTOR_OVER_SPEED, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_OVER_SPEED], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::DESATURATION_FAULT, FaultDisplayData(motorFaultsTexts[MotorFaults::DESATURATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultDisplayData(motorFaultsTexts[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::WATCHDOG_CAUSED_LAST_RESET, FaultDisplayData(motorFaultsTexts[MotorFaults::WATCHDOG_CAUSED_LAST_RESET], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::CONFIG_READ_ERROR, FaultDisplayData(motorFaultsTexts[MotorFaults::CONFIG_READ_ERROR], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultDisplayData(motorFaultsTexts[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::MOTOR_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BUS_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListZero_.faults().insert(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT], FaultPriorities::MEDIUM_PRIORITY, false));

    faultListOne_.faults().insert(MotorFaults::MOTOR_OVER_SPEED, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_OVER_SPEED], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::DESATURATION_FAULT, FaultDisplayData(motorFaultsTexts[MotorFaults::DESATURATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultDisplayData(motorFaultsTexts[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::WATCHDOG_CAUSED_LAST_RESET, FaultDisplayData(motorFaultsTexts[MotorFaults::WATCHDOG_CAUSED_LAST_RESET], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::CONFIG_READ_ERROR, FaultDisplayData(motorFaultsTexts[MotorFaults::CONFIG_READ_ERROR], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultDisplayData(motorFaultsTexts[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::MOTOR_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::MOTOR_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BUS_CURRENT_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultListOne_.faults().insert(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT, FaultDisplayData(motorFaultsTexts[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT], FaultPriorities::MEDIUM_PRIORITY, false));
}
