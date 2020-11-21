#include "MotorFaultList.h"

MotorFaultList::MotorFaultList()
    : currentFault_(0)
{

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
