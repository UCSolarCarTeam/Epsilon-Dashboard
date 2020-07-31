#include "MotorFaultList.h"

MotorFaultList::MotorFaultList()
    : faultLabels_(
{
    FaultLabel(motorFaultsTexts[MotorFaults::MOTOR_OVER_SPEED], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::SOFTWARE_OVER_CURRENT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::DC_BUS_OVER_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::DESATURATION_FAULT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE], FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::WATCHDOG_CAUSED_LAST_RESET], FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::CONFIG_READ_ERROR], FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT], FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::MOTOR_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::BUS_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT], FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT], FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(motorFaultsTexts[MotorFaults::VELOCITY_LIMIT], FaultPriorities::LOW_PRIORITY, false)
})
,currentFault_(0)
{
    faultList_.insert(MotorFaults::MOTOR_OVER_SPEED, FaultLabel(motorFaultsTexts[MotorFaults::MOTOR_OVER_SPEED], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::SOFTWARE_OVER_CURRENT, FaultLabel(motorFaultsTexts[MotorFaults::SOFTWARE_OVER_CURRENT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::DC_BUS_OVER_VOLTAGE, FaultLabel(motorFaultsTexts[MotorFaults::DC_BUS_OVER_VOLTAGE], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::DESATURATION_FAULT, FaultLabel(motorFaultsTexts[MotorFaults::DESATURATION_FAULT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE, FaultLabel(motorFaultsTexts[MotorFaults::BAD_MOTOR_POSITION_HALL_SEQUENCE], FaultPriorities::MEDIUM_PRIORITY, false));
    faultList_.insert(MotorFaults::WATCHDOG_CAUSED_LAST_RESET, FaultLabel(motorFaultsTexts[MotorFaults::WATCHDOG_CAUSED_LAST_RESET], FaultPriorities::MEDIUM_PRIORITY, false));
    faultList_.insert(MotorFaults::CONFIG_READ_ERROR, FaultLabel(motorFaultsTexts[MotorFaults::CONFIG_READ_ERROR], FaultPriorities::MEDIUM_PRIORITY, false));
    faultList_.insert(MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT, FaultLabel(motorFaultsTexts[MotorFaults::RAIL_UNDER_VOLTAGE_LOCK_OUT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultList_.insert(MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::OUTPUT_VOLTAGE_PWM_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::MOTOR_CURRENT_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::MOTOR_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::BUS_CURRENT_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::BUS_CURRENT_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::BUS_VOLTAGE_LOWER_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_LOWER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::BUS_VOLTAGE_UPPER_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::BUS_VOLTAGE_UPPER_LIMIT], FaultPriorities::HIGH_PRIORITY, false));
    faultList_.insert(MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::IPM_MOTOR_TEMPERATURE_LIMIT], FaultPriorities::MEDIUM_PRIORITY, false));
    faultList_.insert(MotorFaults::VELOCITY_LIMIT, FaultLabel(motorFaultsTexts[MotorFaults::VELOCITY_LIMIT], FaultPriorities::LOW_PRIORITY, false));

}


MotorFaultList::~MotorFaultList()
{
}

FaultLabel MotorFaultList::nextActiveFault()
{
    QMapIterator<MotorFaults, FaultLabel> i(faultList_);
    while(i.hasNext())
    {
        i.next();
        if(faultList_[i.key()].isActive())
        {
            return faultList_[i.key()];
        }
    }

    return FaultLabel();
}
QMap<MotorFaults, FaultLabel>& MotorFaultList::faults()
{
    return faultList_;
}

int MotorFaultList::numberOfActiveFaults()
{
    int numberOfLabels = 0;
    QMapIterator<MotorFaults, FaultLabel> i(faultList_);

    while(i.hasNext())
    {
        i.next();
        if(faultList_[i.key()].isActive())
        {
            numberOfLabels++;
        }
    }

    return numberOfLabels;
}
