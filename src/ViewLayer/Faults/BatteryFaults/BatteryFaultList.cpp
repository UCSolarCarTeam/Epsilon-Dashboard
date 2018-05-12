#include "BatteryFaultList.h"

namespace
{
    int NUMBER_OF_BATTERY_ERRORS = 21;
    int NUMBER_OF_BATTERY_LIMITS = 14;
    //Battery errors
    QString INTERNAL_COMMUNICATION_FAULT = "Internal Communication Fault";
    QString INTERNAL_CONVERSION_FAULT = "Internal Conversion Fault";
    QString WEAK_CELL_FAULT = "Weak Cell Fault";
    QString LOW_CELL_VOLTAGE_FAULT = "Low Cell Voltage Fault";
    QString OPEN_WIRING_FAULT = "Open Wiring Fault";
    QString CURRENT_SENSOR_FAULT = "Current Sensor Fault";
    QString PACK_VOLTAGE_SENSOR = "Pack Voltage Sensor";
    QString WEAK_PACK_FAULT = "Weak Pack Fault";
    QString VOLTAGE_REDUNDANCY_FAULT = "Voltage Redundancy Fault";
    QString FAN_MONITOR_FAULT = "Fan Monitor Fault";
    QString THERMISTOR_FAULT = "Thermistor Fault";
    QString CANBUS_COMMUNICATIONS_FAULT = "CANBUS Communications Fault";
    QString ALWAYS_ON_SUPPLY_FAULT = "Always-On Supply Fault";
    QString HIGH_VOLTAGE_ISOLATION_FAULT = "High Voltage Isolation Fault";
    QString POWER_SUPPLY_FAULT = "Power Supply Fault";
    QString CHARGE_LIMIT_ENFORCEMENT_FAULT = "Charge Limit Enforcement Fault";
    QString DISCHARGE_LIMIT_ENFORCEMENT_FAULT = "Discharge Limit Enforcement Fault";
    QString CHARGER_SAFETY_RELAY_FAULT = "Charger Safety Relay Fault";
    QString INTERNAL_MEMORY_FAULT = "Internal Memory Fault";
    QString INTERNAL_THERMISTOR_FAULT = "Internal Thermistor Fault";
    QString INTERNAL_LOGIC_FAULT = "Internal Logic Fault";
    //Battery limits
    QString DCL_REDUCED_DUE_TO_LOW_SOC = "DCL Reduced Due To Low SOC";
    QString DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "DCL Reduced Due To High Cell Resistance";
    QString DCL_REDUCED_DUE_TO_TEMPERATURE = "DCL Reduced Due To Temperature";
    QString DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE = "DCL Reduced Due To Low Cell Voltage";
    QString DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE = "DCL Reduced Due To Low Pack Voltage";
    QString DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE = "DCL and CCL Reduced Due To Voltage Failsafe";
    QString DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE = "DCL and CCL Reduced Due To Communication Failsafe";
    QString CCL_REDUCED_DUE_TO_HIGH_SOC = "CCL Reduced Due To High SOC";
    QString CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "CCL Reduced Due To High Cell Resistance";
    QString CCL_REDUCED_DUE_TO_TEMPERATURE = "CCL Reduced Due To Temperature";
    QString CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE = "CCL Reduced Due To High Cell Voltage";
    QString CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE = "CCL Reduced Due To High Pack Voltage";
    QString CCL_REDUCED_DUE_TO_CHARGER_LATCH = "CCL Reduced Due To Charger Latch";
    QString CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT = "CCL Reduced Due To Alternate Current Limit";
}

