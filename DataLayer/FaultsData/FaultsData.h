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

#include "I_FaultsData.h"

class MotorFaults;
class LimitFlags;
class BatteryFaults;

class FaultsData : public I_FaultsData
{
public:
   FaultsData();
   virtual ~FaultsData();

   /* FaultData Gets */
   MotorFaults motorOneFaults() const;
   LimitFlags motorOneLimitFlags() const;
   MotorFaults motorTwoFaults() const;
   LimitFlags motorTwoLimitFlags() const;
   BatteryFaults batteryFaults() const;

   /* FaultData Sets */
   void setMotorOneFaults(MotorFaults motorFaults);
   void setMotorOneLimitFlags(LimitFlags limitFlags);
   void setMotorTwoFaults(MotorFaults motorFaults);
   void setMotorTwoLimitFlags(LimitFlags limitFlags);
   void setBatteryFaults(BatteryFaults batteryFaults);

private:
   MotorFaults motorOneFaults_;
   LimitFlags motorOneLimitFlags_;
   MotorFaults motorTwoFaults_;
   LimitFlags motorTwoLimitFlags_;
   BatteryFaults batteryFaults_;
};
