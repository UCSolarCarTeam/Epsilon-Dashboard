#include "MpptPresenter.h"

MpptPresenter::MpptPresenter(const I_MpptData& mpptData)
    : mpptData_(mpptData)
{
    relayMpptData();
}

void MpptPresenter::relayMpptData()
{
    connect(&mpptData_, SIGNAL(mpptZeroReceived(Mppt)),
            this, SIGNAL(mpptZeroReceived(Mppt)));
    connect(&mpptData_, SIGNAL(mpptOneReceived(Mppt)),
            this, SIGNAL(mpptOneReceived(Mppt)));
    connect(&mpptData_, SIGNAL(mpptTwoReceived(Mppt)),
            this, SIGNAL(mpptTwoReceived(Mppt)));
    connect(&mpptData_, SIGNAL(mpptPowerReceived(double)),
            this, SIGNAL(mpptPowerReceived(double)));
}
