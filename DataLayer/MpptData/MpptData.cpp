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

#include "MpptData.h"
#include <QDebug>

MpptData::MpptData()
{
}

MpptData::~MpptData()
{
}

/*ArrayData "Gets"*/
double MpptData::mppt1VoltageIn() const
{
   return mppt1VoltageIn_;
}
double MpptData::mppt1CurrentIn() const
{
   return mppt1CurrentIn_;
}
double MpptData::mppt1VoltageOut() const
{
   return mppt1VoltageOut_;
}
double MpptData::mppt1CurrentOut() const
{
   return mppt1CurrentOut_;
}
double MpptData::mppt1PowerIn() const
{
   return mppt1PowerIn_;
}
double MpptData::mppt1PowerOut() const
{
   return mppt1PowerOut_;
}
double MpptData::mppt1Efficiency() const
{
   return mppt1Efficiency_;
}
QString MpptData::mppt1Type() const
{
   return mppt1Type_;
}
QString MpptData::mppt1Mode() const
{
   return mppt1Mode_;
}

double MpptData::mppt2VoltageIn() const
{
   return mppt2VoltageIn_;
}
double MpptData::mppt2CurrentIn() const
{
   return mppt2CurrentIn_;
}
double MpptData::mppt2VoltageOut() const
{
   return mppt2VoltageOut_;
}
double MpptData::mppt2CurrentOut() const
{
   return mppt2CurrentOut_;
}
double MpptData::mppt2PowerIn() const
{
   return mppt2PowerIn_;
}
double MpptData::mppt2PowerOut() const
{
   return mppt2PowerOut_;
}
double MpptData::mppt2Efficiency() const
{
   return mppt2Efficiency_;
}
QString MpptData::mppt2Type() const
{
   return mppt2Type_;
}
QString MpptData::mppt2Mode() const
{
   return mppt2Mode_;
}

double MpptData::mppt3VoltageIn() const
{
   return mppt3VoltageIn_;
}
double MpptData::mppt3CurrentIn() const
{
   return mppt3CurrentIn_;
}
double MpptData::mppt3VoltageOut() const
{
   return mppt3VoltageOut_;
}
double MpptData::mppt3CurrentOut() const
{
   return mppt3CurrentOut_;
}
double MpptData::mppt3PowerIn() const
{
   return mppt3PowerIn_;
}
double MpptData::mppt3PowerOut() const
{
   return mppt3PowerOut_;
}
double MpptData::mppt3Efficiency() const
{
   return mppt3Efficiency_;
}
QString MpptData::mppt3Type() const
{
   return mppt3Type_;
}
QString MpptData::mppt3Mode() const
{
   return mppt3Mode_;
}

double MpptData::mppt4VoltageIn() const
{
   return mppt4VoltageIn_;
}
double MpptData::mppt4CurrentIn() const
{
   return mppt4CurrentIn_;
}
double MpptData::mppt4VoltageOut() const
{
   return mppt4VoltageOut_;
}
double MpptData::mppt4CurrentOut() const
{
   return mppt4CurrentOut_;
}
double MpptData::mppt4PowerIn() const
{
   return mppt4PowerIn_;
}
double MpptData::mppt4PowerOut() const
{
   return mppt4PowerOut_;
}
double MpptData::mppt4Efficiency() const
{
   return mppt4Efficiency_;
}
QString MpptData::mppt4Type() const
{
   return mppt4Type_;
}
QString MpptData::mppt4Mode() const
{
   return mppt4Mode_;
}

double MpptData::mppt5VoltageIn() const
{
   return mppt5VoltageIn_;
}
double MpptData::mppt5CurrentIn() const
{
   return mppt5CurrentIn_;
}
double MpptData::mppt5VoltageOut() const
{
   return mppt5VoltageOut_;
}
double MpptData::mppt5CurrentOut() const
{
   return mppt5CurrentOut_;
}
double MpptData::mppt5PowerIn() const
{
   return mppt5PowerIn_;
}
double MpptData::mppt5PowerOut() const
{
   return mppt5PowerOut_;
}
double MpptData::mppt5Efficiency() const
{
   return mppt5Efficiency_;
}
QString MpptData::mppt5Type() const
{
   return mppt5Type_;
}
QString MpptData::mppt5Mode() const
{
   return mppt5Mode_;
}

