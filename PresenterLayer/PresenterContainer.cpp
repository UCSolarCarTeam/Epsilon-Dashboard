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

#include "BatteryPresenter/BatteryPresenter.h"
#include "BusinessLayer/BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "CommunicationPresenter/CommunicationPresenter.h"
#include "DataLayer/DataContainer.h"
#include "FaultsPresenter/FaultsPresenter.h"
#include "MpptPresenter/MpptPresenter.h"
#include "PowerPresenter/PowerPresenter.h"
#include "PresenterContainer.h"
#include "VehiclePresenter/VehiclePresenter.h"

PresenterContainer::PresenterContainer(DataContainer& dataContainer,
      CommunicationContainer& communicationContainer,
      BusinessContainer& businessContainer)
: batteryPresenter_(new BatteryPresenter(dataContainer.batteryData()))
, communicationPresenter_(new CommunicationPresenter(
   communicationContainer.commDevice(),
   businessContainer.communicationsMonitoringService()))
, vehiclePresenter_(new VehiclePresenter(dataContainer.vehicleData()))
, mpptPresenter_(new MpptPresenter(dataContainer.mpptData()))
, powerPresenter_(new PowerPresenter(dataContainer.powerData()))
, faultsPresenter_(new FaultsPresenter(dataContainer.faultsData()))
{
}

PresenterContainer::~PresenterContainer()
{
}

BatteryPresenter& PresenterContainer::batteryPresenter()
{
   return *batteryPresenter_;
}

CommunicationPresenter& PresenterContainer::communicationPresenter()
{
   return *communicationPresenter_;
}

VehiclePresenter& PresenterContainer::vehiclePresenter()
{
   return *vehiclePresenter_;
}

MpptPresenter& PresenterContainer::mpptPresenter()
{
   return *mpptPresenter_;
}

PowerPresenter& PresenterContainer::powerPresenter()
{
   return *powerPresenter_;
}

FaultsPresenter& PresenterContainer::faultsPresenter()
{
   return *faultsPresenter_;
}
