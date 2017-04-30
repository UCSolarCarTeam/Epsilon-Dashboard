#pragma once

#include "I_CmuData.h"

class CmuData : public I_CmuData
{
public:
    CmuData();
    virtual ~CmuData();

    Cmu cmuZero() const;
    Cmu cmuOne() const;
    Cmu cmuTwo() const;
    Cmu cmuThree() const;

    void setCmuZero(Cmu cmuZero);
    void setCmuOne(Cmu cmuOne);
    void setCmuTwo(Cmu cmuTwo);
    void setCmuThree(Cmu cmuThree);
private:
    QList<Cmu> cmuList_;

    double findMaxCellTemp();
    double findLowestVoltage();
    double findAverageCellTemp();
    double findAverageVoltage();
};

