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

#include "FaultsData.h"

FaultsData::FaultsData()
: motorOneFaults_(0)
, motorOneLimitFlags_(0)
, motorTwoFaults_(0)
, motorTwoLimitFlags_(0)
, batteryFaults_(0)
{
}
FaultsData::~FaultsData()
{
}

/* FaultData Gets */
MotorFaults FaultsData::motorOneFaults() const
{
   return motorOneFaults_;
}
LimitFlags FaultsData::motorOneLimitFlags() const
{
   return motorOneLimitFlags_;
}
MotorFaults FaultsData::motorTwoFaults() const
{
   return motorTwoFaults_;
}
LimitFlags FaultsData::motorTwoLimitFlags() const
{
   return motorTwoLimitFlags_;
}
BatteryFaults FaultsData::batteryFaults() const
{
   return batteryFaults_;
}

/* FaultData Sets */
void FaultsData::setMotorOneFaults(MotorFaults motorFaults)
{
   motorOneFaults_ = motorFaults;
   emit motorOneFaultsReceived(motorOneFaults_);
}
void FaultsData::setMotorOneLimitFlags(LimitFlags limitFlags)
{
   motorOneLimitFlags_ = limitFlags;
   emit motorOneLimitFlagsReceived(motorOneLimitFlags_);
}
void FaultsData::setMotorTwoFaults(MotorFaults motorFaults)
{
   motorTwoFaults_ = motorFaults;
   emit motorTwoFaultsReceived(motorTwoFaults_);
}
void FaultsData::setMotorTwoLimitFlags(LimitFlags limitFlags)
{
   motorTwoLimitFlags_ = limitFlags;
   emit motorTwoLimitFlagsReceived(motorTwoLimitFlags_);
}
void FaultsData::setBatteryFaults(BatteryFaults batteryFaults)
{
   batteryFaults_ = batteryFaults;
   emit batteryFaultsReceived(batteryFaults_);
}
