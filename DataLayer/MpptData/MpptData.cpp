#include "MpptData.h"
#include <QDebug>

MpptData::MpptData()
{
    mpptList_.reserve(3);
}

MpptData::~MpptData()
{
}

void MpptData::setMppt(int i, Mppt mppt)
{
      mpptList_.replace(i, mppt);
      emit mpptReceived(i, mpptList_.at(i));
}
