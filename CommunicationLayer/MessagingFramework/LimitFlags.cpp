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

#include "LimitFlags.h"

namespace
{
   const quint8 OUTPUT_VOLTAGE_MASK = 0x01;
   const quint8 MOTOR_CURRENT_MASK = 0x02;
   const quint8 VELOCITY_MASK = 0x04;
   const quint8 BUS_CURRENT_MASK = 0x08;
   const quint8 BUS_VOLTAGE_UPPER_MASK = 0x10;
   const quint8 BUS_VOLTAGE_LOWER_MASK = 0x20;
   const quint8 IPM_OR_MOTOR_TEMP = 0x40;
}

LimitFlags::LimitFlags(quint8 flags)
: flags_(flags)
{
}

bool LimitFlags::outputVoltagePwmLimit() const
{
   return static_cast<bool>(flags_ & OUTPUT_VOLTAGE_MASK);
}

bool LimitFlags::motorCurrentLimit() const
{
   return static_cast<bool>(flags_ & MOTOR_CURRENT_MASK);
}

bool LimitFlags::velocityLimit() const
{
   return static_cast<bool>(flags_ & VELOCITY_MASK);
}

bool LimitFlags::busCurrentLimit() const
{
   return static_cast<bool>(flags_ & BUS_CURRENT_MASK);
}

bool LimitFlags::busVoltageUpperLimit() const
{
   return static_cast<bool>(flags_ & BUS_VOLTAGE_UPPER_MASK);
}

bool LimitFlags::busVoltageLowerLimit() const
{
   return static_cast<bool>(flags_ & BUS_VOLTAGE_LOWER_MASK);
}

bool LimitFlags::ipmOrMotorTelemetryLimit() const
{
   return static_cast<bool>(flags_ & IPM_OR_MOTOR_TEMP);
}

bool LimitFlags::operator==(const LimitFlags& other) const
{
   return flags_ == other.flags_;
}

QString LimitFlags::toString() const
{
   return "0x" + QString::number(flags_, 16);
}
