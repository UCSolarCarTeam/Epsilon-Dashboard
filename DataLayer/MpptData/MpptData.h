#pragma once

#include "I_MpptData.h"

class MpptData : public I_MpptData
{
public:
    MpptData();
    virtual ~MpptData();

    Mppt mpptZero() const;
    Mppt mpptOne() const;
    Mppt mpptTwo() const;

    void setMpptZero(Mppt mpptZero);
    void setMpptOne(Mppt mpptZero);
    void setMpptTwo(Mppt mpptZero);

private:
    QList<Mppt> mpptList_;
};

