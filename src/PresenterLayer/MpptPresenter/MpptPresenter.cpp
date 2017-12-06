#include "MpptPresenter.h"

MpptPresenter::MpptPresenter(const I_MpptData& mpptData)
    : mpptData_(mpptData)
{
    relayMpptData();
}

void MpptPresenter::relayMpptData()
{
    connect(&mpptData_, SIGNAL(mpptReceived(int, Mppt)),
            this, SIGNAL(mpptReceived(int, Mppt)));
    connect(&mpptData_, SIGNAL(mpptPowerReceived(double)),
            this, SIGNAL(mpptPowerReceived(double)));
}
