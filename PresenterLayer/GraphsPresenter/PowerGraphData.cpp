/**
 *  Gen 5 Dashboard
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Gen 5 Dashboard
 *
 *  The Gen 5 Dashboard is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Gen 5 Dashboard is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Gen 5 Dashboard.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "PowerGraphData.h"
#include <QDebug>

PowerGraphData::PowerGraphData()
{
}

PowerGraphData::PowerGraphData(int numberOfIntervals,
                               double intervalSize,
                               int numberOfDataSets)
{
    xData_ = QVector<double>(numberOfIntervals);
    for(int i = 0; i < numberOfIntervals; i++)
    {
        xData_.prepend((double)i * intervalSize);
    }

    yDataSets_ = QList<QVector<double> >();
    for(int i = 0; i < numberOfDataSets; i++)
    {
        yDataSets_.append(QVector<double>(numberOfIntervals, 0));
    }
}

QVector<double> PowerGraphData::xData()
{
    return xData_;
}

QList<QVector<double> > PowerGraphData::yDataSets()
{
    return yDataSets_;
}

void PowerGraphData::addData(double datum[])
{
    for(int i = 0; i < yDataSets_.length(); i++)
    {
        yDataSets_[i].removeLast();
        yDataSets_[i].prepend(datum[i]);
    }
}