double MpptData::mppt6VoltageIn() const
{
   return mppt6VoltageIn_;
}
double MpptData::mppt6CurrentIn() const
{
   return mppt6CurrentIn_;
}
double MpptData::mppt6VoltageOut() const
{
   return mppt6VoltageOut_;
}
double MpptData::mppt6CurrentOut() const
{
   return mppt6CurrentOut_;
}
double MpptData::mppt6PowerIn() const
{
   return mppt6PowerIn_;
}
double MpptData::mppt6PowerOut() const
{
   return mppt6PowerOut_;
}
double MpptData::mppt6Efficiency() const
{
   return mppt6Efficiency_;
}
QString MpptData::mppt6Type() const
{
   return mppt6Type_;
}
QString MpptData::mppt6Mode() const
{
   return mppt6Mode_;
}

double MpptData::mppt7VoltageIn() const
{
   return mppt7VoltageIn_;
}
double MpptData::mppt7CurrentIn() const
{
   return mppt7CurrentIn_;
}
double MpptData::mppt7VoltageOut() const
{
   return mppt7VoltageOut_;
}
double MpptData::mppt7CurrentOut() const
{
   return mppt7CurrentOut_;
}
double MpptData::mppt7PowerIn() const
{
   return mppt7PowerIn_;
}
double MpptData::mppt7PowerOut() const
{
   return mppt7PowerOut_;
}
double MpptData::mppt7Efficiency() const
{
   return mppt7Efficiency_;
}
QString MpptData::mppt7Type() const
{
   return mppt7Type_;
}
QString MpptData::mppt7Mode() const
{
   return mppt7Mode_;
}

/*ArrayData "Sets"*/
void MpptData::setMppt1VoltageIn(double mppt1VoltageIn)
{
   mppt1VoltageIn_ = mppt1VoltageIn;
   emit mppt1VoltageInReceived(mppt1VoltageIn);
   setMppt1PowerIn();
}
void MpptData::setMppt1CurrentIn(double mppt1CurrentIn)
{
   mppt1CurrentIn_ = mppt1CurrentIn;
   emit mppt1CurrentInReceived(mppt1CurrentIn);
   setMppt1PowerIn();
}
void MpptData::setMppt1VoltageOut(double mppt1VoltageOut)
{
   mppt1VoltageOut_ = mppt1VoltageOut;
   emit mppt1VoltageOutReceived(mppt1VoltageOut);
   setMppt1PowerOut();
}
void MpptData::setMppt1CurrentOut(double mppt1CurrentOut)
{
   mppt1CurrentOut_ = mppt1CurrentOut;
   emit mppt1CurrentOutReceived(mppt1CurrentOut);
   setMppt1PowerOut();
}
void MpptData::setMppt1PowerIn()
{
   mppt1PowerIn_ = mppt1CurrentIn() * mppt1VoltageIn();
   emit mppt1PowerInReceived(mppt1PowerIn_);
   setMppt1Efficiency();
}
void MpptData::setMppt1PowerOut()
{
   mppt1PowerOut_ = mppt1CurrentOut() * mppt1VoltageOut();
   emit mppt1PowerOutReceived(mppt1PowerOut_);
   setMppt1Efficiency();
}
void MpptData::setMppt1Efficiency()
{
   mppt1Efficiency_ = mppt1PowerIn() / mppt1PowerOut() * 100;
   emit mppt1EfficiencyReceived(mppt1Efficiency_);
}
void MpptData::setMppt1Type(QString mppt1Type)
{
   mppt1Type_ = mppt1Type;
   emit mppt1TypeReceived(mppt1Type);
}
void MpptData::setMppt1Mode(QString mppt1Mode)
{
   mppt1Mode_ = mppt1Mode;
   emit mppt1ModeReceived(mppt1Mode);
}

