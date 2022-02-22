#include "BatteryFaultPopulator.h"
#include "BatteryFaultsResources.h"
#include "Faults/FaultPriorities/FaultPriorities.h"
#include "I_BatteryFaultList.h"

BatteryFaultPopulator::BatteryFaultPopulator(I_BatteryFaultList& faultList)
    : faultList_(faultList)
{

}

void BatteryFaultPopulator::populateFaults()
{
    QMap<BatteryFaults, FaultDisplayData>& faults =  faultList_.faults();
    faults.insert(BatteryFaults::INTERNAL_COMMUNICATION_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_COMMUNICATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_CONVERSION_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_CONVERSION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::WEAK_CELL_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::WEAK_CELL_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::LOW_CELL_VOLTAGE_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::LOW_CELL_VOLTAGE_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::OPEN_WIRING_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::OPEN_WIRING_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CURRENT_SENSOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CURRENT_SENSOR_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::PACK_VOLTAGE_SENSOR, FaultDisplayData(batteryFaultsText[BatteryFaults::PACK_VOLTAGE_SENSOR], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::VOLTAGE_REDUNDANCY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::VOLTAGE_REDUNDANCY_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::THERMISTOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::THERMISTOR_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CANBUS_COMMUNICATIONS_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CANBUS_COMMUNICATIONS_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::POWER_SUPPLY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::POWER_SUPPLY_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CHARGER_SAFETY_RELAY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CHARGER_SAFETY_RELAY_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_THERMISTOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_THERMISTOR_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_LOGIC_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_LOGIC_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::WEAK_PACK_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::WEAK_PACK_FAULT], FaultPriorities::MEDIUM_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_MEMORY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_MEMORY_FAULT], FaultPriorities::MEDIUM_PRIORITY, false));
    faults.insert(BatteryFaults::FAN_MONITOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::FAN_MONITOR_FAULT], FaultPriorities::LOW_PRIORITY, false));
    faults.insert(BatteryFaults::ALWAYS_ON_SUPPLY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::ALWAYS_ON_SUPPLY_FAULT], FaultPriorities::LOW_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC], FaultPriorities::MEDIUM_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE], FaultPriorities::LOW_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE], FaultPriorities::LOW_PRIORITY, false));

}

void BatteryFaultPopulator::populateRaceFaults()
{
    QMap<BatteryFaults, FaultDisplayData>& faults =  faultList_.faults();
    faults.insert(BatteryFaults::INTERNAL_COMMUNICATION_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_COMMUNICATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_CONVERSION_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_CONVERSION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::WEAK_CELL_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::WEAK_CELL_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::LOW_CELL_VOLTAGE_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::LOW_CELL_VOLTAGE_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::OPEN_WIRING_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::OPEN_WIRING_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CURRENT_SENSOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CURRENT_SENSOR_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::PACK_VOLTAGE_SENSOR, FaultDisplayData(batteryFaultsText[BatteryFaults::PACK_VOLTAGE_SENSOR], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::VOLTAGE_REDUNDANCY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::VOLTAGE_REDUNDANCY_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::THERMISTOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::THERMISTOR_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CANBUS_COMMUNICATIONS_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CANBUS_COMMUNICATIONS_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::POWER_SUPPLY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::POWER_SUPPLY_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CHARGER_SAFETY_RELAY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::CHARGER_SAFETY_RELAY_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_THERMISTOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_THERMISTOR_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_LOGIC_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_LOGIC_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::WEAK_PACK_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::WEAK_PACK_FAULT], FaultPriorities::MEDIUM_PRIORITY, false));
    faults.insert(BatteryFaults::INTERNAL_MEMORY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::INTERNAL_MEMORY_FAULT], FaultPriorities::MEDIUM_PRIORITY, false));
    faults.insert(BatteryFaults::FAN_MONITOR_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::FAN_MONITOR_FAULT], FaultPriorities::LOW_PRIORITY, false));
    faults.insert(BatteryFaults::ALWAYS_ON_SUPPLY_FAULT, FaultDisplayData(batteryFaultsText[BatteryFaults::ALWAYS_ON_SUPPLY_FAULT], FaultPriorities::LOW_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC], FaultPriorities::MEDIUM_PRIORITY, false));
    faults.insert(BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultDisplayData(batteryFaultsText[BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE], FaultPriorities::LOW_PRIORITY, false));
    faults.insert(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultDisplayData(batteryFaultsText[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE], FaultPriorities::LOW_PRIORITY, false));
}
