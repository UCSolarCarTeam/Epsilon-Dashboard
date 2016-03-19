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

#pragma once

#include <QObject>
class I_BatteryData;

class BatteryPresenter : public QObject
{
   Q_OBJECT
public:
   explicit BatteryPresenter(const I_BatteryData& batteryData);

private:
   void relayBatteryData();

   const I_BatteryData& batteryData_;

signals:
   void mod0PcbTemperatureReceived(double mod0PcbTemperature);
   void mod0CellTemperatureReceived(double mod0CellTemperature);
   void mod0CellVoltagesReceived(QList<double> mod0CellVoltages);

   void mod1PcbTemperatureReceived(double mod1PcbTemperature);
   void mod1CellTemperatureReceived(double mod1CellTemperature);
   void mod1CellVoltagesReceived(QList<double> mod1CellVoltages);

   void mod2PcbTemperatureReceived(double mod2PcbTemperature);
   void mod2CellTemperatureReceived(double mod2CellTemperature);
   void mod2CellVoltagesReceived(QList<double> mod2CellVoltages);

   void mod3PcbTemperatureReceived(double mod3PcbTemperature);
   void mod3CellTemperatureReceived(double mod3CellTemperature);
   void mod3CellVoltagesReceived(QList<double> mod3CellVoltages);

   void batteryVoltageReceived(double batteryVoltage);
   void batteryCurrentReceived(double batteryCurent);
};
