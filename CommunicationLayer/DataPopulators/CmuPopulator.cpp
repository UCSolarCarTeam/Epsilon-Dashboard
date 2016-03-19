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

#include "CmuPopulator.h"
#include <QDebug>

CmuPopulator::CmuPopulator(I_PacketDecoder& packetDecoder,
                           I_BatteryData& batteryData)
: packetDecoder_(packetDecoder)
, batteryData_(batteryData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const CmuDataMessage)),
            this, SLOT(populateData(const CmuDataMessage)));
}

void CmuPopulator::populateData(const CmuDataMessage message)
{
    switch(message.cellNumber()){ 
        case 0:
            batteryData_.setMod0PcbTemperature(message.pcbTemperature());
            batteryData_.setMod0CellTemperature(message.cellTemperature());
            batteryData_.setMod0CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
        case 1:
            batteryData_.setMod1PcbTemperature(message.pcbTemperature());
            batteryData_.setMod1CellTemperature(message.cellTemperature());
            batteryData_.setMod1CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
        case 2:
            batteryData_.setMod2PcbTemperature(message.pcbTemperature());
            batteryData_.setMod2CellTemperature(message.cellTemperature());
            batteryData_.setMod2CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
        case 3:
            batteryData_.setMod3PcbTemperature(message.pcbTemperature());
            batteryData_.setMod3CellTemperature(message.cellTemperature());
            batteryData_.setMod3CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
    }
}

QList<double> CmuPopulator::convertFloatListToDouble(QList<float> floatList)
{
    QList<double> doubleList;
    for(int i = 0; i < floatList.length(); i++)
    {
        doubleList.append((double)floatList[i]);
    }
    return doubleList;
}
