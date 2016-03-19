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

#include "MpptPresenter.h"
#include "DataLayer/MpptData/I_MpptData.h"

MpptPresenter::MpptPresenter(const I_MpptData& mpptData)
: mpptData_(mpptData)
{
   relayMpptData();
}

void MpptPresenter::relayMpptData()
{
   connect(&mpptData_, SIGNAL(mppt1VoltageInReceived(double)),
        this, SIGNAL(mppt1VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1CurrentInReceived(double)),
        this, SIGNAL(mppt1CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1VoltageOutReceived(double)),
        this, SIGNAL(mppt1VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1CurrentOutReceived(double)),
        this, SIGNAL(mppt1CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1PowerInReceived(double)),
        this, SIGNAL(mppt1PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1PowerOutReceived(double)),
        this, SIGNAL(mppt1PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1EfficiencyReceived(double)),
        this, SIGNAL(mppt1EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt1TypeReceived(QString)),
        this, SIGNAL(mppt1TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt1ModeReceived(QString)),
        this, SIGNAL(mppt1ModeReceived(QString)));

   connect(&mpptData_, SIGNAL(mppt2VoltageInReceived(double)),
        this, SIGNAL(mppt2VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2CurrentInReceived(double)),
        this, SIGNAL(mppt2CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2VoltageOutReceived(double)),
        this, SIGNAL(mppt2VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2CurrentOutReceived(double)),
        this, SIGNAL(mppt2CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2PowerInReceived(double)),
        this, SIGNAL(mppt2PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2PowerOutReceived(double)),
        this, SIGNAL(mppt2PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2EfficiencyReceived(double)),
        this, SIGNAL(mppt2EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt2TypeReceived(QString)),
        this, SIGNAL(mppt2TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt2ModeReceived(QString)),
        this, SIGNAL(mppt2ModeReceived(QString)));

   connect(&mpptData_, SIGNAL(mppt3VoltageInReceived(double)),
        this, SIGNAL(mppt3VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3CurrentInReceived(double)),
        this, SIGNAL(mppt3CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3VoltageOutReceived(double)),
        this, SIGNAL(mppt3VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3CurrentOutReceived(double)),
        this, SIGNAL(mppt3CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3PowerInReceived(double)),
        this, SIGNAL(mppt3PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3PowerOutReceived(double)),
        this, SIGNAL(mppt3PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3EfficiencyReceived(double)),
        this, SIGNAL(mppt3EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt3TypeReceived(QString)),
        this, SIGNAL(mppt3TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt3ModeReceived(QString)),
        this, SIGNAL(mppt3ModeReceived(QString)));

   connect(&mpptData_, SIGNAL(mppt4VoltageInReceived(double)),
        this, SIGNAL(mppt4VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4CurrentInReceived(double)),
        this, SIGNAL(mppt4CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4VoltageOutReceived(double)),
        this, SIGNAL(mppt4VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4CurrentOutReceived(double)),
        this, SIGNAL(mppt4CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4PowerInReceived(double)),
        this, SIGNAL(mppt4PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4PowerOutReceived(double)),
        this, SIGNAL(mppt4PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4EfficiencyReceived(double)),
        this, SIGNAL(mppt4EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt4TypeReceived(QString)),
        this, SIGNAL(mppt4TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt4ModeReceived(QString)),
        this, SIGNAL(mppt4ModeReceived(QString)));

   connect(&mpptData_, SIGNAL(mppt5VoltageInReceived(double)),
        this, SIGNAL(mppt5VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5CurrentInReceived(double)),
        this, SIGNAL(mppt5CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5VoltageOutReceived(double)),
        this, SIGNAL(mppt5VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5CurrentOutReceived(double)),
        this, SIGNAL(mppt5CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5PowerInReceived(double)),
        this, SIGNAL(mppt5PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5PowerOutReceived(double)),
        this, SIGNAL(mppt5PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5EfficiencyReceived(double)),
        this, SIGNAL(mppt5EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt5TypeReceived(QString)),
        this, SIGNAL(mppt5TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt5ModeReceived(QString)),
        this, SIGNAL(mppt5ModeReceived(QString)));

   connect(&mpptData_, SIGNAL(mppt6VoltageInReceived(double)),
        this, SIGNAL(mppt6VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6CurrentInReceived(double)),
        this, SIGNAL(mppt6CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6VoltageOutReceived(double)),
        this, SIGNAL(mppt6VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6CurrentOutReceived(double)),
        this, SIGNAL(mppt6CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6PowerInReceived(double)),
        this, SIGNAL(mppt6PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6PowerOutReceived(double)),
        this, SIGNAL(mppt6PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6EfficiencyReceived(double)),
        this, SIGNAL(mppt6EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt6TypeReceived(QString)),
        this, SIGNAL(mppt6TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt6ModeReceived(QString)),
        this, SIGNAL(mppt6ModeReceived(QString)));

   connect(&mpptData_, SIGNAL(mppt7VoltageInReceived(double)),
        this, SIGNAL(mppt7VoltageInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7CurrentInReceived(double)),
        this, SIGNAL(mppt7CurrentInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7VoltageOutReceived(double)),
        this, SIGNAL(mppt7VoltageOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7CurrentOutReceived(double)),
        this, SIGNAL(mppt7CurrentOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7PowerInReceived(double)),
        this, SIGNAL(mppt7PowerInReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7PowerOutReceived(double)),
        this, SIGNAL(mppt7PowerOutReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7EfficiencyReceived(double)),
        this, SIGNAL(mppt7EfficiencyReceived(double)));
   connect(&mpptData_, SIGNAL(mppt7TypeReceived(QString)),
        this, SIGNAL(mppt7TypeReceived(QString)));
   connect(&mpptData_, SIGNAL(mppt7ModeReceived(QString)),
        this, SIGNAL(mppt7ModeReceived(QString)));
}
