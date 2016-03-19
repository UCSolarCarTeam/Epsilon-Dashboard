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

#include "FaultsPresenter.h"
#include "../../DataLayer/FaultsData/I_FaultsData.h"

FaultsPresenter::FaultsPresenter(const I_FaultsData& faultsData)
: faultsData_ (faultsData)
{
   relayFaultsData();
}

void FaultsPresenter::relayFaultsData()
{
   connect(&faultsData_, SIGNAL(motorOneFaultsReceived(MotorFaults)),
         this, SIGNAL(motorOneFaultsReceived(MotorFaults)));
   connect(&faultsData_, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
         this, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)));
   connect(&faultsData_, SIGNAL(motorTwoFaultsReceived(MotorFaults)),
         this, SIGNAL(motorTwoFaultsReceived(MotorFaults)));
   connect(&faultsData_, SIGNAL(motorTwoLimitFlagsReceived(LimitFlags)),
         this, SIGNAL(motorTwoLimitFlagsReceived(LimitFlags)));
   connect(&faultsData_, SIGNAL(batteryFaultsReceived(BatteryFaults)),
         this, SIGNAL(batteryFaultsReceived(BatteryFaults)));
}
