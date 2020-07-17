#pragma once

#include <QMap>

enum class MotorFaults
{
    MOTOR_OVER_SPEED,
    SOFTWARE_OVER_CURRENT,
    DC_BUS_OVER_VOLTAGE,
    BAD_MOTOR_POSITION_HALL_SEQUENCE,
    WATCHDOG_CAUSED_LAST_RESET,
    CONFIG_READ_ERROR,
    RAIL_UNDER_VOLTAGE_LOCK_OUT,
    DESATURATION_FAULT,
    OUTPUT_VOLTAGE_PWM_LIMIT,
    MOTOR_CURRENT_LIMIT,
    VELOCITY_LIMIT,
    BUS_CURRENT_LIMIT,
    BUS_VOLTAGE_UPPER_LIMIT,
    BUS_VOLTAGE_LOWER_LIMIT,
    IPM_MOTOR_TEMPERATURE_LIMIT
};

const QMap<MotorFaults, QString> motorFaultsTexts = {
    { MotorFaults::MOTOR_OVER_SPEED, "Motor Over Speed" },
    { MotorFaults::SOFTWARE_OVER_CURRENT, "Software Over Current" },
    { MotorFaults::DC_BUS_OVER_VOLTAGE, "DC Bus Over Voltage" },
    { MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE, "Bad Motor Position Hall Sequence"},
    { MotorFaults::WATCHDOG_CAUSED_LAST_RESET, "Watchdog Caused Last Reset" },
    { MotorFaults::CONFIG_READ_ERROR,  "Config Read Error" },
    { MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT,  "Rail Under-Voltage Lock Out" },
    { MotorFaults::DESATURATION_FAULT, "Desaturation Fault" },
    { MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT, "Output Voltage PWM Limit" },
    { MotorFaults::MOTOR_CURRENT_LIMIT, "Motor Current Limit" },
    { MotorFaults::VELOCITY_LIMIT, "Velocity Limit" },
    { MotorFaults::BUS_CURRENT_LIMIT, "Bus Current Limit" },
    { MotorFaults::BUS_VOLTAGE_UPPER_LIMIT, "Bus Voltage Upper Limit" },
    { MotorFaults::BUS_VOLTAGE_LOWER_LIMIT, "Bus Voltage Lower Limit" },
    { MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT, "IPM or Motor Temperature Limit" }
};
