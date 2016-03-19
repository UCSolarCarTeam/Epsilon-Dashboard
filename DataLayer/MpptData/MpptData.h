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

#include "I_MpptData.h"

class MpptData : public I_MpptData
{
   Q_OBJECT
public:
    MpptData();
    virtual ~MpptData();

private:
   /*ArrayData "Gets"*/
   double mppt1VoltageIn() const;
   double mppt1CurrentIn() const;
   double mppt1VoltageOut() const;
   double mppt1CurrentOut() const;
   double mppt1PowerIn() const;
   double mppt1PowerOut() const;
   double mppt1Efficiency() const;
   QString mppt1Type() const;
   QString mppt1Mode() const;

   double mppt2VoltageIn() const;
   double mppt2CurrentIn() const;
   double mppt2VoltageOut() const;
   double mppt2CurrentOut() const;
   double mppt2PowerIn() const;
   double mppt2PowerOut() const;
   double mppt2Efficiency() const;
   QString mppt2Type() const;
   QString mppt2Mode() const;

   double mppt3VoltageIn() const;
   double mppt3CurrentIn() const;
   double mppt3VoltageOut() const;
   double mppt3CurrentOut() const;
   double mppt3PowerIn() const;
   double mppt3PowerOut() const;
   double mppt3Efficiency() const;
   QString mppt3Type() const;
   QString mppt3Mode() const;

   double mppt4VoltageIn() const;
   double mppt4CurrentIn() const;
   double mppt4VoltageOut() const;
   double mppt4CurrentOut() const;
   double mppt4PowerIn() const;
   double mppt4PowerOut() const;
   double mppt4Efficiency() const;
   QString mppt4Type() const;
   QString mppt4Mode() const;

   double mppt5VoltageIn() const;
   double mppt5CurrentIn() const;
   double mppt5VoltageOut() const;
   double mppt5CurrentOut() const;
   double mppt5PowerIn() const;
   double mppt5PowerOut() const;
   double mppt5Efficiency() const;
   QString mppt5Type() const;
   QString mppt5Mode() const;

   double mppt6VoltageIn() const;
   double mppt6CurrentIn() const;
   double mppt6VoltageOut() const;
   double mppt6CurrentOut() const;
   double mppt6PowerIn() const;
   double mppt6PowerOut() const;
   double mppt6Efficiency() const;
   QString mppt6Type() const;
   QString mppt6Mode() const;

   double mppt7VoltageIn() const;
   double mppt7CurrentIn() const;
   double mppt7VoltageOut() const;
   double mppt7CurrentOut() const;
   double mppt7PowerIn() const;
   double mppt7PowerOut() const;
   double mppt7Efficiency() const;
   QString mppt7Type() const;
   QString mppt7Mode() const;

      /*ArrayData "Sets"*/
   void setMppt1VoltageIn(double mppt1VoltageIn);
   void setMppt1CurrentIn(double mppt1CurrentIn);
   void setMppt1VoltageOut(double mppt1VoltageOut);
   void setMppt1CurrentOut(double mppt1CurrentOut);
   void setMppt1PowerIn();
   void setMppt1PowerOut();
   void setMppt1Efficiency();
   void setMppt1Type(QString mppt1Type);
   void setMppt1Mode(QString mppt1Mode);

   void setMppt2VoltageIn(double mppt2VoltageIn);
   void setMppt2CurrentIn(double mppt2CurrentIn);
   void setMppt2VoltageOut(double mppt2VoltageOut);
   void setMppt2CurrentOut(double mppt2CurrentOut);
   void setMppt2PowerIn();
   void setMppt2PowerOut();
   void setMppt2Efficiency();
   void setMppt2Type(QString mppt2Type);
   void setMppt2Mode(QString mppt2Mode);

   void setMppt3VoltageIn(double mppt3VoltageIn);
   void setMppt3CurrentIn(double mppt3CurrentIn);
   void setMppt3VoltageOut(double mppt3VoltageOut);
   void setMppt3CurrentOut(double mppt3CurrentOut);
   void setMppt3PowerIn();
   void setMppt3PowerOut();
   void setMppt3Efficiency();
   void setMppt3Type(QString mppt3Type);
   void setMppt3Mode(QString mppt3Mode);

