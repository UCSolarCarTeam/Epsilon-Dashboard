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

class I_BatteryData : public QObject
{
   Q_OBJECT

public:
   virtual ~I_BatteryData() {}

   /*BatteryData "Gets"*/
   virtual double mod0PcbTemperature() const = 0;
   virtual double mod0CellTemperature() const = 0;
   virtual QList<double> mod0CellVoltages() const = 0;

   virtual double mod1PcbTemperature() const = 0;
   virtual double mod1CellTemperature() const = 0;
   virtual QList<double> mod1CellVoltages() const = 0;

   virtual double mod2PcbTemperature() const = 0;
   virtual double mod2CellTemperature() const = 0;
   virtual QList<double> mod2CellVoltages() const = 0;

   virtual double mod3PcbTemperature() const = 0;
   virtual double mod3CellTemperature() const = 0;
   virtual QList<double> mod3CellVoltages() const = 0;

   virtual double batteryVoltage() const = 0;
   virtual double batteryCurrent() const = 0;

   /*BatteryData "Sets"*/
   virtual void setMod0PcbTemperature(double mod0PcbTemperature) = 0;
   virtual void setMod0CellTemperature(double mod0CellTemperature) = 0;
   virtual void setMod0CellVoltages(QList<double> setMod0CellVoltages) = 0;

   virtual void setMod1PcbTemperature(double mod1PcbTemperature) = 0;
   virtual void setMod1CellTemperature(double mod1CellTemperature) = 0;
   virtual void setMod1CellVoltages(QList<double> setMod1CellVoltages) = 0;

   virtual void setMod2PcbTemperature(double mod2PcbTemperature) = 0;
   virtual void setMod2CellTemperature(double mod2CellTemperature) = 0;
   virtual void setMod2CellVoltages(QList<double> setMod2CellVoltages) = 0;

   virtual void setMod3PcbTemperature(double mod3PcbTemperature) = 0;
   virtual void setMod3CellTemperature(double mod3CellTemperature) = 0;
   virtual void setMod3CellVoltages(QList<double> setMod3CellVoltages) = 0;

   virtual void setBatteryVoltage(double batteryVoltage) = 0;
   virtual void setBatteryCurrent(double batteryCurrent) = 0;

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
