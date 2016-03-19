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

#include "FakeVehicleData.h"

FakeVehicleData::FakeVehicleData()
{
}

FakeVehicleData::~FakeVehicleData()
{
}

/*PowerData "Gets"*/
double FakeVehicleData::driverSetSpeedMetersPerSecond() const
{   
   return 1;
}

double FakeVehicleData::driverSetCurrent() const
{
   return 2;
}

double FakeVehicleData::vehicleVelocityMetersPerSecond() const
{
   return 3;
}

double FakeVehicleData::motorVelocityRpm() const
{
   return 4;
}

double FakeVehicleData::ipmHeatSinkTemp() const
{
   return 5;
}
double FakeVehicleData::dspBoardTemp() const
{
   return 6;
}

double FakeVehicleData::receivedErrorCount() const
{
   return 7;
}
double FakeVehicleData::transmittedErrorCount() const
{
   return 8;
}

/*PowerData "Sets"*/
void FakeVehicleData::setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond){}
void FakeVehicleData::setDriverSetCurrent(double driverSetCurrent){}
void FakeVehicleData::setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond){}
void FakeVehicleData::setMotorVelocityRpm(double motorVelocityRpm){}
void FakeVehicleData::setIpmHeatSinkTemp(double ipmHeatSinkTemp){}
void FakeVehicleData::setDspBoardTemp(double dspBoardTemp){}
void FakeVehicleData::setReceivedErrorCount(double receivedErrorCount){}
void FakeVehicleData::setTransmittedErrorCount(double transmittedErrorCount){}