void MpptData::setMppt2VoltageIn(double mppt2VoltageIn)
{
   mppt2VoltageIn_ = mppt2VoltageIn;
   emit mppt2VoltageInReceived(mppt2VoltageIn);
   setMppt2PowerIn();
}
void MpptData::setMppt2CurrentIn(double mppt2CurrentIn)
{
   mppt2CurrentIn_ = mppt2CurrentIn;
   emit mppt2CurrentInReceived(mppt2CurrentIn);
   setMppt2PowerIn();
}
void MpptData::setMppt2VoltageOut(double mppt2VoltageOut)
{
   mppt2VoltageOut_ = mppt2VoltageOut;
   emit mppt2VoltageOutReceived(mppt2VoltageOut);
   setMppt2PowerOut();
}
void MpptData::setMppt2CurrentOut(double mppt2CurrentOut)
{
   mppt2CurrentOut_ = mppt2CurrentOut;
   emit mppt2CurrentOutReceived(mppt2CurrentOut);
   setMppt2PowerOut();
}
void MpptData::setMppt2PowerIn()
{
   mppt2PowerIn_ = mppt2CurrentIn() * mppt2VoltageIn();
   emit mppt2PowerInReceived(mppt2PowerIn_);
   setMppt2Efficiency();
}
void MpptData::setMppt2PowerOut()
{
   mppt2PowerOut_ = mppt2CurrentOut() * mppt2VoltageOut();
   emit mppt2PowerOutReceived(mppt2PowerOut_);
   setMppt2Efficiency();
}
void MpptData::setMppt2Efficiency()
{
   mppt2Efficiency_ = mppt2PowerIn() / mppt2PowerOut() * 200;
   emit mppt2EfficiencyReceived(mppt2Efficiency_);
}
void MpptData::setMppt2Type(QString mppt2Type)
{
   mppt2Type_ = mppt2Type;
   emit mppt2TypeReceived(mppt2Type);
}
void MpptData::setMppt2Mode(QString mppt2Mode)
{
   mppt2Mode_ = mppt2Mode;
   emit mppt2ModeReceived(mppt2Mode);
}

void MpptData::setMppt3VoltageIn(double mppt3VoltageIn)
{
   mppt3VoltageIn_ = mppt3VoltageIn;
   emit mppt3VoltageInReceived(mppt3VoltageIn);
   setMppt3PowerIn();
}
void MpptData::setMppt3CurrentIn(double mppt3CurrentIn)
{
   mppt3CurrentIn_ = mppt3CurrentIn;
   emit mppt3CurrentInReceived(mppt3CurrentIn);
   setMppt3PowerIn();
}
void MpptData::setMppt3VoltageOut(double mppt3VoltageOut)
{
   mppt3VoltageOut_ = mppt3VoltageOut;
   emit mppt3VoltageOutReceived(mppt3VoltageOut);
   setMppt3PowerOut();
}
void MpptData::setMppt3CurrentOut(double mppt3CurrentOut)
{
   mppt3CurrentOut_ = mppt3CurrentOut;
   emit mppt3CurrentOutReceived(mppt3CurrentOut);
   setMppt3PowerOut();
}
void MpptData::setMppt3PowerIn()
{
   mppt3PowerIn_ = mppt3CurrentIn() * mppt3VoltageIn();
   emit mppt3PowerInReceived(mppt3PowerIn_);
   setMppt3Efficiency();
}
void MpptData::setMppt3PowerOut()
{
   mppt3PowerOut_ = mppt3CurrentOut() * mppt3VoltageOut();
   emit mppt3PowerOutReceived(mppt3PowerOut_);
   setMppt3Efficiency();
}
void MpptData::setMppt3Efficiency()
{
   mppt3Efficiency_ = mppt3PowerIn() / mppt3PowerOut() * 300;
   emit mppt3EfficiencyReceived(mppt3Efficiency_);
}
void MpptData::setMppt3Type(QString mppt3Type)
{
   mppt3Type_ = mppt3Type;
   emit mppt3TypeReceived(mppt3Type);
}
void MpptData::setMppt3Mode(QString mppt3Mode)
{
   mppt3Mode_ = mppt3Mode;
   emit mppt3ModeReceived(mppt3Mode);
}

