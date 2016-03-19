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

#include "CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "CommunicationLayer/MessagingFramework/BatteryFaults.h"

class I_FaultsData : public QObject
{
   Q_OBJECT
public:
   virtual ~I_FaultsData() {}

   /* FaultData Gets */
   virtual MotorFaults motorOneFaults() const = 0;
   virtual LimitFlags motorOneLimitFlags() const = 0;
   virtual MotorFaults motorTwoFaults() const = 0;
   virtual LimitFlags motorTwoLimitFlags() const = 0;
   virtual BatteryFaults batteryFaults() const = 0;

   /* FaultData Sets */
   virtual void setMotorOneFaults(MotorFaults motorFaults) = 0;
   virtual void setMotorOneLimitFlags(LimitFlags limitFlags) = 0;
   virtual void setMotorTwoFaults(MotorFaults motorFaults) = 0;
   virtual void setMotorTwoLimitFlags(LimitFlags limitFlags) = 0;
   virtual void setBatteryFaults(BatteryFaults batteryFaults) = 0;

signals:
   void motorOneFaultsReceived(MotorFaults motorFaults);
   void motorOneLimitFlagsReceived(LimitFlags limitFlags);
   void motorTwoFaultsReceived(MotorFaults motorFaults);
   void motorTwoLimitFlagsReceived(LimitFlags limitFlags);
   void batteryFaultsReceived(BatteryFaults batteryFaults);
};
