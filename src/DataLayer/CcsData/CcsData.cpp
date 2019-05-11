#include "CcsData.h"

CcsData::CcsData()
{
}

CcsData::~CcsData()
{
}

bool CcsData::ccsAlive() const
{
    return ccsAlive_;
}

void CcsData::setCcsAlive(bool ccsAlive)
{
    ccsAlive_ = ccsAlive;
    emit ccsAliveReceived(ccsAlive_);
}
