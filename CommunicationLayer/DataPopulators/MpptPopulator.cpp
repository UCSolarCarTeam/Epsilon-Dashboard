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

#include "MpptPopulator.h"
#include "../MessagingFramework/MpptDefines.h"
#include <QDebug>

MpptPopulator::MpptPopulator(I_PacketDecoder& packetDecoder,
                      I_MpptData& mpptData)
: packetDecoder_(packetDecoder)
, mpptData_(mpptData)
{
   connect(&packetDecoder_, SIGNAL(packetDecoded(const MpptDataMessage)),
         this, SLOT(populateData(const MpptDataMessage)));
}

void MpptPopulator::populateData(const MpptDataMessage message)
{
   switch(message.mpptNumber())
   {
      case 0:
         mpptData_.setMppt1Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt1VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt1CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt1VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt1CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt1Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 1:
         mpptData_.setMppt2Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt2VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt2CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt2VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt2CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt2Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 2:
         mpptData_.setMppt3Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt3VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt3CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt3VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt3CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt3Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 3:
         mpptData_.setMppt4Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt4VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt4CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt4VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt4CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt4Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 4:
         mpptData_.setMppt5Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt5VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt5CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt5VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt5CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt5Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 5:
         mpptData_.setMppt6Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt6VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt6CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt6VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt6CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt6Mode(MpptDefines::modeToString(message.mode()));
         }
         break;
      case 6:
         mpptData_.setMppt7Type(MpptDefines::typeToString(message.type()));
         if(message.isVoltageInValid()){
            mpptData_.setMppt7VoltageIn(message.voltageIn());
         }
         if(message.isCurrentInValid()){
            mpptData_.setMppt7CurrentIn(message.currentIn());
         }
         if(message.isVoltageOutValid()){
            mpptData_.setMppt7VoltageOut(message.voltageOut());
         }
         if(message.isCurrentOutValid()){
            mpptData_.setMppt7CurrentOut(message.currentOut());
         }
         if(message.isModeValid()){
            mpptData_.setMppt7Mode(MpptDefines::modeToString(message.mode()));
         }
   }
}
