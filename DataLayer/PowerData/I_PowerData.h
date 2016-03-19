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

class I_PowerData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_PowerData() {}

   /*PowerData "Gets"*/
    virtual double busCurrentA() const = 0;
    virtual double busVoltage() const = 0;
    virtual double motorVoltageReal() const = 0;
    virtual double motorCurrentReal() const = 0;
    virtual double backEmfImaginary() const = 0;
    virtual double dcBusAmpHours() const = 0;

   /*PowerData "Sets"*/
    virtual void setBusCurrentA(double busCurrentA) = 0;
    virtual void setBusVoltage(double busVoltage) = 0;
    virtual void setMotorVoltageReal(double motorVoltageReal) = 0;
    virtual void setMotorCurrentReal(double motorCurrentReal) = 0;
    virtual void setBackEmfImaginary(double backEmfImaginary) = 0;
    virtual void setDcBusAmpHours(double dcBusAmpHours) = 0;

signals:
   void busCurrentAReceived(double busCurrentA);
   void busVoltageReceived(double busVoltage);
   void motorVoltageRealReceived(double motorVoltageReal);
   void motorCurrentRealReceived(double motorCurrepowerntReal);
   void backEmfImaginaryReceived(double backEmfImaginary);
   void dcBusAmpHoursReceived(double dcBusAmpHours);
};
