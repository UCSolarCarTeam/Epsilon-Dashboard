#include "MotorFaultList.h"

MotorFaultList::MotorFaultList()
    : currentFault_(faultList_.end())
{

}


MotorFaultList::~MotorFaultList()
{
}

FaultDisplayData MotorFaultList::nextActiveFault()
{
    QMap<MotorFaults, FaultDisplayData>::iterator iterator;

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

QVector<QString>& MotorFaultList::activeFaultLabels()
{
    numberOfActiveFaults();
    return activeLabels_;
}

QMap<MotorFaults, FaultDisplayData>& MotorFaultList::faults()
{
    return faultList_;
}

int MotorFaultList::numberOfActiveFaults()
{
    activeLabels_.clear();
    int numberOfActiveFaults = 0;
    QMap<MotorFaults, FaultDisplayData>::const_iterator i ;

    for (i = faultList_.constBegin(); i != faultList_.constEnd(); ++i)
    {
        if (i.value().isActive())
        {
            numberOfActiveFaults ++;
            activeLabels_.append(i.value().name());
        }
    }

    return numberOfActiveFaults;
}
