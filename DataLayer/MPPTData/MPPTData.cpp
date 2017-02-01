#include "MpptData.h"
#include <QDebug>

MpptData::MpptData()
{
}

MpptData::~MpptData()
{
}

Mppt MpptData::mpptZero() const
{
    return mpptZero_;
}

Mppt MpptData::mpptOne() const
{
    return mpptOne_;
}

Mppt MpptData::mpptTwo() const
{
    return mpptTwo_;
}


void MpptData::setMpptZero(Mppt mpptZero)
{
    mpptZero_ = mpptZero;
    emit mpptZeroReceived(mpptZero_);
}

void MpptData::setMpptOne(Mppt mpptOne)
{
    mpptOne_ = mpptOne;
    emit mpptOneReceived(mpptOne_);
}

void MpptData::setMpptTwo(Mppt mpptTwo)
{
    mpptTwo_ = mpptTwo;
    emit mpptTwoReceived(mpptTwo_);
}
