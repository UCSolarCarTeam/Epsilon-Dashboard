#pragma once

#include <QObject>
#include "DataLayer/CmuData/Cmu.h"

class I_CmuData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_CmuData() {}

    virtual Cmu cmuZero() const = 0;
    virtual Cmu cmuOne() const = 0;
    virtual Cmu cmuTwo() const = 0;
    virtual Cmu cmuThree() const = 0;

    virtual void setCmuZero(Cmu cmuZero) = 0;
    virtual void setCmuOne(Cmu cmuOne) = 0;
    virtual void setCmuTwo(Cmu cmuTwo) = 0;
    virtual void setCmuThree(Cmu cmuThree) = 0;

signals:
    void cmuZeroReceived(Cmu cmuZero);
    void cmuOneReceived(Cmu cmuOne);
    void cmuTwoReceived(Cmu cmuTwo);
    void cmuThreeReceived(Cmu cmuThree);
    void cmuMaxCellTempReceived(double maxCellTemp);
    void cmuLowestCellVoltageReceived(double lowestCellVoltage);
    void cmuAverageCellTempReceived(double averageCellTemp);
    void cmuAverageVoltageReceived(double averageVoltage);
};
