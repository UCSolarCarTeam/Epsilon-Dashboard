#include "MpptData.h"
#include <QDebug>

MpptData::MpptData()
{
    mpptList_.reserve(3);
}

MpptData::~MpptData()
{
}

Mppt MpptData::mpptZero() const
{
    return mpptList_.at(0);
}

Mppt MpptData::mpptOne() const
{
    return mpptList_.at(1);
}

Mppt MpptData::mpptTwo() const
{
    return mpptList_.at(2);
}


void MpptData::setMpptZero(Mppt mpptZero)
{
    mpptList_.replace(0, mpptZero);
    emit mpptZeroReceived(mpptList_.at(0));
}

void MpptData::setMpptOne(Mppt mpptOne)
{
    mpptList_.replace(1, mpptOne);
    emit mpptOneReceived(mpptList_.at(1));
}

void MpptData::setMpptTwo(Mppt mpptTwo)
{
    mpptList_.replace(2, mpptTwo);
    emit mpptTwoReceived(mpptList_.at(2));
}
