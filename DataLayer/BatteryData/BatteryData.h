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

#include "I_BatteryData.h"

class BatteryData : public I_BatteryData
{
public:
   BatteryData();
   virtual ~BatteryData();

    /*Data "Gets"*/
   double mod0PcbTemperature() const;
   double mod0CellTemperature() const;
   QList<double> mod0CellVoltages() const;

   double mod1PcbTemperature() const;
   double mod1CellTemperature() const;
   QList<double> mod1CellVoltages() const;
 
   double mod2PcbTemperature() const;
   double mod2CellTemperature() const;
   QList<double> mod2CellVoltages() const;
 
   double mod3PcbTemperature() const;
   double mod3CellTemperature() const;
   QList<double> mod3CellVoltages() const;

   double batteryVoltage() const;
   double batteryCurrent() const;

  /*BatteryData "Sets"*/
   void setMod0PcbTemperature(double mod0PcbTemperature);
   void setMod0CellTemperature(double mod0CellTemperature);
   void setMod0CellVoltages(QList<double> mod0CellVoltages);

   void setMod1PcbTemperature(double mod1PcbTemperature);
   void setMod1CellTemperature(double mod1CellTemperature);
   void setMod1CellVoltages(QList<double> mod1CellVoltages);

   void setMod2PcbTemperature(double mod2PcbTemperature);
   void setMod2CellTemperature(double mod2CellTemperature);
   void setMod2CellVoltages(QList<double> mod2CellVoltages);

   void setMod3PcbTemperature(double mod3PcbTemperature);
   void setMod3CellTemperature(double mod3CellTemperature);
   void setMod3CellVoltages(QList<double> mod3CellVoltages);

   void setBatteryVoltage(double batteryVoltage);
   void setBatteryCurrent(double batteryCurrent);

private: 
   double mod0PcbTemperature_;
   double mod0CellTemperature_;
   QList<double> mod0CellVoltages_;

   double mod1PcbTemperature_;
   double mod1CellTemperature_;
   QList<double> mod1CellVoltages_;

   double mod2PcbTemperature_;
   double mod2CellTemperature_;
   QList<double> mod2CellVoltages_;

   double mod3PcbTemperature_;
   double mod3CellTemperature_;
   QList<double> mod3CellVoltages_;

   double batteryVoltage_;
   double batteryCurrent_;
};