void MpptData::setMppt4VoltageIn(double mppt4VoltageIn)
{
   mppt4VoltageIn_ = mppt4VoltageIn;
   emit mppt4VoltageInReceived(mppt4VoltageIn);
   setMppt4PowerIn();
}
void MpptData::setMppt4CurrentIn(double mppt4CurrentIn)
{
   mppt4CurrentIn_ = mppt4CurrentIn;
   emit mppt4CurrentInReceived(mppt4CurrentIn);
   setMppt4PowerIn();
}
void MpptData::setMppt4VoltageOut(double mppt4VoltageOut)
{
   mppt4VoltageOut_ = mppt4VoltageOut;
   emit mppt4VoltageOutReceived(mppt4VoltageOut);
   setMppt4PowerOut();
}
void MpptData::setMppt4CurrentOut(double mppt4CurrentOut)
{
   mppt4CurrentOut_ = mppt4CurrentOut;
   emit mppt4CurrentOutReceived(mppt4CurrentOut);
   setMppt4PowerOut();
}
void MpptData::setMppt4PowerIn()
{
   mppt4PowerIn_ = mppt4CurrentIn() * mppt4VoltageIn();
   emit mppt4PowerInReceived(mppt4PowerIn_);
   setMppt4Efficiency();
}
void MpptData::setMppt4PowerOut()
{
   mppt4PowerOut_ = mppt4CurrentOut() * mppt4VoltageOut();
   emit mppt4PowerOutReceived(mppt4PowerOut_);
   setMppt4Efficiency();
}
void MpptData::setMppt4Efficiency()
{
   mppt4Efficiency_ = mppt4PowerIn() / mppt4PowerOut() * 400;
   emit mppt4EfficiencyReceived(mppt4Efficiency_);
}
void MpptData::setMppt4Type(QString mppt4Type)
{
   mppt4Type_ = mppt4Type;
   emit mppt4TypeReceived(mppt4Type);
}
void MpptData::setMppt4Mode(QString mppt4Mode)
{
   mppt4Mode_ = mppt4Mode;
   emit mppt4ModeReceived(mppt4Mode);
}

void MpptData::setMppt5VoltageIn(double mppt5VoltageIn)
{
   mppt5VoltageIn_ = mppt5VoltageIn;
   emit mppt5VoltageInReceived(mppt5VoltageIn);
   setMppt5PowerIn();
}
void MpptData::setMppt5CurrentIn(double mppt5CurrentIn)
{
   mppt5CurrentIn_ = mppt5CurrentIn;
   emit mppt5CurrentInReceived(mppt5CurrentIn);
   setMppt5PowerIn();
}
void MpptData::setMppt5VoltageOut(double mppt5VoltageOut)
{
   mppt5VoltageOut_ = mppt5VoltageOut;
   emit mppt5VoltageOutReceived(mppt5VoltageOut);
   setMppt5PowerOut();
}
void MpptData::setMppt5CurrentOut(double mppt5CurrentOut)
{
   mppt5CurrentOut_ = mppt5CurrentOut;
   emit mppt5CurrentOutReceived(mppt5CurrentOut);
   setMppt5PowerOut();
}
void MpptData::setMppt5PowerIn()
{
   mppt5PowerIn_ = mppt5CurrentIn() * mppt5VoltageIn();
   emit mppt5PowerInReceived(mppt5PowerIn_);
   setMppt5Efficiency();
}
void MpptData::setMppt5PowerOut()
{
   mppt5PowerOut_ = mppt5CurrentOut() * mppt5VoltageOut();
   emit mppt5PowerOutReceived(mppt5PowerOut_);
   setMppt5Efficiency();
}
void MpptData::setMppt5Efficiency()
{
   mppt5Efficiency_ = mppt5PowerIn() / mppt5PowerOut() * 500;
   emit mppt5EfficiencyReceived(mppt5Efficiency_);
}
void MpptData::setMppt5Type(QString mppt5Type)
{
   mppt5Type_ = mppt5Type;
   emit mppt5TypeReceived(mppt5Type);
}
void MpptData::setMppt5Mode(QString mppt5Mode)
{
   mppt5Mode_ = mppt5Mode;
   emit mppt5ModeReceived(mppt5Mode);
}

