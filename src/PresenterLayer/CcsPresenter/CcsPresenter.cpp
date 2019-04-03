#include "CcsPresenter.h"
#include "../../DataLayer/CcsData/I_CcsData.h"

CcsPresenter::CcsPresenter(const I_CcsData& ccsData)
    : ccsData_(ccsData)
{
    relayCcsData();
}

void CcsPresenter::relayCcsData()
{
    connect(&ccsData_, SIGNAL(ccsAliveReceived(bool)),
            this, SIGNAL(ccsAliveReceived(bool)));
}
