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

    QString RED = "red";
    QString YELLOW = "yellow";
}

BatteryFaultList::BatteryFaultList()
    : errorLabels_({
          FaultLabel(INTERNAL_COMMUNICATION_FAULT, RED, 0, false)
          , FaultLabel(INTERNAL_CONVERSION_FAULT, RED, 0, false)
          , FaultLabel(WEAK_CELL_FAULT, RED, 0, false)
          , FaultLabel(LOW_CELL_VOLTAGE_FAULT, RED, 0, false)
          , FaultLabel(OPEN_WIRING_FAULT, RED, 0, false)
          , FaultLabel(CURRENT_SENSOR_FAULT, RED, 0, false)
          , FaultLabel(PACK_VOLTAGE_SENSOR, RED, 0, false)
          , FaultLabel(WEAK_PACK_FAULT, RED, 0, false)
          , FaultLabel(VOLTAGE_REDUNDANCY_FAULT, RED, 0, false)
          , FaultLabel(FAN_MONITOR_FAULT, RED, 0, false)
          , FaultLabel(THERMISTOR_FAULT, RED, 0, false)
          , FaultLabel(CANBUS_COMMUNICATIONS_FAULT, RED, 0, false)
          , FaultLabel(ALWAYS_ON_SUPPLY_FAULT, RED, 0, false)
          , FaultLabel(HIGH_VOLTAGE_ISOLATION_FAULT, RED, 0, false)
          , FaultLabel(POWER_SUPPLY_FAULT, RED, 0, false)
          , FaultLabel(CHARGE_LIMIT_ENFORCEMENT_FAULT, RED, 0, false)
          , FaultLabel(DISCHARGE_LIMIT_ENFORCEMENT_FAULT, RED, 0, false)
          , FaultLabel(CHARGER_SAFETY_RELAY_FAULT, RED, 0, false)
          , FaultLabel(INTERNAL_MEMORY_FAULT, RED, 0, false)
          , FaultLabel(INTERNAL_THERMISTOR_FAULT, RED, 0, false)
          , FaultLabel(INTERNAL_LOGIC_FAULT, RED, 0, false)
          })
    , limitLabels_({
                   FaultLabel(DCL_REDUCED_DUE_TO_LOW_SOC, YELLOW, 1, false)
                   , FaultLabel(DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, YELLOW, 1, false)
                   , FaultLabel(DCL_REDUCED_DUE_TO_TEMPERATURE, YELLOW, 1, false)
                   , FaultLabel(DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE, YELLOW, 1, false)
                   , FaultLabel(DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE, YELLOW, 1, false)
                   , FaultLabel(DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE, YELLOW, 1, false)
                   , FaultLabel(DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_SOC, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_TEMPERATURE, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_CHARGER_LATCH, YELLOW, 1, false)
                   , FaultLabel(CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT, YELLOW, 1, false)
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

void BatteryFaultList::updateErrors(const BatteryErrorFlags &errorFlags)
{
    errorLabels_[0].setIsActive(errorFlags.internalCommununicationFault());
    errorLabels_[1].setIsActive(errorFlags.internalConversionFault());
    errorLabels_[2].setIsActive(errorFlags.weakCellFault());
    errorLabels_[3].setIsActive(errorFlags.lowCellVoltageFault());
    errorLabels_[4].setIsActive(errorFlags.openWiringFault());
    errorLabels_[5].setIsActive(errorFlags.currentSensorFault());
    errorLabels_[6].setIsActive(errorFlags.packVoltageSensorFault());
    errorLabels_[7].setIsActive(errorFlags.weakPackFault());
    errorLabels_[8].setIsActive(errorFlags.voltageRedundancyFault());
    errorLabels_[9].setIsActive(errorFlags.fanMonitorFault());
    errorLabels_[10].setIsActive(errorFlags.thermistorFault());
    errorLabels_[11].setIsActive(errorFlags.canbusCommunicationsFault());
    errorLabels_[12].setIsActive(errorFlags.alwaysOnSupplyFault());
    errorLabels_[13].setIsActive(errorFlags.highVoltageIsolationFault());
    errorLabels_[14].setIsActive(errorFlags.powerSupplyFault12V());
    errorLabels_[15].setIsActive(errorFlags.chargeLimitEnforcementFault());
    errorLabels_[16].setIsActive(errorFlags.dischargeLimitEnforcementFault());
    errorLabels_[17].setIsActive(errorFlags.chargerSafetyRelayFault());
    errorLabels_[18].setIsActive(errorFlags.internalMemoryFault());
    errorLabels_[19].setIsActive(errorFlags.internalThermistorFault());
    errorLabels_[20].setIsActive(errorFlags.internalLogicFault());
}

void BatteryFaultList::updateLimits(const BatteryLimitFlags &limitFlags)
{
    limitLabels_[0].setIsActive(limitFlags.dclReducedDueToLowSoc());
    limitLabels_[1].setIsActive(limitFlags.dclReducedDueToHighCellResistance());
    limitLabels_[2].setIsActive(limitFlags.dclReducedDueToTemperature());
    limitLabels_[3].setIsActive(limitFlags.dclReducedDueToLowCellVoltage());
    limitLabels_[4].setIsActive(limitFlags.dclReducedDueToLowPackVoltage());
    limitLabels_[5].setIsActive(limitFlags.dclandCclReducedDueToVoltageFailsafe());
    limitLabels_[6].setIsActive(limitFlags.dclandCclReducedDueToCommunicationFailsafe());
    limitLabels_[7].setIsActive(limitFlags.cclReducedDueToHighSoc());
    limitLabels_[8].setIsActive(limitFlags.cclReducedDueToHighCellResistance());
    limitLabels_[9].setIsActive(limitFlags.cclReducedDueToTemperature());
    limitLabels_[10].setIsActive(limitFlags.cclReducedDueToHighCellVoltage());
    limitLabels_[11].setIsActive(limitFlags.cclReducedDueToHighPackVoltage());
    limitLabels_[12].setIsActive(limitFlags.cclReducedDueToChargerLatch());
    limitLabels_[13].setIsActive(limitFlags.cclReducedDueToAlternateCurrentLimit());
}