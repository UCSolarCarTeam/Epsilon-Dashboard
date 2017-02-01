#pragma once

#include <QObject>
#include "DataLayer/MpptData/Mppt.h"

class I_MpptData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_MpptData() {}

    virtual Mppt mpptZero() const = 0;
    virtual Mppt mpptOne() const = 0;
    virtual Mppt mpptTwo() const = 0;

    virtual void setMpptZero(Mppt mpptZero) = 0;
    virtual void setMpptOne(Mppt mpptOne) = 0;
    virtual void setMpptTwo(Mppt mpptTwo) = 0;

signals:
    void mpptZeroReceived(Mppt mpptZero);
    void mpptOneReceived(Mppt mpptOne);
    void mpptTwoReceived(Mppt mpptTwo);
};
