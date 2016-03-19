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

#include <QByteArray>
#include <QString>
#include "BatteryFaults.h"
#include "LimitFlags.h"
#include "MotorFaults.h"

class FaultsMessage
{
public:
   FaultsMessage(const QByteArray& messageData);

   MotorFaults motorOneFaults() const;
   LimitFlags motorOneLimitFlags() const;
   MotorFaults motorTwoFaults() const;
   LimitFlags motorTwoLimitFlags() const;
   BatteryFaults batteryFaults() const;

   quint8 canReceivedErrorCounts() const;
   quint8 canTransmittedErrorCounts() const;

   QString toString() const;

private:
   const QByteArray messageData_;
};
