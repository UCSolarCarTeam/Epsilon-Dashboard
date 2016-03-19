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

#include "MotorFaults.h"

namespace
{
   const quint8 HARDWARE_OVER_CURRENT_MASK = 0x01;
   const quint8 SOFTWARE_OVER_CURRENT_MASK = 0x02;
   const quint8 DC_BUS_OVER_VOLTAGE_MASK = 0x04;
   const quint8 BAD_MOTOR_POS_HALL_MASK = 0x08;
   const quint8 WATCHDOG_CAUSED_LAST_RESET_MASK = 0x10;
   const quint8 CONFIG_READ_ERROR_MASK = 0x20;
   const quint8 RAIL_UNDER_VOLT_MASK = 0x40;
   const quint8 DESATURATION_FAULT_MASK = 0x80;
}

MotorFaults::MotorFaults(quint8 flags)
: flags_(flags)
{
}

bool MotorFaults::hardwareOverCurrent() const
{
   return static_cast<bool>(flags_ & HARDWARE_OVER_CURRENT_MASK);
}

bool MotorFaults::softwareOverCurrent() const
{
   return static_cast<bool>(flags_ & SOFTWARE_OVER_CURRENT_MASK);
}

bool MotorFaults::dcBusOverVoltage() const
{
   return static_cast<bool>(flags_ & DC_BUS_OVER_VOLTAGE_MASK);
}

bool MotorFaults::badMotorPositionHallSequence() const
{
   return static_cast<bool>(flags_ & BAD_MOTOR_POS_HALL_MASK);
}

bool MotorFaults::watchdogCausedLastReset() const
{
   return static_cast<bool>(flags_ & WATCHDOG_CAUSED_LAST_RESET_MASK);
}

bool MotorFaults::configReadError() const
{
   return static_cast<bool>(flags_ & CONFIG_READ_ERROR_MASK);
}

bool MotorFaults::railUnderVoltageLockOut() const
{
   return static_cast<bool>(flags_ & RAIL_UNDER_VOLT_MASK);
}

bool MotorFaults::desaturationFault() const
{
   return static_cast<bool>(flags_ & DESATURATION_FAULT_MASK);
}

bool MotorFaults::operator==(const MotorFaults& other) const
{
   return flags_ == other.flags_;
}

QString MotorFaults::toString() const
{
   return "0x" + QString::number(flags_, 16);
}
