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

#include "I_VehicleData.h"

class VehicleData : public I_VehicleData
{
public:
    VehicleData();
    virtual ~VehicleData();

    /*VehicleData "Gets"*/
    double driverSetSpeedMetersPerSecond() const;
    double driverSetCurrent() const;
    double vehicleVelocityMetersPerSecond() const;
    double motorVelocityRpm() const;
    double ipmHeatSinkTemp() const;
    double dspBoardTemp() const;
    double receivedErrorCount() const;
    double transmittedErrorCount() const;

    /*VehicleData "Sets"*/
    void setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond);
    void setDriverSetCurrent(double driverSetCurrent);
    void setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond);
    void setMotorVelocityRpm(double motorVelocityRpm);
    void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
    void setDspBoardTemp(double dspBoardTemp);
    void setReceivedErrorCount(double receivedErrorCount);
    void setTransmittedErrorCount(double transmittedErrorCount);

private:
    double driverSetSpeedMetersPerSecond_;
    double driverSetCurrent_;
    double vehicleVelocityMetersPerSecond_;
    double motorVelocityRpm_;
    double ipmHeatSinkTemp_;
    double dspBoardTemp_;
    double receivedErrorCount_;
    double transmittedErrorCount_;
};
