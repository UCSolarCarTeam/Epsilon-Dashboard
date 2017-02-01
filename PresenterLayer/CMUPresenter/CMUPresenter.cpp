#include "CmuPresenter.h"

CmuPresenter::CmuPresenter(const I_CmuData& cmuData)
    : cmuData_(cmuData)
{
    relayCmuData();
}

void CmuPresenter::relayCmuData()
{
    connect(&cmuData_, SIGNAL(cmuZeroReceived(Cmu)),
            this, SIGNAL(cmuZeroReceived(Cmu)));
    connect(&cmuData_, SIGNAL(cmuOneReceived(Cmu)),
            this, SIGNAL(cmuOneReceived(Cmu)));
    connect(&cmuData_, SIGNAL(cmuTwoReceived(Cmu)),
            this, SIGNAL(cmuTwoReceived(Cmu)));
    connect(&cmuData_, SIGNAL(cmuThreeReceived(Cmu)),
            this, SIGNAL(cmuThreeReceived(Cmu)));
    connect(&cmuData_, SIGNAL(cmuMaxCellTempReceived(double)),
            this, SIGNAL(cmuMaxCellTempReceived(double)));
    connect(&cmuData_, SIGNAL(cmuLowestCellVoltageReceived(double)),
            this, SIGNAL(cmuLowestCellVoltageReceived(double)));
    connect(&cmuData_, SIGNAL(cmuAverageCellTempReceived(double)),
            this, SIGNAL(cmuAverageCellTempReceived(double)));
    connect(&cmuData_, SIGNAL(cmuAverageVoltageReceived(double)),
            this, SIGNAL(cmuAverageVoltageReceived(double)));
}
