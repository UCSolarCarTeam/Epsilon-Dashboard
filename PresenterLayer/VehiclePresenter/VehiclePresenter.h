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
class I_VehicleData;

class VehiclePresenter : public QObject
{
   Q_OBJECT
public:
   explicit VehiclePresenter(const I_VehicleData& vehicleData);

private:
   void relayVehicleData();

   const I_VehicleData& vehicleData_;

signals:
    void driverSetSpeedMetersPerSecondReceived(double driverSetSpeedMetersPerSecond);
    void driverSetCurrentReceived(double driverSetCurrent);
    void vehicleVelocityMetersPerSecondReceived(double vehicleVelocityMetersPerSecond);
    void motorVelocityRpmReceived(double motorVelocityRpm);
    void ipmHeatSinkTempReceived(double ipmHeatSinkTemp);
    void dspBoardTempReceived(double dspBoardTemp);
    void receivedErrorCountReceived(double ReceivedErrorCount);
    void transmittedErrorCountReceived(double transmittedErrorCount);
    void busVoltageReceived(double busVoltage);
};
