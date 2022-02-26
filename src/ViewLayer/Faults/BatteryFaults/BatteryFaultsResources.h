#pragma once

#include <QMap>

//There are 35 Faults: 21 errors, 14 limits
//All DCL & CCL faults are limits
enum class BatteryFaults
{
    INTERNAL_COMMUNICATION_FAULT,
    INTERNAL_CONVERSION_FAULT,
    WEAK_CELL_FAULT,
    LOW_CELL_VOLTAGE_FAULT,
    OPEN_WIRING_FAULT,
    CURRENT_SENSOR_FAULT,
    PACK_VOLTAGE_SENSOR,
    VOLTAGE_REDUNDANCY_FAULT,
    THERMISTOR_FAULT,
    CANBUS_COMMUNICATIONS_FAULT,
    HIGH_VOLTAGE_ISOLATION_FAULT,
    POWER_SUPPLY_FAULT,
    CHARGE_LIMIT_ENFORCEMENT_FAULT,
    DISCHARGE_LIMIT_ENFORCEMENT_FAULT,
    CHARGER_SAFETY_RELAY_FAULT,
    INTERNAL_THERMISTOR_FAULT,
    INTERNAL_LOGIC_FAULT,
    WEAK_PACK_FAULT,
    INTERNAL_MEMORY_FAULT,
    FAN_MONITOR_FAULT,
    ALWAYS_ON_SUPPLY_FAULT,
    DCL_REDUCED_DUE_TO_TEMPERATURE,
    DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE,
    DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE,
    DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE,
    DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE,
    CCL_REDUCED_DUE_TO_HIGH_SOC,
    CCL_REDUCED_DUE_TO_TEMPERATURE,
    CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE,
    CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE,
    CCL_REDUCED_DUE_TO_CHARGER_LATCH,
    CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT,
    DCL_REDUCED_DUE_TO_LOW_SOC,
    DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE,
    CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE
};

const QMap<BatteryFaults, QString> batteryFaultsText =
{
    { BatteryFaults::INTERNAL_COMMUNICATION_FAULT, "Intern. Comms. Fault" },
    { BatteryFaults::INTERNAL_CONVERSION_FAULT, "Intern. Conv. Fault" },
    { BatteryFaults::WEAK_CELL_FAULT, "Weak Cell Fault" },
    { BatteryFaults::LOW_CELL_VOLTAGE_FAULT, "Low Cell Voltage Fault" },
    { BatteryFaults::OPEN_WIRING_FAULT, "Open Wiring Fault" },
    { BatteryFaults::CURRENT_SENSOR_FAULT, "Current Sensor Fault" },
    { BatteryFaults::PACK_VOLTAGE_SENSOR, "Pack Voltage Sensor" },
    { BatteryFaults::VOLTAGE_REDUNDANCY_FAULT, "Voltage Redundancy Fault" },
    { BatteryFaults::THERMISTOR_FAULT, "Thermistor Fault" },
    { BatteryFaults::CANBUS_COMMUNICATIONS_FAULT, "CANBUS Communications Fault" },
    { BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT, "High Voltage Isolation Fault" },
    { BatteryFaults::POWER_SUPPLY_FAULT, "Power Supply Fault" },
    { BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT, "Charge Limit Enforcement Fault" },
    { BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT, "Discharge Limit Enforcement Fault" },
    { BatteryFaults::CHARGER_SAFETY_RELAY_FAULT, "Charger Safety Relay Fault" },
    { BatteryFaults::INTERNAL_THERMISTOR_FAULT, "Intern. Thermistor Fault" },
    { BatteryFaults::INTERNAL_LOGIC_FAULT, "Intern. Logic Fault" },
    { BatteryFaults::WEAK_PACK_FAULT, "Weak Pack Fault" },
    { BatteryFaults::INTERNAL_MEMORY_FAULT, "Intern. Memory Fault" },
    { BatteryFaults::FAN_MONITOR_FAULT, "Fan Monitor Fault" },
    { BatteryFaults::ALWAYS_ON_SUPPLY_FAULT, "Always-On Supply Fault" },
    { BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE, "DCL Temperature" },
    { BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE, "DCL Low Cell Voltage" },
    { BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE, "DCL Low Pack Voltage" },
    { BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE, "DCL CCL Voltage Failsafe" },
    { BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE, "DCL CCL Communication Failsafe" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC, "CCL High SOC" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE, "CCL Temperature" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE, "CCL High Cell Voltage" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE, "CCL High Pack Voltage" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH, "CCL Charger Latch" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT, "CCL Alternate Current" },
    { BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC, "DCL Low SOC" },
    { BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, "DCL High Cell Resistance" },
    { BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, "CCL High Cell Resistance" }
};
