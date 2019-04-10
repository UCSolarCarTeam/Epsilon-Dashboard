/**
 *  Schulich Delta Android Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Android Telemetry
 *
 *  Schulich Delta Android Telemetry is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Android Telemetry is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Android Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QJsonObject>
#include <QJsonArray>

#include "CmuPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"

CmuPopulator::CmuPopulator(I_CmuData& cmuData)
    : cmuData_(cmuData)
{
}

void CmuPopulator::populateData(const QJsonObject& data)
{
    Cmu cmuZero;
    Cmu cmuOne;
    Cmu cmuTwo;
    Cmu cmuThree;
    QList<double> cmuZeroVoltages;
    QList<double> cmuOneVoltages;
    QList<double> cmuTwoVoltages;
    QList<double> cmuThreeVoltages;
    QList<double> cmuZeroCellTemps;
    QList<double> cmuOneCellTemps;
    QList<double> cmuTwoCellTemps;
    QList<double> cmuThreeCellTemps;
    QList<double> cmuVoltages [4] = {cmuZeroVoltages, cmuOneVoltages, cmuTwoVoltages, cmuThreeVoltages};
    QList<double> cmuPcbTemps;
    QList<double> cmuCellTemps [4] = {cmuZeroCellTemps, cmuOneCellTemps, cmuTwoCellTemps, cmuThreeCellTemps};
    QJsonValue value = data.value(JsonFormat::CMU);
    QJsonArray array = value.toArray();

    for (int i = 0 ; i < 3 ; i++)
    {
        QJsonValue voltages = array.at(i).toObject().value(JsonFormat::CMU_VOLTAGES);
        QJsonArray voltagesArray = voltages.toArray();

        foreach (const QJsonValue& v, voltagesArray)
        {
            cmuVoltages[i].append(v.toDouble());
        }

        QJsonValue pcbTemp = array.at(i).toObject().value(JsonFormat::CMU_PCBTEMP);
        cmuPcbTemps.append(pcbTemp.toDouble());
        QJsonValue cellTemps = array.at(i).toObject().value(JsonFormat::CMU_CELLTEMPS);
        QJsonArray cellTempsArray = cellTemps.toArray();

        foreach (const QJsonValue& c, cellTempsArray)
        {
            cmuCellTemps[i].append(c.toDouble());
        }
    }

    cmuZero.setVoltages(cmuVoltages[0]);
    cmuZero.setPcbTemp(cmuPcbTemps.at(0));
    cmuZero.setCellTemps(cmuVoltages[0]);
    cmuOne.setVoltages(cmuVoltages[1]);
    cmuOne.setPcbTemp(cmuPcbTemps.at(1));
    cmuOne.setCellTemps(cmuVoltages[1]);
    cmuTwo.setVoltages(cmuVoltages[2]);
    cmuTwo.setPcbTemp(cmuPcbTemps.at(2));
    cmuTwo.setCellTemps(cmuVoltages[2]);
    cmuThree.setVoltages(cmuVoltages[3]);
    cmuThree.setPcbTemp(cmuPcbTemps.at(3));
    cmuThree.setCellTemps(cmuVoltages[3]);
    cmuData_.setCmuZero(cmuZero);
    cmuData_.setCmuOne(cmuOne);
    cmuData_.setCmuTwo(cmuTwo);
    cmuData_.setCmuThree(cmuThree);
}