BatteryFaultList::BatteryFaultList()
    : errorLabels_(
{
    FaultLabel(INTERNAL_COMMUNICATION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_CONVERSION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(WEAK_CELL_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(LOW_CELL_VOLTAGE_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(OPEN_WIRING_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CURRENT_SENSOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(PACK_VOLTAGE_SENSOR, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(WEAK_PACK_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(VOLTAGE_REDUNDANCY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(FAN_MONITOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(THERMISTOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CANBUS_COMMUNICATIONS_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(ALWAYS_ON_SUPPLY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(HIGH_VOLTAGE_ISOLATION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(POWER_SUPPLY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CHARGE_LIMIT_ENFORCEMENT_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DISCHARGE_LIMIT_ENFORCEMENT_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CHARGER_SAFETY_RELAY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_MEMORY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_THERMISTOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_LOGIC_FAULT, FaultPriorities::HIGH_PRIORITY, false)
})
, limitLabels_(
{
    FaultLabel(DCL_REDUCED_DUE_TO_LOW_SOC, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_TEMPERATURE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_SOC, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_TEMPERATURE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_CHARGER_LATCH, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT, FaultPriorities::MEDIUM_PRIORITY, false)
})
{
}

BatteryFaultList::~BatteryFaultList()
{
}

FaultLabel BatteryFaultList::determineHighestActivePriorityLabel() const
{
    int highestPriorityErrorIndex = -1;

    for (int i = 0; i < NUMBER_OF_BATTERY_ERRORS; i++)
    {
        if (errorLabels_[i].isActive())
        {
            if (highestPriorityErrorIndex == -1)
            {
                highestPriorityErrorIndex = i;
            }
            else if (errorLabels_[i].priority() > errorLabels_[highestPriorityErrorIndex].priority())
            {
                highestPriorityErrorIndex = i;
            }
        }
    }

    int highestPriorityLimitIndex = -1;

    for (int i = 0; i < NUMBER_OF_BATTERY_LIMITS; i++)
    {
        if (limitLabels_[i].isActive())
        {
            if (highestPriorityLimitIndex == -1)
            {
                highestPriorityLimitIndex = i;
            }
            else if (limitLabels_[i].priority() > limitLabels_[highestPriorityLimitIndex].priority())
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

FaultLabel BatteryFaultList::getHighestActivePriorityLabel() const
{
    return determineHighestActivePriorityLabel();
}

QVector<FaultLabel>& BatteryFaultList::errorLabels()
{
    return errorLabels_;
}

QVector<FaultLabel>& BatteryFaultList::limitLabels()
{
    return limitLabels_;
}

void BatteryFaultList::updateErrors(const BatteryErrorFlags& errorFlags)
{
    errorLabels_[0].setActive(errorFlags.internalCommununicationFault());
    errorLabels_[1].setActive(errorFlags.internalConversionFault());
    errorLabels_[2].setActive(errorFlags.weakCellFault());
    errorLabels_[3].setActive(errorFlags.lowCellVoltageFault());
    errorLabels_[4].setActive(errorFlags.openWiringFault());
    errorLabels_[5].setActive(errorFlags.currentSensorFault());
    errorLabels_[6].setActive(errorFlags.packVoltageSensorFault());
    errorLabels_[7].setActive(errorFlags.weakPackFault());
    errorLabels_[8].setActive(errorFlags.voltageRedundancyFault());
    errorLabels_[9].setActive(errorFlags.fanMonitorFault());
    errorLabels_[10].setActive(errorFlags.thermistorFault());
    errorLabels_[11].setActive(errorFlags.canbusCommunicationsFault());
    errorLabels_[12].setActive(errorFlags.alwaysOnSupplyFault());
    errorLabels_[13].setActive(errorFlags.highVoltageIsolationFault());
    errorLabels_[14].setActive(errorFlags.powerSupplyFault12V());
    errorLabels_[15].setActive(errorFlags.chargeLimitEnforcementFault());
    errorLabels_[16].setActive(errorFlags.dischargeLimitEnforcementFault());
    errorLabels_[17].setActive(errorFlags.chargerSafetyRelayFault());
    errorLabels_[18].setActive(errorFlags.internalMemoryFault());
    errorLabels_[19].setActive(errorFlags.internalThermistorFault());
    errorLabels_[20].setActive(errorFlags.internalLogicFault());
}

void BatteryFaultList::updateLimits(const BatteryLimitFlags& limitFlags)
{
    limitLabels_[0].setActive(limitFlags.dclReducedDueToLowSoc());
    limitLabels_[1].setActive(limitFlags.dclReducedDueToHighCellResistance());
    limitLabels_[2].setActive(limitFlags.dclReducedDueToTemperature());
    limitLabels_[3].setActive(limitFlags.dclReducedDueToLowCellVoltage());
    limitLabels_[4].setActive(limitFlags.dclReducedDueToLowPackVoltage());
    limitLabels_[5].setActive(limitFlags.dclandCclReducedDueToVoltageFailsafe());
    limitLabels_[6].setActive(limitFlags.dclandCclReducedDueToCommunicationFailsafe());
    limitLabels_[7].setActive(limitFlags.cclReducedDueToHighSoc());
    limitLabels_[8].setActive(limitFlags.cclReducedDueToHighCellResistance());
    limitLabels_[9].setActive(limitFlags.cclReducedDueToTemperature());
    limitLabels_[10].setActive(limitFlags.cclReducedDueToHighCellVoltage());
    limitLabels_[11].setActive(limitFlags.cclReducedDueToHighPackVoltage());
    limitLabels_[12].setActive(limitFlags.cclReducedDueToChargerLatch());
    limitLabels_[13].setActive(limitFlags.cclReducedDueToAlternateCurrentLimit());
}
