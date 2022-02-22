#pragma once

class FaultPopulator
{
public:
    virtual ~FaultPopulator() {};

    virtual void populateFaults() = 0;
    virtual void populateRaceFaults() = 0;
};
