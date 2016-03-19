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

#include "FakePowerData.h"

FakePowerData::FakePowerData()
{
}

FakePowerData::~FakePowerData()
{
}

/*FakePowerData "Gets"*/
double FakePowerData::busCurrentA() const
{
   return 1;
}
double FakePowerData::busVoltage() const
{
   return 2;
}
double FakePowerData::motorVoltageReal() const
{
   return 3;
}
double FakePowerData::motorCurrentReal() const
{
   return 4;
}
double FakePowerData::backEmfImaginary() const
{
   return 5;
}
double FakePowerData::dcBusAmpHours() const
{
   return 6;
}

/*FakePowerData "Sets"*/
void FakePowerData::setBusCurrentA(double busCurrentA){}
void FakePowerData::setBusVoltage(double busVoltage){}
void FakePowerData::setMotorVoltageReal(double motorVoltageReal){}
void FakePowerData::setMotorCurrentReal(double motorCurrentReal){}
void FakePowerData::setBackEmfImaginary(double backEmfImaginary){}
void FakePowerData::setDcBusAmpHours(double dcBusAmpHours){}