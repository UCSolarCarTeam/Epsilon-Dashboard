#pragma once
#include "../../DataLayer/CmuData/I_CmuData.h"
#include <QObject>
class I_CmuData;

class CmuPresenter : public QObject
{
    Q_OBJECT
public:
    explicit CmuPresenter(const I_CmuData& cmuData);

private:
    void relayCmuData();

    const I_CmuData& cmuData_;

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
