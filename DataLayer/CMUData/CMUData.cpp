#include "CmuData.h"
#include <QDebug>

CmuData::CmuData()
{
}

CmuData::~CmuData()
{
}

Cmu CmuData::cmuZero() const
{
    return cmuZero_;
}
Cmu CmuData::cmuOne() const
{
    return cmuOne_;
}
Cmu CmuData::cmuTwo() const
{
    return cmuTwo_;
}
Cmu CmuData::cmuThree() const
{
    return cmuThree_;
}

void CmuData::setCmuZero(Cmu cmuZero)
{
    cmuZero_ = cmuZero;
    emit cmuZeroReceived(cmuZero_);
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}
void CmuData::setCmuOne(Cmu cmuOne)
{
    cmuOne_ = cmuOne;
    emit cmuOneReceived(cmuOne_);
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}
void CmuData::setCmuTwo(Cmu cmuTwo)
{
    cmuTwo_ = cmuTwo;
    emit cmuTwoReceived(cmuTwo_);
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}
void CmuData::setCmuThree(Cmu cmuThree)
{
    cmuThree_ = cmuThree;
    emit cmuThreeReceived(cmuThree_);
    emit cmuMaxCellTempReceived(findMaxCellTemp());
    emit cmuLowestCellVoltageReceived(findLowestVoltage());
    emit cmuAverageCellTempReceived(findAverageCellTemp());
    emit cmuAverageVoltageReceived(findAverageVoltage());
}

double CmuData::findMaxCellTemp()
{
    QList<double> allCellTemps;
    double maxCellTemp;
    allCellTemps.append(cmuZero_.cellTemps());
    allCellTemps.append(cmuOne_.cellTemps());
    allCellTemps.append(cmuTwo_.cellTemps());
    allCellTemps.append(cmuThree_.cellTemps());
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
    allVoltages.append(cmuZero_.voltages());
    allVoltages.append(cmuOne_.voltages());
    allVoltages.append(cmuTwo_.voltages());
    allVoltages.append(cmuThree_.voltages());
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
    allCellTemps.append(cmuZero_.cellTemps());
    allCellTemps.append(cmuOne_.cellTemps());
    allCellTemps.append(cmuTwo_.cellTemps());
    allCellTemps.append(cmuThree_.cellTemps());

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
    allVoltages.append(cmuZero_.voltages());
    allVoltages.append(cmuOne_.voltages());
    allVoltages.append(cmuTwo_.voltages());
    allVoltages.append(cmuThree_.voltages());

    foreach (const double voltage, allVoltages)
    {
        sumVoltages += voltage;
        voltagesCount++;
    }

    return sumVoltages / voltagesCount;
}