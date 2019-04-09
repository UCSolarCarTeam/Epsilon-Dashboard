/**
 *  Schulich Delta Android Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Android Telemetry
 *
 *  Schulich Delta Android Telemetry is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Android Telemetry is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Android Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#pragma once
#include "I_DriverControlsPopulator.h"
class I_DriverControlsData;

class DriverControlsPopulator : public I_DriverControlsPopulator
{
    Q_OBJECT
public:
    DriverControlsPopulator(I_DriverControlsData& driverControlsData);
    virtual ~DriverControlsPopulator() {}

public slots:
    void populateData(const QJsonObject&);

private:
    I_DriverControlsData& driverControlsData_;
};