   void setMppt4VoltageIn(double mppt4VoltageIn);
   void setMppt4CurrentIn(double mppt4CurrentIn);
   void setMppt4VoltageOut(double mppt4VoltageOut);
   void setMppt4CurrentOut(double mppt4CurrentOut);
   void setMppt4PowerIn();
   void setMppt4PowerOut();
   void setMppt4Efficiency();
   void setMppt4Type(QString mppt4Type);
   void setMppt4Mode(QString mppt4Mode);

   void setMppt5VoltageIn(double mppt5VoltageIn);
   void setMppt5CurrentIn(double mppt5CurrentIn);
   void setMppt5VoltageOut(double mppt5VoltageOut);
   void setMppt5CurrentOut(double mppt5CurrentOut);
   void setMppt5PowerIn();
   void setMppt5PowerOut();
   void setMppt5Efficiency();
   void setMppt5Type(QString mppt5Type);
   void setMppt5Mode(QString mppt5Mode);

   void setMppt6VoltageIn(double mppt6VoltageIn);
   void setMppt6CurrentIn(double mppt6CurrentIn);
   void setMppt6VoltageOut(double mppt6VoltageOut);
   void setMppt6CurrentOut(double mppt6CurrentOut);
   void setMppt6PowerIn();
   void setMppt6PowerOut();
   void setMppt6Efficiency();
   void setMppt6Type(QString mppt6Type);
   void setMppt6Mode(QString mppt6Mode);

   void setMppt7VoltageIn(double mppt7VoltageIn);
   void setMppt7CurrentIn(double mppt7CurrentIn);
   void setMppt7VoltageOut(double mppt7VoltageOut);
   void setMppt7CurrentOut(double mppt7CurrentOut);
   void setMppt7PowerIn();
   void setMppt7PowerOut();
   void setMppt7Efficiency();
   void setMppt7Type(QString mppt7Type);
   void setMppt7Mode(QString mppt7Mode);

private:
   double mppt1VoltageIn_;
   double mppt1CurrentIn_;
   double mppt1VoltageOut_;
   double mppt1CurrentOut_;
   double mppt1PowerIn_;
   double mppt1PowerOut_;
   double mppt1Efficiency_;
   QString mppt1Type_;
   QString mppt1Mode_;

   double mppt2VoltageIn_;
   double mppt2CurrentIn_;
   double mppt2VoltageOut_;
   double mppt2CurrentOut_;
   double mppt2PowerIn_;
   double mppt2PowerOut_;
   double mppt2Efficiency_;
   QString mppt2Type_;
   QString mppt2Mode_;

   double mppt3VoltageIn_;
   double mppt3CurrentIn_;
   double mppt3VoltageOut_;
   double mppt3CurrentOut_;
   double mppt3PowerIn_;
   double mppt3PowerOut_;
   double mppt3Efficiency_;
   QString mppt3Type_;
   QString mppt3Mode_;

   double mppt4VoltageIn_;
   double mppt4CurrentIn_;
   double mppt4VoltageOut_;
   double mppt4CurrentOut_;
   double mppt4PowerIn_;
   double mppt4PowerOut_;
   double mppt4Efficiency_;
   QString mppt4Type_;
   QString mppt4Mode_;

   double mppt5VoltageIn_;
   double mppt5CurrentIn_;
   double mppt5VoltageOut_;
   double mppt5CurrentOut_;
   double mppt5PowerIn_;
   double mppt5PowerOut_;
   double mppt5Efficiency_;
   QString mppt5Type_;
   QString mppt5Mode_;

   double mppt6VoltageIn_;
   double mppt6CurrentIn_;
   double mppt6VoltageOut_;
   double mppt6CurrentOut_;
   double mppt6PowerIn_;
   double mppt6PowerOut_;
   double mppt6Efficiency_;
   QString mppt6Type_;
   QString mppt6Mode_;

   double mppt7VoltageIn_;
   double mppt7CurrentIn_;
   double mppt7VoltageOut_;
   double mppt7CurrentOut_;
   double mppt7PowerIn_;
   double mppt7PowerOut_;
   double mppt7Efficiency_;
   QString mppt7Type_;
   QString mppt7Mode_;
};
