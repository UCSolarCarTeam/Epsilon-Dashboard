#pragma once

#include "I_CcsData.h"

class CcsData : public I_CcsData
{
public:
    CcsData();
    virtual ~CcsData();

    bool ccsAlive() const;

    void setCcsAlive(bool ccsAlive);

private:
    bool ccsAlive_;
};
