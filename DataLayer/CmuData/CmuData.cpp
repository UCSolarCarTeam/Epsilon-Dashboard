#include "CmuData.h"
#include <QDebug>

CmuData::CmuData()
{
    cmuList_.reserve(4);
}

CmuData::~CmuData()
{
}

Cmu CmuData::cmuZero() const
{
    return cmuList_.at(0);
}
Cmu CmuData::cmuOne() const
{
    return cmuList_.at(1);
}
Cmu CmuData::cmuTwo() const
{
    return cmuList_.at(2);
}
Cmu CmuData::cmuThree() const
{
    return cmuList_.at(3);
}

void CmuData::setCmuZero(Cmu cmuZero)
{
    cmuList_.replace(0, cmuZero);
    emit cmuZeroReceived(cmuList_.at(0));
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}
void CmuData::setCmuOne(Cmu cmuOne)
{
    cmuList_.replace(1, cmuOne);
    emit cmuOneReceived(cmuList_.at(1));
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}
void CmuData::setCmuTwo(Cmu cmuTwo)
{
    cmuList_.replace(2, cmuTwo);
    emit cmuTwoReceived(cmuList_.at(2));
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}
void CmuData::setCmuThree(Cmu cmuThree)
{
    cmuList_.replace(3, cmuThree);
    emit cmuThreeReceived(cmuList_.at(3));
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}

double CmuData::findMaxCellTemp()
{
    QList<double> allCellTemps;
    double maxCellTemp;
    allCellTemps.append(cmuList_.at(0).cellTemps());
    allCellTemps.append(cmuList_.at(1).cellTemps());
    allCellTemps.append(cmuList_.at(2).cellTemps());
    allCellTemps.append(cmuList_.at(3).cellTemps());
    maxCellTemp = allCellTemps.at(0);

    foreach (const double cellTemp, allCellTemps)
    {
        if (cellTemp > maxCellTemp)
        {
            maxCellTemp = cellTemp;
        }
    }

    return maxCellTemp;
}
double CmuData::findLowestVoltage()
{
    QList<double> allVoltages;
    double minVoltage;
    allVoltages.append(cmuList_.at(0).voltages());
    allVoltages.append(cmuList_.at(1).voltages());
    allVoltages.append(cmuList_.at(2).voltages());
    allVoltages.append(cmuList_.at(3).voltages());
    minVoltage = allVoltages.at(0);

    foreach (const double voltage, allVoltages)
    {
        if (voltage < minVoltage)
        {
            minVoltage = voltage;
        }
    }

    return minVoltage;
}
double CmuData::findAverageCellTemp()
{
    QList<double> allCellTemps;
    double sumCellTemps = 0;
    int cellTempsCount = 0;
    allCellTemps.append(cmuList_.at(0).cellTemps());
    allCellTemps.append(cmuList_.at(1).cellTemps());
    allCellTemps.append(cmuList_.at(2).cellTemps());
    allCellTemps.append(cmuList_.at(3).cellTemps());

    foreach (const double cellTemp, allCellTemps)
    {
        sumCellTemps += cellTemp;
        cellTempsCount++;
    }

    return sumCellTemps / cellTempsCount;
}
double CmuData::findAverageVoltage()
{
    QList<double> allVoltages;
    double sumVoltages = 0;
    int voltagesCount = 0;
    allVoltages.append(cmuList_.at(0).voltages());
    allVoltages.append(cmuList_.at(1).voltages());
    allVoltages.append(cmuList_.at(2).voltages());
    allVoltages.append(cmuList_.at(3).voltages());

    foreach (const double voltage, allVoltages)
    {
        sumVoltages += voltage;
        voltagesCount++;
    }

    return sumVoltages / voltagesCount;
}
