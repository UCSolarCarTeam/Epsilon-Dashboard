/**
 *  Schulich Delta Host Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Schulich Delta Host Telemetry
 *
 *  The Schulich Delta Host Telemetry is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Schulich Delta Host Telemetry is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Schulich Delta Host Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "MessageDefines.h"

namespace
{
   const int KEY_DRIVER_CONTROL_LENGTH = 21;
   const int DRIVER_CONTROL_DETAILS_LENGTH = 29;
   const int FAULTS_LENGTH = 9;
   const int BATTERY_DATA_LENGTH = 18;
   const int CMU_DATA_LENGTH = 42;
   const int MPPT_DATA_LENGTH = 21;
}

int MessageDefines::getLengthForMessage(MessageDefines::Type type)
{
   switch(type)
   {
   case KeyDriverControlTelemetry:
      return KEY_DRIVER_CONTROL_LENGTH;
   case DriverControlDetails:
      return DRIVER_CONTROL_DETAILS_LENGTH;
   case Faults:
      return FAULTS_LENGTH;
   case BatteryData:
      return BATTERY_DATA_LENGTH;
   case CmuData:
      return CMU_DATA_LENGTH;
   case MpptData:
      return MPPT_DATA_LENGTH;
   default:
      return 0;
   }
}
