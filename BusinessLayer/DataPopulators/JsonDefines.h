/**
 *  Schulich Delta Android Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Android Telemetry
 *
 *  Schulich Delta Android Telemetry is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Android Telemetry is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Android Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QString>
//TODO finish by adding voltages with all the numbers in them... ask managers how they want it formatted
namespace JsonFormat
{
    const int DECIMAL_PRECISION = 2;
    const QString DATA_TYPE = "datatype";

    const QString PACKETTITLE = "PacketTitle";
    const QString TIMESTAMP = "TimeStamp";

    const QString KEYMOTOR = "KeyMotor";
    const QString KEYMOTOR_ALIVE = "Alive";
    const QString KEYMOTOR_SETCURRENT = "SetCurrent";
    const QString KEYMOTOR_SETVELOCITY = "SetVelocity";
    const QString KEYMOTOR_BUSCURRENT = "BusCurrent";
    const QString KEYMOTOR_BUSVOLTAGE = "BusVoltage";
    const QString KEYMOTOR_VEHICLEVELOCITY = "VehicleVelocity";

    const QString MOTORDETAILS = "MotorDetails";
    const QString MOTORDETAILS_PHASECCURRENT = "PhaseCCurrent";
    const QString MOTORDETAILS_PHASEBCURRENT = "PhaseBCurrent";
    const QString MOTORDETAILS_MOTORVOLTAGEREAL = "MotorVoltageReal";
    const QString MOTORDETAILS_MOTORVOLTAGEIMAGINARY = "MotorVoltageImaginary";
    const QString MOTORDETAILS_MOTORCURRENTREAL = "MotorCurrentReal";
    const QString MOTORDETAILS_MOTORCURRENTIMAGINARY = "MotorCurrentImaginary";
    const QString MOTORDETAILS_BACKEMFREAL = "BackEmfReal";
    const QString MOTORDETAILS_VOLTAGERAIL15VSUPPLY = "VoltageRail15VSupply";
    const QString MOTORDETAILS_VOLTAGERAIL3VSUPPLY = "VoltageRail3VSupply";
    const QString MOTORDETAILS_VOLTAGERAIL1VSUPPLY = "VoltageRail1VSupply";
    const QString MOTORDETAILS_HEATSINKTEMP = "HeatSinkTemp";
    const QString MOTORDETAILS_MOTORTEMP = "MotorTemp";
    const QString MOTORDETAILS_DSPBOARDTEMP = "DspBoardTemp";
    const QString MOTORDETAILS_DCBUSAMPHOURS = "DcBusAmpHours";
    const QString MOTORDETAILS_ODOMETER = "Odometer";
    const QString MOTORDETAILS_SLIPSPEED = "SlipSpeed";


    const QString DRIVERCONTROLS = "DriverControl";
    const QString DRIVERCONTROLS_ALIVE = "Alive";
    const QString DRIVERCONTROLS_HEADLIGHTSOFF = "HeadlightsOff";
    const QString DRIVERCONTROLS_HEADLIGHTSLOW = "HeadlightsLow";
    const QString DRIVERCONTROLS_HEADLIGHTSHIGH = "HeadlightsHigh";
    const QString DRIVERCONTROLS_SIGNALRIGHT = "SignalRight";
    const QString DRIVERCONTROLS_SIGNALLEFT = "SignalLeft";
    const QString DRIVERCONTROLS_HAZARD = "Hazard";
    const QString DRIVERCONTROLS_INTERIOR = "Interior";
    const QString DRIVERCONTROLS_AUX = "Aux";
    const QString DRIVERCONTROLS_VOLUMEUP = "VolumeUp";
    const QString DRIVERCONTROLS_VOLUMEDOWN = "VolumeDown";
    const QString DRIVERCONTROLS_NEXTSONG = "NextSong";
    const QString DRIVERCONTROLS_PREVSONG = "PrevSong";
    const QString DRIVERCONTROLS_ACCELERATION = "Acceleration";
    const QString DRIVERCONTROLS_REGENBRAKING = "RegenBraking";
    const QString DRIVERCONTROLS_BRAKES = "Brakes";
    const QString DRIVERCONTROLS_FORWARD = "Forward";
    const QString DRIVERCONTROLS_REVERSE = "Reverse";
    const QString DRIVERCONTROLS_PUSHTOTALK = "PushToTalk";
    const QString DRIVERCONTROLS_HORN = "Horn";
    const QString DRIVERCONTROLS_RESET = "Reset";


    const QString MOTORFAULTS = "MotorFaults";
    const QString MOTORFAULTS_ERRORFLAGS = "ErrorFlags";
    const QString MOTORFAULTS_ERRORFLAGS_MOTOROVERSPEED = "MotorOverSpeed";
    const QString MOTORFAULTS_ERRORFLAGS_SOFTWAREOVERCURRENT = "SoftwareOverCurrent";
    const QString MOTORFAULTS_ERRORFLAGS_DCBUSOVERVOLTAGE = "DcBusOverVoltage";
    const QString MOTORFAULTS_ERRORFLAGS_BADMOTORPOSITIONHALLSEQUENCE = "BadMotorPositionHallSequence";
    const QString MOTORFAULTS_ERRORFLAGS_WATCHDOGCAUSEDLASTRESET = "WatchdogCausedLastReset";
    const QString MOTORFAULTS_ERRORFLAGS_CONFIGREADERROR = "ConfigReadError";
    const QString MOTORFAULTS_ERRORFLAGS_RAIL15VUNDERVOLTAGELOCKOUT = "Rail15VUnderVoltageLockOut";
    const QString MOTORFAULTS_ERRORFLAGS_DESATURATIONFAULT = "DesaturationFault";

    const QString MOTORFAULTS_LIMITFLAGS = "LimitFlags";
    const QString MOTORFAULTS_LIMITFLAGS_OUTPUTVOLTAGEPWM = "OutputVoltagePwm";
    const QString MOTORFAULTS_LIMITFLAGS_MOTORCURRENT = "MotorCurrent";
    const QString MOTORFAULTS_LIMITFLAGS_VELOCITY = "Velocity";
    const QString MOTORFAULTS_LIMITFLAGS_BUSCURRENT = "BusCurrent";
    const QString MOTORFAULTS_LIMITFLAGS_BUSVOLTAGEUPPER = "BusVoltageUpper";
    const QString MOTORFAULTS_LIMITFLAGS_BUSVOLTAGELOWER = "BusVoltageLower";
    const QString MOTORFAULTS_LIMITFLAGS_IPMORMOTORTEMPERATURE = "IpmOrMotorTemperature";
    const QString MOTORFAULTS_RXERRORCOUNT = "RxErrorCount";
    const QString MOTORFAULTS_TXERRORCOUNT = "TxErrorCount";


    const QString BATTERYFAULTS = "BatteryFaults";
    const QString BATTERYFAULTS_CELLOVERVOLTAGE = "CellOverVoltage";
    const QString BATTERYFAULTS_CELLUNDERVOLTAGE = "CellUnderVoltage";
    const QString BATTERYFAULTS_CELLOVERTEMP = "CellOverTemp";
    const QString BATTERYFAULTS_MEASUREMENTUNTRUSTED = "MeasurementUntrusted";
    const QString BATTERYFAULTS_CMUCOMMTIMEOUT = "CMUCommTimeout";
    const QString BATTERYFAULTS_BMUSETUPMODE = "BMUSetupMode";
    const QString BATTERYFAULTS_CMUCANBUSPOWERSTATUS = "CMUCANBusPowerStatus";
    const QString BATTERYFAULTS_PACKISOLATIONFAILURE = "PackIsolationFailure";
    const QString BATTERYFAULTS_SOFTWAREOVERCURRENT = "SoftwareOverCurrent";
    const QString BATTERYFAULTS_CAN12VSUPPLYLOW = "CAN12VSupplyLow";
    const QString BATTERYFAULTS_CONTACTORSTUCK = "ContactorStuck";
    const QString BATTERYFAULTS_CMUDETECTEDEXTRACELL = "CMUDetectedExtraCell";


    const QString BATTERY = "Battery";
    const QString BATTERY_ALIVE = "Alive";
    const QString BATTERY_PACKSOCAMPHOURS = "PackSocAmpHours";
    const QString BATTERY_PACKSOCPERCENTAGE = "PackSocPercentage";
    const QString BATTERY_PACKBALANCESOCAMPHOURS = "PackBalanceSocAmpHours";
    const QString BATTERY_PACKBALANCESOCPERCENTAGE = "PackBalanceSocPercentage";
    const QString BATTERY_CHARGINGCELLVOLTAGEERROR = "ChargingCellVoltageError";
    const QString BATTERY_CELLTEMPMARGIN = "CellTempMargin";
    const QString BATTERY_DISCHARGINGCELLVOLTAGEERROR = "DischargingCellVoltageError";
    const QString BATTERY_TOTALPACKCAPACITY = "TotalPackCapacity";
    const QString BATTERY_PRECHARGECONTACTOR0DRIVERSTATUS = "PrechargeContactor0DriverStatus";
    const QString BATTERY_PRECHARGECONTACTOR1DRIVERSTATUS = "PrechargeContactor1DriverStatus";
    const QString BATTERY_PRECHARGECONTACTOR2DRIVERSTATUS = "PrechargeContactor2DriverStatus";
    const QString BATTERY_PRECHARGECONTACTOR0DRIVERERROR = "PrechargeContactor0DriverError";
    const QString BATTERY_PRECHARGECONTACTOR1DRIVERERROR = "PrechargeContactor1DriverError";
    const QString BATTERY_PRECHARGECONTACTOR2DRIVERERROR = "PrechargeContactor2DriverError";
    const QString BATTERY_CONTACTORSUPPLYOK = "ContactorSupplyOk";
    const QString BATTERY_PRECHARGESTATE = "PrechargeState";
    const QString BATTERY_PRECHARGETIMERELAPSED = "PrechargeTimerElapsed";
    const QString BATTERY_PRECHARGETIMERCOUNT = "PrechargeTimerCount";

    const QString BATTERY_LOWESTCELLVOLTAGE = "LowestCellVoltage";
    const QString BATTERY_LOWESTCELLVOLTAGE_VOLTAGE = "Voltage";
    const QString BATTERY_LOWESTCELLVOLTAGE_CMUNUMBER = "CMUNumber";
    const QString BATTERY_LOWESTCELLVOLTAGE_CELLNUMBER = "CellNumber";

    const QString BATTERY_LOWESTCELLTEMP = "LowestCellTemp";
    const QString BATTERY_LOWESTCELLTEMP_TEMPERATURE = "Temperature";
    const QString BATTERY_LOWESTCELLTEMP_CMUNUMBER = "CMUNumber";
    const QString BATTERY_LOWESTCELLTEMP_CELLNUMBER = "CellNumber";

    const QString BATTERY_HIGHESTCELLVOLTAGE = "HighestCellVoltage";
    const QString BATTERY_HIGHESTCELLVOLTAGE_VOLTAGE = "Voltage";
    const QString BATTERY_HIGHESTCELLVOLTAGE_CMUNUMBER = "CMUNumber";
    const QString BATTERY_HIGHESTCELLVOLTAGE_CELLNUMBER = "CellNumber";

    const QString BATTERY_HIGHESTCELLTEMP = "HighestCellTemp";
    const QString BATTERY_HIGHESTCELLTEMP_TEMPERATURE = "Temperature";
    const QString BATTERY_HIGHESTCELLTEMP_CMUNUMBER = "CMUNumber";
    const QString BATTERY_HIGHESTCELLTEMP_CELLNUMBER = "CellNumber";

    const QString BATTERY_VOLTAGE = "Voltage";
    const QString BATTERY_CURRENT = "Current";
    const QString BATTERY_FAN0SPEED = "Fan0Speed";
    const QString BATTERY_FAN1SPEED = "Fan1Speed";
    const QString BATTERY_FANCONTACTORSCURRENT = "FanContactorsCurrent";
    const QString BATTERY_CMUCURRENT = "CMUCurrent";

    const QString CMU = "CMU";
    const QString CMU_VOLTAGES = "Voltages";
    const QString CMU_PCBTEMP = "PcbTemp";
    const QString CMU_CELLTEMPS = "CellTemps";

    const QString MPPT = "MPPT";
    const QString MPPT_ALIVE = "Alive";
    const QString MPPT_ARRAYVOLTAGE = "ArrayVoltage";
    const QString MPPT_ARRAYCURRENT = "ArrayCurrent";
    const QString MPPT_BATTERYVOLTAGE = "BatteryVoltage";
    const QString MPPT_TEMPERATURE = "Temperature";


    const QString LIGHTS = "Lights";
    const QString LIGHTS_LOWBEAMS = "LowBeams";
    const QString LIGHTS_HIGHBEAMS = "HighBeams";
    const QString LIGHTS_BRAKES = "Brakes";
    const QString LIGHTS_LEFTSIGNAL = "LeftSignal";
    const QString LIGHTS_RIGHTSIGNAL = "RightSignal";
    const QString LIGHTS_BMSSTROBELIGHT = "BmsStrobeLight";
}
