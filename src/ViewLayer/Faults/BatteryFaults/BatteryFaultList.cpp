#include "BatteryFaultList.h"

BatteryFaultList::BatteryFaultList()
    : currentFault_(faultList_.end())
{
}

BatteryFaultList::~BatteryFaultList()
{
}

FaultDisplayData BatteryFaultList::nextActiveFault()
{
    QMap<BatteryFaults, FaultDisplayData>::iterator iterator;

    for (int i = 0; i < faultList_.size(); i ++)
    {
        if (currentFault_ == faultList_.end())
        {
            currentFault_ = faultList_.begin();
        }

        iterator = currentFault_;
        ++currentFault_;

        if (iterator.value().isActive())
        {
            return iterator.value();
        }
    }

    return FaultDisplayData();
}

QMap<BatteryFaults, FaultDisplayData>& BatteryFaultList::faults()
{
    return faultList_;
}

int BatteryFaultList::numberOfActiveFaults() const
{
    int numberOfActiveFaults = 0;

    QMap<BatteryFaults, FaultDisplayData>::const_iterator i ;

    for (i = faultList_.constBegin(); i != faultList_.constEnd(); ++i)
    {
        if (i.value().isActive())
        {
            numberOfActiveFaults ++;
        }
    }

    return numberOfActiveFaults;
}
