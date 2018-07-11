#include "MpptData.h"
#include <QDebug>

MpptData::MpptData()
{
    mpptList_.reserve(4);

    for (int i  =  0; i < 4; i++)
    {
        mpptList_.append(Mppt());
    }
}

MpptData::~MpptData()
{
}

void MpptData::setMppt(int i, Mppt mppt)
{
    mpptList_.replace(i, mppt);
    emit mpptReceived(i, mpptList_.at(i));
}
