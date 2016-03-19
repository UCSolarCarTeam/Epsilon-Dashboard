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
#include "I_PowerGraphsPresenter.h"
#include "../../DataLayer/VehicleData/I_VehicleData.h"
#include "../../DataLayer/PowerData/I_PowerData.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"
#include <QTimer>
#include "PowerGraphData.h"

class PowerGraphsPresenter : public I_PowerGraphsPresenter
{
   Q_OBJECT
public:
   explicit PowerGraphsPresenter(const I_VehicleData& vehicleData,
      const I_PowerData& powerData,
      const I_BatteryData& batteryData);
   void startUpdating();
   void stopUpdating();

public slots:
   void updateGraphData();

private:
   QTimer graphUpdateTimer_;

   const I_VehicleData& vehicleData_;
   const I_PowerData& powerData_;
   const I_BatteryData& batteryData_;

   PowerGraphData busCurrentGraphData_;
   PowerGraphData busVoltageGraphData_;
   PowerGraphData busPowerGraphData_;
   PowerGraphData driverCurrentGraphData_;
   PowerGraphData driverSpeedGraphData_;
   PowerGraphData batteryCellTempGraphData_;
   PowerGraphData batteryCellVoltageGraphData_;
   PowerGraphData batteryPowerGraphData_;

   void updateBusCurrentGraphData();
   void updateBusVoltage();
   void updateBusPowerGraphData();
   void updateDriverCurrentGraphData();
   void updateDriverSpeedGraphData();
   void updateBatteryCellTempGraphData();
   void updateBatteryCellVoltageGraphData();
   void updateBatteryPowerGraphData();

signals:
   void busCurrentGraphDataUpdated(PowerGraphData);
   void busVoltageGraphDataUpdated(PowerGraphData);
   void busPowerGraphDataUpdated(PowerGraphData);

   void drivingCurrentGraphDataUpdated(PowerGraphData);
   void drivingSpeedGraphDataUpdated(PowerGraphData);

   void cellTemperatureGraphDataUpdated(PowerGraphData);
   void cellVoltageGraphDataUpdated(PowerGraphData);
   void batteryPowerGraphUpdated(PowerGraphData);
};