void MpptData::setMppt6VoltageIn(double mppt6VoltageIn)
{
   mppt6VoltageIn_ = mppt6VoltageIn;
   emit mppt6VoltageInReceived(mppt6VoltageIn);
   setMppt6PowerIn();
}
void MpptData::setMppt6CurrentIn(double mppt6CurrentIn)
{
   mppt6CurrentIn_ = mppt6CurrentIn;
   emit mppt6CurrentInReceived(mppt6CurrentIn);
   setMppt6PowerIn();
}
void MpptData::setMppt6VoltageOut(double mppt6VoltageOut)
{
   mppt6VoltageOut_ = mppt6VoltageOut;
   emit mppt6VoltageOutReceived(mppt6VoltageOut);
   setMppt6PowerOut();
}
void MpptData::setMppt6CurrentOut(double mppt6CurrentOut)
{
   mppt6CurrentOut_ = mppt6CurrentOut;
   emit mppt6CurrentOutReceived(mppt6CurrentOut);
   setMppt6PowerOut();
}
void MpptData::setMppt6PowerIn()
{
   mppt6PowerIn_ = mppt6CurrentIn() * mppt6VoltageIn();
   emit mppt6PowerInReceived(mppt6PowerIn_);
   setMppt6Efficiency();
}
void MpptData::setMppt6PowerOut()
{
   mppt6PowerOut_ = mppt6CurrentOut() * mppt6VoltageOut();
   emit mppt6PowerOutReceived(mppt6PowerOut_);
   setMppt6Efficiency();
}
void MpptData::setMppt6Efficiency()
{
   mppt6Efficiency_ = mppt6PowerIn() / mppt6PowerOut() * 600;
   emit mppt6EfficiencyReceived(mppt6Efficiency_);
}
void MpptData::setMppt6Type(QString mppt6Type)
{
   mppt6Type_ = mppt6Type;
   emit mppt6TypeReceived(mppt6Type);
}
void MpptData::setMppt6Mode(QString mppt6Mode)
{
   mppt6Mode_ = mppt6Mode;
   emit mppt6ModeReceived(mppt6Mode);
}

void MpptData::setMppt7VoltageIn(double mppt7VoltageIn)
{
   mppt7VoltageIn_ = mppt7VoltageIn;
   emit mppt7VoltageInReceived(mppt7VoltageIn);
   setMppt7PowerIn();
}
void MpptData::setMppt7CurrentIn(double mppt7CurrentIn)
{
   mppt7CurrentIn_ = mppt7CurrentIn;
   emit mppt7CurrentInReceived(mppt7CurrentIn);
   setMppt7PowerIn();
}
void MpptData::setMppt7VoltageOut(double mppt7VoltageOut)
{
   mppt7VoltageOut_ = mppt7VoltageOut;
   emit mppt7VoltageOutReceived(mppt7VoltageOut);
   setMppt7PowerOut();
}
void MpptData::setMppt7CurrentOut(double mppt7CurrentOut)
{
   mppt7CurrentOut_ = mppt7CurrentOut;
   emit mppt7CurrentOutReceived(mppt7CurrentOut);
   setMppt7PowerOut();
}
void MpptData::setMppt7PowerIn()
{
   mppt7PowerIn_ = mppt7CurrentIn() * mppt7VoltageIn();
   emit mppt7PowerInReceived(mppt7PowerIn_);
   setMppt7Efficiency();
}
void MpptData::setMppt7PowerOut()
{
   mppt7PowerOut_ = mppt7CurrentOut() * mppt7VoltageOut();
   emit mppt7PowerOutReceived(mppt7PowerOut_);
   setMppt7Efficiency();
}
void MpptData::setMppt7Efficiency()
{
   mppt7Efficiency_ = mppt7PowerIn() / mppt7PowerOut() * 700;
   emit mppt7EfficiencyReceived(mppt7Efficiency_);
}
void MpptData::setMppt7Type(QString mppt7Type)
{
   mppt7Type_ = mppt7Type;
   emit mppt7TypeReceived(mppt7Type);
}
void MpptData::setMppt7Mode(QString mppt7Mode)
{
   mppt7Mode_ = mppt7Mode;
   emit mppt7ModeReceived(mppt7Mode);
}

